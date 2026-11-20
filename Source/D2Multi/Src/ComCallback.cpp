#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CompositeUnitStrc;
struct D2WinEditBoxStrc;
struct Unicode;
struct D2LaunchNameNodeStrc;
struct D2LaunchCharInfoStrc;
struct D2MultiChannelUserStrc;
struct D2LaunchFuncsStrc;
struct ComAdStrc;

struct Unicode
{
    unsigned short wChar;
};

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
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strncat(char* szDest, const char* szSource, size_t nCount); // 0x00687490
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
int __stdcall sub_00435E00_Back(int nArg); // 0x00435E00
void __fastcall sub_00439780_PickClass(int nClass, int bExpansion); // 0x00439780
void __cdecl sub_0043C4F0(); // 0x0043C4F0
int __fastcall sub_0043DAD0_SetMainState(int bSet); // 0x0043DAD0
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor); // 0x0043E610
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText); // 0x00446A90
int __cdecl sub_00449E20(); // 0x00449E20
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
int __stdcall sub_004FD110_SetBarValue(D2WinControlStrc* pBar, int nValue); // 0x004FD110
int __stdcall sub_004FD170_SetBarMode(D2WinControlStrc* pBar, int nMode); // 0x004FD170
int __stdcall sub_004FD1B0_GetBarMax(D2WinControlStrc* pBar); // 0x004FD1B0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
extern D2WinControlInitStrc gtControlInit_0070D300; // 0x0070D300
extern D2WinControlInitStrc gtControlInit_0070EAA0; // 0x0070EAA0
extern D2WinControlInitStrc gtControlInit_0070EAD0; // 0x0070EAD0
extern D2WinControlInitStrc gtControlInit_0070EB30; // 0x0070EB30
extern D2WinControlInitStrc gtControlInit_0070EB60; // 0x0070EB60
extern int gnLaunchMode_007795EC; // 0x007795EC
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlStrc* gpNamesButton_0077BD08; // 0x0077BD08
extern D2LaunchNameNodeStrc* gpNameList_0077BDB4; // 0x0077BDB4
extern D2WinControlStrc* gpCreateButton_00798C28; // 0x00798C28

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    union
    {
        char szName0x8D[0x30];
        char szText0x8D[0x10];
    };
};

struct D2MultiChannelUserStrc
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x15];
    D2CompositeUnitStrc* f_9C;
    int nValue0xA0;
    int unk0xA4;
    int nValue0xA8;
    int unk0xAC;
    D2MultiChannelUserStrc* pNext;
};

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
int __fastcall sub_00440CA0(const char* szName, char* szA, char* szB, char* szC); // 0x00440CA0
void __cdecl sub_00443D50_CreateControls(); // 0x00443D50
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox); // 0x004F91C0
const char* __fastcall sub_00446820_SkipNamePrefix(const char* szName); // 0x00446820
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* pCompositeUnit); // 0x00505330
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags); // 0x00505360
void __cdecl sub_004477A0_Refresh(); // 0x004477A0
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern D2WinControlInitStrc gtControlInit_0070E680; // 0x0070E680
extern D2WinControlInitStrc gtControlInit_0070E6B0; // 0x0070E6B0
extern D2WinControlInitStrc gtControlInit_0070E6E0; // 0x0070E6E0
extern D2WinControlInitStrc gtControlInit_0070E710; // 0x0070E710
extern D2WinControlInitStrc gtControlInit_0070E740; // 0x0070E740
extern D2WinControlInitStrc gtControlInit_0070E770; // 0x0070E770
extern D2WinControlInitStrc gtControlInit_0070E7A0; // 0x0070E7A0
extern D2WinControlInitStrc gtControlInit_0070E7D0; // 0x0070E7D0
extern D2WinControlInitStrc gtControlInit_0070E800; // 0x0070E800
extern D2WinControlInitStrc gtControlInit_0070E830; // 0x0070E830
extern D2WinControlInitStrc gtControlInit_0070E920; // 0x0070E920
extern D2WinControlInitStrc gtControlInit_0070E950; // 0x0070E950
extern D2WinControlInitStrc gtControlInit_0070E980; // 0x0070E980
extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern D2WinControlStrc* gpControl_00798C64; // 0x00798C64
extern D2WinControlStrc* gpControl_00798C68; // 0x00798C68
extern D2WinControlStrc* gpControl_00798C6C; // 0x00798C6C
extern D2WinControlStrc* gpControl_00798C70; // 0x00798C70
extern D2WinControlStrc* gpControl_00798C78; // 0x00798C78
extern D2WinControlStrc* gpControl_00798C7C; // 0x00798C7C
extern D2WinControlStrc* gpControl_00798C8C; // 0x00798C8C
extern int gnSubmitMode_00798CAC; // 0x00798CAC
extern char gszName_00798CD4[]; // 0x00798CD4
extern int gnPendingValueA_00798CE4; // 0x00798CE4
extern int gnPendingValueB_00798CE8; // 0x00798CE8
extern D2MultiChannelUserStrc* gpSelectedChannelUser_00798F48; // 0x00798F48

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinEditBoxStrc* pEditBox); // 0x004FDD90
int __fastcall sub_004FF5A0(D2WinEditBoxStrc* pEditBox, const Unicode* pText); // 0x004FF5A0
int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper); // 0x004428D0
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void __cdecl sub_00448050_ClearSelectedUser(); // 0x00448050
extern D2WinEditBoxStrc* gpChatEditBox_0077BD94; // 0x0077BD94
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C

