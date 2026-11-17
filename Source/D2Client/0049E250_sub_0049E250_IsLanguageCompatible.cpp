// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H* 0x00403040

struct D2HoverTextStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    static Unicode* __fastcall strcat(Unicode* dest, const Unicode* src);                                 // 0x00526700
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);                    // 0x00526F20
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xA4 - 0x08];
    D2HoverTextStrc* pHoverText;
};

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

struct D2CommonChatIgnoreListStrc
{
    virtual int sub_00610EB0_Add(const char* szName) = 0;
    virtual int sub_0060FB20_Remove(const char* szName) = 0;
    virtual int sub_00610380_IsListed(const char* szName) = 0;
    virtual void sub_00610F90_VirtSlot3() = 0;
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;
    virtual int sub_0060FC40_IsTextFiltered(const char* szText) = 0;
    virtual void sub_00611320_VirtSlot6() = 0;
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;
    virtual int sub_0060DDF0_IsEnabled() = 0;
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;
    virtual void sub_0060F500_VirtSlot10() = 0;
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
};

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C
extern "C" unsigned int __cdecl strlen(const char* szString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
Unicode* __fastcall sub_00452300_StripStringAndNextChar(Unicode* pText);                                    // 0x00452300
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
int __fastcall sub_0047A170_TestNotFlag4(int nUnitId);                                                      // 0x0047A170
void __fastcall sub_0048BBE0_SetNameText(const Unicode* wszName, int nUnused, int nArg);                    // 0x0048BBE0
void __fastcall sub_0049E3A0_ShowChatText(const Unicode* wszText, char nColor);                             // 0x0049E3A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
extern "C" Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                          // 0x005267E0
void __cdecl sub_005269D0_Unicode_sprintf(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);                  // 0x005269D0
D2CommonIgnoreListStrc* sub_00611560_GetOrCreateIgnoreList();                                               // 0x00611560
char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit);                                                     // 0x00622150
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemoryPool, const char* szText, int nGameFrame);       // 0x00661110
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId);                 // 0x00661230

extern int gnGameFrame_007BF20E;                                                                            // 0x007BF20E

static __declspec(noinline) bool sub_0049E250_IsLanguageCompatible(int nLangId);

// 0x0049E250
static bool sub_0049E250_IsLanguageCompatible(int nLangId)
{
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (!(nCurrentLangId == nLangId))
    {
        if (nCurrentLangId == 7)
        {
            if (nLangId == 0xC)
                return true;
        }
        else if (nCurrentLangId == 0xC)
        {
            if (nLangId == 7)
                return true;
        }
        return false;
    }
    return true;
}

// build: context sub_0049E280_ConvertHoverText
static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        Unicode::win2Unicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    if (sub_0049E250_IsLanguageCompatible(nLangId))
        return true;

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

// 0x0049F410
static void __stdcall sub_0049F410_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (!strlen(szText))
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        return;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

// build: context sub_0049F490_HandleHoverTextPacket
void __fastcall sub_0049F490_HandleHoverTextPacket(D2GSPacketSrv26* pPacket)
{
    if (pPacket->nUnitType == 0 && !sub_0047A170_TestNotFlag4(pPacket->dwUnitGUID))
        return;

    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitGUID, pPacket->nUnitType);
    char szName[0x11] = { 0 };
    if ((pUnit && pUnit->dwUnitType == 0) || pPacket->szName[0])
    {
        if (pUnit)
            SStrCopy(szName, UNITS_GetPlayerName(pUnit), 0x11);
        else
            SStrCopy(szName, pPacket->szName, 0x11);

        if (sub_00611560_GetOrCreateIgnoreList()->sub_00610380_IsListed(szName))
            return;
        if (sub_00611560_GetOrCreateIgnoreList()->sub_0060FC40_IsTextFiltered(pPacket->szMessage))
            return;
    }

    Unicode wszText[0x100];
    if (!sub_0049E280_ConvertHoverText(pPacket->nLang, wszText, pPacket->szMessage))
        return;
    wszText[0xFF].wChar = 0;

    if (pPacket->nMessageType == 4)
    {
        sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
        return;
    }

    UnicodeChar wszA[0x264];
    UnicodeChar wszB[0x264];
    UnicodeChar wszC[0x10];
    if (pPacket->nMessageType == 6)
    {
        Unicode::win2Unicode(wszB, pPacket->szMessage, 0x100);
        Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
        sub_005269D0_Unicode_sprintf(0x264, wszA, D2LANG_GetStringFromTblIndex(0xE4A), wszC, wszB);
        sub_00452300_StripStringAndNextChar(wszA);
        sub_0049E3A0_ShowChatText(wszA, 2);
    }
    else if (pPacket->nMessageType == 2)
    {
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszC);
            Unicode::strcat(wszA, D2LANG_GetStringFromTblIndex(0xE46));
            sub_005267E0(wszB, wszText);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_ShowChatText(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
            return;
        }
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            UnicodeChar wszD[0x10];
            Unicode::win2Unicode(wszD, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszD);
            sub_004521C0_PrefixLevelText(wszA, 4);
            sub_005267E0(wszB, D2LANG_GetStringFromTblIndex(0xFD0));
            Unicode::strcat(wszB, wszText);
            sub_004521C0_PrefixLevelText(wszB, 0);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
    }
    else if (pPacket->nMessageType == 5)
    {
        if (pUnit)
            sub_0049F410_SetHoverText(pPacket->nLang, pPacket->szMessage, pUnit);
    }
    else if (pPacket->nMessageType == 7)
    {
        UnicodeChar wszE[0x100];
        MultiByteToWideChar(0, 1, pPacket->szMessage, 0x100, wszE, 0x100);
        const int nLang = pPacket->nLang;
        if (nLang != STRTABLE_GetLanguage())
        {
            for (Unicode* p = wszE; p->wChar; ++p)
                ;
        }
        sub_0048BBE0_SetNameText(wszE, nLang, pPacket->nMessageColor);
    }
}
