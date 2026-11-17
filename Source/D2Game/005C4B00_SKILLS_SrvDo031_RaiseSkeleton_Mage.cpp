struct D2ActiveRoomStrc;
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct D2GameStrc
{
    char unk0x00[0x1C];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
    char unk0xC8[0x08];
    int dwNodeIndex;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

struct D2SkillsTxt
{
    char unk0x000[0xBE];
    signed char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x23C - 0xC4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);           // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __fastcall sub_005C2FF0_DamagePaladinCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C2FF0
void __fastcall D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet);                   // 0x005C40D0
void __fastcall sub_005C4430_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C4430
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2);                             // 0x00645510
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C4B00
int __fastcall SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SummonArgStrc summonArg;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        sub_005C2FF0_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            int nSpawnMode;
            const int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
            if (nMonsterId >= 0)
            {
                const int nPetType = pSkillsTxtRecord->nPetType;
                if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
                {
                    const int nX = CLIENTS_GetUnitX(pTarget);
                    const int nY = CLIENTS_GetUnitY(pTarget);
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                    SUNIT_RemoveUnit(pGame, pTarget);
                    memset(&summonArg, 0, sizeof(summonArg));
                    summonArg.nHcIdx = nMonsterId;
                    summonArg.nAiSpecialState = 0;
                    summonArg.nMonMode = nSpawnMode;
                    summonArg.dwFlags = 1;
                    summonArg.pOwner = pUnit;
                    summonArg.pPosition.nX = nX;
                    summonArg.pPosition.nY = nY;
                    summonArg.nPetType = nPetType;
                    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

                    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
                    if (pPet)
                    {
                        D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
                        sub_005C4430_SetNecroPetComponents(pUnit, pPet, nSkillId, nSkillLevel);
                        D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
                        D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
                        D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
