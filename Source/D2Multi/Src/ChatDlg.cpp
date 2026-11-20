#include "D2Multi.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2LaunchRecord3Strc;
struct D2LaunchFuncsStrc;
struct D2LaunchCharInfoStrc;
struct D2LaunchThreadRecordStrc;
struct D2ChatMessageStrc;
struct D2LaunchNameNodeStrc;

struct D2LaunchRecord3Strc
{
    int nValue0;
    int nValue1;
    int f_8;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x04];
    int (__fastcall* pfn0x1C)(int nA, int nB, int nC);
    char unk0x20[0x48];
    int (__fastcall* pfn0x68)();
    char unk0x6C[0x08];
    int (__fastcall* pfn0x74)(int nA, int nB, void* pKey, D2LaunchRecord3Strc* pRecord);
    char unk0x78[0x04];
    int (__fastcall* pfn0x7C)(int nA, int nB, void* pKey, D2LaunchRecord3Strc* pRecord);
    char unk0x80[0x0C];
    int (__fastcall* pfn0x8C)(int* pOut);
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    char wFlags[2];
    char unk0x1F1[0x3C];
    char bOnline;
    char unk0x22E[0x17];
    char szText0x245[0x10];
    unsigned char unk_255[0x10C];
    char nByte361;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940
int __fastcall sub_004F9190(); // 0x004F9190
void __cdecl sub_0043FBD0_Refresh(); // 0x0043FBD0
int __fastcall sub_0044AAE0_SendSelect(const char* szName, int nB, int nC); // 0x0044AAE0
int __fastcall sub_0044A2E0_Forward3(int nA, int nB, int nC); // 0x0044A2E0
int __fastcall sub_0044A380_Forward1(int nA); // 0x0044A380
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA); // 0x00449050
unsigned long __stdcall sub_0044A070_ThreadProc(void* pParameter); // 0x0044A070
extern char gnSelectModeA_0070CD62; // 0x0070CD62
extern char gKey_0070CD54; // 0x0070CD54
extern char gszSelectName_0077B040[]; // 0x0077B040
extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070
extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern char gKey_0077B0A8; // 0x0077B0A8
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern unsigned short gwSavedRequestId_0077BBDC; // 0x0077BBDC
extern int gnLaunchMode_0077BBE4; // 0x0077BBE4
extern int gbCheck_0077BD58; // 0x0077BD58
extern int gbSelectActive_0077BD00; // 0x0077BD00
extern unsigned long gdwSelectTime_0077BD5C; // 0x0077BD5C
extern int gbDone_0077BDA0; // 0x0077BDA0
extern int gnValue_00798F5C; // 0x00798F5C
extern int gnValue_00798F7C; // 0x00798F7C
extern int gnValue_00798F84; // 0x00798F84
extern D2LaunchThreadRecordStrc gtThreadRecord_00798FB8; // 0x00798FB8
extern int gnValue_00799100; // 0x00799100
extern int gnValue_00799104; // 0x00799104
extern int gnValue_00799298; // 0x00799298
extern int gnValue_0079929C; // 0x0079929C
extern int gnValue_007992A0; // 0x007992A0
extern void* ghThread_007992A4; // 0x007992A4
extern int gnValue_007992A8; // 0x007992A8
extern int gnValue_007992E0; // 0x007992E0
extern int gnValue_007992E8; // 0x007992E8
extern int gnValue_007992F0; // 0x007992F0

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};
extern "C" unsigned int __cdecl strlen(const char* szString);
extern D2CriticalSectionStrc gtChatLock_0077AE28; // 0x0077AE28
extern D2ChatMessageStrc* gpChatQueueHead_0077BDAC; // 0x0077BDAC
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C
extern D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
void __fastcall sub_004423B0_RunCommand(char* szText); // 0x004423B0
void __fastcall sub_004481F0_PrintOwnLine(const char* szText); // 0x004481F0
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __fastcall sub_004FB910_GetLineCount(D2WinControlStrc* pTextBox); // 0x004FB910
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern int gbChatSetup_0077BBF8; // 0x0077BBF8
extern D2WinControlStrc* gpClassButtons_0077BC98[8]; // 0x0077BC98
extern int gbExpansionClasses_0070CD70; // 0x0070CD70
extern char gszChatBuffer_0077AE40[0x200]; // 0x0077AE40
extern D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94
extern int gnGlobal_0077B0A0; // 0x0077B0A0
extern int gnGlobal_0077AD70; // 0x0077AD70
extern int gnGlobal_0070CD7C; // 0x0070CD7C
extern unsigned char gbGlobal_0070CD63; // 0x0070CD63
extern unsigned char gbGlobal_0070CD62; // 0x0070CD62
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall sub_004FCC40_AddLine(D2WinControlStrc* pControl, const Unicode* pText, int nColor, int nA, int nB); // 0x004FCC40
extern "C" const char gszDash_006CCA2C[]; // 0x006CCA2C
extern int gnColor_0077AD74; // 0x0077AD74
extern int gnSelection_0077BBF4; // 0x0077BBF4
extern D2WinControlStrc* gpList_0077BD00; // 0x0077BD00

