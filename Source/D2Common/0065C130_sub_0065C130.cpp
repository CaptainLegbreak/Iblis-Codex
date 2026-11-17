struct D2Block0 { int n[4]; };
struct D2Block1 { int n[6]; };
struct D2Block2 { int n[5]; };
struct D2Table96D4F4Record
{
    D2Block0 tBlock0;
    D2Block1 tBlock1;
    D2Block2 tBlock2[10];
};

unsigned int gnTable96D4F4RecordCount;                                                                      // 0x0096D4F0
D2Table96D4F4Record* gpTable96D4F4;                                                                         // 0x0096D4F4
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define T4_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static D2Table96D4F4Record* sub_0065C140(unsigned int nIndex)
{
    T4_ASSERT(gpTable96D4F4, 127);

    if (nIndex > gnTable96D4F4RecordCount)
    {
        return 0;
    }

    return &gpTable96D4F4[nIndex];
}

// 0x0065C130
void __fastcall sub_0065C130()
{
    DATATBLS_UnloadBin(gpTable96D4F4);
}

// 0x0065C180
void __stdcall sub_0065C180(int nId, int nGroup, D2Block0* pBlock)
{
    D2Table96D4F4Record* pRecord = sub_0065C140(nId + 16 * nGroup);
    T4_ASSERT(pRecord, 140);

    *pBlock = pRecord->tBlock0;
}

// 0x0065C1F0
void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock)
{
    D2Table96D4F4Record* pRecord = sub_0065C140(nId + 16 * nGroup);
    T4_ASSERT(pRecord, 151);

    *pBlock = pRecord->tBlock1;
}

// 0x0065C270
void __stdcall sub_0065C270(int nId, int nGroup, D2Block2* pBlock, int nEntry)
{
    D2Table96D4F4Record* pRecord = sub_0065C140(nId + 16 * nGroup);
    T4_ASSERT(pRecord, 163);

    D2Block2* pEntry = &pRecord->tBlock2[nEntry];
    T4_ASSERT(pEntry, 165);

    *pBlock = *pEntry;
}
