struct D2GameStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x70];
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillFlags;
    int nLeftSkillFlags;
    int nSwitchRightSkillId;
    int nSwitchLeftSkillId;
    int nSwitchRightSkillFlags;
    int nSwitchLeftSkillFlags;
};

#define UNIT_PLAYER 0
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_LEVEL 12
#define STAT_GOLD 14
#define STAT_GOLDBANK 15
#define STAT_NEXTEXP 30
#define STAT_VELOCITYPERCENT 67
#define STAT_ATTACKRATE 68
#define STAT_OTHER_ANIMRATE 69

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                       // 0x006221A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                   // 0x00623460
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __fastcall CLIENTS_GetSkillHotKey(D2ClientStrc* pClient, int nId, int* pSkillId, int* pHand, int* pItemGUID); // 0x005390D0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, int nSkillId, int nHand, int nItemGUID); // 0x005390A0
int __fastcall sub_0056AF20_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex);        // 0x0056AF20
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel);                                           // 0x00611800
unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc* pClient);                                    // 0x00539220
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc* pClient);                              // 0x0053E110

inline void UNITS_SetInventoryGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetInventoryGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLD, nGold, 0);
    }
}

inline void UNITS_SetStashGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetStashGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, nGold, 0);
    }
}

// 0x0056AF80
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrSave2.cpp", 2222);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);

    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pUnit))
    {
        UNITS_SetInventoryGold(pUnit, 0);
    }

    const int nGoldBank = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDBANK, 0);
    if (nGoldBank < 0 || nGoldBank > UNITS_GetStashGoldLimit(pUnit))
    {
        UNITS_SetStashGold(pUnit, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);

    for (int i = 0; i < 16; ++i)
    {
        int nSkillId;
        int nHand;
        int nItemIndex;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkillId, &nHand, &nItemIndex);
        if (nItemIndex)
        {
            nItemIndex = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, nItemIndex);
            CLIENTS_SetSkillHotKey(pClient, i, nSkillId, nHand, nItemIndex);
        }
    }

    if (pPlayerData->nLeftSkillFlags)
    {
        pPlayerData->nLeftSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillFlags)
    {
        pPlayerData->nRightSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nRightSkillFlags);
    }

    if (pPlayerData->nSwitchLeftSkillFlags)
    {
        pPlayerData->nSwitchLeftSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchLeftSkillFlags);
    }

    if (pPlayerData->nSwitchRightSkillFlags)
    {
        pPlayerData->nSwitchRightSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchRightSkillFlags);
    }

    if (pPlayerData->nLeftSkillId)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 1, pPlayerData->nLeftSkillId, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillId)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 0, pPlayerData->nRightSkillId, pPlayerData->nRightSkillFlags);
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    const int nNextExp = DATATBLS_GetLevelThreshold(!pUnit ? -1 : pUnit->dwClassId, STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0));
    STATLIST_SetUnitStat(pUnit, STAT_NEXTEXP, nNextExp, 0);

    if (CLIENTS_GetWeaponSwitch(pClient))
    {
        D2GAME_PACKETS_SendPacket0x97_6FC3FB60(pClient);
    }
}
