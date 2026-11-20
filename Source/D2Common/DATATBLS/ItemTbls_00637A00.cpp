#include "D2Common.h"
#include "D2Txt.h"
struct D2BinFieldStrc;
struct D2OpStatDataStrc;
struct D2ItemStatCostTxt;
struct D2ItemStatCostDescStrc;
struct D2GambleTxt;
struct D2ItemsTxt;
struct D2GambleDataTbl;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};



struct D2ItemStatCostDescStrc
{
    unsigned short wStatId;
    short nDescPriority;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern D2TxtLinkStrc* gpEventsLinker_0096BCA8; // 0x0096BCA8
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __cdecl DATATBLS_CompareItemStatCostDescs(const void* pRecord1, const void* pRecord2); // 0x006379D0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2GambleTxt
{
    unsigned int dwItemCode;
    int nLevel;
    int nItemId;
};


struct D2GambleDataTbl
{
    int nGambleTxtRecordCount;
    unsigned int* pGambleSelection;
    int pGambleChooseLimit[100];
};

struct D2DataTablesStrc
{
    char unk0x000[0x94];
    D2TxtLinkStrc* pItemsLinker;
    char unk0x098[0xD94];
    D2ItemsTxt* pItemsTxt;
    char unk0xE30[0x50];
    D2GambleDataTbl pGambleDataTables;
};
extern D2DataTablesStrc sgtDataTables; // 0x0096BC30
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130
int __cdecl DATATBLS_CompareGambleTxtRecords(const void* pRecord1, const void* pRecord2); // 0x00638AC0

D2ItemStatCostTxt* gpItemStatCostTxt; // 0x0096C7FC

int gnItemStatCostTxtRecordCount; // 0x0096C804

unsigned short* gpStatsWithDescFunc; // 0x0096C808

int gnStatsWithDescFunc; // 0x0096C80C

int gnItemStatCostStuff_0096C89C; // 0x0096C89C

int gnItemStatCostStuffMask_0096C8A0; // 0x0096C8A0

static __forceinline void STATFLAG_SET(unsigned char* pFlags, int nBit)
{
    pFlags[nBit >> 3] |= (unsigned char)gdwBitMasks[nBit & 7];
}

// 0x00637A00
void __fastcall DATATBLS_LoadItemStatCostTxt(void* hArchive)
{
    D2ItemStatCostDescStrc pStatsWithDescFunc[511];
    D2BinFieldStrc pTbl[] =
    {
        { "stat", 17, 0, 0, &gpItemStatCostLinker },
        { "send bits", 4, 0, 8, 0 },
        { "send param bits", 4, 0, 9, 0 },
        { "divide", 2, 0, 12, 0 },
        { "multiply", 2, 0, 16, 0 },
        { "add", 2, 0, 20, 0 },
        { "valshift", 4, 0, 24, 0 },
        { "minaccr", 2, 0, 44, 0 },
        { "save bits", 4, 0, 25, 0 },
        { "save add", 2, 0, 28, 0 },
        { "save param bits", 2, 0, 36, 0 },
        { "1.09-save bits", 4, 0, 26, 0 },
        { "1.09-save add", 2, 0, 32, 0 },
        { "encode", 4, 0, 48, 0 },
        { "send other", 26, 0, 4, 0 },
        { "signed", 26, 1, 4, 0 },
        { "updateanimrate", 26, 9, 4, 0 },
        { "fmin", 26, 10, 4, 0 },
        { "damagerelated", 26, 2, 4, 0 },
        { "itemspecific", 26, 3, 4, 0 },
        { "direct", 26, 4, 4, 0 },
        { "fcallback", 26, 11, 4, 0 },
        { "saved", 26, 12, 4, 0 },
        { "csvsigned", 26, 13, 4, 0 },
        { "csvbits", 4, 0, 10, 0 },
        { "csvparam", 4, 0, 11, 0 },
        { "maxstat", 20, 0, 50, &gpItemStatCostLinker },
        { "itemevent1", 20, 0, 72, &gpEventsLinker_0096BCA8 },
        { "itemeventfunc1", 3, 0, 76, 0 },
        { "itemevent2", 20, 0, 74, &gpEventsLinker_0096BCA8 },
        { "itemeventfunc2", 3, 0, 78, 0 },
        { "descpriority", 3, 0, 52, 0 },
        { "descfunc", 4, 0, 54, 0 },
        { "descval", 4, 0, 55, 0 },
        { "descstrpos", 22, 0, 56, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "descstrneg", 22, 0, 58, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "descstr2", 22, 0, 60, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrp", 3, 0, 62, 0 },
        { "dgrpfunc", 4, 0, 64, 0 },
        { "dgrpval", 4, 0, 65, 0 },
        { "dgrpstrpos", 22, 0, 66, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrpstrneg", 22, 0, 68, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrpstr2", 22, 0, 70, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "keepzero", 4, 0, 80, 0 },
        { "op", 4, 0, 84, 0 },
        { "op base", 20, 0, 86, &gpItemStatCostLinker },
        { "op param", 4, 0, 85, 0 },
        { "op stat1", 20, 0, 88, &gpItemStatCostLinker },
        { "op stat2", 20, 0, 90, &gpItemStatCostLinker },
        { "op stat3", 20, 0, 92, &gpItemStatCostLinker },
        { "stuff", 2, 0, 320, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemStatCostLinker = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 1716);
    gpItemStatCostTxt = (D2ItemStatCostTxt*)DATATBLS_CompileTxt(hArchive, "itemstatcost", pTbl, &gnItemStatCostTxtRecordCount, sizeof(D2ItemStatCostTxt));

    ITEM_ASSERT(gnItemStatCostTxtRecordCount <= 511, 1718);

    gnItemStatCostStuff_0096C89C = gpItemStatCostTxt->nStuff;
    if (gnItemStatCostStuff_0096C89C <= 0 || gnItemStatCostStuff_0096C89C > 8)
    {
        gnItemStatCostStuff_0096C89C = 6;
    }
    gnItemStatCostStuffMask_0096C8A0 = (1 << gnItemStatCostStuff_0096C89C) - 1;

    D2ItemStatCostTxt* pTxt = gpItemStatCostTxt;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            pTxt[i].wStatsAffected[j] = 0xFFFF;
        }
    }

    D2ItemStatCostTxt* pItemStatCostTxt = gpItemStatCostTxt;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        if (pItemStatCostTxt->nOp > 0 && pItemStatCostTxt->nOp < 14)
        {
            if (pItemStatCostTxt->wOpBase < gnItemStatCostTxtRecordCount)
            {
                D2ItemStatCostTxt* pOpBase = &gpItemStatCostTxt[pItemStatCostTxt->wOpBase];
                int j = 0;
                pOpBase->bIsBaseOfOtherStatOp = 1;
                for (j = 0; j < 64; ++j)
                {
                    if (pOpBase->wStatsAffected[j] >= gnItemStatCostTxtRecordCount)
                    {
                        break;
                    }
                }

                if (j < 64)
                {
                    pOpBase->wStatsAffected[j] = i;
                }

                if (pItemStatCostTxt->nOp == 4 || pItemStatCostTxt->nOp == 5)
                {
                    pItemStatCostTxt->bHasOpApplyingToItem = 1;
                }
            }

            for (int k = 0; k < 3; ++k)
            {
                int nStatId = pItemStatCostTxt->wOpStat[k];
                if (nStatId >= gnItemStatCostTxtRecordCount)
                {
                    break;
                }

                pItemStatCostTxt->bIsBaseOfOtherStatOp = 1;

                int j = 0;
                for (j = 0; j < 16; ++j)
                {
                    if (!gpItemStatCostTxt[nStatId].pOpStatData[j].nOp)
                    {
                        break;
                    }
                }

                if (j < 16)
                {
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nStat = i;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOp = pItemStatCostTxt->nOp;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOpBase = pItemStatCostTxt->wOpBase;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOpParam = pItemStatCostTxt->nOpParam;
                    gpItemStatCostTxt[nStatId].bHasOpStatData = 1;

                    if (i == 7 || nStatId == 7)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 6);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                    else if (i == 9 || nStatId == 9)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 7);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                    else if (i == 11 || nStatId == 11)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 8);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                }
            }

            ++pItemStatCostTxt;
        }
        else
        {
            pItemStatCostTxt->nOp = 0;
            ++pItemStatCostTxt;
        }
    }

    gnStatsWithDescFunc = 0;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        if (gpItemStatCostTxt[i].nDescFunc)
        {
            pStatsWithDescFunc[gnStatsWithDescFunc].wStatId = i;
            pStatsWithDescFunc[gnStatsWithDescFunc].nDescPriority = gpItemStatCostTxt[i].nDescPriority;
            ++gnStatsWithDescFunc;
        }
    }

    qsort(pStatsWithDescFunc, gnStatsWithDescFunc, sizeof(D2ItemStatCostDescStrc), DATATBLS_CompareItemStatCostDescs);

    gpStatsWithDescFunc = (unsigned short*)FOG_AllocPool(0, sizeof(unsigned short) * gnStatsWithDescFunc, ".\\DATATBLS\\ItemTbls.cpp", 1864, 0);
    for (int i = 0; i < gnStatsWithDescFunc; ++i)
    {
        gpStatsWithDescFunc[i] = pStatsWithDescFunc[i].wStatId;
    }
}

