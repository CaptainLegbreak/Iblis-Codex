struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

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
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x10];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define MONMODE_NEUTRAL 1
#define MONMODE_WALK 2
#define UNITFLAG_DOUPDATE 0x00000001
#define MONSTATSFLAGINDEX_BOSS 6
#define MONSTATSFLAGINDEX_SWITCHAI 16

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit);                                                   // 0x006209D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DC00
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit);                                       // 0x006272E0
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);                                                    // 0x00624390

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x00623470
int __fastcall UNITS_CanSwitchAI(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
        return 0;
    if (!sub_0046C140_CheckMonStats2ModeFlag(nMonsterId, MONMODE_WALK))
        return 0;
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7])
        return 0;
    return (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_SWITCHAI >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_SWITCHAI & 7]) != 0;
}

// 0x00623830
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit)
{
    int nY = UNITS_GetYPositionInline(pUnit);
    int nX = UNITS_GetXPositionInline(pUnit);
    COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), nX, nY, UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
}

// 0x00623C60
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (D2UnitStrc* pItem = D2Common_10434(pUnit, 1))
        return ITEMS_GetWeaponClassId(pItem);
    return 0;
}

// 0x00624690
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType == UNIT_TILE)
        return 0;
    if (pUnit->dwAnimMode != nMode)
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwAnimMode = nMode;
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        STATLIST_DeactivateTemporaryStates(pUnit);
        sub_00624390_AnimInit(pUnit);
        return 1;
    }
    if (!(pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_NEUTRAL))
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
    }
    return 0;
}
