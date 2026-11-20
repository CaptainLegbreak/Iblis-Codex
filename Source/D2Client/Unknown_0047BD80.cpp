#include "D2Client.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2ChatTextStrc;
struct D2ClientNotifyStrc;
struct Unicode;
struct D2ChatSendStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
// 0x0047BD80
static void sub_0047BD80_CopyCharPart(char* szDest, const char* szSource);

struct D2ChatMessageStrc
{
    unsigned char unk0x00;
    unsigned char nType;
    unsigned char unk0x02[6];
    unsigned char nColor;
    unsigned char unk0x09[0x11];
    D2ChatTextStrc tText;
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x14];
    void(__fastcall* pfnResign)(const char* szInput);
};
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" size_t __cdecl strlen(const char* sz);
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify(); // 0x0044B7B0

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

struct D2ClientInfoStrc
{
    char unk0x00[0x8D];
    char szName[0x10];
};

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
void __cdecl sub_00477C60_CheckCacheStats(); // 0x00477C60
void __cdecl sub_00477C00_ToggleCacheStats(); // 0x00477C00
int __cdecl sub_0044DB30(); // 0x0044DB30
void __cdecl sub_004BABC0_ToggleHints(); // 0x004BABC0
bool __fastcall sub_0047BD00_IsNarrowText(const Unicode* pText); // 0x0047BD00
int __stdcall sub_0047BAD0_ParseChatCommand(char** ppText, char* pCode, char* szArgument); // 0x0047BAD0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* pText, char nColor); // 0x0049E3A0
void __fastcall sub_004787B0_SendStrings(const unsigned char* pData); // 0x004787B0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
unsigned int __fastcall D2Win_10128(unsigned char nChar); // 0x00502550
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
T0044CB60* __fastcall sub_00502970_SplitText(Unicode* pText, unsigned int* pLineCount, int nWidth); // 0x00502970
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
extern int gnLanguageId_007BB5DC; // 0x007BB5DC
extern unsigned char gbChatInputOpen_007BB5E1; // 0x007BB5E1
extern unsigned int gnChatCaret_007BB5E8; // 0x007BB5E8
extern int gdwGlobal_007BB5EC; // 0x007BB5EC
extern int gnGlobal_0071146C; // 0x0071146C
extern int gbNoPickup_007A6A90; // 0x007A6A90
extern unsigned short gwChatHistoryCount_007BB5E4; // 0x007BB5E4
extern Unicode gawszChatHistory_007BB840[8][257]; // 0x007BB840
extern Unicode gwszChatLine_007BB638[]; // 0x007BB638

struct D2OptionHeaderStrc
{
    int nCount;
};

struct D2OptionEntryStrc
{
    int nKind;
    int bExpansionOnly;
    char unk0x008[4];
    char f_C[0x104];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[4];
    char szValueCels[4][0x104];
    void* pCel;
    void* pValueCels[4];
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries); // 0x0047DBB0
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
D2CelFileStrc* __cdecl sub_00453AA0(); // 0x00453AA0
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
extern D2OptionHeaderStrc gOptionHeader_00713044; // 0x00713044
extern D2OptionEntryStrc gaOptionEntries_00713220[]; // 0x00713220
extern D2OptionHeaderStrc gOptionHeader_00714210; // 0x00714210
extern D2OptionEntryStrc gaOptionEntries_00714238[]; // 0x00714238
extern D2OptionHeaderStrc gOptionHeader_00714224; // 0x00714224
extern D2OptionEntryStrc gaOptionEntries_00715CC8[]; // 0x00715CC8
extern D2OptionHeaderStrc gOptionHeader_0071875C; // 0x0071875C
extern D2OptionEntryStrc gaOptionEntries_0071ACA0[]; // 0x0071ACA0
extern D2OptionHeaderStrc gOptionHeader_0071D734; // 0x0071D734
extern D2OptionEntryStrc gaOptionEntries_0071F728[]; // 0x0071F728
extern D2OptionHeaderStrc gOptionHeader_00718748; // 0x00718748
extern D2OptionEntryStrc gaOptionEntries_00718770[]; // 0x00718770
extern D2OptionHeaderStrc gOptionHeader_0071D720; // 0x0071D720
extern D2OptionEntryStrc gaOptionEntries_0071D748[]; // 0x0071D748
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C
extern D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940
extern D2CelFileStrc* gpOptionCel_007BC950; // 0x007BC950
extern D2CelFileStrc* gpOptionCel_007BC954; // 0x007BC954
extern D2CelFileStrc* gpOptionCel_007BC958; // 0x007BC958

