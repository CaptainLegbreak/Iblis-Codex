struct D2GameStrc { unsigned char pad[0x6D]; unsigned char nDifficulty; };
struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2PlayerDataStrc { unsigned char pad[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2QuestDataStrc {
    int nQuestNo; D2GameStrc* pGame;
    unsigned char nActNo, bNotIntro, bActive, fLastState, fState;
    unsigned char pad0D[7];
    unsigned int dwFlags;
    unsigned char pad18[0xC8];
    int nQuestFilter;
};
struct D2QuestArgStrc {
    D2GameStrc* pGame; int nEvent; D2UnitStrc* pTarget; D2UnitStrc* pPlayer;
    int unk10, nOldLevel, nNewLevel;
};
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc*, D2UnitStrc*, void*);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __fastcall QUESTS_StateDebug(D2QuestDataStrc*, int, const char*, int); // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*, int, D2UnitStrc*, QUESTUNITITERATE, bool); // 0x00544300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*, int, void*, QUESTUNITITERATE); // 0x005537D0
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4560
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4E40

// 0x005B4EA0
void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 103 && pQuestData->fState == 2)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1)
            return;
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 687);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, false);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
    if (nNewLevel == 108 && pQuestData->bNotIntro)
    {
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 703);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, true);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
}
