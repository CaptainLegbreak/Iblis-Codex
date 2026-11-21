#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"

typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2CmpTileStrc;






int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppProjects, int nOrientation, int nMainIndex, int nSubIndex, D2CmpTileStrc** ppTiles, int nMaxTiles); // 0x00604AE0
void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry); // 0x0066DDE0
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);                  // 0x0066B980
int __fastcall sub_006427A0_GetLevelIdFromCoordinates(D2DrlgStrc* pDrlg, int nX, int nY);                   // 0x006427A0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId);                               // 0x00642AE0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040

inline D2DrlgLevelStrc* DRLG_InlineGetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->eLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642A30
void __fastcall DRLGANIM_InitCache(D2DrlgStrc* pDrlg, D2DrlgTileDataStrc* pTileData)
{
    D2CmpTileStrc* ppTileLibraryEntry[40];

    D2_ASSERT(pDrlg, 1079);
    D2_ASSERT(pTileData, 1080);

    memset(pTileData, 0x00, sizeof(D2DrlgTileDataStrc));

    int nSequence = 0;
    int nStyle = 0;
    switch (pDrlg->nAct)
    {
    case 0:
        break;

    case 1:
        nSequence = 1;
        break;

    case 2:
        nStyle = 29;
        nSequence = 12;
        break;

    default:
        return;
    }

    D2_ASSERT(TileLibraryGetTiles(pDrlg->pTiles, 0, nStyle, nSequence, ppTileLibraryEntry, 40), 1100);
    DRLGROOMTILE_InitTileData(0, pTileData, 0, 0, 0, ppTileLibraryEntry[0]);
}

// 0x00642C30
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoomHint, D2DrlgLevelStrc* pLevel)
{
    if (pDrlgRoomHint)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pDrlgRoomHint->pDrlgCoord, nX, nY))
        {
            return pDrlgRoomHint;
        }

        for (int i = 0; i < pDrlgRoomHint->nRoomsNear; ++i)
        {
            D2DrlgRoomStrc* pNear = pDrlgRoomHint->ppRoomsNear[i];
            if (pDrlgRoomHint != pNear && DRLGROOM_AreXYInsideCoordinates(&pNear->pDrlgCoord, nX, nY))
            {
                return pNear;
            }
        }
    }

    if (!pLevel)
    {
        pLevel = DRLG_InlineGetLevel(pDrlg, sub_006427A0_GetLevelIdFromCoordinates(pDrlg, nX, nY));
    }

    if (!pLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pLevel);
    }

    return DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
}

// 0x00642F70
void __fastcall sub_00642F70_AddLevelActivity(D2DrlgLevelStrc* pLevel, int nDelta)
{
    pLevel->bActive += nDelta;
    pLevel->bActive = pLevel->bActive <= 0 ? 0 : pLevel->bActive;
    pLevel->unk0x1D4 = 10;

    int* pVisLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
    for (int i = 0; i < 8; ++i)
    {
        const int nVisLevelId = pVisLevelIds[i];
        if (nVisLevelId)
        {
            D2DrlgLevelStrc* pVisLevel = DRLG_InlineGetLevel(pLevel->pDrlg, nVisLevelId);
            pVisLevel->bActive += nDelta;
            pVisLevel->bActive = pVisLevel->bActive <= 0 ? 0 : pVisLevel->bActive;
            pVisLevel->unk0x1D4 = 10;
        }
    }
}

// 0x00643060
int __stdcall sub_00643060_FreeInactiveVisRoomTiles(D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMempool;

    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if (pRoom->fRoomStatus <= 3 || pRoom->dwFlags & 0x100000)
        {
            return 0;
        }
    }

    int* pLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
    for (int j = 0; j < 8; ++j)
    {
        if (pLevelIds[j])
        {
            D2DrlgLevelStrc* pCurrentLevel = DRLG_InlineGetLevel(pLevel->pDrlg, pLevelIds[j]);
            D2DrlgRoomStrc* pRoom = pCurrentLevel->ptRoomFirst;
            if (pRoom)
            {
                int* pLevels = DRLGROOM_GetVisArrayFromLevelId(pCurrentLevel->pDrlg, pCurrentLevel->eLevelId);
                unsigned int dwFlags = 0;
                for (int i = 0; i < 8; ++i)
                {
                    if (pLevels[i] == pLevel->eLevelId)
                    {
                        dwFlags |= 1 << (i + 4);
                    }
                }

                for (; pRoom; pRoom = pRoom->pDrlgRoomNext)
                {
                    if (pRoom->dwFlags & dwFlags && (pRoom->fRoomStatus <= 3 || pRoom->dwFlags & 0x100000))
                    {
                        return 0;
                    }
                }

                for (pRoom = pCurrentLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
                {
                    if (pRoom->dwFlags & dwFlags)
                    {
                        DRLGROOM_FreeRoomTiles(pMemPool, pRoom);
                        if (pRoom->ppRoomsNear)
                        {
                            FOG_FreeServerMemory(pMemPool, pRoom->ppRoomsNear, ".\\DRLG\\Drlg.cpp", 367, 0);
                            pRoom->ppRoomsNear = 0;
                            pRoom->nRoomsNear = 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}

// 0x006433C0
void __stdcall DUNGEON_GameToClientTileDrawPositionCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 80 * (nX - nY);
    *pY = 40 * (nX + nY);
    *pX -= 80;
    *pY += 80;
}
