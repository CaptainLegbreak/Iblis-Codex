extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
struct D2GameStrc { char unk0x00[0xA8]; int dwGameFrame; };
struct D2UnitStrc { int dwUnitType; };
struct D2ActiveRoomStrc;
struct D2AiControlStrc;
struct D2SkillsTxt
{
    char unk0x00[0xBE];
    signed char nPetType;
    char unk0xBF;
    unsigned int dwPetMax;
    char unk0xC4[0x178];
};
struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
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
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnHydraOffsetX_006E312C[]; // 0x006E312C
extern const int gnHydraOffsetY_006E3120[]; // 0x006E3120
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pArgs); // 0x0056D940
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005CA910
int __fastcall sub_005CA910(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
        return 0;
    int nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        return 0;
    pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        return 0;
    if (pUnit && pUnit->dwUnitType == 1 && MONSTERS_GetHirelingTypeId(pUnit))
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
            pUnit = pOwner;
    }
    const int nExpireFrame = pGame->dwGameFrame + sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
    D2SummonArgStrc summonArg;
    memset(&summonArg, 0, sizeof(summonArg));
    summonArg.dwFlags |= 1;
    summonArg.pOwner = pUnit;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    int nResult = 0;
    for (int i = 0; i < 3; i += 1)
    {
        summonArg.nHcIdx = nSummonId + i;
        summonArg.nX = nX + gnHydraOffsetX_006E312C[i];
        summonArg.nY = nY + gnHydraOffsetY_006E3120[i];
        D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
        if (pPet)
        {
            D2GAME_SetSkills_6FD14C60(pPet, nSkillId, nSkillLevel, 1);
            D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
            nResult = 1;
            D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pPet);
            if (pAiControl)
                AITHINK_SetAiControlParams(pAiControl, nExpireFrame, -666, -666);
            if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == 1)
                sub_6FCBDD30(pPet, STATLIST_GetUnitAlignment(pUnit), 1);
        }
    }
    return nResult;
}

#include "gen/data/Source/D2Game/005CA910_sub_005CA910.inc"
