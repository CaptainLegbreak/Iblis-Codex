#include "D2TxtItems.h"
struct D2ItemsTxt;
struct D2CubeMainTxtStrc
{
    char unk0x00[0x0C];
    D2CubeInputItem pInputItem[7];
};

struct D2UniqueItemsTxtStrc
{
    char unk0x00[0x28];
    int dwBaseItemCode;
    char unk0x2C[0x120];
};

struct D2SetItemsTxtStrc
{
    char unk0x00[0x28];
    int szItemCode;
    char unk0x2C[0x18C];
};

extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet);                          // 0x00688990
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
#pragma intrinsic(strlen, strcmp)

int __stdcall FOG_GetLinkIndex(void* pLinker, int nCode, int bLogError);                                    // 0x006BD130
int __stdcall FOG_GetRowFromTxt(void* pLinker, const char* szText, int nColumn);                            // 0x006BD3C0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

extern void* gpItemTypesLinker_0096C824;                                                                    // 0x0096C824
extern void* gpSetItemsLinker_0096C844;                                                                     // 0x0096C844
extern D2SetItemsTxtStrc* gpSetItemsTxt_0096C848;                                                          // 0x0096C848
extern void* gpUniqueItemsLinker_0096C850;                                                                  // 0x0096C850
extern D2UniqueItemsTxtStrc* gpUniqueItemsTxt_0096C854;                                                    // 0x0096C854

static void sub_00668510_MakeCode(const char* szText, char* szCode);

// 0x00668510
static void sub_00668510_MakeCode(const char* szText, char* szCode)
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

static __forceinline int DATATBLS_StringToCode(const char* szText)
{
    int nCode;
    sub_00668510_MakeCode(szText, (char*)&nCode);
    return nCode;
}

static int __stdcall sub_00668600_CubeMainInputParser(D2CubeInputItem* pCubeInput, char* szInput);

