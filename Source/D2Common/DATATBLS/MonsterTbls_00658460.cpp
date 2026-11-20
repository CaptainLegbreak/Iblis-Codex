#include "D2Records.h"
struct D2TxtLinkStrc;


struct D2MonTypeTxt
{
    short nType;
    short nEquiv[3];
    char unk0x08[4];
};

extern "C" const char gszTxtField_equiv1[];                                                                 // 0x006DCD14
extern "C" const char gszTxtField_equiv2[];                                                                 // 0x006DCD0C
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096C868;                                                                    // 0x0096C868
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0
extern D2MonTypeTxt* gpMonTypeTxt;                                                                          // 0x0096C86C
extern int gnMonTypeTxtRecordCount;                                                                         // 0x0096C870
extern unsigned int* gpMonTypeNest;                                                                         // 0x0096C874
extern int gnMonTypeIndex;                                                                                  // 0x0096C878
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#pragma function(memset)

// 0x00658460
int __fastcall DATATBLS_CheckNestedMonsterTypes(int nMonType1, int nMonType2)
{
    int nParentMonsterTypes[128];

    if (nMonType2 <= 0)
    {
        return 0;
    }

    if (nMonType1 <= 0 || nMonType1 >= gnMonTypeTxtRecordCount)
    {
        return 0;
    }

    nParentMonsterTypes[0] = nMonType1;
    int nIndex = 1;
    do
    {
        int nMonsterType = nParentMonsterTypes[--nIndex];
        if (nMonType2 == nMonsterType)
        {
            return 1;
        }

        if (nMonsterType >= gnMonTypeTxtRecordCount || nIndex > 124)
        {
            break;
        }

        D2MonTypeTxt* pMonTypeTxtRecord = &gpMonTypeTxt[nMonsterType];
        if (pMonTypeTxtRecord->nEquiv[0] > 0)
        {
            nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[0];
            if (pMonTypeTxtRecord->nEquiv[1])
            {
                nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[1];
                if (pMonTypeTxtRecord->nEquiv[2])
                {
                    nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[2];
                }
            }
        }
    }
    while (nIndex);

    return 0;
}

void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "type", 17, 0, 0, &gTxtLink_0096C868 },
        { gszTxtField_equiv1, 20, 0, 2, &gTxtLink_0096C868 },
        { gszTxtField_equiv2, 20, 0, 4, &gTxtLink_0096C868 },
        { "equiv3", 20, 0, 6, &gTxtLink_0096C868 },
        { "strsing", 22, 0, 8, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "strplur", 22, 0, 10, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C868 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2806);
    gpMonTypeTxt = (D2MonTypeTxt*)DATATBLS_CompileTxt(hArchive, "montype", pTbl, &gnMonTypeTxtRecordCount, 12);

    gnMonTypeIndex = (gnMonTypeTxtRecordCount + 31) / 32;
    int nSize = sizeof(unsigned int) * gnMonTypeIndex * gnMonTypeTxtRecordCount;
    gpMonTypeNest = (unsigned int*)FOG_AllocPool(0, nSize, ".\\DATATBLS\\MonsterTbls.cpp", 2812, 0);
    memset(gpMonTypeNest, 0, nSize);

    for (int i = 0; i < gnMonTypeTxtRecordCount; ++i)
    {
        unsigned int* pMonTypeNest = &gpMonTypeNest[gnMonTypeIndex * i];
        for (int j = 0; j < gnMonTypeTxtRecordCount; ++j)
        {
            if (DATATBLS_CheckNestedMonsterTypes(i, j))
            {
                pMonTypeNest[j >> 5] |= gdwBitMasks[j & 31];
            }
        }
    }
}
