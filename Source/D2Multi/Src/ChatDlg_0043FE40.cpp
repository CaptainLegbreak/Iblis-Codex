#include "D2Multi.h"

struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlInitStrc
{
    int nType;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_14;
    int nStringId;
    void* ppCellFile;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x1C];
    int (__fastcall* pfn0x1C)(const char* szText, int nB, int nC);
    char unk0x20[0x24];
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(char* szRealm, const char* szKey);
    char unk0x48[0x20];
    int (__fastcall* pfn0x68)();
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x86];
    char szName0xBD[0x132];
    char wFlags[2];
    char unk0x1F1[0x3C];
    char szRealm0x22D[0x18];
    char szText0x245[0x18];
    char szText0x25D[0x10];
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
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, size_t nCount);                        // 0x00687330
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __cdecl sub_004F9190();                                                              // 0x004F9190
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x004401C0
int __stdcall sub_0043D9A0(int nArg);                                                                       // 0x0043D9A0
int __stdcall sub_0043DBC0(int nArg);                                                                       // 0x0043DBC0
int __stdcall sub_0043DBF0(int nArg);                                                                       // 0x0043DBF0
void __cdecl sub_00443630_UpdateCreateButton();                                                                                // 0x00443630
int __stdcall sub_00449E10_Forward1(const char* szName);                                                    // 0x00449E10
void __stdcall sub_00449E50_SetValue(int nValue);                                                           // 0x00449E50
void __stdcall sub_0044A130_StartThread(D2LaunchThreadRecordStrc* pRecord);                                 // 0x0044A130
int __fastcall sub_0044A400_SendLogin(D2LaunchLoginStrc* pLogin, unsigned short wRequestId);                // 0x0044A400
int __fastcall sub_0044A610_SendText(char* szText, unsigned short wRequestId);                              // 0x0044A610
void __stdcall sub_006BC780(void* pConnection);                                                             // 0x006BC780

