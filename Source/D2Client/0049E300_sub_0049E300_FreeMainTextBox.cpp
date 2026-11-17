struct D2HoverTextStrc;
struct D2ClientDialogStrc;
struct D2MsgHandlerEntryStrc;

struct Unicode
{
    unsigned short wChar;
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)
struct T00479230
{
    T0044CB60* pFirst;
    int nLines;
    int nTextTop;
    int nTextBottom;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned short f_14;
    int nScroll;
    int nField1A;
    int nField1E;
    int nField22;
    int nField26;
    unsigned short nField2A;
};
#pragma pack(pop)

struct D2UnitStrc
{
    char unk0x00[0xA4];
    D2HoverTextStrc* pHoverText;
};

class D2ListBoxViewStrc
{
public:
    virtual ~D2ListBoxViewStrc();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __fastcall sub_00467430(void* pRect);                                                                  // 0x00467430
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
void __stdcall sub_0049D4D0_FreeTextList(void* pList);                                                      // 0x0049D4D0
void __cdecl sub_0049FE10();                                                                                // 0x0049FE10
T0044CB60* __stdcall sub_004A0320_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_004B9610_FindHint(int nId);                                                              // 0x004B9610
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);      // 0x00502970
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
T00479230* __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg);                              // 0x00661200
void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed);                               // 0x00661210
void __stdcall sub_006612A0(int nHandle);                                                                   // 0x006612A0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[];                                                  // 0x00722600
T00479230* gpTextBox_007BF0A4;                                                                          // 0x007BF0A4
T00479230* gpTextBox_007BF1A8;                                                                          // 0x007BF1A8
extern unsigned int gdwTextEndTick_007BF1AC;                                                                // 0x007BF1AC
extern D2ClientDialogStrc* gpListDialog_007BF1B0;                                                           // 0x007BF1B0
extern D2ListBoxViewStrc* gpListBox_007BF1B4;                                                                   // 0x007BF1B4
extern int gnGlobal_007BF1C4;                                                                               // 0x007BF1C4
extern int gnGlobal_007BF1C8;                                                                               // 0x007BF1C8
int gnTextBoxX_007BF1D0;                                                                                    // 0x007BF1D0
int gnTextBoxY_007BF1D4;                                                                                    // 0x007BF1D4
extern char gtTextList_007BF1E4[];                                                                          // 0x007BF1E4
extern char gtTextList_007BF1EA[];                                                                          // 0x007BF1EA
extern char gtTextList_007BF1F0[];                                                                          // 0x007BF1F0
extern unsigned short gwTextStringId_007BF212;                                                              // 0x007BF212
int gbTextSound_007BF230;                                                                                   // 0x007BF230
extern int gnHintSound_007BF24B;                                                                            // 0x007BF24B
extern int gdwGlobal_007BF250;                                                                              // 0x007BF250
extern int gnHintId_007BF260;                                                                               // 0x007BF260
extern int gbStarted_007BF27C;                                                                              // 0x007BF27C

static void sub_0049D370_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0x60F, 0);
        FOG_Free(pLine, ".\\UI\\text.cpp", 0x610, 0);
        pLine = pNext;
    }
}

