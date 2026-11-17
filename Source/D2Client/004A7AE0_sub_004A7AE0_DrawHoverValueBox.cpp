struct Unicode
{
    unsigned short wChar;
};

struct D2TextCellStrc
{
    int nValue;

    D2TextCellStrc() : nValue(0) {}
};

struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short nNameStr;
    char unk0x08[0x1A0];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2HoverBoxStrc
{
    int nBoxX;
    int nBoxY;
    int nTitleX;
    int nTitleY;
    int nTextX;
    int nTextY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern unsigned char gnTextColor_007C02F8;                                                                  // 0x007C02F8
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2HoverBoxStrc gaHoverBoxes_006DA430[2];                                                       // 0x006DA430

void __cdecl sub_00499E30();                                                                                // 0x00499E30
int __cdecl sub_00466DC0();                                                                                 // 0x00466DC0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static void __stdcall sub_004A7AE0_DrawHoverValueBox(int nValueA, int nValueB, int nX, int nY);

// 0x004A7AE0
static __declspec(noinline) void __stdcall sub_004A7AE0_DrawHoverValueBox(int nValueA, int nValueB, int nX, int nY)
{
    D2TextCellStrc aText[0x40];
    sub_00499E30();

    int bHoverA = 0;
    int bHoverB = 0;
    if (nX >= gnGlobal_007A2858 + 0xA2 && nX <= gnGlobal_007A2858 + 0x140
        && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x14E && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x13B)
    {
        bHoverA = 1;
    }
    else if (nX >= gnGlobal_007A2858 + 0xA2 && nX <= gnGlobal_007A2858 + 0x140
        && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x134 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x121)
    {
        bHoverB = 1;
    }

    if (!nValueA)
    {
        bHoverA = 0;
    }
    if (!nValueB)
    {
        bHoverB = 0;
    }

    int nIndex;
    int nValue;
    if (bHoverA)
    {
        nIndex = 0;
        nValue = nValueA;
    }
    else if (bHoverB)
    {
        nIndex = 1;
        nValue = nValueB;
    }
    else
    {
        return;
    }

    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    sub_0046EFD0_DrawFramedBox(gaHoverBoxes_006DA430[nIndex].nBoxX + gnGlobal_007A2858, gaHoverBoxes_006DA430[nIndex].nBoxY + gnGlobal_007A285C + gnGlobal_00711470 - 480, 0x9B, 0x1E, gnTextColor_007C02F8, 2);
    const int nTitleY = gaHoverBoxes_006DA430[nIndex].nTitleY + gnGlobal_007A285C + gnGlobal_00711470 - 480;
    const int nTitleX = gaHoverBoxes_006DA430[nIndex].nTitleX + gnGlobal_007A2858;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x103F), nTitleX, nTitleY, 0, 0);

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(sub_00466DC0());
    D2_ASSERT(pMonStatsTxtRecord, 0xEC);

    sub_005269D0(0x80, (Unicode*)aText, D2LANG_GetStringFromTblIndex(0x2777), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->nNameStr), nValue);
    sub_00502320((Unicode*)aText, gaHoverBoxes_006DA430[nIndex].nTextX + gnGlobal_007A2858, gaHoverBoxes_006DA430[nIndex].nTextY + gnGlobal_007A285C + gnGlobal_00711470 - 480, 0, 0);
}

// build: context sub_004A7AE0_Shim
// calling-convention shim (not game code)
void __stdcall sub_004A7AE0_Shim(int nX, int nY, int nValueA, int nValueB)
{
    sub_004A7AE0_DrawHoverValueBox(nValueA, nValueB, nX, nY);
}
