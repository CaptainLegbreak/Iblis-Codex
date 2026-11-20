#include "D2Client.h"

struct T0047A980;
struct D2MsgHandlerEntryStrc;
struct Unicode;
struct D2ClientFlagsLowStrc;
struct D2ClientFlagsStrc;

struct Unicode
{
    unsigned short wChar;
};

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
extern "C" __declspec(dllimport) T0047A980* __stdcall GetKeyboardLayout(unsigned long idThread); // 0x006CC4C0
extern "C" int __stdcall ImmIsIME(T0047A980* hKl); // 0x006B00D8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC; // 0x00712EFC
extern D2ClientFlagsStrc gtClientFlags_00712EFC; // 0x00712EFC
extern int gnLanguageId_007BB5DC; // 0x007BB5DC
extern int gnChatIndex_007BB5D8; // 0x007BB5D8
extern int gnChatCaret_007BB5E8; // 0x007BB5E8
extern int gdwGlobal_007BB5EC; // 0x007BB5EC
extern Unicode gwszChatLine_007BB638[]; // 0x007BB638
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
bool __cdecl sub_0047B010_IsImeLanguage(); // 0x0047B010
int __cdecl sub_004F59A0(); // 0x004F59A0
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
extern "C" int __stdcall ImmReleaseContext(int hWnd, T0046E1B0* hImc); // 0x006B00B4
extern "C" T0046E1B0* __stdcall ImmGetContext(int hWnd); // 0x006B00C6
extern "C" int __stdcall ImmGetConversionStatus(T0046E1B0* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE
extern "C" int __stdcall ImmSimulateHotKey(int hWnd, unsigned long nHotKey); // 0x006B00E4
extern D2MsgHandlerEntryStrc gtChatHandlers_00712F4C[]; // 0x00712F4C
extern D2MsgHandlerEntryStrc gtChatInputHandlers_00712FA8[]; // 0x00712FA8
extern unsigned short gwChatText_007BB5F8; // 0x007BB5F8
extern unsigned short gwChatText_007BC850; // 0x007BC850

Unicode gwChatHistory_007BB840[8][0x101]; // 0x007BB840

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

unsigned char gbChatInputOpen_007BB5E1; // 0x007BB5E1

static unsigned char gbGlobal_007BB5E0; // 0x007BB5E0

static int gnGlobal_007BB5F0; // 0x007BB5F0

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
    T0046E1B0* hImc = ImmGetContext(sub_004F59A0());
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
            gbGlobal_007BB5E0 = 1;
            gnGlobal_007BB5F0 = 3;
        }
        else
        {
            gbGlobal_007BB5E0 = 0;
            gnGlobal_007BB5F0 = 0;
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
            gnGlobal_007BB5F0 = 1;
            gbGlobal_007BB5E0 = 1;
        }
        else
        {
            gnGlobal_007BB5F0 = 0;
        }
        gbChatInputOpen_007BB5E1 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }

    case 9:
        gbGlobal_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x70);
        ImmSetOpenStatus(hImc, 1);
        gnGlobal_007BB5F0 = 4;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;

    case 8:
        gbGlobal_007BB5E0 = 0;
        gbChatInputOpen_007BB5E1 = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(sub_004F59A0(), 0x10);
        ImmSetOpenStatus(hImc, 1);
        gnGlobal_007BB5F0 = 5;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        break;
    }
    ImmReleaseContext(sub_004F59A0(), hImc);
}

#include "gen/data/Source/D2Client/UI/chat.inc"
