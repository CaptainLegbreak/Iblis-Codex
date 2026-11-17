struct D2CubeMainTxt
{
    char unk0x000[0x144];
    int nSynTail;
};

struct D2DataTablesStrc
{
    char unk0x0000[0x19F8];
    D2CubeMainTxt* pCubeMainTxt;
    int nCubeMainTxtRecordCount;
};

extern D2DataTablesStrc gtDataTables_0096BC30;                                                                       // 0x0096BC30
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define CUBE_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0066A1A0
void __fastcall DATATBLS_UnloadCubeMainTxt()
{
    DATATBLS_UnloadBin(gtDataTables_0096BC30.pCubeMainTxt);
}

// 0x0066A1B0
D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex)
{
    CUBE_ASSERT(gtDataTables_0096BC30.pCubeMainTxt, 846);
    CUBE_ASSERT(nIndex < gtDataTables_0096BC30.nCubeMainTxtRecordCount, 847);

    return &gtDataTables_0096BC30.pCubeMainTxt[nIndex];
}

// 0x0066A200
int __fastcall DATATBLS_GetCubemainTxtRecordCount()
{
    return gtDataTables_0096BC30.nCubeMainTxtRecordCount;
}

void __stdcall DATATBLS_EmptyStub_0066A220(int a1, int a2)
{
}

void __stdcall DATATBLS_EmptyStub_0066A250(int a1)
{
}

void __fastcall DATATBLS_EmptyStub_0066A260()
{
}

void __fastcall sub_0066A270()
{
}

void __fastcall DATATBLS_EmptyStub_0066A280()
{
}
