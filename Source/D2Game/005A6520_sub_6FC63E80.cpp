struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};
struct D2DynamicPathStrc;
struct D2HoverTextStrc;
struct D2UnitStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
    int unk0x14[6];
    D2DynamicPathStrc* pDynamicPath;
    int unk0x30[29];
    D2HoverTextStrc* pHoverText;
    int unk0xA8[7];
    unsigned int dwFlags;
};
struct D2MonStatsTxt
{
    int unk0x000[0x6A];
};
struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};
struct D2ModeChangeStrc
{
    int unk0x00;
    D2UnitStrc* pUnit;
    int unk0x08[3];
    unsigned char nDirection;
};
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                            // 0x006611A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                      // 0x0064C040
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit);                                               // 0x0058F6C0
void __fastcall sub_005B1A90(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005B1A90
void __stdcall D2Common_10469(D2UnitStrc* pUnit);                                                            // 0x00627540
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster);                               // 0x0063E9F0
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss);                                  // 0x00639FB0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                            // 0x0063A320
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                   // 0x004638A0
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                              // 0x00649F70
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                          // 0x006488A0
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pMonster);                               // 0x005738D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                        // 0x00553570
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

inline D2MonStatsTxt* GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nId = pUnit->dwClassId;
        if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nId];
        }
    }
    return 0;
}

// 0x005A6520
static void __stdcall sub_6FC63E80(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 0x100;
    }

    AIGENERAL_UpdateMinionList(pUnit);
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit);
    sub_005B1A90(pGame, pUnit);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFF7FF3;
    }

    D2Common_10469(pUnit);
    STATES_UpdateStayDeathFlags(pUnit, MONSTERS_IsBoss(pMonStatsTxtRecord, pUnit));
    if (STATES_CheckStateMaskHideOnUnit(pUnit) && pUnit)
    {
        pUnit->dwFlags &= ~2;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 0x13))
    {
        PATH_SetUnitDeadCollision(pUnit, 1);
    }

    sub_006488A0_SetDirection(pPath, nDirection);
    MONSTER_DeleteEvents(pGame, pUnit);
}

// 0x005A7390
int __fastcall sub_005A7390_MONSTERMODE_EndDeath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_6FC63E80(pModeChange->nDirection, pGame, pUnit);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 12);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, 0);
    return 1;
}
