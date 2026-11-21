#include "D2Unicode.h"
#include "D2Client.h"
struct D2SelectionRectStrc;
struct T0044CB60
{
    Unicode* wszText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)
struct D2TextScrollStrc
{
    T0044CB60* pLines;
    int nLines;
    unsigned int nPos;
    int nSpeed;
    char unk0x10[6];
    int nState;
    unsigned int dwLastTime;
    unsigned int dwStartTime;
    unsigned int dwStep;
    unsigned int dwAccum;
    unsigned short wFrames;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);                                // 0x006CC544

void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect);                                               // 0x00452E50
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
void __fastcall sub_00501DF0_DrawClippedFontText(const Unicode* pText, int nX, int nY, int nTextColor, int nSkipLines, int nDrawLines); // 0x00501DF0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

extern int gnGlobal_007225FC;                                                                               // 0x007225FC
extern unsigned long gnGlobal_007BF1F6;                                                                     // 0x007BF1F6
extern int gnGlobal_007BF1FA;                                                                               // 0x007BF1FA
extern int gbTextSide_007BF236;                                                                             // 0x007BF236
extern int gnGlobal_007BF264;                                                                               // 0x007BF264
extern int gnGlobal_007BF278;                                                                               // 0x007BF278

// 0x0049D590
unsigned int __fastcall sub_0049D590_CalcTextOffset(unsigned int nValue)
{
    return 0x70 - (nValue >> 10);
}

// build: context sub_0049D5A0_DrawClippedLine
static __forceinline void sub_0049D5A0_DrawClippedLine(T0044CB60* pLine, int nY, int nColor, int nSkipLines, int nDrawLines)
{
    if (gnGlobal_007BF1F6 || gnGlobal_007BF1FA)
    {
        sub_00501DF0_DrawClippedFontText(pLine->wszText, gnGlobal_007BF278 + 0x10, gnGlobal_007225FC + nY, nColor, nSkipLines, nDrawLines);
    }
}

static int sub_0049D5A0_UpdateScrollText(D2TextScrollStrc* pRec);
static int sub_0049D5A0_UpdateScrollText(D2TextScrollStrc* pRec); // 0x0049D5A0

// 0x0049D5A0
static int sub_0049D5A0_UpdateScrollText(D2TextScrollStrc* pRec)
{
    D2_ASSERT(pRec, 1805);

    int nOldFont = sub_00502EF0(8);

    unsigned int dwNow = timeGetTime();
    if (!pRec->dwStartTime)
    {
        pRec->dwLastTime = dwNow;
        pRec->dwStartTime = dwNow;
    }
    else
    {
        unsigned int nElapsed = (dwNow - pRec->dwStartTime) >> 2;
        unsigned int nExtra = 0;
        if (pRec->dwLastTime == dwNow)
        {
            if (!pRec->dwStep)
            {
                ++pRec->wFrames;
            }
            else
            {
                pRec->dwAccum += pRec->dwStep;
                nExtra = pRec->dwAccum;
            }
        }
        else
        {
            pRec->dwAccum = 0;
            if (!pRec->dwStep && pRec->wFrames)
            {
                pRec->dwStep = (dwNow - pRec->dwLastTime) / pRec->wFrames;
            }
            pRec->dwLastTime = dwNow;
        }
        pRec->nPos = (nExtra + nElapsed) * pRec->nSpeed;
    }

    if (!gbTextSide_007BF236 && (gnGlobal_007BF1F6 || gnGlobal_007BF1FA))
    {
        sub_0046EFD0_DrawFramedBox(gnGlobal_007BF278, gnGlobal_007225FC - 5, 0x145, 0x7A, 0, 1);
        D2RectStrc tRect;
        tRect.nLeft = gnGlobal_007BF278 - 1;
        tRect.nTop = gnGlobal_007225FC - 6;
        tRect.nRight = gnGlobal_007BF278 + 0x146;
        tRect.nBottom = gnGlobal_007225FC + 0x75;
        sub_00452E50_DrawRectangleBorder(&tRect);
    }

    T0044CB60* pLine = pRec->pLines;
    T0044CB60* pLast = 0;
    unsigned int nFirstPos = 0;
    unsigned int nLastPos = 0;
    unsigned int nPos = pRec->nPos;
    T0044CB60* pFirst = 0;
    if (nPos && pLine)
    {
        do
        {
            if (nPos < 0x17800)
            {
                int nY = sub_0049D590_CalcTextOffset(nPos);
                if (gnGlobal_007BF1F6 || gnGlobal_007BF1FA)
                {
                    sub_00502320(pLine->wszText, gnGlobal_007BF278 + 0x10, gnGlobal_007225FC + nY, 0, 0);
                }

                if (!pFirst)
                {
                    pFirst = pLine;
                    nFirstPos = nPos;
                }
                nLastPos = nPos;
                pLast = pLine;
            }

            if (nPos < 0x4800)
            {
                break;
            }

            pLine = pLine->pNext;
            nPos -= 0x4800;
        }
        while (pLine);

        if (pFirst)
        {
            T0044CB60* pPrev = 0;
            T0044CB60* pNode = pRec->pLines;
            while (pNode != pFirst)
            {
                pPrev = pNode;
                pNode = pNode->pNext;
            }

            if (pPrev)
            {
                int nY = sub_0049D590_CalcTextOffset(nFirstPos) - 0x12;
                int nLines = nY < 0x12 ? nY : 0x12;

                sub_0049D5A0_DrawClippedLine(pPrev, nY, 3, 0, nLines);
            }
        }

        T0044CB60* pNext;
        if (pLast && (pNext = pLast->pNext) != 0)
        {
            int nY = sub_0049D590_CalcTextOffset(nLastPos + 0x400);
            int nSkip = nY - 0x5E;
            int nHeight = D2Win_10125();
            if (nSkip < nHeight)
            {

                const int nOldSkip = nSkip;
                nSkip = nHeight - nSkip;
                sub_0049D5A0_DrawClippedLine(pNext, nY + 0x13, 0, nOldSkip, nSkip);
            }
        }
    }

    if (!pFirst && !pLast)
    {
        T0044CB60* pTail = pRec->pLines;
        unsigned int nTailPos = pRec->nPos;
        while (pTail->pNext)
        {
            pTail = pTail->pNext;
            nTailPos -= 0x4800;
        }

        if (nTailPos < 0x1C000)
        {
            int nY = sub_0049D590_CalcTextOffset(nTailPos + 0x400);
            int nLines = nY < 0x12 ? nY : 0x12;
            if (nLines)
            {
                sub_0049D5A0_DrawClippedLine(pTail, nY, 3, 0, nLines);
            }
        }
    }

    sub_00502EF0(nOldFont);

    int nRows = pRec->nLines - 1;
    if (nRows <= 0)
    {
        nRows = 1;
    }

    if ((pRec->nPos >> 10) > (unsigned int)(nRows * 18 + 0x70))
    {
        if (gnGlobal_007BF264 == 1)
        {
            gnGlobal_007BF264 = 0;
        }
        return 1;
    }

    return 0;
}

