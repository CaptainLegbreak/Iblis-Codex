#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct SMSGHANDLER_PARAMS;

struct D2LaunchCharEntryStrc;

struct D2LaunchCharSelectStrc;

struct D2LaunchGameRecStrc;

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

struct D2LaunchCharSelectStrc
{
    char unk0x000[0x210];
    char nMode;
};

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605

extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void __stdcall sub_00411320_CapitalizeWords(char* szText); // 0x00411320

char* __fastcall sub_0040E080_AddressToString(int nAddress); // 0x0040E080

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80

int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20

int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4); // 0x004FCD40

void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0

int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30

void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0

int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton); // 0x00500960

void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0

void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __fastcall sub_00434A00_Join(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00

int __fastcall sub_00434960_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x00434960

int __fastcall sub_004349B0_Validate(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x004349B0

void __fastcall sub_00435180_ShowMessage2(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00435180

int __stdcall sub_004370B0_ShowLoginScreen(int nArg); // 0x004370B0

void __cdecl sub_0043B080_InitCharSelectScreen(); // 0x0043B080

void __fastcall sub_0043C750_JoinEntry(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x0043C750

int __fastcall sub_0043CAA0_UpdateSaveFlags(const char* szName); // 0x0043CAA0

int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0

int __cdecl sub_0043E570(); // 0x0043E570

int __fastcall sub_0043F5F0_CallTable74(int nA, int nB, int nC, int nD); // 0x0043F5F0

void __cdecl sub_0043FC20(); // 0x0043FC20

int __fastcall sub_0043FFA0_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0

void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140

void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0

void __fastcall sub_004411E0_Use(const char* szText); // 0x004411E0

int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper); // 0x004428D0

int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0

extern char gszValue_0070EBD0[]; // 0x0070EBD0

extern char gszValue_0070EBD4[]; // 0x0070EBD4

extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80

extern int gnCounter_00779DDC; // 0x00779DDC

extern D2LaunchGameRecStrc gaNewGames_0077BDC8[]; // 0x0077BDC8

extern D2LaunchGameRecStrc gaGames_0078A440[]; // 0x0078A440

extern D2WinControlStrc* gpGameText_00798BC4; // 0x00798BC4

extern D2WinControlStrc* gpJoinName_00798BD4; // 0x00798BD4

extern D2WinControlStrc* gpJoinPassword_00798BD8; // 0x00798BD8

extern D2WinControlStrc* gpCreateButton_00798C28; // 0x00798C28

extern D2WinControlStrc* gpCreateName_00798C2C; // 0x00798C2C

extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C

extern D2WinControlStrc* gpButton_00798C40; // 0x00798C40

extern D2WinControlStrc* gpSubmitEditA_00798C80; // 0x00798C80

extern D2WinControlStrc* gpSubmitEditB_00798C84; // 0x00798C84

extern D2WinControlStrc* gpSubmitEditC_00798C88; // 0x00798C88

extern int gnSubmitMode_00798CAC; // 0x00798CAC

char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50

void __cdecl sub_0043A270_UpdateStatus(); // 0x0043A270

extern int gbFlag_00779C6C; // 0x00779C6C

extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90

extern int gnState_00779DAC; // 0x00779DAC

extern char* gpszName_00779DB0; // 0x00779DB0

extern unsigned long gdwStartTick_00779DB4; // 0x00779DB4

static void sub_00437CB0_SelectNamedSlot(const char* szName);

D2WinControlStrc* gpButton_007799E4; // 0x007799E4

int gbBusy_00779DA0; // 0x00779DA0

D2LaunchCharEntryStrc* gpCharList_00779DBC; // 0x00779DBC

D2WinControlStrc* gpButton_0077BCEC; // 0x0077BCEC

D2WinControlStrc* gpGameList_00798BC0; // 0x00798BC0

D2WinControlStrc* gpJoinButton_00798BCC; // 0x00798BCC

int gnGameCount_00798CC8; // 0x00798CC8

char gbRealmNamesInit_00779DA8;                                                             // 0x00779DA8

Unicode gwszRealmNames_00779DF0[7][0x100];                                                  // 0x00779DF0

#pragma intrinsic(strcpy)

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

#pragma intrinsic(strcat, strlen)

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6

void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall D2Win_10046(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0

void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nX);                              // 0x005052B0

void __stdcall D2Win_10153(D2CompositeUnitStrc* pCompositeUnit, int nY);                              // 0x005052F0

void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags);                                // 0x00505360

const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

extern const int gnFlagSet0_006CE278;                                                                       // 0x006CE278

extern const int gnFlagSet1_006CE27C;                                                                       // 0x006CE27C

extern const int gnFlagClear0_006CE2F8;                                                                     // 0x006CE2F8

extern const int gnFlagClear1_006CE2FC;                                                                     // 0x006CE2FC

extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C

extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC

int gnListTop_007799FC;                                                                                     // 0x007799FC

extern D2WinControlStrc* gapRowControls_00779A20[];                                                         // 0x00779A20

extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8

extern D2WinControlStrc* gpControl_00779DD0;                                                                // 0x00779DD0

static Unicode* sub_00437F60_GetClassName(Unicode* pBuffer, int nClass);

static int sub_00437D20_IsTestRealm(const Unicode* pName);


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

extern int gnGlobal_00779DC4;                                                                               // 0x00779DC4

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20

extern "C" const char gszCharSelFile_006D4DBC[];                                                            // 0x006D4DBC

extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560

int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0

void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0

void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260

D2CompositeUnitStrc* __stdcall sub_005066C0_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0

unsigned short __stdcall sub_006BBF20_ReadPackedWord(const unsigned char* pData);                           // 0x006BBF20

static int __stdcall sub_00438AD0_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm);

#pragma intrinsic(strlen)

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData);

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);

