// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

struct D2UnitStrc;
struct D2ClientDialogStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_0048C060(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x0048C060
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength); // 0x004B2AD0
int __cdecl sub_004B2E70_MenuBack();                                                                        // 0x004B2E70
int __cdecl sub_004B2F00_MenuClose();                                                                       // 0x004B2F00
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8);                                                                   // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern D2ClientDialogStrc* gpDialog_007C0D5F;                                                               // 0x007C0D5F
extern int gnGlobal_007C0DE5;                                                                               // 0x007C0DE5
extern Unicode gwszCost_007C0DF5[];                                                                         // 0x007C0DF5

// 0x004B2F50
void __cdecl sub_004B2F50_ShowTradeDialog()
{
    D2_ASSERT(!gpDialog_007C0D5F, 0x151B);

    gnGlobal_007C0C6B = 4;
    gpDialog_007C0D5F = sub_004B7EB0_CreateDialog(sub_00468730(), sub_00468740(), sub_004B2F00_MenuClose, 0, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0D5F, 1);

    D2UnitStrc* pItem;
    int bService;
    int bShowItem = 1;
    switch (gnGlobal_007C0D31)
    {
    case 1:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD14), 0x15, 0, 4, 1, 0, 0);
        bService = 0;
        break;

    case 2:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD13), 0x15, 0, 4, 1, 0, 0);
        bService = 1;
        break;

    case 3:
        bService = 1;
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD17), 0x15, 0, 4, 1, 0, 0);
        break;

    case 4:
        bService = 1;
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD16), 0x15, 0, 4, 1, 0, 0);
        break;

    case 5:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD18), 0x15, 0, 4, 1, 0, 0);
        bShowItem = 0;
        break;

    default:
        D2_ASSERT(0, 0x1550);
    }

    if (bShowItem)
    {
        pItem = sub_00463990(gnGlobal_007C0DE5, 4);
        if (!pItem)
        {
            return;
        }

        UnicodeChar wszName[0xC0];
        sub_0048C060(pItem, wszName, 0xBF);
        const int nLength = sub_00526800(wszName);
        int i = 0;
        int bDone = 0;
        while (!bDone)
        {
            if (i >= nLength)
            {
                bDone = 1;
            }
            else if (wszName[i].wChar == '\n')
            {
                wszName[i].wChar = 0;
                bDone = 1;
            }
            else
            {
                ++i;
            }
        }

        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, wszName, 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);

        int nCost;
        gwszCost_007C0DF5[0].wChar = 0;
        sub_004B2AD0_GetTradeCostText(pItem, bService, &nCost, gwszCost_007C0DF5, 0x28);

        {
            UnicodeChar wszCost[10];
            char szCost[12];
            wsprintfA(szCost, gszFormatD_006D57BC, nCost);
            sub_00526F20_ToUnicode(wszCost, szCost, 9);
            sub_005267E0(gwszCost_007C0DF5, wszCost);
        }

        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD12), 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, gwszCost_007C0DF5, 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD10), 0xF, 0, 0, 1, sub_004B2E70_MenuBack, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD11), 0xF, 0, 0, 1, sub_004B2F00_MenuClose, 1);
}