extern "C" const char gszPassword_006D423C[];                                                               // 0x006D423C
extern int gnRequestId_0070CD60;                                                                            // 0x0070CD60
extern int gnPendingId_0070EBD8;                                                                            // 0x0070EBD8
extern D2WinControlInitStrc gtControlInit_0070E860;                                                         // 0x0070E860
extern D2WinControlInitStrc gtControlInit_0070E890;                                                         // 0x0070E890
extern D2WinControlInitStrc gtControlInit_0070E8C0;                                                         // 0x0070E8C0
extern D2WinControlInitStrc gtControlInit_0070E8F0;                                                         // 0x0070E8F0
extern D2WinControlInitStrc gtControlInit_0070E9B0;                                                         // 0x0070E9B0
extern D2WinControlStrc* gpChatControl_0077B058;                                                            // 0x0077B058
extern D2WinControlStrc* gpChatControl_0077B05C;                                                            // 0x0077B05C
extern D2WinControlStrc* gpChatControl_0077B064;                                                            // 0x0077B064
extern D2WinControlStrc* gpChatControl_0077B068;                                                            // 0x0077B068
extern D2WinControlStrc* gpChatControl_0077B06C;                                                            // 0x0077B06C
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
D2WinControlStrc* gpControl_0077B080;                                                                       // 0x0077B080
extern D2WinControlStrc* gpChatControl_0077B084;                                                            // 0x0077B084
extern D2WinControlStrc* gpChatControl_0077B088;                                                            // 0x0077B088
extern D2WinControlStrc* gpChatControl_0077B08C;                                                            // 0x0077B08C
extern D2WinControlStrc* gpChatControl_0077B090;                                                            // 0x0077B090
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern unsigned short gwSavedRequestId_0077BBDC;                                                            // 0x0077BBDC
extern unsigned short gwOtherRequestId_0077BBE0;                                                            // 0x0077BBE0
extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
extern int gnFlag_0077BD60;                                                                                 // 0x0077BD60
extern int gbDone_0077BDA0;                                                                                 // 0x0077BDA0
extern D2LaunchCallback gpfnLaunchCallback_0077BDA4;                                                        // 0x0077BDA4
extern D2LaunchReplyEntryStrc gaReplyEntries_0077BDC9[];                                                    // 0x0077BDC9
char gszPendingText_00798AB8[264];                                                                          // 0x00798AB8
extern D2WinControlStrc* gpControl_00798BC0;                                                                // 0x00798BC0
D2WinControlStrc* gpControl_00798BC8;                                                                       // 0x00798BC8
D2WinControlStrc* gpControl_00798BD0;                                                                       // 0x00798BD0
extern D2WinControlStrc* gpControl_00798BD4;                                                                // 0x00798BD4
extern D2WinControlStrc* gpControl_00798BD8;                                                                // 0x00798BD8
extern D2WinControlStrc* gpControl_00798BDC;                                                                // 0x00798BDC
extern D2WinControlStrc* gpControl_00798BE0;                                                                // 0x00798BE0
extern D2WinControlStrc* gpControl_00798BE4;                                                                // 0x00798BE4
extern D2WinControlStrc* gpControl_00798BE8;                                                                // 0x00798BE8
extern D2WinControlStrc* gpControl_00798BEC;                                                                // 0x00798BEC
extern D2WinControlStrc* gpControl_00798BF8;                                                                // 0x00798BF8
extern D2WinControlStrc* gpControl_00798BFC;                                                                // 0x00798BFC
extern D2WinControlStrc* gpControl_00798C00;                                                                // 0x00798C00
extern D2WinControlStrc* gpControl_00798C04;                                                                // 0x00798C04
extern D2WinControlStrc* gpControl_00798C08;                                                                // 0x00798C08
extern D2WinControlStrc* gpControl_00798C0C;                                                                // 0x00798C0C
extern D2WinControlStrc* gpControl_00798C10;                                                                // 0x00798C10
extern D2WinControlStrc* gpControl_00798C14;                                                                // 0x00798C14
extern D2WinControlStrc* gpControl_00798C18;                                                                // 0x00798C18
D2WinControlStrc* gpControl_00798C1C;                                                                       // 0x00798C1C
D2WinControlStrc* gpControl_00798C20;                                                                       // 0x00798C20
extern D2WinControlStrc* gpControl_00798C24;                                                                // 0x00798C24
extern D2WinControlStrc* gpControl_00798C2C;                                                                // 0x00798C2C
extern D2WinControlStrc* gpControl_00798C30;                                                                // 0x00798C30
extern D2WinControlStrc* gpControl_00798C34;                                                                // 0x00798C34
extern D2WinControlStrc* gpControl_00798C38;                                                                // 0x00798C38
extern D2WinControlStrc* gpControl_00798C3C;                                                                // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40;                                                                 // 0x00798C40
extern D2WinControlStrc* gpControl_00798C44;                                                                // 0x00798C44
extern D2WinControlStrc* gpControl_00798C4C;                                                                // 0x00798C4C
extern D2WinControlStrc* gpControl_00798C50;                                                                // 0x00798C50
extern D2WinControlStrc* gpControl_00798C54;                                                                // 0x00798C54
extern D2WinControlStrc* gpControl_00798C58;                                                                // 0x00798C58
extern D2WinControlStrc* gpControl_00798C5C;                                                                // 0x00798C5C
extern D2WinControlStrc* gpControl_00798C60;                                                                // 0x00798C60
D2WinControlStrc* gpControl_00798C64;                                                                       // 0x00798C64
D2WinControlStrc* gpControl_00798C68;                                                                       // 0x00798C68
D2WinControlStrc* gpControl_00798C6C;                                                                       // 0x00798C6C
D2WinControlStrc* gpControl_00798C70;                                                                       // 0x00798C70
extern D2WinControlStrc* gpControl_00798C74;                                                                // 0x00798C74
D2WinControlStrc* gpControl_00798C78;                                                                       // 0x00798C78
D2WinControlStrc* gpControl_00798C7C;                                                                       // 0x00798C7C
extern D2WinControlStrc* gpSubmitEditA_00798C80;                                                            // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB_00798C84;                                                            // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC_00798C88;                                                            // 0x00798C88
D2WinControlStrc* gpControl_00798C8C;                                                                       // 0x00798C8C
D2WinControlStrc* gpControl_00798C90;                                                                       // 0x00798C90
D2WinControlStrc* gpControl_00798C94;                                                                       // 0x00798C94
D2WinControlStrc* gpControl_00798C98;                                                                       // 0x00798C98
D2WinControlStrc* gpControl_00798C9C;                                                                       // 0x00798C9C
extern D2WinControlStrc* gpControl_00798CA0;                                                                // 0x00798CA0
extern D2WinControlStrc* gpControl_00798CA4;                                                                // 0x00798CA4
D2WinControlStrc* gpControl_00798CA8;                                                                       // 0x00798CA8
int gnSubmitMode_00798CAC;                                                                                  // 0x00798CAC
extern D2WinControlStrc* gpControl_00798CB0;                                                                // 0x00798CB0
extern D2WinControlStrc* gpControl_00798CB4;                                                                // 0x00798CB4
extern D2WinControlStrc* gpControl_00798CB8;                                                                // 0x00798CB8
extern D2WinControlStrc* gpControl_00798CBC;                                                                // 0x00798CBC
extern int gnValue_00798CC0;                                                                                // 0x00798CC0
extern char gszName_00798CD4[];                                                                             // 0x00798CD4
extern int gnChannelLines_00798F40;                                                                         // 0x00798F40
int gnChannelScroll_00798F44;                                                                               // 0x00798F44
extern unsigned short gwRequestId_00798F80;                                                                 // 0x00798F80
extern void* gpConnection_00798FB4;                                                                         // 0x00798FB4
extern char gData_00799108[];                                                                               // 0x00799108
void* ghThread_007992A4;                                                                                    // 0x007992A4
extern void* ghConnectEvent_007992EC;                                                                       // 0x007992EC