#pragma pack(push, 1)
typedef int(__fastcall* PANELCLOSEFN)(void* pArg, int a2, int a3);
#pragma pack(pop)

extern D2TextScrollStrc* gpTextBox_007BF0A4; // 0x007BF0A4
extern int gnPanelOpen_007BF1BC; // 0x007BF1BC
extern int gnPending_007BF1C4; // 0x007BF1C4
extern void* gpHint_007BF202; // 0x007BF202
extern int gbHintActive_007BF20A; // 0x007BF20A
extern void* gpHint_007BF24B; // 0x007BF24B
extern PANELCLOSEFN gpfnClose_007BF258; // 0x007BF258
extern void* gpCloseArg_007BF25C; // 0x007BF25C
extern int gbHandlers_007BF27C; // 0x007BF27C
extern char gHandlerTable_00722600[]; // 0x00722600

int __cdecl sub_00514CC0(); // 0x00514CC0
int __fastcall sub_004B95C0_IsHintPlaying(void* pHint); // 0x004B95C0
void __stdcall sub_0049D410_FreeTextBox(D2TextScrollStrc* pTextBox); // 0x0049D410
void __fastcall sub_00467430_SetSelectionRect(const D2SelectionRectStrc* pRect); // 0x00467430
void __cdecl sub_0049F960_ResetTextBox(); // 0x0049F960
void __fastcall sub_004B3D10_CancelAndFlag(void* pHint); // 0x004B3D10
void __cdecl sub_00453AE0(); // 0x00453AE0
void* __stdcall sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, void* pTable, int nCount); // 0x00451E10

// 0x004A0770
static int __stdcall sub_004A0770(int bIgnore, D2TextScrollStrc* pTextBox)
{
    if (bIgnore)
    {
        pTextBox->nState = 2;
        return 0;
    }

    const int bBusy = sub_00514CC0();
    if (!gpHint_007BF24B || sub_004B95C0_IsHintPlaying(gpHint_007BF24B) || !bBusy)
    {
        gpHint_007BF24B = 0;
        if (sub_0049D5A0_UpdateScrollText(pTextBox))
        {
            gnPanelOpen_007BF1BC = 1;
            if (!gbHintActive_007BF20A && gpTextBox_007BF0A4)
            {
                sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
                gpTextBox_007BF0A4 = 0;
                sub_00467430_SetSelectionRect(0);
            }

            sub_0049F960_ResetTextBox();
            if (gpfnClose_007BF258)
            {
                return gpfnClose_007BF258(gpCloseArg_007BF25C, 0, 0);
            }

            if (gnPending_007BF1C4 == 1)
            {
                gnPending_007BF1C4 = 0;
            }
            else if (gbHintActive_007BF20A)
            {
                sub_004B3D10_CancelAndFlag(gpHint_007BF202);
            }

            sub_00453AE0();
            gbHintActive_007BF20A = 0;
            sub_00467430_SetSelectionRect(0);
            if (gbHandlers_007BF27C == 1)
            {
                gbHandlers_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gHandlerTable_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

// build: context sub_004A0770_Shim
// calling-convention shim (not game code)
int __stdcall sub_004A0770_Shim()
{
    D2TextScrollStrc* pTextBox = gpTextBox_007BF0A4;
    if (pTextBox && (pTextBox->nState == 1 || pTextBox->nState == 0))
    {
        return sub_004A0770(gnPanelOpen_007BF1BC, pTextBox);
    }

    return 0;
}
