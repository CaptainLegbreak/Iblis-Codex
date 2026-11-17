struct D2WinControlStrc;

struct Unicode
{
    unsigned short ch;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" int __cdecl strcmp(const char*, const char*);

void __cdecl sub_0043E660_UpdateOkEnabled();                                                                // 0x0043E660
void __cdecl sub_0043EA20_Wait();                                                                           // 0x0043EA20
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
int __cdecl sub_0043EBA0_ResetControls();                                                                   // 0x0043EBA0
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __cdecl sub_0043EB30_CreateControls();                                                                 // 0x0043EB30
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl);                                    // 0x004FB950
int __fastcall D2Win_10055(D2WinControlStrc* pTextBox);                                                     // 0x004FBAB0
Unicode* __fastcall D2Win_10196(D2WinControlStrc* pTextBox, int nLineNum, int nColumnNum);                  // 0x004FBB90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
void __fastcall sub_0044AA10_SendPacket11(unsigned char nArg1, unsigned short nArg2);                       // 0x0044AA10

extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpList_0077BD00;                                                                   // 0x0077BD00
extern int gnColor_0077AD74;                                                                                // 0x0077AD74
extern int gnSelectLine_0070CD68;                                                                           // 0x0070CD68
extern int gnSelectIdA_0070CD7C;                                                                            // 0x0070CD7C
extern int gnSelectFlag_0070CD6C;                                                                           // 0x0070CD6C
extern int gnSelectLinePrev_0070CD64;                                                                       // 0x0070CD64
extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
extern char gnSelectModeB_0070CD63;                                                                         // 0x0070CD63
extern int gnSelectIdB_0070CD80;                                                                            // 0x0070CD80
unsigned long gdwSelectTime_0077BD5C;                                                                       // 0x0077BD5C
extern int gnSelection_0077BBF4;                                                                            // 0x0077BBF4

// 0x00440110
int __stdcall sub_00440110_OnEditChange(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043E660_UpdateOkEnabled();
    return 1;
}

// 0x00440120
int __stdcall sub_00440120_OnClearEdit(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
    sub_0043EA20_Wait();
    return 1;
}

// 0x00440240
int __stdcall sub_00440240_OnReset(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043EBA0_ResetControls();
    sub_0043F8C0_ResetLaunchState();
    return 1;
}

// 0x00440260
int __stdcall sub_00440260_OnBack(SMSGHANDLER_PARAMS* pMsg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    sub_0043F8C0_ResetLaunchState();
    sub_0043EB30_CreateControls();
    return 1;
}

// 0x004402A0
int __cdecl sub_004402A0_FindDashLine()
{
    char szText[0x100];
    int nLine = sub_004FB950_GetFirstVisible(gpList_0077BD00);
    const int nCount = D2Win_10055(gpList_0077BD00);
    const int nEnd = (nLine + nCount < gnColor_0077AD74) ? nLine + nCount : gnColor_0077AD74;

    for (; nLine < nEnd; ++nLine)
    {
        const Unicode* pText = D2Win_10196(gpList_0077BD00, nLine, 0);
        sub_00526F70(szText, pText, 0x100);
        if (!strcmp(szText, "-"))
        {
            gnSelectIdA_0070CD7C = gnSelectLine_0070CD68 = nLine / 16 * 16;
            return 1;
        }
    }
    return 0;
}

// 0x00440350
int __stdcall sub_00440350_OnIdle(SMSGHANDLER_PARAMS* pMsg)
{
    if (GetTickCount() > gdwSelectTime_0077BD5C && gpList_0077BD00
        && (sub_004402A0_FindDashLine() || gnSelectFlag_0070CD6C)
        && (gnSelection_0077BBF4 != gnSelectIdA_0070CD7C || gnSelectLine_0070CD68 != gnSelectLinePrev_0070CD64))
    {
        gnSelectModeB_0070CD63 = gnSelectModeA_0070CD62;
        gnSelectIdB_0070CD80 = gnSelectIdA_0070CD7C;
        sub_0044AA10_SendPacket11(gnSelectModeA_0070CD62, gnSelectLine_0070CD68);
        gdwSelectTime_0077BD5C = GetTickCount() + 1000;
        gnSelection_0077BBF4 = gnSelectIdB_0070CD80;
        gnSelectLinePrev_0070CD64 = gnSelectLine_0070CD68;
    }
    return 1;
}

#include "gen/data/Source/D2Client/00440110_sub_00440110_OnEditChange.inc"
