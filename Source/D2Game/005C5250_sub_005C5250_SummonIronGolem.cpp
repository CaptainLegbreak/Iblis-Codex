struct D2GameStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk08;
    int dwUnitId;
    char unk10[0xB4];
    unsigned int dwFlags;
    char unkC8[8];
    int dwNodeIndex;
};
struct D2CoordStrc { int nX; int nY; };
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
    char unk000[0xBE];
    unsigned char nPetType;
    unsigned char nSumMode;
    unsigned int dwPetMax;
    char unk0C4[0x178];
};
struct D2DataTablesStrc
{
    char unk000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unkBA4[0x4C];
    int nPetTypeTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __fastcall sub_6FC3E200(D2ClientStrc*, D2UnitStrc*); // 0x0053CDF0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
int __fastcall sub_6FC45060(D2GameStrc*, D2UnitStrc*, int, unsigned char, int, int*); // 0x005606B0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc*, D2SummonArgStrc*); // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc*, int, int, int, int*, int*, int*); // 0x0056E620
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1900
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C32A0
void __fastcall sub_005C50C0_SetSummonStats(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005C50C0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc*, int, int); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc*); // 0x00623830
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc*, unsigned char*, unsigned char*); // 0x0062EA80
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc*); // 0x0064C370
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
// 0x005C5250
int __fastcall sub_005C5250_SummonIronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_SrvSt20_IronGolem(pGame, pUnit, nSkillId, nSkillLevel))
        return 0;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
        return 0;
    int nSpawnMode;
    int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nMonsterId < 0)
        return 0;
    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
        nPetType = 0;
    D2SummonArgStrc summonArg = {};
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nMonsterId;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.dwFlags = 1;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = CLIENTS_GetUnitX(pUnit);
    summonArg.pPosition.nY = CLIENTS_GetUnitY(pUnit);
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        summonArg.pPosition.nX = CLIENTS_GetUnitX(pTarget);
        summonArg.pPosition.nY = CLIENTS_GetUnitY(pTarget);
    }
    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
        return 0;
    if (pTarget)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
        UNITS_FreeCollisionPath(pTarget);
        UNITROOM_RemoveUnitFromRoom(pTarget);
        unsigned char nBodyLoc1;
        unsigned char nBodyLoc2;
        ITEMS_GetAllowedBodyLocations(pTarget, &nBodyLoc1, &nBodyLoc2);
        UNITS_ChangeAnimMode(pTarget, 4);
        sub_6FC45060(pGame, pPet, !pTarget ? -1 : pTarget->dwUnitId, nBodyLoc1, 1, 0);
    }
    sub_005C50C0_SetSummonStats(pGame, pUnit, pPet, nSkillId, nSkillLevel);
    sub_6FC3E200(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillNec.cpp", 1871), pPet);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}
