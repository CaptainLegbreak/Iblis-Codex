struct D2PoolSystemStrc;
struct D2LoadingTimerStrc { unsigned long dwStart,dwLength; };
struct D2MsgHandlerEntryStrc { int nType,nId; void* pfnHandler; };
struct D2MessageStrc { void* hWnd; unsigned int uMessage,wParam,lParam,time; int x,y; };
struct D2CriticalSectionStrc { int fields[6]; };
struct D2VersionInfoStrc { unsigned long dwSize; char unknown04[144]; };
struct D2ComInterfaceStrc { char unknown00[0xC4]; void (__stdcall* Close)(); };
#pragma pack(push,1)
struct D2ClientInfoStrc
{
    char unknown00[0x1EF];
    union { unsigned short wFlags; struct {unsigned char lowFlags,progress;}; };
    char unknown1F1[0x33]; unsigned char nSoundArg;
};
#pragma pack(pop)
typedef int (__stdcall* D2IdleHandler)(int);
typedef unsigned long (__stdcall* D2ThreadProc)(void*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2VersionInfoStrc*); // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*,unsigned long,D2ThreadProc,void*,unsigned long,unsigned long*); // 0x006CC250
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2MessageStrc*,void*,unsigned int,unsigned int,unsigned int); // 0x006CC480
extern D2MsgHandlerEntryStrc gtHandlers_0070F2C4[1]; // 0x0070F2C4
extern D2MsgHandlerEntryStrc gtHandlers_0070F2D0[10]; // 0x0070F2D0
extern D2MsgHandlerEntryStrc gtHandlers_0070F348[2]; // 0x0070F348
extern D2MsgHandlerEntryStrc gtHandlers_0070F360[2]; // 0x0070F360
extern D2MsgHandlerEntryStrc gtHandlers_0070F3C0[7]; // 0x0070F3C0
extern D2MsgHandlerEntryStrc gtHandlers_0070F418[9]; // 0x0070F418
extern D2ClientInfoStrc* gpClientInfo_007A0438; // 0x007A0438
extern D2CriticalSectionStrc gtCriticalSection_007A0468; // 0x007A0468
extern int gnServerToken_007A0520; // 0x007A0520
extern D2VersionInfoStrc gtVersionInfo_007A0528; // 0x007A0528
extern void* ghThread_007A05BC; // 0x007A05BC
extern int gnServerHash_007A05C0; // 0x007A05C0
extern const char gszGameName_007A05DC[]; // 0x007A05DC
extern unsigned long gnThreadId_007A05F0; // 0x007A05F0
extern D2ComInterfaceStrc* gpComInterface_007A05F4; // 0x007A05F4
extern int gnBetaScreens_007A0600; // 0x007A0600
extern int gnDifficultyDirty_007A0604; // 0x007A0604
extern unsigned char gnDifficulty_007A060C; // 0x007A060C
extern int gnMode_007A0610; // 0x007A0610
extern int gnPlayCinematic_007A0628; // 0x007A0628
extern int gnCinematicPlayed_007A062C; // 0x007A062C
extern int gnVersionValid_007A0644; // 0x007A0644
extern int gnThreadStop_007A0648; // 0x007A0648
extern int gnThreadReady_007A064C; // 0x007A064C
extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc*,int); // 0x00409FF0
void __fastcall sub_0044B440_PushValue(int); // 0x0044B440
void __fastcall sub_0044B880_SetValue(int); // 0x0044B880
void __fastcall sub_0044BA20_SetResolution(int); // 0x0044BA20
void __cdecl sub_0044C890_ReleaseGameState(); // 0x0044C890
unsigned long __stdcall sub_0044CF20(void*); // 0x0044CF20
int __stdcall sub_0044D100_ShowBetaScreens(int); // 0x0044D100
void __cdecl sub_0044DCE0_MouseExtTables(); // 0x0044DCE0
int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc*); // 0x0044E040
void __cdecl sub_0044E200_InitGameState(); // 0x0044E200
int __stdcall sub_0044E400_LoadingTimerCallback(int); // 0x0044E400
int __stdcall sub_0044E770_DrawEndGameScreen(int); // 0x0044E770
int __stdcall sub_0044EFA0_GameLoop(int); // 0x0044EFA0
void __cdecl sub_00451620_WriteRecordFile(); // 0x00451620
int __cdecl sub_00451910_IsRecording(); // 0x00451910
void __cdecl sub_00451940_InstallRecordHandler(); // 0x00451940
void __cdecl sub_00451970(); // 0x00451970
int __cdecl sub_00451980_IsReplaying(); // 0x00451980
int __fastcall sub_00451BB0_MessageLoop(D2IdleHandler); // 0x00451BB0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int,D2MsgHandlerEntryStrc*,unsigned int); // 0x00451DB0
void __fastcall sub_00451E10_UnregisterMsgHandlers(int,D2MsgHandlerEntryStrc*,int); // 0x00451E10
int __cdecl sub_00451F10_PushRegisterState(); // 0x00451F10
int __fastcall sub_004680B0_InitCursor(int); // 0x004680B0
void __cdecl sub_00468170_ShutdownCursor(); // 0x00468170
void __cdecl sub_00475DF0_BuildLerpTables(); // 0x00475DF0
void __cdecl sub_00475EF0_FreeLerpTables(); // 0x00475EF0
void __fastcall sub_00477CA0_SendPacket67(const char*,int); // 0x00477CA0
void __fastcall sub_00477F70_SendGameLogon(int,int); // 0x00477F70
int __cdecl sub_0047A990(); // 0x0047A990
int __fastcall sub_004803C0_InitWarden(int); // 0x004803C0
void __cdecl sub_00481830(); // 0x00481830
void __fastcall sub_00482260_UpdateSoundSystem(int); // 0x00482260
void __cdecl sub_00482940_UpdateSound(); // 0x00482940
void __fastcall sub_00482EF0_PlayCinematic(int); // 0x00482EF0
void __cdecl sub_00483310_ResetCinematicFlags(); // 0x00483310
int __cdecl sub_004F59A0(); // 0x004F59A0
void __stdcall D2Win_10006_ClearDrawCaches(); // 0x004F9130
void __fastcall sub_00515F50_FadeOutMaster(int); // 0x00515F50
static __forceinline int TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if(pTimer->dwLength)
    {
        unsigned long dwNow=GetTickCount();
        unsigned long dwLeft;
        if(dwNow>=pTimer->dwStart+pTimer->dwLength)
        {
            pTimer->dwStart=0;
            pTimer->dwLength=0;
            dwLeft=0;
        }
        else dwLeft=pTimer->dwLength-(dwNow-pTimer->dwStart);
        return dwLeft==0;
    }
    return 1;
}
// 0x0044F360
int __cdecl sub_0044F360_RunGameSession()
{
    if(TimerExpired(&gtLoadingTimer_007A0684))sub_0044B880_SetValue(1);
    GetTickCount();
    gtVersionInfo_007A0528.dwSize=sizeof(gtVersionInfo_007A0528);
    if(GetVersionExA(&gtVersionInfo_007A0528))gnVersionValid_007A0644=1;
    sub_00475DF0_BuildLerpTables();
    sub_00483310_ResetCinematicFlags();
    sub_00451F10_PushRegisterState();
    sub_004680B0_InitCursor(0);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2C4,1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F348,2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F360,2);
    if(gnMode_007A0610!=3 && gnMode_007A0610!=7 && gnMode_007A0610!=9)
    {
        sub_00477CA0_SendPacket67(gszGameName_007A05DC,sub_0047A990());
        if(gnMode_007A0610==6 || gnMode_007A0610==8)
        {
            gnThreadStop_007A0648=0;
            gnThreadReady_007A064C=0;
            InitializeCriticalSection(&gtCriticalSection_007A0468);
            ghThread_007A05BC=CreateThread(0,0,sub_0044CF20,0,0,&gnThreadId_007A05F0);
        }
    }
    else
    {
        sub_00477F70_SendGameLogon(gnServerToken_007A0520,gnServerHash_007A05C0);
        if(gnMode_007A0610==2 || gnMode_007A0610==3)sub_004803C0_InitWarden(gnServerHash_007A05C0);
    }
    sub_00482260_UpdateSoundSystem(gpClientInfo_007A0438->nSoundArg);
    sub_0044E200_InitGameState();
    if(sub_00451910_IsRecording() || sub_00451980_IsReplaying())
    {
        D2MessageStrc tMessage;
        while(PeekMessageA(&tMessage,0,0,0,1)){}
        if(sub_00451980_IsReplaying())sub_00451970();
        else if(sub_00451910_IsRecording())sub_00451940_InstallRecordHandler();
    }
    FOG_SetMemoryPoolSystemMode(0,0);
    if(gnMode_007A0610==6 || gnMode_007A0610==8)
    {
        EnterCriticalSection(&gtCriticalSection_007A0468);
        gnThreadReady_007A064C=1;
        LeaveCriticalSection(&gtCriticalSection_007A0468);
    }
    sub_00451BB0_MessageLoop(sub_0044EFA0_GameLoop);
    GetTickCount();
    sub_00515F50_FadeOutMaster(180);
    sub_00481830();
    if(sub_0044E040_TimerRunning(&gtLoadingTimer_007A0684) && !gnDifficultyDirty_007A0604 && !gnCinematicPlayed_007A062C)sub_00451BB0_MessageLoop(sub_0044E400_LoadingTimerCallback);
    if(sub_00451910_IsRecording())sub_00451620_WriteRecordFile();
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2C4,1);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F348,2);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F360,2);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F3C0,7);
        sub_00451BB0_MessageLoop(sub_0044D100_ShowBetaScreens);
    }
    else if(gnDifficultyDirty_007A0604)
    {
        sub_00482EF0_PlayCinematic(5);
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_0044DCE0_MouseExtTables();
        sub_0044BA20_SetResolution(0);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        sub_00451BB0_MessageLoop(sub_0044E770_DrawEndGameScreen);
    }
    else if(gnPlayCinematic_007A0628)
    {
        sub_00482EF0_PlayCinematic(7);
        gnCinematicPlayed_007A062C=1;
    }
    unsigned char bEndGame=1;
    if(gnCinematicPlayed_007A062C)
    {
        int nDifficulty=gnDifficulty_007A060C;
        int nProgress=gpClientInfo_007A0438->progress&31;
        D2ClientInfoStrc* pClientInfo=gpClientInfo_007A0438;
        switch(nDifficulty)
        {
        case 0:
            if(nProgress==8)bEndGame=0;
            else if(nProgress==12)bEndGame=0;
            break;
        case 1:
            if(nProgress==12)bEndGame=0;
            break;
        }
        pClientInfo->wFlags=((nDifficulty<<10)+0x500)|(pClientInfo->wFlags&0xE0FF);
        if(bEndGame)
        {
            sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
            sub_0044DCE0_MouseExtTables();
            sub_0044BA20_SetResolution(2);
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
            sub_00451BB0_MessageLoop(sub_0044E770_DrawEndGameScreen);
        }
    }
    sub_0044C890_ReleaseGameState();
    sub_00482940_UpdateSound();
    sub_00475EF0_FreeLerpTables();
    sub_00468170_ShutdownCursor();
    D2Win_10006_ClearDrawCaches();
    sub_0044B440_PushValue(4);
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F3C0,7);
        gnBetaScreens_007A0600=0;
    }
    else if(gnDifficultyDirty_007A0604)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        gnDifficultyDirty_007A0604=0;
    }
    else if(bEndGame && gnCinematicPlayed_007A062C)
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F418,9);
        gnCinematicPlayed_007A062C=0;
    }
    else
    {
        sub_00451E10_UnregisterMsgHandlers(sub_004F59A0(),gtHandlers_0070F2D0,10);
        sub_0044DCE0_MouseExtTables();
    }
    if(gnMode_007A0610==2 || gnMode_007A0610==6 || gnMode_007A0610==3 || gnMode_007A0610==7)
        if(gpComInterface_007A05F4)gpComInterface_007A05F4->Close();
    return 6;
}

#include "gen/data/Source/D2Client/0044F360_sub_0044F360_RunGameSession.inc"
