typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch)
    {
    }
};

struct D2WinControlStrc;

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    void (__fastcall* pfn0x14)(const char* szText);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" int __cdecl toupper(int nChar); // 0x00685385
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0

extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C
extern char gszLastWhisperer_0077B0D0[]; // 0x0077B0D0
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern "C" const char gszNobodyToReply_006D561C[]; // 0x006D561C
extern "C" const char gszCommandSpace_006D5618[]; // 0x006D5618
extern "C" const char gszCorrectUsage_006D55F8[]; // 0x006D55F8
extern "C" const char gszReplyFormat_006D55EC[]; // 0x006D55EC

static __declspec(noinline) int __stdcall sub_0043E6E0_CompareCommand(const char* szText, const char* szCommand);

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

// build: context CONSOLE_FindSecondTokenInline
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

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
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

extern "C" const char gszCmdR_006D56D4[]; // 0x006D56D4
extern "C" const char gszCmdReply_006D56CC[]; // 0x006D56CC
// calling-convention shim (not game code)
int __fastcall sub_00442180_Shim(char* szText)
{
    if (sub_00442180_ReplyCommand(szText, gszCmdR_006D56D4))
        return 1;
    if (sub_00442180_ReplyCommand(szText, gszCmdReply_006D56CC))
        return 1;
    return 0;
}