static __forceinline int LAUNCH_SetCallback_inl(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
    sub_0043F8C0_ResetLaunchState();
    gpfnLaunchCallback_0077BDA4 = pfnCallback;
    return 1;
}

// 0x0043FE40
int __fastcall sub_0043FE40_SetupLogin(D2LaunchLoginStrc* pLogin, const char* szText0x37)
{
    LAUNCH_SetCallback_inl(0, sub_0043DAF0_OnConnect);
    strcpy(gpCharInfo_0077BBD8->szText0x1F, pLogin->szText0x00);
    strcpy(gpCharInfo_0077BBD8->szText0x245, pLogin->szText0x10);
    strcpy(gpCharInfo_0077BBD8->szText0x25D, pLogin->szText0x20);
    gnLaunchMode_0077BBE4 = 1;
    if (gpCharInfo_0077BBD8->szRealm0x22D[0])
    {
        if (sub_00449B30_QueryAddress())
        {
            *(int*)gpCharInfo_0077BBD8->nState = 2;
            while (++*(unsigned short*)&gnRequestId_0070CD60 == 0)
            {
            }
            sub_00449E50_SetValue(0);
            sub_0044A400_SendLogin(pLogin, gnRequestId_0070CD60);
            gwSavedRequestId_0077BBDC = gnRequestId_0070CD60;
            return 1;
        }
        gnLaunchMode_0077BBE4 = 0;
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        return 0;
    }
    *(int*)gpCharInfo_0077BBD8->nState = 6;
    strcpy(gpCharInfo_0077BBD8->szText0x37, szText0x37);
    gbDone_0077BDA0 = 1;
    sub_004F9160_SetLoopValue(0);
    sub_004F9190();
    return 1;
}

// 0x004411E0
void __fastcall sub_004411E0_Use(const char* szText)
{
    gpLaunchFuncs_0077B09C->pfn0x1C(szText, 0, 0);
    sub_0043F8C0_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnLaunchMode_0077BBE4 = 0;
}

