#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;
struct D2MenuItemStrc;
struct T0047BAD0;
struct Unicode;
struct D2BnetChatPacketStrc;
struct D2ClientNotifyStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

#pragma pack(push, 2)
struct T0047BAD0
{
    const char* szName;
    short nCode;
    int bArgument;
    int bAlways;
};

#pragma pack(pop)

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80
int __cdecl GAME_GetConnectionType(); // 0x0044DB30
extern T0047BAD0 gaChatCommands[3]; // 0x00712F7C
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl strcmp(const char* a, const char* b);

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

typedef void(__fastcall* MENUSELECT)(D2MenuItemStrc*, SMSGHANDLER_PARAMS*);

typedef void(__fastcall* MENUOPTION)(D2MenuItemStrc*, int);

typedef void(__fastcall* MENUUPDATE)(D2MenuItemStrc*, int);

struct D2MenuItemStrc
{
    unsigned int dwType;
    int bExpansion;
    int nHeight;
    char szImage[260];
    MENUENABLED pfEnabled;
    MENUSELECT pfSelect;
    MENUOPTION pfOption;
    MENUUPDATE pfUpdate;
    unsigned int dwCount;
    unsigned int dwMoveCount;
    unsigned int dwSliderType;
    char szChoices[4][260];
    D2CelFileStrc* pImage;
    D2CelFileStrc* pChoices[4];
};

int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0
int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20
static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern D2OptionHeaderStrc* gpOptionHeader; // 0x007BC93C
extern D2CelFileStrc* gpSliderDisabledCell_007BC950; // 0x007BC950
extern D2CelFileStrc* gpSliderEnabledCell_007BC954; // 0x007BC954
extern D2CelFileStrc* gpSliderKnob_007BC958; // 0x007BC958
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nStyle); // 0x0046EFD0
void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCellFile, int nX, int nY, int nFrame, int nColor, int nArg6); // 0x00502680
int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nColor, int nArg6); // 0x004F6480
extern int gaSlotFrame[]; // 0x007BC918
extern int gaSlotX[]; // 0x007BC898
extern int gaSlotY[]; // 0x007BC8B8
extern void* gpSlotCells; // 0x007BC964

// 0x0047BAD0
int __stdcall sub_0047BAD0_ParseChatCommand(const char** ppText, char* pCode, char* szArgument)
{
    char szText[0x100];
    char szToken[0x104];
    const char* pText = szText;
    *szArgument = 0;
    strncpy(szText, *ppText, 0x100);
    const int nTextLen = SStrLen(pText);
    for (int i = 0; i < 3; i++)
    {
        const int nNameLen = SStrLen(gaChatCommands[i].szName);
        if (!gaChatCommands[i].bAlways && !GAME_GetConnectionType())
            continue;

        if (gaChatCommands[i].nCode == 3)
        {
            if (nTextLen < nNameLen)
                continue;
            if (SStrCmpI(pText, gaChatCommands[i].szName, nNameLen))
                continue;
            *pCode = gaChatCommands[i].nCode;
            return 1;
        }

        if (nTextLen <= nNameLen)
            continue;
        if (SStrCmpI(pText, gaChatCommands[i].szName, nNameLen))
            continue;
        if (!pText[nNameLen])
            continue;

        pText += nNameLen;
        if (gaChatCommands[i].bArgument)
        {
// build: symbol ?gszSpace@* 0x006FFC44
            SStrTokenize(&pText, szToken, 0x100, gszSpace, 0);
            if (!strlen(pText))
                return 0;
            if (strlen(szToken) >= 0x32)
                return 0;
            SStrCopy(szArgument, szToken, 0x7FFFFFFF);
            *ppText += strlen(szToken) + nNameLen + 1;
        }
        else
        {
            *ppText += nNameLen;
        }
        *pCode = gaChatCommands[i].nCode;
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_0047BAD0.inc"

// 0x0047BD60
static const char* sub_0047BD60_GetAccountPart(const char* szName)
{
    const char* p = SStrChr(szName, 0x2A);
    if (p && *++p)
        return p;
    return szName;
}

static void sub_0047BD80_CopyCharPart(char* szDest, const char* szSource)
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
    }
    SStrCopy(szDest, szSource, 0x7FFFFFFF);
}

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
        const char* szText = tPacket.szName + strlen(tPacket.szName) + 1;
        if (sub_00611560_GetSquelchList()->IsNameSquelched(tPacket.szName))
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
            sub_0047BD80_CopyCharPart(szName, tPacket.szName);
            if (szName[0] && (szName[0] != 0x2A || strcmp(sub_0047BD60_GetAccountPart(szName), sub_0047BD60_GetAccountPart(tPacket.szName))))
