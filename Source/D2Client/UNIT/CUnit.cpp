#include "D2Client.h"

#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define PLRMODE_NEUTRAL 1
#define PLRMODE_TOWNNEUTRAL 5
#define PLRMODE_DEAD 17
#define MONSTATS2FLAGINDEX_ISATT 9
#define UNITFLAG_CANBEATTACKED 0x00000004
#define UNITFLAG_ISDEAD 0x00010000
#define UNIT_HASH_BUCKETS 0x80
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gpUnitTable_007A5670 (gpUnitHashTable_007A5270 + 2 * UNIT_HASH_BUCKETS)
#define gpUnitTable_007A6270 (gpUnitHashTable_007A5E70 + 2 * UNIT_HASH_BUCKETS)
#define PLRMODE_DEATH 0
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define SKILLSFLAGINDEX_PERIODIC 6
struct D2PacketListStrc;
struct D2PlayerDataStrc;
struct D2MapAIStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2SkillsTxt;
struct D2SetsTxt;
struct D2SetItemsTxt;
struct D2UniqueItemsTxt;
struct D2HotkeyStrc;
struct Unicode;
struct D2ObjectDataStrc;
struct D2DrlgCoordsStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    unsigned char unk_18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x54 - 0x30];
    D2GfxDataStrc* pGfxData;
    int nCounter0x58;
    unsigned char unk_5C[0x8];
    void* pLight;
    int dwStartLight;
    char unk0x6C[0xC4 - 0x6C];
    unsigned int dwFlags;
    char unk0xC8[0xD8 - 0xC8];
    D2PacketListStrc* pPacketList;
    char unk0xDC[0xE4 - 0xDC];
    D2UnitStrc* pListNext;
    D2UnitStrc* pRoomNext;
};

struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short wNameStr;
    unsigned char unk_08[0x10];
    short wMonStatsEx;
    char unk0x1A[0x1A8 - 0x1A];
};

struct D2MonStats2Txt
{
    int dwId;
    unsigned char nFlags[4];
    char unk0x08[0x134 - 0x08];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xA90 - 0xA84];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[4];
    int nMonStats2TxtRecordCount;
    unsigned char unk_A9C[0xFC];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x68];
    D2SetsTxt* pSetsTxt;
    int nSetsTxtRecordCount;
    char unk0xC14[0x4];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x4];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2ObjectsTxt
{
    char unk0x00[0x40];
    Unicode wszName[64];
    char f_C0[0x7A];
    unsigned char nIsDoor;
    unsigned char unk_13B[0x2C];
    unsigned char nSubClass;
    unsigned char unk_168[0x9];
    unsigned char nLockable;
    char unk0x172[0x46];
    unsigned char nOpenWarp;
    unsigned char unk_1B9[0x1];
};

struct D2LevelsTxt
{
    char unk0x00[0x02];
    unsigned char nAct;
    unsigned char unk_03[0x1BB];
    unsigned short wszLevelWarp[40];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2UnitStrc* gpPlayerUnit_007A6A70; // 0x007A6A70
extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634
extern D2UnitStrc* gpUnitHashTable_007A5270[6 * UNIT_HASH_BUCKETS]; // 0x007A5270
extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * UNIT_HASH_BUCKETS]; // 0x007A5E70
void __fastcall sub_00480810_OnUnitA(D2UnitStrc* pUnit); // 0x00480810
void __fastcall sub_0046D780(D2UnitStrc* pUnit); // 0x0046D780
void __fastcall sub_004BDEE0(D2UnitStrc* pUnit); // 0x004BDEE0
int __fastcall sub_0046F1F0(D2GfxDataStrc* pGfxData); // 0x0046F1F0
int __fastcall sub_0046F250(D2GfxDataStrc* pGfxData); // 0x0046F250
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
int __fastcall sub_004BC5E0(D2UnitStrc* pUnit, int nArg); // 0x004BC5E0
void __fastcall sub_00480420_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
short __fastcall sub_00479C00(D2UnitStrc* pUnit); // 0x00479C00
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

