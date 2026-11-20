#include "D2Launch.h"
#include "D2MultiTypes.h"

struct Unicode
{
    unsigned short wChar;
};
struct SMSGHANDLER_PARAMS;

#pragma pack(push, 1)
#pragma pack(pop)

struct D2LaunchCharEntryStrc
{
    char szName[0x324];
    int nFlags;
    char unk0x328[0x0C];
    int bShared;
    D2CelFileStrc* pCellFile;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
};

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
extern "C" void __cdecl sub_00432EF0_ConfigureLanguageLayout(); // 0x00432EF0
int __stdcall sub_00433020_PollConnectA(int nArg);                                                                       // 0x00433020
int __stdcall sub_00433060_PollConnectB(int nArg);                                                                       // 0x00433060
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380
extern "C" int __stdcall sub_0043A460_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460
void __cdecl sub_0043A730_UpdateButtons();                                                                                // 0x0043A730
void __stdcall sub_00449E50_SetValue(int nValue);                                                                    // 0x00449E50
void __fastcall sub_0044A7A0_SendPacket0A(const char* szName, unsigned short nArg);                                      // 0x0044A7A0
void __fastcall sub_0044A810_SendPacket18(const char* szName);                                                           // 0x0044A810
void __cdecl sub_0044AA80_SendPacket13();                                                                                // 0x0044AA80
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile);                          // 0x004F91A0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740
int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl);                                       // 0x004FB990
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
int __stdcall sub_004FD0B0_SetColor(D2WinControlStrc* pControl, int nColor, int nValue);                    // 0x004FD0B0
int __stdcall sub_00500810(D2WinControlStrc* pControl, int nArg);                                           // 0x00500810
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag);                                   // 0x005041B0
int __stdcall sub_00518150(D2FuncRecordStrc* pRecord, int nIndex);                                          // 0x00518150
D2FuncTable_0077ABF0Strc* __cdecl sub_00518C00();                                                           // 0x00518C00
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern "C" const char* const gapszSkyPalette_006D3A08[2];                                                   // 0x006D3A08
extern int gnSelectionA_0070CC04;                                                                           // 0x0070CC04
extern D2WinControlStrc* gpControl_00779590;                                                                // 0x00779590
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
D2WinControlStrc* gpList_0077995C;                                                                          // 0x0077995C
D2WinControlStrc* gpList_00779960;                                                                          // 0x00779960
D2WinControlStrc* gpList_00779964;                                                                          // 0x00779964
extern int gnListPos_0077996C;                                                                              // 0x0077996C
D2LaunchSlotStrc** gppSlots_00779988;                                                                       // 0x00779988
int gdwGlobal_0077998C;                                                                                     // 0x0077998C
extern D2WinControlStrc* gpControl_007799EC;                                                                // 0x007799EC
extern D2WinControlStrc* gpControl_007799F0;                                                                // 0x007799F0
D2WinControlStrc* gpControl_007799F4;                                                                       // 0x007799F4
extern D2WinControlStrc* gpControl_007799F8;                                                                // 0x007799F8
extern int ganRowValues_007799FC[];                                                                         // 0x007799FC
extern D2WinControlStrc* gpControl_00779A1C;                                                                // 0x00779A1C
D2WinControlStrc* gpControl_00779B60;                                                                       // 0x00779B60
extern D2WinControlStrc* gpControl_00779B64;                                                                // 0x00779B64
D2WinControlStrc* gpControl_00779C68;                                                                       // 0x00779C68
extern int gbFlag_00779C6C;                                                                                 // 0x00779C6C
extern D2WinControlStrc* gpControl_00779C70;                                                                // 0x00779C70
extern D2WinControlStrc* gpControl_00779C74;                                                                // 0x00779C74
extern D2WinControlStrc* gpControl_00779C78;                                                                // 0x00779C78
extern D2WinControlStrc* gpControl_00779C7C;                                                                // 0x00779C7C
D2WinControlStrc* gpControl_00779C80;                                                                       // 0x00779C80
extern char gszName_00779C88[];                                                                             // 0x00779C88
extern D2WinControlStrc* gpControl_00779D88;                                                                // 0x00779D88
D2WinControlStrc* gpControl_00779D90;                                                                       // 0x00779D90
D2WinControlStrc* gpControl_00779D94;                                                                       // 0x00779D94
extern D2WinControlStrc* gpControl_00779D9C;                                                                // 0x00779D9C
unsigned long gdwStartTick_00779DB4;                                                                        // 0x00779DB4
extern D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                          // 0x00779DBC
D2LaunchCharEntryStrc* gpCharEntry_00779DC0;                                                                // 0x00779DC0
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4
extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8
extern D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10;                                                      // 0x0077AC10
#define gdwFlags_0077AC34 (gtCharSaveHeader_0077AC10.dwFlags)
extern D2WinControlStrc* gpControls_0077ADA8[];                                                             // 0x0077ADA8
extern D2CriticalSectionStrc gtChatLock_0077AE28;                                                           // 0x0077AE28
extern D2WinControlStrc* gapControls_0077B050[2];                                                           // 0x0077B050
extern D2WinControlStrc* gpControl_0077B080;                                                                // 0x0077B080
extern char gaszHistory_0077B1D8[10][0x100];                                                                // 0x0077B1D8
extern int gnControlCount_0077BBE8;                                                                         // 0x0077BBE8
extern unsigned long gdwConnectTime_0077BBF0;                                                               // 0x0077BBF0
extern D2WinControlStrc* gpControl_0077BC40;                                                                // 0x0077BC40
extern D2CelFileStrc* gpCellFile_0077BC6C;                                                                 // 0x0077BC6C
extern D2WinControlStrc* gpControl_0077BCDC;                                                                // 0x0077BCDC
extern D2WinControlStrc* gpControl_0077BCE0;                                                                // 0x0077BCE0
extern D2WinControlStrc* gpControl_0077BCE4;                                                                // 0x0077BCE4
extern D2WinControlStrc* gpControl_0077BCE8;                                                                // 0x0077BCE8
extern D2WinControlStrc* gpButton_0077BCEC;                                                                 // 0x0077BCEC
extern D2WinControlStrc* gpControl_0077BCF0;                                                                // 0x0077BCF0
extern D2WinControlStrc* gpControl_0077BCFC;                                                                // 0x0077BCFC
extern int gdwGlobal_0077BD50;                                                                              // 0x0077BD50
extern D2ChatMessageStrc* gpChatQueueHead_0077BDAC;                                                         // 0x0077BDAC
D2ChatMessageStrc* gpChatQueueTail_0077BDB0;                                                                // 0x0077BDB0