struct D2LaunchNameNodeStrc
{
    char szName[0x200];
    int nId;
    D2LaunchNameNodeStrc* pNext;
};

extern D2LaunchNameNodeStrc* gpNameList_0077BDB4; // 0x0077BDB4
void __cdecl sub_0043F730(); // 0x0043F730

D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C

int gbPending_0077BD9C; // 0x0077BD9C

D2LaunchCallback gpfnLaunchCallback_0077BDA4; // 0x0077BDA4

int gnResult_00798F58; // 0x00798F58

char gszText_00798F60[28]; // 0x00798F60

char gszText_00799294[4]; // 0x00799294

// 0x0043D9B0
int __stdcall sub_0043D9B0_NextRequestCallback(int nArg)
{
    while (++gwRequestId_0070CD60 == 0)
    {
    }
    gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043EB10
int __stdcall sub_0043EB10_RunCallback(int nArg)
{
    if (gpfnLaunchCallback_0077BDA4)
        gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043EC60
void __fastcall sub_0043EC60_SelectEntry(const char* szName, int nB, int nC)
{
    if (!gbSelectActive_0077BD00)
        return;
    SStrCopy(gszSelectName_0077B040, szName, 0x7FFFFFFF);
    char nMode;
    if (nC)
        nMode = nB ? 0x13 : 0x1B;
    else
        nMode = nB ? 0 : 9;
    gnSelectModeA_0070CD62 = nMode;
    gnSelectModeB_0070CD63 = nMode;
    gnSelectIdA_0070CD7C = -1;
    gnSelectIdB_0070CD80 = -1;
    sub_0044AAE0_SendSelect(szName, nB, nC);
    gdwSelectTime_0077BD5C = GetTickCount() + 1000;
}

// 0x0043F590
int __stdcall sub_0043F590_CallTable7C(int nUnused)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = 8;
    tRecord.nValue1 = 0x28;
    tRecord.f_8 = 0xC8;
    if (gpLaunchFuncs_0077B09C->pfn0x7C(3, 1, &gKey_0077B0A8, &tRecord) || gbFlag_0077ADA4)
        sub_004F9190();
    return 1;
}

// 0x0043F5F0
int __fastcall sub_0043F5F0_CallTable74(int nA, int nB, int nC, int nD)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = nB;
    tRecord.nValue1 = nC;
    tRecord.f_8 = nD;
    return gpLaunchFuncs_0077B09C->pfn0x74(nA, 3, &gKey_0070CD54, &tRecord);
}

// 0x0043F930
int __stdcall sub_0043F930_SetCallback(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
    sub_0043F8C0_ResetLaunchState();
    gpfnLaunchCallback_0077BDA4 = pfnCallback;
    return 1;
}

// 0x0043FFA0
int __fastcall sub_0043FFA0_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37)
{
    gnLaunchMode_0077BBE4 = 2;
    sub_0043F930_SetCallback(0, sub_0043DAF0_OnConnect);
    *(unsigned short*)gpCharInfo_0077BBD8->wValue = wValue;
    strcpy(gpCharInfo_0077BBD8->szText0x1F, szText0x1F);
    strcpy(gpCharInfo_0077BBD8->szText0x245, szText0x245);
    if (gpCharInfo_0077BBD8->bOnline)
    {
        if (sub_00449B30_QueryAddress())
        {
            *(int*)gpCharInfo_0077BBD8->nState = 3;
            while (++gwRequestId_0070CD60 == 0)
            {
            }
            sub_0044A4E0_SendConnect(szText0x1F, szText0x245, gwRequestId_0070CD60);
            gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
            return 1;
        }
        gnLaunchMode_0077BBE4 = 0;
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
        return 0;
    }
    *(int*)gpCharInfo_0077BBD8->nState = 7;
    strcpy(gpCharInfo_0077BBD8->szText0x37, szText0x37);
    gbDone_0077BDA0 = 1;
    sub_004F9160_SetLoopValue(0);
    sub_004F9190();
    return 1;
}

