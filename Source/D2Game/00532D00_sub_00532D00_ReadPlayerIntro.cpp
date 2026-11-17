extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define NUM_DIFFICULTIES 3
#define PLRSAVE2ERROR_BAD_PLAYERINTRO 11

struct D2GameStrc;
struct D2InventoryStrc;
struct D2PlrIntroStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x48];
    int dwUniqueId;
    int bBusy;
    char unk0x50[0x10];
    D2PlrIntroStrc* pPlayerIntro[NUM_DIFFICULTIES];
};

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[NUM_DIFFICULTIES][8];
    unsigned char unk0x1C[NUM_DIFFICULTIES][8];
};

struct D2RosterIterateStrc
{
    int bFlag;
    D2UnitStrc* pUnit;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall sub_00535AF0_RosterFlagCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);              // 0x00535AF0
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall PLRINTRO_CopyBufferToQuestIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572540
void __fastcall PLRINTRO_CopyBufferToNpcIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer);   // 0x00572550
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory);                            // 0x0063BF90

// 0x00532D00
int __fastcall sub_00532D00_ReadPlayerIntro(D2UnitStrc* pUnit, const D2PlrIntroSaveStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;
    D2PlrIntroSaveStrc plrIntro = *pSection;
    if (plrIntro.nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    for (int i = 0; i < NUM_DIFFICULTIES; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.unk0x04[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.unk0x1C[i]);
    }

    *pSize = sizeof(D2PlrIntroSaveStrc);
    return 0;
}

// 0x005350B0
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(pPlayerData->bBusy != 0, 0x1C7);

    pPlayerData->bBusy = 0;
}

// 0x005353F0
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer)
{
    D2_ASSERT(pPlayer, 0x24D);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x250);

    return pPlayerData->dwUniqueId;
}

// 0x00535B10
int __fastcall PLAYER_HasHostilePlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};

    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;

    SUNIT_IterateLivingPlayers(pGame, sub_00535AF0_RosterFlagCb, &rosterIterate);
    return rosterIterate.bFlag;
}

// 0x00535D10
void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pAttacker, int bTemporaryWeaponStats)
{
    if (bTemporaryWeaponStats)
    {
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
        }

        D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pAttacker->pInventory);
        if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
        }
    }

    if (UNITS_CanDualWield(pAttacker))
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (!pWeapon)
        {
            if (pLeftHandWeapon)
            {
                if (STATLIST_GetOwner(pLeftHandWeapon, 0))
                {
                    STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
                }
            }
        }
        else if (pWeapon == pLeftHandWeapon)
        {
            D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pAttacker->pInventory);
            if (STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
            }

            if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
            }
        }
        else
        {
            if (STATLIST_GetOwner(pWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pWeapon, 1);
            }

            if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
            }
        }
    }
}

// 0x00535E20
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pTarget, int bTemporaryWeaponStats)
{
    if (!bTemporaryWeaponStats)
    {
        return;
    }

    D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pTarget->pInventory);
    if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
    {
        STATLIST_MergeStatLists(pTarget, pLeftHandWeapon, 1);
    }

    D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pTarget->pInventory);
    if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon)
    {
        if (STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pTarget, pSecondaryWeapon, 0);
        }
    }
}