struct D2SkillsTxt
{
    char unk0x00[0x08];
    unsigned char nFlags[8];
    unsigned char unk_10[0x5];
    unsigned char nSelectProc;
    char unk0x16[0x226];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, void* pTarget, int nArg); // 0x00461250
void __cdecl sub_00466FE0(); // 0x00466FE0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
void __cdecl sub_004DBFE0_StopSkill(); // 0x004DBFE0
void __stdcall sub_0061ACD0_SetRoomPos(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged); // 0x0061ACD0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall sub_0061DBE0(int nLevelId); // 0x0061DBE0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20
void __cdecl sub_00459140_Refresh(); // 0x00459140
void __fastcall sub_00472C20_PlayerMoved(int nArg); // 0x00472C20
int __stdcall sub_00645630(D2UnitStrc* pUnit); // 0x00645630
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

enum
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[]; // 0x00711F34
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __fastcall sub_M210_EmitTest(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);
int __fastcall sub_M210_EmitUse(D2UnitStrc* pUnit);

struct D2SetsTxt { char unk0x000[0x128]; };

struct D2SetItemsTxt { char unk0x000[0x1B8]; };

struct D2UniqueItemsTxt { char unk0x000[0x14C]; };

#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};

#pragma pack(pop)
enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource); // 0x004743D0
void __cdecl sub_0049F960_ResetTextBox(); // 0x0049F960
void __stdcall sub_00416710_Unlock(void* pHandle); // 0x00416710
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern int gnGlobal_00721E34; // 0x00721E34
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gdwGlobal_007BCBF8; // 0x007BCBF8
extern D2TextHeaderStrc* gpTextHeader_007BF250; // 0x007BF250
extern int gnGlobal_007C0E7C; // 0x007C0E7C
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC
extern void* gpReply_008818D0; // 0x008818D0
extern "C" void* gpCDKeyHandle_00882744; // 0x00882744
extern "C" void* gpCDKeyHandle_00882750; // 0x00882750

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
};

struct D2ItemsTxt
{
    char unk0x00[0xF4];
    unsigned short wNameStr;
};

const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit); // 0x00463810
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
const Unicode* __fastcall sub_00464A30_GetWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pTile); // 0x00464A30
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit); // 0x00621B00
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    unsigned int bSpawned;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

void __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

int gnPeriodOfDay_007A6A74; // 0x007A6A74

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId_Inl
inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

// 0x004638A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00463900
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

// build: context CLIENT_FindUnitInHashTable_Inl
static __forceinline D2UnitStrc* CLIENT_FindUnitInHashTable_Inl(int nUnitId, int nUnitType)
{
    D2UnitStrc* pUnit = gpUnitHashTable_007A5270[(nUnitType << 7) + (nUnitId & 0x7F)];
    while (pUnit)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
        pUnit = pUnit->pListNext;
    }
    return 0;
}

// 0x00463CC0
void __stdcall sub_00463CC0_FreeUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            sub_00480810_OnUnitA(pUnit);
            D2UnitStrc* pFound = CLIENT_FindUnitInHashTable_Inl(nUnitId, nUnitType);
            if (pFound)
            {
                if (pFound->dwUnitType == UNIT_MONSTER)
                {
                    sub_0046D780(pFound);
                }
                else if (pFound->dwUnitType == UNIT_OBJECT)
                {
                    sub_004BDEE0(pFound);
                }
            }
            pUnit = pNext;
        }
    }
}

// 0x00463DE0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit()
{
    return gpPlayerUnit_007A6A70;
}

// 0x00463DF0
int __cdecl sub_00463DF0()
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (!pPlayer)
    {
        return 1;
    }
    return pPlayer->dwAnimMode == PLRMODE_DEAD;
}

