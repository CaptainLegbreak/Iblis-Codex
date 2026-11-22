#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

struct SMSGHANDLER_PARAMS;

struct D2CompositeUnitStrc;

struct D2CelFileStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
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

D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0

void __cdecl MAINMENUS_DestroyControls();                                                                // 0x0042F3F0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId);                                           // 0x0042F430

void __cdecl MAINMENUS_Reset();                                                                          // 0x0042F480

void __cdecl MAINMENUS_ShowConnectingPopup();                                                                                // 0x0042F6E0

extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0

int __stdcall MAINMENUS_PollCharDelete(int nArg);                                                                       // 0x00433020

int __stdcall MAINMENUS_PollCharUpgrade(int nArg);                                                                       // 0x00433060

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380

extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460

void __cdecl CHARSEL_UpdateButtons();                                                                                // 0x0043A730

void __stdcall sub_00449E50_SetValue(int nValue);                                                                    // 0x00449E50

void __fastcall WINMAIN_SendMcpCharDelete(const char* szName, unsigned short nArg);                                      // 0x0044A7A0

void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szName);                                                           // 0x0044A810

void __cdecl VIEW_SendMcpCancelGameCreate();                                                                                // 0x0044AA80

int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox);                                                                  // 0x004F91C0

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

int gbFlag_00779C6C; // 0x00779C6C

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

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

void __fastcall sub_A15_UseText(const Unicode* pText);

void __cdecl sub_00439CC0_CreateControls(); // 0x00439CC0

char* __fastcall CHARSEL_GetSlotName(int nIndex); // 0x00430B50

void __cdecl CHARSEL_UpdateStatus(); // 0x0043A270

#pragma intrinsic(memset)

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

D2CompositeUnitStrc* __stdcall sub_005066C0_CreateComposite(int nSel, int nMode, unsigned char* pFlags, unsigned char* pColors);

void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0

void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260

int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0

void __cdecl sub_00438560_Refresh();

int gnLastValue_00779DCC; // 0x00779DCC

int gnState_00779DAC; // 0x00779DAC

char* gpszName_00779DB0; // 0x00779DB0

// 0x00430520
void __cdecl sub_00430520()
{
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xCD);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xCE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xCF);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14B7), 0, 0, 0);
}

// 0x004306C0
void __cdecl CHARSEL_UpdateLoginOk()
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
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControl_00779594, bOk);
}


// 0x00430B50
char* __fastcall CHARSEL_GetSlotName(int nIndex)
{
    D2LaunchSlotStrc* pSlot = gppSlots_00779988[nIndex];
    D2_ASSERT(pSlot, 0x115C);
    return pSlot->szName;
}

// 0x00430C80
void __cdecl CHARSEL_FillCreditsList()
{
    for (int i = 0; i < 50; i++)
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_00779964, "The End");
    gnListPos_0077996C = sub_004FB950_GetFirstVisible(gpList_00779964);
}

// 0x00430EF0
void __cdecl CHARSEL_SyncCreditsLists()
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
void __fastcall CHARSEL_CreateExpansionDiscPopup(int bFlag)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
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
    MAINMENUS_Reset();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(6);
    sub_00500810(pControl, 0);
    pControl = MAINMENUS_CreateControl(7);
    sub_00500810(pControl, 0);
    MAINMENUS_CreateControl(8);
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateFromTemplate(0x4D);
    MAINMENUS_CreateFromTemplate(0x63);
    MAINMENUS_CreateFromTemplate(0x64);
    pControl = MAINMENUS_CreateFromTemplate(0x5F);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146B), 0, 0, 0);
    D2WinControlStrc* pList = MAINMENUS_CreateFromTemplate(0x60);
    int nOld = sub_00502EF0(5);
    int nValue = D2Win_10125();
    sub_00502EF0(nOld);
    sub_004FC9B0_SetText(pList, D2LANG_GetStringFromTblIndex(0x146C), 0, 0, 0);
    sub_004FB740(pList, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x61);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146D), 0, 0, 0);
    sub_004FB740(pControl, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x62);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B77), 0, 0, 0);
}

// 0x00433450
void __fastcall CHARSEL_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_ShowMessage(pText, pfnDone, 1);
}

// 0x00439780
void __fastcall CHARSEL_PickClass(int nClass, int bExpansion)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xAC);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAB);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2723), 7, 0, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xA8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xA9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAA);
    CONTROL_SetEnabled(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    if ((!bExpansion && nClass >= 8) || nClass >= 10)
        CONTROL_SetEnabled(pControl, 1);
    MAINMENUS_CreateFromTemplate(0xAD);
}