int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                           // 0x00407050

int __fastcall sub_0043C8A0(const char* szName, char* szPath);                                              // 0x0043C8A0

char gszCharName_00779B68[256];                                                                             // 0x00779B68

int gnCharCount_00779DE0;                                                                                   // 0x00779DE0

static int sub_00438030_IsNotListedCode(int nValue);

extern int gnSelected_0070CC00; // 0x0070CC00

extern int gnSelectionA_0070CC04; // 0x0070CC04

extern int gnSelectionB_0070CC08; // 0x0070CC08

extern int gnCount_00779DC4; // 0x00779DC4

extern int gbFlag_00779DD8; // 0x00779DD8

static D2LaunchCharEntryStrc* gpCurrent_00779DC0; // 0x00779DC0

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern unsigned int gdwInverseMasks[]; // 0x006CE2E8

extern "C" const char gszCharSelFile[]; // 0x006D4DBC

extern "C" const char gszNameTagFormat[]; // 0x006D4E34

extern "C" const char gszLevelFormat[]; // 0x006D4E24

int __cdecl sub_004390A0_UpdateSelection(); // 0x004390A0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0

void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc*,int); // 0x004F96F0

void __fastcall sub_004F9740(D2WinControlStrc*,int); // 0x004F9740

void __stdcall sub_004FD0B0_SetSprite(D2WinControlStrc*,int,void*); // 0x004FD0B0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc*,const Unicode*,int,int,int); // 0x004FC9B0

void __stdcall sub_005041B0_FreeAnim(void*,int); // 0x005041B0

void __stdcall sub_005051A0_SetAnimField(void*,int); // 0x005051A0

void __stdcall sub_00505260_SetAnimField(void*,int); // 0x00505260

void __fastcall sub_005042F0_SetAnimMode(void*,int); // 0x005042F0

void __stdcall sub_005052B0_SetAnimX(void*,int); // 0x005052B0

void __stdcall sub_005052F0_SetAnimY(void*,int); // 0x005052F0

void __stdcall sub_00505360_SetAnimFlags(void*,unsigned int); // 0x00505360

extern D2WinControlStrc* gpControl_007799F0; // 0x007799F0

extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4

extern D2WinControlStrc* gpControl_00779A1C; // 0x00779A1C

extern D2WinControlStrc* gpControl_00779B60; // 0x00779B60

extern D2WinControlStrc* gpControl_00779B64; // 0x00779B64

extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68

extern D2WinControlStrc* gpControl_00779C70; // 0x00779C70

extern D2WinControlStrc* gpControl_00779C78; // 0x00779C78

extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94

extern void* gaSprites_007799FC[]; // 0x007799FC

extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1D8

extern int gnGlobal_007795EC;                                                                               // 0x007795EC

extern int gnGlobal_0070CC04;                                                                               // 0x0070CC04

extern int gnGlobal_0070CC08;                                                                               // 0x0070CC08

extern int gnGlobal_00779DD8;                                                                               // 0x00779DD8

void __fastcall sub_00437AB0_CharSelCacheStore(const char* szKey, const void* pData, unsigned int nSize); // 0x00437AB0

void __cdecl sub_00437B90_FreeCache();                                                                      // 0x00437B90

int __cdecl sub_00439210_Redraw(); // 0x00439210

extern "C" int __stdcall sub_0043A460_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460

D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430

void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0

static int sub_00437A20_FindSlotName(const char* szName);

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004378D0
int __stdcall sub_004378D0_SubmitTexts(int nArg)
{
    char szA[0x100];
    char szB[0x100];

    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }

    if (!sub_004F9710_TestFlag(gpButton_007799E4))
        return 1;

    const Unicode* pTextA = sub_004FDD90_GetEditText(gpEdit_007799DC);
    const Unicode* pTextB = sub_004FDD90_GetEditText(gpEdit_007799E0);
    sub_005263E0(szA, pTextA, 0x100);
    sub_005263E0(szB, pTextB, 0x100);

    if (gpFuncTable_0077ABF0->pfnSlot68() && gpFuncTable_0077ABF0->pfnSlotBC(szA, szB))
    {
        sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B60), 0x13EE, 0, sub_004370B0_ShowLoginScreen, 0, 1, 0);
        return 1;
    }

    sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
    return 0;
}

// 0x00437A20
static int sub_00437A20_FindSlotName(const char* szName)
{
    for (int i = 0; ; ++i)
    {
        char* szSlot = i < sub_00430B40() ? sub_00430B50_GetSlotName(i) : 0;
        if (!szSlot)
        {
            break;
        }

        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        {
            return 1;
        }
    }

    return 0;
}

struct D2WinControlStrc;

// 0x00437CB0
static void sub_00437CB0_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
    char* szSlot;
    while ((szSlot = (i < sub_00430B40() ? sub_00430B50_GetSlotName(i) : 0)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            D2Win_10188(gpNameControl_007799E8, i, 1);
        ++i;
    }
}

static void sub_0043A1F0_ShowConnectError(int nError)
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
    sub_004F96F0_ControlClearState(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

int __stdcall sub_0043AC00_PollConnect(int nUnused)
{
    switch (gnState_00779DAC)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl_007799E8, -1, 4);
        sub_00437CB0_SelectNamedSlot(gpszName_00779DB0);
        sub_00432480(gpszName_00779DB0, 1);
        gnState_00779DAC = 2;
        gdwStartTick_00779DB4 = GetTickCount();
        break;

    case 2:
        sub_0043A270_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
            sub_00449E70_SetMcpPacket(0, 0);
            gnState_00779DAC = 3;
            if (!sub_0044AAB0_SendPacket19())
                sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        case 2:
            sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        }
        break;

    case 3:
    {
        sub_0043A270_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnState_00779DAC = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl_007799E8, -1, 4);
            sub_0043AAB0(gpszName_00779DB0, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}