// 0x00463E20
void __fastcall sub_00463E20_SetGfxField34(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x563);
    sub_0046F1C0(pUnit->pGfxData, nValue);
}

// 0x00463E50
int __fastcall sub_00463E50_GetGfxField34(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x56C);
    return sub_0046F1F0(pUnit->pGfxData);
}

// 0x00463E80
void __fastcall sub_00463E80_SetGfxField38(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x575);
    sub_0046F220(pUnit->pGfxData, nValue);
}

// 0x00463EB0
int __fastcall sub_00463EB0_GetGfxField38(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x57E);
    return sub_0046F250(pUnit->pGfxData);
}

// 0x00464370
int __fastcall sub_00464370_IsSelectedUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pSelected = sub_00467A10();
    if (pSelected && pSelected->dwUnitType == UNIT_OBJECT && (DATATBLS_GetObjectsTxtRecord(pSelected->dwClassId)->nSubClass & 0x80))
    {
        return 0;
    }
    return sub_00467A10() == pUnit;
}

static __forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00464420
void __fastcall sub_00464420_TurnTowardPlayer(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    D2_ASSERT(pPath, 0x7F3);
    UNITS_ChangeAnimMode(pUnit, 1);
    D2Common_10216(pPath, UNITS_GetXPositionInline(pPlayer), UNITS_GetYPositionInline(pPlayer), 0);
}

// 0x004644E0
void __fastcall sub_004644E0_PlayerFaceUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pPlayer && (pPlayer->dwAnimMode == PLRMODE_NEUTRAL || pPlayer->dwAnimMode == PLRMODE_TOWNNEUTRAL))
    {
        D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
        D2_ASSERT(pPath, 0x802);
        D2Common_10216(pPath, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), 0);
    }
}

// 0x004646A0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom()
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pPlayer)
    {
        return UNITS_GetRoom(pPlayer);
    }
    return 0;
}

// 0x004646C0
void __cdecl sub_004646C0_UpdateObjectsForPeriod()
{
    const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    if (nPeriod != gnPeriodOfDay_007A6A74)
    {
        gnPeriodOfDay_007A6A74 = nPeriod;
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A6270[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x88C);
                sub_004BC5E0(pUnit, 0);
                pUnit = pNext;
            }
        }
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A5670[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x896);
                sub_004BC5E0(pUnit, 0);
                pUnit = pNext;
            }
        }
    }
}

// 0x00464770
D2PacketListStrc* __fastcall sub_00464770_GetPacketList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x8A5);
    return pUnit->pPacketList;
}

// 0x004647A0
void __fastcall sub_004647A0_SetPacketList(D2UnitStrc* pUnit, D2PacketListStrc* pPacketList)
{
    D2_ASSERT(pUnit, 0x8AF);
    pUnit->pPacketList = pPacketList;
}

// 0x004647D0
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit)
{
    unsigned int dwFlags = pUnit->dwFlags & ~UNITFLAG_ISDEAD;
    pUnit->dwFlags = dwFlags;
    if (pUnit->dwUnitType != UNIT_MONSTER || sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_ISATT))
    {
        dwFlags |= UNITFLAG_CANBEATTACKED;
        pUnit->dwFlags = dwFlags;
    }
}

// 0x004648F0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit)
{
    sub_00480420_RefreshPathTarget(pUnit);
    D2_ASSERT(pUnit->pDynamicPath, 0x946);
    return PATH_GetTargetUnit(pUnit->pDynamicPath);
}

// 0x00464A30
const unsigned short* __fastcall sub_00464A30_GetTileLevelWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const int nLevelId = sub_0061A1D0_GetTileLevelId(pRoom, !pUnit ? -1 : pUnit->dwClassId);
    if (nLevelId)
    {
        return DATATBLS_GetLevelsTxtRecord(nLevelId)->wszLevelWarp;
    }
    return 0;
}

