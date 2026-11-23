#include "D2Multi.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2Win32Types.h"

struct D2WinButtonStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CharSaveHeaderStrc;

struct D2CharSaveFileStrc;

struct D2LaunchCharInfoStrc;

struct Unicode;

struct D2ChatMessageStrc;

struct D2LaunchFuncsStrc;

struct SMSGHANDLER_PARAMS;

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    unsigned int dwChecksum;
    char unk0x10[0x13F];
};

struct D2CharSaveFileStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    unsigned int dwChecksum;
    char unk0x10[0x08];
    unsigned int dwOldFlags;
    char unk0x1C[0x08];
    unsigned int dwFlags;
    char unk0x28[0x1FD8];
};

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

void* __fastcall FOG_CreateFileA(const char* szPath, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x00406960

int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nSize, unsigned long* pRead, void* pOverlapped); // 0x004069B0

int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nSize, unsigned long* pWritten, void* pOverlapped); // 0x004069D0

unsigned long __fastcall FOG_SetFilePointer(void* hFile, long nDistance, long* pDistanceHigh, unsigned long dwMethod); // 0x004069F0

unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize); // 0x00411130

D2CelFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0

void __stdcall sub_00504D30(D2CelFileStrc* pCellFileA, D2CelFileStrc* pCellFileB); // 0x00504D30

int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0

int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox); // 0x004F91C0

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __cdecl CHARSEL_ResetChatControls(); // 0x0043E130

void __cdecl COMCALLBACK_RefreshChatButtons(); // 0x004477A0

int __stdcall COMCALLBACK_ButtonCallback(D2ChatMessageStrc* pMsg); // 0x00448C70

extern "C" const char gszDataGlobal[]; // 0x006D4118

extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230

extern D2WinControlInitStrc gtControlTemplates_00708D10[]; // 0x00708D10

extern D2WinControlStrc* gapChatButtons_0077AD78[]; // 0x0077AD78

extern D2WinControlStrc* gpChatControl_0077B058; // 0x0077B058

extern D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C

extern D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064

extern D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068

extern D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C

extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074

D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                                  // 0x0077BBD8

int gbToggle_0077BBEC; // 0x0077BBEC

extern D2CelFileStrc* gpChatCellFile_0077BBFC; // 0x0077BBFC

extern D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

extern D2WinControlStrc* gpChatControl_0077BC48; // 0x0077BC48

extern D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94

extern D2CelFileStrc* gpCellFile_0077BC04; // 0x0077BC04

extern D2CelFileStrc* gpCellFile_0077BC08; // 0x0077BC08

extern D2CelFileStrc* gpCellFile_0077BC0C; // 0x0077BC0C

extern D2CelFileStrc* gpCellFile_0077BC10; // 0x0077BC10

extern D2CelFileStrc* gpCellFile_0077BC14; // 0x0077BC14

extern D2CelFileStrc* gpCellFile_0077BC18; // 0x0077BC18

extern D2CelFileStrc* gpCellFile_0077BC1C; // 0x0077BC1C

extern D2CelFileStrc* gpCellFile_0077BC20; // 0x0077BC20

extern D2CelFileStrc* gpCellFile_0077BC28; // 0x0077BC28

extern D2CelFileStrc* gpCellFile_0077BC2C; // 0x0077BC2C

extern D2CelFileStrc* gpCellFile_0077BC30; // 0x0077BC30

extern D2CelFileStrc* gpCellFile_0077BC34; // 0x0077BC34

extern D2CelFileStrc* gpCellFile_0077BC38; // 0x0077BC38

extern D2CelFileStrc* gpCellFile_0077BC3C; // 0x0077BC3C

extern D2CelFileStrc* gpCellFile_0077BC50; // 0x0077BC50

extern D2CelFileStrc* gpCellFile_0077BC54; // 0x0077BC54

extern D2CelFileStrc* gpCellFile_0077BC58; // 0x0077BC58

extern D2CelFileStrc* gpCellFile_0077BC5C; // 0x0077BC5C

extern D2CelFileStrc* gpCellFile_0077BC60; // 0x0077BC60

extern D2CelFileStrc* gpCellFile_0077BC64; // 0x0077BC64

extern D2CelFileStrc* gpCellFile_0077BC68; // 0x0077BC68

extern D2CelFileStrc* gpCellFile_0077BC6C; // 0x0077BC6C

extern D2CelFileStrc* gpCellFile_0077BC70; // 0x0077BC70

extern D2CelFileStrc* gpCellFile_0077BC74; // 0x0077BC74

extern D2CelFileStrc* gpCellFile_0077BC78; // 0x0077BC78

extern D2CelFileStrc* gpCellFile_0077BC7C; // 0x0077BC7C

extern D2CelFileStrc* gpCellFile_0077BC80; // 0x0077BC80

extern D2CelFileStrc* gpCellFile_0077BC84; // 0x0077BC84

extern D2CelFileStrc* gpCellFile_0077BC88; // 0x0077BC88

extern D2CelFileStrc* gpCellFile_0077BC8C; // 0x0077BC8C

extern D2CelFileStrc* gpCellFile_0077BC90; // 0x0077BC90

extern D2CelFileStrc* gpCellFile_0077BC94; // 0x0077BC94

extern D2CelFileStrc* gpCellFile_0077BCB8; // 0x0077BCB8

extern D2CelFileStrc* gpCellFile_0077BCBC; // 0x0077BCBC

extern D2CelFileStrc* gpCellFile_0077BCC0; // 0x0077BCC0

extern D2CelFileStrc* gpCellFile_0077BCC4; // 0x0077BCC4

extern D2CelFileStrc* gpCellFile_0077BCC8; // 0x0077BCC8

extern D2CelFileStrc* gpCellFile_0077BCCC; // 0x0077BCCC

extern D2CelFileStrc* gpCellFile_0077BCD0; // 0x0077BCD0

extern D2CelFileStrc* gpCellFile_0077BCD4; // 0x0077BCD4

extern D2CelFileStrc* gpCellFile_0077BCD8; // 0x0077BCD8

extern D2CelFileStrc* gpCellFile_0077BD0C; // 0x0077BD0C

extern D2CelFileStrc* gpCellFile_0077BD10; // 0x0077BD10

extern D2CelFileStrc* gpCellFile_0077BD18; // 0x0077BD18

extern D2CelFileStrc* gpCellFile_0077BD2C; // 0x0077BD2C

extern D2CelFileStrc* gpCellFile_0077BD30; // 0x0077BD30

extern D2CelFileStrc* gpCellFile_0077BD34; // 0x0077BD34

extern D2CelFileStrc* gpCellFile_0077BD38; // 0x0077BD38

extern D2CelFileStrc* gpCellFile_0077BD3C; // 0x0077BD3C

extern D2CelFileStrc* gpCellFile_0077BD40; // 0x0077BD40

extern D2CelFileStrc* gpCellFile_0077BD44; // 0x0077BD44

extern D2CelFileStrc* gpCellFile_0077BD48; // 0x0077BD48

extern D2CelFileStrc* gpCellFile_0077BD4C; // 0x0077BD4C

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned int __stdcall GetACP(); // 0x006CC32C

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, unsigned short* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall GetDateFormatA(unsigned long nLocale, unsigned long dwFlags, const D2SystemTimeStrc* pDate, const char* szFormat, char* szDate, int nDate); // 0x006CC330

extern "C" __declspec(dllimport) int __stdcall FileTimeToSystemTime(const _FILETIME* pFileTime, D2SystemTimeStrc* pSystemTime); // 0x006CC334

extern "C" __declspec(dllimport) int __stdcall FileTimeToLocalFileTime(const _FILETIME* pFileTime, _FILETIME* pLocalFileTime); // 0x006CC338

unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int GetPersist();
    virtual void SetPersist(int bPersist);
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" size_t __cdecl strlen(const char* szString);

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140

void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0

int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor); // 0x0043E5F0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

extern char gaszHistory_0077B1D8[10][0x100]; // 0x0077B1D8

extern int gnHistoryCount_0077BD50; // 0x0077BD50

extern int gbShowJoinLeave_0077BD54; // 0x0077BD54

D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C

extern char gszLastWhisperer_0077B0D0[]; // 0x0077B0D0

extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C

extern unsigned char gnSelectModeA_0070CD62; // 0x0070CD62

int gnGlobal_0077B0A0;                                                                                      // 0x0077B0A0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" int __cdecl strcmp(const char*, const char*);

void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0

int __cdecl CHATDLG_ResetControls(); // 0x0043EBA0

void __cdecl CHATDLG_CreateControls(); // 0x0043EB30

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0

Unicode* __fastcall D2Win_10196(D2WinControlStrc* pTextBox, int nLineNum, int nColumnNum); // 0x004FBB90

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

void __fastcall VIEW_SendMcpLadderRequest(unsigned char nArg1, unsigned short nArg2); // 0x0044AA10

extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070

extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078

D2WinControlStrc* gpList_0077BD00; // 0x0077BD00

int gnColor_0077AD74; // 0x0077AD74

extern int gnSelectLine_0070CD68; // 0x0070CD68

extern int gnSelectLinePrev_0070CD64; // 0x0070CD64

int gnSelection_0077BBF4;                                                                                   // 0x0077BBF4

D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10; // 0x0077AC10

D2WinControlStrc* gpChatControl_0077B060; // 0x0077B060

D2WinControlStrc* gpChatControl_0077B084; // 0x0077B084

D2WinControlStrc* gpChatControl_0077B088; // 0x0077B088

D2WinControlStrc* gpChatControl_0077B08C; // 0x0077B08C

D2WinControlStrc* gpChatControl_0077B090; // 0x0077B090

int gbChatSetup_0077BBF8; // 0x0077BBF8