// build: context sub_00668600_CubeMainInputParser
static int __stdcall sub_00668600_CubeMainInputParser(D2CubeInputItem* pCubeInput, char* szInput)
{
    char* szInputModifier;
    char* szNext;
    char* szTemp;
    int nBaseItemId;
    int nLinkId;

    if (*szInput == '"')
    {
        ++szInput;
    }

    szTemp = szInput;
    while (*szTemp)
    {
        if (*szTemp == '"')
        {
            *szTemp = 0;
        }
        ++szTemp;
    }

    if (!*szInput)
    {
        return 1;
    }

    {
        szNext = &szInput[strcspn(szInput, ",")];
        if (*szNext)
        {
            *szNext = 0;
            ++szNext;
        }
        else
        {
            szNext = 0;
        }

        if (strlen(szInput) <= 4 && !_stricmp(szInput, "any"))
        {
            pCubeInput->wInputFlags |= 1;
            pCubeInput->wItem = -1;
        }
        else
        {
            nLinkId = -1;

            if (strlen(szInput) <= 4)
            {
                nLinkId = FOG_GetLinkIndex(gpItemTypesLinker_0096C824, DATATBLS_StringToCode(szInput), 0);
            }

            if (nLinkId >= 0)
            {
                pCubeInput->wInputFlags |= 2;
                pCubeInput->wItem = nLinkId;
            }
            else if (strlen(szInput) <= 4 && DATATBLS_GetItemRecordFromItemCode(DATATBLS_StringToCode(szInput), &nBaseItemId))
            {
                pCubeInput->wInputFlags |= 1;
StoreBaseItem:
                pCubeInput->wItem = nBaseItemId;
            }
            else
            {
                nLinkId = -1;

                if (gpUniqueItemsLinker_0096C850)
                {
                    nLinkId = FOG_GetRowFromTxt(gpUniqueItemsLinker_0096C850, szInput, 0);
                }

                if (nLinkId >= 0)
                {
                    DATATBLS_GetItemRecordFromItemCode(gpUniqueItemsTxt_0096C854[nLinkId].dwBaseItemCode, &nBaseItemId);
                    pCubeInput->wInputFlags |= 0x41;
                    pCubeInput->nQuality = 7;
                    pCubeInput->wItemID = nLinkId + 1;
                    goto StoreBaseItem;
                }
                else
                {
                    nLinkId = -1;

                    if (gpSetItemsLinker_0096C844)
                    {
                        nLinkId = FOG_GetRowFromTxt(gpSetItemsLinker_0096C844, szInput, 0);
                    }

                    if (nLinkId >= 0)
                    {
                        DATATBLS_GetItemRecordFromItemCode(gpSetItemsTxt_0096C848[nLinkId].szItemCode, &nBaseItemId);
                        pCubeInput->wInputFlags |= 0x41;
                        pCubeInput->nQuality = 5;
                        pCubeInput->wItemID = nLinkId + 1;
                        goto StoreBaseItem;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }

        while (szNext)
        {
            szInputModifier = szNext;
            szNext = &szNext[strcspn(szNext, "=,")];
            if (*szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            else
            {
                szNext = 0;
            }

            if (!szInputModifier)
            {
                return 1;
            }

            if (!strcmp(szInputModifier, "qty"))
            {
                szTemp = szNext;
                szNext = &szNext[strcspn(szNext, ",")];
                if (*szNext)
                {
                    *szNext = 0;
                    ++szNext;
                    pCubeInput->nQuantity = atoi(szTemp);
                }
                else
                {
                    szNext = 0;
                    pCubeInput->nQuantity = atoi(szTemp);
                }
            }
            else if (!strcmp(szInputModifier, "low"))
            {
                pCubeInput->nQuality = 1;
            }
            else if (!strcmp(szInputModifier, "nor"))
            {
                pCubeInput->nQuality = 2;
            }
            else if (!strcmp(szInputModifier, "hiq"))
            {
                pCubeInput->nQuality = 3;
            }
            else if (!strcmp(szInputModifier, "mag"))
            {
                pCubeInput->nQuality = 4;
            }
            else if (!strcmp(szInputModifier, "set"))
            {
                pCubeInput->nQuality = 5;
            }
            else if (!strcmp(szInputModifier, "rar"))
            {
                pCubeInput->nQuality = 6;
            }
            else if (!strcmp(szInputModifier, "uni"))
            {
                pCubeInput->nQuality = 7;
            }
            else if (!strcmp(szInputModifier, "crf"))
            {
                pCubeInput->nQuality = 8;
            }
            else if (!strcmp(szInputModifier, "tmp"))
            {
                pCubeInput->nQuality = 9;
            }
            else if (!strcmp(szInputModifier, "nos"))
            {
                pCubeInput->wInputFlags |= 4;
            }
            else if (!strcmp(szInputModifier, "sock"))
            {
                pCubeInput->wInputFlags |= 8;
            }
            else if (!strcmp(szInputModifier, "noe"))
            {
                pCubeInput->wInputFlags |= 0x20;
            }
            else if (!strcmp(szInputModifier, "eth"))
            {
                pCubeInput->wInputFlags |= 0x10;
            }
            else if (!strcmp(szInputModifier, "upg"))
            {
                pCubeInput->wInputFlags |= 0x80;
            }
            else if (!strcmp(szInputModifier, "bas"))
            {
                pCubeInput->wInputFlags |= 0x100;
            }
            else if (!strcmp(szInputModifier, "exc"))
            {
                pCubeInput->wInputFlags |= 0x200;
            }
            else if (!strcmp(szInputModifier, "eli"))
            {
                pCubeInput->wInputFlags |= 0x400;
            }
            else if (!strcmp(szInputModifier, "nru"))
            {
                pCubeInput->wInputFlags |= 0x800;
            }
            else
            {
                return 1;
            }
        }
    }

    return 1;
}

// 0x00669080
void __fastcall sub_00669080_CubeInputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    if (pRecord && pSrc && *pSrc)
        sub_00668600_CubeMainInputParser((D2CubeInputItem*)((char*)pRecord + 0x14 + 8 * nOffset), pSrc);
}