// 0x00464C40
int __fastcall sub_00464C40_DecrementCounter58(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA19);
    if (!pUnit->nCounter0x58)
    {
        return 0;
    }
    --pUnit->nCounter0x58;
    return !STATES_CheckState(pUnit, 0x8F);
}

// 0x00464C90
void __fastcall sub_00464C90_SetCounter58(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA34);
    pUnit->nCounter0x58 = 3;
}

// 0x00464CF0
void __fastcall sub_00464CF0_SetStartLight(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0xA4A);
    pUnit->dwStartLight = nValue;
}

// 0x00465400
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return sub_00479C00(pUnit);
    }
    return -1;
}

// 0x00465BF0
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget && pTarget != pUnit)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2_ASSERT(pPath, 0x7E2);
        D2Common_10216(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nArg);
    }
}

// 0x00463B80
static void sub_00463B80_QueueIdleMove(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nMode = pUnit->dwAnimMode;
        if (UNITS_GetRoom(pUnit))
        {
            switch (nMode)
            {
            case PLRMODE_NEUTRAL:
            case PLRMODE_TOWNNEUTRAL:
                sub_00461250_QueueMove(7, pUnit, 0, 1);
                break;
            }
        }
    }
}

// 0x004654C0
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int bFlag)
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pUnit == pPlayer)
    {
        sub_00466FE0();
    }
    D2ActiveRoomStrc* pRoom = sub_00465420_FindRoomAt(nX, nY);
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2_ASSERT(pDynamicPath, 0x166);
    if (nX && nY)
    {
        D2_ASSERT(pRoom, 0x168);
    }
    if (pUnit->dwFlags & 0x10000)
    {
        return;
    }
    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == PLRMODE_DEATH || nMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    case UNIT_MONSTER:
        if (nMode == MONMODE_DEATH || nMode == MONMODE_DEAD)
        {
            return;
        }
        break;
    }
    if (pUnit == pPlayer)
    {
        D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pUnit);
        if (pOldRoom)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
            D2SkillsTxt* pSkillsTxtRecord;
            if (pSkill && (pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill)) != 0 && (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_PERIODIC & 7]))
            {
                bFlag = 0;
            }
            else if (bFlag)
            {
                D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x17D);
                sub_004DBFE0_StopSkill();
            }
        }
        if (pRoom)
        {
            sub_0061ACD0_SetRoomPos(pRoom, nX, nY, pOldRoom != pRoom);
            sub_004F5190_SetTownMode(!sub_0061DBE0(DUNGEON_GetLevelIdFromRoom(pRoom)));
            if (pOldRoom)
            {
                D2LevelsTxt* pOldLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pOldRoom));
                D2LevelsTxt* pNewLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (pOldLevel->nAct != pNewLevel->nAct)
                {
                    sub_004FB480_SetActA(pNewLevel->nAct);
                    sub_00600C00_SetActB(pNewLevel->nAct);
                }
            }
        }
    }
    if (!sub_00650BE0_PlaceUnit(pDynamicPath, pUnit, pRoom, nX, nY))
    {
        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
        COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 1);
        D2_ASSERT(D2Common_10231(pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY), 0x1A9);
    }
    sub_00459140_Refresh();
    if (pUnit == pPlayer)
    {
        sub_00472C20_PlayerMoved(bFlag);
    }
    sub_00463B80_QueueIdleMove(pUnit);
}

// 0x00464210
int __fastcall sub_00464210_SkillSelectProc1(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return sub_00645680_CanUnitCorpseBeSelected(pTarget);
}

// 0x00464280
int __fastcall sub_00464280_SkillSelectProc4(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11018(pTarget);
}

// 0x00464290
int __fastcall sub_00464290_SkillSelectProc6(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return sub_00645630(pTarget);
}

// 0x004642A0
int __fastcall sub_004642A0_SkillSelectProc5(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11019(pTarget);
}

// 0x004643B0
int __fastcall sub_004643B0_IsPlayerOrMonster(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x793);
    const int nType = pUnit->dwUnitType;
    return nType == 0 || nType == 1;
}

