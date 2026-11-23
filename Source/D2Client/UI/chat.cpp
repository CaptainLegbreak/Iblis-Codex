#include "D2Client.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2ClientFlagsLowStrc;

struct D2ClientFlagsStrc;

struct D2ClientFlagsLowStrc
{
    unsigned char bFlag0 : 1;
    unsigned char bNumberDisplay : 1;
    unsigned char bFlags2 : 6;
};

struct D2ClientFlagsStrc
{
    unsigned int bFlags0 : 8;
    unsigned int bClassOverride : 1;
    unsigned int bFlags9 : 23;
};

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(); // 0x006CC354

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC; // 0x00712EFC

extern D2ClientFlagsStrc gtClientFlags_00712EFC; // 0x00712EFC

int gnLanguageId;        // 0x007BB5DC

extern int gnChatHistoryCursor; // 0x007BB5D8

extern int gnChatCaret; // 0x007BB5E8

extern int gnChatDrawCount; // 0x007BB5EC

extern Unicode gwszChatLine_007BB638[]; // 0x007BB638

void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

bool __cdecl CHAT_IsImeLanguage(); // 0x0047B010

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern "C" int __stdcall ImmSimulateHotKey(int hWnd, unsigned long nHotKey); // 0x006B00E4

extern D2MsgHandlerEntryStrc gaChatHandlers[]; // 0x00712F4C

extern D2MsgHandlerEntryStrc gaChatInputHandlers[]; // 0x00712FA8

extern Unicode gwszImeResult[32]; // 0x007BB5F8

extern Unicode gwszImeComposition[32]; // 0x007BC850

Unicode gawszChatHistory[8][0x101]; // 0x007BB840

struct HKL__;

typedef T0046E1B0* HIMC;

struct CANDIDATELIST
{
    unsigned long dwSize;
    unsigned long dwStyle;
    unsigned long dwCount;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

extern "C" int __stdcall ImmReleaseContext(int hWnd, HIMC hImc); // 0x006B00B4

extern "C" int __stdcall ImmGetOpenStatus(HIMC hImc); // 0x006B00BA

extern "C" HIMC __stdcall ImmGetContext(int hWnd); // 0x006B00C6

extern "C" unsigned long __stdcall ImmGetCandidateListA(HIMC hImc, unsigned long dwIndex, CANDIDATELIST* pCandList, unsigned long dwBufLen); // 0x006B00CC

extern "C" unsigned long __stdcall ImmGetCandidateListCountA(HIMC hImc, unsigned long* pListCount); // 0x006B00D2

extern "C" int __stdcall ImmIsIME(HKL__* hKl); // 0x006B00D8

extern "C" int __stdcall ImmGetConversionStatus(HIMC hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE

extern "C" __declspec(dllimport) HKL__* __stdcall GetKeyboardLayout(unsigned long idThread); // 0x006CC4C0

unsigned char gbImeOpen;        // 0x007BB5E0

int gnImeState;        // 0x007BB5F0

static CANDIDATELIST* gpImeCandidateList; // 0x007BB5F4

unsigned char gbChatInputOpen; // 0x007BB5E1

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

// 0x0047A980
int __cdecl CHAT_IsNumberDisplayEnabled()
{
    return gtClientFlagsLow_00712EFC.bNumberDisplay;
}

// 0x0047A9A0
void __fastcall CHAT_SetClientFlags(int nFlags)
{
// build: symbol ?gdwClientFlags@* 0x00712EFC
    gdwClientFlags = nFlags;
}

// 0x0047AA30
int __cdecl CHAT_HasClassOverride()
{
    return gtClientFlags_00712EFC.bClassOverride;
}

// 0x0047AD60
static void CHAT_RefreshCandidates(HIMC hImc)
{
    unsigned long nListCount;
    unsigned long nSize = ImmGetCandidateListCountA(hImc, &nListCount);
    if (ImmGetCandidateListA(hImc, 0, 0, 0) && nSize)
    {
        if (gpImeCandidateList)
        {
            FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 235, 0);
        }

        gpImeCandidateList = (CANDIDATELIST*)FOG_Alloc(nSize, ".\\UI\\chat.cpp", 237, 0);
        ImmGetCandidateListA(hImc, 0, gpImeCandidateList, nSize);

        if (gpImeCandidateList->dwStyle == 2 && gpImeCandidateList->dwCount == 1)
        {
            FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 242, 0);
            gpImeCandidateList = 0;
        }
    }
}

