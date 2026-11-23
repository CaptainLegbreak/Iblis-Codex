#include "D2Client.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CelFileStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

int __cdecl sub_004DF880();



extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
D2CelFileStrc* __cdecl UI_GetPentspinCel(); // 0x00453AA0
int __cdecl UI_TickElapsed(); // 0x00454850
void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC); // 0x00502680
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall sub_0047E260_DrawOptionSlider(D2OptionEntryStrc* pEntry, int nY, int nColor, int bNoCel); // 0x0047E260
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern D2OptionHeaderStrc* gpOptionHeader; // 0x007BC93C
extern int gnOptionMaxWidth; // 0x007BC95C

// 0x0047CEE0
int __fastcall sub_0047CD80_IsSoundEnabled()
{
    return sub_004DF880();
}

int __fastcall sub_0047CD90_IsSoundEnabled()
{
    return sub_004DF880();
}

static int gnOptionSelected; // 0x007BC938

static D2OptionEntryStrc* gpOptionEntries; // 0x007BC940

int gnOptionArrowFrame; // 0x007BC944

static int gbOptionPressed; // 0x007BC948

static int gbOptionDragging; // 0x007BC94C

int gnOptionLastX; // 0x007BC980

int gnOptionLastY; // 0x007BC984

static inline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

static int sub_0047D520_FindOptionAtY(int nY)
{
    const int nCount = gpOptionHeader->nCount;
    const int nHalf = gpOptionHeader->nHeight * nCount / 2;
    const int nCenter = (gnScreenHeight - 0x50) / 2;
    int nResult = -1;

    if (nY > nCenter - nHalf && nY < nCenter + nHalf)
    {
        for (int i = 0; i < nCount; ++i)
        {
            if (gpOptionEntries[i].nY && nY >= gpOptionEntries[i].nY + nCount)
            {
                nResult = i;
            }
        }

        if (nResult >= 0)
        {
            if (gpOptionEntries[nResult].nKind == -1 || !sub_0047D500(&gpOptionEntries[nResult]))
            {
                nResult = -1;
            }
        }
    }

    return nResult;
}

// 0x0047D5B0
static void sub_0047D5B0_SelectOptionAtY(int nY)
{
    const int nIndex = sub_0047D520_FindOptionAtY(nY);
    if (nIndex != -1)
    {
        gnOptionSelected = nIndex;
    }
}

// build: context sub_0047D5C0_ActivateOption
static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        return;
    }

    switch (gpOptionEntries[gnOptionSelected].nKind)
    {
    case 1:
        gpOptionEntries[gnOptionSelected].nValue++;
        if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
        {
            gpOptionEntries[gnOptionSelected].nValue = 0;
        }
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], pMsg);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
        break;

    case 0:
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], pMsg);
        }
        sub_004B9A00(2, 0, 0, 0, 0);
        break;
    }
}

