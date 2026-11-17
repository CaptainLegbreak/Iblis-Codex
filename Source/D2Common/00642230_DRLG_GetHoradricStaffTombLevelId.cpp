typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgLevelStrc;
struct D2DrlgOutdoorInfoStrc;

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};

struct D2LevelDefBin
{
    char unk0x00[0x48];
    int dwVis[8];
    int dwWarp[8];
};

struct D2DrlgStrc
{
    char unk0x000[0x08C];
    unsigned int dwFlags;
    D2DrlgWarpStrc* pWarp;
    int nStaffTombLevel;
    char unk0x098[0x478 - 0x098];
    void* pMempool;
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    char unk0x2C[0x58 - 0x2C];
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x010];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x1AC - 0x018];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x1B4 - 0x1B0];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x1D0 - 0x1B8];
    int nLevelId;
    char unk0x1D4[0x1E0 - 0x1D4];
    int nRoom_Center_Warp_X[4];
};

struct D2DrlgOrthStrc
{
    D2DrlgLevelStrc* pLevel;
    int nDirection;
    char unk0x08[0x14 - 0x08];
    D2DrlgOrthStrc* pNext;
};

struct D2DrlgOutdoorInfoStrc
{
    char unk0x000[0x05C];
    int nGridWidth;
    int nGridHeight;
    char unk0x064[0x264 - 0x064];
    D2DrlgOrthStrc* pRoomData;
};

struct D2DrlgTableEntryStrc
{
    char unk0x00[0x38];
};

struct D2DrlgEntryTableStrc
{
    char unk0x0000[0x404];
    D2DrlgTableEntryStrc pEntries[200];
    int nEntries;
};

extern const int gnTileTypeMappingTable_006EEF20[];                                                         // 0x006EEF20
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId);                               // 0x00642AE0
void __fastcall sub_00642F70_AddLevelActivity(D2DrlgLevelStrc* pLevel, int nDelta);                         // 0x00642F70
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nPickedFile, int a4, int a5); // 0x00674730

inline D2DrlgLevelStrc* DRLG_InlineGetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->nLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642230
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg)
{
    if (pDrlg)
    {
        return pDrlg->nStaffTombLevel;
    }

    return 0;
}

// 0x00642380
int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pLevel->nRoom_Center_Warp_X;
}

// 0x006426A0
int __fastcall DRLG_IsTownLevel(int nLevelId)
{
    switch (nLevelId)
    {
    case 1:
    case 40:
    case 75:
    case 103:
    case 109:
        return 1;

    default:
        return 0;
    }
}

// 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* i = pDrlg->pWarp; i; i = i->pNext)
    {
        if (i->nLevel == nLevelId)
        {
            return i;
        }
    }

    D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(nLevelId);
    D2DrlgWarpStrc* pDrlgWarp = (D2DrlgWarpStrc*)sub_0040B430(pDrlg->pMempool, sizeof(D2DrlgWarpStrc), ".\\DRLG\\Drlg.cpp", 0x3E0, 0);
    pDrlgWarp->nLevel = nLevelId;

    for (int i = 0; i < 8; ++i)
    {
        pDrlgWarp->nVis[i] = pLevelDefBin->dwVis[i];
        pDrlgWarp->nWarp[i] = pLevelDefBin->dwWarp[i];
    }

    pDrlgWarp->pNext = pDrlg->pWarp;
    pDrlg->pWarp = pDrlgWarp;

    return pDrlgWarp;
}

// 0x00642A00
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg)
{
    D2_ASSERT(pDrlg, 0x42E);

    return pDrlg->dwFlags & 1;
}

// 0x00642BE0
int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    int nCounter = 0;
    D2DrlgLevelStrc* pLevel = DRLG_InlineGetLevel(pDrlg, nLevelId);

    for (D2DrlgRoomStrc* i = pLevel->pFirstRoomEx; i; i = i->pDrlgRoomNext)
    {
        if (!(i->dwFlags & 0x800000))
        {
            ++nCounter;
        }
    }

    return nCounter;
}

// 0x00643020
void __fastcall sub_6FD745C0(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    D2DrlgLevelStrc* pLevel1 = pDrlgRoom1 ? pDrlgRoom1->pLevel : 0;
    D2DrlgLevelStrc* pLevel2 = pDrlgRoom2 ? pDrlgRoom2->pLevel : 0;

    if (pLevel1 != pLevel2)
    {
        if (pLevel1)
        {
            sub_00642F70_AddLevelActivity(pLevel1, -1);
        }

        if (pLevel2)
        {
            sub_00642F70_AddLevelActivity(pLevel2, 1);
        }
    }
}

// 0x0066D7F0
int __fastcall DRLGPRESET_MapTileType(int nId)
{
    return gnTileTypeMappingTable_006EEF20[nId];
}

// 0x00675320
void __fastcall DRLGOUTDOORS_AllocOutdoorInfo(D2DrlgLevelStrc* pLevel)
{
    pLevel->pOutdoors = (D2DrlgOutdoorInfoStrc*)sub_0040B430(pLevel->pDrlg->pMempool, 0x268, ".\\DRLG\\Outdoors.cpp", 0x34C, 0);
    memset(pLevel->pOutdoors, 0, 0x268);
}

// 0x0067B1C0
D2DrlgTableEntryStrc* __fastcall sub_0067B1C0_AllocTableEntry(D2DrlgEntryTableStrc* pTable)
{
    if (pTable->nEntries == 200)
    {
        return 0;
    }

    D2DrlgTableEntryStrc* pEntry = &pTable->pEntries[pTable->nEntries++];
    memset(pEntry, 0, sizeof(D2DrlgTableEntryStrc));
    return pEntry;
}

// 0x0067F560
void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOrthStrc* pTownRoomData = pLevel->pOutdoors->pRoomData;

    while (pTownRoomData && pTownRoomData->pLevel->nLevelId != 40)
    {
        pTownRoomData = pTownRoomData->pNext;
    }

    if (pTownRoomData)
    {
        if (pTownRoomData->nDirection == 3)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, pLevel->pOutdoors->nGridHeight - 1, 0x16B, -1, 0);
        }
        else
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pLevel->pOutdoors->nGridWidth - 1, 0, 0x16A, -1, 0);
        }
    }
}

// 0x0067F670
void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId = 0;

    switch (pLevel->nLevelId)
    {
    case 41:
    case 42:
        nLevelPrestId = 0x184;
        break;

    case 43:
        nLevelPrestId = 0x186;
        break;

    case 44:
        nLevelPrestId = 0x19C;
        break;

    case 45:
        nLevelPrestId = 0x185;
        break;
    }

    D2_ASSERT(nLevelPrestId && DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nLevelPrestId, -1, 0, 15), 0xAA);
}

#include "gen/data/Source/D2Common/00642230_DRLG_GetHoradricStaffTombLevelId.inc"
