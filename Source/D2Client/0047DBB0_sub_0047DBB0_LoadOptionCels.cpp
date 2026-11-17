struct D2CelFileStrc;

struct D2OptionHeaderStrc
{
    int nCount;
};

struct D2OptionEntryStrc
{
    int nKind;
    int bExpansionOnly;
    char unk0x008[4];
    char f_C[0x104];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[4];
    char szValueCels[4][0x104];
    void* pCel;
    void* pValueCels[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                              // 0x004788B0

extern "C" const char szDataLocal_006D41A8[];                                                               // 0x006D41A8

// 0x0047DBB0
void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x4E8);
    D2_ASSERT(pEntries, 0x4E9);
    char szPath[260] = {0};
    char szLang[4] = {0};
    sub_00525260(szLang, 0);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
        if (pEntries[i].bExpansionOnly && !sub_00408F20_HasExpansionMpq())
            continue;
        if (pEntries[i].f_C[0])
        {
            sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].f_C);
            pEntries[i].pCel = sub_004788B0(szPath, 0);
            if (pEntries[i].nKind == 1)
            {
                D2_ASSERT(pEntries[i].nValues > 0 && pEntries[i].nValues <= 4, 0x4FE);
                for (unsigned int j = 0; j < pEntries[i].nValues; ++j)
                {
                    D2_ASSERT(pEntries[i].szValueCels[j][0], 0x501);
                    sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].szValueCels[j]);
                    pEntries[i].pValueCels[j] = sub_004788B0(szPath, 0);
                }
            }
        }
        if (pEntries[i].pfnLoad)
            pEntries[i].pfnLoad(&pEntries[i], 0);
    }
}