// 0x00437D20
static int sub_00437D20_IsTestRealm(const Unicode* pName)
{
    if (!gbRealmNamesInit_00779DA8)
    {
        char szBuffer[0x100];
        gbRealmNamesInit_00779DA8 = 1;
        strcpy(szBuffer, "Testv104");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[0], szBuffer, 255);
        strcpy(szBuffer, "FatRealm");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[1], szBuffer, 255);
        strcpy(szBuffer, "BetaWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[2], szBuffer, 255);
        strcpy(szBuffer, "BetaEurope");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[3], szBuffer, 255);
        strcpy(szBuffer, "BetaUSWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[4], szBuffer, 255);
        strcpy(szBuffer, "BetaUSEast");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[5], szBuffer, 255);
        strcpy(szBuffer, "BetaAsia");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[6], szBuffer, 255);
    }

    for (int i = 0; i < 7; ++i)
    {
        if (!Unicode::strcmp(pName, gwszRealmNames_00779DF0[i]))
        {
            return 1;
        }
    }
    return 0;
}

int __stdcall sub_M216_Emit_00437D20(const Unicode* pName, int n)
{
    return sub_00437D20_IsTestRealm(pName) + n;
}

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

static __forceinline unsigned int sub_004380B0_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

// 0x004380F0
void __cdecl sub_004380F0_UpdateCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    int nY = gnListTop_007799FC - 13;
    int nX = 0x25;
    int nIndex = 0;

    for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
    {
        sub_004FB6A0_ClearText(gapRowControls_00779A20[i]);
        switch (STRTABLE_GetLanguage())
        {
        case 7:
            sub_004FB740(gapRowControls_00779A20[i], -1, -7);
            break;
        case 6:
        case 9:
        case 10:
            sub_004FB740(gapRowControls_00779A20[i], -1, -2);
            break;
        }
    }

    if (gpControl_00779DD0)
    {
        sub_004FB6A0_ClearText(gpControl_00779DD0);
    }

    if (gnLaunchMode_007795EC == 1 && gnState_00779DAC)
    {
        return;
    }

    while (pEntry)
    {
        if (nIndex >= gnTopRow_00779DC8 && nIndex < gnTopRow_00779DC8 + gnVisibleRows_0070CC0C)
        {
            const int nRow = nIndex - gnTopRow_00779DC8;
            D2Win_10152(pEntry->pCompositeUnit, nX + 30);
            D2Win_10153(pEntry->pCompositeUnit, nY);

            const int bHardcore = pEntry->wFlags & 4;
            int nFlags = 1;
            if (pEntry->wFlags & 8)
            {
                nFlags |= gnFlagSet0_006CE278;
            }
            else
            {
                nFlags &= gnFlagClear0_006CE2F8;
            }
            if (bHardcore)
            {
                nFlags |= gnFlagSet1_006CE27C;
            }
            else
            {
                nFlags &= gnFlagClear1_006CE2FC;
            }
            D2Win_10156(pEntry->pCompositeUnit, nFlags);

            if (pEntry->nState == 2)
            {
                D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x2B3B), 1, 0, 0);
            }
            else if (!pEntry->nState)
            {
                const int nClass = pEntry->nType;
                char szName[100];
                Unicode wszClass[100];
                szName[0] = 0;
                for (int j = 0; j < 100; ++j)
                {
                    wszClass[j].wChar = 0;
                }

                const char* szTitle = D2Win_10161(nClass, (pEntry->wFlags >> 8) & 0x1F, bHardcore, pEntry->wFlags & 0x20);
                if (szTitle)
                {
                    int nColor;
                    if (bHardcore)
                    {
                        nColor = 1;
                    }
                    else
                    {
                        nColor = 4;
                    }
                    D2Win_10046(gapRowControls_00779A20[nRow], szTitle, nColor);
                }

                strcat(szName, pEntry->szName);
                if (strlen(pEntry->szCode32A))
                {
                    sprintf(&szName[strlen(szName)], " {%s}", pEntry->szCode32A);
                }
                D2Win_10046(gapRowControls_00779A20[nRow], szName, bHardcore ? 1 : 4);

                sub_00437F60_GetClassName(wszClass, pEntry->nType);

                Unicode wszText[100];
                for (int j = 0; j < 100; ++j)
                {
                    wszText[j].wChar = 0;
                }
                Unicode wszLevel[10];
                wszLevel[0].wChar = 0;
                wszLevel[1].wChar = 0;
                wszLevel[2].wChar = 0;
                wszLevel[3].wChar = 0;
                wszLevel[4].wChar = 0;
                wszLevel[5].wChar = 0;
                wszLevel[6].wChar = 0;
                wszLevel[7].wChar = 0;
                wszLevel[8].wChar = 0;
                wszLevel[9].wChar = 0;
                sprintf(szName, " %d ", pEntry->nLevel);
                sub_00526F20_ToUnicode(wszLevel, szName, 9);
                sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xFD9));
                sub_00526700(wszText, wszLevel);
                sub_00526700(wszText, wszClass);
                D2Win_10051(gapRowControls_00779A20[nRow], wszText, 0, 0, 0);

                if (pEntry->wFlags & 0x20)
                {
                    D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x58CB), 2, 0, 0);
                }
                if (pEntry->nByte32E)
                {
                    D2Win_10051(gapRowControls_00779A20[nRow], D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
                }

                const unsigned int nDays = sub_004380B0_GetDaysLeft(pEntry->nExpireTime);
                if (gnLaunchMode_007795EC == 1 && nDays <= 60)
                {
                    int nColor = 1;
                    unsigned short nString;
                    if (!nDays)
                    {
                        nString = 0x2B7E;
                    }
                    else if (nDays < 2)
                    {
                        nString = 0x2B7C;
                    }
                    else
                    {
                        nString = 0x2B7D;
                        if (nDays >= 15)
                        {
                            nColor = 0;
                        }
                    }
                    sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(nString), nDays);
                    D2Win_10051(gapRowControls_00779A20[nRow], wszText, nColor, 0, 0);
                }
            }

            if (nX == 0x25)
            {
                nX = 0x135;
            }
            else
            {
                nY += 0x5D;
                nX = 0x25;
            }
        }
        else
        {
            D2Win_10156(pEntry->pCompositeUnit, 0);
        }

        pEntry = pEntry->pNext;
        ++nIndex;
    }
}

