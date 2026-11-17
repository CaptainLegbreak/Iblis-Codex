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

struct T0047A980;

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID();                        // 0x006CC354
extern "C" __declspec(dllimport) T0047A980* __stdcall GetKeyboardLayout(unsigned long idThread);               // 0x006CC4C0
extern "C" int __stdcall ImmIsIME(T0047A980* hKl);                                                              // 0x006B00D8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC;                                                      // 0x00712EFC
extern D2ClientFlagsStrc gtClientFlags_00712EFC;                                                            // 0x00712EFC
extern int gdwGlobal_00712EFC;                                                                              // 0x00712EFC
extern int gnLanguageId_007BB5DC;                                                                           // 0x007BB5DC
extern int gnChatIndex_007BB5D8;                                                                            // 0x007BB5D8
extern int gnChatCaret_007BB5E8;                                                                            // 0x007BB5E8
extern int gdwGlobal_007BB5EC;                                                                              // 0x007BB5EC
extern Unicode gwszChatLine_007BB638[];                                                                     // 0x007BB638
Unicode gwChatHistory_007BB840[8][0x101];                                                                   // 0x007BB840

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