// 0x00430520
void __cdecl sub_00430520()
{
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xCD);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0xCE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = sub_0042F3A0_CreateFromTemplate(0xCF);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14B7), 0, 0, 0);
}

// 0x004306C0
void __cdecl sub_004306C0_UpdateOk()
{
    const Unicode* pName = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    int bOk = 0;
    if (pName && pPassword)
    {
        int nNameLength = sub_00526800(pName);
        int nPasswordLength = sub_00526800(pPassword);
        if (nNameLength >= 1 && nNameLength <= 50 && nPasswordLength >= 1 && nPasswordLength <= 13)
            bOk = 1;
    }
    if (gpControl_00779594)
        sub_004F96F0_ControlClearState(gpControl_00779594, bOk);
}

// 0x00430A20
int __cdecl sub_00430A20_FreeSlots()
{
    if (!gppSlots_00779988)
        return 1;
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        D2LaunchSlotStrc* pSlot = gppSlots_00779988[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, ".\\Src\\MainMenus.cpp", 0x113A, 0);
            D2_ASSERT(gppSlots_00779988[i]->szName, 0x113B);
            sub_0040B3C0(gppSlots_00779988[i]->szName, ".\\Src\\MainMenus.cpp", 0x113C, 0);
            sub_0040B3C0(gppSlots_00779988[i], ".\\Src\\MainMenus.cpp", 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots_00779988, ".\\Src\\MainMenus.cpp", 0x1141, 0);
    gppSlots_00779988 = 0;
    return 1;
}

// 0x00430B50
char* __fastcall sub_00430B50_GetSlotName(int nIndex)
{
    D2LaunchSlotStrc* pSlot = gppSlots_00779988[nIndex];
    D2_ASSERT(pSlot, 0x115C);
    return pSlot->szName;
}

// 0x00430C80
void __cdecl sub_00430C80_FillList()
{
    for (int i = 0; i < 50; i++)
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_00779964, "The End");
    gnListPos_0077996C = sub_004FB950_GetFirstVisible(gpList_00779964);
}

// 0x00430EF0
void __cdecl sub_00430EF0_SyncLists()
{
    int nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    int nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    int nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    while (nSecond > nThird)
    {
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
        nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    }
    while (nSecond < nThird)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    }
    while (nFirst > nSecond)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
    }
    while (nFirst < nSecond)
    {
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
        nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    }
    D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431570
void __fastcall sub_00431570_CreateControls(int bFlag)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    if (bFlag)
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x5578), 0, 0, 0);
    else
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
}

