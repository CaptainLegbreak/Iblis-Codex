struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
D2TxtLinkStrc* gTxtLink_0096C81C;                                                                           // 0x0096C81C
void __fastcall sub_006117B0();                                                                 // 0x006117B0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpPettypeTxt;                                                                                  // 0x0096C818
int gnPettypeTxtRecordCount;                                                                                // 0x0096C820
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpPettypeLinker;                                                                      // 0x0096C81C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00618D90
void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "pet type", 18, 0, 0, &gTxtLink_0096C81C },
        { "group", 3, 0, 8, 0 },
        { "basemax", 3, 0, 10, 0 },
        { "warp", 26, 0, 4, 0 },
        { "range", 26, 1, 4, 0 },
        { "partysend", 26, 2, 4, 0 },
        { "unsummon", 26, 3, 4, 0 },
        { "automap", 26, 4, 4, 0 },
        { "drawhp", 26, 5, 4, 0 },
        { "icontype", 4, 0, 14, 0 },
        { "baseicon", 1, 32, 15, 0 },
        { "mclass1", 3, 0, 178, 0 },
        { "micon1", 1, 32, 47, 0 },
        { "mclass2", 3, 0, 180, 0 },
        { "micon2", 1, 32, 79, 0 },
        { "mclass3", 3, 0, 182, 0 },
        { "micon3", 1, 32, 111, 0 },
        { "mclass4", 3, 0, 184, 0 },
        { "micon4", 1, 32, 143, 0 },
        { "name", 22, 0, 12, (void*)sub_006117B0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C81C = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1833);
    gpPettypeTxt = DATATBLS_CompileTxt(hArchive, "pettype", pTbl, &gnPettypeTxtRecordCount, 224);
    TBL_ASSERT(gnPettypeTxtRecordCount < 256, 1835);
    gnPettypeTxtRecordCount = gnPettypeTxtRecordCount <= 0 ? 0 : gnPettypeTxtRecordCount;
    if (gnPettypeTxtRecordCount >= 256)
    {
        gnPettypeTxtRecordCount = 256;
    }
}