// 0x0047AE00
void __stdcall CHAT_ImeNotifyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned long nSentence;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);

    HIMC hImc = ImmGetContext(WINDOW_GetWindow());
    if (!hImc)
    {
        return;
    }

    switch (pMsg->wParam)
    {
    case 8:
        switch (gnLanguageId)
        {
        case 6:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 3;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;

        case 8:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 5;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;

        case 9:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 4;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;
        }
        break;

    case 6:
    {
        unsigned long nConversion;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (gnLanguageId == 7 || gnLanguageId == 12)
        {
            if (nConversion & 1)
            {
                gnImeState = 1;
                gbImeOpen = 1;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
        }
        break;
    }

    case 5:
        if (gnLanguageId == 9)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId == 8)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 4:
        if (gnLanguageId == 9)
        {
            if (gpImeCandidateList)
            {
                FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 352, 0);
                gpImeCandidateList = 0;
            }
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId == 8)
        {
            if (gpImeCandidateList)
            {
                FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 363, 0);
                gpImeCandidateList = 0;
            }
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 3:
        if (gnLanguageId == 9)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 2:
        if (gnLanguageId == 9)
        {
            gnImeState = ImmIsIME(GetKeyboardLayout(0)) ? 0 : 4;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        break;
    }

    ImmReleaseContext(WINDOW_GetWindow(), hImc);
}

// 0x0047B010
bool __cdecl CHAT_IsImeLanguage()
{
    if (gnLanguageId == 9)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x404 || nLangId == 0xC04)
            return true;
        return false;
    }
    if (gnLanguageId == 8)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x804 || nLangId == 0x1004)
            return true;
        return false;
    }
    return ImmIsIME(GetKeyboardLayout(0));
}

// 0x0047B090
void __cdecl CHAT_InitChatIme()
{
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatHandlers, 4);
    gnLanguageId = STRTABLE_GetLanguage();
    if (gnLanguageId != 6 && gnLanguageId != 9 && gnLanguageId != 8 && gnLanguageId != 7 && gnLanguageId != 12)
        return;

    gbChatInputOpen = 0;
    if (!CHAT_IsImeLanguage())
        return;

    const unsigned short nLangId = GetSystemDefaultLangID();
    HIMC hImc = ImmGetContext(WINDOW_GetWindow());
    if (!hImc)
        return;

    gwszImeComposition[0].wChar = 0;
    gwszImeResult[0].wChar = 0;
    switch (gnLanguageId)
    {
    case 6:
        if (nLangId != 0x411)
            break;
        gbChatInputOpen = 1;
        COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        if (ImmSetOpenStatus(hImc, 1))
        {
            gbImeOpen = 1;
            gnImeState = 3;
        }
        else
        {
            gbImeOpen = 0;
            gnImeState = 0;
        }
        ImmReleaseContext(WINDOW_GetWindow(), hImc);
        return;

    case 7:
    case 12:
    {
        if (nLangId != 0x412 && nLangId != 0x812)
            break;
        ImmSetOpenStatus(hImc, 1);
        unsigned long nConversion, nSentence;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        ImmSetConversionStatus(hImc, 1, nSentence);
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (nConversion & 1)
        {
            gnImeState = 1;
            gbImeOpen = 1;
        }
        else
        {
            gnImeState = 0;
        }
        gbChatInputOpen = 1;
        COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;
    }

    case 9:
        gbImeOpen = 0;
        gbChatInputOpen = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(WINDOW_GetWindow(), 0x70);
        ImmSetOpenStatus(hImc, 1);
        gnImeState = 4;
        COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;

    case 8:
        gbImeOpen = 0;
        gbChatInputOpen = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(WINDOW_GetWindow(), 0x10);
        ImmSetOpenStatus(hImc, 1);
        gnImeState = 5;
        COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;
    }
    ImmReleaseContext(WINDOW_GetWindow(), hImc);
}


