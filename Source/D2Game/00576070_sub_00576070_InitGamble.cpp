struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x50];
    int nGameType;
};

struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x108];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

struct D2NpcGambleStrc
{
    unsigned short nNameId;
    unsigned short unk0x02;
    unsigned int nSeed;
    int unk0x08;
    int bSelected;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2NpcGambleStrc* pGamble;
    char unk0x14[0x0D];
    unsigned char bGambleInit;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
D2SeedStrc* __fastcall sub_00536B40_GetGameSeed(D2GameStrc* pGame);                                         // 0x00536B40
D2HirelingTxt* __stdcall sub_006564D0_GetHirelingTxtRecord(int nGameType, int nId, int nDifficulty, int a4); // 0x006564D0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00575FF0
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = sub_006564D0_GetHirelingTxtRecord(pGame->nGameType, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    const int nCount = *pNameLast - *pNameFirst + 1;
    D2_ASSERT(nCount != -1, 96);
    return nCount;
}

// 0x00576070
void __fastcall sub_00576070_InitGamble(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord->bGambleInit)
    {
        return;
    }

    pNpcRecord->bGambleInit = 1;
    if (pNpcRecord->pGamble)
    {
        return;
    }

    pNpcRecord->pGamble = (D2NpcGambleStrc*)FOG_AllocPool(pGame->pMemoryPool, 0x450, ".\\UNIT\\SUNITNPC.CPP", 0x6E, 0);
    memset(pNpcRecord->pGamble, 0, 0x450);

    D2SeedStrc* pSeed = sub_00536B40_GetGameSeed(pGame);
    D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;

    int nMin;
    int nMax;
    const int nCount = sub_00575FF0(pGame, nVendorId, &nMin, &nMax, 0);
    D2_ASSERT(nCount != -1, 0x7A);

    if (nMin <= nMax)
    {
        int i = 0;
        do
        {
            if (i >= nCount)
            {
                break;
            }

            pGamble[i].nNameId = nMin + i;
            pGamble[i].nSeed = SEED_RollRandomNumber(pSeed);
            pGamble[i].unk0x08 = 0;
            pGamble[i].bSelected = 0;
            ++i;
        } while (nMin + i <= nMax);
    }

    for (nMin = 0; nMin < 10; ++nMin)
    {
        int nIndex = SEED_RollLimitedRandomNumber(pSeed, nCount);
        const int nStart = nIndex;
        for (;;)
        {
            if (!pGamble[nIndex].bSelected && !pGamble[nIndex].unk0x08)
            {
                pGamble[nIndex].bSelected = 1;
                break;
            }

            ++nIndex;
            if (nIndex >= nCount)
            {
                nIndex = 0;
            }

            if (nIndex == nStart)
            {
                return;
            }
        }
    }
}