// 0x00638AE0
void __fastcall DATATBLS_LoadGambleTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 9, 0, 0, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2GambleTxt* pGambleTxt = (D2GambleTxt*)DATATBLS_CompileTxt(hArchive, "gamble", pTbl, &sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt));

    if (sgtDataTables.pGambleDataTables.nGambleTxtRecordCount)
    {
        sgtDataTables.pGambleDataTables.pGambleSelection = (unsigned int*)FOG_AllocPool(0, sizeof(unsigned int) * sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 0x7DB, 0);
        for (int i = 0; i < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
        {
            const unsigned int dwItemCode = pGambleTxt[i].dwItemCode;
            const int nItemId = FOG_GetLinkIndex(sgtDataTables.pItemsLinker, dwItemCode, 0);
            D2ItemsTxt* pItemsTxtRecord;
            D2_ASSERT(nItemId >= 0 && (pItemsTxtRecord = &sgtDataTables.pItemsTxt[nItemId]) != 0, 0x7E0);
            pGambleTxt[i].nLevel = pItemsTxtRecord->nLevel;
            pGambleTxt[i].nItemId = nItemId;
        }
        qsort(pGambleTxt, sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt), DATATBLS_CompareGambleTxtRecords);
    }
    else
    {
        sgtDataTables.pGambleDataTables.pGambleSelection = 0;
    }

    for (int i = 0; i < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
    {
        sgtDataTables.pGambleDataTables.pGambleSelection[i] = pGambleTxt[i].nItemId;
    }

    sgtDataTables.pGambleDataTables.pGambleChooseLimit[0] = 2;

    for (int i = 1; i < 100; ++i)
    {
        sgtDataTables.pGambleDataTables.pGambleChooseLimit[i] = sgtDataTables.pGambleDataTables.nGambleTxtRecordCount;

        for (int nCounter = 0; nCounter < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++nCounter)
        {
            if (i < pGambleTxt[nCounter].nLevel)
            {
                sgtDataTables.pGambleDataTables.pGambleChooseLimit[i] = nCounter;
                break;
            }
        }
    }

    DATATBLS_UnloadBin(pGambleTxt);
}
