struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char pad00[0x6D];
    unsigned char nDifficulty;
    char pad6E[0x78 - 0x6E];
    unsigned short wItemFormat;
};

struct D2UnitStrc
{
    char pad00[0x20];
    D2SeedStrc pSeed;
};

struct D2ItemsTxt
{
    char pad00[0x88];
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    char pad90[0xF6 - 0x90];
    unsigned short wVersion;
};

struct D2DifficultyLevelsTxt
{
    char pad00[0x08];
    int dwUberCodeOddsNorm;
    int dwUberCodeOddsGood;
    char pad10[0x20 - 0x10];
    int dwUltraCodeOddsNorm;
    int dwUltraCodeOddsGood;
};

struct D2ItemCodeListStrc
{
    unsigned char nCountA;
    char pad01[3];
    unsigned int dwCodesA[30];
    unsigned char nCountB;
    char pad7D[3];
    unsigned int dwCodesB[1];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0055FB80
unsigned int __fastcall sub_0055FB80_PickItemCode(D2GameStrc* pGame, D2ItemCodeListStrc* pList, D2UnitStrc* pUnit, int bGood)
{
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nIndex = SEED_RollLimitedRandomNumberInline(pSeed, pList->nCountA + pList->nCountB);
    unsigned int dwCode;
    if (nIndex < pList->nCountA)
    {
        dwCode = pList->dwCodesA[nIndex];
    }
    else
    {
        dwCode = pList->dwCodesB[nIndex - pList->nCountA];
    }

    int nItemId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (!pItemsTxt)
    {
        return dwCode;
    }

    D2_ASSERT(pItemsTxt->wVersion <= pGame->wItemFormat, 6601);

    if (pItemsTxt->dwUberCode == 0x20202030 || !pItemsTxt->dwUberCode)
    {
        return dwCode;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUberCodeOddsGood : pDifficultyLevelsTxtRecord->dwUberCodeOddsNorm))
    {
        dwCode = pItemsTxt->dwUberCode;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUltraCodeOddsGood : pDifficultyLevelsTxtRecord->dwUltraCodeOddsNorm))
        {
            dwCode = pItemsTxt->dwUltraCode;
        }
    }

    return dwCode;
}
