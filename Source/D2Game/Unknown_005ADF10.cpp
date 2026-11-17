struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwMissileMode;
};

struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[4];
    char unk0x008[0x06];
    short wSrvHitFunc;
    short wSrvDmgFunc;
    char unk0x012[0x174];
    unsigned char nCollideKill;
    unsigned char nCollideFriend;
    unsigned char nNextHit;
    unsigned char nNextDelay;
    unsigned char unk0x18A;
    unsigned char nToHit;
    unsigned char nAlwaysExplode;
    char unk0x18D[0x17];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    void* pMissilesLinker;
    int nMissilesTxtRecordCount;
};

struct D2DamageStrc
{
    int nData[0x1C];
};

struct D2StatListStrc;
struct D2ActiveRoomStrc;
typedef int (__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);
typedef void (__fastcall* MISSILESRVDMGFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern int gnMissileSrvHitFnCount;                                                                          // 0x0073C83C
extern MISSILESRVHITFN gpfMissileSrvHitFn[];                                                                // 0x0073C840
extern int gnMissileSrvDmgFnCount_0073C95C;                                                                 // 0x0073C95C
extern MISSILESRVDMGFN gpfMissileSrvDmgFn_0073C960[];                                                       // 0x0073C960
void __fastcall MISSMODE_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);          // 0x005ADAF0
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);// 0x005AD730
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile);// 0x0057D9B0
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage);// 0x005C0C30
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);// 0x005A89A0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);// 0x005417D0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask);// 0x0064EBA0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID);// 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove);// 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag);// 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                            // 0x0064A470
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                                   // 0x0064A400
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005ADA40_CheckMissileMode(int, D2UnitStrc*); // 0x005ADA40
// 0x005ADA40
static int sub_005ADA40_CheckMissileMode(int nMissileMode, D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    switch (nMissileMode)
    {
    case 0:
        return 0;
    case 1:
        if (nUnitType != 0)
            return 0;
        break;
    case 2:
        if (nUnitType != 1)
            return 0;
        break;
    case 3:
        return 1;
    }
    return 1;
}

static __declspec(noinline) int sub_005ADA80_GetPierceFlags(D2UnitStrc* pUnit);
static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pUnit); // 0x005ADA80
// 0x005ADA80
static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pUnit);

// 0x005ADA80
static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pUnit)
{
    int nResult = 3;
    D2MissilesTxt* pTxt;
    if (!pUnit || pUnit->dwClassId < 0 || pUnit->dwClassId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        pTxt = 0;
    }
    else
    {
        pTxt = sgptDataTables->pMissilesTxt + pUnit->dwClassId;
    }

    if (pTxt->nFlags[0] & gdwBitMasks_006CE268[2])
    {
        int nPierce = STATLIST_UnitGetStatValue(pUnit, 328, 0);
        if (nPierce)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pUnit, 328, nPierce - 1, 0);
        }
    }
    return nResult;
}

static void __fastcall sub_005ADB00_SetJustHitState(D2UnitStrc*, D2UnitStrc*); // 0x005ADB00
// 0x005ADB00
static void __fastcall sub_005ADB00_SetJustHitState(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pTxt->nNextHit || !pUnit)
        return;

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pMissile);
    const int nDelay = pTxt->nNextDelay + pGame->dwGameFrame;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nDelay, pUnit->dwUnitType, pUnit->dwUnitId);
    if (!pStatList)
        return;

    EVENT_SetEvent(pGame, pUnit, 0xC, nDelay, 0, 0);
    STATLIST_SetState(pStatList, 0x56);
    STATLIST_SetStatRemoveCallback(pStatList, MISSMODE_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, 0x56, 1);
}

static void __fastcall sub_005ADCD0_ApplyDamageFlags(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x005ADCD0
// 0x005ADCD0
static void __fastcall sub_005ADCD0_ApplyDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    MISSMODE_SetDamageFlags(pGame, pMissile, pUnit, pDamage);
    if (pUnit && pUnit->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pUnit))
    {
        const int nDamageTargetAc = STATLIST_UnitGetStatValue(pMissile, 0x78, 0);
        if (nDamageTargetAc)
        {
            int nArmor = nDamageTargetAc + STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
            if (nArmor < 0)
                nArmor = 0;
            STATLIST_SetUnitStat(pUnit, 0x1F, nArmor, 0);
        }
    }
}

// 0x005ADF10
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision)
{
    D2MissilesTxt* pTxt;
    if (!pMissile || pMissile->dwClassId < 0 || pMissile->dwClassId >= sgptDataTables->nMissilesTxtRecordCount)
        pTxt = 0;
    else
        pTxt = &sgptDataTables->pMissilesTxt[pMissile->dwClassId];

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nHitResult = 2;
    int nPierceFlags = 3;
    if (pTxt->nFlags[0] & gdwBitMasks_006CE268[1])
    {
        nHitResult = 0;
    }

    if (pUnit)
    {
        if ((pTxt->nNextHit && STATES_CheckState(pUnit, 0x56)) || MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        {
            return 1;
        }

        MISSILE_SetOwner(pMissile, pUnit);
        if (!sub_005ADA40_CheckMissileMode(!pMissile ? 0 : pMissile->dwMissileMode, pUnit))
        {
            return 1;
        }

        if (pOwner && !sub_00554200(pGame, pOwner, pUnit) && !pTxt->nCollideFriend)
        {
            return 1;
        }
    }

    if (pOwner && pUnit && (pTxt->nFlags[0] & gdwBitMasks_006CE268[2])
        && (STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0)))
    {
        nPierceFlags = sub_005ADA80_GetPierceFlags(pMissile);
    }

    if (pTxt->nCollideKill)
    {
        nHitResult |= 1;
    }

    if (pUnit)
    {
        if (pTxt->nToHit)
        {
            int nToHit = 0;
            if (pMissile)
            {
                nToHit = STATLIST_UnitGetStatValue(pMissile, 0x13, 0);
            }

            if (!SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1))
            {
                sub_005ADB00_SetJustHitState(pMissile, pUnit);
                SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
                if (pTxt->nAlwaysExplode)
                {
                    const short nHitFunc = pTxt->wSrvHitFunc;
                    if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
                    {
                        if (gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit) & 4)
                        {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
    }
    else if (!bForceCollision && !pTxt->nAlwaysExplode)
    {
        goto finish_collision;
    }

    if (nPierceFlags & 2)
    {
        sub_005ADB00_SetJustHitState(pMissile, pUnit);
        SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
        const short nHitFunc = pTxt->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            nHitResult = gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit);
            if (nHitResult & 4)
            {
                return 1;
            }
        }
    }

    if (pUnit && (nHitResult & 2))
    {
        D2DamageStrc tDamage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
        const short nDmgFunc = pTxt->wSrvDmgFunc;
        if (nDmgFunc > 0 && nDmgFunc < gnMissileSrvDmgFnCount_0073C95C)
        {
            gpfMissileSrvDmgFn_0073C960[nDmgFunc](pGame, pMissile, pUnit, &tDamage);
        }
        sub_005ADCD0_ApplyDamageFlags(pGame, pMissile, pUnit, &tDamage);
    }

finish_collision:
    if (((nHitResult & 1) || bForceCollision) && (nPierceFlags & 1))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            COLLISION_ResetMaskWithSize(pRoom, UNITS_GetXPosition(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
        }
        return 2;
    }
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_005ADF10.inc"
