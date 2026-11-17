struct D2TxtLinkStrc;
struct D2ItemsTxt;

struct D2CubeInputItemStrc
{
    unsigned short wFlags;
    unsigned short wItem;
    unsigned short wItemId;
    unsigned char nQuality;
    unsigned char nQuantity;
    unsigned char nType;
    unsigned char unk0x09[2];
    unsigned char nLevel;
    unsigned short wPrefix[3];
    unsigned short wSuffix[3];
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x28];
    unsigned int dwCode;
    char unk0x2C[0x08];
    unsigned char nLevel;
    char unk0x35[0x117];
};

struct D2SetItemsTxt
{
    char unk0x00[0x28];
    unsigned int dwCode;
    char unk0x2C[0x04];
    unsigned char nLevel;
    char unk0x31[0x187];
};

extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet); // 0x00688990
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" unsigned int __cdecl strlen(const char* szString);
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn); // 0x006BD3C0

extern "C" const char gszComma_006EE82C[]; // 0x006EE82C
extern "C" const char gszEqualComma_006EE824[]; // 0x006EE824
extern "C" const char gszCowPortal_006EE88C[]; // 0x006EE88C
extern "C" const char gszPandemoniumPortal_006EE878[]; // 0x006EE878
extern "C" const char gszPandemoniumFinalePortal_006EE85C[]; // 0x006EE85C
extern D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824
extern D2TxtLinkStrc* gpSetItemsLinker_0096C844; // 0x0096C844
extern D2SetItemsTxt* gpSetItemsTxt_0096C848; // 0x0096C848
extern D2TxtLinkStrc* gpUniqueItemsLinker_0096C850; // 0x0096C850
extern D2UniqueItemsTxt* gpUniqueItemsTxt_0096C854; // 0x0096C854

// 0x00668510
static __declspec(noinline) void sub_00668510_MakeCode(const char* szText, char* szCode)
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

// 0x00668590
static char* sub_00668590_NextSetToken(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return szToken;
}

// 0x006685C0
static int sub_006685C0_NextSetTokenInt(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return atoi(szToken);
}

// build: context DATATBLS_StringToCode
static __forceinline int DATATBLS_StringToCode(const char* szText)
{
    int nCode;
    sub_00668510_MakeCode(szText, (char*)&nCode);
    return nCode;
}

// build: context sub_00668A90_LookupItem
static __forceinline int sub_00668A90_LookupItem(D2CubeInputItemStrc* pInput, char* szText)
{
    int nLinkId;
    if (strlen(szText) <= 4 && (nLinkId = FOG_GetLinkIndex(gpItemTypesLinker_0096C824, DATATBLS_StringToCode(szText), 0)) >= 0)
    {
        pInput->nType = 0xFD;
        pInput->wItem = nLinkId;
    }
    else
    {
        nLinkId = -1;
        if (gpUniqueItemsLinker_0096C850)
        {
            nLinkId = FOG_GetRowFromTxt(gpUniqueItemsLinker_0096C850, szText, 0);
        }
        if (nLinkId >= 0)
        {
            int nItemId;
            DATATBLS_GetItemRecordFromItemCode(gpUniqueItemsTxt_0096C854[nLinkId].dwCode, &nItemId);
            pInput->wFlags |= 8;
            pInput->nType = 0xFC;
            pInput->nQuality = 7;
            pInput->wItemId = nLinkId + 1;
            pInput->wItem = nItemId;
            pInput->nLevel = gpUniqueItemsTxt_0096C854[nLinkId].nLevel;
        }
        else
        {
            nLinkId = -1;
            if (gpSetItemsLinker_0096C844)
            {
                nLinkId = FOG_GetRowFromTxt(gpSetItemsLinker_0096C844, szText, 0);
            }
            if (nLinkId >= 0)
            {
                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(gpSetItemsTxt_0096C848[nLinkId].dwCode, &nItemId);
                pInput->wFlags |= 8;
                pInput->nType = 0xFC;
                pInput->nQuality = 5;
                pInput->wItemId = nLinkId + 1;
                pInput->wItem = nItemId;
                pInput->nLevel = gpSetItemsTxt_0096C848[nLinkId].nLevel;
            }
            return 0;
        }
    }
    return 1;
}

// build: context sub_00668A90_TryItemCode
static __forceinline int sub_00668A90_TryItemCode(D2CubeInputItemStrc* pInput, char* szText)
{
    int nCode;
    if (strlen(szText) <= 4 && DATATBLS_GetItemRecordFromItemCode(DATATBLS_StringToCode(szText), &nCode))
    {
        pInput->nType = 0xFC;
        pInput->wItem = nCode;
        return 1;
    }
    return 0;
}

