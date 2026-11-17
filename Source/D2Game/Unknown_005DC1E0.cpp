#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
    char unk0xC8[0x08];
    int dwNodeIndex;
};

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    int nX;
    int nY;
    int nPetType;
    int nPetMax;
};

struct D2SkillsTxt
{
    char unk0x000[0xBE];
    unsigned char nPetType;
    char unk0x0BF[0x01];
    unsigned int dwPetMax;
    char unk0x0C4[0x74];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);         // 0x0056D940
void __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

enum
{
    UNIT_PLAYER = 0,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,
    STATE_VALKYRIE = 0x5D,
};

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005DC1E0
int __fastcall SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 20, 0, 0);
    STATES_ToggleState(pPet, STATE_VALKYRIE, 1);
    UNITS_StoreOwner(pPet, pUnit);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}