// 0x00441A90
int __cdecl sub_00441A90()
{
    if (!gpCharInfo_0077BBD8->szRealm0x22D[0])
        return 1;
    if (!gpLaunchFuncs_0077B09C)
        return 0;
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
        return 0;
    if (sub_00449B30_QueryAddress())
        return 1;
    gnFlag_0077BD60 = 0;
    sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), sub_0043D9A0);
    D2LaunchPayloadStrc* pPayload = gpLaunchFuncs_0077B09C->pfn0x44(gpCharInfo_0077BBD8->szRealm0x22D, gszPassword_006D423C);
    if (!pPayload)
        return 0;
    if (pPayload->nSize <= 8)
        return 0;
    sub_0044A130_StartThread(&pPayload->tRecord);
    sub_004FA590_RunLoop(sub_0043DBC0);
    sub_0043EA20_Wait();
    if (gnFlag_0077BD60 || !sub_00449B30_QueryAddress() || sub_00449C00())
    {
        sub_0043EA20_Wait();
        return 0;
    }
    sub_00449E10_Forward1(gpCharInfo_0077BBD8->szName0xBD);
    sub_004FA590_RunLoop(sub_0043DBF0);
    sub_0043EA20_Wait();
    return sub_00449C00() == 0;
}

// 0x00442AE0
const char* __fastcall sub_00442AE0_SkipString(const char* szText)
{
    D2_ASSERT(szText, 0xAD);
    while (*szText != 0)
        szText += 1;
    return szText + 1;
}

// 0x00442B90
void __fastcall sub_00442B90_HandleReply(D2LaunchReplyStrc* pReply)
{
    const int nCount = gnValue_00798CCC;
    for (int i = 0; i < nCount; ++i)
    {
        if (gaReplyEntries_0077BDC9[i].f_32 == pReply->f_8)
            return;
    }
    gaReplyEntries_0077BDC9[nCount].f_32 = pReply->f_8;
    gaReplyEntries_0077BDC9[nCount].nValue = 0;
    gaReplyEntries_0077BDC9[nCount].wValue = pReply->wValue;
    strcpy(gaReplyEntries_0077BDC9[nCount].szName, pReply->szName);
    strcpy(gaReplyEntries_0077BDC9[nCount].szDesc, pReply->szDesc);
    gnValue_00798CCC = nCount + 1;
}

// 0x00442DD0
void __fastcall sub_00442DD0_SetPendingText(const char* szText, unsigned short wRequestId)
{
    strncpy(gszPendingText_00798AB8, szText, 0x100);
    gnPendingId_0070EBD8 = wRequestId;
}

// 0x00442E00
void __cdecl sub_00442E00_Poll()
{
    if (gnPendingId_0070EBD8 != -1)
    {
        sub_0044A610_SendText(gszPendingText_00798AB8, gnPendingId_0070EBD8);
        gwOtherRequestId_0077BBE0 = gnPendingId_0070EBD8;
        gnPendingId_0070EBD8 = -1;
    }
}

// 0x00443130
void __cdecl sub_00443130_Reset()
{
    sub_004F95C0_ControlDestroy(&gpControl_00798BC8);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD4);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD8);
    sub_004F95C0_ControlDestroy(&gpControl_00798BC0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BC4);
    sub_004F95C0_ControlDestroy(&gpControl_00798BCC);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BDC);
    sub_004F95C0_ControlDestroy(&gpControl_00798BE0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BE4);
    sub_004F95C0_ControlDestroy(&gpControl_00798BE8);
    sub_004FA450_SetActive(gpControl_0077B080);
}