static __declspec(noinline) void sub_0047BD80_CopyCharPart(char* szDest, const char* szSource)
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

void __cdecl sub_M04_Emit_0047BD80(char* szDest, const char* szSource)
{
    sub_0047BD80_CopyCharPart(szDest, szSource);
}

static int __stdcall sub_0047B3B0_CompareCommand(const char* szCommand, const char* szInput)
{
    if (strlen(szInput) < strlen(szCommand))
        return -1;
    size_t nLength = strlen(szCommand);
    while (nLength)
    {
        --nLength;
        const int nDiff = toupper(*szInput) - toupper(*szCommand);
        if (nDiff)
            return (nDiff > 0) * 2 - 1;
        ++szInput;
        ++szCommand;
    }
    return 0;
}

// 0x0047C100
static int sub_0047C100(char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0047B3B0_CompareCommand(szCommand, szInput))
    {
        const char c = szInput[nLength];
        if (c == 0x20 || !c)
        {
            char szDelim[] = " ";
            int nTokens = 0;
            if (strtok(szInput, szDelim))
            {
                do
                {
                    if (nTokens >= 2)
                    {
                        break;
                    }
                    nTokens += 1;
                }
                while (strtok(0, szDelim));
            }
            if (nTokens != 1)
            {
                D2ChatMessageStrc tMessage;
                tMessage.nType = 4;
                tMessage.nColor = 3;
                D2ChatTextStrc tBuffer;
                sprintf(tBuffer.sz, "<BattleNet>: Correct usage is: %s", szCommand);
                tMessage.tText = tBuffer;
                sub_0049F490_PrintChatMessage(&tMessage);
                return 1;
            }
            D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
            if (pNotify)
                pNotify->pfnResign(szInput);
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_F07_Emit_0047C100(char* szInput)
{
    if (sub_0047C100(szInput, "/help"))
        return 1;
    if (sub_0047C100(szInput, "/?"))
        return 1;
    return 0;
}

static void sub_0047BA00_PushChatHistory(const Unicode* pText)
{
    int nIndex;
    if (gwChatHistoryCount_007BB5E4 != 8)
    {
        if (gwChatHistoryCount_007BB5E4)
        {
            if (--gnChatHistoryHead_00712F44 < 0)
                gnChatHistoryHead_00712F44 = 7;
        }
        nIndex = gnChatHistoryHead_00712F44;
        ++gwChatHistoryCount_007BB5E4;
    }
    else
    {
        nIndex = gnChatHistoryTail_00712F48;
        gnChatHistoryHead_00712F44 = nIndex;
        if (--gnChatHistoryTail_00712F48 < 0)
            gnChatHistoryTail_00712F48 = 7;
    }
    gnChatHistoryCursor_007BB5D8 = nIndex;
    memcpy(gawszChatHistory_007BB840[nIndex], pText, sizeof(gawszChatHistory_007BB840[0]));
}

// 0x0047C1F0
static int __stdcall sub_0047C1F0_HandleWhisperCommand(int bCheckStored, char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0047B3B0_CompareCommand(szCommand, szInput))
    {
        const char c = szInput[nLength];
        if (c == ' ' || !c)
        {
            D2ChatMessageStrc tMessage;
            char szName[0x100];
            char szMessage[0x100];
            {
                char szCopy[0x104];
                strcpy(szCopy, szInput);
                char* pToken = strtok(szInput, gszSpace_00712FFC);
                int nTokens = 0;
                for (; pToken; pToken = strtok(0, gszSpace_00712FFC))
                {
                    ++nTokens;
                    if (nTokens == 2)
                    {
                        strcpy(szName, pToken);
                    }
                    else if (nTokens == 3)
                    {
                        strcpy(szMessage, &szCopy[pToken - szInput]);
                        break;
                    }
                }
                if (nTokens != 3)
                {
                    tMessage.nType = 4;
                    tMessage.nColor = 3;
                    sprintf(szCopy, "<BattleNet>: Correct usage is: %s (name) (message)", szCommand);
                    memcpy(&tMessage.tText, szCopy, sizeof(tMessage.tText));
                    sub_0049F490_PrintChatMessage(&tMessage);
                    return 1;
                }
            }
            if (bCheckStored)
            {
                for (D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0); pEntry; pEntry = sub_004795A0_GetNextEntry(pEntry))
                {
                    if (!_stricmp(sub_004795C0_GetEntryName(pEntry), szName))
                    {
                        D2ChatSendStrc tSend;
                        strncpy(tSend.szText, szMessage, sizeof(tSend.szText) - 1);
                        tSend.szText[sizeof(tSend.szText) - 1] = 0;
                        strcpy(tSend.szArgument, szName);
                        tSend.nLang = gnLanguageId_007BB5DC;
                        tSend.nCode = 2;
                        tSend.nType = 0x15;
                        sub_004787B0_SendStrings((const unsigned char*)&tSend);
                        return 1;
                    }
                }
            }
            sprintf(szInput, "%s %s %s", szCommand, szName, szMessage);
            D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
            if (pNotify)
                pNotify->pfnResign(szInput);
            return 1;
        }
    }
    return 0;
}

