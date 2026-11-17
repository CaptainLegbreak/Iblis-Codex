struct D2WinControlStrc;
struct Unicode;

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    char wFlags[2];
    char unk0x1F1[0x170];
    char nByte361;
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0
void __fastcall sub_004423B0_RunCommand(char* szText);                                                      // 0x004423B0
void __fastcall sub_004481F0_EchoText(char* szText);                                                        // 0x004481F0
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
int __fastcall D2Win_10055(D2WinControlStrc* pTextBox);                                                     // 0x004FBAB0
int __fastcall sub_004FB910_GetLineCount(D2WinControlStrc* pTextBox);                                       // 0x004FB910
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30

extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern int gbChatSetup_0077BBF8;                                                                            // 0x0077BBF8
extern int gbCheck_0077BD58;                                                                                // 0x0077BD58
extern D2WinControlStrc* gpClassButtons_0077BC98[8];                                                        // 0x0077BC98
extern int gbExpansionClasses_0070CD70;                                                                     // 0x0070CD70
extern char gszChatBuffer_0077AE40[0x200];                                                                  // 0x0077AE40
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern D2WinControlStrc* gpChatTextBox_0077BD8C;                                                            // 0x0077BD8C

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
        sub_004481F0_EchoText(gszChatBuffer_0077AE40);
    }
    sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
    const int nFirst = D2Win_10055(gpChatTextBox_0077BD8C);
    const int nCount = sub_004FB910_GetLineCount(gpChatTextBox_0077BD8C);
    if (nCount > nFirst)
        D2Win_10053(gpChatTextBox_0077BD8C, nCount - nFirst);
    return 1;
}