static __forceinline int sub_F4B0_IsMaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

// 0x00438AD0
static int __stdcall sub_00438AD0_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), gszCharSelFile_006D4DBC, 0x414, 0);
    pEntry->nKeyLow = nKeyLow;
    pEntry->nKeyHigh = nKeyHigh;
    pEntry->nFlag348 = nFlag;
    SStrCopy(pEntry->szName, szName, 0x7FFFFFFF);

    Unicode* pText = pEntry->wszName;
    if (szRealm)
    {
        Unicode::win2Unicode(pText, szRealm, 255);
    }
    else
    {
        pText->wChar = 0;
    }

    const unsigned char* pData = (const unsigned char*)szStats;
    pEntry->nWord326 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    if (sub_00437D20_IsTestRealm(pText))
    {
        char szText[0x100];
        Unicode::unicode2Win(szText, pText, 255);
        sub_0043C750_JoinEntry(pEntry, szText);
        return 0;
    }

    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aFlags[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aFlags[i] = 0xFF;
        }
    }

    pEntry->nType = *pData - 1;
    ++pData;
    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aColors[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aColors[i] = 0xFF;
        }
    }

    pEntry->pNext = 0;
    pEntry->nWord322 = *pData++;
    pEntry->nWord324 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    pEntry->nWord328 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    pEntry->nByte32E = *pData++;
    pEntry->nByte32E = pEntry->nByte32E == 0xFF ? 0 : pEntry->nByte32E;
    pEntry->nByte32F = *pData++;
    pEntry->nByte32F = pEntry->nByte32F == 0xFF ? 0 : pEntry->nByte32F;
    pEntry->nByte330 = *pData++;
    pEntry->nByte330 = pEntry->nByte330 == 0xFF ? 0 : pEntry->nByte330;
    strncpy(pEntry->szCode32A, (const char*)pData, 3);

    unsigned char nSel = pEntry->nType;
    int nMode = 5;
    if (pEntry->nWord324 & 4)
    {
        if (pEntry->nWord324 & 8)
        {
            nSel = sub_F4B0_IsMaleClass(nSel) ? 9 : 8;
        }
        else if (sub_00408F20_HasExpansionMpq() || pEntry->nType < 5)
        {
            nMode = 1;
        }
    }

    pEntry->pCompositeUnit = sub_005066C0_CreateCompositeUnit(nSel, nMode, pEntry->aFlags, pEntry->aColors);
    if (!pEntry->pCompositeUnit)
    {
        for (int j = 0; j < 16; ++j)
        {
            pEntry->aFlags[j] = 0;
            pEntry->aColors[j] = 0xFF;
        }

        pEntry->aFlags[1] = 1;
        pEntry->pCompositeUnit = sub_005066C0_CreateCompositeUnit(7, 5, pEntry->aFlags, pEntry->aColors);
    }

    D2_ASSERT(pEntry->pCompositeUnit, 0x4BE);
    pEntry->nState = 0;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);

    if (gpCharList_00779DBC)
    {
        D2LaunchCharEntryStrc* pPrev = 0;
        D2LaunchCharEntryStrc* pCur = gpCharList_00779DBC;
        if (sub_00408F20_HasExpansionMpq())
        {
            while (pCur)
            {
                if (nKeyHigh > pCur->nKeyHigh || (nKeyHigh == pCur->nKeyHigh && nKeyLow > pCur->nKeyLow))
                {
                    break;
                }

                pPrev = pCur;
                pCur = pCur->pNext;
            }

            if (pPrev)
            {
                pEntry->pNext = pPrev->pNext;
                pPrev->pNext = pEntry;
            }
            else
            {
                pEntry->pNext = gpCharList_00779DBC;
                gpCharList_00779DBC = pEntry;
            }
        }
        else
        {
            while (pCur->pNext)
            {
                pCur = pCur->pNext;
            }

            pCur->pNext = pEntry;
        }
    }
    else
    {
        gpCharList_00779DBC = pEntry;
    }

    gnGlobal_00779DC4 += 1;
    sub_00438560_Refresh();
    gdwGlobal_00779DA4 = 1;
    return 1;
}