// 0x0047D670
static void sub_0047D670_UpdateOptionSlider(int nX, int nY)
{
    if (!gbOptionDragging && sub_0047D520_FindOptionAtY(nY) != gnOptionSelected)
    {
        return;
    }

    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 2:
        {
            const int nHalfWidth = gnScreenWidth / 2;
            int nLeft = nHalfWidth - 0x3B;
            int nBar = nHalfWidth - 0x3C;
            if (!gpOptionEntries[gnOptionSelected].pCel)
            {
                nLeft = nHalfWidth - 0x90;
                nBar = nHalfWidth - 0x91;
            }

            if (gbOptionDragging || nX > nLeft && nX < nLeft + 0x121)
            {
                const int nStart = nBar + 0xC;
                if (nX < nStart)
                {
                    gpOptionEntries[gnOptionSelected].nValue = 0;
                }
                else if (nX > nStart + 0x109)
                {
                    gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
                }
                else
                {
                    gpOptionEntries[gnOptionSelected].nValue = (int)((nX - nStart) / (float)(265.0 / (float)(gpOptionEntries[gnOptionSelected].nValues - 1) * 0.5) + 1.0) / 2;
                }
                gbOptionDragging = 1;
            }
            break;
        }
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

// 0x0047D7F0
void __stdcall sub_0047D7F0_OptionMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_0047D5B0_SelectOptionAtY(nY);
    sub_0047D670_UpdateOptionSlider(nX, nY);
    gbOptionPressed = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D840
void __stdcall sub_0047D840_OptionMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    if (gbOptionPressed && sub_0047D520_FindOptionAtY(nY) == gnOptionSelected)
    {
        sub_0047D5C0_ActivateOption(pMsg);
    }
    GAME_ResetMouseState();
    gbOptionPressed = 0;
    gbOptionDragging = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047DB80
void __stdcall sub_0047DB80_OptionActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047D5C0_ActivateOption(pMsg);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __cdecl sub_0047E3D0_DrawOptions()
{
    D2_ASSERT(gpOptionHeader, 0x64B);
    D2_ASSERT(gpOptionEntries, 0x64C);

    const int nX = sub_00468730();
    const int nY = sub_00468740();
    const int nTop = (gnScreenHeight - 0x50) / 2 - gpOptionHeader->nHeight * gpOptionHeader->nCount / 2;

    if (gnOptionLastY != nY || gnOptionLastX != nX)
    {
        gnOptionLastY = nY;
        gnOptionLastX = nX;
        if (gbOptionPressed)
        {
            sub_0047D670_UpdateOptionSlider(nX, nY);
        }
        else
        {
            sub_0047D5B0_SelectOptionAtY(nY);
        }
    }

    int bEnabled;
    int nRow = 0;
    for (int i = 0; i < gpOptionHeader->nCount; ++i)
    {
        bEnabled = 0;
        gpOptionEntries[i].nY = 0;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (gpOptionEntries[i].bExpansionOnly && !FOG_IsExpansion())
        {
            continue;
        }

        if (!gpOptionEntries[i].pfnEnabled || gpOptionEntries[i].pfnEnabled())
        {
            bEnabled = 1;
        }

        const int nColor = bEnabled ? 5 : 1;
        if (gpOptionEntries[i].pfnInit)
        {
            gpOptionEntries[i].pfnInit(&gpOptionEntries[i], 0);
        }

        const int nEntryY = gpOptionHeader->nHeight * nRow + nTop;
        const int nDrawY = gpOptionHeader->nTextOffset + nEntryY;
        gpOptionEntries[i].nY = nEntryY;
        switch (gpOptionEntries[i].nKind)
        {
        case -1:
        case 0:
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2, nDrawY, 1, nColor, -1);
            break;

        case 1:
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2 - 0xE6, nDrawY, 0, nColor, -1);
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pValueCels[gpOptionEntries[i].nValue], gnScreenWidth / 2 + 0xE6, nDrawY, 2, nColor, -1);
            break;

        case 2:
            if (gpOptionEntries[i].pCel)
            {
                D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2 - 0xE6, nDrawY, 0, nColor, -1);
            }
            sub_0047E260_DrawOptionSlider(&gpOptionEntries[i], nEntryY, nColor, gpOptionEntries[i].pCel == 0);
            break;
        }
        ++nRow;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = UI_GetPentspinCel();
    if (gnOptionArrowFrame)
    {
        tContext.nFrame = 8 - gnOptionArrowFrame;
    }
    else
    {
        tContext.nFrame = 0;
    }

    const int nArrowY = gpOptionEntries[gnOptionSelected].nY + gpOptionHeader->nArrowOffset;
    sub_004F6480(&tContext, gnScreenWidth / 2 - gnOptionMaxWidth - 0xF9, nArrowY, -1, 5, 0);
    tContext.nFrame = gnOptionArrowFrame;
    sub_004F6480(&tContext, gnScreenWidth / 2 + 0xF9, nArrowY, -1, 5, 0);
    if (UI_TickElapsed())
    {
        gnOptionArrowFrame = (gnOptionArrowFrame + 1) % 8;
    }
}