// 0x00434700
int __stdcall CHARSEL_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg)
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    int nSelection = sub_004FB990_GetSelection(gpControl_00779590);
    if (nSelection != -1)
    {
        nSelection += 1;
        sub_00518150(pRecord, nSelection);
        SRegSaveString("Diablo II", "Preferred Realm", 0, sub_005180E0(pRecord, nSelection));
    }
    MAINMENUS_Reset();
    sub_004336C0();
    return 1;
}

// 0x004349B0
int __fastcall CHARSEL_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharUpgrade(pEntry->szName);
    sub_004FA590_RunLoop(MAINMENUS_PollCharUpgrade);
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    return GAME_GetConnectError() == 0;
}

// 0x00434960
int __fastcall CHARSEL_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharDelete(pEntry->szName, 0);
    sub_004FA590_RunLoop(MAINMENUS_PollCharDelete);
    return 1;
}

// 0x00435E00
int __stdcall CHARSEL_Back(int nArg)
{
    sub_00435580();
    return 1;
}

// 0x00437BF0
void __cdecl CHARSEL_CreateCharInfoControls()
{
    gpControl_007799EC = MAINMENUS_CreateFromTemplate(0x6D);
    D2Win_10033(gpControl_007799EC, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
    gpControl_00779C7C = MAINMENUS_CreateFromTemplate(0x6E);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
    gpControl_00779D9C = MAINMENUS_CreateFromTemplate(0x6F);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
    gpNameControl_007799E8 = MAINMENUS_CreateFromTemplate(0x70);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl_007799E8, 1);
    gpControl_00779D88 = MAINMENUS_CreateFromTemplate(0x71);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
    gpControl_00779C74 = MAINMENUS_CreateFromTemplate(0x72);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
}

// 0x00437F60
static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

// 0x00438030
static int sub_00438030_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

// 0x004380B0
static unsigned int CHARSEL_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

// 0x00438EA0
void __cdecl CHARSEL_FreeCharList()
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
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x004390A0
int __cdecl CHARSEL_UpdateSelection()
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
    CONTROL_SetEnabled(gpControl_007799F4, 1);
    CONTROL_SetEnabled(gpControl_00779C68, 1);
    if (!pEntry)
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_007799F4, 0);
        CONTROL_SetEnabled(gpControl_00779C68, 0);
        sub_004F9740_ControlSetState(gpControl_00779D94, 0);
        return 1;
    }
    CONTROL_SetEnabled(gpControl_00779C80, 1);
    if (pEntry->nFlags & 0x20)
        CONTROL_SetEnabled(gpControl_00779C80, 0);
    CONTROL_SetEnabled(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    if (gnLaunchMode_007795EC == 1 && gbFlag_00779DD8)
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    sub_004FB6A0_ClearText(gpControl_00779B60);
    sub_004FCFF0_SetTextA(gpControl_00779B60, pEntry->szName, 0);
    return 1;
}

void __fastcall sub_A15_Emit_00437F60(const unsigned char* pClass)
{
    Unicode wszText[0x40];
    sub_00437F60_GetClassName(wszText, *pClass);
    sub_A15_UseText(wszText);
}

int __fastcall sub_A15_Emit_00438030(const unsigned char* pClass)
{
    return sub_00438030_IsNotListedCode(*pClass);
}

unsigned int __fastcall sub_A15_Emit_004380B0(const unsigned int* pExpire)
{
    return CHARSEL_GetDaysLeft(*pExpire);
}

// 0x00439BE0
int __stdcall CHARSEL_CreateExpansionControls(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        MAINMENUS_DestroyControls();
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDA);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xDB);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
        D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xDC);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
        pControl = MAINMENUS_CreateFromTemplate(0xDD);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CE), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CF), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58D0), 0, 0, 0);
    }
    return 1;
}

// 0x0043A650
void __cdecl CHARSEL_RefreshCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
    sub_004FB6A0_ClearText(gpControl_00779B60);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    CONTROL_SetEnabled(gpControl_007799F4, 0);
    CONTROL_SetEnabled(gpControl_00779C68, 0);
    CONTROL_SetEnabled(gpControl_007799F8, 0);
    CONTROL_SetEnabled(gpControl_00779A1C, 0);
    CONTROL_SetEnabled(gpControl_00779B64, 0);
    sub_004F9740_ControlSetState(gpControl_00779D94, 0);
    if (FOG_IsExpansion())
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    }
    else
    {
        sub_004F9740_ControlSetState(gpControl_00779C78, 0);
    }
}