// 0x004325B0
void __cdecl sub_004325B0_CreateScreen()
{
    sub_0042F480_Reset();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(6);
    sub_00500810(pControl, 0);
    pControl = sub_0042F430_CreateControl(7);
    sub_00500810(pControl, 0);
    sub_0042F430_CreateControl(8);
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_0042F3A0_CreateFromTemplate(0x4D);
    sub_0042F3A0_CreateFromTemplate(0x63);
    sub_0042F3A0_CreateFromTemplate(0x64);
    pControl = sub_0042F3A0_CreateFromTemplate(0x5F);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146B), 0, 0, 0);
    D2WinControlStrc* pList = sub_0042F3A0_CreateFromTemplate(0x60);
    int nOld = sub_00502EF0(5);
    int nValue = D2Win_10125();
    sub_00502EF0(nOld);
    sub_004FC9B0_SetText(pList, D2LANG_GetStringFromTblIndex(0x146C), 0, 0, 0);
    sub_004FB740(pList, nValue / -10, 0);
    pControl = sub_0042F3A0_CreateFromTemplate(0x61);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146D), 0, 0, 0);
    sub_004FB740(pControl, nValue / -10, 0);
    pControl = sub_0042F3A0_CreateFromTemplate(0x62);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B77), 0, 0, 0);
}

// 0x00433450
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    sub_00433380_ShowMessage(pText, pfnDone, 1);
}

// 0x00434700
int __stdcall sub_00434700(SMSGHANDLER_PARAMS* pMsg)
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    int nSelection = sub_004FB990_GetSelection(gpControl_00779590);
    if (nSelection != -1)
    {
        nSelection += 1;
        sub_00518150(pRecord, nSelection);
        SRegSaveString("Diablo II", "Preferred Realm", 0, sub_005180E0(pRecord, nSelection));
    }
    sub_0042F480_Reset();
    sub_004336C0();
    return 1;
}

// 0x00434960
int __fastcall sub_00434960_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
        int nResult = sub_00432480(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    sub_0042F6E0();
    sub_0044A7A0_SendPacket0A(pEntry->szName, 0);
    sub_004FA590_RunLoop(sub_00433020_PollConnectA);
    return 1;
}

// 0x004349B0
int __fastcall sub_004349B0_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
        int nResult = sub_00432480(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    sub_0042F6E0();
    sub_0044A810_SendPacket18(pEntry->szName);
    sub_004FA590_RunLoop(sub_00433060_PollConnectB);
    return sub_00449C00() == 0;
}

// 0x00435E00
int __stdcall sub_00435E00_Back(int nArg)
{
    sub_00435580();
    return 1;
}

// 0x00437BF0
void __cdecl sub_00437BF0_CreateControls()
{
    gpControl_007799EC = sub_0042F3A0_CreateFromTemplate(0x6D);
    D2Win_10033(gpControl_007799EC, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
    gpControl_00779C7C = sub_0042F3A0_CreateFromTemplate(0x6E);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
    gpControl_00779D9C = sub_0042F3A0_CreateFromTemplate(0x6F);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
    gpNameControl_007799E8 = sub_0042F3A0_CreateFromTemplate(0x70);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl_007799E8, 1);
    gpControl_00779D88 = sub_0042F3A0_CreateFromTemplate(0x71);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
    gpControl_00779C74 = sub_0042F3A0_CreateFromTemplate(0x72);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
}

