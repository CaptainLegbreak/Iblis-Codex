struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2CellFileStrc;

struct D2OptionHeaderStrc
{
    int nCount;
    int nHeight;
    int nTextOffset;
    int nArrowOffset;
};

struct D2OptionEntryStrc
{
    int nKind;
    int bExpansionOnly;
    int nY;
    char f_C[0x104];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[4];
    char szValueCels[4][0x104];
    D2CellFileStrc* pCel;
    D2CellFileStrc* pValueCels[4];
};

extern "C" __declspec(dllimport) int __stdcall SendMessageA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC49C
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860
void __fastcall sub_0047E200_CloseMenus(int bRestore);                                                      // 0x0047E200

static int gnOptionSelected_007BC938;                                                                       // 0x007BC938
D2OptionHeaderStrc* gpOptionHeader_007BC93C;                                                                // 0x007BC93C
static D2OptionEntryStrc* gpOptionEntries_007BC940;                                                         // 0x007BC940
extern D2OptionHeaderStrc gOptionHeader_00713044;                                                           // 0x00713044
extern D2OptionEntryStrc gaOptionEntries_00713220[];                                                        // 0x00713220
extern D2OptionHeaderStrc gOptionHeader_00714210;                                                           // 0x00714210
extern D2OptionHeaderStrc gOptionHeader_00714224;                                                           // 0x00714224
extern D2OptionEntryStrc gaOptionEntries_00714238[];                                                        // 0x00714238
extern D2OptionEntryStrc gaOptionEntries_00715CC8[];                                                        // 0x00715CC8
extern D2OptionHeaderStrc gOptionHeader_00718748;                                                           // 0x00718748
extern D2OptionHeaderStrc gOptionHeader_0071875C;                                                           // 0x0071875C
extern D2OptionEntryStrc gaOptionEntries_00718770[];                                                        // 0x00718770
extern D2OptionEntryStrc gaOptionEntries_0071ACA0[];                                                        // 0x0071ACA0
extern D2OptionHeaderStrc gOptionHeader_0071D720;                                                           // 0x0071D720
extern D2OptionHeaderStrc gOptionHeader_0071D734;                                                           // 0x0071D734
extern D2OptionEntryStrc gaOptionEntries_0071D748[];                                                        // 0x0071D748
extern D2OptionEntryStrc gaOptionEntries_0071F728[];                                                        // 0x0071F728

// 0x0047F2A0
void __fastcall sub_0047F2A0_ShowPage1(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714210;
    gpOptionEntries_007BC940 = gaOptionEntries_00714238;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F460
void __fastcall sub_0047F460_ShowPage1Twin(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714210;
    gpOptionEntries_007BC940 = gaOptionEntries_00714238;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F2D0
void __fastcall sub_0047F2D0_ExitGame(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_0044B880_SetValue(0);
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    sub_0044C860_SetValue(1);
    sub_0047E200_CloseMenus(1);
}

// 0x0047F300
void __fastcall sub_0047F300_CloseMenus(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047E200_CloseMenus(1);
}

// 0x0047F310
void __fastcall sub_0047F310_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00714224;
    gpOptionEntries_007BC940 = gaOptionEntries_00715CC8;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F340
void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071875C;
        gpOptionEntries_007BC940 = gaOptionEntries_0071ACA0;
    }
    else
    {
        gpOptionHeader_007BC93C = &gOptionHeader_00718748;
        gpOptionEntries_007BC940 = gaOptionEntries_00718770;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F3A0
void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071D734;
        gpOptionEntries_007BC940 = gaOptionEntries_0071F728;
    }
    else
    {
        gpOptionHeader_007BC93C = &gOptionHeader_0071D720;
        gpOptionEntries_007BC940 = gaOptionEntries_0071D748;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

// 0x0047F400
void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_004538D0(9))
        sub_00455F20(9, 1, 0);
    sub_00455F20(0xB, 0, 0);
}

// 0x0047F430
void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(9, 0, 0);
    gpOptionHeader_007BC93C = &gOptionHeader_00713044;
    gpOptionEntries_007BC940 = gaOptionEntries_00713220;
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
}

#include "gen/data/Source/D2Client/0047F2A0_sub_0047F2A0_ShowPage1.inc"
