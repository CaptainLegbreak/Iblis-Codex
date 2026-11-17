struct D2OptionHeaderStrc
{
    int nCount;
};

struct D2OptionEntryStrc
{
    int nKind;
    char unk0x004[0x10C];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[0x414];
    void* pCel;
    void* pValueCels[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_0044BA20(int nResolution);                                                              // 0x0044BA20
void __fastcall sub_0044BE80(int bAlwaysRun);                                                               // 0x0044BE80
int __cdecl sub_004576C0();                                                                                 // 0x004576C0
void __fastcall sub_004576F0(int nFade);                                                                    // 0x004576F0
int __cdecl sub_0045A710();                                                                                 // 0x0045A710
void __fastcall sub_0045A720(int nMode);                                                                    // 0x0045A720
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00

// 0x0047D3B0
void __fastcall sub_0047D3B0_LoadAutoMapMode(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapMode", 0, &dwValue);
    if (dwValue > 2)
    {
        dwValue = 0;
    }
    sub_0045A720(dwValue);
    pEntry->nValue = sub_0045A710();
}

// 0x0047D430
void __fastcall sub_0047D430_LoadAutoMapFade(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    if (dwValue > 4)
    {
        dwValue = 0;
        sub_004576F0(dwValue);
    }
    pEntry->nValue = sub_004576C0();
}

// 0x0047DF00
void __fastcall sub_0047DF00_FreeOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x558);
    D2_ASSERT(pEntries, 0x559);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
        D2OptionEntryStrc* pEntry = &pEntries[i];
        if (pEntry->pCel)
        {
            sub_00478A00(pEntry->pCel);
            pEntry->pCel = 0;
        }
        if (pEntry->nKind == 1)
        {
            D2_ASSERT(pEntry->nValues > 0 && pEntry->nValues <= 4, 0x565);
            for (unsigned int j = 0; j < pEntry->nValues; ++j)
            {
                if (pEntry->pValueCels[j])
                {
                    sub_00478A00(pEntry->pValueCels[j]);
                    pEntry->pValueCels[j] = 0;
                }
            }
        }
    }
}

// 0x0047E720
void __cdecl sub_0047E720_LoadAlwaysRun()
{
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "Always Run", 0, &dwValue);
    sub_0044BE80(dwValue);
}

// 0x0047F1D0
void __cdecl sub_0047F1D0_LoadResolution()
{
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Resolution", 0, &dwValue))
    {
        dwValue = 1;
    }
    int nResolution = 2;
    if (!dwValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}