// 0x00438EA0
void __cdecl sub_00438EA0_FreeCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    while (pEntry)
    {
        D2LaunchCharEntryStrc* pNext = pEntry->pNext;
        sub_005041B0_Destroy(pEntry->pCellFile, 1);
        sub_0040B3C0(pEntry, ".\\Src\\CharSel.cpp", 0x518, 0);
        pEntry = pNext;
    }
    gpCharList_00779DBC = 0;
    gdwGlobal_00779DC4 = 0;
    gnTopRow_00779DC8 = 0;
    gbFlag_00779DD8 = 0;
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->bShared)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x004390A0
int __cdecl sub_004390A0_UpdateSelection()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    int n = 0;
    if (!gdwGlobal_00779DC4)
        gnSelected_0070CC00 = 0;
    int nRow = gnSelected_0070CC00 - gnTopRow_00779DC8;
    int bShow;
    if (nRow >= 0 && nRow < gnVisibleRows_0070CC0C)
    {
        sub_004FD0B0_SetColor(gpControl_00779D94, (nRow % 2) ? 0x135 : 0x25, ganRowValues_007799FC[nRow]);
        bShow = 1;
    }
    else
    {
        bShow = 0;
    }
    sub_004F9740_ControlSetState(gpControl_00779D94, bShow);
    for (; pEntry && gnSelected_0070CC00 != n; n++)
        pEntry = pEntry->pNext;
    sub_004F96F0_ControlClearState(gpControl_007799F4, 1);
    sub_004F96F0_ControlClearState(gpControl_00779C68, 1);
    if (!pEntry)
    {
        sub_004F96F0_ControlClearState(gpControl_00779C80, 0);
        sub_004F96F0_ControlClearState(gpControl_007799F4, 0);
        sub_004F96F0_ControlClearState(gpControl_00779C68, 0);
        sub_004F9740_ControlSetState(gpControl_00779D94, 0);
        return 1;
    }
    sub_004F96F0_ControlClearState(gpControl_00779C80, 1);
    if (pEntry->nFlags & 0x20)
        sub_004F96F0_ControlClearState(gpControl_00779C80, 0);
    sub_004F96F0_ControlClearState(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    if (gnLaunchMode_007795EC == 1 && gbFlag_00779DD8)
        sub_004F96F0_ControlClearState(gpControl_00779D90, 0);
    sub_004FB6A0_ClearText(gpControl_00779B60);
    sub_004FCFF0_SetTextA(gpControl_00779B60, pEntry->szName, 0);
    return 1;
}

// 0x00439780
void __fastcall sub_00439780_PickClass(int nClass, int bExpansion)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xAC);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xAB);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2723), 7, 0, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0xA8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = sub_0042F3A0_CreateFromTemplate(0xA9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xAA);
    sub_004F96F0_ControlClearState(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    if ((!bExpansion && nClass >= 8) || nClass >= 10)
        sub_004F96F0_ControlClearState(pControl, 1);
    sub_0042F3A0_CreateFromTemplate(0xAD);
}

// 0x00439CC0
void __cdecl sub_00439CC0_CreateControls()
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0xD7);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = sub_0042F3A0_CreateFromTemplate(0xD8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x142B), 0, 0, 0);
}

// 0x0043A270
void __cdecl sub_0043A270_UpdateStatus()
{
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    if (GetTickCount() - gdwStartTick_00779DB4 > 1000)
        sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(0x2B39), 4, 0, 0);
}

// 0x0043A5D0
void __cdecl sub_0043A5D0_ShowMessage()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x1419);
    const Unicode* pText;
    if (gnLaunchMode_007795EC == 1)
        pText = D2LANG_GetStringFromTblIndex(0x141B);
    else
        pText = D2LANG_GetStringFromTblIndex(0x141A);
    gnSelectionA_0070CC04 = gdwGlobal_00779DC4;
    sub_0043A460_CreateNotice(pTitle, pText, 1, 0xC);
}

// 0x0043A650
void __cdecl sub_0043A650_Refresh()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->bShared)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
    sub_004FB6A0_ClearText(gpControl_00779B60);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    sub_004F96F0_ControlClearState(gpControl_007799F4, 0);
    sub_004F96F0_ControlClearState(gpControl_00779C68, 0);
    sub_004F96F0_ControlClearState(gpControl_007799F8, 0);
    sub_004F96F0_ControlClearState(gpControl_00779A1C, 0);
    sub_004F96F0_ControlClearState(gpControl_00779B64, 0);
    sub_004F9740_ControlSetState(gpControl_00779D94, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_004F96F0_ControlClearState(gpControl_00779C80, 0);
        sub_004F96F0_ControlClearState(gpControl_00779D90, 0);
    }
    else
    {
        sub_004F9740_ControlSetState(gpControl_00779C78, 0);
    }
}

