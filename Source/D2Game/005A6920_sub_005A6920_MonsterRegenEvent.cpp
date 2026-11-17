struct D2ActiveRoomStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x9C];
    int dwKillerGUID;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit);                                           // 0x0063A750
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit);                                    // 0x005A5650
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent);                    // 0x00571A10
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetOwnerType(D2StatListStrc* pStatList);                                             // 0x00625250
int __stdcall STATLIST_GetOwnerGUID(D2StatListStrc* pStatList);                                             // 0x006252B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, void* pDamage); // 0x005C0C30

// 0x005A6920
void __fastcall sub_005A6920_MonsterRegenEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nParam)
{
    int nRegen = STATLIST_UnitGetStatValue(pUnit, 0x4A, 0);
    if (STATES_CheckStateMaskLifeOnUnit(pUnit))
    {
        nRegen -= STATLIST_GetUnitBaseStat(pUnit, 0x4A, 0);
    }

    if (STATES_CheckState(pUnit, 0x34) && nRegen >= 0)
    {
        return;
    }

    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
    if (!nRegen)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
        return;
    }

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nRegen < 0 && nHitpoints < 0x100)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return;
        }
    }

    nHitpoints += nRegen;
    if (nHitpoints > nMaxHp)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
        nHitpoints = nMaxHp;
    }

    if (nHitpoints < 1)
    {
        nHitpoints = 0;
    }

    STATLIST_SetUnitStat(pUnit, 6, nHitpoints, 0);

    const unsigned char nOldPercent = STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
    const unsigned char nNewPercent = MONSTERMODE_GetHpPercent128(pUnit);
    int nDiff = nOldPercent - nNewPercent;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }
    if (nDiff > 4)
    {
        SUNITMSG_QueueLifeUpdate(pUnit, nNewPercent);
        STATLIST_SetUnitStat(pUnit, 0x160, nNewPercent, 0);
    }

    if (nHitpoints || !pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 12)
    {
        return;
    }

    D2StatListStrc* pStatList = 0;
    int nStates[2];
    nStates[0] = 2;
    nStates[1] = 0x3E;
    for (int i = 0; i < 2; ++i)
    {
        if (pStatList)
        {
            break;
        }
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStates[i]);
    }

    D2UnitStrc* pKiller = 0;
    pUnit->dwKillerGUID = 0;
    if (pStatList)
    {
        pKiller = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    }

    if (STATES_CheckState(pUnit, 0x36))
    {
        STATES_ToggleState(pUnit, 0x5C, 1);
        return;
    }

    SUNITDMG_KillMonster(pGame, pUnit, pKiller, 1);
    SUNITEVENT_Trigger(pGame, 10, pUnit, pKiller, 0);
    if (pKiller)
    {
        SUNITEVENT_Trigger(pGame, 9, pKiller, pUnit, 0);
    }
}
