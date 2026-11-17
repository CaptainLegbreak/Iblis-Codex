typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2WinControlInitStrc
{
    char data[0x30];
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x4C];
    int (__fastcall* pfnSlot4C)();
};

struct D2LaunchNameNodeStrc
{
    char szName[0x204];
    D2LaunchNameNodeStrc* pNext;
};

struct D2LaunchCharEntryStrc
{
    char szName[0x100];
    Unicode wszName[0x100];
    char aBlock0x300[0x10];
    char aBlock0x310[0x10];
    unsigned char nType;
    char unk0x321;
    char nByte0x322;
    char unk0x323;
    unsigned short wFlags;
    char unk0x326[0x08];
    char nByte0x32E;
    char unk0x32F[0x1D];
    D2LaunchCharEntryStrc* pNext;
};

#pragma pack(push, 1)
struct D2LaunchCharSelectStrc
{
    char unk0x000[0x19];
    int nState;
    char unk0x01D[0x1F3];
    char nMode;
    char unk0x211[0x190];
    char aBlock0x3A1[0x10];
    char aBlock0x3B1[0x10];
    char nByte0x3C1;
    char nByte0x3C2;
    char unk0x3C3[0x08];
    unsigned short wFlags;
};
#pragma pack(pop)

typedef void (__cdecl* D2LaunchDoneFn)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" char* __cdecl strncat(char* szDest, const char* szSource, size_t nCount);                        // 0x00687490
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __fastcall sub_00434A00_Join(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00
int __stdcall sub_00435E00_Back(int nArg);                                                                  // 0x00435E00
void __fastcall sub_00439780_PickClass(int nClass, int bExpansion);                                         // 0x00439780
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
int __fastcall sub_0043DAD0_SetMainState(int bSet);                                                         // 0x0043DAD0
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor);                                          // 0x0043E610
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
int __cdecl sub_00449E20();                                                                                 // 0x00449E20
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FCFF0_SetTextA(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
int __stdcall sub_004FD110_SetBarValue(D2WinControlStrc* pBar, int nValue);                                 // 0x004FD110
int __stdcall sub_004FD170_SetBarMode(D2WinControlStrc* pBar, int nMode);                                   // 0x004FD170
int __stdcall sub_004FD1B0_GetBarMax(D2WinControlStrc* pBar);                                               // 0x004FD1B0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern "C" const char gszSpace_006FFC44[];                                                                  // 0x006FFC44
extern D2WinControlInitStrc gtControlInit_0070D300;                                                         // 0x0070D300
extern D2WinControlInitStrc gtControlInit_0070EAA0;                                                         // 0x0070EAA0
extern D2WinControlInitStrc gtControlInit_0070EAD0;                                                         // 0x0070EAD0
extern D2WinControlInitStrc gtControlInit_0070EB30;                                                         // 0x0070EB30
extern D2WinControlInitStrc gtControlInit_0070EB60;                                                         // 0x0070EB60
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4;                                                       // 0x007795D4
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
D2WinControlStrc* gpProgressText_00779978;                                                                  // 0x00779978
D2WinControlStrc* gpProgressBar_0077997C;                                                                   // 0x0077997C
extern int gbBusy_00779DA0;                                                                                 // 0x00779DA0
extern D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                          // 0x00779DBC
D2WinControlStrc* gpCharSelectText_00779DD4;                                                                // 0x00779DD4
int gbFlag_00779DD8;                                                                                        // 0x00779DD8
int gnCounter_00779DDC;                                                                                     // 0x00779DDC
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlStrc* gpNamesButton_0077BD08;                                                            // 0x0077BD08
extern D2LaunchNameNodeStrc* gpNameList_0077BDB4;                                                           // 0x0077BDB4
D2WinControlStrc* gpPanelControl_00798BEC;                                                                  // 0x00798BEC
D2WinControlStrc* gpPanelTitle_00798BF0;                                                                    // 0x00798BF0
D2WinControlStrc* gpPanelText_00798BF4;                                                                     // 0x00798BF4
extern D2WinControlStrc* gpCreateButton_00798C28;                                                           // 0x00798C28
D2WinControlStrc* gpPanelControl_00798C48;                                                                  // 0x00798C48

#include "gen/data/Source/D2Client/0042F890_sub_0042F890_ShowProgressScreen/s_nSelected_0070CC00.inc"
#include "gen/data/Source/D2Client/0042F890_sub_0042F890_ShowProgressScreen/s_nSelectionA_0070CC04.inc"
#include "gen/data/Source/D2Client/0042F890_sub_0042F890_ShowProgressScreen/s_nSelectionB_0070CC08.inc"

static __forceinline int ProgressBarValue(int nPercent)
{
    return nPercent * sub_004FD1B0_GetBarMax(gpProgressBar_0077997C) / 100;
}

// 0x0042F890
void __cdecl sub_0042F890_ShowProgressScreen()
{
    char szText[100];
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x116);
    gpProgressBar_0077997C = sub_0042F430_CreateControl(0x117);
    sub_004FD170_SetBarMode(gpProgressBar_0077997C, 3);
    gpProgressText_00779978 = sub_0042F430_CreateControl(0x113);
    int nPercent = gpFuncTable_0077ABF0->pfnSlot4C();
    if (nPercent > 100)
        nPercent = 100;
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x114);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143A), 0, 0, 0);
    pControl = sub_0042F430_CreateControl(0x112);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143B), 0, 0, 0);
    sub_0042F430_CreateControl(0x118);
    sub_004FD110_SetBarValue(gpProgressBar_0077997C, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    sub_004FCFF0_SetTextA(gpProgressText_00779978, szText, 0);
}

