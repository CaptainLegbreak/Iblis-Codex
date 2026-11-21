#include "D2Txt.h"
#include "D2Records.h"
struct D2TxtLinkStrc;


struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    short nItemId;
    short nTxtRow;
    unsigned char nFlags;
    char unk0x0D;
    short nMagic;
    short nRare;
    short nSet;
    short nUnique;
    short nSuperior;
    short nNormal;
    char unk0x1A[2];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    char unk0x18[2];
    short nQuality[6];
    char unk0x26[2];
    D2TCExInfoStrc* pInfo;
};

struct D2TreasureClassExTxt
{
    char szTreasureClass[32];
    int nPicks;
    unsigned short nGroup;
    short nLevel;
    unsigned short nQuality[6];
    int nNoDrop;
    char szItem[10][64];
    int nProb[10];
};


struct D2UniqueItemsTxt
{
    char unk0x00[0x28];
    unsigned int dwBaseItemCode;
    char unk0x2C[0x14C - 0x2C];
};

typedef char check_D2TCExInfoStrc_size[sizeof(D2TCExInfoStrc) == 0x1C ? 1 : -1];
typedef char check_D2TCExShortStrc_size[sizeof(D2TCExShortStrc) == 0x2C ? 1 : -1];
typedef char check_D2TreasureClassExTxt_size[sizeof(D2TreasureClassExTxt) == 0x2E0 ? 1 : -1];
typedef char check_D2ItemsTxt_size[sizeof(D2ItemsTxt) == 0x1A8 ? 1 : -1];
typedef char check_D2UniqueItemsTxt_size[sizeof(D2UniqueItemsTxt) == 0x14C ? 1 : -1];
typedef char check_D2SetItemsTxt_size[sizeof(D2SetItemsTxt) == 0x1B8 ? 1 : -1];

extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" unsigned int __cdecl strlen(const char* sz);

extern D2TxtLinkStrc* gpTreasureClassExLinker;                                                              // 0x0096C5E8
extern D2TCExShortStrc* gpTreasureClassEx;                                                                  // 0x0096C5EC
D2TxtLinkStrc* gpSetItemsLinker;                                                                            // 0x0096C844
void* gpSetItemsTxt;                                                                                        // 0x0096C848
extern D2TxtLinkStrc* gpUniqueItemsLinker;                                                                  // 0x0096C850
extern void* gpUniqueItemsTxt;                                                                              // 0x0096C854
extern int gnTreasureClassItemTypes;                                                                        // 0x0096D4B0

extern "C" const char gszTxtField_magic_006DCFBC[];                                                         // 0x006DCFBC
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, const char* szKey, int bLogError);                   // 0x006BD3C0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass);                       // 0x00653F90
D2TCExInfoStrc* __fastcall sub_00654080(D2TCExShortStrc* pTCExShort);                               // 0x00654080
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion); // 0x006540C0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

// 0x00650EB0
static void __declspec(noinline) sub_00650EB0_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

static int __declspec(noinline) sub_00654410_NextIntToken(char** ppString, char chSeparator);

// 0x00654410
static int sub_00654410_NextIntToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return atoi(szToken);
}

struct D2TCExRecordArgStrc
{
    D2TCExShortStrc* pRecord;
};
static int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExRecordArgStrc tRecord, int nProb, char* szText);
static int __declspec(noinline) __stdcall DATATBLS_ParseTreasureClassItem(D2TCExRecordArgStrc tRecord, int nProb, char* szText);

// 0x00654440
static int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExRecordArgStrc tRecord, int nProb, char* szText)
{
    D2TCExInfoStrc* pTCExInfo;
    if (nProb <= 0)
    {
        return 0;
    }

    char* szItem = szText;
    if (*szItem == '"')
    {
        ++szItem;
    }

    for (char* szTmp = szItem; *szTmp; ++szTmp)
    {
        if (*szTmp == '"')
        {
            *szTmp = 0;
        }
    }

    char* szNext = strchr(szItem, ',');
    if (szNext)
    {
        *szNext = 0;
        ++szNext;
    }

    if (strlen(szItem) <= 4)
    {
        unsigned int dwCode;
        sub_00650EB0_MakeCode(szItem, (char*)&dwCode);
        int nItemId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
        if (pItemsTxtRecord)
        {
            pTCExInfo = sub_00654080(tRecord.pRecord);
            pTCExInfo->nItemId = nItemId;
            if (pItemsTxtRecord->wVersion >= 100)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, pItemsTxtRecord->wVersion >= 100);
            goto MODIFIERS;
        }
    }

    {
        int nIndex = FOG_GetLinkIndex(gpTreasureClassExLinker, szItem, 0);
        if (nIndex > 0)
        {
            pTCExInfo = sub_00654080(tRecord.pRecord);
            pTCExInfo->nFlags |= 4;
            pTCExInfo->nItemId = nIndex;
            if (!gpTreasureClassEx[nIndex].nClassic)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, gpTreasureClassEx[nIndex].nClassic == 0);
        }
        else if (gpUniqueItemsLinker && (nIndex = FOG_GetLinkIndex(gpUniqueItemsLinker, szItem, 0)) > 0)
        {
            pTCExInfo = sub_00654080(tRecord.pRecord);
            int nUniqueItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2UniqueItemsTxt*)gpUniqueItemsTxt)[nIndex].dwBaseItemCode, &nUniqueItemId);
            pTCExInfo->nItemId = nUniqueItemId;
            pTCExInfo->nFlags |= 0x11;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, 1);
        }
        else if (gpSetItemsLinker && (nIndex = FOG_GetLinkIndex(gpSetItemsLinker, szItem, 0)) >= 0)
        {
            pTCExInfo = sub_00654080(tRecord.pRecord);
            int nSetItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2SetItemsTxt*)gpSetItemsTxt)[nIndex].dwItemCode, &nSetItemId);
            pTCExInfo->nItemId = nSetItemId;
            pTCExInfo->nFlags |= 0x12;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(tRecord.pRecord, pTCExInfo, nProb, 1);
        }
        else
        {
            return 0;
        }
    }