struct ComAdStrc
{
    void* pContext;
    int n04;
    char* szName;
    void* pData;
    void* pBuffer;
    unsigned long nSize;
};

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
extern void* gpLaunchContext_0077B0A4; // 0x0077B0A4
extern char gszTempFile_00798E30[]; // 0x00798E30
extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* lpBuffer); // 0x006CC344
extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(const char* lpPathName, const char* lpPrefixString, unsigned int uUnique, char* lpTempFileName); // 0x006CC340
void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut); // 0x00447560

D2WinControlStrc* gpProgressText_00779978; // 0x00779978

D2WinControlStrc* gpProgressBar_0077997C; // 0x0077997C

D2WinControlStrc* gpCharSelectText_00779DD4; // 0x00779DD4

int gbFlag_00779DD8; // 0x00779DD8

int gnCounter_00779DDC; // 0x00779DDC

D2WinControlStrc* gpPanelControl_00798BEC; // 0x00798BEC

D2WinControlStrc* gpPanelTitle_00798BF0; // 0x00798BF0

D2WinControlStrc* gpPanelText_00798BF4; // 0x00798BF4

D2WinControlStrc* gpPanelControl_00798C48; // 0x00798C48

#include "gen/data/Source/D2Multi/Src/ComCallback/s_nSelected_0070CC00.inc"

#include "gen/data/Source/D2Multi/Src/ComCallback/s_nSelectionA_0070CC04.inc"

#include "gen/data/Source/D2Multi/Src/ComCallback/s_nSelectionB_0070CC08.inc"

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
    D2Win_10044(gpPanelTitle_00798BF0, D2LANG_GetStringFromTblIndex(0x141E));
    gpPanelText_00798BF4 = CONTROL_Create(&gtControlInit_0070EAD0);
    D2Win_10044(gpPanelText_00798BF4, D2LANG_GetStringFromTblIndex(0x2B0F));
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
    D2Win_10044(gpPanelText_00798BF4, wszText);

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

#include "gen/data/Source/D2Multi/Src/ComCallback.inc"

int gbCheck_0077BD58; // 0x0077BD58

D2WinControlStrc* gpControl_00798C74; // 0x00798C74

D2WinControlStrc* gpSubmitEditA_00798C80; // 0x00798C80

D2WinControlStrc* gpSubmitEditB_00798C84; // 0x00798C84

D2WinControlStrc* gpSubmitEditC_00798C88; // 0x00798C88

D2WinControlStrc* gpControl_00798CA0; // 0x00798CA0

D2WinControlStrc* gpControl_00798CA4; // 0x00798CA4

// 0x00443D10
static __declspec(noinline) void __stdcall sub_00443D10_SetPendingName(int nA, int nB, const char* szText)
{
    strcpy(gszName_00798CD4, szText);
    gnPendingValueA_00798CE4 = nA;
    gnPendingValueB_00798CE8 = nB;
}

