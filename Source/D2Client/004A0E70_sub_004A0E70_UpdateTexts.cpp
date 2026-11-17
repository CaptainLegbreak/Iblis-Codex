extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ViewStrc;
struct D2MsgHandlerEntryStrc;
struct D2ClientDialogStrc;
struct T0044CB60;

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
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

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
};

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);
typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);

void __fastcall sub_00451E10_UnregisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);  // 0x00451E10
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_00464950(UNITFN pfnCallback);                                                           // 0x00464950
void __fastcall sub_00464990(UNITFN pfnCallback);                                                           // 0x00464990
void __fastcall sub_004649D0(UNITFN pfnCallback);                                                           // 0x004649D0
void __fastcall sub_00467430(int nArg);                                                                     // 0x00467430
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY);                        // 0x0049D8E0
void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox);                                           // 0x0049D410
static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(T00479230* pTextBox);
void __cdecl sub_0049DC40_DrawTextList();                                                                   // 0x0049DC40
void __cdecl sub_0049DEE0_DrawOverheadTextList();                                                           // 0x0049DEE0
void __cdecl sub_0049E300_FreeMainTextBox();                                                                // 0x0049E300
void __cdecl sub_0049F960_ResetTextBox();                                                                   // 0x0049F960
void __cdecl sub_004A0880_CloseTextUnit();                                                                  // 0x004A0880
void __fastcall sub_004A0B30_DrawUnitHoverText(D2UnitStrc* pUnit);                                         // 0x004A0B30
void __fastcall sub_004A0D20_DrawObjectHoverText(D2UnitStrc* pUnit);                                       // 0x004A0D20
void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId);                                        // 0x004B3830
void __fastcall sub_004B3D10_ReleaseTextUnit(int nUnitId);                                                  // 0x004B3D10
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog);                                       // 0x004B8100
int __fastcall sub_004B95C0_IsHintPlaying(void* pHint);                                                    // 0x004B95C0
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __cdecl sub_00514CC0();                                                                                 // 0x00514CC0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_007225FC;                                                                               // 0x007225FC
extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[];                                                  // 0x00722600
extern T00479230* gpTextBox_007BF0A4;                                                                   // 0x007BF0A4
D2RectStrc gaHoverRects_007BF0A8[16];                                                                       // 0x007BF0A8
extern T00479230* gpTextBox_007BF1A8;                                                                   // 0x007BF1A8
unsigned long gdwTextEndTick_007BF1AC;                                                                      // 0x007BF1AC
extern D2ClientDialogStrc* gpListDialog_007BF1B0;                                                           // 0x007BF1B0
int gnGlobal_007BF1BC;                                                                                      // 0x007BF1BC
int gnGlobal_007BF1C0;                                                                                      // 0x007BF1C0
extern int gnGlobal_007BF1C4;                                                                               // 0x007BF1C4
extern int gnGlobal_007BF1C8;                                                                               // 0x007BF1C8
extern D2RectStrc gtTextRect_007BF1D0;                                                                      // 0x007BF1D0
extern int gnGlobal_007BF1FA;                                                                               // 0x007BF1FA
extern int gdwGlobal_007BF202;                                                                              // 0x007BF202
extern int gdwGlobal_007BF20A;                                                                              // 0x007BF20A
extern int gnGameFrame_007BF20E;                                                                            // 0x007BF20E
D2RectStrc gtHoverOffset_007BF214;                                                                          // 0x007BF214
int gnHoverRectCount_007BF224;                                                                              // 0x007BF224
extern int gnHintSound_007BF24B;                                                                            // 0x007BF24B
extern D2TextCallback gpfnTextCallback_007BF258;                                                            // 0x007BF258
extern void* gpTextCallbackContext_007BF25C;                                                                // 0x007BF25C
extern int gnGlobal_007BF278;                                                                               // 0x007BF278
int gbStarted_007BF27C;                                                                                     // 0x007BF27C

static int __stdcall sub_004A0770(T00479230* pTextBox, int bIgnore);                                        // 0x004A0770
static int sub_0049D9A0_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect);                          // 0x0049D9A0

// build: context sub_0049D5A0_UpdateTextBox
// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(T00479230* pTextBox)
{
    int nA = sub_004F59A0();
    int nB = sub_004F59A0();
    sub_00467430(nA);
    sub_00467430(nB);
    sub_00467430(nA);
    sub_00467430(nB);
    pTextBox->nScroll = 1;
    return *(char*)pTextBox;
}