// 0x00443220
void __cdecl sub_00443220_DestroyControls()
{
    sub_004F95C0_ControlDestroy(&gpControl_00798BEC);
    sub_004F95C0_ControlDestroy(&gpControl_00798BF0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BF4);
    sub_004F95C0_ControlDestroy(&gpControl_00798BF8);
    sub_004F95C0_ControlDestroy(&gpControl_00798BFC);
    sub_004F95C0_ControlDestroy(&gpControl_00798C00);
    sub_004F95C0_ControlDestroy(&gpControl_00798C04);
    sub_004F95C0_ControlDestroy(&gpControl_00798C08);
    sub_004F95C0_ControlDestroy(&gpControl_00798C2C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C30);
    sub_004F95C0_ControlDestroy(&gpControl_00798C34);
    sub_004F95C0_ControlDestroy(&gpControl_00798C38);
    sub_004F95C0_ControlDestroy(&gpControl_00798C3C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C28);
    sub_004F95C0_ControlDestroy(&gpControl_00798C48);
    sub_004F95C0_ControlDestroy(&gpButton_00798C40);
    sub_004F95C0_ControlDestroy(&gpControl_00798C4C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C50);
    sub_004F95C0_ControlDestroy(&gpControl_00798C54);
    sub_004F95C0_ControlDestroy(&gpControl_00798C58);
    sub_004F95C0_ControlDestroy(&gpControl_00798C5C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C60);
    sub_004F95C0_ControlDestroy(&gpControl_00798C44);
    sub_004F95C0_ControlDestroy(&gpControl_00798C14);
    sub_004F95C0_ControlDestroy(&gpControl_00798C18);
    sub_004F95C0_ControlDestroy(&gpControl_00798C1C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C20);
    sub_004F95C0_ControlDestroy(&gpControl_00798C24);
    sub_004F95C0_ControlDestroy(&gpControl_00798C0C);
    sub_004F95C0_ControlDestroy(&gpControl_00798C10);
    sub_004FA450_SetActive(gpControl_0077B080);
    sub_0043D990();
}

// 0x00443D50
void __cdecl sub_00443D50_CreateControls()
{
    gpControl_00798C90 = CONTROL_Create(&gtControlInit_0070E860);
    D2Win_10044(gpControl_00798C90, D2LANG_GetStringFromTblIndex(0x1493));
    gpControl_00798C94 = CONTROL_Create(&gtControlInit_0070E890);
    D2Win_10044(gpControl_00798C94, D2LANG_GetStringFromTblIndex(0x1494));
    gpControl_00798C98 = CONTROL_Create(&gtControlInit_0070E8C0);
    D2Win_10044(gpControl_00798C98, D2LANG_GetStringFromTblIndex(0x1496));
    gpControl_00798C9C = CONTROL_Create(&gtControlInit_0070E8F0);
    D2Win_10044(gpControl_00798C9C, D2LANG_GetStringFromTblIndex(0x1497));
    gpControl_00798CA8 = CONTROL_Create(&gtControlInit_0070E9B0);
    D2Win_10044(gpControl_00798CA8, D2LANG_GetStringFromTblIndex(0x1492));
}

// 0x00443E10
void __cdecl sub_00443E10()
{
    if (gnSubmitMode_00798CAC)
    {
        if (gnSubmitMode_00798CAC == 1)
        {
            sub_004F95C0_ControlDestroy(&gpControl_00798C64);
            sub_004F95C0_ControlDestroy(&gpControl_00798C68);
            sub_004F95C0_ControlDestroy(&gpControl_00798C6C);
            sub_004F95C0_ControlDestroy(&gpControl_00798C70);
            sub_004F95C0_ControlDestroy(&gpControl_00798C74);
        }
        else
        {
            sub_004F95C0_ControlDestroy(&gpControl_00798C78);
            sub_004F95C0_ControlDestroy(&gpControl_00798C7C);
            sub_004F95C0_ControlDestroy(&gpSubmitEditA_00798C80);
            sub_004F95C0_ControlDestroy(&gpSubmitEditB_00798C84);
            sub_004F95C0_ControlDestroy(&gpSubmitEditC_00798C88);
            sub_004F95C0_ControlDestroy(&gpControl_00798C8C);
        }
        gnSubmitMode_00798CAC = 0;
        sub_004F95C0_ControlDestroy(&gpControl_00798C90);
        sub_004F95C0_ControlDestroy(&gpControl_00798C94);
        sub_004F95C0_ControlDestroy(&gpControl_00798C98);
        sub_004F95C0_ControlDestroy(&gpControl_00798C9C);
        sub_004F95C0_ControlDestroy(&gpControl_00798CA0);
        sub_004F95C0_ControlDestroy(&gpControl_00798CA4);
        sub_004F95C0_ControlDestroy(&gpControl_00798CA8);
    }
    sub_004FA450_SetActive(gpControl_0077B080);
    sub_0043D990();
}

