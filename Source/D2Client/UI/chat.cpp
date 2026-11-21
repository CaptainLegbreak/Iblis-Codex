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

int gnLanguageId_007BB5DC;        // 0x007BB5DC

extern int gnChatIndex_007BB5D8; // 0x007BB5D8

extern int gnChatCaret_007BB5E8; // 0x007BB5E8

extern int gdwGlobal_007BB5EC; // 0x007BB5EC

extern Unicode gwszChatLine_007BB638[]; // 0x007BB638

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

bool __cdecl sub_0047B010_IsImeLanguage(); // 0x0047B010

int __cdecl sub_004F59A0(); // 0x004F59A0

extern "C" int __stdcall ImmSimulateHotKey(int hWnd, unsigned long nHotKey); // 0x006B00E4

extern D2MsgHandlerEntryStrc gtChatHandlers_00712F4C[]; // 0x00712F4C

extern D2MsgHandlerEntryStrc gtChatInputHandlers_00712FA8[]; // 0x00712FA8

extern unsigned short gwChatText_007BB5F8; // 0x007BB5F8

extern unsigned short gwChatText_007BC850; // 0x007BC850

Unicode gwChatHistory_007BB840[8][0x101]; // 0x007BB840

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

unsigned char gbImeOpen_007BB5E0;        // 0x007BB5E0

int gnImeState_007BB5F0;        // 0x007BB5F0

static CANDIDATELIST* gpCandidateList_007BB5F4; // 0x007BB5F4

unsigned char gbChatInputOpen_007BB5E1; // 0x007BB5E1

// 0x0047A980
int __cdecl sub_0047A980_IsNumberDisplayEnabled()
{
    return gtClientFlagsLow_00712EFC.bNumberDisplay;
}

// 0x0047A9A0
void __fastcall sub_0047A9A0_SetClientFlags(int nFlags)
{
    gdwGlobal_00712EFC = nFlags;
}

// 0x0047AA30
int __cdecl sub_0047AA30_HasClassOverride()
{
    return gtClientFlags_00712EFC.bClassOverride;
}

// 0x0047AD60
static __declspec(noinline) void sub_0047AD60_RefreshCandidates(HIMC hImc)
{
    unsigned long nListCount;
    unsigned long nSize = ImmGetCandidateListCountA(hImc, &nListCount);
    if (ImmGetCandidateListA(hImc, 0, 0, 0) && nSize)
    {
        if (gpCandidateList_007BB5F4)
        {
            FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 235, 0);
        }

        gpCandidateList_007BB5F4 = (CANDIDATELIST*)FOG_Alloc(nSize, ".\\UI\\chat.cpp", 237, 0);
        ImmGetCandidateListA(hImc, 0, gpCandidateList_007BB5F4, nSize);

        if (gpCandidateList_007BB5F4->dwStyle == 2 && gpCandidateList_007BB5F4->dwCount == 1)
        {
            FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 242, 0);
            gpCandidateList_007BB5F4 = 0;
        }
    }
}

// 0x0047AE00
void __stdcall sub_0047AE00(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned long nSentence;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);

    HIMC hImc = ImmGetContext(sub_004F59A0());
    if (!hImc)
    {
        return;
    }

    switch (pMsg->wParam)
    {
    case 8:
        switch (gnLanguageId_007BB5DC)
        {
        case 6:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 3;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;

        case 8:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 5;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;

        case 9:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 4;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;
        }
        break;

    case 6:
    {
        unsigned long nConversion;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (gnLanguageId_007BB5DC == 7 || gnLanguageId_007BB5DC == 12)
        {
            if (nConversion & 1)
            {
                gnImeState_007BB5F0 = 1;
                gbImeOpen_007BB5E0 = 1;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
        }
        break;
    }

    case 5:
        if (gnLanguageId_007BB5DC == 9)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId_007BB5DC == 8)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 4:
        if (gnLanguageId_007BB5DC == 9)
        {
            if (gpCandidateList_007BB5F4)
            {
                FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 352, 0);
                gpCandidateList_007BB5F4 = 0;
            }
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId_007BB5DC == 8)
        {
            if (gpCandidateList_007BB5F4)
            {
                FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 363, 0);
                gpCandidateList_007BB5F4 = 0;
            }
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 3:
        if (gnLanguageId_007BB5DC == 9)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 2:
        if (gnLanguageId_007BB5DC == 9)
        {
            gnImeState_007BB5F0 = ImmIsIME(GetKeyboardLayout(0)) ? 0 : 4;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        break;
    }

    ImmReleaseContext(sub_004F59A0(), hImc);
}

