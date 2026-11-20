#include "D2Common.h"
#include "D2Structs.h"

#define DRLGROOMFLAG_NO_LOS_DRAW 0x80000
#define DRLGROOMFLAG_PRESET_UNITS_SPAWNED 0x4000000
struct D2PresetUnitStrc;
struct D2DrlgStrc;
struct D2SeedStrc;
struct D2LvlSubTxt;
struct D2DrlgCoordStrc;
struct D2DrlgWarpStrc;
struct D2LevelDefBin;
struct D2DrlgOrthStrc;


struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
    unsigned char unk_94[0x3E4];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x4];
    unsigned int dwFlags;
    int nRooms;
    char unk0x00C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x14[0x1A0];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0xC];
    D2SeedStrc pSeed;
    unsigned char unk_1CC[0x4];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    unsigned int dwInitSeed;
    D2DrlgRoomStrc** ppRoomsNear;
    unsigned char unk_0C[0x8];
    D2SeedStrc pSeed;
    unsigned char unk_1C[0x8];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    unsigned char unk_34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0x3];
    int nType;
    char unk0x4C[0x4];
    unsigned int dwDT1Mask;
    char unk0x54[0x4];
    D2DrlgLevelStrc* pLevel;
    D2PresetUnitStrc* pPresetUnits;
    unsigned char unk_60[0x8C];
};

struct D2LvlSubTxt
{
    int dwType;
    char unk0x004[0x44];
    unsigned int dwDt1Mask;
    char unk0x04C[0xD0];
    int nProb[5];
    char unk0x130[0x2C];
};

enum D2C_J11DrlgConstants
{
    DRLGTYPE_MAZE = 1,
    DRLGTYPE_PRESET = 2,
    DRLGLEVELFLAG_AUTOMAP_REVEAL = 0x10,
    DRLGROOMFLAG_AUTOMAP_REVEAL = 0x40000,
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId); // 0x0061FA90
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x00666630
void __fastcall sub_0067D6D0(D2DrlgRoomStrc* pRoom); // 0x0067D6D0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[16];
    D2DrlgWarpStrc* pNext;
};

struct D2LevelDefBin
{
    char unk0x00[0x30];
    int dwDrlgType;
    unsigned char unk_34[0x14];
    int dwVis[8];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0
const char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x00667010
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x0066AB00
unsigned int __fastcall sub_0067D7A0(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D7A0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

struct D2DrlgOrthStrc
{
    D2DrlgRoomStrc* pTarget;
    int nDirection;
    int bPreset;
    int bInit;
    void* pBox;
    D2DrlgOrthStrc* pNext;
};

struct D2PresetUnitStrc
{
    int unk0x00[3];
    D2PresetUnitStrc* pNext;
};

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x006665B0
void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit); // 0x006675D0
void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2DrlgOrthStrc* pDrlgOrth); // 0x0066B530
void __fastcall sub_0066B610(void* pMemPool, D2DrlgOrthStrc** ppDrlgOrth, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B610
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C6E0
void __fastcall DRLGROOMTILE_FreeTileGrid(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F0B0
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D610

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0066B3E0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType)
{
    D2DrlgRoomStrc* pDrlgRoom = (D2DrlgRoomStrc*)sub_0040B430(pLevel->pDrlg->pMempool, sizeof(D2DrlgRoomStrc), ".\\DRLG\\DrlgRoom.cpp", 32, 0);
    memset(pDrlgRoom, 0, sizeof(D2DrlgRoomStrc));
    pDrlgRoom->nType = nType;
    pDrlgRoom->pLevel = pLevel;
    pDrlgRoom->fRoomStatus = 4;
    SEED_InitLowSeed(&pDrlgRoom->pSeed, (unsigned int)SEED_RollRandomNumber(&pLevel->pSeed));
    pDrlgRoom->dwInitSeed = (unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed);
    if (pLevel->dwFlags & DRLGLEVELFLAG_AUTOMAP_REVEAL)
    {
        pDrlgRoom->dwFlags |= DRLGROOMFLAG_AUTOMAP_REVEAL;
    }
    switch (nType)
    {
    case DRLGTYPE_MAZE:
        sub_0067D6D0(pDrlgRoom);
        break;
    case DRLGTYPE_PRESET:
        DRLGPRESET_AllocPresetRoomData(pDrlgRoom);
        break;
    }
    return pDrlgRoom;
}

// 0x006706A0
int __fastcall DRLGTILESUB_PickSubThemes(D2DrlgRoomStrc* pDrlgRoom, int nSubType, int nSubTheme)
{
    if (nSubType != -1 && nSubTheme != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(nSubType);
        int nMask = 0;
        int nCounter = 0;
        while (pLvlSubTxtRecord->dwType == nSubType)
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed) % 100) < pLvlSubTxtRecord->nProb[nSubTheme])
            {
                nMask |= 1 << nCounter;
                pDrlgRoom->dwDT1Mask |= pLvlSubTxtRecord->dwDt1Mask;
            }
            ++pLvlSubTxtRecord;
            ++nCounter;
        }
        return nMask;
    }
    return 0;
}

// 0x0066B970
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom)
{
    pDrlgRoom->pDrlgRoomNext = pLevel->pFirstRoomEx;
    ++pLevel->nRooms;
    pLevel->pFirstRoomEx = pDrlgRoom;
}

// 0x0066BA70
int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case DRLGTYPE_MAZE:
        return 1;

    case DRLGTYPE_PRESET:
        return pDrlgRoom->dwFlags & DRLGROOMFLAG_NO_LOS_DRAW;
    }

    return 0;
}