static void __stdcall sub_0047C3F0_CopyCommandArgs(char* szDest, const char* szSource, unsigned int nSize)
{
    const char* pArgs = SStrChr(szSource, ' ');
    if (pArgs)
        SStrCopy(szDest, pArgs + 1, nSize);
    else
        *szDest = 0;
}

static void __stdcall sub_0047C420_HandleChatCommand(char* szText, int nSkip, const Unicode* pLine)
{
    D2ChatSendStrc tSend;
    memset(tSend.szText, 0, sizeof(tSend.szText));
    tSend.nLang = gnLanguageId_007BB5DC;
    char* pCommand = &szText[nSkip];
    char* pText = pCommand;
    if (!_stricmp(pText, "/fps"))
    {
        sub_00477C60_CheckCacheStats();
        sub_00455F20(5, 1, 0);
        return;
    }
    if (!_stricmp(pText, "/framerate"))
    {
        sub_00477C00_ToggleCacheStats();
        sub_00455F20(5, 1, 0);
        return;
    }
    if (!_strnicmp(pText, "/players", 8))
    {
        if (!sub_0044DB30() || sub_0044DB30() == 1 || sub_0044DB30() == 6 || sub_0044DB30() == 8)
        {
            int nPlayers = atoi(pText + 8);
            if (nPlayers <= 1)
                nPlayers = 1;
            else if (nPlayers >= 8)
                nPlayers = 8;
            sub_00535780_SetPlayerCount(nPlayers);
            sprintf(pText, "players set to %d", nPlayers);
        }
    }
    if (!_stricmp(pText, "/nopickup"))
    {
        gbNoPickup_007A6A90 = !gbNoPickup_007A6A90;
    }
    else if (!_stricmp(pText, "soundchaosdebug"))
    {
        sub_004BABC0_ToggleHints();
    }
    else
    {
        tSend.nCode = 1;
        tSend.nType = 0x15;
        tSend.nLang = gnLanguageId_007BB5DC;
        if (!gbChatInputOpen_007BB5E1 || sub_0047BD00_IsNarrowText(pLine))
        {
            if (sub_0047BAD0_ParseChatCommand(&pCommand, &tSend.nCode, tSend.szArgument) && !tSend.nCode)
                tSend.nType = 0x14;
            pText = pCommand;
        }
        if (!sub_0047B3B0_CompareCommand("/ignorepersist", pText))
        {
            D2SquelchListStrc* pGetList = sub_00611560_GetSquelchList();
            D2SquelchListStrc* pSetList = sub_00611560_GetSquelchList();
            pSetList->SetPersistent(!pGetList->IsPersistent());
            Unicode wszText[0x104];
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix_006D72B0, 0x208);
            if (sub_00611560_GetSquelchList()->IsPersistent())
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA1));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA2));
            sub_0049E3A0_PrintChatLine(wszText, 3);
        }
        else if (!sub_0047B3B0_CompareCommand("/ignore ", pText) || !sub_0047B3B0_CompareCommand(gszCmdSquelch_006D5698, pText))
        {
            Unicode wszText[0x208];
            Unicode wszLine[0x208];
            Unicode wszName[0x22];
            char szName[0x11];
            sub_0047C3F0_CopyCommandArgs(szName, pText, sizeof(szName));
            if (SStrCmpI(&szName[1], gpClientInfo_007A0438->szName, 0x7FFFFFFF))
            {
                sub_00526320_ToUnicode(wszLine, gszBattleNetPrefix_006D72B0, 0x208);
                sub_00526320_ToUnicode(wszName, szName, 0x22);
                if (sub_00611560_GetSquelchList()->Squelch(szName))
                    sub_005269D0(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
                else
                    sub_005269D0(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
                sub_00526700(wszLine, wszText);
            }
            sub_0049E3A0_PrintChatLine(wszLine, 3);
        }
        else if (!sub_0047B3B0_CompareCommand("/unignore ", pText) || !sub_0047B3B0_CompareCommand(gszCmdUnsquelch_006D5680, pText))
        {
            Unicode wszText[0x208];
            Unicode wszLine[0x208];
            Unicode wszName[0x22];
            char szName[0x11];
            sub_0047C3F0_CopyCommandArgs(szName, pText, sizeof(szName));
            sub_00526320_ToUnicode(wszLine, gszBattleNetPrefix_006D72B0, 0x208);
            sub_00526320_ToUnicode(wszName, szName, 0x22);
            if (sub_00611560_GetSquelchList()->Unsquelch(szName))
                sub_005269D0(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
            else
                sub_005269D0(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
            sub_00526700(wszLine, wszText);
            sub_0049E3A0_PrintChatLine(wszLine, 3);
        }
        else if (!sub_0047B3B0_CompareCommand("/filtermsg ", pText))
        {
            Unicode wszText[0x208];
            char szFilter[0x104];
            sub_0047C3F0_CopyCommandArgs(szFilter, pText, sizeof(szFilter));
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix_006D72B0, 0x208);
            if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA7));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA8));
            sub_0049E3A0_PrintChatLine(wszText, 3);
        }
        else if (!sub_0047B3B0_CompareCommand("/unfiltermsg ", pText))
        {
            Unicode wszText[0x104];
            char szFilter[0x104];
            sub_0047C3F0_CopyCommandArgs(szFilter, pText, sizeof(szFilter));
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix_006D72B0, 0x208);
            if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA9));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BAA));
            sub_0049E3A0_PrintChatLine(wszText, 3);
        }
        else if (tSend.nCode == 3 && (!gbChatInputOpen_007BB5E1 || sub_0047BD00_IsNarrowText(pLine)))
        {
            if (!sub_0047C1F0_HandleWhisperCommand(1, pText, "/msg")
                && !sub_0047C1F0_HandleWhisperCommand(1, pText, "/m")
                && !sub_0047C1F0_HandleWhisperCommand(1, pText, "/whisper")
                && !sub_0047C1F0_HandleWhisperCommand(1, pText, "/w")
                && !sub_0047C100(pText, "/help")
                && !sub_0047C100(pText, "/?"))
            {
                D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
                if (pNotify)
                    pNotify->pfnResign(pText);
            }
        }
        else if (sub_00526800(pLine) > 0)
        {
            memcpy(tSend.szText, pText, sizeof(tSend.szText) - 1);
            tSend.szText[sizeof(tSend.szText) - 1] = 0;
            sub_004787B0_SendStrings((const unsigned char*)&tSend);
        }
    }
    sub_00455F20(5, 1, 0);
}