static __declspec(noinline) int __stdcall sub_004A0770(T00479230* pTextBox, int bIgnore)
{
    if (bIgnore)
    {
        pTextBox->nScroll = 2;
        return 0;
    }

    const int bBusy = sub_00514CC0();
    if (!gnHintSound_007BF24B || sub_004B95C0_IsHintPlaying((void*)gnHintSound_007BF24B) || !bBusy)
    {
        gnHintSound_007BF24B = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gnGlobal_007BF1BC = 1;
            if (!gdwGlobal_007BF20A && gpTextBox_007BF0A4)
            {
                sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
                gpTextBox_007BF0A4 = 0;
                sub_00467430(0);
            }

            sub_0049F960_ResetTextBox();
            if (gpfnTextCallback_007BF258)
            {
                return gpfnTextCallback_007BF258(gpTextCallbackContext_007BF25C, 0, 0);
            }

            if (gnGlobal_007BF1C4 == 1)
            {
                gnGlobal_007BF1C4 = 0;
            }
            else if (gdwGlobal_007BF20A)
            {
                sub_004B3D10_ReleaseTextUnit(gdwGlobal_007BF202);
            }

            sub_00453AE0();
            gdwGlobal_007BF20A = 0;
            sub_00467430(0);
            if (gbStarted_007BF27C == 1)
            {
                gbStarted_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int sub_0049D9A0_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnGlobal_0071146C / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnGlobal_0071146C / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    sub_0049D8E0_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

// 0x004A0E70
void __fastcall sub_004A0E70_UpdateTexts(D2ViewStrc* pView)
{
    D2RectStrc tViewRect;
    D2CoordStrc tViewPos;

    ++gnGameFrame_007BF20E;
    int nResult = 0;
    sub_00476070_GetViewRect(pView, &tViewRect.nLeft, &tViewRect.nTop, &tViewRect.nRight, &tViewRect.nBottom);
    sub_004760C0_GetViewOffset(pView, &tViewPos.nX, &tViewPos.nY);
    SetRect(&gtHoverOffset_007BF214, tViewPos.nX, tViewPos.nY, tViewPos.nX + tViewRect.nRight - tViewRect.nLeft, tViewPos.nY + tViewRect.nBottom - tViewRect.nTop);

    if (gnGlobal_007BF1C0 == 1)
    {
        gaHoverRects_007BF0A8[0].nLeft = gnGlobal_007BF278;
        gaHoverRects_007BF0A8[0].nRight = gnGlobal_007BF278 + 0x145;
        gaHoverRects_007BF0A8[0].nTop = gnGlobal_007225FC;
        gnHoverRectCount_007BF224 = 1;
        gaHoverRects_007BF0A8[0].nBottom = gnGlobal_007225FC + 0x70;
    }
    else
    {
        gnHoverRectCount_007BF224 = 0;
    }

    sub_00464950(sub_004A0B30_DrawUnitHoverText);
    sub_00464990(sub_004A0D20_DrawObjectHoverText);
    sub_004649D0(sub_004A0D20_DrawObjectHoverText);

    if (gnGlobal_007BF1C0 == 1 && gpTextBox_007BF0A4 && (gpTextBox_007BF0A4->nScroll == 1 || !gpTextBox_007BF0A4->nScroll))
    {
        nResult = sub_004A0770(gpTextBox_007BF0A4, gnGlobal_007BF1BC);

        D2UnitStrc* pUnit = 0;
        if (gdwGlobal_007BF20A)
        {
            pUnit = sub_00463990(gdwGlobal_007BF202, 1);
        }

        if (sub_00463DF0() || (gdwGlobal_007BF20A && pUnit && pUnit->dwAnimMode == 0x0C))
        {
            if (gdwGlobal_007BF20A)
            {
                sub_004786A0_SendIntInt(0x30, 1, gdwGlobal_007BF202);
                sub_004B3830_ClearNpcInventoryAndSound(gdwGlobal_007BF202);
            }

            sub_004A0880_CloseTextUnit();
            if (gbStarted_007BF27C == 1)
            {
                gbStarted_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
            }
        }
    }

    if (gnGlobal_007BF1C4)
    {
        gnGlobal_007BF1C8 ? (void)0 : (sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xD02), exit(-1));
        int nDrawn = 1;
        (gdwTextEndTick_007BF1AC < GetTickCount()) ? (void)(nDrawn = 0) : (void)sub_0049D9A0_DrawTextBoxAt(gpTextBox_007BF1A8, &gtTextRect_007BF1D0);
        if (!nDrawn)
        {
            sub_0049E300_FreeMainTextBox();
            gnGlobal_007BF1C4 = 0;
            gdwGlobal_007BF20A = 0;
        }
        nResult += nDrawn;
    }

    if (!nResult && gnGlobal_007BF1C0 == 1)
    {
        gnGlobal_007BF1FA = 0;
        gdwGlobal_007BF20A = 0;
        gnGlobal_007BF1BC = 1;
        gnGlobal_007BF1C0 = 0;
        if (gbStarted_007BF27C == 1)
        {
            gbStarted_007BF27C = 0;
            sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
        }
    }

    gnGlobal_007BF1BC = 0;
    if (!sub_004538D0(0x18))
    {
        sub_0049DC40_DrawTextList();
        sub_0049DEE0_DrawOverheadTextList();
    }

    if (gpListDialog_007BF1B0)
    {
        sub_004B8100_DrawDialog(gpListDialog_007BF1B0);
    }
}