// 0x00439CA0
int __stdcall CHARSEL_DestroyIfExpansion(SMSGHANDLER_PARAMS* pMsg)
{
    if (FOG_IsExpansion())
        MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439CC0
void __cdecl sub_00439CC0_CreateControls()
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xD7);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xD8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x142B), 0, 0, 0);
}

// 0x00439D40
int __stdcall CHARSEL_OnClosePopup(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439D50
int __stdcall sub_00439D50_CreateControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439CC0_CreateControls();
    return 1;
}

// 0x00439D60
int __stdcall CHARSEL_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 > 0)
        gnTopRow_00779DC8 -= 1;
    if (gnSelected_0070CC00 > 0)
        gnSelected_0070CC00 -= 1;
    sub_00438560_Refresh();
// build: symbol ?CHARSEL_Redraw@* 0x00439210
    CHARSEL_Redraw();
    return 1;
}

// 0x00439DA0
int __stdcall CHARSEL_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 + gnVisibleRows_0070CC0C < gdwGlobal_00779DC4)
    {
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
            gnSelected_0070CC00 += 1;
        gnTopRow_00779DC8 += 1;
        sub_00438560_Refresh();
        CHARSEL_Redraw();
    }
    return 1;
}

static void sub_00437CB0_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
next:
// build: symbol ?GAME_GetSlotNameCount@* 0x00430B40
    if (i >= GAME_GetSlotNameCount())
        return;
    char* szSlot = CHARSEL_GetSlotName(i);
    if (!szSlot)
        return;
    if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        D2Win_10188(gpNameControl_007799E8, i, 1);
    ++i;
    goto next;
}

// 0x0043A950
int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg)
{
    SStrCopy(gData_00779A40, gszName_00779C88, 0x7FFFFFFF);
    SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
    if (gnLaunchMode_007795EC == 1)
    {
        MAINMENUS_DestroyControls();
        CHARSEL_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x00439DF0
int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg)
{
    const int nValue = sub_004FC620_GetValue(gpControl_00779C84);
    if (gnLastValue_00779DCC == nValue)
        return 0;
    gnTopRow_00779DC8 += 2 * (nValue - gnLastValue_00779DCC);
    if (gnTopRow_00779DC8 < 0)
        gnTopRow_00779DC8 = 0;
    if (gnTopRow_00779DC8 >= gdwGlobal_00779DC4)
        gnTopRow_00779DC8 = gdwGlobal_00779DC4 - 1;
    gnLastValue_00779DCC = nValue;
    sub_00438560_Refresh();
    CHARSEL_Redraw();
    return 1;
}

// 0x0043A1F0
static void CHARSEL_ShowConnectError(int nError)
{
    int nStringId;
    switch (nError)
    {
    case 0x7E:
        nStringId = 0x2B99;
        break;
    case 0x7F:
        nStringId = 0x2B9A;
        break;
    default:
        nStringId = 0x2B3A;
        break;
    }

    gdwGlobal_00779DB8 = 1;
    gnState_00779DAC = 0;
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(nStringId), 4, 0, 0);
    CONTROL_SetEnabled(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

// 0x0043A270
void __cdecl CHARSEL_UpdateStatus()
{
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    if (GetTickCount() - gdwStartTick_00779DB4 > 1000)
        sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(0x2B39), 4, 0, 0);
}

// 0x0043A460
extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), ".\\Src\\CharSel.cpp", 0xBAF, 0);
    sub_005263E0(pEntry->szName, pTitle, 0x100);
    sub_005267E0((unsigned short*)pEntry->wszName, (const unsigned short*)pText);
    memset(pEntry->aFlags, 0, sizeof(pEntry->aFlags));
    memset(pEntry->aColors, 0, sizeof(pEntry->aColors));
    pEntry->nType = nSel;
    pEntry->nWord322 = 0;
    pEntry->nWord324 = 0;
    pEntry->nWord326 = 0;
    pEntry->nWord328 = 0;
    pEntry->nByte32E = 0;
    pEntry->nByte32F = 0;
    pEntry->nByte330 = 0;
    pEntry->pCompositeUnit = 0;
    pEntry->pNext = 0;
    for (int i = 0; i < 16; ++i)
    {
        pEntry->aFlags[i] = 0;
        pEntry->aColors[i] = 0xFF;
    }
    pEntry->aFlags[1] = 1;
    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(pEntry->nType, 5, pEntry->aFlags, pEntry->aColors);
    pEntry->nState = nState;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);
    if (!gpCharList_00779DBC)
    {
        gpCharList_00779DBC = pEntry;
    }
    else
    {
        D2LaunchCharEntryStrc* pLast = gpCharList_00779DBC;
        D2LaunchCharEntryStrc** ppNext = &gpCharList_00779DBC->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
        }
        pLast->pNext = pEntry;
    }
    ++gdwGlobal_00779DC4;
    sub_00438560_Refresh();
    return 1;
}