void __stdcall sub_0043AAB0(const char* szName, unsigned char* pPacket, int bFlag)
{
    const unsigned char nType = pPacket[0];
    const char* pCursor = (const char*)pPacket + 9;
    unsigned int nCount = *(unsigned short*)(pPacket + 7);

    if (!sub_00408F20_HasExpansionMpq())
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x1419);
        unsigned short nText = 0x141B;
        if (gnGlobal_007795EC != 1)
            nText = 0x141A;
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(nText);
        gnGlobal_0070CC04 = gnGlobal_00779DC4;
        sub_0043A460_CreateNotice(wszTitle, wszText, 1, 0xC);
    }

    unsigned int nEntries = *(unsigned short*)(pPacket + 3);
    if (nCount < nEntries)
        nEntries = nCount;

    for (unsigned int i = 0; i < nEntries; ++i)
    {
        int nExpire = 0;
        if (nType == 0x19)
        {
            nExpire = *(const int*)pCursor;
            pCursor += 4;
        }

        const char* szCharName = pCursor;
        pCursor += strlen(pCursor) + 1;
        const char* szStats = pCursor;
        pCursor += strlen(pCursor) + 1;
        D2FileTimeStrc tTime = {};
        if (!sub_00438AD0_AddCharEntry(szCharName, szStats, nExpire, tTime.dwLowDateTime, tTime.dwHighDateTime, szName))
        {
            --nCount;
            sub_00437B90_FreeCache();
            bFlag = 0;
        }
    }

    if (bFlag)
    {
        sub_00437AB0_CharSelCacheStore(szName, pPacket, (const unsigned char*)pCursor - pPacket);
    }

    if (nCount >= *(unsigned short*)(pPacket + 1))
    {
        gnGlobal_00779DD8 = 1;
    }

    if (*(unsigned short*)(pPacket + 3) > *(unsigned short*)(pPacket + 7))
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
        Unicode wszEmpty;
        wszEmpty.wChar = 0;
        gnGlobal_0070CC08 = gnGlobal_00779DC4;
        sub_0043A460_CreateNotice(wszTitle, &wszEmpty, 2, 0x12);
    }

    sub_00439210_Redraw();
}

static __forceinline int CharSel_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

// 0x00438F70
int __cdecl sub_00438F70_ScanCharFiles()
{
    D2FindDataStrc tFindData;
    char szPath[0x100];
    char szDir[0x400];
    char szPattern[0x400];

    gnCharCount_00779DE0 = 0;
    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPattern, "%s*.d2s", szDir);
    void* hFind = FindFirstFileA(szPattern, &tFindData);
    if (hFind == (void*)-1)
    {
        return 1;
    }

    do
    {
        const char* pSrc = tFindData.cFileName;
        char* pDst = gszCharName_00779B68;
        while (*pSrc && *pSrc != '.')
        {
            *pDst++ = *pSrc++;
        }
        *pDst = 0;

        if (CharSel_IsValidCharName(gszCharName_00779B68) && sub_0043C8A0(gszCharName_00779B68, szPath))
        {
            sub_00438AD0_AddCharEntry(gszCharName_00779B68, szPath, 0, tFindData.ftLastWriteTime.dwLowDateTime, tFindData.ftLastWriteTime.dwHighDateTime, 0);
            ++gnCharCount_00779DE0;
        }
    }
    while (FindNextFileA(hFind, &tFindData));

    FindClose(hFind);
    return 1;
}

void __cdecl sub_LEG_Emit_00438F70()
{
    sub_00438F70_ScanCharFiles();
}

