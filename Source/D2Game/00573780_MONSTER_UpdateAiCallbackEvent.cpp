struct D2GameStrc { char unk00[0xA8]; unsigned int dwGameFrame; };
struct D2UnitStrc { char unk00[0x10]; int dwAnimMode; };
struct D2DataTablesStrc { char unk00[0xA80]; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_00463860_GetMonsterClass(D2UnitStrc* pUnit); // 0x00463860
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nParam); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nParam1, int nParam2); // 0x005417D0
static __forceinline int GetValidMonsterClass(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return nClassId;
    return -1;
}
// 0x00573780
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (!pUnit) return;
    if (pUnit->dwAnimMode == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
    }
    else if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        return;
    }
    switch (GetValidMonsterClass(sub_00463860_GetMonsterClass(pUnit)))
    {
    case 110:
    case 118:
    case 136:
    case 247:
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
        break;
    }
}
