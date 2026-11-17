#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2CelFileStrc;
struct D2CelStrc;
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

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries);      // 0x0047DBB0
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                              // 0x004788B0
D2CelFileStrc* __cdecl sub_00453AA0();                                                                      // 0x00453AA0
int __stdcall sub_006019F0(D2CelFileStrc* pCelFile);                                                // 0x006019F0
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0

extern D2OptionHeaderStrc gOptionHeader_00713044;                                                           // 0x00713044
extern D2OptionEntryStrc gaOptionEntries_00713220[];                                                        // 0x00713220
extern D2OptionHeaderStrc gOptionHeader_00714210;                                                           // 0x00714210
extern D2OptionEntryStrc gaOptionEntries_00714238[];                                                        // 0x00714238
extern D2OptionHeaderStrc gOptionHeader_00714224;                                                           // 0x00714224
extern D2OptionEntryStrc gaOptionEntries_00715CC8[];                                                        // 0x00715CC8
extern D2OptionHeaderStrc gOptionHeader_0071875C;                                                           // 0x0071875C
extern D2OptionEntryStrc gaOptionEntries_0071ACA0[];                                                        // 0x0071ACA0
extern D2OptionHeaderStrc gOptionHeader_0071D734;                                                           // 0x0071D734
extern D2OptionEntryStrc gaOptionEntries_0071F728[];                                                        // 0x0071F728
extern D2OptionHeaderStrc gOptionHeader_00718748;                                                           // 0x00718748
extern D2OptionEntryStrc gaOptionEntries_00718770[];                                                        // 0x00718770
extern D2OptionHeaderStrc gOptionHeader_0071D720;                                                           // 0x0071D720
extern D2OptionEntryStrc gaOptionEntries_0071D748[];                                                        // 0x0071D748
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C;                                                         // 0x007BC93C
extern D2OptionEntryStrc* gpOptionEntries_007BC940;                                                         // 0x007BC940
extern D2CelFileStrc* gpOptionCel_007BC950;                                                                 // 0x007BC950
extern D2CelFileStrc* gpOptionCel_007BC954;                                                                 // 0x007BC954
extern D2CelFileStrc* gpOptionCel_007BC958;                                                                 // 0x007BC958
int gnOptionMaxWidth_007BC95C;                                                                              // 0x007BC95C
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118

// 0x0047DD70
void __cdecl sub_0047DD70_LoadOptionMenus()
{
    D2CelContextStrc tContext;
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00713044, gaOptionEntries_00713220);
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00714210, gaOptionEntries_00714238);
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00714224, gaOptionEntries_00715CC8);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071875C, gaOptionEntries_0071ACA0);
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071D734, gaOptionEntries_0071F728);
    }
    else
    {
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_00718748, gaOptionEntries_00718770);
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071D720, gaOptionEntries_0071D748);
    }
    gpOptionHeader_007BC93C = &gOptionHeader_00713044;
    gpOptionEntries_007BC940 = gaOptionEntries_00713220;
    char szPath[260] = {0};
    sprintf(szPath, "%s\\UI\\Widgets\\OptBar", szDataGlobal_006D4118);
    gpOptionCel_007BC950 = sub_004788B0(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptBarC", szDataGlobal_006D4118);
    gpOptionCel_007BC954 = sub_004788B0(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptSkull", szDataGlobal_006D4118);
    gpOptionCel_007BC958 = sub_004788B0(szPath, 0);
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00453AA0();
    const unsigned int nFrames = sub_006019F0(tContext.pCellFile);
    int nMax = 0;
    for (tContext.nFrame = 0; tContext.nFrame < nFrames; ++tContext.nFrame)
        nMax = D2_MAX(nMax, sub_006018C0(D2CMP_CelGetHandle(&tContext)));
    gnOptionMaxWidth_007BC95C = nMax;
}

#include "gen/data/Source/D2Client/0047DD70_sub_0047DD70_LoadOptionMenus.inc"