void __stdcall sub_LEG_Emit_00438AD0(const char* szName, char* szPath, int nArg3, unsigned int nTimeLow, unsigned int nTimeHigh, int nMode)
{
    sub_00438AD0_AddCharEntry(szName, szPath, nArg3, nTimeLow, nTimeHigh, (const char*)nMode);
}

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

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00439210
int __cdecl sub_00439210_Redraw()
{
    if(sub_00408F20_HasExpansionMpq()) {sub_004390A0_UpdateSelection();return 1;}
    if(!gnCount_00779DC4) gnSelected_0070CC00=0;
    int row=gnSelected_0070CC00-gnTopRow_00779DC8;
    sub_004F96F0_ControlClearState(gpControl_007799F4,gnCount_00779DC4>0 && gnSelected_0070CC00>gnSelectionA_0070CC04 && gnSelected_0070CC00!=gnSelectionB_0070CC08 ? 1:0);
    sub_004F96F0_ControlClearState(gpControl_00779C68,1);
    if(row>=0 && row<gnVisibleRows_0070CC0C) {
        if(gnSelected_0070CC00==gnSelectionA_0070CC04 && gbFlag_00779DD8) {
            sub_004FD0B0_SetSprite(gpControl_00779C78,0x202,gaSprites_007799FC[row]);
            sub_004F9740(gpControl_00779C78,1);
            sub_004F9740(gpControl_00779D94,0);
        } else {
            sub_004FD0B0_SetSprite(gpControl_00779D94,0x202,gaSprites_007799FC[row]);
            sub_004F9740(gpControl_00779D94,1);
            sub_004F9740(gpControl_00779C78,0);
        }
    } else {
        sub_004F9740(gpControl_00779D94,0);
        sub_004F9740(gpControl_00779C78,0);
    }
    if(gnTopRow_00779DC8>0) sub_004F9740(gpControl_00779A1C,1);
    else sub_004F9740(gpControl_00779A1C,0);
    if(gnTopRow_00779DC8+gnVisibleRows_0070CC0C<gnCount_00779DC4) sub_004F9740(gpControl_00779B64,1);
    else sub_004F9740(gpControl_00779B64,0);
    int index=0;
    D2LaunchCharEntryStrc* entry=gpCharList_00779DBC;
    if(!gpCharList_00779DBC) return 1;
    do {
        if(gnSelected_0070CC00==index) break;
        entry=entry->pNext;
        ++index;
    } while(entry);
    if(!entry) return 1;
    if(gpCurrent_00779DC0) {
        if(!gpCurrent_00779DC0->nState) sub_005041B0_FreeAnim(gpCurrent_00779DC0->pAnim,1);
        FOG_Free(gpCurrent_00779DC0,gszCharSelFile,0x5DE,0);
        gpCurrent_00779DC0=0;
    }
    gpCurrent_00779DC0=(D2LaunchCharEntryStrc*)FOG_Alloc(0x350,gszCharSelFile,0x5E2,0);
    SMemCopy(gpCurrent_00779DC0,entry,0x350);
    gpCurrent_00779DC0->pNext=0;
    unsigned short statusText;
    if(entry->nState==1) {
        sub_004FB6A0_ClearText(gpControl_00779B60);
        statusText=0x1419;
    } else if(entry->nState==2) {
        sub_004FB6A0_ClearText(gpControl_00779B60);
        statusText=0x2B3B;
    } else goto BUILD_MODEL;
    sub_004FC9B0_SetText(gpControl_00779B60,D2LANG_GetStringFromTblIndex(statusText),1,0,0);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    return 1;
BUILD_MODEL:
    unsigned char type=gpCurrent_00779DC0->nType;
    int mode=5;
    if(gpCurrent_00779DC0->wFlags&4) {
        if(gpCurrent_00779DC0->wFlags&8) type=8+(sub_00438030_IsNotListedCode(type)!=0);
        else if(sub_00408F20_HasExpansionMpq() || gpCurrent_00779DC0->nType<5) mode=1;
    }
    gpCurrent_00779DC0->pAnim=sub_005066C0_CreateCompositeUnit(type,mode,gpCurrent_00779DC0->aFlags,gpCurrent_00779DC0->aColors);
    if(!gpCurrent_00779DC0->pAnim) {
        for(int i=0;i<16;++i) {gpCurrent_00779DC0->aFlags[i]=0;gpCurrent_00779DC0->aColors[i]=255;}
        gpCurrent_00779DC0->aFlags[1]=1;
        gpCurrent_00779DC0->pAnim=sub_005066C0_CreateCompositeUnit(7,5,gpCurrent_00779DC0->aFlags,gpCurrent_00779DC0->aColors);
    }
    if(!gpCurrent_00779DC0->pAnim) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x619);exit(-1);}
    sub_005051A0_SetAnimField(gpCurrent_00779DC0->pAnim,0);
    sub_00505260_SetAnimField(gpCurrent_00779DC0->pAnim,0);
    sub_005042F0_SetAnimMode(gpCurrent_00779DC0->pAnim,5);
    sub_005052B0_SetAnimX(gpCurrent_00779DC0->pAnim,0x118);
    sub_005052F0_SetAnimY(gpCurrent_00779DC0->pAnim,0x172);
    unsigned int flags=5;
    if(gpCurrent_00779DC0->wFlags&8) flags|=gdwBitMasks[4];else flags&=gdwInverseMasks[4];
    if(gpCurrent_00779DC0->wFlags&4) flags|=gdwBitMasks[5];else flags&=gdwInverseMasks[5];
    if(gpCurrent_00779DC0->wFlags&32) flags|=gdwBitMasks[12];else flags&=gdwInverseMasks[12];
    sub_00505360_SetAnimFlags(gpCurrent_00779DC0->pAnim,flags);
    Unicode className[100];
    char text[100];
    sub_004FB6A0_ClearText(gpControl_00779B60);
    if(strlen(gpCurrent_00779DC0->szCode32A)) {
        sprintf(text,gszNameTagFormat,gpCurrent_00779DC0->szName,gpCurrent_00779DC0->szCode32A);
        D2Win_10046(gpControl_00779B60,text,0);
    } else D2Win_10046(gpControl_00779B60,gpCurrent_00779DC0->szName,0);
    sub_004FB6A0_ClearText(gpControl_007799F0);
    sub_00437F60_GetClassName(className,gpCurrent_00779DC0->nType);
    Unicode description[100];
    Unicode level[10];
    sprintf(text,gszLevelFormat,entry->nLevel);
    sub_00526F20_ToUnicode(level,text,9);
    sub_005267E0(description,D2LANG_GetStringFromTblIndex(0xFD9));
    sub_00526700(description,level);
    sub_00526700(description,className);
    sub_004FC9B0_SetText(gpControl_007799F0,description,0,0,0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    if(gpCurrent_00779DC0->wszName[0].wChar) sub_004FC9B0_SetText(gpControl_00779C70,gpCurrent_00779DC0->wszName,0,0,0);
    else sub_004FC9B0_SetText(gpControl_00779C70,D2LANG_GetStringFromTblIndex(0x142C),0,0,0);
    if(entry->wFlags&32) sub_004F96F0_ControlClearState(gpControl_00779C68,0);
    return 1;
}

// 0x00439AF0
void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode)
{
    char szName[0x100];

    if (gnSelected_0070CC00 == -1)
        return;

    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected_0070CC00 == i)
            break;
    }

    if (!pEntry)
        return;

    gpCharSelect_007795D4->nMode = nMode;
    sub_0042F3F0_DestroyControls();
    sub_00526F70(szName, pEntry->wszName, 0xFF);
    sub_00434A00_Join(pEntry, pEntry->wFlags, pEntry->nType, szName);
}

// 0x0043B520
int __stdcall sub_0043B520_OnCharSelect(int nArg)
{
    char szName[0x100];

    if (sub_00408F20_HasExpansionMpq())
    {
        D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
        for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
        {
            if (gnSelected_0070CC00 == i)
                break;
        }

        if (pEntry)
        {
            if (pEntry->wFlags & 0x20)
                return 1;

            int bOk;
            const Unicode* pwszName = pEntry->wszName;
            if (pwszName && pwszName->wChar)
            {
                sub_00526F70(szName, pwszName, 0xFF);
                bOk = sub_004349B0_Validate(pEntry, szName);
                if (!bOk)
                {
                    if (sub_00449C00() != 0x7B)
                    {
                        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080_InitCharSelectScreen);
                    }
                    else
                    {
                        Unicode wszText[0x100];
                        Unicode wszArg[0x100];
                        sub_00526F20_ToUnicode(wszArg, pEntry->szName, 0x100);
                        sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszArg);
                        sub_00433450_ShowText(wszText, sub_0043B080_InitCharSelectScreen);
                    }
                    gbBusy_00779DA0 = 0;
                    return 1;
                }
            }
            else
            {
                bOk = sub_0043CAA0_UpdateSaveFlags(pEntry->szName);
            }

            if (bOk)
            {
                pEntry->wFlags |= 0x20;
                sub_00438560_Refresh();
                sub_0042F3F0_DestroyControls();
            }
            else
            {
                sub_00435180_ShowMessage2(D2LANG_GetStringFromTblIndex(0x5570), sub_0043B080_InitCharSelectScreen, 1);
            }
        }

        sub_004F96F0_ControlClearState(gpControl_00779C80, 0);
    }
    return 1;
}

