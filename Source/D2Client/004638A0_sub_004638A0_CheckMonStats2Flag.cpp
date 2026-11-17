struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2DrlgActStrc;
struct D2GfxDataStrc;
struct D2InventoryStrc;
struct D2PacketListStrc;

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
    char unk0x14[0x2C - 0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x54 - 0x30];
    D2GfxDataStrc* pGfxData;
    int nCounter0x58;
    char unk0x5C[0x68 - 0x5C];
    int dwStartLight;
    char unk0x6C[0xC4 - 0x6C];
    unsigned int dwFlags;
    char unk0xC8[0xD8 - 0xC8];
    D2PacketListStrc* pPacketList;
    char unk0xDC[0xE4 - 0xDC];
    D2UnitStrc* pListNext;
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
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
};

struct D2ObjectsTxt
{
    char unk0x000[0x167];
    unsigned char nSubClass;
};

struct D2LevelsTxt
{
    char unk0x000[0x1BE];
    unsigned short wszLevelWarp[40];
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70
int gnPeriodOfDay_007A6A74;                                                                                 // 0x007A6A74
extern D2DrlgActStrc* gpDrlgAct_007A0634;                                                                   // 0x007A0634
extern D2UnitStrc* gpUnitHashTable_007A5270[6 * UNIT_HASH_BUCKETS];                                            // 0x007A5270
extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * UNIT_HASH_BUCKETS];                                            // 0x007A5E70
#define gpUnitTable_007A5670 (gpUnitHashTable_007A5270 + 2 * UNIT_HASH_BUCKETS)
#define gpUnitTable_007A6270 (gpUnitHashTable_007A5E70 + 2 * UNIT_HASH_BUCKETS)

void __fastcall sub_00480810_OnUnitA(D2UnitStrc* pUnit);                                                    // 0x00480810
void __fastcall sub_0046D780(D2UnitStrc* pUnit);                                                            // 0x0046D780
void __fastcall sub_004BDEE0(D2UnitStrc* pUnit);                                                            // 0x004BDEE0
void __fastcall sub_0046F1C0(D2GfxDataStrc* pGfxData, int nValue);                                          // 0x0046F1C0
int __fastcall sub_0046F1F0(D2GfxDataStrc* pGfxData);                                                       // 0x0046F1F0
void __fastcall sub_0046F220(D2GfxDataStrc* pGfxData, int nValue);                                          // 0x0046F220
int __fastcall sub_0046F250(D2GfxDataStrc* pGfxData);                                                       // 0x0046F250
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __fastcall sub_004BC5E0(D2UnitStrc* pUnit, int nArg);                                                   // 0x004BC5E0
void __fastcall sub_00480420_RefreshPathTarget(D2UnitStrc* pUnit);                                          // 0x00480420
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
int __stdcall sub_0061A1D0_GetTileLevelId(D2ActiveRoomStrc* pRoom, int nClassId);                           // 0x0061A1D0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
short __fastcall sub_00479C00(D2UnitStrc* pUnit);                                                           // 0x00479C00
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

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
