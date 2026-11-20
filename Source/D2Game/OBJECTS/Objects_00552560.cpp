#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Drlg.h"




struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
};


struct D2LevelsTxt
{
    char unk0x000[0xE5];
    unsigned char nObjGroup[8];
    unsigned char nObjPrb[8];
    char unk0x0F5[0x11B];
    unsigned int dwThemes;
};

struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
};



typedef int (__fastcall* OBJTHEMEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);
typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

struct D2ObjectPopulateStrc
{
    int bActive;
    OBJTHEMEFN pfPopulate;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2ObjectPopulateStrc gObjectThemeTable_00731E68[7];                                            // 0x00731E68
extern OBJECTPOPULATEFN sgPopulateTable[10];                                          // 0x00731D00
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

static __forceinline unsigned int OBJPOP_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int OBJPOP_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return OBJPOP_RollSeed_Inline(pSeed) % nMax;
    }

    return OBJPOP_RollSeed_Inline(pSeed) & (nMax - 1);
}

static int __stdcall sub_00552400_PopulateTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion)
{
    if (pObjectRegion->nPopulatedRooms < 10 * pObjectRegion->unk0x0C)
    {
        return 0;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    const int nRoll = OBJPOP_RollSeed_Inline(&pObjectControl->pSeed) % 100;

    int nProbability = 0;
    if (pObjectRegion->field_4 > pObjectRegion->nPopulatedRooms / 2)
    {
        nProbability = 5;
    }

    if (pObjectRegion->field_4 > pObjectRegion->nPopulatedRooms - pObjectRegion->nPopulatedRooms / 4)
    {
        nProbability += 5;
    }

    if (nRoll >= nProbability + 12)
    {
        return 0;
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    int nMax = 0;
    int nIndices[7] = {};
    for (int i = 0; i < 7; ++i)
    {
        if ((1 << i) & nThemes)
        {
            nIndices[nMax] = i + 1;
            ++nMax;
        }
    }

    const int nIndex = OBJPOP_RollLimited_Inline(&pObjectControl->pSeed, nMax);
    if (nIndex < nMax && nIndices[nIndex] < nMax && gObjectThemeTable_00731E68[nIndices[nIndex]].bActive && gObjectThemeTable_00731E68[nIndices[nIndex]].pfPopulate)
    {
        return gObjectThemeTable_00731E68[nIndices[nIndex]].pfPopulate(pGame, pRoom, &drlgCoords);
    }

    return 0;
}

// 0x00552560
static int __stdcall sub_00552560_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom)
{
    if (DUNGEON_HasWaypoint(pRoom))
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, nLevelId);
    if (!nLevelId)
    {
        return 0;
    }

    if (D2Common_10087(pRoom))
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    if (pObjectRegion->nPopulatedRooms == 0x7FFFFFFF)
    {
        pObjectRegion->nPopulatedRooms = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pGame->pAct[pObjectRegion->nAct], nLevelId);
    }

    pObjectRegion->field_4 += 1;

    if (pLevelsTxtRecord->dwThemes)
    {
        if (sub_00552400_PopulateTheme(pGame, pRoom, pLevelsTxtRecord->dwThemes, pObjectRegion) == 1)
        {
            return 0;
        }
    }

    return 1;
}

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0xBEC);

    if (!sub_00552560_CanPopulateRoom(pGame, pLevelsTxtRecord, pRoom))
    {
        return;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjGroup = pLevelsTxtRecord->nObjGroup[i];
        int nProbability = OBJPOP_RollSeed_Inline(pSeed) % 100;

        D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->field_4 << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines
            && DATATBLS_GetObjectsTxtRecord(nObjGroup)->nSubClass)
        {
            nProbability = 100;
        }

        if (nObjGroup && nProbability <= pLevelsTxtRecord->nObjPrb[i])
        {
            D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
            if (!pObjGroupTxtRecord)
            {
                return;
            }

            const int nRoll = OBJPOP_RollSeed_Inline(pSeed) % 100;
            int nAccumulatedProbability = 0;
            for (int j = 0; j < 8; ++j)
            {
                const unsigned int nObjectId = pObjGroupTxtRecord->dwId[j];
                if (!nObjectId)
                {
                    break;
                }

                nAccumulatedProbability += pObjGroupTxtRecord->nProbability[j];
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
                if (nRoll < nAccumulatedProbability && pObjectsTxtRecord->nGore <= gnObjectGoreLevel_00731BBC)
                {
                    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC43);
                    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC46);
                        const unsigned char nDensity = pObjGroupTxtRecord->nDensity[j];
                        D2_ASSERT(nDensity < 128, 0xC47);
                        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, nDensity, nObjectId, 100);
                    }
                    break;
                }
            }
        }
    }
}

#include "gen/data/Source/D2Game/OBJECTS/Objects_00552560.inc"
