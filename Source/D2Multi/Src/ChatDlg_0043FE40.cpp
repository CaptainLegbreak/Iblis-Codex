#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};
struct D2LaunchLoginStrc
{
    char szText0x00[0x10];
    char szText0x10[0x10];
    char szText0x20[0x20];
    int nValue0x40;
    char nValue0x44;
    char nValue0x45;
    char nValue0x46;
};
struct D2LaunchReplyStrc
{
    int nStatus;
    unsigned short f_4;
    char unk0x06[0x02];
    unsigned short f_8;
    char unk0x0A[0x0A];
    unsigned short wValue;
    char unk0x16[0x06];
    char szName[0x10];
    char szDesc[0x20];
};
#pragma pack(push, 1)
struct D2LaunchReplyEntryStrc
{
    char szName[0x10];
    char szDesc[0x20];
    unsigned short wValue;
    unsigned short f_32;
    char unk0x34[0x02];
    int nValue;
    char unk0x3A[0x01];
};
#pragma pack(pop)
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, size_t nCount);                        // 0x00687330
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x004401C0
int __stdcall CHATDLG_OnRealmConnectCancel(int nArg);                                                                       // 0x0043D9A0
int __stdcall sub_0043DBC0(int nArg);                                                                       // 0x0043DBC0
int __stdcall sub_0043DBF0(int nArg);                                                                       // 0x0043DBF0
void __cdecl sub_00443630_UpdateCreateButton();                                                                                // 0x00443630
int __stdcall CHATDLG_RequestCharLogon(const char* szName);                                                    // 0x00449E10
void __stdcall sub_00449E50_SetValue(int nValue);                                                           // 0x00449E50
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord);                                 // 0x0044A130
int __fastcall WINMAIN_SendMcpCreateGame(D2LaunchLoginStrc* pLogin, unsigned short wRequestId);                // 0x0044A400
int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId);                              // 0x0044A610
void __stdcall D2QSSOCKET_DestroyRecord(void* pConnection);                                                             // 0x006BC780
extern "C" const char gszPassword[];                                                               // 0x006D423C
extern int gnRequestId_0070CD60;                                                                            // 0x0070CD60
extern int gnPendingId;                                                                            // 0x0070EBD8
extern D2WinControlInitStrc gtControlInit_0070E860;                                                         // 0x0070E860
extern D2WinControlInitStrc gtControlInit_0070E890;                                                         // 0x0070E890
extern D2WinControlInitStrc gtControlInit_0070E8C0;                                                         // 0x0070E8C0
extern D2WinControlInitStrc gtControlInit_0070E8F0;                                                         // 0x0070E8F0
extern D2WinControlInitStrc gtControlInit_0070E9B0;                                                         // 0x0070E9B0
extern D2WinControlStrc* gapChatDlgControls;                                                            // 0x0077B058
extern D2WinControlStrc* gpChatControl_0077B05C;                                                            // 0x0077B05C
extern D2WinControlStrc* gpChatControl_0077B064;                                                            // 0x0077B064
extern D2WinControlStrc* gpChatControl_0077B068;                                                            // 0x0077B068
extern D2WinControlStrc* gpChatControl_0077B06C;                                                            // 0x0077B06C
extern D2WinControlStrc* gpCreateScreenButton;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpJoinScreenButton;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2WinControlStrc* gpQuitButton;                                                                       // 0x0077B080
extern D2WinControlStrc* gpChatUpButtonA;                                                            // 0x0077B084
extern D2WinControlStrc* gpChatDownButtonA;                                                            // 0x0077B088
extern D2WinControlStrc* gpChatUpButtonB;                                                            // 0x0077B08C
extern D2WinControlStrc* gpChatDownButtonB;                                                            // 0x0077B090
extern D2LaunchFuncsStrc* gpLaunchFuncs;                                                           // 0x0077B09C
extern D2ConfigStrc* gpCharInfo;                                                           // 0x0077BBD8
extern unsigned short gwSavedRequestId;                                                            // 0x0077BBDC
extern unsigned short gwOtherRequestId;                                                            // 0x0077BBE0
extern int gnChatLaunchMode;                                                                           // 0x0077BBE4
extern int gnFlag_0077BD60;                                                                                 // 0x0077BD60
extern int gbDone;                                                                                 // 0x0077BDA0
extern D2LaunchCallback gpfnLaunchCallback;                                                        // 0x0077BDA4
extern D2LaunchReplyEntryStrc gatReplyEntries[];                                                    // 0x0077BDC9
extern char gszPendingText[264];                                                                          // 0x00798AB8
extern D2WinControlStrc* gpControl_00798BC0;                                                                // 0x00798BC0
extern D2WinControlStrc* gpJoinGameBckgImage;                                                                       // 0x00798BC8
extern D2WinControlStrc* gpControl_00798BD0;                                                                       // 0x00798BD0
extern D2WinControlStrc* gpControl_00798BD4;                                                                // 0x00798BD4
extern D2WinControlStrc* gpJoinPassword;                                                                // 0x00798BD8
extern D2WinControlStrc* gpJoinGameTitle;                                                                // 0x00798BDC
extern D2WinControlStrc* gpJoinNameLabel;                                                                // 0x00798BE0
extern D2WinControlStrc* gpJoinPasswordLabel;                                                                // 0x00798BE4
extern D2WinControlStrc* gpControl_00798BE8;                                                                // 0x00798BE8
extern D2WinControlStrc* gpControl_00798BEC;                                                                // 0x00798BEC
extern D2WinControlStrc* gpCreatePasswordLabel;                                                                // 0x00798BF8
extern D2WinControlStrc* gpCreateDescLabel;                                                                // 0x00798BFC
extern D2WinControlStrc* gpMaxPlayersLabel;                                                                // 0x00798C00
extern D2WinControlStrc* gpLevelDiffLabel;                                                                // 0x00798C04
extern D2WinControlStrc* gpControl_00798C08;                                                                // 0x00798C08
extern D2WinControlStrc* gpMaxPlayersBoxImage;                                                                // 0x00798C0C
extern D2WinControlStrc* gpControl_00798C10;                                                                // 0x00798C10
extern D2WinControlStrc* gpMaxPlayersUpButton;                                                                // 0x00798C14
extern D2WinControlStrc* gpMaxPlayersDownButton;                                                                // 0x00798C18
extern D2WinControlStrc* gpLevelDiffUpButton;                                                                       // 0x00798C1C
extern D2WinControlStrc* gpLevelDiffDownButton;                                                                       // 0x00798C20
extern D2WinControlStrc* gpLevelDiffGreyArrows;                                                                // 0x00798C24
extern D2WinControlStrc* gpControl_00798C2C;                                                                // 0x00798C2C
extern D2WinControlStrc* gpCreatePassword;                                                                // 0x00798C30
extern D2WinControlStrc* gpCreateDesc;                                                                // 0x00798C34
extern D2WinControlStrc* gpMaxPlayerControl;                                                                // 0x00798C38
extern D2WinControlStrc* gpLevelDiffEdit;                                                                // 0x00798C3C
extern D2WinControlStrc* gpLevelDiffCheck;                                                                 // 0x00798C40
extern D2WinControlStrc* gpLevelDiffBoxImage;                                                                // 0x00798C44
extern D2WinControlStrc* gpNormalRadio;                                                                // 0x00798C4C
extern D2WinControlStrc* gpNightmareRadio;                                                                // 0x00798C50
extern D2WinControlStrc* gpHellRadio;                                                                // 0x00798C54
extern D2WinControlStrc* gpNormalLabel;                                                                // 0x00798C58
extern D2WinControlStrc* gpNightmareLabel;                                                                // 0x00798C5C
extern D2WinControlStrc* gpHellLabel;                                                                // 0x00798C60
extern D2WinControlStrc* gpProfileViewBckg;                                                                       // 0x00798C64
extern D2WinControlStrc* gpControl_00798C68;                                                                       // 0x00798C68
extern D2WinControlStrc* gpControl_00798C6C;                                                                       // 0x00798C6C
extern D2WinControlStrc* gpControl_00798C70;                                                                       // 0x00798C70
extern D2WinControlStrc* gpControl_00798C74;                                                                // 0x00798C74
extern D2WinControlStrc* gpProfileEditBckg;                                                                       // 0x00798C78
extern D2WinControlStrc* gpControl_00798C7C;                                                                       // 0x00798C7C
extern D2WinControlStrc* gpSubmitEditA;                                                            // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB;                                                            // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC;                                                            // 0x00798C88
extern D2WinControlStrc* gpRefreshButton;                                                                       // 0x00798C8C
extern D2WinControlStrc* gpControl_00798C90;                                                                       // 0x00798C90
extern D2WinControlStrc* gpControl_00798C94;                                                                       // 0x00798C94
extern D2WinControlStrc* gpControl_00798C98;                                                                       // 0x00798C98
extern D2WinControlStrc* gpControl_00798C9C;                                                                       // 0x00798C9C
extern D2WinControlStrc* gpSubmitButton;                                                                // 0x00798CA0
extern D2WinControlStrc* gpSelectButton;                                                                // 0x00798CA4
extern D2WinControlStrc* gpControl_00798CA8;                                                                       // 0x00798CA8
extern int gnSubmitMode;                                                                                  // 0x00798CAC
extern D2WinControlStrc* gpControl_00798CB0;                                                                // 0x00798CB0
extern D2WinControlStrc* gpControl_00798CB4;                                                                // 0x00798CB4
extern D2WinControlStrc* gpControl_00798CB8;                                                                // 0x00798CB8
extern D2WinControlStrc* gpHelpBckgImage;                                                                // 0x00798CBC
extern int gnValue_00798CC0;                                                                                // 0x00798CC0
extern char gszPendingEntryName[];                                                                             // 0x00798CD4
extern int gnChannelUserCount;                                                                         // 0x00798F40
extern int gnChannelScroll;                                                                               // 0x00798F44
extern unsigned short gwMcpReplyRequestId;                                                                 // 0x00798F80
extern void* gpMcpConnection;                                                                         // 0x00798FB4
extern char gabMcpReply[];                                                                               // 0x00799108
extern void* ghThread;                                                                                    // 0x007992A4
extern void* ghConnectEvent;                                                                       // 0x007992EC
static inline int LAUNCH_SetCallback_inl(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    gpfnLaunchCallback = pfnCallback;
    return 1;
}
// 0x0043FE40
int __fastcall CHATDLG_SetupLogin(D2LaunchLoginStrc* pLogin, const char* szText0x37)
{
    LAUNCH_SetCallback_inl(0, sub_0043DAF0_OnConnect);
    strcpy(gpCharInfo->szGameName, pLogin->szText0x00);
    strcpy(gpCharInfo->szText0x245, pLogin->szText0x10);
    strcpy(gpCharInfo->szText0x25D, pLogin->szText0x20);
    gnChatLaunchMode = 1;
    if (gpCharInfo->szRealm0x22D[0])
    {
        if (sub_00449B30_QueryAddress())
        {
            gpCharInfo->dwGameType = 2;
            while (++*(unsigned short*)&gnRequestId_0070CD60 == 0)
            {
            }
            sub_00449E50_SetValue(0);
            WINMAIN_SendMcpCreateGame(pLogin, gnRequestId_0070CD60);
            gwSavedRequestId = gnRequestId_0070CD60;
            return 1;
        }
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        return 0;
    }
    gpCharInfo->dwGameType = 6;
    strcpy(gpCharInfo->szServerIP, szText0x37);
    gbDone = 1;
    sub_004F9160_SetLoopValue(0);
    D2Win_StopMessageLoop();
    return 1;
}
void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0
int __cdecl CHATDLG_ConnectRealm(); // 0x00441A90
const char* __fastcall CHATDLG_SkipString(const char* szText); // 0x00442AE0
void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply); // 0x00442B90
void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId); // 0x00442DD0
void __cdecl CHATDLG_SendPendingText(); // 0x00442E00
void __cdecl CHATDLG_DestroyJoinControls(); // 0x00443130
void __cdecl CHATDLG_DestroyCreateControls(); // 0x00443220
void __cdecl CHATDLG_CreateProfileControls(); // 0x00443D50
void __cdecl CHATDLG_DestroyProfileControls(); // 0x00443E10
void __fastcall CHATDLG_CopyName(char* szDest); // 0x00443F50
int __cdecl CHATDLG_DestroyGameListControls(); // 0x00444E20
int __stdcall CHATDLG_OnLevelRestrictToggle(int nArg); // 0x00445550
const char* __fastcall CHATDLG_SkipNamePrefix(const char* szName); // 0x00446820
void __fastcall CHATDLG_CopyNamePrefix(const char* szName, char* szOut); // 0x00446840
void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
unsigned short __cdecl CHATDLG_GetRequestId(); // 0x00449BD0
void __cdecl CHATDLG_ClearReply(); // 0x00449D60