// 0x0043A5D0
void __cdecl CHARSEL_ShowMessage()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x1419);
    const Unicode* pText;
    if (gnLaunchMode_007795EC == 1)
        pText = D2LANG_GetStringFromTblIndex(0x141B);
    else
        pText = D2LANG_GetStringFromTblIndex(0x141A);
    gnSelectionA_0070CC04 = gdwGlobal_00779DC4;
    CHARSEL_CreateNotice(pTitle, pText, 1, 0xC);
}

// 0x0043AC00
int __stdcall CHARSEL_PollConnect(int nUnused)
{
    switch (gnState_00779DAC)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl_007799E8, -1, 4);
        sub_00437CB0_SelectNamedSlot(gpszName_00779DB0);
        MAINMENUS_ConnectToRealm(gpszName_00779DB0, 1);
        gnState_00779DAC = 2;
        gdwStartTick_00779DB4 = GetTickCount();
        break;

    case 2:
        CHARSEL_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
// build: symbol ?MCPCONNECT_SetPacket@* 0x00449E70
            MCPCONNECT_SetPacket(0, 0);
            gnState_00779DAC = 3;
// build: symbol ?VIEW_SendMcpCharListRequest@* 0x0044AAB0
            if (!VIEW_SendMcpCharListRequest())
                CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        case 2:
            CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        }
        break;

    case 3:
    {
        CHARSEL_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnState_00779DAC = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl_007799E8, -1, 4);
// build: symbol ?CHARSEL_HandleCharList@* 0x0043AAB0
            CHARSEL_HandleCharList(gpszName_00779DB0, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}

// 0x0043B7A0
int __fastcall CHARSEL_InitFuncTable(D2LaunchRecordStrc* pRecord)
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
void __cdecl CHARSEL_ClearCancelled()
{
    gdwGlobal_0077AC04 = 0;
}

// 0x0043B9A0
void __cdecl CHARSEL_DisconnectBattleNet()
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
void __cdecl CHARSEL_CreateBaseScreen()
{
    MAINMENUS_Reset();
    MAINMENUS_CreateControl(8);
    MAINMENUS_CreateControl(6);
    MAINMENUS_CreateControl(7);
    sub_0042F2E0_ReadPaletteFiles(gapszSkyPalette_006D3A08[0], gapszSkyPalette_006D3A08[1]);
    MAINMENUS_ConfigureLanguageLayout();
}

// 0x0043C6A0
void __fastcall sub_0043C6A0(int bSet)
{
    if (bSet)
        gdwFlags_0077AC34 |= 2;
}

// 0x0043D990
void __cdecl CHARSEL_ActivateChatEdit()
{
    if (gpChatEdit_0077BD94)
        CONTROL_SetFocusedEditBox(gpChatEdit_0077BD94);
}

// 0x0043DB20
void __cdecl CHARSEL_DestroyDialogControls()
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
        CONTROL_SetFocusedEditBox(gpChatEdit_0077BD94);
}

// 0x0043DC30
int __cdecl CHARSEL_GetConnectStatus()
{
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
        return -1;
    return 0;
}

// 0x0043E130
void __cdecl CHARSEL_ResetChatControls()
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


// 0x0043EA20
void __cdecl CHARSEL_DestroyPopupControls()
{
    for (int i = 0; i < gnControlCount_0077BBE8; i++)
        sub_004F95C0_ControlDestroy(&gpControls_0077ADA8[i]);
    gnControlCount_0077BBE8 = 0;
    sub_004FA450_SetActive(gpControl_0077B080);
    gdwConnectTime_0077BBF0 = 0;
}

// 0x0043F4D0
void __cdecl CHARSEL_ClearHistory()
{
    for (int i = 0; i < 10; i++)
        gaszHistory_0077B1D8[i][0] = 0;
    gnHistoryIndex_0070CD74 = -1;
    gdwGlobal_0077BD50 = 0;
}

// 0x0043F560
void __fastcall CHARSEL_DisableControl(D2WinControlStrc* pControl)
{
    CONTROL_SetCellFile(pControl, gpCellFile_0077BC6C);
    CONTROL_SetEnabled(pControl, 0);
}

// 0x0043F850
int __cdecl CHARSEL_CancelGameCreate()
{
    VIEW_SendMcpCancelGameCreate();
    sub_00449E50_SetValue(0);
    return 1;
}

#include "gen/data/Source/D2Launch/Src/CharSel_00430520.inc"