// 0x0066BAB0
int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BFA0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_AUTOMAP_REVEAL))
    {
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_PRESET_UNITS_SPAWNED)
        {
            return 0;
        }

        pDrlgRoom->dwFlags |= DRLGROOMFLAG_PRESET_UNITS_SPAWNED;
    }

    return pDrlgRoom->pPresetUnits;
}

// 0x0066B980
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX >= pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY < pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066B9D0
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX > pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY <= pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066BA20
int __fastcall sub_0066BA20(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    int nLeft = 5 * pDrlgCoord->nPosX;
    if (nX < nLeft)
    {
        return 0;
    }

    if (nX >= nLeft + 5 * pDrlgCoord->nWidth)
    {
        return 0;
    }

    int nTop = 5 * pDrlgCoord->nPosY;
    if (nY < nTop)
    {
        return 0;
    }

    return nY < nTop + 5 * pDrlgCoord->nHeight;
}

// 0x0066BA90
unsigned int __fastcall sub_0066BA90(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case 1:
        return sub_0067D7A0(pDrlgRoom);
    }

    return 0;
}

// 0x0066BAA0
unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->dwFlags & 0x30000;
}

// 0x0066BAC0
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel)
{
    int nDestinationLevel;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2ActiveRoomStrc* pRoom = DRLGWARP_GetDestinationRoom(pDrlgRoom, nSourceLevel, &nDestinationLevel, &pLvlWarpTxtRecord);
    if (!pRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 604);
        exit(-1);
    }

    pDrlgRoom = DUNGEON_GetRoomExFromRoom(pRoom);
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 606);
        exit(-1);
    }

    if (!pDrlgRoom->pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 607);
        exit(-1);
    }

    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BB20
int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 619);
        exit(-1);
    }

    if (pDrlgRoom->dwFlags & 0x800000)
    {
        return 0;
    }

    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BB60
int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* ptRoom)
{
    if (!ptRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 630);
        exit(-1);
    }

    return DRLGROOM_CheckWaypointFlags(ptRoom) != 0;
}

// 0x0066BBA0
const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->nType == 2)
    {
        return DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(pDrlgRoom);
    }

    return "None";
}

// 0x0066BCF0
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->nRoomsNear;
}

// 0x0066BFC0
void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom)
{
    pDrlgRoom->pRoom = pRoom;
}

// 0x0066C040
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* ptVisInfo = pDrlg->pWarp; ptVisInfo; ptVisInfo = ptVisInfo->pNext)
    {
        if (!ptVisInfo->nLevel)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1040);
            exit(-1);
        }

        if (nLevelId == ptVisInfo->nLevel)
        {
            return ptVisInfo->nVis;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwVis;
}

// 0x0066C020
int __fastcall sub_0066C020_GetDrlgTypeFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return DATATBLS_GetLevelDefRecord(pDrlgRoom->pLevel->nLevelId)->dwDrlgType;
}

// 0x0066C090
int* __fastcall sub_0066C090_GetVisArrayFromLevel(D2DrlgLevelStrc* pLevel)
{
    return DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
}

// 0x0066C100
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;

    DRLGROOM_FreeRoomTiles(pMemPool, pDrlgRoom);

    if (pDrlgRoom->ppRoomsNear)
    {
        sub_0040B480(pMemPool, pDrlgRoom->ppRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 105, 0);
        pDrlgRoom->nRoomsNear = 0;
        pDrlgRoom->ppRoomsNear = 0;
    }

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTROOM_FreeDrlgOutdoorRoom(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_FreePresetRoomData(pDrlgRoom);
        break;
    }

    D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits;
    while (pPresetUnit)
    {
        D2PresetUnitStrc* pFree = pPresetUnit;
        pPresetUnit = pPresetUnit->pNext;
        DRLGPRESET_FreePresetUnit(pMemPool, pFree);
    }

    D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth;
    while (pDrlgOrth)
    {
        D2DrlgOrthStrc* pCurrent = pDrlgOrth;
        pDrlgOrth = pDrlgOrth->pNext;
        if (pCurrent->bInit == 1)
        {
            D2DrlgRoomStrc* pTarget = pCurrent->pTarget;
            sub_0066B610(pMemPool, &pDrlgRoom->pDrlgOrth, pTarget);
            sub_0066B610(pMemPool, &pTarget->pDrlgOrth, pDrlgRoom);
        }
    }

    DRLGROOM_FreeRoomData(pMemPool, pDrlgRoom->pDrlgOrth);

    D2DrlgLevelStrc* pLevel = pDrlgRoom->pLevel;
    D2DrlgRoomStrc* pCurrentRoomEx = pLevel->pFirstRoomEx;
    if (pCurrentRoomEx == pDrlgRoom)
    {
        pLevel->pFirstRoomEx = pDrlgRoom->pDrlgRoomNext;
        --pLevel->nRooms;
    }
    else
    {
        while (pCurrentRoomEx->pDrlgRoomNext)
        {
            if (pCurrentRoomEx->pDrlgRoomNext == pDrlgRoom)
            {
                pCurrentRoomEx->pDrlgRoomNext = pDrlgRoom->pDrlgRoomNext;
                --pLevel->nRooms;
                break;
            }

            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
        }
    }

    DRLGROOMTILE_FreeTileGrid(pDrlgRoom);
    DRLGLOGIC_FreeDrlgCoordList(pDrlgRoom);
    sub_0040B480(pMemPool, pDrlgRoom, ".\\DRLG\\DrlgRoom.cpp", 174, 0);
}