struct D2LaunchRecord3Strc;

struct D2LaunchThreadRecordStrc;

struct D2LaunchNameNodeStrc;

struct D2LaunchRecord3Strc
{
    int nValue0;
    int nValue1;
    int f_8;
};

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

void __cdecl CHATDLG_RefreshChatScreen(); // 0x0043FBD0

int __fastcall sub_0044AAE0_SendSelect(const char* szName, int nB, int nC); // 0x0044AAE0

int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0

int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380

int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50

void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA); // 0x00449050

unsigned long __stdcall sub_0044A070_ThreadProc(void* pParameter); // 0x0044A070

extern char gKey_0070CD54; // 0x0070CD54

char gszSelectName_0077B040[16];                                                                            // 0x0077B040

extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C

extern char gKey_0077B0A8; // 0x0077B0A8

unsigned short gwSavedRequestId_0077BBDC;                                                                   // 0x0077BBDC

int gnLaunchMode_0077BBE4;                                                                                  // 0x0077BBE4

extern int gbCheck_0077BD58; // 0x0077BD58

extern int gbSelectActive_0077BD00; // 0x0077BD00

static int gbDone_0077BDA0;                                                                                 // 0x0077BDA0

extern int gnValue_00798F5C; // 0x00798F5C

extern int gnValue_00798F7C; // 0x00798F7C

extern int gnValue_00798F84; // 0x00798F84

extern D2LaunchThreadRecordStrc gtThreadRecord_00798FB8; // 0x00798FB8

extern int gnValue_00799100; // 0x00799100

extern int gnValue_00799104; // 0x00799104

extern int gnValue_00799298; // 0x00799298

extern int gnValue_0079929C; // 0x0079929C

extern int gnValue_007992A0; // 0x007992A0

extern void* ghThread_007992A4; // 0x007992A4

extern int gnValue_007992A8; // 0x007992A8

extern int gnValue_007992E0; // 0x007992E0

extern int gnValue_007992E8; // 0x007992E8

extern int gnValue_007992F0; // 0x007992F0

extern D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98

void __fastcall sub_004423B0_RunCommand(char* szText); // 0x004423B0

void __fastcall COMCALLBACK_PrintOwnLine(const char* szText); // 0x004481F0

int __fastcall sub_004FB910_GetLineCount(D2WinControlStrc* pTextBox); // 0x004FB910

D2WinButtonStrc* gpClassButtons_0077BC98[8]; // 0x0077BC98

static int gbExpansionClasses_0070CD70; // 0x0070CD70

extern char gszChatBuffer_0077AE40[0x200]; // 0x0077AE40

int gnGlobal_0077AD70;                                                                                      // 0x0077AD70

extern int gnGlobal_0070CD7C; // 0x0070CD7C

extern unsigned char gbGlobal_0070CD63; // 0x0070CD63

extern unsigned char gbGlobal_0070CD62; // 0x0070CD62

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_004FCC40_AddLine(D2WinControlStrc* pControl, const Unicode* pText, int nColor, int nA, int nB); // 0x004FCC40

extern "C" const char gszDash_006CCA2C[]; // 0x006CCA2C

struct D2LaunchNameNodeStrc
{
    char szName[0x200];
    int nId;
    D2LaunchNameNodeStrc* pNext;
};

D2LaunchNameNodeStrc* gpNameList_0077BDB4; // 0x0077BDB4

void __cdecl COMCALLBACK_UpdateNameListText(); // 0x0043F730

D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C

int gbPending_0077BD9C; // 0x0077BD9C

D2LaunchCallback gpfnLaunchCallback_0077BDA4; // 0x0077BDA4

int gnResult_00798F58; // 0x00798F58

char gszText_00798F60[28]; // 0x00798F60

char gszText_00799294[4]; // 0x00799294

unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750

unsigned int __stdcall SStrHashHT(const char* szPath);                                           // 0x00414150

extern "C" int __cdecl isalnum(int c);                                                                      // 0x006870FB

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

const char* __fastcall CHATDLG_SkipNamePrefix(const char* szName); // 0x00446820

void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText);                      // 0x0043EA70

int __stdcall MAINMENUS_FindCdKeyInText(const char* szText);                                             // 0x0043E900

int __cdecl CHATDLG_SendChatBuffer();                                                                  // 0x00442810

extern D2MultiChannelUserStrc* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48

static int __stdcall sub_0043E860_FindHashedWord(char* szText, unsigned int nHash, int nLength);

struct D2WinTextBoxStrc;

struct UnicodeChar;

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470

int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

int __cdecl STRTABLE_GetLanguage(); // 0x00525150

void __fastcall sub_004FC720(D2WinControlStrc* pList, int nValue); // 0x004FC720

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740

void __fastcall sub_004FBCD0(D2WinControlStrc* pList, int nColumn, int nValue); // 0x004FBCD0

void __cdecl CHATDLG_ClearLadderList(); // 0x0043F0E0

void __fastcall sub_004FD830(D2WinControlStrc* pControl); // 0x004FD830

void __fastcall sub_004FDA50(D2WinControlStrc* pControl); // 0x004FDA50

void __fastcall CHATDLG_FillLadderList(int nA, int nB); // 0x004403F0

void __cdecl CHATDLG_ClearLadderState(); // 0x0043ED50

int __stdcall sub_0043EB00_OnErrorDone(int nArg); // 0x0043EB00

extern D2WinControlInitStrc gtControlInits_0070CE50[]; // 0x0070CE50

unsigned long gdwConnectTime_0077BBF0;                                                                      // 0x0077BBF0

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* pButton, int nValue); // 0x00500B20

extern "C" int __cdecl rand();

D2WinControlStrc* gpControls_0077ADA8[32]; // 0x0077ADA8

int gnControlCount_0077BBE8; // 0x0077BBE8

struct D2WinMsgStrc;

void __cdecl CHATDLG_ReleaseClassButtons();                                                            // 0x0043F060

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

void __fastcall CHATDLG_CopyNamePrefix(const char* szName, char* szOut);                               // 0x00446840

const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

void __cdecl CHATDLG_CreateClassScreen();                                                              // 0x004406F0

void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone);              // 0x004401C0

static D2WinControlStrc* CHATDLG_CreateControl(int nIndex); // 0x0043E9D0

struct D2LadderEntryStrc
{
    int nA;
    int nB;
    int dwFlags;
    char szName[1];
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __fastcall CHATDLG_CopyName(char* szName);                                                   // 0x00443F50

void __fastcall sub_004FB870_InsertRow(D2WinControlStrc* pControl, int nRow);                                // 0x004FB870

int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int a3);                               // 0x004FBDE0

int __fastcall D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn); // 0x004FCD90

const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0

void __stdcall sub_005255C0_FormatDate(Unicode* wszOut, int nA, int nB, int nMaxLength);                   // 0x005255C0

extern "C" const char* const gaszClassNames_006D5524[];                                                     // 0x006D5524

static D2CriticalSectionStrc gtChatLock_0077AE28; // 0x0077AE28

static D2ChatMessageStrc* gpChatQueueHead_0077BDAC; // 0x0077BDAC

static D2ChatMessageStrc* gpChatQueueTail_0077BDB0; // 0x0077BDB0

void __cdecl CHATDLG_OpenStandardLadder(); // 0x004408B0

void __cdecl CHATDLG_OpenHardcoreLadder(); // 0x00440980

void __cdecl CHATDLG_OpenExpansionLadder(); // 0x00440A50

void __cdecl CHATDLG_OpenExpansionHardcoreLadder(); // 0x00440B30

unsigned long gdwSelectTime_0077BD5C; // 0x0077BD5C

void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0

struct D2LaunchReplyStrc
{
    int nStatus;
    unsigned short f_4;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect);                                                // 0x004F97B0

void __stdcall CHATDLG_EnableConnection(int bEnable);                                                            // 0x004413E0

void __cdecl CHATDLG_FlushChatMessages();                                                                   // 0x0043E3A0

void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply);                                        // 0x00442B90

void __cdecl CHATDLG_SendPendingText();                                                                           // 0x00442E00

void __fastcall sub_00442EB0_HandleOther(D2LaunchReplyStrc* pReply);                                        // 0x00442EB0

void __cdecl CHATDLG_DestroyJoinControls();                                                                          // 0x00443130

int __cdecl COMCALLBACK_PumpMessages();                                                                            // 0x00447A10

void* __cdecl sub_00449BC0();                                                                               // 0x00449BC0

unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0

void* __cdecl sub_00449D50();                                                                               // 0x00449D50

void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60

int __cdecl sub_00449DE0();                                                                                 // 0x00449DE0

unsigned short gwOtherRequestId_0077BBE0;                                                                   // 0x0077BBE0

extern int gnLoopValueOut_0077BC14;                                                                         // 0x0077BC14

extern int gnLoopValueIn_0077BC18;                                                                          // 0x0077BC18

extern int gnFlag_0077BD60; // 0x0077BD60

static __forceinline int CONSOLE_FindSecondTokenInline(const char* szText, char* szCopy, const char** ppArg)
{
    strcpy(szCopy, szText);
    char szDelim[2] = " ";
    char* pToken = strtok(szCopy, szDelim);
    int nCount = 0;
    while (pToken)
    {
        if (++nCount == 2)
        {
            *ppArg = szText + (pToken - szCopy);
            return 1;
        }
        pToken = strtok(0, szDelim);
    }
    return 0;
}

// 0x0043C6B0
int __fastcall sub_0043C6B0_WriteSaveHeader(const char* szName)
{
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwWritten;

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = FOG_CreateFileA(szPath, 0x40000000, 0, 0, 2, 0x8000000, 0);
    if (!hFile)
        return 0;

    gtCharSaveHeader_0077AC10.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&gtCharSaveHeader_0077AC10, 0x14F);
    FOG_WriteFile(hFile, &gtCharSaveHeader_0077AC10, 0x14F, &dwWritten, 0);
