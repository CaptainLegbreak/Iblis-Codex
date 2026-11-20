#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SeedStrc;
struct D2SkillsTxt;


struct D2SkillsTxt
{
    char unk0x000[0x12C];
    short wUnk0x12C;
    char unk0x12E[0x23C - 0x12E];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

// 0x0045C370
unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0045C390
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0045C4B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004AA8B0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        const int nValue = sgptDataTables->pSkillsTxt[nSkillId].wUnk0x12C;
        if (nValue > 0)
            return nValue;
    }
    return 20;
}
