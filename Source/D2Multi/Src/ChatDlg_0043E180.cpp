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
extern unsigned char gnSelectModeA_0070CD62; // 0x0070CD62

int __fastcall sub_004F9190(); // 0x004F9190
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
void __stdcall sub_A09_Use(const char* szText);
int __cdecl sub_00444E20(); // 0x00444E20
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
void __cdecl sub_0043EB30_CreateControls(); // 0x0043EB30
void __cdecl sub_00440FC0_CreateGatewayControls(); // 0x00440FC0
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
int __fastcall D2Win_10015(); // 0x004F8FE0
int __stdcall sub_004F90A0_SwitchResolution(int nResolution); // 0x004F90A0
int __fastcall sub_00441B70_RunChat(D2LaunchCharInfoStrc* pInfo); // 0x00441B70
int __fastcall D2Win_10016(); // 0x004FA550
extern int gbDone_0077BDA0; // 0x0077BDA0
void __cdecl sub_00440980_OpenClassSelectB(); // 0x00440980
int __cdecl sub_00442810_SendChatBuffer(); // 0x00442810


void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
extern D2WinControlInitStrc gtWaitInit_0070D3C0; // 0x0070D3C0
extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070
extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078
extern int gnLaunchMode_0077BBE4; // 0x0077BBE4
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlStrc* gpWaitText_0077BD9C; // 0x0077BD9C
extern D2LaunchCallback gpfnLaunchCallback_0077BDA4; // 0x0077BDA4

D2CriticalSectionStrc gtChatLock_0077AE28; // 0x0077AE28

D2ChatMessageStrc* gpChatQueueHead_0077BDAC; // 0x0077BDAC

// 0x0043E180
static __forceinline void sub_0043E180_UnixTimeToFileTime(unsigned int nTime, _FILETIME* pFileTime)
{
    const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
    pFileTime->dwLowDateTime = (unsigned long)nFileTime;
    pFileTime->dwHighDateTime = (unsigned long)(nFileTime >> 32);
}

// 0x0043E230
void __cdecl sub_0043E230_InitChatLock()
{
    InitializeCriticalSection(&gtChatLock_0077AE28);
}

// 0x0043E240
void __cdecl sub_0043E240_DeleteChatLock()
{
    DeleteCriticalSection(&gtChatLock_0077AE28);
}

// 0x0043E2E0
static __forceinline void sub_0043E2E0(D2ChatMessageStrc* pMessage)
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
D2ChatMessageStrc* __cdecl sub_0043E370()
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

// 0x0043EC50
void __fastcall sub_0043EC50_SetSelect(unsigned char nMode, int nId)
{
    gnSelectModeA_0070CD62 = nMode;
    gnSelectIdA_0070CD7C = nId;
}

// 0x0043ED50
void __cdecl sub_0043ED50_Nop()
{
}

int __fastcall sub_M110_Emit_0043E180(unsigned int nTime, _FILETIME* pFileTime)
{
    sub_0043E180_UnixTimeToFileTime(nTime, pFileTime);
    sub_0043E2E0((D2ChatMessageStrc*)pFileTime->dwHighDateTime);
    return 1;
}

int gbDone_0077BDA0; // 0x0077BDA0

// 0x0043E6C0
int __stdcall sub_0043E6C0_OnCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gbDone_0077BDA0 = 4;
    sub_004F9190();
    return 1;
}

// 0x0043EB00
int __stdcall sub_0043EB00_OnWait(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043EA20_Wait();
    return 1;
}

char gaszHistory_0077B1D8[10][0x100]; // 0x0077B1D8

int gnHistoryCount_0077BD50; // 0x0077BD50

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

// 0x0043F510
static void sub_0043F510_PushHistory(const char* szText)
{
    memmove(gaszHistory_0077B1D8[1], gaszHistory_0077B1D8[0], 0x900);
    strcpy(gaszHistory_0077B1D8[0], szText);
    if (++gnHistoryCount_0077BD50 >= 10)
        gnHistoryCount_0077BD50 = 10;
}

// 0x0043F870
static void __stdcall sub_0043F870_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

void __fastcall sub_A09_Emit_004423B0(char* szText)
{
    sub_0043F510_PushHistory(szText);
    if (!sub_0043E6E0_CompareCommand(szText, "/ignore "))
        return;
    if (!sub_0043E6E0_CompareCommand(szText, "/filtermsg "))
    {
        char szArg[0x104];
        sub_0043F870_GetArgument(0x104, szArg, szText);
        sub_A09_Use(szArg);
    }
}

D2WinControlStrc* gpControlB_0077B078; // 0x0077B078

D2WinControlStrc* gpControlA_0077B070; // 0x0077B070

// 0x0043F580
int __stdcall sub_0043F580(int nArg)
{
    gbFlag_0077ADA4 = 1;
    return 1;
}

// 0x0043F720
int __stdcall sub_0043F720_Callback(int nArg)
{
    sub_00444E20();
    return 1;
}

// 0x0043F970
int __stdcall sub_0043F970_ReleaseAndRecreate(int nArg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    sub_0043F8C0_ResetLaunchState();
    sub_0043EB30_CreateControls();
    return 1;
}

// 0x00442150
int __fastcall sub_00442150_StartChat(D2LaunchCharInfoStrc* pInfo)
{
    gpCharInfo_0077BBD8 = pInfo;
    D2Win_10015();
    sub_004F90A0_SwitchResolution(1);
    sub_00441B70_RunChat(pInfo);
    D2Win_10016();
    return gbDone_0077BDA0;
}

// 0x00442350
int __stdcall sub_00442350_OpenClassSelect(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00440980_OpenClassSelectB();
    gnSelectModeA_0070CD62 = 0;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00442370
int __stdcall sub_00442370_ReleaseAndCreate(int nArg)
{
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    sub_0043F8C0_ResetLaunchState();
    sub_00440FC0_CreateGatewayControls();
    return 1;
}

// 0x004428B0
int __stdcall sub_004428B0_SendChat(int nArg)
{
    sub_00442810_SendChatBuffer();
    sub_0043EA20_Wait();
    return 1;
}

// 0x0043FB50
int __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone)
{
    sub_0043F8C0_ResetLaunchState();
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpWaitText_0077BD9C = CONTROL_Create(&gtWaitInit_0070D3C0);
    D2Win_10044(gpWaitText_0077BD9C, pText);
    gpfnLaunchCallback_0077BDA4 = pfnDone;
    return 1;
}

// 0x0043FBD0
void __cdecl sub_0043FBD0_Refresh()
{
    sub_0043F8C0_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnLaunchMode_0077BBE4 = 0;
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043E180.inc"