// 0x00443F50
void __fastcall sub_00443F50_CopyName(char* szDest)
{
    SStrCopy(szDest, gszName_00798CD4, 0x7FFFFFFF);
}

// 0x00444E20
int __cdecl sub_00444E20()
{
    sub_004F95C0_ControlDestroy(&gpControl_00798CBC);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB0);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB4);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB8);
    gnValue_00798CC0 = 0;
    sub_004FA450_SetActive(gpControl_0077B080);
    return 1;
}

// 0x00445550
int __stdcall sub_00445550(int nArg)
{
    if (sub_00500960_IsPressed(gpButton_00798C40))
    {
        sub_004F9740_SetControlState(gpControl_00798C44, 0);
        sub_004F9740_SetControlState(gpControl_00798C24, 0);
        sub_004F9740_SetControlState(gpControl_00798C1C, 1);
        sub_004F9740_SetControlState(gpControl_00798C20, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C3C, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C1C, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C20, 1);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpControl_00798C44, 1);
        sub_004F9740_SetControlState(gpControl_00798C24, 1);
        sub_004F9740_SetControlState(gpControl_00798C1C, 0);
        sub_004F9740_SetControlState(gpControl_00798C20, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C3C, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C1C, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C20, 0);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x00446820
const char* __fastcall sub_00446820_SkipNamePrefix(const char* szName)
{
    const char* pFound = SStrChr(szName, '*');
    if (pFound)
    {
        pFound += 1;
        if (*pFound != 0)
            return pFound;
    }
    return szName;
}

// 0x00446840
void __fastcall sub_00446840_CopyNamePrefix(const char* szName, char* szOut)
{
    if (*szName != '*')
    {
        const char* pFound = SStrChr(szName, '*');
        if (pFound)
        {
            memcpy(szOut, szName, pFound - szName);
            szOut[pFound - szName] = 0;
            return;
        }
    }
    SStrCopy(szOut, szName, 0x7FFFFFFF);
}

// 0x00448BD0
void __fastcall sub_00448BD0_UpdateScroll(int nDelta)
{
    int bUp = 0;
    int bDown = 0;
    const int nOld = gnChannelScroll_00798F44;
    if (gnChannelLines_00798F40 <= 11)
    {
        gnChannelScroll_00798F44 = 0;
    }
    else
    {
        gnChannelScroll_00798F44 = D2_MIN(D2_MAX(gnChannelScroll_00798F44 + nDelta, 0), gnChannelLines_00798F40 - 11);
        if (gnChannelScroll_00798F44 > 0)
            bUp = 1;
        if (gnChannelScroll_00798F44 < gnChannelLines_00798F40 - 11)
            bDown = 1;
    }
    if (gnChannelScroll_00798F44 != nOld)
        sub_00447BB0_Refresh();
    sub_004F96F0_ControlClearState(gpChatControl_0077B084, bUp);
    sub_004F96F0_ControlClearState(gpChatControl_0077B088, bDown);
    sub_004F96F0_ControlClearState(gpChatControl_0077B08C, bUp);
    sub_004F96F0_ControlClearState(gpChatControl_0077B090, bDown);
}

// 0x00449AD0
void __cdecl D2MCPClientCloseMCP()
{
    if (gpConnection_00798FB4)
    {
        sub_006BC780(gpConnection_00798FB4);
        gpConnection_00798FB4 = 0;
    }
    if (ghThread_007992A4)
    {
        WaitForSingleObject(ghThread_007992A4, 0xFFFFFFFF);
        CloseHandle(ghThread_007992A4);
        ghThread_007992A4 = 0;
    }
    if (ghConnectEvent_007992EC)
    {
        CloseHandle(ghConnectEvent_007992EC);
        ghConnectEvent_007992EC = 0;
    }
}

// 0x00449BD0
unsigned short __cdecl sub_00449BD0_GetRequestId()
{
    return gwRequestId_00798F80;
}

// 0x00449D60
void __cdecl sub_00449D60_ClearReply()
{
    memset(gData_00799108, 0, 0x18C);
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043FE40.inc"