// 0x004413E0
void __stdcall sub_004413E0_Enable(int bEnable)
{
    if (bEnable)
    {
        if (!sub_00449B30_QueryAddress())
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return;
        }
        gnLaunchMode_0077BBE4 = 0;
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        if (gpControlMain_0077BC4C)
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
        return;
    }
    if (!gnLaunchMode_0077BBE4 && gbPending_0077BD9C)
        sub_0043F8C0_ResetLaunchState();
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        sub_004F96F0_ControlClearState(gpControlA_0077B070, 1);
        sub_004F96F0_ControlClearState(gpControlB_0077B078, 1);
    }
    sub_004F96F0_ControlClearState(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
}

// 0x00442B20
int __fastcall sub_00442B20_IsCharOverLimit(const unsigned char* pChar)
{
    unsigned char nChar = *pChar;
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    const int nLimit = ((wFlags >> 8) & 0x1F) / 5 + 1;
    if (wFlags & 4)
    {
        if (nChar - '3' > nLimit || nChar < '3')
            return 1;
        return 0;
    }
    return nChar - '0' > nLimit;
}

// 0x00443600
int __stdcall sub_00443600_IsPrintableChar(int nA, int nB, const char* pChar)
{
    const char nChar = *pChar;
    if (nChar >= 0x20 && nChar < 0x80)
        return 1;
    return 0;
}

// 0x00443840
int __stdcall sub_00443840_CallTable8C(int nUnused)
{
    int nOut;
    if (gpLaunchFuncs_0077B09C->pfn0x8C(&nOut))
        sub_004F9190();
    return 1;
}

// 0x00446810
char* __cdecl sub_00446810_StrChr(const char* szString, int nChar)
{
    return strchr(szString, nChar);
}

// 0x00446A90
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText)
{
    D2_ASSERT(sub_00526800(pText) < 500, 0x300);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nPatternLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_FindSubstring(pText, pPattern);
    while (pFound && pFound[nPatternLength].wChar)
    {
        memmove(pFound, &pFound[nPatternLength + 1], (sub_00526800(pFound) - nPatternLength) * sizeof(Unicode));
        pFound = sub_00526940_FindSubstring(pText, pPattern);
    }
}

// 0x00447700
int __fastcall sub_00447700_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    gpLaunchFuncs_0077B09C->pfn0x1C(nLength, 1, 0);
    sub_0043FBD0_Refresh();
    return 1;
}

// 0x00449330
int __fastcall sub_00449330_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    sub_00449050_AddEntry(szText, nLength, nA);
    return 1;
}

// 0x004497F0
void __fastcall sub_004497F0_MixChar(char* pChar, int nBits, unsigned int* pPool)
{
    *pChar = (char)toupper(*pChar);
    if (*pChar <= '7')
    {
        *pChar ^= *pPool & 7;
        *pPool >>= 3;
    }
    else if (*pChar < 'A')
    {
        *pChar ^= nBits & 1;
    }
}

// 0x00449BF0
void __stdcall sub_00449BF0_SetValue(int nValue)
{
    gnValue_0079929C = nValue;
}

// 0x00449C20
void __stdcall sub_00449C20_SetValue(int nValue)
{
    gnValue_007992E8 = nValue;
}

// 0x00449C40
void __stdcall sub_00449C40_SetValue(int nValue)
{
    gnValue_007992E0 = nValue;
}

// 0x00449C60
void __stdcall sub_00449C60_SetValue(int nValue)
{
    gnValue_00799298 = nValue;
}

// 0x00449C80
void __stdcall sub_00449C80_SetValue(int nValue)
{
    gnValue_007992F0 = nValue;
}

// 0x00449C90
void __stdcall sub_00449C90_SetValue(int nValue)
{
    gnValue_00799100 = nValue;
}

// 0x00449CC0
void __stdcall sub_00449CC0_SetValue(int nValue)
{
    gnValue_007992A0 = nValue;
}

// 0x00449CD0
int __stdcall sub_00449CD0_GetTexts(char* szText1, char* szText2)
{
    strcpy(szText1, gszText_00799294);
    strcpy(szText2, gszText_00798F60);
    return gnResult_00798F58;
}

// 0x00449D10
void __stdcall sub_00449D10_SetTexts(int nResult, const char* szText1, const char* szText2)
{
    strcpy(gszText_00799294, szText1);
    strcpy(gszText_00798F60, szText2);
    gnResult_00798F58 = nResult;
}

// 0x00449D90
void __stdcall sub_00449D90_SetValue(int nValue)
{
    gnValue_007992A8 = nValue;
}

