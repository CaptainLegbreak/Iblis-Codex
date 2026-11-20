#include "D2Drlg.h"
#include "D2ItemsWorld.h"
// build: context DRLG_ComputeManhattanDistanceCheck



struct D2DrlgRoomStrc;
struct D2LvlWarpTxt;


struct D2RoomTileStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    int unk0x0C;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    int unk0x14;
};



struct D2LevelDefBin
{
    char unk0x00[0x88];
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B4B0
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                             // 0x0061E470
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                         // 0x006424A0
int __fastcall DRLG_IsTownLevel(int nLevelId);                                                       // 0x006426A0
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                      // 0x00642BB0
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId);                   // 0x0066AF30
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char nDirection);   // 0x0066AF50
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                                   // 0x0066C040

// build: context DRLG_ComputeManhattanDistance
inline void DRLG_ComputeManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int* pDistanceX, int* pDistanceY)
{
    if (pDrlgCoord1->nPosX < pDrlgCoord2->nPosX)
    {
        *pDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    else
    {
        *pDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY < pDrlgCoord2->nPosY)
    {
        *pDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    else
    {
        *pDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }
}

inline int DRLG_ComputeManhattanDistanceCheck(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY)
{
    DRLG_ComputeManhattanDistance(pDrlgCoord1, pDrlgCoord2, pDistanceX, pDistanceY);
    return *pDistanceX >= nMaxDistance || *pDistanceY >= nMaxDistance;
}

// 0x0066BBC0
static void DRLGROOM_SortRoomListByPosition(D2DrlgRoomStrc** ppRoomList, int nListSize)
{
    for (int j = nListSize - 1; j > 0; --j)
    {
        for (int i = 0; i < nListSize - 1; ++i)
        {
            D2DrlgRoomStrc* pDrlgRoom1 = ppRoomList[i + 1];
            D2DrlgRoomStrc* pDrlgRoom2 = ppRoomList[i];

            if (pDrlgRoom2->pDrlgCoord.nPosX >= pDrlgRoom1->pDrlgCoord.nPosX + pDrlgRoom1->pDrlgCoord.nWidth || pDrlgRoom2->pDrlgCoord.nPosY >= pDrlgRoom1->pDrlgCoord.nPosY + pDrlgRoom1->pDrlgCoord.nHeight)
            {
                ppRoomList[i] = pDrlgRoom1;
                ppRoomList[i + 1] = pDrlgRoom2;
            }
        }
    }
}

// 0x0066BC20
static void __stdcall sub_0066BC20(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgRoomStrc* ppNearRooms[30];

    D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom->ptDrlgLevel->ptRoomFirst;
    pDrlgRoom->nRoomsNear = 0;

    while (pCurrentRoomEx)
    {
        int nX;
        int nY;

        if (DRLG_ComputeManhattanDistanceCheck(&pDrlgRoom->pDrlgCoord, &pCurrentRoomEx->pDrlgCoord, 6, &nX, &nY))
        {
            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
        }
        else
        {
            ppNearRooms[pDrlgRoom->nRoomsNear] = pCurrentRoomEx;
            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
            ++pDrlgRoom->nRoomsNear;
        }
    }

    int nRoomsNear = pDrlgRoom->nRoomsNear;
    DRLGROOM_SortRoomListByPosition(ppNearRooms, nRoomsNear);

    pDrlgRoom->ppRoomsNear = (D2DrlgRoomStrc**)sub_0040B430(pMemPool, sizeof(D2DrlgRoomStrc*) * nRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 715, 0);

    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        pDrlgRoom->ppRoomsNear[i] = ppNearRooms[i];
    }
}

// 0x0066BD00
int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, void** ppRoomList)
{
    int nRooms = 0;

    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        if (pDrlgRoom->ppRoomsNear[i]->pRoom)
        {
            ppRoomList[nRooms] = pDrlgRoom->ppRoomsNear[i]->pRoom;
            ++nRooms;
        }
    }

    for (int i = nRooms; i < pDrlgRoom->nRoomsNear; ++i)
    {
        ppRoomList[i] = 0;
    }

    return nRooms;
}