MODIFIERS:
    while (szNext)
    {
        char* szKey = szNext;
        szNext = strchr(szNext, '=');
        if (!szNext)
        {
            break;
        }
        *szNext = 0;
        ++szNext;
        if (!szNext)
        {
            break;
        }

        if (!strcmp(szKey, "mul"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nTxtRow = atoi(szValue);
        }
        else if (!strcmp(szKey, "cu"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nUnique = atoi(szValue);
        }
        else if (!strcmp(szKey, "cs"))
        {
            char* szValue = szNext;
            szNext = strchr(szValue, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nSet = atoi(szValue);
        }
        else if (!strcmp(szKey, "cr"))
        {
            pTCExInfo->nRare = sub_00654410_NextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "cm"))
        {
            pTCExInfo->nMagic = sub_00654410_NextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "ce"))
        {
            pTCExInfo->nSuperior = sub_00654410_NextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "cg"))
        {
            pTCExInfo->nNormal = sub_00654410_NextIntToken(&szNext, ',');
        }
        else if (!strcmp(szKey, "ma") || !strcmp(szKey, "mg"))
        {
            pTCExInfo->nTxtRow = sub_00654410_NextIntToken(&szNext, ',');
        }
        else
        {
            break;
        }
    }

    return 1;
}

void __stdcall sub_006547D0(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "treasure class", 1, 32, 0, 0 },
        { "group", 3, 0, 36, 0 },
        { "level", 3, 0, 38, 0 },
        { "picks", 2, 0, 32, 0 },
        { "unique", 3, 0, 46, 0 },
        { "set", 3, 0, 44, 0 },
        { "rare", 3, 0, 42, 0 },
        { gszTxtField_magic_006DCFBC, 3, 0, 40, 0 },
        { "nodrop", 2, 0, 52, 0 },
        { "item1", 1, 64, 56, 0 },
        { "prob1", 2, 0, 696, 0 },
        { "item2", 1, 64, 120, 0 },
        { "prob2", 2, 0, 700, 0 },
        { "item3", 1, 64, 184, 0 },
        { "prob3", 2, 0, 704, 0 },
        { "item4", 1, 64, 248, 0 },
        { "prob4", 2, 0, 708, 0 },
        { "item5", 1, 64, 312, 0 },
        { "prob5", 2, 0, 712, 0 },
        { "item6", 1, 64, 376, 0 },
        { "prob6", 2, 0, 716, 0 },
        { "item7", 1, 64, 440, 0 },
        { "prob7", 2, 0, 720, 0 },
        { "item8", 1, 64, 504, 0 },
        { "prob8", 2, 0, 724, 0 },
        { "item9", 1, 64, 568, 0 },
        { "prob9", 2, 0, 728, 0 },
        { "item10", 1, 64, 632, 0 },
        { "prob10", 2, 0, 732, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    int nRecordCount;
    D2TreasureClassExTxt* pTreasureClassExTxt = (D2TreasureClassExTxt*)DATATBLS_CompileTxt(hArchive, "treasureclassex", pTbl, &nRecordCount, sizeof(D2TreasureClassExTxt));

    for (int i = 0; i < nRecordCount; ++i)
    {
        if (!pTreasureClassExTxt[i].szTreasureClass[0])
        {
            break;
        }

        D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(pTreasureClassExTxt[i].szTreasureClass);
        if (pTCExTxtRecord)
        {
            if (pTreasureClassExTxt[i].nGroup)
            {
                pTCExTxtRecord->nGroup = pTreasureClassExTxt[i].nGroup + gnTreasureClassItemTypes;
            }
            pTCExTxtRecord->nLevel = pTreasureClassExTxt[i].nLevel;
            pTCExTxtRecord->nPicks = pTreasureClassExTxt[i].nPicks;
            if (!pTCExTxtRecord->nPicks)
            {
                pTCExTxtRecord->nPicks = 1;
            }
            pTCExTxtRecord->nNoDrop = pTreasureClassExTxt[i].nNoDrop;
            for (int nQuality = 0; nQuality < 6; ++nQuality)
            {
                pTCExTxtRecord->nQuality[nQuality] = pTreasureClassExTxt[i].nQuality[nQuality];
            }

            for (int nItem = 0; nItem < 10; ++nItem)
            {
                if (!pTreasureClassExTxt[i].szItem[nItem][0])
                {
                    break;
                }
                D2TCExRecordArgStrc tRecord = { pTCExTxtRecord };
                DATATBLS_ParseTreasureClassItem(tRecord, pTreasureClassExTxt[i].nProb[nItem], pTreasureClassExTxt[i].szItem[nItem]);
            }
        }
    }

    DATATBLS_UnloadBin(pTreasureClassExTxt);
}