// build: symbol ?FOG_CloseFile@* 0x004069A0
    FOG_CloseFile(hFile);
    return 1;
}

// 0x0043CAA0
int __fastcall CHATDLG_UpdateSaveFlags(const char* szName)
{
    D2CharSaveFileStrc tSave;
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwFlags;
    unsigned long dwWritten;
    unsigned long dwRead;

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = FOG_CreateFileA(szPath, 0xC0000000, 0, 0, 3, 0x8000000, 0);
    if (!hFile)
        return 0;

    FOG_ReadFile(hFile, &tSave, 0x2000, &dwRead, 0);
    if (dwRead < 8)
        return 0;
    if (tSave.dwMagic != 0xAA55AA55)
        return 0;

    int nResult;
    if (tSave.dwVersion <= 0x5B)
    {
        if (dwRead < 0x82)
            return 0;
        dwFlags = tSave.dwOldFlags | 0x20;
        FOG_SetFilePointer(hFile, 0x18, 0, 0);
        nResult = FOG_WriteFile(hFile, &dwFlags, 4, &dwWritten, 0);
    }
    else
    {
        if (dwRead < 0x14F)
            return 0;
        tSave.dwFlags |= 0x20;
        tSave.dwChecksum = 0;
        tSave.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&tSave, dwRead);
        FOG_SetFilePointer(hFile, 0, 0, 0);
        nResult = FOG_WriteFile(hFile, &tSave, dwRead, &dwWritten, 0);
    }

    FOG_CloseFile(hFile);
    return nResult;
}

// 0x0043CC30
void __cdecl CHATDLG_LoadFrontEndCels()
{
    char szPath[0x104];

    sprintf(szPath, "%s\\UI\\FrontEnd\\PopUpLargest2", gszDataGlobal);
    gpCellFile_0077BC0C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FrontEnd\\MediumButtonBlank2", gszDataGlobal);
    gpCellFile_0077BC10 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\bnet", gszDataGlobal);
    gpCellFile_0077BC04 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\waitingroombkgd", gszDataGlobal);
    gpCellFile_0077BC08 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpCellFile_0077BC14 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\lrotate", gszDataGlobal);
    gpCellFile_0077BC18 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\scrollbar", gszDataGlobal);
    gpCellFile_0077BC1C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpCellFile_0077BC20 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons", gszDataGlobal);
    gpCellFile_0077BC28 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons1", gszDataGlobal);
    gpCellFile_0077BC2C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons2", gszDataGlobal);
    gpCellFile_0077BC30 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrightbuttons", gszDataGlobal);
    gpCellFile_0077BC34 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrighttopbuttons", gszDataGlobal);
    gpCellFile_0077BC38 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatarrows", gszDataGlobal);
    gpCellFile_0077BC3C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingamebckg", gszDataGlobal);
    gpCellFile_0077BC50 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GameButtonBlank", gszDataGlobal);
    gpCellFile_0077BC5C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingameclickbox", gszDataGlobal);
    gpCellFile_0077BC60 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpCellFile_0077BCC0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpCellFile_0077BCC4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpCellFile_0077BCC8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpCellFile_0077BCCC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numbergreyarrows", gszDataGlobal);
    gpCellFile_0077BCD0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GreyLevelBox", gszDataGlobal);
    gpCellFile_0077BC64 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\createjoinbckg", gszDataGlobal);
    gpCellFile_0077BCD4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\okaybutton", gszDataGlobal);
    gpCellFile_0077BCD8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebckg", gszDataGlobal);
    gpCellFile_0077BD0C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebutton", gszDataGlobal);
    gpCellFile_0077BD10 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\widebuttonblank", gszDataGlobal);
    gpCellFile_0077BD18 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpCellFile_0077BD2C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\yesnobuttonblank", gszDataGlobal);
    gpCellFile_0077BD30 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBlackBnet", gszDataGlobal);
    gpCellFile_0077BD48 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBnet", gszDataGlobal);
    gpCellFile_0077BD4C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\blankbckg2", gszDataGlobal);
    gpCellFile_0077BC54 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\gembutton", gszDataGlobal);
    gpCellFile_0077BC58 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\LadderChoiceEXP", gszDataGlobal);
    gpCellFile_0077BD34 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HardcoreLadderBckg", gszDataGlobal);
    gpCellFile_0077BD38 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpCellFile_0077BD40 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpCellFile_0077BD3C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HelpBckg", gszDataGlobal);
    gpCellFile_0077BD44 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobutton", gszDataGlobal);
    gpCellFile_0077BC68 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobuttonGrey", gszDataGlobal);
    gpCellFile_0077BC6C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\PopUpOK", gszDataGlobal);
    gpCellFile_0077BC70 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpCellFile_0077BC74 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\overalltab", gszDataGlobal);
    gpCellFile_0077BC78 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\amazontab", gszDataGlobal);
    gpCellFile_0077BC7C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\sorceresstab", gszDataGlobal);
    gpCellFile_0077BC80 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\necromancertab", gszDataGlobal);
    gpCellFile_0077BC84 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\paladintab", gszDataGlobal);
    gpCellFile_0077BC88 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\barbariantab", gszDataGlobal);
    gpCellFile_0077BC8C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\druidtab", gszDataGlobal);
    gpCellFile_0077BC90 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\assassintab", gszDataGlobal);
    gpCellFile_0077BC94 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SquelchAura", gszDataGlobal);
    gpCellFile_0077BCB8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SelectAura", gszDataGlobal);
    gpCellFile_0077BCBC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sub_00504D30(gpCellFile_0077BCB8, gpCellFile_0077BCBC);
}

// 0x0043D9A0
int __stdcall CHATDLG_OnRealmConnectCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gnFlag_0077BD60 = 1;
    return 1;
}

// 0x0043D9B0
int __stdcall CHATDLG_NextRequestCallback(int nArg)
{
    while (++gwRequestId_0070CD60 == 0)
    {
    }
    gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043D9E0
int __stdcall CHATDLG_ScrollPageUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-10);
    return 1;
}

// 0x0043DAF0
int __stdcall sub_0043DAF0_OnConnect(int nArg)
{
    sub_004F9740_SetControlState(gpControlMain_0077BC4C, 1);
    return 1;
}

// 0x0043DB90
int __stdcall sub_0043DB90(int nArg)
{
    COMCALLBACK_RefreshChatButtons();
    return 1;
}

// 0x0043E1A0
static void __stdcall CHATDLG_AddTextLines(D2WinControlStrc* pControl, int bBlankLine, char* szText, int nColor)
{
    char* pText = szText;
    const int nLength = strlen(szText);
    if (nLength > 0)
    {
        while (*pText)
        {
            char* pBreak = 0;
            char* pLine = pText;
            while (*pText != '\n' && *pText)
            {
                pText++;
            }
            if (*pText == '\n')
            {
                pBreak = pText;
                *pText = 0;
                pText++;
            }
            sub_004FCFF0_SetTextA(pControl, pLine, nColor);
            if (bBlankLine)
            {
                sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
            }
            if (pBreak)
            {
                *pBreak = '\n';
            }
        }
    }
    else
    {
        sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
    }
}

// 0x0043E250
static D2ChatMessageStrc* __stdcall CHATDLG_CreateChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = (D2ChatMessageStrc*)FOG_Alloc(sizeof(D2ChatMessageStrc), ".\\Src\\ChatDlg.cpp", 0xC1D, 0);
    memset(pMessage, 0, sizeof(D2ChatMessageStrc));
    if (pMessage)
    {
        if (!szText)
        {
            pMessage->szText = 0;
        }
        else
        {
            const int nLength = SStrLen(szText);
            pMessage->szText = (char*)FOG_Alloc(nLength + 1, ".\\Src\\ChatDlg.cpp", 0xC28, 0);
            if (pMessage->szText)
            {
                SStrCopy(pMessage->szText, szText, 0x7FFFFFFF);
            }
        }
        pMessage->nColor = nColor;
        pMessage->bClear = bClear;
    }
    return pMessage;
}

// 0x0043E310
static void CHATDLG_PostChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = CHATDLG_CreateChatMessage(szText, nColor, bClear);
    if (!pMessage)
    {
        return;
    }
    EnterCriticalSection(&gtChatLock_0077AE28);
    if (gpChatQueueHead_0077BDAC)
    {
        gpChatQueueTail_0077BDB0->pNext = pMessage;
        gpChatQueueTail_0077BDB0 = pMessage;
    }
    else
    {
        gpChatQueueHead_0077BDAC = pMessage;
        gpChatQueueTail_0077BDB0 = pMessage;
    }
    LeaveCriticalSection(&gtChatLock_0077AE28);
}

// build: symbol ?CHATDLG_PopChatMessage@* 0x0043E370
static D2ChatMessageStrc* CHATDLG_PopChatMessage()
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

// build: symbol ?CHATDLG_FreeChatMessage@* 0x0043E2E0
static void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage)
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

// 0x0043E3A0
void __cdecl CHATDLG_FlushChatMessages()
{
    for (;;)
    {
        D2ChatMessageStrc* pMessage = CHATDLG_PopChatMessage();
        if (!pMessage)
        {
            return;
        }
        if (pMessage->bClear)
        {
            sub_004FB6A0_ClearText(gpChatTextBox_0077BD8C);
        }
        if (pMessage->szText)
        {
            CHATDLG_AddTextLines(gpChatTextBox_0077BD8C, 0, pMessage->szText, pMessage->nColor);
        }
        CHATDLG_FreeChatMessage(pMessage);
        D2Win_10053(gpChatTextBox_0077BD8C, 0);
    }
}

