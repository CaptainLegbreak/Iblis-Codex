struct D2WinControlStrc;
struct D2WinControlInitStrc;
struct D2CompositeUnitStrc;

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    char szName0x8D[0x30];
};

struct T0043E860
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
    T0043E860* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strtok(char* szText, const char* szDelim);                                         // 0x0068264F
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
int __fastcall sub_00440CA0(const char* szName, char* szA, char* szB, char* szC);                           // 0x00440CA0
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __cdecl sub_00443D50_CreateControls();                                                                 // 0x00443D50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext);                  // 0x004FDDD0
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox);                                                     // 0x004FDD00
const char* __fastcall sub_00446820_SkipNamePrefix(const char* szName);                                     // 0x00446820
void __cdecl sub_0043D990();                                                                                // 0x0043D990
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* pCompositeUnit);                                    // 0x00505330
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags);                                // 0x00505360
int __cdecl sub_0043DB10();                                                                                 // 0x0043DB10
void __cdecl sub_004477A0_Refresh();                                                                        // 0x004477A0

extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8
extern D2WinControlInitStrc gtControlInit_0070E680;                                                         // 0x0070E680
extern D2WinControlInitStrc gtControlInit_0070E6B0;                                                         // 0x0070E6B0
extern D2WinControlInitStrc gtControlInit_0070E6E0;                                                         // 0x0070E6E0
extern D2WinControlInitStrc gtControlInit_0070E710;                                                         // 0x0070E710
extern D2WinControlInitStrc gtControlInit_0070E740;                                                         // 0x0070E740
extern D2WinControlInitStrc gtControlInit_0070E770;                                                         // 0x0070E770
extern D2WinControlInitStrc gtControlInit_0070E7A0;                                                         // 0x0070E7A0
extern D2WinControlInitStrc gtControlInit_0070E7D0;                                                         // 0x0070E7D0
extern D2WinControlInitStrc gtControlInit_0070E800;                                                         // 0x0070E800
extern D2WinControlInitStrc gtControlInit_0070E830;                                                         // 0x0070E830
extern D2WinControlInitStrc gtControlInit_0070E920;                                                         // 0x0070E920
extern D2WinControlInitStrc gtControlInit_0070E950;                                                         // 0x0070E950
extern D2WinControlInitStrc gtControlInit_0070E980;                                                         // 0x0070E980
extern int gnSelectedLine_0070EC1C;                                                                         // 0x0070EC1C
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
int gbCheck_0077BD58;                                                                                       // 0x0077BD58
extern D2WinControlStrc* gpControl_00798C64;                                                                // 0x00798C64
extern D2WinControlStrc* gpControl_00798C68;                                                                // 0x00798C68
extern D2WinControlStrc* gpControl_00798C6C;                                                                // 0x00798C6C
extern D2WinControlStrc* gpControl_00798C70;                                                                // 0x00798C70
D2WinControlStrc* gpControl_00798C74;                                                                       // 0x00798C74
extern D2WinControlStrc* gpControl_00798C78;                                                                // 0x00798C78
extern D2WinControlStrc* gpControl_00798C7C;                                                                // 0x00798C7C
D2WinControlStrc* gpSubmitEditA_00798C80;                                                                   // 0x00798C80
D2WinControlStrc* gpSubmitEditB_00798C84;                                                                   // 0x00798C84
D2WinControlStrc* gpSubmitEditC_00798C88;                                                                   // 0x00798C88
extern D2WinControlStrc* gpControl_00798C8C;                                                                // 0x00798C8C
D2WinControlStrc* gpControl_00798CA0;                                                                       // 0x00798CA0
D2WinControlStrc* gpControl_00798CA4;                                                                       // 0x00798CA4
extern int gnSubmitMode_00798CAC;                                                                           // 0x00798CAC
extern char gszName_00798CD4[];                                                                             // 0x00798CD4
extern int gnPendingValueA_00798CE4;                                                                        // 0x00798CE4
extern int gnPendingValueB_00798CE8;                                                                        // 0x00798CE8
extern T0043E860* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48

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

#include "gen/data/Source/D2Client/00443D10_sub_00443D10_SetPendingName.inc"