// 0x00445A80
void __fastcall sub_00445A80_ShowProfileDialog(const char* szText, int nA, int nB)
{
    const char* szName = gpCharInfo_0077BBD8->szName0x8D;
    char szA[12];
    char szB[44];
    char szC[204];

    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    if (!sub_00440CA0(szName, szA, szB, szC))
    {
        return;
    }

    sub_0043F8C0_ResetLaunchState();
    gnSubmitMode_00798CAC = 2;
    gpControl_00798C78 = CONTROL_Create(&gtControlInit_0070E680);
    gpControl_00798C7C = CONTROL_Create(&gtControlInit_0070E6B0);
    sub_004FCF80_SetTextA(gpControl_00798C7C, szName);
    gpSubmitEditA_00798C80 = CONTROL_Create(&gtControlInit_0070E6E0);
    sub_004FFE10_SetTextA(gpSubmitEditA_00798C80, szA);
    sub_004FDD50_SetMaxLength(gpSubmitEditA_00798C80, 8);
    gpSubmitEditB_00798C84 = CONTROL_Create(&gtControlInit_0070E710);
    sub_004FFE10_SetTextA(gpSubmitEditB_00798C84, szB);
    sub_004FDD50_SetMaxLength(gpSubmitEditB_00798C84, 0x28);
    gpSubmitEditC_00798C88 = CONTROL_Create(&gtControlInit_0070E740);
    sub_004FFE10_SetTextA(gpSubmitEditC_00798C88, szC);
    sub_004FDD50_SetMaxLength(gpSubmitEditC_00798C88, 0xC8);
    gpControl_00798C8C = CONTROL_Create(&gtControlInit_0070E920);
    sub_004FA450_SetActive(gpControl_00798C8C);
    gpControl_00798CA0 = CONTROL_Create(&gtControlInit_0070E950);
    if (!gbCheck_0077BD58)
    {
        gpControl_00798CA4 = CONTROL_Create(&gtControlInit_0070E980);
    }
    sub_00443D50_CreateControls();
    sub_004FDDD0_LinkTab(gpSubmitEditC_00798C88, gpSubmitEditA_00798C80);
    sub_004FDDD0_LinkTab(gpSubmitEditA_00798C80, gpSubmitEditB_00798C84);
    sub_004FDDD0_LinkTab(gpSubmitEditB_00798C84, gpSubmitEditC_00798C88);
    if (!szA[0] && !szB[0] && !szC[0])
    {
        sub_004F91C0(gpSubmitEditA_00798C80);
    }
    else
    {
        sub_004F91C0(gpSubmitEditC_00798C88);
        D2Win_10082(gpSubmitEditC_00798C88);
    }
    sub_00443D10_SetPendingName(nA, nB, szText);
}

// 0x00445C70
void __fastcall sub_00445C70_ShowUserInfoDialog(const char* szUser, const char* szText, int nA, int nB)
{
    const char* szName = sub_00446820_SkipNamePrefix(szUser);
    char szA[12];
    char szB[44];
    char szC[204];

    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    if (!sub_00440CA0(szName, szA, szB, szC))
    {
        return;
    }

    sub_0043F8C0_ResetLaunchState();
    gnSubmitMode_00798CAC = 1;
    gpControl_00798C64 = CONTROL_Create(&gtControlInit_0070E770);
    gpControl_00798C68 = CONTROL_Create(&gtControlInit_0070E7A0);
    sub_004FCF80_SetTextA(gpControl_00798C68, szName);
    gpControl_00798C6C = CONTROL_Create(&gtControlInit_0070E7D0);
    sub_004FCF80_SetTextA(gpControl_00798C6C, szA);
    gpControl_00798C70 = CONTROL_Create(&gtControlInit_0070E800);
    sub_004FCF80_SetTextA(gpControl_00798C70, szB);
    gpControl_00798C74 = CONTROL_Create(&gtControlInit_0070E830);
    char szDelim[] = "\r\n";
    char* szLine = strtok(szC, szDelim);
    while (szLine)
    {
        sub_004FCF80_SetTextA(gpControl_00798C74, szLine);
        szLine = strtok(0, szDelim);
    }
    gpControl_00798CA0 = CONTROL_Create(&gtControlInit_0070E950);
    sub_004FA450_SetActive(gpControl_00798CA0);
    if (!gbCheck_0077BD58)
    {
        gpControl_00798CA4 = CONTROL_Create(&gtControlInit_0070E980);
    }
    sub_00443D50_CreateControls();
    sub_0043D990();
    sub_00443D10_SetPendingName(nA, nB, szText);
}

// 0x00448050
void __cdecl sub_00448050_ClearSelectedUser()
{
    if (gpSelectedChannelUser_00798F48)
    {
        D2_ASSERT(gpSelectedChannelUser_00798F48->f_9C, 0x85A);
        const unsigned int nFlags = D2Win_10155(gpSelectedChannelUser_00798F48->f_9C);
        D2Win_10156(gpSelectedChannelUser_00798F48->f_9C, nFlags & gdwInvBitMasks[10]);
        gpSelectedChannelUser_00798F48 = 0;
        gnSelectedLine_0070EC1C = -1;
    }

    if (!sub_0043DB10())
    {
        sub_004477A0_Refresh();
    }
}

static unsigned long s_dwLastCommandTick_00798F50; // 0x00798F50

// 0x004468F0
int __stdcall sub_004468F0_SendChatLine(int nUnused)
{
    char szText[0x100];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (!wszText || !sub_00526800(wszText))
    {
        return 1;
    }

    sub_00526F70(szText, wszText, sizeof(szText));
    return sub_004428D0_SendChatText(szText, 1);
}

