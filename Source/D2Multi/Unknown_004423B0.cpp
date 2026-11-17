#include "D2Multi.h"
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch)
    {
    }
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    void (__fastcall* pfn0x14)(const char* szText);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    char szText0x8D[0x10];
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
    virtual int GetPersist();
    virtual void SetPersist(int bPersist);
};
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax);                                      // 0x004135D0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
void __fastcall sub_004411E0_Use(const char* szText);                                                       // 0x004411E0
void __fastcall sub_0043E5F0_PrintMessage(const Unicode* pText, int nColor);                                // 0x0043E5F0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

extern char gaszHistory_0077B1D8[10][0x100];                                                                // 0x0077B1D8
extern int gnHistoryCount_0077BD50;                                                                         // 0x0077BD50
extern int gbShowJoinLeave_0077BD54;                                                                        // 0x0077BD54
extern D2WinControlStrc* gpChatTextBox_0077BD8C;                                                            // 0x0077BD8C
extern char gszLastWhisperer_0077B0D0[];                                                                    // 0x0077B0D0
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern "C" const char gszCmdIgnorePersist_006D56B0[];                                                       // 0x006D56B0
extern "C" const char gszCmdIgnore_006D56A4[];                                                              // 0x006D56A4
extern "C" const char gszCmdUnignore_006D568C[];                                                            // 0x006D568C
extern "C" const char gszCmdFilter_006D5674[];                                                              // 0x006D5674
extern "C" const char gszCmdUnfilter_006D5664[];                                                            // 0x006D5664

// 0x0043E6E0
static int __stdcall sub_0043E6E0_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

// @ref 0x0043E780
// 0x0043E780
static int sub_0043E780_NotifyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0043E6E0_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        if (!sub_0043E6E0_CompareCommand(szText, szCommand))
        {
            char szMessage[0x100];
            unsigned short wszMessage[0x100];
            gbShowJoinLeave_0077BD54 = !gbShowJoinLeave_0077BD54;
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            if (gbShowJoinLeave_0077BD54)
                strcpy(szMessage, "Player entering/leaving notifications are enabled.");
            else
                strcpy(szMessage, "Player entering/leaving notifications are disabled.");
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x200);
            if (gpChatTextBox_0077BD8C)
                sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, (Unicode*)wszMessage, 3, 0, 1);
        }
        return 1;
    }
    return 0;
}

// 0x0043F510
static void sub_0043F510_PushHistory(const char* szText)
{
    memmove(gaszHistory_0077B1D8[1], gaszHistory_0077B1D8[0], 0x900);
    strcpy(gaszHistory_0077B1D8[0], szText);
    if (++gnHistoryCount_0077BD50 >= 10)
        gnHistoryCount_0077BD50 = 10;
}

// 0x0043F870
static void __stdcall sub_0043F870_GetArgument(int nSize, const char* szText, char* szDest)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

static __declspec(noinline) int sub_00442180_ReplyCommand(const char* szText, const char* szCommand);

// build: context CONSOLE_FindSecondTokenInline
// calling-convention shim (not game code)
static __forceinline int CONSOLE_FindSecondTokenInline(const char* szText, char* szCopy, const char** ppArg)
{
    strcpy(szCopy, szText);
    char szDelim[2] = " ";
    char* pToken = strtok(szCopy, szDelim);
    int nCount = 0;
    while (pToken)
    {
        if (++nCount == 2)
        {
            *ppArg = szText + (pToken - szCopy);
            return 1;
        }
        pToken = strtok(0, szDelim);
    }
    return 0;
}

// 0x00442180
static int sub_00442180_ReplyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0043E6E0_CompareCommand(szText, szCommand))
    {
        if (szText[nLength] == ' ' || !szText[nLength])
        {
            char szMessage[260];
            if (!strlen(gszLastWhisperer_0077B0D0))
            {
                Unicode wszMessage[0x100] = {};
                sprintf(szMessage, gszNobodyToReply_006D561C);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox_0077BD8C)
                    sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, wszMessage, 1, 0, 1);
                return 1;
            }

            char szPrefix[0x100];
            sprintf(szPrefix, gszCommandSpace_006D5618, szCommand);
            char szCopy[0x100];
            const char* pMessage;
            if (!CONSOLE_FindSecondTokenInline(szText, szCopy, &pMessage))
            {
                Unicode wszMessage[0x100];
                sprintf(szMessage, gszCorrectUsage_006D55F8, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox_0077BD8C)
                    sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, wszMessage, 1, 0, 1);
                return 1;
            }
            if (!gpLaunchFuncs_0077B09C->pfn0x68())
            {
                sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }

            sprintf(szMessage, gszReplyFormat_006D55EC, gszLastWhisperer_0077B0D0, pMessage);
            gpLaunchFuncs_0077B09C->pfn0x14(szMessage);
            return 1;
        }
    }
    return 0;
}

// 0x004423B0
void __fastcall sub_004423B0_RunCommand(char* szText)
{
    sub_0043F510_PushHistory(szText);
    if (sub_00442180_ReplyCommand(szText, gszCmdR_006D56D4))
        return;

    if (sub_00442180_ReplyCommand(szText, gszCmdReply_006D56CC))
        return;

    if (sub_0043E780_NotifyCommand(szText, gszCmdD2Notify_006D56C0))
        return;

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdIgnorePersist_006D56B0))
    {
        sub_00611560_GetSquelchList()->SetPersist(!sub_00611560_GetSquelchList()->GetPersist());
        if (sub_00611560_GetSquelchList()->GetPersist())
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA1), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA2), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdIgnore_006D56A4) || !sub_0043E6E0_CompareCommand(szText, gszCmdSquelch_006D5698))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        sub_0043F870_GetArgument(0x11, szText, szName);
        if (!SStrCmpI(&szName[1], gpCharInfo_0077BBD8->szText0x8D, 0x7FFFFFFF))
            return;

        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Squelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
        sub_00526700(wszMessage, wszFormat);
        sub_0043E5F0_PrintMessage(wszMessage, 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdUnignore_006D568C) || !sub_0043E6E0_CompareCommand(szText, gszCmdUnsquelch_006D5680))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        sub_0043F870_GetArgument(0x11, szText, szName);
        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Unsquelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
        sub_00526700(wszMessage, wszFormat);
        sub_0043E5F0_PrintMessage(wszMessage, 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdFilter_006D5674))
    {
        char szFilter[0x104];
        sub_0043F870_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA7), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA8), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdUnfilter_006D5664))
    {
        char szFilter[0x104];
        sub_0043F870_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA9), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BAA), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdHomeChannel_006D5654) || !sub_0043E6E0_CompareCommand(szText, gszCmdDefaultChannel_006D5640) || !sub_0043E6E0_CompareCommand(szText, gszCmdHomeSpace_006D5638))
    {
        char szChannel[0x20];
        sub_0043F870_GetArgument(0x20, szText, szChannel);
        SRegSaveString(gszDiablo2_006CC8B8, gszDefaultChannel_006D5504, 0, szChannel);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdHome_006D5630))
    {
        char szChannel[0x20];
        if (SRegLoadString(gszDiablo2_006CC8B8, gszDefaultChannel_006D5504, 0, szChannel, 0x20))
            sub_004411E0_Use(szChannel);
        return;
    }

    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
}