// 0x0043E450
static void __stdcall CHATDLG_FileTimeToText(char* szDate, int nSize, const _FILETIME* pFileTime)
{
    unsigned short wszDate[0x100];
    for (int i = 0; i < 0x100; i++)
        wszDate[i] = 0;
    D2SystemTimeStrc tSystemTime;
    FileTimeToSystemTime(pFileTime, &tSystemTime);
    GetDateFormatA(0x400, 2, &tSystemTime, 0, szDate, nSize);
    MultiByteToWideChar(GetACP(), 1, szDate, -1, wszDate, 0x100);
    sub_005263E0(szDate, (Unicode*)wszDate, nSize);
}

// 0x0043E4C0
int __fastcall CHATDLG_OnChatTime(unsigned int nTime, const char* szText)
{
    D2_ASSERT(szText, 0xCA4);
    if (nTime)
    {
        const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
        _FILETIME tFileTime;
        tFileTime.dwLowDateTime = (unsigned long)nFileTime;
        tFileTime.dwHighDateTime = (unsigned long)(nFileTime >> 32);
        _FILETIME tLocalTime;
        FileTimeToLocalFileTime(&tFileTime, &tLocalTime);
        char szDate[0x40];
        CHATDLG_FileTimeToText(szDate, 0x40, &tLocalTime);
        CHATDLG_PostChatMessage(szDate, 0, 0);
        CHATDLG_PostChatMessage(szText, 4, 0);
        CHATDLG_PostChatMessage(&gszEmptyAssertText, 0, 0);
    }
    return 1;
}

struct D2WinControlStrc;

// 0x0043E570
int __cdecl CHATDLG_PostClearMessage()
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

// 0x0043E5F0
int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E610
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E630
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText)
{
    if (gpControl_0077BD98)
    {
        sub_004FB6A0_ClearText(gpControl_0077BD98);
        sub_004FC9B0_SetText(gpControl_0077BD98, pText, 3, 0, 0);
    }

    return 1;
}

// build: symbol ?CHATDLG_CompareCommand@* 0x0043E6E0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand)
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

// 0x0043E780
static int CHATDLG_NotifyCommand(const char* szCommand, const char* szText)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        if (!CHATDLG_CompareCommand(szText, szCommand))
        {
            char szMessage[0x100];
            unsigned short wszMessage[0x100];
            gbShowJoinLeave_0077BD54 = !gbShowJoinLeave_0077BD54;
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            if (gbShowJoinLeave_0077BD54)
                strcpy(szMessage, "Player entering/leaving notifications are enabled.");
            else
                strcpy(szMessage, "Player entering/leaving notifications are disabled.");
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x200);
            if (gpChatTextBox_0077BD8C)
                sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, (Unicode*)wszMessage, 3, 0, 1);
        }
        return 1;
    }
    return 0;
}

// 0x0043E860
static int __stdcall sub_0043E860_FindHashedWord(char* szText, unsigned int nHash, int nLength)
{
    if (!nLength)
        return 0;

    const int nTextLength = SStrLen(szText);
    for (int i = 0; i <= nTextLength - nLength; ++i)
    {
        if (i > 0 && isalnum(szText[i - 1]))
            continue;

        if (i < nTextLength - nLength && isalnum((szText + i)[nLength]))
            continue;

        const unsigned char c = (szText + i)[nLength];
        (szText + i)[nLength] = 0;
        const unsigned int nValue = SStrHashHT(szText + i);
        (szText + i)[nLength] = c;
        if (nValue == nHash)
            return 1;
    }

    return 0;
}

int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper)
{
    const int bCommand = szText[0] == '/';
    SMemZero(gszChatBuffer_0077AE40, sizeof(gszChatBuffer_0077AE40));
    if (bWhisper && !bCommand && gpSelectedChannelUser_00798F48)
        sprintf(gszChatBuffer_0077AE40, "/whisper *%s %s", CHATDLG_SkipNamePrefix(gpSelectedChannelUser_00798F48->szName), szText);
    else
        strcpy(gszChatBuffer_0077AE40, szText);

    if (sub_0043E860_FindHashedWord(szText, gpCharInfo_0077BBD8->nWordHash, gpCharInfo_0077BBD8->nWordLength))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B37), D2LANG_GetStringFromTblIndex(0x2B38));
        gszChatBuffer_0077AE40[0] = 0;
        return 0;
    }

    if (MAINMENUS_FindCdKeyInText(szText))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B7A), D2LANG_GetStringFromTblIndex(0x2B7B));
        gszChatBuffer_0077AE40[0] = 0;
        return 0;
    }

    return CHATDLG_SendChatBuffer();
}

// 0x0043E9D0
static D2WinControlStrc* CHATDLG_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount_0077BBE8 < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlInits_0070CE50[nIndex]);
    gpControls_0077ADA8[gnControlCount_0077BBE8++] = pControl;
    return pControl;
}

// 0x0043EA70
void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText)
{
// build: symbol ?CHARSEL_DestroyPopupControls@* 0x0043EA20
    CHARSEL_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x25);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x27);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x28);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pTitle, 0, 0, 0);
    pControl = CHATDLG_CreateControl(0x29);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
}

// 0x0043EB10
int __stdcall CHATDLG_RunCallback(int nArg)
{
    if (gpfnLaunchCallback_0077BDA4)
        gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043EB30
void __cdecl CHATDLG_CreateControls()
{
    D2WinControlStrc* pControl;
    CHATDLG_CreateControl(0x5D);
    pControl = CHATDLG_CreateControl(0x5E);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    CHATDLG_CreateControl(0x5F);
    CHATDLG_CreateControl(0x61);
    CHATDLG_CreateControl(0x62);
    CHATDLG_CreateControl(0x63);
    sub_004FA450_SetActive(CHATDLG_CreateControl(0x64));
}

// 0x0043EBA0
int __cdecl CHATDLG_ResetControls()
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControlA_0077B070, 1);
        CONTROL_SetEnabled(gpControlB_0077B078, 1);
    }
    if (gpCharInfo_0077BBD8->szRealm0x361[0])
        CONTROL_SetEnabled(gpChatControl_0077B074, 1);
    else
        CONTROL_SetEnabled(gpChatControl_0077B074, gbChatSetup_0077BBF8 == 0);
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    return 1;
}

// 0x0043EC60
void __fastcall CHATDLG_SelectEntry(const char* szName, int nB, int nC)
{
    if (!gbSelectActive_0077BD00)
        return;
    SStrCopy(gszSelectName_0077B040, szName, 0x7FFFFFFF);
    char nMode;
    if (nC)
        nMode = nB ? 0x13 : 0x1B;
    else
        nMode = nB ? 0 : 9;
    gnSelectModeA_0070CD62 = nMode;
    gnSelectModeB_0070CD63 = nMode;
    gnSelectIdA_0070CD7C = -1;
    gnSelectIdB_0070CD80 = -1;
    sub_0044AAE0_SendSelect(szName, nB, nC);
    gdwSelectTime_0077BD5C = GetTickCount() + 1000;
}

// build: symbol ?CHATDLG_PushHistory@* 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory_0077B1D8[1], gaszHistory_0077B1D8[0], 0x900);
    strcpy(gaszHistory_0077B1D8[0], szText);
    if (++gnHistoryCount_0077BD50 >= 10)
        gnHistoryCount_0077BD50 = 10;
}

// build: symbol ?CHATDLG_GetArgument@* 0x0043F870
static void __stdcall CHATDLG_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

// 0x00442180
static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand))
    {
        if (szText[nLength] == ' ' || !szText[nLength])
        {
            char szMessage[260];
            if (!strlen(gszLastWhisperer_0077B0D0))
            {
                Unicode wszMessage[0x100] = {};
                sprintf(szMessage, gszNobodyToReply_006D561C);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox_0077BD8C)
                    sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, wszMessage, 1, 0, 1);
                return 1;
            }

            char szPrefix[0x100];
            sprintf(szPrefix, gszCommandSpace_006D5618, szCommand);
            char szCopy[0x100];
            const char* pMessage;
            if (!CONSOLE_FindSecondTokenInline(szText, szCopy, &pMessage))
            {
                Unicode wszMessage[0x100];
                sprintf(szMessage, gszCorrectUsage_006D55F8, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox_0077BD8C)
                    sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, wszMessage, 1, 0, 1);
                return 1;
            }
            if (!gpLaunchFuncs_0077B09C->pfn0x68())
            {
                CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }

            sprintf(szMessage, gszReplyFormat_006D55EC, gszLastWhisperer_0077B0D0, pMessage);
            gpLaunchFuncs_0077B09C->pfn0x14(szMessage);
            return 1;
        }
    }
    return 0;
}

void __fastcall sub_004423B0_RunCommand(char* szText)
{
    CHATDLG_PushHistory(szText);
    if (CHATDLG_ReplyCommand(gszCmdR_006D56D4, szText))
        return;

    if (CHATDLG_ReplyCommand(gszCmdReply_006D56CC, szText))
        return;

    if (CHATDLG_NotifyCommand(gszCmdD2Notify_006D56C0, szText))
        return;

    if (!CHATDLG_CompareCommand(szText, "/ignorepersist"))
    {
        sub_00611560_GetSquelchList()->SetPersist(!sub_00611560_GetSquelchList()->GetPersist());
        if (sub_00611560_GetSquelchList()->GetPersist())
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA1), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA2), 3);
        return;
    }