// 0x00446970
int __stdcall sub_00446970_SendEmoteLine(int nUnused)
{
    char szText[0x12C];
    char szLine[0x12C];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (wszText && sub_00526800(wszText))
    {
        sub_00526F70(szText, wszText, sizeof(szText));
        if (szText[0] != '/')
        {
            const unsigned long dwTick = GetTickCount();
            if (dwTick >= s_dwLastCommandTick_00798F50 + 1000)
            {
                s_dwLastCommandTick_00798F50 = dwTick;
                sprintf(szLine, "/me %s", szText);
                sub_004428D0_SendChatText(szLine, 0);
            }
        }
    }
    return 1;
}

// 0x00448E30
int __stdcall sub_00448E30_SquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser_00798F48)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser_00798F48->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < s_dwLastCommandTick_00798F50 + 1000)
    {
        return 1;
    }

    s_dwLastCommandTick_00798F50 = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/squelch *%s", pName);
    sub_00448050_ClearSelectedUser();
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
    sub_004FF5A0(gpChatEditBox_0077BD94, 0);
    pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    if (SStrCmpI(pName, gpCharInfo_0077BBD8->szText0x8D, 0x7FFFFFFF))
    {
        sub_00611560_GetSquelchList()->Squelch(szName);
    }
    return 1;
}

// 0x00448F60
int __stdcall sub_00448F60_UnsquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser_00798F48)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser_00798F48->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < s_dwLastCommandTick_00798F50 + 1000)
    {
        return 1;
    }

    s_dwLastCommandTick_00798F50 = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/unsquelch *%s", pName);
    sub_00448050_ClearSelectedUser();
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
    sub_004FF5A0(gpChatEditBox_0077BD94, 0);
    sub_00611560_GetSquelchList()->Unsquelch(szName);
    return 1;
}

D2WinSmackStrc* gpControl_0077B098; // 0x0077B098

// 0x00446B70
static int sub_00446B70_Func(ComAdStrc* pAd)
{
    char szTempFile[260];
    char szTempPath[260];
    unsigned long nWritten;

    SMACK_DeleteFile(gpControl_0077B098);
    if (!GetTempPathA(260, szTempPath))
    {
        *(unsigned short*)szTempPath = '.';
    }
    if (GetTempFileNameA(szTempPath, "BNetAd", 0, szTempFile) > 0)
    {
        DeleteFileA(gszTempFile_00798E30);
        void* hFile = sub_00406960_CreateFile(szTempFile, 0x40000000, 0, 0, 4, 0x8000000, 0);
        if (hFile != (void*)-1)
        {
            sub_004069D0_WriteFile(hFile, pAd->pBuffer, pAd->nSize, &nWritten, 0);
            sub_004069A0_CloseFile(hFile);
        }
        char* pExt = strrchr(pAd->szName, '.');
        pExt++;
        int ch = *pExt;
        int n = tolower(ch);
        SMACK_Decode(gpControl_0077B098, szTempFile, n);
        int i = 0;
        char c;
        do
        {
            c = szTempFile[i];
            gszTempFile_00798E30[i] = c;
            i++;
        } while (c);
    }
    gpLaunchContext_0077B0A4 = pAd->pContext;
    FOG_Free(pAd->szName, ".\\Src\\ComCallback.cpp", 0x386, 0);
    FOG_Free(pAd->pData, ".\\Src\\ComCallback.cpp", 0x387, 0);
    return 1;
}

int __cdecl sub_00447A10_Pump(int n)
{
    ComAdStrc ad;
    return sub_00446B70_Func(&ad);
}

static const char* SkipStarPrefix_Inl(const char* szName)
{
    const char* p = SStrChr(szName, '*');
    if (p)
    {
        p++;
        if (*p)
        {
            return p;
        }
    }
    return szName;
}

// 0x00448A60
static void sub_00448A60_PrintWhisperSent(const char* szName, const char* szText)
{
    char szLine[0x1F4];
    Unicode wszLine[0x240];
    sprintf(szLine, "You whisper to %s: %s", szName, szText);
    for (int i = 0; i < 0x240; i++)
        wszLine[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszLine, szLine, 0x240);
    sub_00446A90_RemoveTableString(wszLine);
    sub_0043E610_PrintText(wszLine, 2);
}

// 0x00448AD0
int __stdcall sub_00448AD0_OnWhisperSent(const char* szTarget, const char* szText)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    sub_00447560_SplitName(szTarget, szTitle, szName);
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szAccount, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szAccount, szName);
        }
        sub_00448A60_PrintWhisperSent(szAccount, szText);
    }
    else
    {
        sub_00448A60_PrintWhisperSent(SkipStarPrefix_Inl(szTarget), szText);
    }
    return 1;
}
