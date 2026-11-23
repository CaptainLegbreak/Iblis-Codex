#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"

struct D2LaunchCharInfoStrc;
struct D2ChatMessageStrc;
struct _FILETIME;
struct SMSGHANDLER_PARAMS;
struct Unicode;

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};
extern unsigned char gnSelectModeA; // 0x0070CD62

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
void __stdcall sub_A09_Use(const char* szText);
int __cdecl CHATDLG_DestroyGameListControls(); // 0x00444E20
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
void __cdecl CHATDLG_CreateControls(); // 0x0043EB30
void __cdecl sub_00440FC0_CreateGatewayControls(); // 0x00440FC0
extern D2LaunchCharInfoStrc* gpCharInfo; // 0x0077BBD8
int __fastcall D2Win_10015(); // 0x004F8FE0
int __stdcall D2Win_10005(int nResolution); // 0x004F90A0
int __fastcall CHATDLG_RunChat(D2LaunchCharInfoStrc* pInfo); // 0x00441B70
int __fastcall D2Win_10016(); // 0x004FA550
extern int gbDone; // 0x0077BDA0
void __cdecl CHATDLG_OpenHardcoreLadder(); // 0x00440980
int __cdecl CHATDLG_SendChatBuffer(); // 0x00442810


void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
extern D2WinControlInitStrc gtWaitInit; // 0x0070D3C0
extern D2WinControlStrc* gpCreateScreenButton; // 0x0077B070
extern D2WinControlStrc* gpJoinScreenButton; // 0x0077B078
extern int gnChatLaunchMode; // 0x0077BBE4
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlStrc* gpWaitText_0077BD9C; // 0x0077BD9C
extern D2LaunchCallback gpfnLaunchCallback; // 0x0077BDA4

D2CriticalSectionStrc gtChatLock; // 0x0077AE28

D2ChatMessageStrc* gpChatQueueHead; // 0x0077BDAC

// 0x0043E180
static inline void CHATDLG_UnixTimeToFileTime(unsigned int nTime, _FILETIME* pFileTime)
{
    const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
    pFileTime->dwLowDateTime = (unsigned long)nFileTime;
    pFileTime->dwHighDateTime = (unsigned long)(nFileTime >> 32);
}

// 0x0043E230
void __cdecl CHATDLG_InitChatLock()
{
    InitializeCriticalSection(&gtChatLock);
}

// 0x0043E240
void __cdecl CHATDLG_DeleteChatLock()
{
    DeleteCriticalSection(&gtChatLock);
}

// 0x0043E2E0
static inline void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage)
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

// 0x0043E370
D2ChatMessageStrc* __cdecl CHATDLG_PopChatMessage()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock);
    if (gpChatQueueHead)
    {
        pMessage = gpChatQueueHead;
        gpChatQueueHead = gpChatQueueHead->pNext;
    }
    LeaveCriticalSection(&gtChatLock);
    return pMessage;
}

// 0x0043EC50
void __fastcall CHATDLG_SetLadderSelection(unsigned char nMode, int nId)
{
    gnSelectModeA = nMode;
    gnSelectIdA_0070CD7C = nId;
}

// 0x0043ED50
void __cdecl CHATDLG_ClearLadderState()
{
}

int __fastcall sub_M110_Emit_0043E180(unsigned int nTime, _FILETIME* pFileTime)
{
    CHATDLG_UnixTimeToFileTime(nTime, pFileTime);
    CHATDLG_FreeChatMessage((D2ChatMessageStrc*)pFileTime->dwHighDateTime);
    return 1;
}

int gbDone; // 0x0077BDA0

// 0x0043E6C0
int __stdcall CHATDLG_OnCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gbDone = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x0043EB00
int __stdcall CHATDLG_OnWait(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?CHARSEL_DestroyPopupControls@* 0x0043EA20
    CHARSEL_DestroyPopupControls();
    return 1;
}

char gaszHistory[10][0x100]; // 0x0077B1D8

int gnHistoryCount; // 0x0077BD50

// 0x0043E6E0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand)
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

// 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory[1], gaszHistory[0], 0x900);
    strcpy(gaszHistory[0], szText);
    if (++gnHistoryCount >= 10)
        gnHistoryCount = 10;
}

// 0x0043F870
static void __stdcall CHATDLG_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

void __fastcall sub_A09_Emit_004423B0(char* szText)
{
    CHATDLG_PushHistory(szText);
    if (!CHATDLG_CompareCommand(szText, "/ignore "))
        return;
    if (!CHATDLG_CompareCommand(szText, "/filtermsg "))
    {
        char szArg[0x104];
        CHATDLG_GetArgument(0x104, szArg, szText);
        sub_A09_Use(szArg);
    }
}

D2WinControlStrc* gpJoinScreenButton; // 0x0077B078

D2WinControlStrc* gpCreateScreenButton; // 0x0077B070

// 0x0043F580
int __stdcall CHATDLG_SetUserDataFlag(int nArg)
{
    gbFlag_0077ADA4 = 1;
    return 1;
}

// 0x0043F720
int __stdcall CHATDLG_OnProfileClose(int nArg)
{
    CHATDLG_DestroyGameListControls();
    return 1;
}

// 0x0043F970
int __stdcall CHATDLG_ReleaseAndRecreate(int nArg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
}

// 0x0043FB50
int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHARSEL_ResetLaunchState();
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpWaitText_0077BD9C = CONTROL_Create(&gtWaitInit);
    D2Win_10044(gpWaitText_0077BD9C, pText);
    gpfnLaunchCallback = pfnDone;
    return 1;
}

// 0x0043FBD0
void __cdecl CHATDLG_RefreshChatScreen()
{
    CHARSEL_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnChatLaunchMode = 0;
}

// 0x00442150
int __fastcall CHATDLG_StartChat(D2LaunchCharInfoStrc* pInfo)
{
    gpCharInfo = pInfo;
    D2Win_10015();
    D2Win_10005(1);
    CHATDLG_RunChat(pInfo);
    D2Win_10016();
    return gbDone;
}

// 0x00442350
int __stdcall CHATDLG_OpenLadderScreen(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenHardcoreLadder();
    gnSelectModeA = 0;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00442370
int __stdcall CHATDLG_ReleaseAndCreate(int nArg)
{
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    CHARSEL_ResetLaunchState();
    sub_00440FC0_CreateGatewayControls();
    return 1;
}

// 0x004428B0
int __stdcall CHATDLG_SendChat(int nArg)
{
    CHATDLG_SendChatBuffer();
    CHARSEL_DestroyPopupControls();
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043E180.inc"