// build: symbol ?gszCmdSquelch@* 0x006D5698
    if (!CHATDLG_CompareCommand(szText, "/ignore ") || !CHATDLG_CompareCommand(szText, gszCmdSquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szName, szText);
        if (!SStrCmpI(&szName[1], gpCharInfo_0077BBD8->szText0x8D, 0x7FFFFFFF))
            return;

        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Squelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

// build: symbol ?gszCmdUnsquelch@* 0x006D5680
    if (!CHATDLG_CompareCommand(szText, "/unignore ") || !CHATDLG_CompareCommand(szText, gszCmdUnsquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szName, szText);
        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Unsquelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, "/filtermsg "))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szFilter, szText);
        if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA7), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA8), 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, "/unfiltermsg "))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szFilter, szText);
        if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA9), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BAA), 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, gszCmdHomeChannel_006D5654) || !CHATDLG_CompareCommand(szText, gszCmdDefaultChannel_006D5640) || !CHATDLG_CompareCommand(szText, gszCmdHomeSpace_006D5638))
    {
        char szChannel[0x20];
        CHATDLG_GetArgument(0x20, szChannel, szText);
        SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, gszCmdHome_006D5630))
    {
        char szChannel[0x20];
        if (SRegLoadString("Diablo II", "Default Channel", 0, szChannel, 0x20))
            CHATDLG_JoinChannel(szChannel);
        return;
    }

    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
}

// 0x0043ECE0
int __stdcall CHATDLG_ScrollLadderUp(int a)
{
    gnSelectIdA_0070CD7C -= gnGlobal_0077B0A0;
    unsigned char m = gnSelectModeB_0070CD63;
    gnSelectIdA_0070CD7C &= (gnSelectIdA_0070CD7C <= 0) - 1;
    gnSelectModeA_0070CD62 = m;
    return 1;
}

// 0x0043ED10
int __stdcall CHATDLG_ScrollLadderDown(int nUnused)
{
    int nBase = gnGlobal_0077B0A0;
    int nOther = gnGlobal_0077AD70;
    int nCurrent = gnGlobal_0070CD7C;
    int nDifference = nOther - nBase;
    int nCombined = nBase + nCurrent;
    if (nCombined < nDifference)
        nDifference = nCombined;
    gbGlobal_0070CD62 = gbGlobal_0070CD63;
    gnGlobal_0070CD7C = nDifference;
    return 1;
}

// 0x0043ED60
void __cdecl CHATDLG_CreateClassButtons()
{
    D2WinControlStrc* pControl;
    Unicode szText0[0x10];
    Unicode szText1[0x10];
    Unicode szText2[0x10];
    Unicode szText3[0x10];
    Unicode szText4[0x10];
    Unicode szText5[0x10];
    Unicode szText6[0x10];
    sub_00526F20_ToUnicode(szText0, "AMA", 0x10);
    sub_00526F20_ToUnicode(szText1, "SOR", 0x10);
    sub_00526F20_ToUnicode(szText2, "NEC", 0x10);
    sub_00526F20_ToUnicode(szText3, "PAL", 0x10);
    sub_00526F20_ToUnicode(szText4, "BAR", 0x10);
    sub_00526F20_ToUnicode(szText5, "DRU", 0x10);
    sub_00526F20_ToUnicode(szText6, "ASN", 0x10);
    gpClassButtons_0077BC98[0] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6E);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[0], 1);
    pControl = CHATDLG_CreateControl(0x76);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CE));
    gpClassButtons_0077BC98[1] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6F);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[1], 0);
    D2Win_10044(CHATDLG_CreateControl(0x77), szText0);
    gpClassButtons_0077BC98[2] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x70);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[2], 0);
    D2Win_10044(CHATDLG_CreateControl(0x78), szText1);
    gpClassButtons_0077BC98[3] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x71);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[3], 0);
    D2Win_10044(CHATDLG_CreateControl(0x79), szText2);
    gpClassButtons_0077BC98[4] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x72);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[4], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7A), szText3);
    gpClassButtons_0077BC98[5] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x73);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[5], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7B), szText4);
    if (gbExpansionClasses_0070CD70)
    {
        gpClassButtons_0077BC98[6] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x74);
        BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[6], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7C), szText5);
        gpClassButtons_0077BC98[7] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x75);
        BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[7], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7D), szText6);
    }
}

// 0x0043F060
void __cdecl CHATDLG_ReleaseClassButtons()
{
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[0], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[1], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[2], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[3], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[4], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[5], 0);
    if (gbExpansionClasses_0070CD70)
    {
        BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[6], 0);
        BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[7], 0);
    }
}

// 0x0043F0E0
void __cdecl CHATDLG_ClearLadderList()
{
    sub_004FB6A0_ClearText(gpList_0077BD00);
    char szText[2];
    Unicode wszText[2] = { Unicode(0), Unicode(0) };
    sprintf(szText, gszDash_006CCA2C);
    sub_00526F20_ToUnicode(wszText, szText, 2);
    sub_004FCC40_AddLine(gpList_0077BD00, wszText, gnColor_0077AD74, 4, 0);
    D2Win_10053(gpList_0077BD00, 0);
    gnSelection_0077BBF4 = -2;
}

// 0x0043F150
static int __stdcall CHATDLG_GetClassSlot(int nBase, int nMode)
{
    int nOffset;
    if (nMode >= 9 && nMode <= 16)
    {
        nOffset = 9;
    }
    else if (nMode >= 0 && nMode <= 7)
    {
        nOffset = 0;
    }
    else if (nMode >= 0x13 && nMode <= 0x1A)
    {
        nOffset = 0x13;
    }
    else if (nMode >= 0x1B && nMode <= 0x22)
    {
        nOffset = 0x1B;
    }
    else
    {
        D2_ASSERT(0, 0x1A23);
    }
    return nBase + nOffset;
}

// 0x0043F1D0
int __stdcall CHATDLG_OnOverallLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[0], 1);
    if (gnSelectModeA_0070CD62 != 9 && gnSelectModeA_0070CD62 != 0)
    {
        gnColor_0077AD74 = 0x3E8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(0, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F230
int __stdcall CHATDLG_OnAmazonLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[1], 1);
    if (gnSelectModeA_0070CD62 != 10 && gnSelectModeA_0070CD62 != 1)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(1, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F290
int __stdcall CHATDLG_OnSorceressLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[2], 1);
    if (gnSelectModeA_0070CD62 != 11 && gnSelectModeA_0070CD62 != 2)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(2, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F2F0
int __stdcall CHATDLG_OnNecromancerLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[3], 1);
    if (gnSelectModeA_0070CD62 != 12 && gnSelectModeA_0070CD62 != 3)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(3, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F350
int __stdcall CHATDLG_OnPaladinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[4], 1);
    if (gnSelectModeA_0070CD62 != 13 && gnSelectModeA_0070CD62 != 4)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(4, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F3B0
int __stdcall CHATDLG_OnBarbarianLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[5], 1);
    if (gnSelectModeA_0070CD62 != 14 && gnSelectModeA_0070CD62 != 5)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(5, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F410
int __stdcall CHATDLG_OnDruidLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[6], 1);
    if (gnSelectModeA_0070CD62 != 15 && gnSelectModeA_0070CD62 != 6)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(6, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F470
int __stdcall CHATDLG_OnAssassinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gpClassButtons_0077BC98[7], 1);
    if (gnSelectModeA_0070CD62 != 16 && gnSelectModeA_0070CD62 != 7)
    {
        gnColor_0077AD74 = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag_0070CD6C = 1;
        gnSelectModeA_0070CD62 = (unsigned char)CHATDLG_GetClassSlot(7, gnSelectModeA_0070CD62);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F590
int __stdcall CHATDLG_GetUserDataReply(int nUnused)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = 8;
    tRecord.nValue1 = 0x28;
    tRecord.f_8 = 0xC8;
    if (gpLaunchFuncs_0077B09C->pfn0x7C(3, 1, &gKey_0077B0A8, &tRecord) || gbFlag_0077ADA4)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x0043F800
void __cdecl CHATDLG_FreeNameList()
{
    D2LaunchNameNodeStrc* pNode = gpNameList_0077BDB4;
    while (pNode)
    {
        D2LaunchNameNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\ChatDlg.cpp", 0x1C01, 0);
        pNode = pNext;
    }
    gpNameList_0077BDB4 = 0;
}

static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
        D2Win_10051((D2WinTextBoxStrc*)gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043F630
int __stdcall CHATDLG_OnToggleButton(int nArg)
{
    if (gbToggle_0077BBEC)
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpChatControl_0077BC48, 0);
        gbToggle_0077BBEC = 0;
        PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D7), 0x0B);
    }
    else
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpChatControl_0077BC48, 2);
        gbToggle_0077BBEC = 1;
        if (rand() % 1000 == 0)
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D8), 0x0B);
        }
        else if (rand() % 1000 == 0 && rand() % 1000 == 0)
        {
            UnicodeChar wszText[20];
            sub_00526320_ToUnicode(wszText, "Moooooooo!", 12);
            PrintTextBox(wszText, 9);
        }
        else
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D6), 0x0B);
        }
    }
    return 1;
}

// 0x0043F8A0
static inline void CHATDLG_SaveDefaultChannel(const char* szChannel)
{
    SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
}

// 0x0043F930
int __stdcall CHATDLG_SetCallback(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    gpfnLaunchCallback_0077BDA4 = pfnCallback;
    return 1;
}

