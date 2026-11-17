struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2PlayerDataStrc { char unk_00[0x10]; D2BitBufferStrc* pQuestFlags[3]; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pFlags, int nQuest, int nState); // 0x0065C310
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

static __forceinline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestFlags[pGame->nDifficulty];
}

// 0x005872F0
int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (QUESTRECORD_GetQuestState(GetQuestFlags(pGame, pUnit), 35, 13))
        SUNIT_AttachSound(pUnit, 80, pUnit);
    return 0;
}