// 0x00464CC0
int __fastcall sub_00464CC0_GetField68(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA3F);
    return pUnit->dwStartLight;
}

// 0x00464E20
static __forceinline void sub_00464E20_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay)
{
    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

void __fastcall sub_M109_Emit_00464E20(D2UnitStrc* pUnit, int nOverlay)
{
    if (pUnit)
        sub_00464E20_PlayOverlaySound(pUnit, nOverlay);
}

// 0x00464220
int __fastcall sub_00464220_SkillSelectProc2(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

// 0x00464230
int __fastcall sub_00464230_SkillSelectProc3(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (!pTarget)
        return 0;
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
        return 0;
    if (!sub_004B11F0(pTarget))
        return 0;
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    if (nType != 1)
        return 0;
    int nClass = sub_00463860(pTarget);
    if (nClass >= 0 && nClass < sgptDataTables->nMonStatsTxtRecordCount && nClass == 0x4E)
        return 0;
    return 1;
}

// 0x00464E50
void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        sub_00470390(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

// 0x00464310
static int __stdcall sub_00464310_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1674)))
        return 1;

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1678)) != 0;
}

int __fastcall sub_M210_Emit_00464310(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (!sub_M210_EmitTest(pPlayer, pUnit))
        return 0;
    if (sub_00464310_CheckMonsterSkillSelect(pUnit, pPlayer))
        return sub_M210_EmitUse(pUnit);
    return sub_M210_EmitUse(pPlayer);
}

D2WheelCallbackFn gpfnWheelUp_007A7404; // 0x007A7404

D2WheelCallbackFn gpfnWheelDown_007A7408; // 0x007A7408

D2UnitStrc* gpAiTargets_007A7470[1]; // 0x007A7470

int gnGlobal_007BCE2C; // 0x007BCE2C

// 0x00464810
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case 0:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case 1:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00464930
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// 0x004693B0
void __fastcall sub_004693B0(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp_007A7404)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp_007A7404), 0x383);
            gpfnWheelUp_007A7404();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown_007A7408)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown_007A7408), 0x38B);
            gpfnWheelDown_007A7408();
        }
    }
}