// 0x0043FC20
void __cdecl CHATDLG_CreateChatScreen()
{
    char szText[0x100];

    if (!gbChatSetup_0077BBF8)
        return;

    gbChatSetup_0077BBF8 = 0;
    sprintf(szText, "%s,%s", gpCharInfo_0077BBD8->szRealm0x22D, gpCharInfo_0077BBD8->szName0xBD);
    CHARSEL_ResetChatControls();

    if (gpChatCellFile_0077BBFC)
        sub_005041B0_Destroy(gpChatCellFile_0077BBFC, 1);
    gpChatCellFile_0077BBFC = 0;

    BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    gpChatControl_0077B058 = CONTROL_Create(&gtControlTemplates_00708D10[0x15C]);
    gpChatControl_0077B05C = CONTROL_Create(&gtControlTemplates_00708D10[0x15D]);
    gpChatControl_0077B060 = CONTROL_Create(&gtControlTemplates_00708D10[0x15E]);
    gpChatControl_0077B064 = CONTROL_Create(&gtControlTemplates_00708D10[0x15F]);
    gpChatControl_0077B068 = CONTROL_Create(&gtControlTemplates_00708D10[0x160]);
    gpChatControl_0077B06C = CONTROL_Create(&gtControlTemplates_00708D10[0x161]);
    gpChatControl_0077B084 = CONTROL_Create(&gtControlTemplates_00708D10[0x167]);
    gpChatControl_0077B088 = CONTROL_Create(&gtControlTemplates_00708D10[0x168]);
    gpChatControl_0077B08C = CONTROL_Create(&gtControlTemplates_00708D10[0x169]);
    gpChatControl_0077B090 = CONTROL_Create(&gtControlTemplates_00708D10[0x16A]);
    CONTROL_SetEnabled(gpChatControl_0077B074, 1);

    gpChatEdit_0077BD94 = CONTROL_Create(&gtControlTemplates_00708D10[0x172]);
    sub_004FDAD0_SetKeyCallback(gpChatEdit_0077BD94, sub_0043F9B0_EditKey);
    sub_004FDB00_SetEnterCallback(gpChatEdit_0077BD94, sub_0043DB90);
    CONTROL_SetFocusedEditBox(gpChatEdit_0077BD94);
    sub_004FDD50_SetMaxLength(gpChatEdit_0077BD94, 0xC8);
    COMCALLBACK_RefreshChatButtons();

    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B084, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B088, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B08C, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B090, 1);

    D2WinControlStrc** ppButton = gapChatButtons_0077AD78;
    for (int nX = 0x28; nX < 0x2BC; nX += 0x3C)
    {
        *ppButton++ = BUTTON_Create(nX, 0x24F, 0x3C, 0x64, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
    }

    gpChatControl_0077BC44 = CONTROL_Create(&gtControlTemplates_00708D10[0x170]);
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    gpChatControl_0077BC48 = CONTROL_Create(&gtControlTemplates_00708D10[0x178]);
    if (gbToggle_0077BBEC)
        sub_00500B20_SetValue(gpChatControl_0077BC48, 2);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

// 0x0043F9B0
int __stdcall CHATDLG_ChatEditKeyCallback(void* pArg, int nCursor, const char* pKey)
{
    if (*pKey == 0x0E)
    {
        char szText[0x100];
        char szName[0x100];
        char szLeft[0x100];
        char szRight[0x100];

        const Unicode* pEditText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
        if (pEditText && gpSelectedChannelUser_00798F48)
        {
            CHATDLG_CopyNamePrefix(gpSelectedChannelUser_00798F48->szName, szName);
            Unicode wszText[0x100];
            sub_00526F70(szText, pEditText, 0x100);
            const int nTextLength = strlen(szText);
            if ((int)strlen(szName) + nTextLength > 0xFF)
            {
                return 0;
            }

            strncpy(szLeft, szText, nCursor);
            szLeft[nCursor] = 0;
            strncpy(szRight, &szText[nCursor], nTextLength - nCursor);
            szRight[nTextLength - nCursor] = 0;
            sprintf(szText, "%s%s%s", szLeft, szName, szRight);
            sub_00526F20(wszText, szText, 0x100);
            sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, wszText);
        }
        return 0;
    }

    if (*pKey == 9)
    {
        if (gnHistoryCount_0077BD50)
        {
            ++gnHistoryIndex_0070CD74;
            if (gnHistoryIndex_0070CD74 >= gnHistoryCount_0077BD50)
            {
                gnHistoryIndex_0070CD74 = 0;
            }
            sub_004FFE10_SetTextA(gpChatEdit_0077BD94, gaszHistory_0077B1D8[gnHistoryIndex_0070CD74]);
        }
        return 0;
    }

    return 1;
}

// 0x0043F5F0
int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = nB;
    tRecord.nValue1 = nC;
    tRecord.f_8 = nD;
    return gpLaunchFuncs_0077B09C->pfn0x74(nA, 3, &gKey_0070CD54, &tRecord);
}

// 0x0043FFA0
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37)
{
    gnLaunchMode_0077BBE4 = 2;
    CHATDLG_SetCallback(0, sub_0043DAF0_OnConnect);
    *(unsigned short*)gpCharInfo_0077BBD8->wValue = wValue;
    strcpy(gpCharInfo_0077BBD8->szText0x1F, szText0x1F);
    strcpy(gpCharInfo_0077BBD8->szText0x245, szText0x245);
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        if (sub_00449B30_QueryAddress())
        {
            *(int*)gpCharInfo_0077BBD8->nState = 3;
            while (++gwRequestId_0070CD60 == 0)
            {
            }
// build: symbol ?WINMAIN_SendMcpJoinGame@* 0x0044A4E0
            WINMAIN_SendMcpJoinGame(szText0x1F, szText0x245, gwRequestId_0070CD60);
            gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
            return 1;
        }
        gnLaunchMode_0077BBE4 = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
        return 0;
    }
    *(int*)gpCharInfo_0077BBD8->nState = 7;
    strcpy(gpCharInfo_0077BBD8->szText0x37, szText0x37);
    gbDone_0077BDA0 = 1;
    sub_004F9160_SetLoopValue(0);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00440110
int __stdcall CHATDLG_OnEditChange(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?CHARSEL_UpdateOkEnabled@* 0x0043E660
    CHARSEL_UpdateOkEnabled();
    return 1;
}

// 0x00440120
int __stdcall CHATDLG_OnClearEdit(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
    CHARSEL_DestroyPopupControls();
    return 1;
}

// 0x00440140
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHARSEL_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x22);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
    gpfnLaunchCallback_0077BDA4 = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
}

// 0x004401C0
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHARSEL_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x23);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
    gpfnLaunchCallback_0077BDA4 = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
    gdwConnectTime_0077BBF0 = GetTickCount();
}

// 0x00440240
int __stdcall CHATDLG_OnReset(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_ResetControls();
    CHARSEL_ResetLaunchState();
    return 1;
}

// 0x00440260
int __stdcall CHATDLG_OnBack(SMSGHANDLER_PARAMS* pMsg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    CHARSEL_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
}

// 0x004402A0
int __cdecl CHATDLG_FindDashLine()
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
int __stdcall CHATDLG_OnIdle(SMSGHANDLER_PARAMS* pMsg)
{
    if (GetTickCount() > gdwSelectTime_0077BD5C && gpList_0077BD00
        && (CHATDLG_FindDashLine() || gnSelectFlag_0070CD6C)
        && (gnSelection_0077BBF4 != gnSelectIdA_0070CD7C || gnSelectLine_0070CD68 != gnSelectLinePrev_0070CD64))
    {
        gnSelectModeB_0070CD63 = gnSelectModeA_0070CD62;
        gnSelectIdB_0070CD80 = gnSelectIdA_0070CD7C;
        VIEW_SendMcpLadderRequest(gnSelectModeA_0070CD62, gnSelectLine_0070CD68);
        gdwSelectTime_0077BD5C = GetTickCount() + 1000;
        gnSelection_0077BBF4 = gnSelectIdB_0070CD80;
        gnSelectLinePrev_0070CD64 = gnSelectLine_0070CD68;
    }
    return 1;
}

static inline void ResetClassSelectState(int bExpansionClasses)
{
    gbExpansionClasses_0070CD70 = bExpansionClasses;
    gpClassButtons_0077BC98[0] = 0;
    gpClassButtons_0077BC98[1] = 0;
    gpClassButtons_0077BC98[2] = 0;
    gpClassButtons_0077BC98[3] = 0;
    gpClassButtons_0077BC98[4] = 0;
    gpClassButtons_0077BC98[5] = 0;
    gpClassButtons_0077BC98[6] = 0;
    gpClassButtons_0077BC98[7] = 0;
    gpList_0077BD00 = 0;
    gnColor_0077AD74 = 1000;
}

// 0x004403E0
int __stdcall CHATDLG_OnResetCallback(int nArg)
{
    CHARSEL_ResetLaunchState();
    return 1;
}

