union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[0x9C];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x60];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    char unk0x068[0x1A];
    short wAuraTargetState;
    char unk0x084[0xC4];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
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

typedef char D2SkillsTxtSizeCheck[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];
typedef char D2UnkNecSkillStrcSizeCheck[sizeof(D2UnkNecSkillStrc) == 0x68 ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gaMonCurseIds_006E3228[5];                                                                 // 0x006E3228
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId);                    // 0x00645C10
int __fastcall sub_6FD10360(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780
int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs);                                                // 0x005C35C0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x005CE2B0
int __fastcall SKILLS_SrvDo112_MonCurseCast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nIndex = SEED_RollRandomNumber(&pUnit->pSeed) % 5;
    const int nCurseSkillId = gaMonCurseIds_006E3228[nIndex];

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nCurseSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nCurseSkillId, nSkillLevel);
    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nCurseSkillId, nSkillLevel);

    D2UnkNecSkillStrc args;
    memset(&args, 0, sizeof(args));
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.unk0x08 = 0;
    args.nSkillId = nCurseSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nDuration;
    args.bUpdateAnimRate = 0;
    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;

    int i = 0;
    do
    {
        args.nAuraStat[i] = -1;
        args.nAuraStatCalc[i] = 0;
        ++i;
    } while (i < 6);

    switch (nIndex)
    {
    case 0u:
    {
        args.nAuraStat[0] = 36;
        args.nAuraStatCalc[0] = -100;
        break;
    }
    case 1u:
    {
        args.nAuraStat[0] = 25;
        args.nAuraStatCalc[0] = -50;
        break;
    }
    case 2u:
    {
        args.nAuraEvent[0] = 5;
        args.nAuraEventFunc[0] = 4;
        break;
    }
    case 3u:
    {
        args.nAuraEvent[0] = 1;
        args.nAuraEventFunc[0] = 5;
        args.nAuraEvent[1] = 2;
        args.nAuraEventFunc[1] = 5;
        break;
    }
    case 4u:
    {
        args.bUpdateAnimRate = 1;
        args.nAuraStat[0] = 67;
        args.nAuraStatCalc[0] = pSkillsTxtRecord->dwParam[6];
        args.nAuraStat[1] = 25;
        args.nAuraStatCalc[1] = -50;
        args.nAuraStat[2] = 36;
        args.nAuraStatCalc[2] = -50;
        args.nAuraStat[3] = 68;
        args.nAuraStatCalc[3] = pSkillsTxtRecord->dwParam[6];
        break;
    }
    default:
    {
        const int nResSubstraction = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nCurseSkillId);
        args.nAuraStat[0] = 37;
        args.nAuraStatCalc[0] = -nResSubstraction;
        args.nAuraStat[1] = 39;
        args.nAuraStatCalc[1] = -nResSubstraction;
        args.nAuraStat[2] = 41;
        args.nAuraStatCalc[2] = -nResSubstraction;
        args.nAuraStat[3] = 43;
        args.nAuraStatCalc[3] = -nResSubstraction;
        args.nAuraStat[4] = 45;
        args.nAuraStatCalc[4] = -nResSubstraction;
        break;
    }
    }

    return sub_6FD10360(pGame, 3, pUnit, nRange, sub_6FD0B450, &args);
}

#include "gen/data/Source/D2Game/005CE2B0_SKILLS_SrvDo112_MonCurseCast.inc"