// 0x00449DB0
void __stdcall sub_00449DB0_SetValue(int nValue)
{
    gnValue_00798F5C = nValue;
}

// 0x00449DD0
void __stdcall sub_00449DD0_SetValue(int nValue)
{
    gnValue_00798F84 = nValue;
}

// 0x00449DF0
int __stdcall sub_00449DF0_Forward3(int nA, int nB, int nC)
{
    return sub_0044A2E0_Forward3(nA, nB, nC);
}

// 0x00449E10
int __stdcall sub_00449E10_Forward1(int nA)
{
    return sub_0044A380_Forward1(nA);
}

// 0x00449E30
void __stdcall sub_00449E30_SetValue(int nValue)
{
    gnValue_00799104 = nValue;
}

// 0x00449E50
void __stdcall sub_00449E50_SetValue(int nValue)
{
    gnValue_00798F7C = nValue;
}

// 0x0044A130
void __stdcall sub_0044A130_StartThread(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghThread_007992A4)
    {
        gtThreadRecord_00798FB8 = *pRecord;
        unsigned long nThreadId;
        ghThread_007992A4 = CreateThread(0, 0, sub_0044A070_ThreadProc, 0, 0, &nThreadId);
    }
}

#include "gen/data/Source/D2Multi/Src/ChatDlg.inc"

D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C

// 0x0043E1A0
static void __stdcall sub_0043E1A0_AddTextLines(D2WinControlStrc* pControl, int bBlankLine, char* szText, int nColor)
{
    char* pText = szText;
    const int nLength = strlen(szText);
    if (nLength > 0)
    {
        while (*pText)
        {
            char* pBreak = 0;
            char* pLine = pText;
            while (*pText != '\n' && *pText)
            {
                pText++;
            }
            if (*pText == '\n')
            {
                pBreak = pText;
                *pText = 0;
                pText++;
            }
            sub_004FCFF0_SetTextA(pControl, pLine, nColor);
            if (bBlankLine)
            {
                sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
            }
            if (pBreak)
            {
                *pBreak = '\n';
            }
        }
    }
    else
    {
        sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
    }
}

static D2ChatMessageStrc* sub_0043E370()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock_0077AE28);
    if (gpChatQueueHead_0077BDAC)
    {
        pMessage = gpChatQueueHead_0077BDAC;
        gpChatQueueHead_0077BDAC = gpChatQueueHead_0077BDAC->pNext;
    }
    LeaveCriticalSection(&gtChatLock_0077AE28);
    return pMessage;
}

static void sub_0043E2E0(D2ChatMessageStrc* pMessage)
{
    if (pMessage)
    {
        if (pMessage->szText)
        {
            FOG_Free(pMessage->szText, ".\\Src\\ChatDlg.cpp", 0xC38, 0);
        }
        FOG_Free(pMessage, ".\\Src\\ChatDlg.cpp", 0xC39, 0);
    }
}

// 0x0043E3A0
void __cdecl sub_0043E3A0_FlushChatMessages()
{
    for (;;)
    {
        D2ChatMessageStrc* pMessage = sub_0043E370();
        if (!pMessage)
        {
            return;
        }
        if (pMessage->bClear)
        {
            sub_004FB6A0_ClearText(gpChatTextBox_0077BD8C);
        }
        if (pMessage->szText)
        {
            sub_0043E1A0_AddTextLines(gpChatTextBox_0077BD8C, 0, pMessage->szText, pMessage->nColor);
        }
        sub_0043E2E0(pMessage);
        D2Win_10053(gpChatTextBox_0077BD8C, 0);
    }
}

// 0x0043E5F0
int __fastcall sub_0043E5F0_PrintMessage(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E610
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E630
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText)
{
    if (gpControl_0077BD98)
    {
        sub_004FB6A0_ClearText(gpControl_0077BD98);
        sub_004FC9B0_SetText(gpControl_0077BD98, pText, 3, 0, 0);
    }

    return 1;
}

// 0x0043EBA0
int __cdecl sub_0043EBA0_ResetControls()
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        sub_004F96F0_ControlClearState(gpControlA_0077B070, 1);
        sub_004F96F0_ControlClearState(gpControlB_0077B078, 1);
    }
    if (gpCharInfo_0077BBD8->nByte361)
        sub_004F96F0_ControlClearState(gpChatControl_0077B074, 1);
    else
        sub_004F96F0_ControlClearState(gpChatControl_0077B074, gbChatSetup_0077BBF8 == 0);
    sub_004F96F0_ControlClearState(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    return 1;
}

