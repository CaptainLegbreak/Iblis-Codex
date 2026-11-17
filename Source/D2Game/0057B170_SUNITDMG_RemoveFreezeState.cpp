struct D2MonStatsTxt
{
    char unk0x000[0x4F];
    unsigned char nAIdel[3];
};

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    int dwGameType;
    char unk0x78[0x30];
    unsigned int dwGameFrame;
};

struct D2StatListStrc;

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                        // 0x00553570
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState);                 // 0x0063A4A0

// 0x0057B170
void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    SUNIT_SetCombatMode(SUNIT_GetGameFromUnit(pUnit), pUnit, 1);

    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
        if (pMonStatsTxtRecord)
        {
            int nAiDelay;
            if (!pGame->nGameType && !pGame->dwGameType)
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[0];
            }
            else
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
            }

            if (nAiDelay <= 0)
            {
                nAiDelay = 15;
            }

            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
        }
    }
}
