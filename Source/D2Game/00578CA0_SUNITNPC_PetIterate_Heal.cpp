struct D2ClientStrc;
struct D2GameStrc;
struct D2StatListStrc;
struct D2UnitStrc;

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit);                                         // 0x00578C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00554D00
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit);                                             // 0x00622DE0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
void __fastcall D2GAME_SendPacket0x2A_6FC3F3B0(D2ClientStrc* pClient, unsigned char nHeader, int nCode, int nGold, int nUnitGUID, int a6); // 0x0053D740
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost);                  // 0x00576D90
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc);     // 0x00578D30

// 0x00578CA0
void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, void* a4)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, 6, nMaxHp, 0);
        *(unsigned char*)a4 = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, 2);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, 1);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        *(unsigned char*)a4 = 1;
    }
}

// 0x00578ED0
void __fastcall D2GAME_NPC_PurchaseHeal_6FCCB280(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID)
{
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
    if (!pNpc || pInteractUnit != pNpc)
    {
        return;
    }

    int nStatRestored = 0;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) != nMaxHp)
    {
        nStatRestored = 1;
    }

    unsigned int nHealingCost = UNITS_GetHealingCost(pUnit);
    if (!nHealingCost)
    {
        nHealingCost = 1;
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 8, 0) != nMaxMana)
    {
        nStatRestored = 1;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 10, 0) == nMaxStamina && !nStatRestored)
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, 3848), 0x2A, 14, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
        return;
    }

    if (STATLIST_UnitGetStatValue(pUnit, 14, 0) + STATLIST_UnitGetStatValue(pUnit, 15, 0) >= nHealingCost)
    {
        if (!sub_00576D90_SpendGold(pGame, pUnit, nHealingCost))
        {
            D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, 3861), 0x2A, 9, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
            return;
        }

        D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, 3874), 0x2A, 6, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
    }
    else
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, 3868), 0x2A, 12, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, 0);
    }
}