// 0x0043B6B0
int __stdcall sub_0043B6B0_JoinSelected(int nArg)
{
    char szName[0x100];

    D2LaunchCharEntryStrc* pEntry = gpCharList_00779DBC;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected_0070CC00 == i)
            break;
    }

    if (pEntry)
    {
        gbBusy_00779DA0 = 1;

        const Unicode* pwszName = pEntry->wszName;
        if (pwszName && pwszName->wChar)
        {
            sub_00526F70(szName, pwszName, 0xFF);
            if (sub_00434960_Validate(pEntry, szName))
            {
                ++gnCounter_00779DDC;
                gbFlag_00779DD8 = 0;
                sub_0043C750_JoinEntry(pEntry, szName);
            }
            else
            {
                sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x145B), sub_0043B080_InitCharSelectScreen);
                gbBusy_00779DA0 = 0;
                return 1;
            }
        }
        else
        {
            sub_0043C750_JoinEntry(pEntry, &gszEmptyAssertText);
        }

        sub_0043B080_InitCharSelectScreen();
        gbBusy_00779DA0 = 0;
        return 1;
    }

    return 0;
}

// 0x0043E660
void __cdecl sub_0043E660_UpdateOkEnabled()
{
    char szText[0x20];

    const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    int bEnable = 0;
    if (pText)
    {
        sub_00526F70(szText, pText, 0x1F);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    sub_004F96F0_ControlClearState(gpButton_0077BCEC, bEnable);
}

// 0x00441240
int __stdcall sub_00441240_UseEditText(int nArg)
{
    char szText[0x100];

    if (!sub_004F9710_TestFlag(gpButton_0077BCEC))
        return 0;

    const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    if (pText)
    {
        sub_00526F70(szText, pText, 0x100);
        sub_004411E0_Use(szText);
    }
    return 1;
}

// 0x004412A0
int __stdcall sub_004412A0_UseRegistryChannel(int nArg)
{
    char szText[0x20];

    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 1;
    }

    gpLaunchFuncs_0077B09C->pfn0xAC();
    sub_0043E570();
    sub_0043FC20();
    sub_004411E0_Use(SRegLoadString("Diablo II", "Default Channel", 0, szText, 0x20) ? szText : &gszEmptyAssertText);
    return 1;
}

// 0x004429A0
int __stdcall sub_004429A0_ChatLine(const Unicode* pText)
{
    char szCopy[0x100];
    char szText[0x100];

    gnHistoryIndex_0070CD74 = -1;
    if (!sub_00526800(pText))
        return 0;

    D2_ASSERT(gpLaunchFuncs_0077B09C, 0x12C2);

    szText[0] = 0;
    sub_00526F70(szText, pText, 0x100);
    strcpy(szCopy, szText);

    char szDelim[2] = " ";
    if (!strtok(szCopy, szDelim))
    {
        sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
        return 1;
    }
    return sub_004428D0_SendChatText(szText, 0);
}

// 0x00442C20
void __cdecl sub_00442C20_HandleList()
{
    char szSel[0x100];
    char szNumber[0x10];

    if (!gpGameList_00798BC0)
        return;

    const Unicode* pSel = sub_004FBB30_GetText(gpGameList_00798BC0);
    int bHaveSel = 0;
    if (pSel)
    {
        sub_00526F70(szSel, pSel, 0x100);
        bHaveSel = 1;
    }

    int nTop = sub_004FB950_GetFirstVisible(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    gnGameCount_00798CC8 = gnValue_00798CCC;
    if (!gnGameCount_00798CC8)
        return;

    int bNoNumbers = !sub_00449B30_QueryAddress();
    memcpy(gaGames_0078A440, gaNewGames_0077BDC8, gnValue_00798CCC * sizeof(D2LaunchGameRecStrc));
    for (int i = 0; i < gnGameCount_00798CC8; ++i)
    {
        D2Win_10045(gpGameList_00798BC0, gaGames_0078A440[i].szName);
        int nRow = sub_004FBD20_GetLastRow(gpGameList_00798BC0);
        if (!bNoNumbers)
        {
            _itoa(*(unsigned short*)gaGames_0078A440[i].wValue0x31, szNumber, 10);
            D2Win_10057(gpGameList_00798BC0, szNumber, nRow, 1);
        }
    }

    if (bHaveSel)
    {
        for (int i = 0; i < gnGameCount_00798CC8; ++i)
        {
            if (!strcmp(szSel, gaGames_0078A440[i].szName))
            {
                sub_004FB9D0_Select(gpGameList_00798BC0, i);
                break;
            }
        }
        D2Win_10053(gpGameList_00798BC0, nTop);
    }
    else
    {
        D2Win_10053(gpGameList_00798BC0, 0);
    }
}

// 0x00443360
int __cdecl sub_00443360_GetMaxPlayers()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    return atoi(szText);
}

// 0x00443390
int __cdecl sub_00443390_GetLevelRange()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    return atoi(szText);
}

// 0x004433C0
int __stdcall sub_004433C0_IncrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 8)
        ++nValue;
    sprintf(gszValue_0070EBD4, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, gszValue_0070EBD4);
    return 1;
}

// 0x00443420
int __stdcall sub_00443420_DecrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 1)
        --nValue;
    sprintf(gszValue_0070EBD4, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, gszValue_0070EBD4);
    return 1;
}