// 0x0043A950
int __stdcall sub_0043A950(SMSGHANDLER_PARAMS* pMsg)
{
    SStrCopy(gData_00779A40, gszName_00779C88, 0x7FFFFFFF);
    SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
    if (gnLaunchMode_007795EC == 1)
    {
        sub_0042F3F0_DestroyControls();
        sub_0043A730_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x0043B7A0
int __fastcall sub_0043B7A0_InitFuncTable(D2LaunchRecordStrc* pRecord)
{
    if (!pRecord->pFuncTable)
    {
        gpFuncTable_0077ABF0 = sub_00518C00();
        D2_ASSERT(gpFuncTable_0077ABF0, 0x94);
        pRecord->pFuncTable = gpFuncTable_0077ABF0;
        gpFuncTable_0077ABF0->pfnInit(pRecord);
    }
    return 1;
}

// 0x0043B820
void __cdecl sub_0043B820_Clear()
{
    gdwGlobal_0077AC04 = 0;
}

// 0x0043B9A0
void __cdecl sub_0043B9A0()
{
    if (gpFuncTable_0077ABF0)
    {
        gdwGlobal_00779DA4 = 1;
        gpLaunchRecord_007795D4->nByte361 = 0;
        gpLaunchRecord_007795D4->nByte381 = 0;
        OutputDebugStringA("Disconnect from BNET\n");
        D2MCPClientCloseMCP();
        gpFuncTable_0077ABF0->pfnSlot10();
    }
}

// 0x0043C4F0
void __cdecl sub_0043C4F0()
{
    sub_0042F480_Reset();
    sub_0042F430_CreateControl(8);
    sub_0042F430_CreateControl(6);
    sub_0042F430_CreateControl(7);
    sub_0042F2E0_ReadPaletteFiles(gapszSkyPalette_006D3A08[0], gapszSkyPalette_006D3A08[1]);
    sub_00432EF0_ConfigureLanguageLayout();
}

// 0x0043C6A0
void __fastcall sub_0043C6A0(int bSet)
{
    if (bSet)
        gdwFlags_0077AC34 |= 2;
}

// 0x0043D990
void __cdecl sub_0043D990_ActivateEdit()
{
    if (gpChatEdit_0077BD94)
        sub_004F91C0(gpChatEdit_0077BD94);
}

// 0x0043DB20
void __cdecl sub_0043DB20_DestroyControls()
{
    sub_004F95C0_ControlDestroy(&gpControl_0077BCDC);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE0);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE4);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE8);
    sub_004F95C0_ControlDestroy(&gpButton_0077BCEC);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCF0);
    sub_004F95C0_ControlDestroy(&gpEdit_0077BCF4);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCFC);
    sub_004FA450_SetActive(gpControl_0077B080);
    if (gpChatEdit_0077BD94)
        sub_004F91C0(gpChatEdit_0077BD94);
}

// 0x0043DC30
int __cdecl sub_0043DC30_GetStatus()
{
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
        return -1;
    return 0;
}

// 0x0043E130
void __cdecl sub_0043E130_Reset()
{
    for (int i = 0; i <= 1; i++)
    {
        if (gapControls_0077B050[i])
        {
            sub_004F95C0_ControlDestroy(&gapControls_0077B050[i]);
            gapControls_0077B050[i] = 0;
        }
    }
    if (gpControl_0077BC40)
    {
        sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
        gpControl_0077BC40 = 0;
    }
}

// 0x0043E570
int __cdecl sub_0043E570()
{
    D2ChatMessageStrc* pMessage = (D2ChatMessageStrc*)FOG_Alloc(sizeof(D2ChatMessageStrc), ".\\Src\\ChatDlg.cpp", 0xC1D, 0);
    memset(pMessage, 0, sizeof(D2ChatMessageStrc));
    if (pMessage)
    {
        pMessage->szText = 0;
        pMessage->nColor = 0;
        pMessage->bClear = 1;
        EnterCriticalSection(&gtChatLock_0077AE28);
        if (gpChatQueueHead_0077BDAC)
            gpChatQueueTail_0077BDB0->pNext = pMessage;
        else
            gpChatQueueHead_0077BDAC = pMessage;
        gpChatQueueTail_0077BDB0 = pMessage;
        LeaveCriticalSection(&gtChatLock_0077AE28);
    }
    return 1;
}

// 0x0043EA20
void __cdecl sub_0043EA20_Wait()
{
    for (int i = 0; i < gnControlCount_0077BBE8; i++)
        sub_004F95C0_ControlDestroy(&gpControls_0077ADA8[i]);
    gnControlCount_0077BBE8 = 0;
    sub_004FA450_SetActive(gpControl_0077B080);
    gdwConnectTime_0077BBF0 = 0;
}

// 0x0043F4D0
void __cdecl sub_0043F4D0()
{
    for (int i = 0; i < 10; i++)
        gaszHistory_0077B1D8[i][0] = 0;
    gnHistoryIndex_0070CD74 = -1;
    gdwGlobal_0077BD50 = 0;
}

// 0x0043F560
void __fastcall sub_0043F560_Disable(D2WinControlStrc* pControl)
{
    CONTROL_SetCellFile(pControl, gpCellFile_0077BC6C);
    sub_004F96F0_ControlClearState(pControl, 0);
}

// 0x0043F850
int __cdecl sub_0043F850()
{
    sub_0044AA80_SendPacket13();
    sub_00449E50_SetValue(0);
    return 1;
}

#include "gen/data/Source/D2Launch/Src/CharSel_00430520.inc"