// 0x0042F990
void __cdecl sub_0042F990_UpdateProgress()
{
    char szText[100];
    sub_004FB6A0_ClearText(gpProgressText_00779978);
    int nPercent = gpFuncTable_0077ABF0->pfnSlot4C();
    if (nPercent > 100)
        nPercent = 100;
    sub_004FD110_SetBarValue(gpProgressBar_0077997C, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    if (gpProgressText_00779978)
        sub_004FCFF0_SetTextA(gpProgressText_00779978, szText, 0);
}

static __forceinline int FilterNoSeparator(D2WinControlStrc* pControl)
{
    char szText[0x20];
    const Unicode* pText = sub_004FDD90_GetEditText(pControl);
    sub_005263E0(szText, pText, 0x20);
    for (int i = 0; szText[i]; i += 1)
    {
        if (szText[i] == '-' || szText[i] == '_')
            return 0;
    }
    return 1;
}

// 0x00430590
int __stdcall sub_00430590_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar)
{
    const char c = *pChar;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ((c == '-' || c == '_') && bAllowSep && FilterNoSeparator(pControl)))
        return 1;
    return 0;
}

// 0x00439840
int __stdcall sub_00439840(int nArg)
{
    char szName[0x100];

    if (gbBusy_00779DA0)
        return 1;

    gpCharSelect_007795D4->nMode = 0;
    if (s_nSelected_0070CC00 == s_nSelectionA_0070CC04)
    {
        if (gnLaunchMode_007795EC != 1 || !gbFlag_00779DD8)
        {
            sub_00435E00_Back(nArg);
            gnCounter_00779DDC -= 1;
            if (gnCounter_00779DDC <= 0)
            {
                gbFlag_00779DD8 = 1;
                return 1;
            }
        }
    }
    else if (s_nSelected_0070CC00 == s_nSelectionB_0070CC08)
    {
        sub_004FB6A0_ClearText(gpCharSelectText_00779DD4);
        sub_004FC9B0_SetText(gpCharSelectText_00779DD4, D2LANG_GetStringFromTblIndex(0x2B3C), 0, 0, 0);
        sub_004FC9B0_SetText(gpCharSelectText_00779DD4, D2LANG_GetStringFromTblIndex(0x2B3D), 0, 0, 0);
        return 1;
    }
    else if (s_nSelected_0070CC00 != -1)
    {
        D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
        for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
        {
            if (s_nSelected_0070CC00 == i)
                break;
        }

        if (!pEntry)
            return 1;

        if (gnLaunchMode_007795EC == 1 || gnLaunchMode_007795EC == 3)
        {
            memcpy(gpCharSelect_007795D4->aBlock0x3A1, pEntry->aBlock0x300, 0x10);
            memcpy(gpCharSelect_007795D4->aBlock0x3B1, pEntry->aBlock0x310, 0x10);
            gpCharSelect_007795D4->nByte0x3C1 = pEntry->nByte0x322;
            gpCharSelect_007795D4->nByte0x3C2 = pEntry->nByte0x32E;
            gpCharSelect_007795D4->wFlags = pEntry->wFlags;
        }

        if (pEntry->wFlags & 0x20)
        {
            if (!sub_00408F20_HasExpansionMpq())
                return 0;
        }

        if ((pEntry->wFlags & 4) && (pEntry->wFlags & 8) && (gnLaunchMode_007795EC == 0 || gnLaunchMode_007795EC == 2))
        {
            sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14B8), sub_0042F3F0_DestroyControls);
            return 1;
        }

        if (gnLaunchMode_007795EC == 0 || (gnLaunchMode_007795EC == 2 && gpCharSelect_007795D4->nState == 8))
        {
            int nClass = (pEntry->wFlags >> 8) & 0x1F;
            if ((!(pEntry->wFlags & 0x20) && nClass >= 4) || nClass >= 5)
            {
                sub_00439780_PickClass(nClass, pEntry->wFlags & 0x20);
                return 1;
            }
        }

        sub_00526F70(szName, pEntry->wszName, 0xFF);
        sub_00434A00_Join(pEntry, pEntry->wFlags, pEntry->nType, szName);
    }

    return 1;
}