// 0x0047B010
bool __cdecl sub_0047B010_IsImeLanguage()
{
    if (gnLanguageId_007BB5DC == 9)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x404 || nLangId == 0xC04)
            return true;
        return false;
    }
    if (gnLanguageId_007BB5DC == 8)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x804 || nLangId == 0x1004)
            return true;
        return false;
    }
    return ImmIsIME(GetKeyboardLayout(0));
}

// 0x0047B090
void __cdecl sub_0047B090_InitChatIme()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatHandlers_00712F4C, 4);
    gnLanguageId_007BB5DC = STRTABLE_GetLanguage();
    if (gnLanguageId_007BB5DC != 6 && gnLanguageId_007BB5DC != 9 && gnLanguageId_007BB5DC != 8 && gnLanguageId_007BB5DC != 7 && gnLanguageId_007BB5DC != 12)
        return;

    gbChatInputOpen_007BB5E1 = 0;
    if (!sub_0047B010_IsImeLanguage())
        return;

    const unsigned short nLangId = GetSystemDefaultLangID();
    HIMC hImc = ImmGetContext(sub_004F59A0());
    if (!hImc)
        return;

    gwChatText_007BC850 = 0;
    gwChatText_007BB5F8 = 0;
    switch (gnLanguageId_007BB5DC)
    {
    case 6:
        if (nLangId != 0x411)
            break;
        gbChatInputOpen_007BB5E1 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        if (ImmSetOpenStatus(hImc, 1))
        {
            gbImeOpen_007BB5E0 = 1;
            gnImeState_007BB5F0 = 3;
        }
        else
        {
            gbImeOpen_007BB5E0 = 0;
            gnImeState_007BB5F0 = 0;
        }
        ImmReleaseContext(sub_004F59A0(), hImc);
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
            gnImeState_007BB5F0 = 1;
            gbImeOpen_007BB5E0 = 1;
        }
        else
        {
            gnImeState_007BB5F0 = 0;
        }
        gbChatInputOpen_007BB5E1 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }

    case 9:
        gbImeOpen_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x70);
        ImmSetOpenStatus(hImc, 1);
        gnImeState_007BB5F0 = 4;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;

    case 8:
        gbImeOpen_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x10);
        ImmSetOpenStatus(hImc, 1);
        gnImeState_007BB5F0 = 5;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }
    ImmReleaseContext(sub_004F59A0(), hImc);
}

// 0x0047B4E0
void __cdecl sub_0047B4E0()
{
}

// 0x0047B9C0
void __cdecl sub_0047B9C0_RecallChatLine()
{
    memcpy(gwszChatLine_007BB638, gwChatHistory_007BB840[gnChatIndex_007BB5D8], sizeof(gwChatHistory_007BB840[0]));
    gnChatCaret_007BB5E8 = sub_00526800(gwChatHistory_007BB840[gnChatIndex_007BB5D8]);
}

// 0x0047BD00
bool __fastcall sub_0047BD00_IsNarrowText(const Unicode* pText)
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
void __cdecl sub_0047BDC0_ClearChatLine()
{
    memset(gwszChatLine_007BB638, 0, 0x202);
    gnChatCaret_007BB5E8 = 0;
    gdwGlobal_007BB5EC = 0;
}

#include "gen/data/Source/D2Client/UI/chat.inc"