// 0x0043F060
void __cdecl sub_0043F060_ReleaseClassButtons()
{
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[0], 0);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[1], 0);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[2], 0);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[3], 0);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[4], 0);
    BUTTON_SetIsPressed(gpClassButtons_0077BC98[5], 0);
    if (gbExpansionClasses_0070CD70)
    {
        BUTTON_SetIsPressed(gpClassButtons_0077BC98[6], 0);
        BUTTON_SetIsPressed(gpClassButtons_0077BC98[7], 0);
    }
}

// 0x00442810
int __cdecl sub_00442810_SendChatBuffer()
{
    if (gszChatBuffer_0077AE40[0] == '/')
    {
        sub_004423B0_RunCommand(gszChatBuffer_0077AE40);
    }
    else
    {
        if (!gpLaunchFuncs_0077B09C->pfn0x68())
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return 1;
        }
        gpLaunchFuncs_0077B09C->pfn0x14(gszChatBuffer_0077AE40);
        sub_004481F0_PrintOwnLine(gszChatBuffer_0077AE40);
    }
    sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
    const int nFirst = D2Win_10055(gpChatTextBox_0077BD8C);
    const int nCount = sub_004FB910_GetLineCount(gpChatTextBox_0077BD8C);
    if (nCount > nFirst)
        D2Win_10053(gpChatTextBox_0077BD8C, nCount - nFirst);
    return 1;
}

// 0x0043ED10
int __stdcall sub_0043ED10_UpdateCounter(int nUnused)
{
    int nBase = gnGlobal_0077B0A0;
    int nOther = gnGlobal_0077AD70;
    int nCurrent = gnGlobal_0070CD7C;
    int nDifference = nOther - nBase;
    int nCombined = nBase + nCurrent;
    if (nCombined < nDifference)
        nDifference = nCombined;
    gbGlobal_0070CD62 = gbGlobal_0070CD63;
    gnGlobal_0070CD7C = nDifference;
    return 1;
}

// 0x0043F0E0
void __cdecl sub_0043F0E0()
{
    sub_004FB6A0_ClearText(gpList_0077BD00);
    char szText[2];
    Unicode wszText[2] = { Unicode(0), Unicode(0) };
    sprintf(szText, gszDash_006CCA2C);
    sub_00526F20_ToUnicode(wszText, szText, 2);
    sub_004FCC40_AddLine(gpList_0077BD00, wszText, gnColor_0077AD74, 4, 0);
    D2Win_10053(gpList_0077BD00, 0);
    gnSelection_0077BBF4 = -2;
}

// 0x0043F800
void __cdecl sub_0043F800_FreeNameList()
{
    D2LaunchNameNodeStrc* pNode = gpNameList_0077BDB4;
    while (pNode)
    {
        D2LaunchNameNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\ChatDlg.cpp", 0x1C01, 0);
        pNode = pNext;
    }
    gpNameList_0077BDB4 = 0;
}

// 0x0043F8A0
static __forceinline void sub_0043F8A0_SaveDefaultChannel(const char* szChannel)
{
    SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
}

void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    sub_0043F8A0_SaveDefaultChannel(szFirst);
    sub_0043F8A0_SaveDefaultChannel(szSecond);
}

D2LaunchNameNodeStrc* gpNameList_0077BDB4; // 0x0077BDB4

// 0x00440D10
void __fastcall sub_00440D10(int nPlayerId, int nDataLength, const char* szName)
{
    D2LaunchNameNodeStrc* pNode;
    for (pNode = gpNameList_0077BDB4; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nPlayerId)
            break;
    }

    if (!pNode)
    {
        pNode = (D2LaunchNameNodeStrc*)FOG_Alloc(sizeof(D2LaunchNameNodeStrc), ".\\Src\\ChatDlg.cpp", 0x1BAE, 0);
        D2LaunchNameNodeStrc* pCur = gpNameList_0077BDB4;
        pNode->nId = nPlayerId;
        if (!pCur || pCur->nId > nPlayerId)
        {
            pNode->pNext = pCur;
            gpNameList_0077BDB4 = pNode;
        }
        else
        {
            D2LaunchNameNodeStrc* pPrev = pCur;
            do
            {
                if (pCur->nId >= nPlayerId)
                    break;
                pPrev = pCur;
                pCur = pCur->pNext;
            }
            while (pCur);
            pNode->pNext = pCur;
            pPrev->pNext = pNode;
        }
    }

    SStrCopy(pNode->szName, szName, sizeof(pNode->szName));
    sub_0043F730();
}
