struct D2GameStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

#define QUEST_A5Q6_BAAL 36

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId);                                   // 0x005444B0
void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMissile);      // 0x0058E920
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset);                            // 0x0061AED0

// 0x005AD930
static __forceinline void sub_005AD930_BaalFxOpenPortal(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (QUESTS_CheckNotIntroQuest(pGame, QUEST_A5Q6_BAAL))
    {
        ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
    }

    DUNGEON_ToggleHasPortalFlag(pRoom, 1);
}

void __fastcall sub_M250_Emit_005AD930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    sub_005AD930_BaalFxOpenPortal(pGame, pMissile);
}