// 0x004403F0
void __fastcall CHATDLG_FillLadderList(int nStart, int nCount, int nNameLength, unsigned char nMode, D2LadderEntryStrc* pEntries)
{
    if (!gpList_0077BD00)
    {
        return;
    }

    char szTitle[256];
    char szNumber[256];
    if (!nCount)
    {
        Unicode wszText[256];
        {
            Unicode wszFormat[256];
            Unicode wszName[256];
            char szName[256];
            CHATDLG_CopyName(szName);
            sub_00526F20_ToUnicode(wszFormat, "Player '%s' is not on the ladder.", 0x100);
            sub_00526F20_ToUnicode(wszName, szName, 0x100);
            sub_005269D0(0x100, wszText, wszFormat, wszName);
        }

        CHATDLG_ShowWait(wszText, 0);
        return;
    }

    if (nMode != gnSelectModeA_0070CD62)
    {
        return;
    }

    if (gnSelectIdA_0070CD7C == -1)
    {
        D2Win_10053(gpList_0077BD00, nStart);
        gnSelectIdB_0070CD80 = nStart;
        gnSelection_0077BBF4 = nStart;
        gnSelectIdA_0070CD7C = nStart;
    }

    int nEnd = nStart + nCount;
    if (nEnd > gnColor_0077AD74)
    {
        nEnd = gnColor_0077AD74;
    }

    D2LadderEntryStrc* pEntry = pEntries;
    for (int i = nStart; i < nEnd; ++i)
    {
        const int dwFlags = pEntry->dwFlags;
        const int nClass = dwFlags & 0xF;
        const int nLevel = (dwFlags >> 16) & 0xFF;
        const int nColor = !strcmp(pEntry->szName, gszSelectName_0077B040) ? 0 : ((dwFlags & 0x10) ? 5 : 4);

        sub_004FB870_InsertRow(gpList_0077BD00, i);
        D2Win_10188(gpList_0077BD00, i, nColor);

        _itoa(i + 1, szNumber, 10);
        sub_004FCD40_SetCell(gpList_0077BD00, szNumber, i, 0);

        szTitle[0] = '\0';
        const char* szPrefix = D2Win_10161(nClass, ((unsigned int)dwFlags >> 8) & 0x1F, dwFlags & 0x20, dwFlags & 0x40);
        if (szPrefix)
        {
            strcat(szTitle, szPrefix);
        }

        strcat(szTitle, pEntry->szName);
        sub_004FCD40_SetCell(gpList_0077BD00, szTitle, i, 1);
        sub_004FCD40_SetCell(gpList_0077BD00, gaszClassNames_006D5524[nClass], i, 2);
        _itoa(nLevel, szNumber, 10);
        sub_004FCD40_SetCell(gpList_0077BD00, szNumber, i, 3);

        Unicode wszDate[256];
        sub_005255C0_FormatDate(wszDate, pEntry->nA, pEntry->nB, 0xFF);
        D2Win_10058(gpList_0077BD00, wszDate, i, 4);

        pEntry = (D2LadderEntryStrc*)((char*)pEntry + nNameLength + 0xC);
    }
}

// 0x004406F0
void __cdecl CHATDLG_CreateClassScreen()
{
    CHATDLG_CreateClassButtons();
    sub_004FA450_SetActive(CHATDLG_CreateControl(0x6D));
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x67);
    D2Win_10044(pControl, STRTABLE_GetLanguage() == 3 ? D2LANG_GetStringFromTblIndex(0x2B54) : D2LANG_GetStringFromTblIndex(0x14C8));
    pControl = CHATDLG_CreateControl(0x68);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C9));
    pControl = CHATDLG_CreateControl(0x69);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CA));
    pControl = CHATDLG_CreateControl(0x6B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CC));
    pControl = CHATDLG_CreateControl(0x6A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0xFD9));
    gpList_0077BD00 = CHATDLG_CreateControl(0x6C);
    sub_004FC720(gpList_0077BD00, 0x10);
    sub_004FBC20(gpList_0077BD00, 5);
    sub_004FB740(gpList_0077BD00, 0, -6);
    sub_004FBC80(gpList_0077BD00, 0, 0);
    sub_004FBCD0(gpList_0077BD00, 0, 0x10);
    sub_004FBC80(gpList_0077BD00, 1, 0x23);
    sub_004FBC80(gpList_0077BD00, 2, 0xA5);
    sub_004FBC80(gpList_0077BD00, 3, 0xC3);
    sub_004FBCD0(gpList_0077BD00, 3, 0x10);
    sub_004FBC80(gpList_0077BD00, 4, 0xDC);
    sub_004FBCD0(gpList_0077BD00, 4, 0x10);
    CHATDLG_ClearLadderList();
    pControl = CHATDLG_CreateControl(0x80);
    sub_004FD830(pControl);
    sub_004FDA50(pControl);
    gszSelectName_0077B040[0] = 0;
}

// 0x004408B0
void __cdecl CHATDLG_OpenStandardLadder()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(0);
        if (!sub_00449B30_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    CHATDLG_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440980
void __cdecl CHATDLG_OpenHardcoreLadder()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(0);
        if (!sub_00449B30_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C6));
    CHATDLG_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440A50
void __cdecl CHATDLG_OpenExpansionLadder()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(1);
        if (!sub_00449B30_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x276A));
    CHATDLG_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440B30
void __cdecl CHATDLG_OpenExpansionHardcoreLadder()
{
    if (gpCharInfo_0077BBD8->nByte22D)
    {
        ResetClassSelectState(1);
        if (!sub_00449B30_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x276B));
    CHATDLG_CreateClassScreen();
    gnSelection_0077BBF4 = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440C10
int __stdcall CHATDLG_ShowStandardLadder(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenStandardLadder();
    gnSelectModeA_0070CD62 = 9;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C40
int __stdcall CHATDLG_ShowExpansionLadder(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenExpansionLadder();
    gnSelectModeA_0070CD62 = 0x1B;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C70
int __stdcall CHATDLG_ShowExpansionHardcoreLadder(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenExpansionHardcoreLadder();
    gnSelectModeA_0070CD62 = 0x13;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    CHATDLG_SaveDefaultChannel(szFirst);
    CHATDLG_SaveDefaultChannel(szSecond);
}

// 0x00440DB0
int __stdcall CHATDLG_OnQuitMessage(int nArg)
{
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
    gbDone_0077BDA0 = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x004413E0
void __stdcall CHATDLG_EnableConnection(int bEnable)
{
    if (bEnable)
    {
        if (!sub_00449B30_QueryAddress())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return;
        }
        gnLaunchMode_0077BBE4 = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        if (gpControlMain_0077BC4C)
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
        return;
    }
    if (!gnLaunchMode_0077BBE4 && gbPending_0077BD9C)
        CHARSEL_ResetLaunchState();
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        CONTROL_SetEnabled(gpControlA_0077B070, 1);
        CONTROL_SetEnabled(gpControlB_0077B078, 1);
    }
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
}

// 0x00440D10
void __fastcall CHATDLG_SetPlayerName(int nPlayerId, int nDataLength, const char* szName)
{
    D2LaunchNameNodeStrc* pNode;
    for (pNode = gpNameList_0077BDB4; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nPlayerId)
            break;
    }

    if (!pNode)
    {
        pNode = (D2LaunchNameNodeStrc*)FOG_Alloc(sizeof(D2LaunchNameNodeStrc), ".\\Src\\ChatDlg.cpp", 0x1BAE, 0);
        D2LaunchNameNodeStrc* pCur = gpNameList_0077BDB4;
        pNode->nId = nPlayerId;
        if (!pCur || pCur->nId > nPlayerId)
        {
            pNode->pNext = pCur;
            gpNameList_0077BDB4 = pNode;
        }
        else
        {
            D2LaunchNameNodeStrc* pPrev = pCur;
            do
            {
                if (pCur->nId >= nPlayerId)
                    break;
                pPrev = pCur;
                pCur = pCur->pNext;
            }
            while (pCur);
            pNode->pNext = pCur;
            pPrev->pNext = pNode;
        }
    }

    SStrCopy(pNode->szName, szName, sizeof(pNode->szName));
    COMCALLBACK_UpdateNameListText();
}

// 0x00441500
int __stdcall CHATDLG_OnTick(int nUnused)
{
    static unsigned long s_dwTimer_0077BDC0; // 0x0077BDC0
    static unsigned long s_dwTimer_0077BDBC; // 0x0077BDBC
    static unsigned long s_dwTimer_0077BDB8; // 0x0077BDB8
    tagRECT tRect;
    SetRect(&tRect, 0x91, 0xB, 0x28F, 0x47);
    if (CONTROL_MouseInsideRect(&tRect))
        sub_004F9160_SetLoopValue(gnLoopValueIn_0077BC18);
    else
        sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);

    if (gnLaunchMode_0077BBE4 == 2 && gdwConnectTime_0077BBF0 > 0)
    {
        if (GetTickCount() - gdwConnectTime_0077BBF0 > 30000)
        {
            gnLaunchMode_0077BBE4 = 0;
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), 0);
            gdwConnectTime_0077BBF0 = 0;
        }
    }

    int bPending;
    do
    {
        bPending = COMCALLBACK_PumpMessages() | sub_00449B70_Receive();

        switch (gnLaunchMode_0077BBE4)
        {
        case 3:
            if (sub_00449B30_QueryAddress())
            {
                D2LaunchReplyStrc* pReply = (D2LaunchReplyStrc*)sub_00449D50();
                const unsigned short wId = pReply->f_4;
                if (wId != 0)
                {
                    if (wId == gwSavedRequestId_0077BBDC)
                    {
// build: symbol ?GAME_GetConnectError@* 0x00449C00
                        const int nResult = GAME_GetConnectError();
                        if (nResult == 0x33)
                        {
// build: symbol ?CHARSEL_FillGameListControl@* 0x00442C20
                            CHARSEL_FillGameListControl();
                            CHATDLG_ClearReply();
                        }
                        else if (nResult == 0x32)
                        {
                            CHATDLG_DestroyJoinControls();
                            CHATDLG_EnableConnection(1);
                            CHATDLG_ClearReply();
                        }
                        else if (pReply->nStatus)
                        {
                            CHARSEL_FillGameListControl();
                            CHATDLG_ClearReply();
                        }
                        else
                        {
                            CHATDLG_HandleGameListReply(pReply);
                            CHATDLG_ClearReply();
                        }
                    }
                    else
                    {
                        if (wId == gwOtherRequestId_0077BBE0)
                            sub_00442EB0_HandleOther(pReply);
                        CHATDLG_ClearReply();
                    }
                }
            }
            break;

        case 2:
            if (sub_00449B30_QueryAddress())
            {
                const int nId = CHATDLG_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId_0077BBDC)
                {
                    switch (GAME_GetConnectError())
                    {
                    case 0:
                    {
                        *(int*)gpCharInfo_0077BBD8->nState = 3;
                        *(unsigned short*)gpCharInfo_0077BBD8->wValue = (unsigned short)sub_00449BE0();
                        *(int*)gpCharInfo_0077BBD8->nValue0x229 = sub_00449DE0();
                        const char* szSource = (const char*)sub_00449BC0();
                        char* szDest = (char*)&gpCharInfo_0077BBD8->unk0x37;
                        char c;
                        do
                        {
                            c = *szSource;
                            *szDest = c;
                            szSource++;
                            szDest++;
                        }
                        while (c != 0);
                        gbDone_0077BDA0 = 1;
                        gpLaunchFuncs_0077B09C->pfn0x3C(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245);
                        sub_004F9160_SetLoopValue(0);
                        D2Win_StopMessageLoop();
                        return 1;
                    }
                    case 42:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1427), sub_0043DAF0_OnConnect);
                        break;
                    case 41:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1428), sub_0043DAF0_OnConnect);
                        break;
                    case 43:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1429), sub_0043DAF0_OnConnect);
                        break;
                    case 44:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x142A), sub_0043DAF0_OnConnect);
                        break;
                    case 115:
                        gnLaunchMode_0077BBE4 = 0;
                        if (*(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x5522), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x14F4), sub_0043DAF0_OnConnect);
                        break;
                    case 116:
                        gnLaunchMode_0077BBE4 = 0;
                        if (*(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x5521), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x14F3), sub_0043DAF0_OnConnect);
                        break;
                    case 125:
                        gnLaunchMode_0077BBE4 = 0;
                        if (gpCharInfo_0077BBD8->nValue3C2)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB1), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB2), sub_0043DAF0_OnConnect);
                        break;
                    case 113:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1426), sub_0043DAF0_OnConnect);
                        break;
                    case 120:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2775), sub_0043DAF0_OnConnect);
                        break;
                    case 121:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2776), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;

        case 1:
            if (sub_00449B30_QueryAddress())
            {
                const int nId = CHATDLG_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId_0077BBDC)
                {
                    switch (GAME_GetConnectError())
                    {
                    case 0:
                        gnLaunchMode_0077BBE4 = 2;
                        while (++gwRequestId_0070CD60 == 0)
                        {
                        }
                        WINMAIN_SendMcpJoinGame(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245, gwRequestId_0070CD60);
                        gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
                        gpLaunchFuncs_0077B09C->pfn0x34(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245, &gszEmptyAssertText, 0);
                        break;
                    case 30:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1411), sub_0043DAF0_OnConnect);
                        break;
                    case 31:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1412), sub_0043DAF0_OnConnect);
                        break;
                    case 32:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnLaunchMode_0077BBE4 = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1414), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;
        }

        int bUpdated = 0;
        unsigned long dwElapsed = GetTickCount() - s_dwTimer_0077BDC0;
        if (dwElapsed >= 15000)
        {
            s_dwTimer_0077BDC0 += dwElapsed;
            bUpdated = 1;
            gpLaunchFuncs_0077B09C->pfn0x30();
            const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
            if (!(wFlags & 8) || !(wFlags & 4))
            {
                int bEnable = 0;
                if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
                    bEnable = 1;
                CHATDLG_EnableConnection(bEnable);
            }
        }
        if (gnLaunchMode_0077BBE4 == 3)
        {
            dwElapsed = GetTickCount() - s_dwTimer_0077BDBC;
            if (dwElapsed >= 15000)
            {
                s_dwTimer_0077BDBC += dwElapsed;
                bUpdated = 1;
// build: symbol ?CHARSEL_RequestGameList@* 0x00445020
                CHARSEL_RequestGameList();
            }
        }
        dwElapsed = GetTickCount() - s_dwTimer_0077BDB8;
        if (dwElapsed >= 1000)
        {
            s_dwTimer_0077BDB8 += dwElapsed;
            bUpdated = 1;
            CHATDLG_SendPendingText();
        }
        CHATDLG_FlushChatMessages();
        if (!bUpdated)
            return 0;
    }
    while (bPending);
    return 1;
}