// 0x00443480
int __stdcall sub_00443480_IncrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 0x63)
        ++nValue;
    sprintf(gszValue_0070EBD0, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszValue_0070EBD0);
    return 1;
}

// 0x004434E0
int __stdcall sub_004434E0_DecrementEditValue(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    sub_005263E0(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 0)
        --nValue;
    sprintf(gszValue_0070EBD0, gszFormatD_006D57BC, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszValue_0070EBD0);
    return 1;
}

void __cdecl sub_00443630_UpdateCreateButton(); // 0x00443630

// 0x004437E0
void __cdecl sub_004437E0_UpdateButtonState()
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpJoinName_00798BD4);
    int bEnable = 0;
    if (pText)
    {
        sub_00526F70(szText, pText, 0xFF);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    sub_004F96F0_ControlClearState(gpJoinButton_00798BCC, bEnable);
}

// 0x004439F0
int __stdcall sub_004439F0_JoinByName(int nArg)
{
    char szPassword[0x100];
    char szName[0x100];
    D2LaunchGameRecStrc tRecord;

    if (!sub_004F9710_TestFlag(gpJoinButton_00798BCC))
        return 0;

    const Unicode* pName = sub_004FDD90_GetEditText(gpJoinName_00798BD4);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpJoinPassword_00798BD8);
    if (pName)
    {
        sub_00526F70(szName, pName, 0x100);
        sub_00526F70(szPassword, pPassword, 0x100);
        sub_00411320_CapitalizeWords(szName);
        sub_00411320_CapitalizeWords(szPassword);

        if (sub_00449B30_QueryAddress())
        {
            sub_0043FFA0_SetupCharacter(0, szName, szPassword, 0);
            sub_00443130_Reset();
            sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            return 1;
        }

        for (int i = 0; i < gnValue_00798CCC; ++i)
        {
            if (!strcmp(gaGames_0078A440[i].szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)gaGames_0078A440[i].wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)gaGames_0078A440[i].nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }

        if (sub_004438E0_Lookup(szName, szPassword, &tRecord))
        {
            if (!strcmp(tRecord.szName, szName))
            {
                sub_0043FFA0_SetupCharacter(*(unsigned short*)tRecord.wValue0x33, szName, szPassword, sub_0040E080_AddressToString(*(int*)tRecord.nAddress0x37));
                sub_00443130_Reset();
                sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }
        else
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x1411), 0);
        }
    }

    return 0;
}

// 0x00443F80
int __stdcall sub_00443F80_SubmitCreateGame(int nArg)
{
    if (gnSubmitMode_00798CAC == 2)
    {
        char szA[0x8 + 1];
        char szB[0x28 + 1];
        char szC[0xC8 + 1];

        const Unicode* pTextA = sub_004FDD90_GetEditText(gpSubmitEditA_00798C80);
        const Unicode* pTextB = sub_004FDD90_GetEditText(gpSubmitEditB_00798C84);
        const Unicode* pTextC = sub_004FDD90_GetEditText(gpSubmitEditC_00798C88);
        char* szName = gpCharInfo_0077BBD8->szText0x8D;
        sub_00526F70(szA, pTextA, 0x8);
        sub_00526F70(szB, pTextB, 0x28);
        sub_00526F70(szC, pTextC, 0xC8);
        if (!sub_0043F5F0_CallTable74((int)szName, (int)szA, (int)szB, (int)szC))
            return 1;
    }

    sub_00443E10();
    return 1;
}

// 0x00446890
int __stdcall sub_00446890_SendChatLine(int nArg)
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
    if (pText && sub_00526800(pText))
    {
        sub_00526F70(szText, pText, 0x100);
        return sub_004428D0_SendChatText(szText, 0);
    }
    return 1;
}

int __cdecl sub_0043A2B0_InitRealmScreen()
{
    unsigned short nStringId;
    gnState_00779DAC = 0;
    if (gnLaunchMode_007795EC == 1)
    {
        sub_00434060();
        const int nCount = sub_00430B40();
        if (nCount != -1)
        {
            if (nCount != 0)
            {
                D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x7A);
                sub_004FD830(pControl);
                sub_004FDA50(pControl);
                gpControl_00779DD0 = sub_0042F430_CreateControl(0x94);
                gpCharSelectText_00779DD4 = sub_0042F430_CreateControl(0x95);
                sub_0042F430_CreateControl(0x69);
                gpControl_00779D98 = sub_0042F430_CreateControl(0x6B);
                gpControl_00779D8C = sub_0042F430_CreateControl(0x6C);
                sub_004FC9B0_SetText(sub_0042F430_CreateControl(0x6A), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

                if (!SRegLoadString("Diablo II", "Preferred Realm", 0, gData_00779A40, 0x100) || !sub_00437A20_FindSlotName(gData_00779A40))
                {
                    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
                    const int nIndex = pRecord->nIndex;
                    SStrCopy(gData_00779A40, sub_005180E0(pRecord, nIndex), 0x7FFFFFFF);
                    SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    if (!sub_00437A20_FindSlotName(gData_00779A40))
                    {
                        const char* szFirst = sub_00430B40() > 0 ? sub_00430B50_GetSlotName(0) : 0;
                        SStrCopy(gData_00779A40, szFirst, 0x7FFFFFFF);
                        SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    }
                }
            }
            else
            {
                sub_0043B9A0();
                nStringId = 0x14AA;
                goto fail;
            }
        }
        else
        {
            sub_0043B9A0();
            nStringId = 0x14E3;
            goto fail;
        }
    }
    return 1;

fail:
    sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(nStringId), sub_004336C0);
    return 0;
}

#include "gen/data/Source/D2Launch/Src/CharSel_004378D0.inc"
