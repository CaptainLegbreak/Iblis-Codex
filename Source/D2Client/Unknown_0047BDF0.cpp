#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CelFileStrc;
struct Unicode;
struct D2BnetChatPacketStrc;
struct D2ClientNotifyStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* a, const char* b);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor); // 0x0049E3A0



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
extern int gnOptionArrowFrame; // 0x007BC944
extern int gnOptionMaxWidth; // 0x007BC95C
extern int gnOptionLastX; // 0x007BC980
extern int gnOptionLastY; // 0x007BC984

static const char* sub_0047BD60_GetAccountPart(const char* szName)
{
    const char* p = SStrChr(szName, 0x2A);
    if (p && *++p)
        return p;
    return szName;
}

// 0x0047BD80
static void sub_0047BD80_CopyCharPart(const char* szSource, char* szDest)
{
    if (*szSource != 0x2A)
    {
        const char* p = SStrChr(szSource, 0x2A);
        if (p)
        {
            memcpy(szDest, szSource, p - szSource);
            szDest[p - szSource] = 0;
            return;
        }
        SStrCopy(szDest, szSource, 0x7FFFFFFF);
        return;
    }
    SStrCopy(szDest, szSource, 0x7FFFFFFF);
}

// 0x0047BDF0
int __cdecl sub_0047BDF0_HandleBnetChatMessage()
{
    D2ClientNotifyStrc* pNotify = GAME_GetClientNotify();
    if (!pNotify)
        return 0;

    int nResult;
    D2BnetChatPacketStrc tPacket;
    if (!pNotify->pfnGetMessage(&nResult, &tPacket))
        return 0;

    if (nResult == 0)
    {
        Unicode wszLine[0x154];
        Unicode wszText[0x154];
        Unicode wszOut[0x154];
        const int nType = tPacket.nType;
        const char* szSender = tPacket.szName;
        const char* szText = szSender + strlen(szSender) + 1;
        if (sub_00611560_GetSquelchList()->IsNameSquelched(szSender))
            return 1;
        if (sub_00611560_GetSquelchList()->IsTextSquelched(szText))
            return 1;

        switch (nType)
        {
        case 4:
        case 6:
        case 10:
        {
            char szName[0x154];
            char szFormatted[0x154];
            sub_0047BD80_CopyCharPart(szSender, szName);
            if (szName[0] && (szName[0] != 0x2A || strcmp(sub_0047BD60_GetAccountPart(szName), sub_0047BD60_GetAccountPart(szSender))))
// build: symbol ?gszNameAccountFormat@* 0x006D72C0
                sprintf(szFormatted, gszNameAccountFormat, szName, sub_0047BD60_GetAccountPart(szSender));
            else
// build: symbol ?gszStringFormat@* 0x006FFC58
                sprintf(szFormatted, gszStringFormat, szName);
            sub_00526E40_Utf8ToUnicode(wszLine, szFormatted, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (nType == 10)
                sub_005269D0(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D5), wszLine, wszText);
            else
                sub_005269D0(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D4), wszLine, wszText);
            wszOut[0x153].wChar = 0;
            TEXT_PrintChatLine(wszOut, 2);
            break;
        }
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 9:
        case 21:
        case 22:
        case 23:
            break;
        default:
        {
            char szPrefix[20];
            strcpy(szPrefix, "<BattleNet>: ");
            sub_00526E40_Utf8ToUnicode(wszLine, szPrefix, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (sub_00526800(wszText) + sub_00526800(wszLine) >= 0x154)
            {
                const int nLength = sub_00526800(wszLine);
                if (nLength < 0x153)
                    wszText[0x153 - nLength].wChar = 0;
                else
                    wszText[0].wChar = 0;
            }
            sub_00526700(wszLine, wszText);
            wszLine[0x153].wChar = 0;
            TEXT_PrintChatLine(wszLine, 3);
            break;
        }
        }
    }
    return 1;
}

static int gnOptionSelected; // 0x007BC938

static D2OptionEntryStrc* gpOptionEntries; // 0x007BC940

static int gbOptionPressed; // 0x007BC948

static int gbOptionDragging; // 0x007BC94C

static inline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

static int sub_0047D520_FindOptionAtY(int nY) // 0x0047D520
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
            if (gpOptionEntries[nResult].nKind != -1 && sub_0047D500(&gpOptionEntries[nResult]))
            {
                return nResult;
            }

            nResult = -1;
        }
    }

    return nResult;
}

static void sub_0047D5B0_SelectOptionAtY(int nY) // 0x0047D5B0
{
    const int nIndex = sub_0047D520_FindOptionAtY(nY);
    if (nIndex != -1)
    {
        gnOptionSelected = nIndex;
    }
}

static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg) // 0x0047D5C0
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
            sub_004B9A00(2, 0, 0, 0, 0);
        }
        break;
    }
}

static void sub_0047D670_UpdateOptionSlider(int nX, int nY) // 0x0047D670
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

void __stdcall sub_0047D7F0_OptionMouseDown(SMSGHANDLER_PARAMS* pMsg) // 0x0047D7F0
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

void __stdcall sub_0047D840_OptionMouseUp(SMSGHANDLER_PARAMS* pMsg) // 0x0047D840
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

void __stdcall sub_0047DB80_OptionActivate(SMSGHANDLER_PARAMS* pMsg) // 0x0047DB80
{
    sub_0047D5C0_ActivateOption(pMsg);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047E3D0
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
        else
        {
            bEnabled = 0;
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