// 0x0044A130
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghThread_007992A4)
    {
        gtThreadRecord_00798FB8 = *pRecord;
        unsigned long nThreadId;
        ghThread_007992A4 = CreateThread(0, 0, sub_0044A070_ThreadProc, 0, 0, &nThreadId);
    }
}

// 0x00449E10
int __stdcall CHATDLG_RequestCharLogon(int nA)
{
    return WINMAIN_SendMcpCharLogon(nA);
}

// 0x00449E30
void __stdcall sub_00449E30_SetValue(int nValue)
{
    gnValue_00799104 = nValue;
}

// 0x00449E50
void __stdcall sub_00449E50_SetValue(int nValue)
{
    gnValue_00798F7C = nValue;
}

// 0x00442810
int __cdecl CHATDLG_SendChatBuffer()
{
    if (gszChatBuffer_0077AE40[0] == '/')
    {
        sub_004423B0_RunCommand(gszChatBuffer_0077AE40);
    }
    else
    {
        if (!gpLaunchFuncs_0077B09C->pfn0x68())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return 1;
        }
        gpLaunchFuncs_0077B09C->pfn0x14(gszChatBuffer_0077AE40);
        COMCALLBACK_PrintOwnLine(gszChatBuffer_0077AE40);
    }
    sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, 0);
    const int nFirst = D2Win_10055(gpChatTextBox_0077BD8C);
    const int nCount = sub_004FB910_GetLineCount(gpChatTextBox_0077BD8C);
    if (nCount > nFirst)
        D2Win_10053(gpChatTextBox_0077BD8C, nCount - nFirst);
    return 1;
}

// 0x00442B20
int __fastcall CHATDLG_IsCharOverLimit(const unsigned char* pChar)
{
    unsigned char nChar = *pChar;
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    const int nLimit = ((wFlags >> 8) & 0x1F) / 5 + 1;
    if (wFlags & 4)
    {
        if (nChar - '3' > nLimit || nChar < '3')
            return 1;
        return 0;
    }
    return nChar - '0' > nLimit;
}

// 0x00443600
int __stdcall CHATDLG_IsPrintableChar(int nA, int nB, const char* pChar)
{
    const char nChar = *pChar;
    if (nChar >= 0x20 && nChar < 0x80)
        return 1;
    return 0;
}

// 0x00443840
int __stdcall CHATDLG_CheckStartAdvResult(int nUnused)
{
    int nOut;
    if (gpLaunchFuncs_0077B09C->pfn0x8C(&nOut))
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00446810
char* __cdecl CHATDLG_StrChr(const char* szString, int nChar)
{
    return strchr(szString, nChar);
}

// 0x00446A90
void __stdcall CHATDLG_RemoveTableString(Unicode* pText)
{
    D2_ASSERT(sub_00526800(pText) < 500, 0x300);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nPatternLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_FindSubstring(pText, pPattern);
    while (pFound && pFound[nPatternLength].wChar)
    {
        memmove(pFound, &pFound[nPatternLength + 1], (sub_00526800(pFound) - nPatternLength) * sizeof(Unicode));
        pFound = sub_00526940_FindSubstring(pText, pPattern);
    }
}

// 0x00447700
int __fastcall CHATDLG_OnChannelDoesNotExist(int nA, int nB, const char* szText, int nLength)
{
    gpLaunchFuncs_0077B09C->pfn0x1C(nLength, 1, 0);
    CHATDLG_RefreshChatScreen();
    return 1;
}

// 0x00449330
int __fastcall CHATDLG_OnShowUser(int nA, int nB, const char* szText, int nLength)
{
    sub_00449050_AddEntry(szText, nLength, nA);
    return 1;
}

// 0x004497F0
void __fastcall CHATDLG_MixChar(char* pChar, int nBits, unsigned int* pPool)
{
    *pChar = (char)toupper(*pChar);
    if (*pChar <= '7')
    {
        *pChar ^= *pPool & 7;
        *pPool >>= 3;
    }
    else if (*pChar < 'A')
    {
        *pChar ^= nBits & 1;
    }
}

// 0x00449BF0
void __stdcall CHATDLG_SetMcpResult(int nValue)
{
    gnValue_0079929C = nValue;
}

// 0x00449C20
void __stdcall CHATDLG_SetCharCreateReceived(int nValue)
{
    gnValue_007992E8 = nValue;
}

// 0x00449C40
void __stdcall CHATDLG_SetCharLogonReceived(int nValue)
{
    gnValue_007992E0 = nValue;
}

// 0x00449C60
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue)
{
    gnValue_00799298 = nValue;
}

// 0x00449C80
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue)
{
    gnValue_007992F0 = nValue;
}

// 0x00449C90
void __stdcall sub_00449C90_SetValue(int nValue)
{
    gnValue_00799100 = nValue;
}

// 0x00449CC0
void __stdcall sub_00449CC0_SetValue(int nValue)
{
    gnValue_007992A0 = nValue;
}

// 0x00449CD0
int __stdcall CHATDLG_GetMcpTexts(char* szText1, char* szText2)
{
    strcpy(szText1, gszText_00799294);
    strcpy(szText2, gszText_00798F60);
    return gnResult_00798F58;
}

// 0x00449D10
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2)
{
    strcpy(gszText_00799294, szText1);
    strcpy(gszText_00798F60, szText2);
    gnResult_00798F58 = nResult;
}

// 0x00449D90
void __stdcall sub_00449D90_SetValue(int nValue)
{
    gnValue_007992A8 = nValue;
}

// 0x00449DB0
void __stdcall sub_00449DB0_SetValue(int nValue)
{
    gnValue_00798F5C = nValue;
}

// 0x00449DD0
void __stdcall sub_00449DD0_SetValue(int nValue)
{
    gnValue_00798F84 = nValue;
}

// 0x00449DF0
int __stdcall CHATDLG_RequestCharCreate(int nA, int nB, int nC)
{
    return WINMAIN_SendMcpCharCreate(nA, nB, nC);
}

#include "gen/data/Source/D2Multi/Src/ChatDlg.inc"