// 0x00469AA0
unsigned short __fastcall sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469D70
void __fastcall sub_00469D70(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall sub_00469D90(int nA, int nB)
{
    return sub_00469AA0(nA, nB) != 0xFFFF;
}

// 0x0046D750
void __cdecl sub_0046D750()
{
    for (int i = 0; i < 8; ++i)
    {
        gpAiTargets_007A7470[i] = 0;
    }
}

// 0x00483410
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483960
void __cdecl sub_00483960()
{
    gabColors_007BCAD8[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabColors_007BCAD8[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabColors_007BCAD8[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabColors_007BCAD8[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = D2Win_10034_MixRGB(0x80, 0x40, 0x40);
}

// 0x00489840
int __cdecl sub_00489840_IsNpcState123()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3)
    {
        return 1;
    }

    return 0;
}

// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gnGlobal_007BCE2C = 1;
    if (gdwGlobal_007BCBF0 == 13)
    {
        gdwGlobal_007BCBF0 = 12;
    }

    sub_00455F20(5, 1, 0);
}

// 0x004898D0
void __fastcall sub_004898D0(int nState)
{
    gnGlobal_00721E34 = nState;
    if (nState == 0)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x004A1730
void __cdecl sub_004A1730_ClearPanel()
{
    sub_0049F960_ResetTextBox();
    gnGlobal_007BF1FA = 0;
    if (gpTextHeader_007BF250)
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

// 0x004B8A10
int __cdecl sub_004B8A10()
{
    if (gnGlobal_007C0E7C == 1 || gnGlobal_007C0E7C == 2)
    {
        return 1;
    }

    return 0;
}

// 0x005125B0
void __cdecl sub_005125B0_DDrawFreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs_008815AC)
    {
        FOG_Free(gpDDrawDebugFontGlyphs_008815AC, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs_008815AC = 0;
    }
}

// 0x0051B210
void __cdecl sub_0051B210_FreeBuffer()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

// 0x005239C0
void __cdecl sub_005239C0_UnlockCDKeys()
{
    if (gpCDKeyHandle_00882744)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882744);
        gpCDKeyHandle_00882744 = 0;
    }

    if (gpCDKeyHandle_00882750)
    {
        sub_00416710_Unlock(gpCDKeyHandle_00882750);
        gpCDKeyHandle_00882750 = 0;
    }
}

// 0x00464A10
static D2UnitStrc* sub_00464A10_FindTileUnit(D2UnitStrc* pUnit)
{
    for (; pUnit; pUnit = pUnit->pRoomNext)
    {
        if (pUnit->dwUnitType == UNIT_TILE)
        {
            return pUnit;
        }
    }
    return 0;
}

// 0x00464A60
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit)
{
    const Unicode* pName;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pTile;
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRooms;
    int nValue;
    D2_ASSERT(pUnit, 0x99D);
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    {
        if (pUnit->pObjectData->pObjectTxt->nOpenWarp && pUnit->dwAnimMode == 2)
        {
            pRoom = UNITS_GetRoom(pUnit);
            pTile = sub_00464A10_FindTileUnit(pRoom->pUnitFirst);
            if (pTile)
            {
                return sub_00464A30_GetWarpName(pRoom, pTile);
            }
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = sub_00464A10_FindTileUnit(ppRooms[i]->pUnitFirst);
                    if (pTile)
                    {
                        return sub_00464A30_GetWarpName(ppRooms[i], pTile);
                    }
                }
            }
        }
        if (pUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            nValue = pUnit->dwAnimMode;
            unsigned short nStringId = 0xC9B;
            if (nValue == 5 || nValue == 4)
            {
                nStringId = 0xC9C;
            }
            else if (nValue == 0)
            {
                nStringId = 0xC99;
            }
            else if (nValue == 6)
            {
                nStringId = 0xC9D;
            }
            return D2LANG_GetStringFromTblIndex(nStringId);
        }
        if (sub_00621B00_IsShrine(pUnit))
        {
            return D2LANG_GetStringFromTblIndex(pUnit->pObjectData->InteractType + 0x2A39);
        }
        D2ObjectDataStrc* pObjectData = pUnit->pObjectData;
        if (pObjectData->pObjectTxt->nLockable && (pObjectData->InteractType & 0x80))
        {
            return D2LANG_GetStringFromTblIndex(0xCBE);
        }
        return pObjectData->pObjectTxt->wszName;
    }
    case UNIT_MONSTER:
    {
        pName = sub_00463810_GetMonsterName(pUnit);
        if (!sub_00526800(pName))
        {
            return D2LANG_GetStringFromTblIndex(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->wNameStr);
        }
        return pName;
    }
    case UNIT_PLAYER:
    case UNIT_MISSILE:
    case UNIT_TILE:
        return 0;
    case UNIT_ITEM:
        nValue = pUnit->dwClassId;
        return D2LANG_GetStringFromTblIndex(DATATBLS_GetItemsTxtRecord(nValue)->wNameStr);
    }
    return 0;
}

// 0x004656C0
static void sub_004656C0_ClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        sub_00470390(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        sub_00470390(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        sub_00470390(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, -0x37);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            sub_00470390(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        sub_00470390(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

void sub_I08_Emit_004656C0(D2UnitStrc* pUnit, int nClassId)
{
    sub_004656C0_ClassEffects(pUnit, nClassId);
}

// 0x004667F0
static void sub_004667F0_SpawnPresetUnitInRoom(D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    sub_00466730_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
}

void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            sub_004667F0_SpawnPresetUnitInRoom(pRoom, pPresetUnit);
        }
    }
}