// 0x0047B2E0
void __cdecl CHAT_CloseChatInput()
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaChatHandlers, 4);
    if (gbChatInputOpen)
    {
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        T0046E1B0* hImc = ImmGetContext(WINDOW_GetWindow());
        if (hImc)
        {
            ImmSetOpenStatus(hImc, 0);
            if (gnLanguageId == 7 || gnLanguageId == 12)
            {
                unsigned long nConversion;
                unsigned long nSentence;
                ImmGetConversionStatus(hImc, &nConversion, &nSentence);
                ImmSetConversionStatus(hImc, 0, nSentence);
            }
            ImmReleaseContext(WINDOW_GetWindow(), hImc);
        }
        gwszImeResult[0].wChar = 0;
        gwszImeComposition[0].wChar = 0;
        if (gpChatBuffer_007BB5F4)
        {
            FOG_Free(gpChatBuffer_007BB5F4, ".\\UI\\chat.cpp", 0x29D, 0);
            gpChatBuffer_007BB5F4 = 0;
        }
    }
}

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

unsigned long gdwBlinkTick; // 0x007BC890

// 0x0047B450
static void sub_0047B450_DrawBlinkingCaret(int nY, int nColor, int nX)
{
// build: symbol ?gnBlinkOn@* 0x00713004
    if (gnBlinkOn == 1)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xD4C), nX + 0x83, nY, nColor, 0);
    }

    const unsigned long dwTick = GetTickCount();
// build: symbol ?gwBlinkDelay@* 0x00713000
    if (dwTick - gdwBlinkTick > gwBlinkDelay)
    {
        gdwBlinkTick = dwTick;
        if (gnBlinkOn)
        {
            gwBlinkDelay = 100;
            gnBlinkOn = 0;
        }
        else
        {
            gwBlinkDelay = 500;
            gnBlinkOn = 1;
        }
    }
}

// 0x0047B4E0
void __cdecl sub_0047B4E0()
{
}

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

extern int gnScreenWidth;                                                                               // 0x0071146C

// 0x0047B4F0
void __stdcall sub_0047B4F0_DrawImeText(int nX, int nY)
{
    int nWidth = 0;
    int nTextX = nX;
    int nTextY = nY;
    if (sub_00526800(gwszImeResult))
    {
        nWidth = D2Win_10121_GetTextWidth(gwszImeResult);
        if (nWidth + nTextX - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeResult, nTextX, nTextY, 4, 0);
    }

    const int nWidth2 = D2Win_10121_GetTextWidth(gwszImeComposition);
    if (sub_00526800(gwszImeComposition))
    {
        if (nWidth2 + nTextX + nWidth - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeComposition, nTextX + nWidth, nTextY, 4, 0);
    }

    sub_0047B450_DrawBlinkingCaret(nTextY, 4, nWidth2 + nTextX + nWidth - 0x83);
}

// 0x0047B9C0
void __cdecl CHAT_RecallChatLine()
{
    memcpy(gwszChatLine_007BB638, gawszChatHistory[gnChatHistoryCursor], sizeof(gawszChatHistory[0]));
    gnChatCaret = sub_00526800(gawszChatHistory[gnChatHistoryCursor]);
}

// 0x0047BD00
bool __fastcall CHAT_IsNarrowText(const Unicode* pText)
{
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength; i++)
    {
        if (pText[nLength].wChar > 0xFF)
            return false;
    }
    return true;
}

// 0x0047BDC0
void __cdecl CHAT_ClearChatLine()
{
    memset(gwszChatLine_007BB638, 0, 0x202);
    gnChatCaret = 0;
    gnChatDrawCount = 0;
}

#include "gen/data/Source/D2Client/UI/chat.inc"