// 0x0043F730
void __cdecl sub_0043F730()
{
    char szText[0x200];
    Unicode wszText[0x200];

    for (int i = 0; i < 0x200; i++)
        wszText[i].wChar = 0;

    if (!gpControlMain_0077BC4C)
        return;

    szText[0] = 0;
    int nLen = 0;
    for (D2LaunchNameNodeStrc* pNode = gpNameList_0077BDB4; pNode; pNode = pNode->pNext)
    {
        if (nLen >= 0x200)
            break;
        strncat(szText, pNode->szName, 0x200 - nLen);
        nLen = strlen(szText);
    }

    if (!szText[0])
        sub_004F9740_SetControlState(gpNamesButton_0077BD08, 1);
    else
        sub_004F9740_SetControlState(gpNamesButton_0077BD08, 0);

    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x200);
    sub_004FC9B0_SetText(gpControlMain_0077BC4C, wszText, 1, 0, 0);
}

// 0x004453B0
void __cdecl sub_004453B0_BuildPanel()
{
    Unicode wszNumber[3];
    char szNumber[4];
    char szLevel[100];
    Unicode wszLevel[0x64];
    Unicode wszText[0xC8];

    gpPanelControl_00798BEC = CONTROL_Create(&gtControlInit_0070D300);
    gpPanelTitle_00798BF0 = CONTROL_Create(&gtControlInit_0070EAA0);
    sub_004FD060_SetText(gpPanelTitle_00798BF0, D2LANG_GetStringFromTblIndex(0x141E));
    gpPanelText_00798BF4 = CONTROL_Create(&gtControlInit_0070EAD0);
    sub_004FD060_SetText(gpPanelText_00798BF4, D2LANG_GetStringFromTblIndex(0x2B0F));
    sub_004FCFF0_SetTextA(gpPanelText_00798BF4, gszSpace_006FFC44, 0);

    for (int i = 0; i < 0xC8; i++)
        wszText[i].wChar = 0;
    for (int i = 0; i < 0x64; i++)
        wszLevel[i].wChar = 0;

    sprintf(szLevel, "%d ", sub_00449E20());
    sub_00526320_ToUnicode(wszLevel, szLevel, 0x32);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x2B12));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9A));
    wszNumber[0].wChar = 0;
    wszNumber[1].wChar = 0;
    wszNumber[2].wChar = 0;
    wsprintfA(szNumber, gszFormatD_006D57BC, 0);
    sub_00526F20_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszLevel);
    sub_004FD060_SetText(gpPanelText_00798BF4, wszText);

    gpPanelControl_00798C48 = CONTROL_Create(&gtControlInit_0070EB30);
    sub_004FA450_SetActive(gpPanelControl_00798C48);
    gpCreateButton_00798C28 = CONTROL_Create(&gtControlInit_0070EB60);
    sub_0043DAD0_SetMainState(0);
}

// 0x00447870
void __fastcall sub_00447870_AppendNumberText(Unicode* pText, int nValue)
{
    Unicode wszNumber[3];
    char szNumber[4];
    Unicode wszBuffer[0x200];

    for (int i = 0; i < 0x200; i++)
        wszBuffer[i].wChar = 0;
    wszNumber[0].wChar = 0;
    wszNumber[1].wChar = 0;
    wszNumber[2].wChar = 0;
    sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
    wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszBuffer, wszNumber);

    if (!pText[0].wChar)
    {
        sub_005267E0(pText, wszBuffer);
    }
    else
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0xB7D);
        sub_00526700(pText, wszBuffer);
    }
}

// 0x00447940
void __fastcall sub_00447940_PrependNumberText(Unicode* pText, int nValue)
{
    Unicode wszNumber[3];
    char szNumber[4];
    Unicode wszBuffer[0x200];

    for (int i = 0; i < 0x200; i++)
        wszBuffer[i].wChar = 0;
    wszNumber[0].wChar = 0;
    wszNumber[1].wChar = 0;
    wszNumber[2].wChar = 0;
    sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
    wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszBuffer, wszNumber);

    if (!pText[0].wChar)
    {
        sub_005267E0(pText, wszBuffer);
    }
    else
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0xB9B);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
}

// 0x00448150
int __stdcall sub_00448150_PrintChannelText0(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 0);
    return 1;
}

// 0x004484E0
int __stdcall sub_004484E0_PrintChannelText3(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 3);
    return 1;
}

// 0x00448540
int __stdcall sub_00448540_PrintChannelText1(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 1);
    return 1;
}

// 0x004485A0
int __stdcall sub_004485A0_PrintFormattedText(int nUnused, const char* szText)
{
    char szBuffer[0x1F4];
    Unicode wszText[0x240];
    sprintf(szBuffer, "The channel \"%s\" is full. If you are having problems using Battle.net commands, please click the Help button.", szText);
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szBuffer, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 1);
    return 1;
}

// 0x00448610
int __stdcall sub_00448610_PrintFormattedText(int nUnused, const char* szText)
{
    char szBuffer[0x1F4];
    Unicode wszText[0x240];
    sprintf(szBuffer, "The channel \"%s\" is restricted. If you are having problems using Battle.net commands, please click the Help button.", szText);
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szBuffer, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 1);
    return 1;
}

#include "gen/data/Source/D2Client/0042F890_sub_0042F890_ShowProgressScreen.inc"