// build: symbol ?gszNameAccountFormat@* 0x006D72C0
                sprintf(szFormatted, gszNameAccountFormat, szName, sub_0047BD60_GetAccountPart(tPacket.szName));
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
            char szPrefix[] = "<BattleNet>: ";
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

// 0x0047CC90
static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    float fSteps = (float)(pItem->dwCount - 1);
    return (unsigned int)(fSteps * (float)(nValue - nMin + 1) / (float)(nMax - nMin));
}

void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMasterVolumeOption(), 0, 100);
}

void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMusicVolumeOption(), 0, 100);
}

void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetPositionalBiasOption(), 0, 100);
}

void __fastcall Caller_GammaSlider(D2MenuItemStrc* pItem, int nGamma)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nGamma, 0x37, 0xFF);
}

// 0x0047DBB0
void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x4E8);
    D2_ASSERT(pEntries, 0x4E9);
    char szPath[260] = {0};
    char szLang[4] = {0};
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (pEntries[i].bExpansionOnly && !FOG_IsExpansion())
            continue;
        if (pEntries[i].szCelName[0])
        {
            sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].szCelName);
            pEntries[i].pCel = ARCHIVE_LoadClientCellFile(szPath, 0);
            if (pEntries[i].nKind == 1)
            {
                D2_ASSERT(pEntries[i].nValues > 0 && pEntries[i].nValues <= 4, 0x4FE);
                for (unsigned int j = 0; j < pEntries[i].nValues; ++j)
                {
                    D2_ASSERT(pEntries[i].szValueCels[j][0], 0x501);
                    sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].szValueCels[j]);
                    pEntries[i].pValueCels[j] = ARCHIVE_LoadClientCellFile(szPath, 0);
                }
            }
        }
        if (pEntries[i].pfnLoad)
            pEntries[i].pfnLoad(&pEntries[i], 0);
    }
}

// 0x0047E260
void __stdcall sub_0047E260_DrawOptionSlider(D2OptionEntryStrc* pEntry, int nY, int nColor, int bSmall)
{
    const int* pbEnabled = &pEntry->bEnabled;
    int nScreenY = gpOptionHeader->nY + nY;
    nY = bSmall ? (gnScreenWidth_0071146C / 2) - 145 : (gnScreenWidth_0071146C / 2) - 60;
    int nKnobX = nY - (int)(-265.0 / (float)(pEntry->nValues - 1) * (float)pEntry->nValue);
    int nKnobY = nScreenY - !*pbEnabled - 1;
    int nWidth = nKnobX - nY + 12;
    const int nBoxY = nScreenY - 30;
    int nBoxX = bSmall ? (gnScreenWidth_0071146C / 2) - 144 : (gnScreenWidth_0071146C / 2) - 59;
    AUTOMAP_DrawFramedBox(nBoxX, nBoxY, nWidth, 30, 0, *pbEnabled ? 1 : 2);
    AUTOMAP_DrawFramedBox(nBoxX + nWidth, nBoxY, 289 - nWidth, 30, 0, *pbEnabled != 0);

    int nCellX = gnScreenWidth_0071146C / 2 + 230;
    int nFrame = 2;
    if (bSmall)
    {
        nCellX = gnScreenWidth_0071146C / 2;
        nFrame = 1;
    }

    D2Win_10134_DrawCellFile(*pbEnabled ? gpSliderEnabledCell_007BC954 : gpSliderDisabledCell_007BC950, nCellX, nScreenY, nFrame, nColor, -1);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpSliderKnob_007BC958;
    TEXTURE_CelDraw(&tContext, nKnobX, nKnobY, -1, nColor, 0);
}

// 0x0047E9A0
void __stdcall sub_0047E9A0_DrawSlots(int bDraw)
{
    int nSlots = 8;
    if (!bDraw)
    {
        return;
    }

    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }

    int i = 0;
    if (nSlots > 0)
    {
        for (;;)
        {
            if (gnSlotState_007BC8F8[i] == 1)
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells;
                tContext.nFrame = gaSlotFrame[i] + 1;
                TEXTURE_CelDraw(&tContext, gaSlotX[i], gaSlotY[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
            else
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells;
                tContext.nFrame = gaSlotFrame[i];
                TEXTURE_CelDraw(&tContext, gaSlotX[i], gaSlotY[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
        }
    }
}