// 0x0047CA70
void __stdcall sub_0047CA70_OnChatChar(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BB5EC < 1)
        return;
    const int nLength = sub_00526800(gwszChatLine_007BB638);
    switch (pMsg->wParam)
    {
    case 8:
        if (gnChatCaret_007BB5E8 > 0)
        {
            --gnChatCaret_007BB5E8;
            gwszChatLine_007BB638[gnChatCaret_007BB5E8].wChar = 0;
        }
        break;
    case 0x1B:
        sub_00455F20(5, 1, 0);
        break;
    case 0xD:
    {
        int nSkip = 0;
        while (gwszChatLine_007BB638[nSkip].isWhitespace())
            ++nSkip;
        const Unicode* pText = &gwszChatLine_007BB638[nSkip];
        if (!sub_00526800(pText))
        {
            sub_00455F20(5, 1, 0);
            break;
        }
        sub_0047BA00_PushChatHistory(pText);
        char szText[0x104];
        WideCharToMultiByte(0, 0x250, (const wchar_t*)gwszChatLine_007BB638, -1, szText, 0x100, 0, 0);
        sub_0047C420_HandleChatCommand(szText, nSkip, gwszChatLine_007BB638);
        break;
    }
    default:
    {
        if (!gbChatInputOpen_007BB5E1 && !D2Win_10128(pMsg->wParam))
            break;
        if (gnChatCaret_007BB5E8 >= 0xFF || nLength >= 0xFF)
            break;
        const int nOldFont = sub_00502EF0(0xD);
        unsigned int nLines;
        T0044CB60* pLines = sub_00502970_SplitText(gwszChatLine_007BB638, &nLines, gnGlobal_0071146C - 0x109);
        int nWidth = 0;
        for (T0044CB60* pLine = pLines; pLine; )
        {
            T0044CB60* pNext = pLine->pNext;
            nWidth = sub_00501820(pLine->pText);
            pLine = pNext;
        }
        sub_005028A0_FreeTextLines(pLines);
        if (nLines <= 3 && (nLines != 3 || nWidth <= gnGlobal_0071146C - 0x113))
        {
            gwszChatLine_007BB638[nLength].wChar = pMsg->wParam;
            pLines = sub_00502970_SplitText(gwszChatLine_007BB638, &nLines, gnGlobal_0071146C - 0x109);
            nWidth = 0;
            for (T0044CB60* pLine = pLines; pLine; )
            {
                T0044CB60* pNext = pLine->pNext;
                nWidth = sub_00501820(pLine->pText);
                pLine = pNext;
            }
            sub_005028A0_FreeTextLines(pLines);
            if (nLines != 3 || nWidth < gnGlobal_0071146C - 0x113)
                ++gnChatCaret_007BB5E8;
        }
        sub_00502EF0(nOldFont);
        break;
    }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

#include "gen/data/Source/D2Client/Unknown_0047BD80.inc"
struct D2StoredUnitRecordStrc;

int gnOptionMaxWidth_007BC95C; // 0x007BC95C

// 0x0047DD70
void __cdecl sub_0047DD70_LoadOptionMenus()
{
    D2CelContextStrc tContext;
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00713044, gaOptionEntries_00713220);
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00714210, gaOptionEntries_00714238);
    sub_0047DBB0_LoadOptionCels(&gOptionHeader_00714224, gaOptionEntries_00715CC8);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071875C, gaOptionEntries_0071ACA0);
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071D734, gaOptionEntries_0071F728);
    }
    else
    {
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_00718748, gaOptionEntries_00718770);
        sub_0047DBB0_LoadOptionCels(&gOptionHeader_0071D720, gaOptionEntries_0071D748);
    }
    gpOptionHeader_007BC93C = &gOptionHeader_00713044;
    gpOptionEntries_007BC940 = gaOptionEntries_00713220;
    char szPath[260] = {0};
    sprintf(szPath, "%s\\UI\\Widgets\\OptBar", szDataGlobal_006D4118);
    gpOptionCel_007BC950 = sub_004788B0(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptBarC", szDataGlobal_006D4118);
    gpOptionCel_007BC954 = sub_004788B0(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptSkull", szDataGlobal_006D4118);
    gpOptionCel_007BC958 = sub_004788B0(szPath, 0);
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00453AA0();
    const unsigned int nFrames = CelFileGetCelsPerDirection(tContext.pCellFile);
    int nMax = 0;
    for (tContext.nFrame = 0; tContext.nFrame < nFrames; ++tContext.nFrame)
        nMax = D2_MAX(nMax, sub_006018C0(CelGetHandle(&tContext)));
    gnOptionMaxWidth_007BC95C = nMax;
}
