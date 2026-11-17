typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
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

struct D2UnkNecSkillStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int unk0x08;
    int bUpdateAnimRate;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalc[6];
    int nAuraTargetState;
    int nAuraEvent[3];
    int nAuraEventFunc[3];
};

struct D2SkillsTxt
{
    char unk0x000[0x54];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    char unk0x064[0x04];
    unsigned int dwAuraStatCalc[6];
    char unk0x080[0x02];
    short wAuraTargetState;
    char unk0x084[0x38];
    short wSummon;
    unsigned char nPetType;
    unsigned char nSumMode;
    unsigned int dwPetMax;
    char unk0x0C4[0x178];
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x13C];
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x1C];
    int dwAiCurseDiv;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x28];
    D2ItemStatCostTxt* pItemStatCostTxt;
    void* pItemStatCostLinker;
    int nItemStatCostTxtRecordCount;
    char unk0xBD8[0x18];
    int nPetTypeTxtRecordCount;
};

#define SKILL_DIMVISION 71
#define UNITFLAG_SKSRVDOFUNC 0x40
#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs);                                                // 0x005C35C0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);           // 0x0056D940
void __fastcall sub_005C50C0_SetSummonStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C50C0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053CDF0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x005C39C0
void __fastcall sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_DIMVISION);
    if (pSkillsTxtRecord)
    {
        int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, SKILL_DIMVISION, nSkillLevel);

        D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
        if (pDifficultyLevelsTxtRecord && pDifficultyLevelsTxtRecord->dwAiCurseDiv)
        {
            nLength /= pDifficultyLevelsTxtRecord->dwAiCurseDiv;
        }

        D2UnkNecSkillStrc args;
        memset(&args, 0, sizeof(args));
        args.nDuration = nLength;
        args.pGame = pGame;
        args.pUnit = pUnit;
        args.unk0x08 = 1;
        args.nSkillId = SKILL_DIMVISION;
        args.nSkillLevel = nSkillLevel;
        args.bUpdateAnimRate = 0;

        for (int i = 0; i < 6; ++i)
        {
            const short nStatId = pSkillsTxtRecord->wAuraStat[i];
            if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            {
                args.nAuraStat[i] = -1;
                break;
            }

            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
            if (!pItemStatCostTxtRecord)
            {
                break;
            }

            if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
            {
                args.bUpdateAnimRate = 1;
            }

            args.nAuraStat[i] = nStatId;
            args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], SKILL_DIMVISION, nSkillLevel);
        }

        args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
        sub_6FD0B450(pTarget, &args);
    }
}

// 0x005C5100
int __fastcall SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId || pSkillsTxtRecord->wSummon < 0 || pSkillsTxtRecord->wSummon >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    unsigned char nSumMode = pSkillsTxtRecord->nSumMode;
    if (pSkillsTxtRecord->nSumMode >= 16)
    {
        nSumMode = 1;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 0;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = pSkillsTxtRecord->wSummon;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSumMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    sub_005C50C0_SetSummonStats(pGame, pUnit, pPet, nSkillId, nSkillLevel);
    sub_6FC3E200(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillNec.cpp", 1787), pPet);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}