// 0x0066BD50
static void sub_0066BD50(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!DRLG_IsTownLevel(pDrlgRoom->ptDrlgLevel->eLevelId))
    {
        for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
        {
            if (DRLG_IsTownLevel(pDrlgRoom->ppRoomsNear[i]->ptDrlgLevel->eLevelId))
            {
                pDrlgRoom->dwFlags |= 0x800000;
                return;
            }
        }
    }
}

// 0x0066BDA0
static void __stdcall sub_0066BDA0(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    ++pDrlgRoom1->nRoomsNear;
    pDrlgRoom1->ppRoomsNear = (D2DrlgRoomStrc**)FOG_ReallocPool(pMemPool, pDrlgRoom1->ppRoomsNear, sizeof(D2DrlgRoomStrc*) * pDrlgRoom1->nRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 788, 0);
    if (!pDrlgRoom1->ppRoomsNear)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 789);
        exit(-1);
    }

    pDrlgRoom1->ppRoomsNear[pDrlgRoom1->nRoomsNear - 1] = pDrlgRoom2;
    DRLGROOM_SortRoomListByPosition(pDrlgRoom1->ppRoomsNear, pDrlgRoom1->nRoomsNear);
}

// 0x0066BE10
static void __stdcall sub_0066BE10(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, unsigned char nWarpId)
{
    D2RoomTileStrc* pRoomTile = (D2RoomTileStrc*)sub_0040B430(pDrlgRoom1->ptDrlgLevel->pDrlg->pMempool, sizeof(D2RoomTileStrc), ".\\DRLG\\DrlgRoom.cpp", 802, 0);
    memset(pRoomTile, 0, sizeof(D2RoomTileStrc));
    pRoomTile->pDrlgRoom = pDrlgRoom2;
    pRoomTile->pLvlWarpTxtRecord = DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(pDrlgRoom1->ptDrlgLevel, nWarpId, 'b');
    pRoomTile->bEnabled = 1;
    pRoomTile->pNext = pDrlgRoom1->pRoomTiles;
    pDrlgRoom1->pRoomTiles = pRoomTile;
}

// 0x0066BE80
static int __stdcall sub_0066BE80(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, unsigned char nWarpId, D2DrlgRoomStrc* pDrlgRoom2, char nWarpFlag, int nDirection)
{
    int bResult = 0;
    int nWarpMask = 1 << (nWarpFlag + 4);

    while (pDrlgRoom2)
    {
        if (nWarpMask & pDrlgRoom2->dwFlags)
        {
            if (nDirection == -1)
            {
                int nX;
                int nY;
                DRLG_ComputeManhattanDistance(&pDrlgRoom1->pDrlgCoord, &pDrlgRoom2->pDrlgCoord, &nX, &nY);

                if (nX < 6 && nY < 6)
                {
                    sub_0066BDA0(pMemPool, pDrlgRoom1, pDrlgRoom2);
                    bResult = 1;
                }
            }
            else
            {
                sub_0066BDA0(pMemPool, pDrlgRoom1, pDrlgRoom2);
                sub_0066BE10(pDrlgRoom1, pDrlgRoom2, nWarpId);
                return 1;
            }
        }

        pDrlgRoom2 = pDrlgRoom2->pDrlgRoomNext;
    }

    return bResult;
}

// 0x0066BF30
D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = (D2PresetUnitStrc*)sub_0040B430(pMemPool, sizeof(D2PresetUnitStrc), ".\\DRLG\\DrlgRoom.cpp", 950, 0);
    memset(pPresetUnit, 0, sizeof(D2PresetUnitStrc));
    pPresetUnit->nUnitType = nUnitType;
    pPresetUnit->nIndex = nIndex;
    pPresetUnit->nMode = nMode;
    pPresetUnit->nXpos = nX;
    pPresetUnit->nYpos = nY;

    if (pDrlgRoom)
    {
        pPresetUnit->pNext = pDrlgRoom->pPresetUnits;
        pDrlgRoom->pPresetUnits = pPresetUnit;
    }
    else
    {
        pPresetUnit->pNext = 0;
    }

    return pPresetUnit;
}