static void sub_0049D3C0_MeasureTextBox(T00479230* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (T0044CB60* pLine = pBox->pFirst; pLine; pLine = pLine->pNext)
    {
        nMaxWidth = nMaxWidth > sub_00501820(pLine->pText) ? nMaxWidth : sub_00501820(pLine->pText);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        sub_0049D370_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

// 0x0049E300
void __cdecl sub_0049E300_FreeMainTextBox()
{
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        gpTextBox_007BF1A8 = 0;
    }
}

// 0x0049F3D0
void __fastcall sub_0049F3D0_FreeHoverText(D2HoverTextStrc* pHoverText)
{
    T00479230* pTextBox = CHAT_GetUsedFromHoverMsg(pHoverText);
    if (pTextBox)
    {
        sub_0049D410_FreeTextBox(pTextBox);
        CHAT_SetUsedInHoverMsg(pHoverText, 0);
    }
    CHAT_FreeHoverMsg(0, pHoverText);
}

// 0x0049F960
void __cdecl sub_0049F960_ResetTextBox()
{
    sub_00467430(0);
    if (gpTextBox_007BF0A4)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
        gpTextBox_007BF0A4 = 0;
    }
    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId_007BF260 = 0;
    }
    gnHintSound_007BF24B = 0;
    if (gbStarted_007BF27C == 1)
    {
        gbStarted_007BF27C = 0;
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
    }
    if (gbTextSound_007BF230)
    {
        sub_004786A0_SendIntInt(0x31, -1, gwTextStringId_007BF212);
        gbTextSound_007BF230 = 0;
    }
}

// 0x004A05E0
T00479230* __fastcall sub_004A05E0_CreateTextBox(const Unicode* wszText, int nMode)
{
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), ".\\UI\\text.cpp", 0x65D, 0);
    if (nMode == 3)
    {
        pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
        sub_0049D3C0_MeasureTextBox(pTextBox);
        return pTextBox;
    }

    const int nOldFont = sub_00502EF0(8);
    pTextBox->pFirst = sub_004A0320_BuildTextLines(wszText, &pTextBox->nLines, &pTextBox->f_14);
    pTextBox->nWidth = 0x145;
    pTextBox->nHeight = 0x70;
    pTextBox->nField1A = 0;
    pTextBox->nField1E = 0;
    pTextBox->nField22 = 0;
    pTextBox->nField26 = 0;
    pTextBox->nField2A = 0;
    sub_00502EF0(nOldFont);
    sub_0049D3C0_MeasureTextBox(pTextBox);
    return pTextBox;
}

// 0x004A0680
void __cdecl sub_004A0680_FreeTextResources()
{
    if (gdwGlobal_007BF250)
    {
        sub_006612A0(gdwGlobal_007BF250);
        gdwGlobal_007BF250 = 0;
    }
    if (gpTextBox_007BF0A4)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
        gpTextBox_007BF0A4 = 0;
    }
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        FOG_Free(gpTextBox_007BF1A8, ".\\UI\\text.cpp", 0x6E4, 0);
        gpTextBox_007BF1A8 = 0;
    }
    if (gpListDialog_007BF1B0)
    {
        sub_004B8020(gpListDialog_007BF1B0);
        gpListDialog_007BF1B0 = 0;
    }
    if (gpListBox_007BF1B4)
    {
        delete gpListBox_007BF1B4;
        gpListBox_007BF1B4 = 0;
    }
    sub_0049FE10();
    sub_00467430(0);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1E4);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1EA);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1F0);
    gnHintSound_007BF24B = 0;
}

// 0x004A1510
void __fastcall sub_004A1510_ShowTextBox(unsigned short nStringId)
{
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        gpTextBox_007BF1A8 = 0;
    }

    const Unicode* wszText = D2LANG_GetStringFromTblIndex(nStringId);
    const int nOldFont = sub_00502EF0(0x0D);
    gpTextBox_007BF1A8 = sub_004A05E0_CreateTextBox(wszText, 3);
    sub_00502EF0(nOldFont);
    if (gpTextBox_007BF1A8)
    {
        gpTextBox_007BF1A8->nScroll = 1;
        gdwTextEndTick_007BF1AC = GetTickCount() + (sub_00526800(wszText) + 0x19) * 0xC8;
        gnGlobal_007BF1C8 = 1;
        gnGlobal_007BF1C4 = 1;
        gnTextBoxY_007BF1D4 = 0x64 - (gpTextBox_007BF1A8->nHeight >> 2);
        gnTextBoxX_007BF1D0 = 0x140 - (gpTextBox_007BF1A8->nWidth >> 1);
    }
}