// build: context sub_00668A90_ParseItemName
static __forceinline int sub_00668A90_ParseItemName(D2CubeInputItemStrc* pInput, char* szText)
{
    if (!_stricmp(szText, gszCowPortal_006EE88C))
    {
        pInput->nType = 1;
        return 1;
    }
    if (!_stricmp(szText, gszPandemoniumPortal_006EE878))
    {
        pInput->nType = 2;
        return 1;
    }
    if (!_stricmp(szText, gszPandemoniumFinalePortal_006EE85C))
    {
        pInput->nType = 3;
        return 1;
    }
    if (!strcmp(szText, "usetype"))
    {
        pInput->nType = 0xFF;
        return 1;
    }

    if (!strcmp(szText, "useitem"))
    {
        pInput->nType = 0xFE;
        return 1;
    }

    return 0;
}

static int __declspec(noinline) __stdcall sub_00668A90_ParseCubeInput(D2CubeInputItemStrc* pInput, char* szInput);

// 0x00668A90
static int __stdcall sub_00668A90_ParseCubeInput(D2CubeInputItemStrc* pInput, char* szInput)
{
    char* szText = szInput;
    if (*szText == '"')
    {
        ++szText;
    }

    for (char* pChar = szText; *pChar; ++pChar)
    {
        if (*pChar == '"')
        {
            *pChar = 0;
        }
    }

    char* szNext = szText + strcspn(szText, gszComma_006EE82C);
    if (*szNext)
    {
        *szNext = 0;
        ++szNext;
    }
    else
    {
        szNext = 0;
    }

    if (!sub_00668A90_ParseItemName(pInput, szText) && !sub_00668A90_TryItemCode(pInput, szText) && !sub_00668A90_LookupItem(pInput, szText))
    {
        return 0;
    }

    if (szNext)
    {

        unsigned short* pSuffix = pInput->wSuffix;
        unsigned short* pPrefix = pInput->wPrefix;
        do
        {
            char* szToken = sub_00668590_NextSetToken(&szNext, gszEqualComma_006EE824);
            if (!szToken)
            {
                break;
            }

            if (!strcmp(szToken, "qty"))
            {
                pInput->nQuantity = sub_006685C0_NextSetTokenInt(&szNext, gszComma_006EE82C);
            }
            else if (!strcmp(szToken, "pre"))
            {
                *pPrefix = sub_006685C0_NextSetTokenInt(&szNext, gszComma_006EE82C);
                ++pPrefix;
            }
            else if (!strcmp(szToken, "suf"))
            {
                *pSuffix = sub_006685C0_NextSetTokenInt(&szNext, gszComma_006EE82C);
                ++pSuffix;
            }
            else if (!strcmp(szToken, "low"))
            {
                pInput->nQuality = 1;
            }
            else if (!strcmp(szToken, "nor"))
            {
                pInput->nQuality = 2;
            }
            else if (!strcmp(szToken, "hiq"))
            {
                pInput->nQuality = 3;
            }
            else if (!strcmp(szToken, "mag"))
            {
                pInput->nQuality = 4;
            }
            else if (!strcmp(szToken, "set"))
            {
                pInput->nQuality = 5;
            }
            else if (!strcmp(szToken, "rar"))
            {
                pInput->nQuality = 6;
            }
            else if (!strcmp(szToken, "uni"))
            {
                pInput->nQuality = 7;
            }
            else if (!strcmp(szToken, "crf"))
            {
                pInput->nQuality = 8;
            }
            else if (!strcmp(szToken, "tmp"))
            {
                pInput->nQuality = 9;
            }
            else if (!strcmp(szToken, "eth"))
            {
                pInput->wFlags |= 4;
            }
            else if (!strcmp(szToken, "sock"))
            {
                pInput->wFlags |= 2;
                pInput->nQuantity = sub_006685C0_NextSetTokenInt(&szNext, gszComma_006EE82C);
            }
            else if (!strcmp(szToken, "mod"))
            {
                pInput->wFlags |= 1;
            }
            else if (!strcmp(szToken, "uns"))
            {
                pInput->wFlags |= 0x10;
            }
            else if (!strcmp(szToken, "rem"))
            {
                pInput->wFlags |= 0x20;
            }
            else if (!strcmp(szToken, "reg"))
            {
                pInput->wFlags |= 0x40;
                pInput->nType = 0xFF;
            }
            else if (!strcmp(szToken, "exc"))
            {
                pInput->wFlags |= 0x80;
            }
            else if (!strcmp(szToken, "eli"))
            {
                pInput->wFlags |= 0x100;
            }
            else if (!strcmp(szToken, "rep"))
            {
                pInput->wFlags |= 0x200;
            }
            else if (!strcmp(szToken, "rch"))
            {
                pInput->wFlags |= 0x400;
            }
            else
            {
                break;
            }
        }
        while (szNext);
    }

    return 1;
}

// 0x006690B0
void __fastcall DATATBLS_CubeMainOutputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    if (pRecord && pSrc && *pSrc)
        sub_00668A90_ParseCubeInput((D2CubeInputItemStrc*)((char*)pRecord + 0x4C + nOffset * 0x54), pSrc);
}

#include "gen/data/Source/D2Common/00668A90_sub_00668A90_ParseCubeInput.inc"