// 0x0066BFD0
void __fastcall DRLGROOM_GetRGB_IntensityFromRoomEx(D2DrlgRoomStrc* pDrlgRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    D2LevelDefBin* pLevelDefRecord = DATATBLS_GetLevelDefRecord(pDrlgRoom->ptDrlgLevel->eLevelId);

    *pIntensity = pLevelDefRecord->nIntensity;
    *pRed = pLevelDefRecord->nRed;
    *pGreen = pLevelDefRecord->nGreen;
    *pBlue = pLevelDefRecord->nBlue;
}

// 0x0066C0B0
D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom)
{
    if (!pRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1067);
        exit(-1);
    }

    if (!pRoom->ptDrlgLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1068);
        exit(-1);
    }

    if (!pRoom->ptDrlgLevel->pDrlg)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1069);
        exit(-1);
    }

    return pRoom->ptDrlgLevel->pDrlg;
}

// 0x0066C220
static void __stdcall sub_0066C220(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, unsigned char nWarpId)
{
    if (!pDrlgRoom || nWarpId >= 8)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 848);
        exit(-1);
    }

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    int nLevelId = pLevel->eLevelId;
    int* pSourceVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nLevelId);
    int nDestinationLevelId = pSourceVisArray[nWarpId];
    D2DrlgLevelStrc* pDestinationLevel = DRLG_GetLevel(pLevel->pDrlg, nDestinationLevelId);
    int* pDestinationVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nDestinationLevelId);
    int nWarpDestination = DRLGWARP_GetWarpDestinationFromArray(pLevel, nWarpId);

    if (!pDestinationLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pDestinationLevel);
    }

    int bLinkedWarp = 0;
    if (nWarpDestination != -1)
    {
        int nSourceVisCount = 0;
        int nDestinationVisCount = 0;
        for (unsigned char i = 0; i < nWarpId; ++i)
        {
            if (pSourceVisArray[i] == nDestinationLevelId)
            {
                ++nSourceVisCount;
            }
        }

        for (unsigned char i = 0; i < 8; ++i)
        {
            if (pDestinationVisArray[i] == nLevelId)
            {
                if (nSourceVisCount == nDestinationVisCount)
                {
                    if (sub_0066BE80(pMemPool, pDrlgRoom, nWarpId, pDestinationLevel->ptRoomFirst, i, nWarpDestination))
                    {
                        bLinkedWarp = 1;
                    }
                    break;
                }

                ++nDestinationVisCount;
            }
        }
    }

    if (!bLinkedWarp)
    {
        for (unsigned char i = 0; i < 8; ++i)
        {
            if (pDestinationVisArray[i] == nLevelId && sub_0066BE80(pMemPool, pDrlgRoom, nWarpId, pDestinationLevel->ptRoomFirst, i, nWarpDestination))
            {
                break;
            }
        }
    }
}

// 0x0066C370
void __fastcall DRLGROOM_InitNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    sub_0066BC20(pMemPool, pDrlgRoom);

    if (pDrlgRoom->dwFlags & 0xFF0)
    {
        int nFlags = 0x10;
        unsigned char nWarpId = 0;

        do
        {
            if ((nFlags & pDrlgRoom->dwFlags) && pDrlgRoom->ptDrlgLevel->eLevelId != 133)
            {
                sub_0066C220(pMemPool, pDrlgRoom, nWarpId);
            }

            nFlags <<= 1;
            ++nWarpId;
        }
        while (nFlags & 0xFF0);
    }

    sub_0066BD50(pDrlgRoom);
}
