#include "D2Multi.h"

#include "D2FogTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2LevelTxt.h"

#include "D2StormTypes.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"

#include "D2Win32Types.h"

static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand); // 0x00442180

struct D2WinButtonStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CharSaveHeaderStrc;

struct D2CharSaveFileStrc;

struct D2ConfigStrc;

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

extern D2WinControlInitStrc gatControlTemplates[]; // 0x00708D10

D2WinControlStrc* gapChatButtons[11]; // 0x0077AD78

extern D2WinControlStrc* gapChatDlgControls[17]; // 0x0077B058

extern D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C

extern D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064

extern D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068

extern D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C

extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074

D2ConfigStrc* gpCharInfo;                                                                  // 0x0077BBD8

int gbGemToggle; // 0x0077BBEC

D2CelFileStrc* gpChatCellFile; // 0x0077BBFC

D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

D2WinControlStrc* gpGemButton; // 0x0077BC48

D2WinControlStrc* gpChatEdit; // 0x0077BD94

extern D2CelFileStrc* gpChatBackground; // 0x0077BC04

extern D2CelFileStrc* gpWaitingRoomBkgdCelFile; // 0x0077BC08

extern D2CelFileStrc* gpPopUpLargest2CelFile; // 0x0077BC0C

extern D2CelFileStrc* gpMediumButtonBlank2CelFile; // 0x0077BC10

extern D2CelFileStrc* gpBnetCursorOHandCelFile; // 0x0077BC14

extern D2CelFileStrc* gpCursorLRotateCelFile; // 0x0077BC18

extern D2CelFileStrc* gpScrollBarCelFile; // 0x0077BC1C

extern D2CelFileStrc* gpBnetJoinGameScrollBarsCelFile; // 0x0077BC20

extern D2CelFileStrc* gpChatLeftButtonsCelFile; // 0x0077BC28

extern D2CelFileStrc* gpChatLeftButtons1CelFile; // 0x0077BC2C

extern D2CelFileStrc* gpChatLeftButtons2CelFile; // 0x0077BC30

extern D2CelFileStrc* gpChatRightButtonsCelFile; // 0x0077BC34

extern D2CelFileStrc* gpChatRightTopButtonsCelFile; // 0x0077BC38

extern D2CelFileStrc* gpChatArrowsCelFile; // 0x0077BC3C

extern D2CelFileStrc* gpJoinGameBckgCelFile; // 0x0077BC50

extern D2CelFileStrc* gpBlankBckg2CelFile; // 0x0077BC54

extern D2CelFileStrc* gpGemButtonCelFile; // 0x0077BC58

extern D2CelFileStrc* gpGameButtonBlankCelFile; // 0x0077BC5C

extern D2CelFileStrc* gpJoinGameClickBoxCelFile; // 0x0077BC60

extern D2CelFileStrc* gpGreyLevelBoxCelFile; // 0x0077BC64

extern D2CelFileStrc* gpRadioButtonCelFile; // 0x0077BC68

extern D2CelFileStrc* gpRadioButtonGreyCelFile; // 0x0077BC6C

extern D2CelFileStrc* gpBnetPopUpOkCelFile; // 0x0077BC70

extern D2CelFileStrc* gpBnetCancelButtonBlankCelFileA; // 0x0077BC74

extern D2CelFileStrc* gpOverallTabCelFile; // 0x0077BC78

extern D2CelFileStrc* gpAmazonTabCelFile; // 0x0077BC7C

extern D2CelFileStrc* gpSorceressTabCelFile; // 0x0077BC80

extern D2CelFileStrc* gpNecromancerTabCelFile; // 0x0077BC84

extern D2CelFileStrc* gpPaladinTabCelFile; // 0x0077BC88

extern D2CelFileStrc* gpBarbarianTabCelFile; // 0x0077BC8C

extern D2CelFileStrc* gpDruidTabCelFile; // 0x0077BC90

extern D2CelFileStrc* gpAssassinTabCelFile; // 0x0077BC94

extern D2CelFileStrc* gpSquelchAuraCelFile; // 0x0077BCB8

extern D2CelFileStrc* gpSelectAuraCelFile; // 0x0077BCBC

extern D2CelFileStrc* gpNumberArrowsCelFileA; // 0x0077BCC0

extern D2CelFileStrc* gpNumberArrowsCelFileB; // 0x0077BCC4

extern D2CelFileStrc* gpNumberArrowsCelFileC; // 0x0077BCC8

extern D2CelFileStrc* gpNumberArrowsCelFileD; // 0x0077BCCC

extern D2CelFileStrc* gpNumberGreyArrowsCelFile; // 0x0077BCD0

extern D2CelFileStrc* gpCreateJoinBckgCelFile; // 0x0077BCD4

extern D2CelFileStrc* gpOkayButtonCelFile; // 0x0077BCD8

extern D2CelFileStrc* gpCreateGameBckgCelFile; // 0x0077BD0C

extern D2CelFileStrc* gpCreateGameButtonCelFile; // 0x0077BD10

extern D2CelFileStrc* gpBnetWideButtonBlankCelFile; // 0x0077BD18

extern D2CelFileStrc* gpBnetCancelButtonBlankCelFileB; // 0x0077BD2C

extern D2CelFileStrc* gpYesNoButtonBlankCelFile; // 0x0077BD30

extern D2CelFileStrc* gpLadderChoiceExpCelFile; // 0x0077BD34

extern D2CelFileStrc* gpHardcoreLadderBckgCelFile; // 0x0077BD38

extern D2CelFileStrc* gpPlayerProfileBckgCelFileA; // 0x0077BD3C

extern D2CelFileStrc* gpPlayerProfileBckgCelFileB; // 0x0077BD40

extern D2CelFileStrc* gpHelpBckgCelFile; // 0x0077BD44

extern D2CelFileStrc* gpD2LogoBlackBnetCelFile; // 0x0077BD48

extern D2CelFileStrc* gpD2LogoBnetCelFile; // 0x0077BD4C

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

char gaszHistory[10][0x100]; // 0x0077B1D8

int gnHistoryCount; // 0x0077BD50

extern int gbShowJoinLeave; // 0x0077BD54

unsigned char gab_0077BD64[16]; // 0x0077BD64

unsigned char gab_0077BD74[16]; // 0x0077BD74

D2WinControlStrc* gpChatTextBox; // 0x0077BD8C

extern char gszLastWhisperer[]; // 0x0077B0D0

D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern unsigned char gnSelectModeA; // 0x0070CD62

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

D2WinControlStrc* gpCreateScreenButton; // 0x0077B070

D2WinControlStrc* gpJoinScreenButton; // 0x0077B078

D2WinControlStrc* gbSelectActive; // 0x0077BD00

int gnColor; // 0x0077AD74

extern int gnSelectLine; // 0x0070CD68

extern int gnSelectLinePrev; // 0x0070CD64

int gnSelection;                                                                                   // 0x0077BBF4

D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10

D2WinControlStrc* gpChatControl_0077B060; // 0x0077B060

D2WinControlStrc* gpChatUpButtonA; // 0x0077B084

D2WinControlStrc* gpChatDownButtonA; // 0x0077B088

D2WinControlStrc* gpChatUpButtonB; // 0x0077B08C

D2WinControlStrc* gpChatDownButtonB; // 0x0077B090

int gbChatSetup; // 0x0077BBF8

struct D2LaunchRecord3Strc;

struct D2LaunchThreadRecordStrc;

struct D2LaunchNameNodeStrc;


extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

void __cdecl CHATDLG_RefreshChatScreen(); // 0x0043FBD0

int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0

int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0

int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380

int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50

void* __stdcall COMCALLBACK_AddChannelUser(const char* szText, int nLength, int nA); // 0x00449050

unsigned long __stdcall sub_0044A070_ThreadProc(void* pParameter); // 0x0044A070

extern char gKey_0070CD54; // 0x0070CD54

char gszSelectName[16];                                                                            // 0x0077B040

extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C

extern char gKey_0077B0A8; // 0x0077B0A8

unsigned short gwSavedRequestId;                                                                   // 0x0077BBDC

int gnChatLaunchMode;                                                                                  // 0x0077BBE4

extern int gbCheck; // 0x0077BD58

extern int gbSelectActive_0077BD00; // 0x0077BD00

static int gbDone;                                                                                 // 0x0077BDA0

extern int gnValue_00798F5C; // 0x00798F5C

extern int gnValue_00798F7C; // 0x00798F7C

extern int gnValue_00798F84; // 0x00798F84

extern D2LaunchThreadRecordStrc gtThreadRecord; // 0x00798FB8

extern int gnValue_00799100; // 0x00799100

extern int gnValue_00799104; // 0x00799104

extern int gnValue_00799298; // 0x00799298

extern int gnValue_0079929C; // 0x0079929C

extern int gnValue_007992A0; // 0x007992A0

void* ghThread;                                                                                    // 0x007992A4

extern int gnValue_007992A8; // 0x007992A8

extern int gnValue_007992E0; // 0x007992E0

extern int gnValue_007992E8; // 0x007992E8

extern int gnValue_007992F0; // 0x007992F0

D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98

void __fastcall sub_004423B0_RunCommand(char* szText); // 0x004423B0

void __fastcall COMCALLBACK_PrintOwnLine(const char* szText); // 0x004481F0

int __fastcall sub_004FB910_GetLineCount(D2WinControlStrc* pTextBox); // 0x004FB910

D2WinButtonStrc* gapClassButtons[8]; // 0x0077BC98

static int gbExpansionClasses; // 0x0070CD70

extern char gszChatBuffer[0x200]; // 0x0077AE40

int gnGlobal_0077AD70;                                                                                      // 0x0077AD70

extern int gnSelectIdA; // 0x0070CD7C

extern unsigned char gnSelectModeB; // 0x0070CD63

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

D2LaunchNameNodeStrc* gpNameList; // 0x0077BDB4

void __cdecl COMCALLBACK_UpdateNameListText(); // 0x0043F730

D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C

int gpWaitText; // 0x0077BD9C

D2LaunchCallback gpfnLaunchCallback; // 0x0077BDA4

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

extern D2MultiChannelUserStrc* gpSelectedChannelUser;                                                   // 0x00798F48

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

extern D2WinControlInitStrc gatChatControlInits[]; // 0x0070CE50

unsigned long gdwConnectTime;                                                                      // 0x0077BBF0

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* pButton, int nValue); // 0x00500B20

extern "C" int __cdecl rand();

D2WinControlStrc* gapControls[32]; // 0x0077ADA8

int gnControlCount; // 0x0077BBE8

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

extern "C" const char* const gaszClassNames[];                                                     // 0x006D5524

static D2CriticalSectionStrc gtChatLock; // 0x0077AE28

static D2ChatMessageStrc* gpChatQueueHead; // 0x0077BDAC

static D2ChatMessageStrc* gpChatQueueTail; // 0x0077BDB0

void __cdecl CHATDLG_OpenStandardLadder(); // 0x004408B0

void __cdecl CHATDLG_OpenHardcoreLadder(); // 0x00440980

void __cdecl CHATDLG_OpenExpansionLadder(); // 0x00440A50

void __cdecl CHATDLG_OpenExpansionHardcoreLadder(); // 0x00440B30

unsigned long gdwSelectTime; // 0x0077BD5C

void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0

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

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect);                                                // 0x004F97B0

void __stdcall CHATDLG_EnableConnection(int bEnable);                                                            // 0x004413E0

void __cdecl CHATDLG_FlushChatMessages();                                                                   // 0x0043E3A0

void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply);                                        // 0x00442B90

void __cdecl CHATDLG_SendPendingText();                                                                           // 0x00442E00

void __fastcall sub_00442EB0_HandleOther(D2LaunchReplyStrc* pReply);                                        // 0x00442EB0

void __cdecl CHATDLG_DestroyJoinControls();                                                                          // 0x00443130

int __cdecl COMCALLBACK_PumpMessages();                                                                            // 0x00447A10

void* __cdecl GAME_GetMcpGameServerIP();                                                                               // 0x00449BC0

unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0

void* __cdecl GAME_GetMcpReply();                                                                               // 0x00449D50

void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60

int __cdecl GAME_GetMcpGameHash();                                                                                 // 0x00449DE0

unsigned short gwOtherRequestId;                                                                   // 0x0077BBE0

static int gnLoopValueOut_0077BC14; // 0x0077BC14

extern int gnLoopValueIn_0077BC18;                                                                          // 0x0077BC18

extern int gnFlag_0077BD60; // 0x0077BD60

struct D2StartupInfoAStrc;

struct D2ProcessInformationStrc;

struct D2StartupInfoAStrc
{
    unsigned long cb;
    char* lpReserved;
    char* lpDesktop;
    char* lpTitle;
    unsigned long dwX;
    unsigned long dwY;
    unsigned long dwXSize;
    unsigned long dwYSize;
    unsigned long dwXCountChars;
    unsigned long dwYCountChars;
    unsigned long dwFillAttribute;
    unsigned long dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};

struct D2ProcessInformationStrc
{
    void* hProcess;
    void* hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
};

extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494

extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd); // 0x006CC490

extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

int __fastcall sub_005259C0(void* pArg, int nArg); // 0x005259C0

void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40

void __cdecl CHATDLG_LoadFrontEndCels(); // 0x0043CC30

void __cdecl sub_0043DDD0_CreateCharControls(); // 0x0043DDD0

void __cdecl CHARSEL_ClearHistory(); // 0x0043F4D0

void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220

void __cdecl VIEW_SendMcpMotdRequest(); // 0x0044AA50

void __cdecl D2SOUND_InitWaveSlots(); // 0x00514DB0

void __fastcall D2SOUND_PreloadWave(const char* szFile); // 0x00514E10

int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80

void __fastcall D2SOUND_10034(int nArg); // 0x005148F0

int __cdecl CHATDLG_ConnectRealm(); // 0x00441A90

void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590

void __cdecl VIEW_SendMcpCancelGameCreate(); // 0x0044AA80

void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0

void __cdecl sub_00515070(); // 0x00515070

void __cdecl COMCALLBACK_ClearChannel(); // 0x004495A0

void __stdcall D2Win_10146(); // 0x00505100

void __cdecl CHATDLG_FreeNameList(); // 0x0043F800

void __cdecl sub_0043D510_FreeCellFiles(); // 0x0043D510

void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB); // 0x005066C0

void __stdcall sub_005052B0(void* pObject, int nValue); // 0x005052B0

void __fastcall CHATDLG_SetPlayerName(void* pArg); // 0x00440D10

void __fastcall sub_0043E4C0(void* pA, void* pB); // 0x0043E4C0

int __stdcall CHATDLG_OnTick(int nUnused); // 0x00441500

extern D2WinControlInitStrc gatChatControlInits_0070CE50[17]; // 0x0070CE50

extern D2WinControlInitStrc gtControlInit_0070D2A0; // 0x0070D2A0

extern D2WinControlInitStrc gtChatTextBoxInit; // 0x0070D240

extern D2WinControlInitStrc gtChatEditInit; // 0x0070D270

extern D2WinControlInitStrc gtControlInit_0070D210; // 0x0070D210

extern D2WinControlInitStrc gtGemButtonInit; // 0x0070D390

extern D2WinControlInitStrc gtControlInit_0070D2D0; // 0x0070D2D0

extern D2WinControlInitStrc gtBlankBckgImageInit; // 0x0070D300

extern D2WinControlInitStrc gtControlInit_0070D330; // 0x0070D330

extern D2WinControlInitStrc gtControlInit_0070D360; // 0x0070D360

D2WinControlStrc* gpQuitButton;                                                                       // 0x0077B080

void* gpLaunchContext; // 0x0077B0A4

struct _FILETIME;

void __stdcall sub_A09_Use(const char* szText);

int __cdecl CHATDLG_DestroyGameListControls(); // 0x00444E20

void __cdecl sub_00440FC0_CreateGatewayControls(); // 0x00440FC0

int __fastcall D2Win_10015(); // 0x004F8FE0

int __stdcall D2Win_10005(int nResolution); // 0x004F90A0

int __fastcall CHATDLG_RunChat(D2ConfigStrc* pInfo); // 0x00441B70

int __fastcall D2Win_10016(); // 0x004FA550

extern D2WinControlInitStrc gtWaitInit; // 0x0070D3C0

extern D2WinControlStrc* gpWaitText_0077BD9C; // 0x0077BD9C

static int gdwGlobal_0077BBF8; // 0x0077BBF8

D2WinControlStrc* gpNamesButton; // 0x0077BD08

char gszText_0077B1D0[8]; // 0x0077B1D0

char gszText_0077B0B4[28]; // 0x0077B0B4

D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050

D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40

static D2ChatMessageStrc* CHATDLG_PopChatMessage();

static void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage);

static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand);

static void CHATDLG_PushHistory(const char* szText);

static void __stdcall CHATDLG_GetArgument(int nSize, char* szDest, const char* szText);

struct D2WinEditBoxStrc;

struct D2LaunchGameRecStrc;

struct D2GameDetailsStrc;

const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30

int __stdcall CHARSEL_JoinByName(int nArg); // 0x004439F0

void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId); // 0x00442DD0

extern D2LaunchGameRecStrc gaNewGames[]; // 0x0077BDC8

extern D2WinControlStrc* gpJoinName; // 0x00798BD4

extern unsigned long gdwGameListLastClickTick; // 0x00798CEC

struct D2GameDetailsStrc
{
    char unk0x00[0x0C];
    unsigned int dwElapsed;
    unsigned char nLevel;
    unsigned char nLevelDiff;
    unsigned char nMaxPlayers;
    char unk0x13;
    int nPlayers;
    char unk0x18[0x14];
    char szDescription[0x20];
    unsigned short wClass[16];
    unsigned short wLevel[16];
    char szNames[16][16];
};

extern "C" const char gszEmptyString_006CC837[]; // 0x006CC837

D2WinControlStrc* gpGameInfoText; // 0x00798BC4

struct D2ModuleInterfaceStrc;

struct D2CelFileStrc;

extern D2ModuleInterfaceStrc gtInterface; // 0x0070CD14

const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00

void* __cdecl sub_0044DA90(); // 0x0044DA90

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMsg;
    unsigned int wParam;
    int lParam;
};

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

int __cdecl GAME_GetWaitHandle(); // 0x00449AC0

int __cdecl GAME_IsMcpCharLogonReceived(); // 0x00449C30

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40

extern D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

extern void* gpInstance; // 0x0077AD68

void __cdecl sub_00515110_Nop(); // 0x00515110

void __cdecl sub_00515EC0_Nop(); // 0x00515EC0

void __cdecl sub_00515ED0_Nop(); // 0x00515ED0

void __cdecl sub_0042B9D0_Nop(); // 0x0042B9D0

void __cdecl sub_00650EA0_Nop(); // 0x00650EA0

extern D2CelFileStrc* gpCellFile_0077BC24; // 0x0077BC24

int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3); // 0x0043DBA0

int __stdcall sub_0043DBC0_OnWaitTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043DBC0

int __stdcall sub_0043DBF0_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043DBF0

struct D2CompositeUnitStrc;

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0

void __cdecl sub_0043DCE0_FreeChatCellFile(); // 0x0043DCE0

struct Character;

struct Character { signed char value; };

enum { FIRST_PRINTABLE = 32, AFTER_PRINTABLE = 128 };

void __fastcall sub_00442A70_SetFlagBits12(unsigned int* pFlags, int nValue); // 0x00442A70

int __fastcall sub_00442A80_IsNightmareOpen(unsigned int nFlags); // 0x00442A80

int __fastcall sub_00442AB0_IsHellOpen(unsigned int nFlags); // 0x00442AB0

int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x00443540

int __stdcall sub_004435D0(void* unused1,void* unused2,const Character* text); // 0x004435D0

extern int gdwGlobal_00798CC4;                                                                                     // 0x00798CC4

extern D2WinControlStrc* gpNormalRadio;                                                                       // 0x00798C4C

extern D2WinControlStrc* gpNightmareRadio;                                                                       // 0x00798C50

extern D2WinControlStrc* gpHellRadio;                                                                       // 0x00798C54

extern int gnDiffSelect;                                                                                  // 0x00798CD0

extern char gszPendingEntryName[16];                                                                                  // 0x00798CD4

extern int gnPendingValueA;                                                                               // 0x00798CE4

extern int gnPendingValueB;                                                                               // 0x00798CE8

int __cdecl WINMAIN_PollMcpConnection();                                                               // 0x00449B70

void __cdecl CHATDLG_DestroyCreateControls();                                                                // 0x00443220

void __cdecl CHATDLG_DestroyProfileControls();                                                                                // 0x00443E10

void __fastcall CHATDLG_SelectEntry(const char* szName, int nValueA, int nValueB);                    // 0x0043EC60

int __stdcall sub_00443870_SetCancel(int nArg); // 0x00443870

int __stdcall sub_00443880_PollMcp(int nArg); // 0x00443880

int __stdcall sub_004438C0_OnCancel(int nArg); // 0x004438C0

int __stdcall sub_00443C20_SelectNormal(int nArg); // 0x00443C20

int __stdcall sub_00443C70_SelectNightmare(int nArg); // 0x00443C70

int __stdcall sub_00443CC0_SelectHell(int nArg); // 0x00443CC0

int __stdcall sub_00443F70_OnRefresh(int nArg); // 0x00443F70

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

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0

int __stdcall sub_0043D9A0(int nArg);                                                                       // 0x0043D9A0

int __stdcall sub_0043DBC0(int nArg);                                                                       // 0x0043DBC0

int __stdcall sub_0043DBF0(int nArg);                                                                       // 0x0043DBF0

void __cdecl sub_00443630_UpdateCreateButton();                                                                                // 0x00443630

int __stdcall CHATDLG_RequestCharLogon(const char* szName);                                                    // 0x00449E10

void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord);                                 // 0x0044A130

int __fastcall sub_0044A400_SendLogin(D2LaunchLoginStrc* pLogin, unsigned short wRequestId);                // 0x0044A400

int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId);                              // 0x0044A610

void __stdcall sub_006BC780(void* pConnection);                                                             // 0x006BC780

extern "C" const char gszPassword[];                                                               // 0x006D423C

extern int gnRequestId_0070CD60;                                                                            // 0x0070CD60

extern int gnPendingId;                                                                            // 0x0070EBD8

extern D2WinControlInitStrc gtControlInit_0070E860;                                                         // 0x0070E860

extern D2WinControlInitStrc gtControlInit_0070E890;                                                         // 0x0070E890

extern D2WinControlInitStrc gtControlInit_0070E8C0;                                                         // 0x0070E8C0

extern D2WinControlInitStrc gtControlInit_0070E8F0;                                                         // 0x0070E8F0

extern D2WinControlInitStrc gtControlInit_0070E9B0;                                                         // 0x0070E9B0

extern D2LaunchReplyEntryStrc gatReplyEntries[];                                                    // 0x0077BDC9

char gszPendingText[264];                                                                          // 0x00798AB8

extern D2WinControlStrc* gpControl_00798BC0;                                                                // 0x00798BC0

D2WinControlStrc* gpJoinGameBckgImage;                                                                       // 0x00798BC8

D2WinControlStrc* gpControl_00798BD0;                                                                       // 0x00798BD0

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

D2WinControlStrc* gpLevelDiffUpButton;                                                                       // 0x00798C1C

D2WinControlStrc* gpLevelDiffDownButton;                                                                       // 0x00798C20

extern D2WinControlStrc* gpLevelDiffGreyArrows;                                                                // 0x00798C24

extern D2WinControlStrc* gpControl_00798C2C;                                                                // 0x00798C2C

extern D2WinControlStrc* gpCreatePassword;                                                                // 0x00798C30

extern D2WinControlStrc* gpCreateDesc;                                                                // 0x00798C34

extern D2WinControlStrc* gpMaxPlayerControl;                                                                // 0x00798C38

extern D2WinControlStrc* gpLevelDiffEdit;                                                                // 0x00798C3C

extern D2WinControlStrc* gpLevelDiffCheck;                                                                 // 0x00798C40

extern D2WinControlStrc* gpLevelDiffBoxImage;                                                                // 0x00798C44

extern D2WinControlStrc* gpNormalLabel;                                                                // 0x00798C58

extern D2WinControlStrc* gpNightmareLabel;                                                                // 0x00798C5C

extern D2WinControlStrc* gpHellLabel;                                                                // 0x00798C60

D2WinControlStrc* gpProfileViewBckg;                                                                       // 0x00798C64

D2WinControlStrc* gpControl_00798C68;                                                                       // 0x00798C68

D2WinControlStrc* gpControl_00798C6C;                                                                       // 0x00798C6C

D2WinControlStrc* gpControl_00798C70;                                                                       // 0x00798C70

extern D2WinControlStrc* gpControl_00798C74;                                                                // 0x00798C74

D2WinControlStrc* gpProfileEditBckg;                                                                       // 0x00798C78

D2WinControlStrc* gpControl_00798C7C;                                                                       // 0x00798C7C

extern D2WinControlStrc* gpSubmitEditA;                                                            // 0x00798C80

extern D2WinControlStrc* gpSubmitEditB;                                                            // 0x00798C84

extern D2WinControlStrc* gpSubmitEditC;                                                            // 0x00798C88

D2WinControlStrc* gpRefreshButton;                                                                       // 0x00798C8C

D2WinControlStrc* gpControl_00798C90;                                                                       // 0x00798C90

D2WinControlStrc* gpControl_00798C94;                                                                       // 0x00798C94

D2WinControlStrc* gpControl_00798C98;                                                                       // 0x00798C98

D2WinControlStrc* gpControl_00798C9C;                                                                       // 0x00798C9C

extern D2WinControlStrc* gpSubmitButton;                                                                // 0x00798CA0

extern D2WinControlStrc* gpSelectButton;                                                                // 0x00798CA4

D2WinControlStrc* gpControl_00798CA8;                                                                       // 0x00798CA8

int gnSubmitMode;                                                                                  // 0x00798CAC

extern D2WinControlStrc* gpControl_00798CB0;                                                                // 0x00798CB0

extern D2WinControlStrc* gpControl_00798CB4;                                                                // 0x00798CB4

extern D2WinControlStrc* gpControl_00798CB8;                                                                // 0x00798CB8

extern D2WinControlStrc* gpHelpBckgImage;                                                                // 0x00798CBC

extern int gnValue_00798CC0;                                                                                // 0x00798CC0

extern int gnChannelUserCount;                                                                         // 0x00798F40

int gnChannelScroll;                                                                               // 0x00798F44

extern unsigned short gwMcpReplyRequestId;                                                                 // 0x00798F80

extern void* gpMcpConnection;                                                                         // 0x00798FB4

extern char gabMcpReply[];                                                                               // 0x00799108

extern void* ghConnectEvent;                                                                       // 0x007992EC

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
int __fastcall CHATDLG_WriteSaveHeader(const char* szName)
{
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwWritten;

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = FOG_CreateFileA(szPath, 0x40000000, 0, 0, 2, 0x8000000, 0);
    if (!hFile)
        return 0;

    gtCharSaveHeader.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&gtCharSaveHeader, 0x14F);
    FOG_WriteFile(hFile, &gtCharSaveHeader, 0x14F, &dwWritten, 0);
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

// 0x0043CBE0
D2ModuleInterfaceStrc* __fastcall sub_0043CBE0_Init(void* hInstance)
{
    gpInstance = hInstance;
    return &gtInterface;
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0043CC00
const char* __fastcall sub_0043CC00_StrChr(const char* szString, char nChar, int bReverse)
{
    if (bReverse)
        return SStrChrR(szString, nChar);
    return SStrChr(szString, nChar);
}

// 0x0043CC20
int __fastcall sub_0043CC20_TestBit2(int nValue)
{
    return nValue & 4;
}

// 0x0043CC30
void __cdecl CHATDLG_LoadFrontEndCels()
{
    char szPath[0x104];

    sprintf(szPath, "%s\\UI\\FrontEnd\\PopUpLargest2", gszDataGlobal);
    gpPopUpLargest2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FrontEnd\\MediumButtonBlank2", gszDataGlobal);
    gpMediumButtonBlank2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\bnet", gszDataGlobal);
    gpChatBackground = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\waitingroombkgd", gszDataGlobal);
    gpWaitingRoomBkgdCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpBnetCursorOHandCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\lrotate", gszDataGlobal);
    gpCursorLRotateCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\scrollbar", gszDataGlobal);
    gpScrollBarCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpBnetJoinGameScrollBarsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons", gszDataGlobal);
    gpChatLeftButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons1", gszDataGlobal);
    gpChatLeftButtons1CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons2", gszDataGlobal);
    gpChatLeftButtons2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrightbuttons", gszDataGlobal);
    gpChatRightButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrighttopbuttons", gszDataGlobal);
    gpChatRightTopButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatarrows", gszDataGlobal);
    gpChatArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingamebckg", gszDataGlobal);
    gpJoinGameBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GameButtonBlank", gszDataGlobal);
    gpGameButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingameclickbox", gszDataGlobal);
    gpJoinGameClickBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileD = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numbergreyarrows", gszDataGlobal);
    gpNumberGreyArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GreyLevelBox", gszDataGlobal);
    gpGreyLevelBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\createjoinbckg", gszDataGlobal);
    gpCreateJoinBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\okaybutton", gszDataGlobal);
    gpOkayButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebckg", gszDataGlobal);
    gpCreateGameBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebutton", gszDataGlobal);
    gpCreateGameButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\widebuttonblank", gszDataGlobal);
    gpBnetWideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpBnetCancelButtonBlankCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\yesnobuttonblank", gszDataGlobal);
    gpYesNoButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBlackBnet", gszDataGlobal);
    gpD2LogoBlackBnetCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBnet", gszDataGlobal);
    gpD2LogoBnetCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\blankbckg2", gszDataGlobal);
    gpBlankBckg2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\gembutton", gszDataGlobal);
    gpGemButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\LadderChoiceEXP", gszDataGlobal);
    gpLadderChoiceExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HardcoreLadderBckg", gszDataGlobal);
    gpHardcoreLadderBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpPlayerProfileBckgCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpPlayerProfileBckgCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HelpBckg", gszDataGlobal);
    gpHelpBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobutton", gszDataGlobal);
    gpRadioButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobuttonGrey", gszDataGlobal);
    gpRadioButtonGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\PopUpOK", gszDataGlobal);
    gpBnetPopUpOkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpBnetCancelButtonBlankCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\overalltab", gszDataGlobal);
    gpOverallTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\amazontab", gszDataGlobal);
    gpAmazonTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\sorceresstab", gszDataGlobal);
    gpSorceressTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\necromancertab", gszDataGlobal);
    gpNecromancerTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\paladintab", gszDataGlobal);
    gpPaladinTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\barbariantab", gszDataGlobal);
    gpBarbarianTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\druidtab", gszDataGlobal);
    gpDruidTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\assassintab", gszDataGlobal);
    gpAssassinTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SquelchAura", gszDataGlobal);
    gpSquelchAuraCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SelectAura", gszDataGlobal);
    gpSelectAuraCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sub_00504D30(gpSquelchAuraCelFile, gpSelectAuraCelFile);
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
// build: symbol ?gwRequestId@* 0x0070CD60
    while (++gwRequestId == 0)
    {
    }
    gpfnLaunchCallback(nArg);
    return 1;
}

// 0x0043D9E0
int __stdcall CHATDLG_ScrollPageUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-10);
    return 1;
}

// 0x0043DA00
int __stdcall sub_0043DA00_ScrollPageDown(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(10);
    return 1;
}

// 0x0043DA20
int __stdcall sub_0043DA20_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-1);
    return 1;
}

// 0x0043DA30
int __stdcall sub_0043DA30_ScrollForward(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(1);
    return 1;
}

// 0x0043DA50
static int __stdcall CHATDLG_ReadRegValueHKLM(const char* szSubKey, const char* szValueName, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    void* hKey;
    unsigned long dwType;
    *pcbData = 0;
    if (RegOpenKeyExA((void*)0x80000002, szSubKey, 0, 0x20019, &hKey))
    {
        return 0;
    }
    *pcbData = nSize;
    if (RegQueryValueExA(hKey, szValueName, 0, &dwType, pData, pcbData))
    {
        RegCloseKey(hKey);
        return 0;
    }
    return RegCloseKey(hKey) == 0;
}

// 0x0043DAD0
int __fastcall sub_0043DAD0_SetMainState(int bSet)
{
    sub_004F9740_SetControlState(gpControlMain_0077BC4C, bSet);
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

// 0x0043E180
static inline void CHATDLG_UnixTimeToFileTime(unsigned int nTime, _FILETIME* pFileTime)
{
    const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
    pFileTime->dwLowDateTime = (unsigned long)nFileTime;
    pFileTime->dwHighDateTime = (unsigned long)(nFileTime >> 32);
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

// 0x0043E230
void __cdecl CHATDLG_InitChatLock()
{
    InitializeCriticalSection(&gtChatLock);
}

// 0x0043E240
void __cdecl CHATDLG_DeleteChatLock()
{
    DeleteCriticalSection(&gtChatLock);
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

// 0x0043E2E0
static inline void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage)
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

// 0x0043E310
static void CHATDLG_PostChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = CHATDLG_CreateChatMessage(szText, nColor, bClear);
    if (!pMessage)
    {
        return;
    }
    EnterCriticalSection(&gtChatLock);
    if (gpChatQueueHead)
    {
        gpChatQueueTail->pNext = pMessage;
        gpChatQueueTail = pMessage;
    }
    else
    {
        gpChatQueueHead = pMessage;
        gpChatQueueTail = pMessage;
    }
    LeaveCriticalSection(&gtChatLock);
}

// 0x0043E370
D2ChatMessageStrc* __cdecl CHATDLG_PopChatMessage()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock);
    if (gpChatQueueHead)
    {
        pMessage = gpChatQueueHead;
        gpChatQueueHead = gpChatQueueHead->pNext;
    }
    LeaveCriticalSection(&gtChatLock);
    return pMessage;
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
            sub_004FB6A0_ClearText(gpChatTextBox);
        }
        if (pMessage->szText)
        {
            CHATDLG_AddTextLines(gpChatTextBox, 0, pMessage->szText, pMessage->nColor);
        }
        CHATDLG_FreeChatMessage(pMessage);
        D2Win_10053(gpChatTextBox, 0);
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
        EnterCriticalSection(&gtChatLock);
        if (gpChatQueueHead)
            gpChatQueueTail->pNext = pMessage;
        else
            gpChatQueueHead = pMessage;
        gpChatQueueTail = pMessage;
        LeaveCriticalSection(&gtChatLock);
    }
    return 1;
}

// 0x0043E5F0
int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor)
{
    if (gpChatTextBox)
    {
        sub_004FC9B0_SetText(gpChatTextBox, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E610
int __fastcall CHATDLG_PrintText(Unicode* pText, int nColor)
{
    if (gpChatTextBox)
    {
        sub_004FC9B0_SetText(gpChatTextBox, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E630
int __fastcall CHATDLG_ShowChannelText(Unicode* pText)
{
    if (gpControl_0077BD98)
    {
        sub_004FB6A0_ClearText(gpControl_0077BD98);
        sub_004FC9B0_SetText(gpControl_0077BD98, pText, 3, 0, 0);
    }

    return 1;
}

int __fastcall sub_M110_Emit_0043E180(unsigned int nTime, _FILETIME* pFileTime)
{
    CHATDLG_UnixTimeToFileTime(nTime, pFileTime);
    CHATDLG_FreeChatMessage((D2ChatMessageStrc*)pFileTime->dwHighDateTime);
    return 1;
}

void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0

D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC

// 0x0043E660
void __cdecl CHARSEL_UpdateOkEnabled()
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
    CONTROL_SetEnabled(gpChannelOkButton, bEnable);
}

// 0x0043E6C0
int __stdcall CHATDLG_OnCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gbDone = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x0043E6E0
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
            gbShowJoinLeave = !gbShowJoinLeave;
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            if (gbShowJoinLeave)
                strcpy(szMessage, "Player entering/leaving notifications are enabled.");
            else
                strcpy(szMessage, "Player entering/leaving notifications are disabled.");
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x200);
            if (gpChatTextBox)
                sub_004FC9B0_SetText(gpChatTextBox, (Unicode*)wszMessage, 3, 0, 1);
        }
        return 1;
    }
    return 0;
}

// 0x0043E9D0
static D2WinControlStrc* CHATDLG_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gatChatControlInits[nIndex]);
    gapControls[gnControlCount++] = pControl;
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

// 0x0043EB00
int __stdcall CHATDLG_OnWait(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?CHARSEL_DestroyPopupControls@* 0x0043EA20
    CHARSEL_DestroyPopupControls();
    return 1;
}

// 0x0043EB10
int __stdcall CHATDLG_RunCallback(int nArg)
{
    if (gpfnLaunchCallback)
        gpfnLaunchCallback(nArg);
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
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpCreateScreenButton, 1);
        CONTROL_SetEnabled(gpJoinScreenButton, 1);
    }
    if (gpCharInfo->szRealm0x361[0])
        CONTROL_SetEnabled(gpChatControl_0077B074, 1);
    else
        CONTROL_SetEnabled(gpChatControl_0077B074, gbChatSetup == 0);
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck == 0);
    return 1;
}

// 0x0043EC50
void __fastcall CHATDLG_SetLadderSelection(unsigned char nMode, int nId)
{
    gnSelectModeA = nMode;
    gnSelectIdA_0070CD7C = nId;
}

// 0x0043EC60
void __fastcall CHATDLG_SelectEntry(const char* szName, int nB, int nC)
{
    if (!gbSelectActive_0077BD00)
        return;
    SStrCopy(gszSelectName, szName, 0x7FFFFFFF);
    char nMode;
    if (nC)
        nMode = nB ? 0x13 : 0x1B;
    else
        nMode = nB ? 0 : 9;
    gnSelectModeA = nMode;
    gnSelectModeB_0070CD63 = nMode;
    gnSelectIdA_0070CD7C = -1;
// build: symbol ?gnSelectIdB@* 0x0070CD80
    gnSelectIdB = -1;
    WINMAIN_SendMcpCharRank(szName, nB, nC);
    gdwSelectTime = GetTickCount() + 1000;
}

void __fastcall sub_004423B0_RunCommand(char* szText)
{
    CHATDLG_PushHistory(szText);
// build: symbol ?gszCmdR@* 0x006D56D4
    if (CHATDLG_ReplyCommand(gszCmdR, szText))
        return;

// build: symbol ?gszCmdReply@* 0x006D56CC
    if (CHATDLG_ReplyCommand(gszCmdReply, szText))
        return;

// build: symbol ?gszCmdD2Notify@* 0x006D56C0
    if (CHATDLG_NotifyCommand(gszCmdD2Notify, szText))
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
        if (!SStrCmpI(&szName[1], gpCharInfo->szAccount, 0x7FFFFFFF))
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

// build: symbol ?gszCmdHomeSpace@* 0x006D5638
// build: symbol ?gszCmdDefaultChannel@* 0x006D5640
// build: symbol ?gszCmdHomeChannel@* 0x006D5654
    if (!CHATDLG_CompareCommand(szText, gszCmdHomeChannel) || !CHATDLG_CompareCommand(szText, gszCmdDefaultChannel) || !CHATDLG_CompareCommand(szText, gszCmdHomeSpace))
    {
        char szChannel[0x20];
        CHATDLG_GetArgument(0x20, szChannel, szText);
        SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
        return;
    }

// build: symbol ?gszCmdHome@* 0x006D5630
    if (!CHATDLG_CompareCommand(szText, gszCmdHome))
    {
        char szChannel[0x20];
        if (SRegLoadString("Diablo II", "Default Channel", 0, szChannel, 0x20))
            CHATDLG_JoinChannel(szChannel);
        return;
    }

    if (!gpLaunchFuncs->pfn0x68())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs->pfn0x14(szText);
}

// 0x0043ECE0
int __stdcall CHATDLG_ScrollLadderUp(int a)
{
    gnSelectIdA_0070CD7C -= gnGlobal_0077B0A0;
    unsigned char m = gnSelectModeB_0070CD63;
    gnSelectIdA_0070CD7C &= (gnSelectIdA_0070CD7C <= 0) - 1;
    gnSelectModeA = m;
    return 1;
}

// 0x0043ED10
int __stdcall CHATDLG_ScrollLadderDown(int nUnused)
{
    int nBase = gnGlobal_0077B0A0;
    int nOther = gnGlobal_0077AD70;
    int nCurrent = gnSelectIdA;
    int nDifference = nOther - nBase;
    int nCombined = nBase + nCurrent;
    if (nCombined < nDifference)
        nDifference = nCombined;
    gbGlobal_0070CD62 = gnSelectModeB;
    gnSelectIdA = nDifference;
    return 1;
}

// 0x0043ED50
void __cdecl CHATDLG_ClearLadderState()
{
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
    gapClassButtons[0] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6E);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 1);
    pControl = CHATDLG_CreateControl(0x76);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CE));
    gapClassButtons[1] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6F);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 0);
    D2Win_10044(CHATDLG_CreateControl(0x77), szText0);
    gapClassButtons[2] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x70);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 0);
    D2Win_10044(CHATDLG_CreateControl(0x78), szText1);
    gapClassButtons[3] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x71);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 0);
    D2Win_10044(CHATDLG_CreateControl(0x79), szText2);
    gapClassButtons[4] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x72);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7A), szText3);
    gapClassButtons[5] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x73);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7B), szText4);
    if (gbExpansionClasses)
    {
        gapClassButtons[6] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x74);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7C), szText5);
        gapClassButtons[7] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x75);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7D), szText6);
    }
}

// 0x0043F060
void __cdecl CHATDLG_ReleaseClassButtons()
{
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 0);
    if (gbExpansionClasses)
    {
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 0);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 0);
    }
}

// 0x0043F0E0
void __cdecl CHATDLG_ClearLadderList()
{
    sub_004FB6A0_ClearText(gbSelectActive);
    char szText[2];
    Unicode wszText[2] = { Unicode(0), Unicode(0) };
    sprintf(szText, gszDash_006CCA2C);
    sub_00526F20_ToUnicode(wszText, szText, 2);
    sub_004FCC40_AddLine(gbSelectActive, wszText, gnColor, 4, 0);
    D2Win_10053(gbSelectActive, 0);
    gnSelection = -2;
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
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 1);
    if (gnSelectModeA != 9 && gnSelectModeA != 0)
    {
        gnColor = 0x3E8;
        CHATDLG_ClearLadderList();
// build: symbol ?gnSelectFlag@* 0x0070CD6C
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(0, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F230
int __stdcall CHATDLG_OnAmazonLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 1);
    if (gnSelectModeA != 10 && gnSelectModeA != 1)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(1, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F290
int __stdcall CHATDLG_OnSorceressLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 1);
    if (gnSelectModeA != 11 && gnSelectModeA != 2)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(2, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F2F0
int __stdcall CHATDLG_OnNecromancerLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 1);
    if (gnSelectModeA != 12 && gnSelectModeA != 3)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(3, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F350
int __stdcall CHATDLG_OnPaladinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 1);
    if (gnSelectModeA != 13 && gnSelectModeA != 4)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(4, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F3B0
int __stdcall CHATDLG_OnBarbarianLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 1);
    if (gnSelectModeA != 14 && gnSelectModeA != 5)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(5, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F410
int __stdcall CHATDLG_OnDruidLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 1);
    if (gnSelectModeA != 15 && gnSelectModeA != 6)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(6, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F470
int __stdcall CHATDLG_OnAssassinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 1);
    if (gnSelectModeA != 16 && gnSelectModeA != 7)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(7, gnSelectModeA);
        gnSelectIdA_0070CD7C = 0;
    }
    return 1;
}

// 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory[1], gaszHistory[0], 0x900);
    strcpy(gaszHistory[0], szText);
    if (++gnHistoryCount >= 10)
        gnHistoryCount = 10;
}

void __fastcall sub_A09_Emit_004423B0(char* szText)
{
    CHATDLG_PushHistory(szText);
    if (!CHATDLG_CompareCommand(szText, "/ignore "))
        return;
    if (!CHATDLG_CompareCommand(szText, "/filtermsg "))
    {
        char szArg[0x104];
        CHATDLG_GetArgument(0x104, szArg, szText);
        sub_A09_Use(szArg);
    }
}

// 0x0043F580
int __stdcall CHATDLG_SetUserDataFlag(int nArg)
{
    gbFlag_0077ADA4 = 1;
    return 1;
}

// 0x0043F590
int __stdcall CHATDLG_GetUserDataReply(int nUnused)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = 8;
    tRecord.nValue1 = 0x28;
    tRecord.f_8 = 0xC8;
    if (gpLaunchFuncs->pfn0x7C(3, 1, &gKey_0077B0A8, &tRecord) || gbFlag_0077ADA4)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x0043F5F0
int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = nB;
    tRecord.nValue1 = nC;
    tRecord.f_8 = nD;
    return gpLaunchFuncs->pfn0x74(nA, 3, &gKey_0070CD54, &tRecord);
}

static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox)
        D2Win_10051((D2WinTextBoxStrc*)gpChatTextBox, pText, nColor, 0, 1);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043F630
int __stdcall CHATDLG_OnToggleButton(int nArg)
{
    if (gbGemToggle)
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpGemButton, 0);
        gbGemToggle = 0;
        PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D7), 0x0B);
    }
    else
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpGemButton, 2);
        gbGemToggle = 1;
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

// 0x0043F800
void __cdecl CHATDLG_FreeNameList()
{
    D2LaunchNameNodeStrc* pNode = gpNameList;
    while (pNode)
    {
        D2LaunchNameNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\ChatDlg.cpp", 0x1C01, 0);
        pNode = pNext;
    }
    gpNameList = 0;
}

// 0x0043F870
static void __stdcall CHATDLG_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
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
    gpfnLaunchCallback = pfnCallback;
    return 1;
}

// 0x0043F970
int __stdcall CHATDLG_ReleaseAndRecreate(int nArg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
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

        const Unicode* pEditText = sub_004FDD90_GetEditText(gpChatEdit);
        if (pEditText && gpSelectedChannelUser)
        {
            CHATDLG_CopyNamePrefix(gpSelectedChannelUser->szName, szName);
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
            sub_004FF5A0_SetEditText(gpChatEdit, wszText);
        }
        return 0;
    }

    if (*pKey == 9)
    {
        if (gnHistoryCount)
        {
// build: symbol ?gnHistoryIndex@* 0x0070CD74
            ++gnHistoryIndex;
            if (gnHistoryIndex >= gnHistoryCount)
            {
                gnHistoryIndex = 0;
            }
            sub_004FFE10_SetTextA(gpChatEdit, gaszHistory[gnHistoryIndex]);
        }
        return 0;
    }

    return 1;
}

// 0x0043FB50
int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHARSEL_ResetLaunchState();
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpWaitText_0077BD9C = CONTROL_Create(&gtWaitInit);
    D2Win_10044(gpWaitText_0077BD9C, pText);
    gpfnLaunchCallback = pfnDone;
    return 1;
}

// 0x0043FBD0
void __cdecl CHATDLG_RefreshChatScreen()
{
    CHARSEL_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnChatLaunchMode = 0;
}

// 0x0043FC20
void __cdecl CHATDLG_CreateChatScreen()
{
    char szText[0x100];

    if (!gbChatSetup)
        return;

    gbChatSetup = 0;
    sprintf(szText, "%s,%s", gpCharInfo->szRealm0x22D, gpCharInfo->szCharName);
    CHARSEL_ResetChatControls();

    if (gpChatCellFile)
        sub_005041B0_Destroy(gpChatCellFile, 1);
    gpChatCellFile = 0;

    BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    gapChatDlgControls[0] = CONTROL_Create(&gatControlTemplates[0x15C]);
    gpChatControl_0077B05C = CONTROL_Create(&gatControlTemplates[0x15D]);
    gpChatControl_0077B060 = CONTROL_Create(&gatControlTemplates[0x15E]);
    gpChatControl_0077B064 = CONTROL_Create(&gatControlTemplates[0x15F]);
    gpChatControl_0077B068 = CONTROL_Create(&gatControlTemplates[0x160]);
    gpChatControl_0077B06C = CONTROL_Create(&gatControlTemplates[0x161]);
    gpChatUpButtonA = CONTROL_Create(&gatControlTemplates[0x167]);
    gpChatDownButtonA = CONTROL_Create(&gatControlTemplates[0x168]);
    gpChatUpButtonB = CONTROL_Create(&gatControlTemplates[0x169]);
    gpChatDownButtonB = CONTROL_Create(&gatControlTemplates[0x16A]);
    CONTROL_SetEnabled(gpChatControl_0077B074, 1);

    gpChatEdit = CONTROL_Create(&gatControlTemplates[0x172]);
    sub_004FDAD0_SetKeyCallback(gpChatEdit, sub_0043F9B0_EditKey);
    sub_004FDB00_SetEnterCallback(gpChatEdit, sub_0043DB90);
    CONTROL_SetFocusedEditBox(gpChatEdit);
    sub_004FDD50_SetMaxLength(gpChatEdit, 0xC8);
    COMCALLBACK_RefreshChatButtons();

    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonA, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonA, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonB, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonB, 1);

    D2WinControlStrc** ppButton = gapChatButtons;
    for (int nX = 0x28; nX < 0x2BC; nX += 0x3C)
    {
        *ppButton++ = BUTTON_Create(nX, 0x24F, 0x3C, 0x64, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
    }

    gpChatControl_0077BC44 = CONTROL_Create(&gatControlTemplates[0x170]);
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    gpGemButton = CONTROL_Create(&gatControlTemplates[0x178]);
    if (gbGemToggle)
        sub_00500B20_SetValue(gpGemButton, 2);
}

static inline int LAUNCH_SetCallback_inl(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    gpfnLaunchCallback = pfnCallback;
    return 1;
}

// 0x0043FFA0
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37)
{
    gnChatLaunchMode = 2;
    CHATDLG_SetCallback(0, sub_0043DAF0_OnConnect);
    gpCharInfo->wJoinID = wValue;
    strcpy(gpCharInfo->szGameName, szText0x1F);
    strcpy(gpCharInfo->szText0x245, szText0x245);
    if (gpCharInfo->nByte22D)
    {
        if (sub_00449B30_QueryAddress())
        {
            gpCharInfo->dwGameType = 3;
            while (++gwRequestId == 0)
            {
            }
// build: symbol ?WINMAIN_SendMcpJoinGame@* 0x0044A4E0
            WINMAIN_SendMcpJoinGame(szText0x1F, szText0x245, gwRequestId);
            gwSavedRequestId = gwRequestId;
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
            return 1;
        }
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
        return 0;
    }
    gpCharInfo->dwGameType = 7;
    strcpy(gpCharInfo->szServerIP, szText0x37);
    gbDone = 1;
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
    sub_004FF5A0_SetEditText(gpChatEdit, 0);
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
    gpfnLaunchCallback = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
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
    gpfnLaunchCallback = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
    gdwConnectTime = GetTickCount();
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
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    CHARSEL_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
}

// 0x004402A0
int __cdecl CHATDLG_FindDashLine()
{
    char szText[0x100];
    int nLine = sub_004FB950_GetFirstVisible(gbSelectActive);
    const int nCount = D2Win_10055(gbSelectActive);
    const int nEnd = (nLine + nCount < gnColor) ? nLine + nCount : gnColor;

    for (; nLine < nEnd; ++nLine)
    {
        const Unicode* pText = D2Win_10196(gbSelectActive, nLine, 0);
        sub_00526F70(szText, pText, 0x100);
        if (!strcmp(szText, "-"))
        {
            gnSelectIdA_0070CD7C = gnSelectLine = nLine / 16 * 16;
            return 1;
        }
    }
    return 0;
}

// 0x00440350
int __stdcall CHATDLG_OnIdle(SMSGHANDLER_PARAMS* pMsg)
{
    if (GetTickCount() > gdwSelectTime && gbSelectActive
        && (CHATDLG_FindDashLine() || gnSelectFlag)
        && (gnSelection != gnSelectIdA_0070CD7C || gnSelectLine != gnSelectLinePrev))
    {
        gnSelectModeB_0070CD63 = gnSelectModeA;
        gnSelectIdB = gnSelectIdA_0070CD7C;
        VIEW_SendMcpLadderRequest(gnSelectModeA, gnSelectLine);
        gdwSelectTime = GetTickCount() + 1000;
        gnSelection = gnSelectIdB;
        gnSelectLinePrev = gnSelectLine;
    }
    return 1;
}

static inline void ResetClassSelectState(int bExpansionClasses)
{
    gbExpansionClasses = bExpansionClasses;
    gapClassButtons[0] = 0;
    gapClassButtons[1] = 0;
    gapClassButtons[2] = 0;
    gapClassButtons[3] = 0;
    gapClassButtons[4] = 0;
    gapClassButtons[5] = 0;
    gapClassButtons[6] = 0;
    gapClassButtons[7] = 0;
    gbSelectActive = 0;
    gnColor = 1000;
}

// 0x004403E0
int __stdcall CHATDLG_OnResetCallback(int nArg)
{
    CHARSEL_ResetLaunchState();
    return 1;
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
    gbSelectActive = CHATDLG_CreateControl(0x6C);
    sub_004FC720(gbSelectActive, 0x10);
    sub_004FBC20(gbSelectActive, 5);
    sub_004FB740(gbSelectActive, 0, -6);
    sub_004FBC80(gbSelectActive, 0, 0);
    sub_004FBCD0(gbSelectActive, 0, 0x10);
    sub_004FBC80(gbSelectActive, 1, 0x23);
    sub_004FBC80(gbSelectActive, 2, 0xA5);
    sub_004FBC80(gbSelectActive, 3, 0xC3);
    sub_004FBCD0(gbSelectActive, 3, 0x10);
    sub_004FBC80(gbSelectActive, 4, 0xDC);
    sub_004FBCD0(gbSelectActive, 4, 0x10);
    CHATDLG_ClearLadderList();
    pControl = CHATDLG_CreateControl(0x80);
    sub_004FD830(pControl);
    sub_004FDA50(pControl);
    gszSelectName[0] = 0;
}

// 0x004408B0
void __cdecl CHATDLG_OpenStandardLadder()
{
    if (gpCharInfo->nByte22D)
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
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440980
void __cdecl CHATDLG_OpenHardcoreLadder()
{
    if (gpCharInfo->nByte22D)
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
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440A50
void __cdecl CHATDLG_OpenExpansionLadder()
{
    if (gpCharInfo->nByte22D)
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
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnGlobal_0077B0A0 = 0x10;
    gnGlobal_0077AD70 = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440B30
void __cdecl CHATDLG_OpenExpansionHardcoreLadder()
{
    if (gpCharInfo->nByte22D)
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
    gnSelection = -2;
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
    gnSelectModeA = 9;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C40
int __stdcall CHATDLG_ShowExpansionLadder(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenExpansionLadder();
    gnSelectModeA = 0x1B;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00440C70
int __stdcall CHATDLG_ShowExpansionHardcoreLadder(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenExpansionHardcoreLadder();
    gnSelectModeA = 0x13;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

void __cdecl CHARSEL_DestroyPopupControls(); // 0x0043EA20

int gbFlag_0077ADA4; // 0x0077ADA4

D2LaunchRecord3Strc gtRecord_0077B0A8; // 0x0077B0A8

// 0x00440CA0
int __fastcall MAINMENUS_RequestProfile(int nA, int nB, int nC, int nD)
{
    gtRecord_0077B0A8.nValue0 = nB;
    gtRecord_0077B0A8.nValue1 = nC;
    gtRecord_0077B0A8.f_8 = nD;
// build: symbol ?gpLaunchFuncs@* 0x0077B09C
    gpLaunchFuncs->pfn0x78(nA, 3, 1, &gKey_0070CD54);
    gbFlag_0077ADA4 = 0;
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), CHATDLG_SetUserDataFlag);
    sub_004FA590_RunLoop(CHATDLG_GetUserDataReply);
    CHARSEL_DestroyPopupControls();
    return gbFlag_0077ADA4 == 0;
}

// 0x00440D10
void __fastcall CHATDLG_SetPlayerName(int nPlayerId, int nDataLength, const char* szName)
{
    D2LaunchNameNodeStrc* pNode;
    for (pNode = gpNameList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nPlayerId)
            break;
    }

    if (!pNode)
    {
        pNode = (D2LaunchNameNodeStrc*)FOG_Alloc(sizeof(D2LaunchNameNodeStrc), ".\\Src\\ChatDlg.cpp", 0x1BAE, 0);
        D2LaunchNameNodeStrc* pCur = gpNameList;
        pNode->nId = nPlayerId;
        if (!pCur || pCur->nId > nPlayerId)
        {
            pNode->pNext = pCur;
            gpNameList = pNode;
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

void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    CHATDLG_SaveDefaultChannel(szFirst);
    CHATDLG_SaveDefaultChannel(szSecond);
}

// 0x00440DB0
int __stdcall CHATDLG_OnQuitMessage(int nArg)
{
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
    gbDone = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00440DE0
int __stdcall CHATDLG_OpenAdUrl(int nUnused)
{
    const char* szURL = gpLaunchFuncs->pfn0xA4(gpLaunchContext);
    if (!szURL)
    {
        return 1;
    }
    char szCommand[0x800] = { 0 };
    int bOk = 0;
    SetForegroundWindow(GetDesktopWindow());
    char szKey[0x400];
    sprintf(szKey, "%s\\.html", "SOFTWARE\\Classes");
    unsigned long cbData;
    if (CHATDLG_ReadRegValueHKLM(szKey, 0, (unsigned char*)szCommand, 0x400, &cbData))
    {
        char szOpenKey[0x400];
        sprintf(szOpenKey, "%s\\%s\\shell\\open\\command", "SOFTWARE\\Classes", szCommand);
        char szPath[0x400] = { 0 };
        if (CHATDLG_ReadRegValueHKLM(szOpenKey, 0, (unsigned char*)szPath, 0x400, &cbData))
        {
            strcat(szPath, " ");
            strcat(szPath, szURL);
            D2StartupInfoAStrc si;
            D2ProcessInformationStrc pi;
            SMemZero(&si, sizeof(si));
            si.cb = sizeof(si);
            if (CreateProcessA(0, szPath, 0, 0, 0, 0x20, 0, 0, &si, &pi))
            {
                CloseHandle(pi.hThread);
                CloseHandle(pi.hProcess);
                bOk = 1;
            }
        }
    }
    if (!bOk)
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14DC), 0);
    }
    gpLaunchFuncs->pfn0x6C(gpLaunchContext, bOk == 0);
    return 1;
}

struct D2LaunchGameEntryStrc;

struct D2LaunchGameListStrc;

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80

void* __cdecl GAME_GetChannelName(); // 0x00446CF0

extern D2WinControlInitStrc gtCreateJoinBckgImageInit; // 0x0070D8D0

extern D2WinControlInitStrc gtChannelScreenTitleInit; // 0x0070D900

extern D2WinControlInitStrc gtControlInit_0070D930; // 0x0070D930

extern D2WinControlInitStrc gtControlInit_0070D960; // 0x0070D960

extern D2WinControlInitStrc gtChannelNameEditInit; // 0x0070D990

extern D2WinControlInitStrc gtChannelListInit; // 0x0070D9F0

extern D2WinControlInitStrc gtChannelOkButtonInit; // 0x0070DA20

extern D2WinControlInitStrc gtControlInit_0070E110; // 0x0070E110

extern D2WinControlStrc* gpControl_0077BCEC; // 0x0077BCEC

struct D2LaunchGameEntryStrc
{
    int nAddress;
    char unk0x04[0x10];
    char szName[1];
};

struct D2LaunchGameListStrc
{
    int nCount;
    char unk0x04[0x0C];
    D2LaunchGameEntryStrc tFirst;
};

D2WinControlStrc* gpCreateJoinBckgImage; // 0x0077BCDC

D2WinControlStrc* gpChannelScreenTitle; // 0x0077BCE0

D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4

D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8

D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0

D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4

D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// calling-convention shim (not game code)
int __fastcall sub_00442180_Shim(char* szText)
{
// build: symbol ?gszCmdR@* 0x006D56D4
    if (CHATDLG_ReplyCommand(szText, gszCmdR))
        return 1;
// build: symbol ?gszCmdReply@* 0x006D56CC
    if (CHATDLG_ReplyCommand(szText, gszCmdReply))
        return 1;
    return 0;
}

// build: context sub_004438E0_HasProgress
static inline int sub_004438E0_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0

// 0x00440FC0
void __cdecl sub_00440FC0_CreateGatewayControls()
{
    gpCreateJoinBckgImage = CONTROL_Create(&gtCreateJoinBckgImageInit);

    gpChannelScreenTitle = CONTROL_Create(&gtChannelScreenTitleInit);
    D2Win_10044(gpChannelScreenTitle, D2LANG_GetStringFromTblIndex(0x148D));

    gpControl_0077BCE4 = CONTROL_Create(&gtControlInit_0070D930);
    D2Win_10044(gpControl_0077BCE4, D2LANG_GetStringFromTblIndex(0x148E));

    gpControl_0077BCE8 = CONTROL_Create(&gtControlInit_0070D960);
    D2Win_10044(gpControl_0077BCE8, D2LANG_GetStringFromTblIndex(0x148F));

    gpControl_0077BCEC = CONTROL_Create(&gtChannelOkButtonInit);

    gpControl_0077BCF0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_0077BCF0);

    gpChannelNameEdit = CONTROL_Create(&gtChannelNameEditInit);
    sub_004FDD50_SetMaxLength(gpChannelNameEdit, 0x20);
    sub_004FDAD0_SetKeyCallback(gpChannelNameEdit, (int (__stdcall *)(D2WinControlStrc *,int,const char *))sub_0043DBA0_ClearSelection);
    sub_004FDB00_SetEnterCallback(gpChannelNameEdit, (int (__stdcall *)(int))CHATDLG_OnEditChange);

    gpChannelListBox = CONTROL_Create(&gtChannelListInit);

    const char* szList = gpLaunchFuncs->pfn0x20(gpCharInfo->aFlags1EF[0] & 0x20);

    if (gpCharInfo->szRealm0x381[0])
    {
        D2Win_10045(gpChannelListBox, gpCharInfo->szRealm0x381);
    }

    if (gpCharInfo->szRealm0x361[0] && strcmp(gpCharInfo->szRealm0x381, gpCharInfo->szRealm0x361))
    {
        D2Win_10045(gpChannelListBox, gpCharInfo->szRealm0x361);
    }

    while (*szList)
    {
        if (!gpCharInfo->szRealm0x361[0] || strcmp(szList, gpCharInfo->szRealm0x361))
        {
            D2Win_10045(gpChannelListBox, szList);
        }

        while (*szList)
        {
            ++szList;
        }
        ++szList;
    }

    sub_004FFE10_SetTextA(gpChannelNameEdit, (const char*)GAME_GetChannelName());
    CONTROL_SetFocusedEditBox(gpChannelNameEdit);
    D2Win_10082(gpChannelNameEdit);
    D2Win_10053(gpChannelListBox, 0);
// build: symbol ?CHARSEL_UpdateOkEnabled@* 0x0043E660
    CHARSEL_UpdateOkEnabled();
}

// 0x004411E0
void __fastcall CHATDLG_JoinChannel(const char* szText)
{
    gpLaunchFuncs->pfn0x1C((int)szText, 0, 0);
    CHARSEL_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnChatLaunchMode = 0;
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
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        if (gpControlMain_0077BC4C)
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
        return;
    }
    if (!gnChatLaunchMode && gpWaitText)
        CHARSEL_ResetLaunchState();
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        CONTROL_SetEnabled(gpCreateScreenButton, 1);
        CONTROL_SetEnabled(gpJoinScreenButton, 1);
    }
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck == 0);
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
}

// 0x004414C0
void __cdecl sub_004414C0_UpdateEnable()
{
    if (((gpCharInfo->wFlags1EF) & 8) && ((gpCharInfo->wFlags1EF) & 4))
    {
        return;
    }

    int bEnable = 0;
    if (gpCharInfo->nByte22D && !sub_00449B30_QueryAddress())
    {
        bEnable = 1;
    }

    CHATDLG_EnableConnection(bEnable);
}

// 0x00441A90
int __cdecl CHATDLG_ConnectRealm()
{
    if (!gpCharInfo->szRealm0x22D[0])
        return 1;
    if (!gpLaunchFuncs)
        return 0;
    if (!gpLaunchFuncs->pfn0x68())
        return 0;
    if (sub_00449B30_QueryAddress())
        return 1;
    gnFlag_0077BD60 = 0;
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), sub_0043D9A0);
    D2LaunchPayloadStrc* pPayload = gpLaunchFuncs->pfn0x44(gpCharInfo->szRealm0x22D, gszPassword);
    if (!pPayload)
        return 0;
    if (pPayload->nSize <= 8)
        return 0;
    CHATDLG_StartThread(&pPayload->tRecord);
    sub_004FA590_RunLoop(sub_0043DBC0);
// build: symbol ?CHARSEL_DestroyPopupControls@* 0x0043EA20
    CHARSEL_DestroyPopupControls();
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    if (gnFlag_0077BD60 || !sub_00449B30_QueryAddress() || GAME_GetConnectError())
    {
        CHARSEL_DestroyPopupControls();
        return 0;
    }
    CHATDLG_RequestCharLogon(gpCharInfo->szCharName);
    sub_004FA590_RunLoop(sub_0043DBF0);
    CHARSEL_DestroyPopupControls();
    return GAME_GetConnectError() == 0;
}

// 0x00442150
int __fastcall CHATDLG_StartChat(D2ConfigStrc* pInfo)
{
    gpCharInfo = pInfo;
    D2Win_10015();
    D2Win_10005(1);
    CHATDLG_RunChat(pInfo);
    D2Win_10016();
    return gbDone;
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
            if (!strlen(gszLastWhisperer))
            {
                Unicode wszMessage[0x100] = {};
// build: symbol ?gszNobodyToReply@* 0x006D561C
                sprintf(szMessage, gszNobodyToReply);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }

            char szPrefix[0x100];
// build: symbol ?gszCommandSpace@* 0x006D5618
            sprintf(szPrefix, gszCommandSpace, szCommand);
            char szCopy[0x100];
            const char* pMessage;
            if (!CONSOLE_FindSecondTokenInline(szText, szCopy, &pMessage))
            {
                Unicode wszMessage[0x100];
// build: symbol ?gszCorrectUsage@* 0x006D55F8
                sprintf(szMessage, gszCorrectUsage, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }
            if (!gpLaunchFuncs->pfn0x68())
            {
                CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }

// build: symbol ?gszReplyFormat@* 0x006D55EC
            sprintf(szMessage, gszReplyFormat, gszLastWhisperer, pMessage);
            gpLaunchFuncs->pfn0x14(szMessage);
            return 1;
        }
    }
    return 0;
}

// 0x00442350
int __stdcall CHATDLG_OpenLadderScreen(int nArg)
{
    CHARSEL_ResetLaunchState();
    CHATDLG_OpenHardcoreLadder();
    gnSelectModeA = 0;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00442370
int __stdcall CHATDLG_ReleaseAndCreate(int nArg)
{
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    CHARSEL_ResetLaunchState();
    sub_00440FC0_CreateGatewayControls();
    return 1;
}

// 0x00442810
int __cdecl CHATDLG_SendChatBuffer()
{
    if (gszChatBuffer[0] == '/')
    {
        sub_004423B0_RunCommand(gszChatBuffer);
    }
    else
    {
        if (!gpLaunchFuncs->pfn0x68())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return 1;
        }
        gpLaunchFuncs->pfn0x14(gszChatBuffer);
        COMCALLBACK_PrintOwnLine(gszChatBuffer);
    }
    sub_004FF5A0_SetEditText(gpChatEdit, 0);
    const int nFirst = D2Win_10055(gpChatTextBox);
    const int nCount = sub_004FB910_GetLineCount(gpChatTextBox);
    if (nCount > nFirst)
        D2Win_10053(gpChatTextBox, nCount - nFirst);
    return 1;
}

// 0x004428B0
int __stdcall CHATDLG_SendChat(int nArg)
{
    CHATDLG_SendChatBuffer();
    CHARSEL_DestroyPopupControls();
    return 1;
}

// 0x00442AE0
const char* __fastcall CHATDLG_SkipString(const char* szText)
{
    D2_ASSERT(szText, 0xAD);
    while (*szText != 0)
        szText += 1;
    return szText + 1;
}

// 0x00442B20
int __fastcall CHATDLG_IsCharOverLimit(const unsigned char* pChar)
{
    unsigned char nChar = *pChar;
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    const int nLimit = ((wFlags >> 8) & 0x1F) / 5 + 1;
    if (wFlags & 4)
    {
        if (nChar - '3' > nLimit || nChar < '3')
            return 1;
        return 0;
    }
    return nChar - '0' > nLimit;
}

// 0x00442B90
void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply)
{
    const int nCount = gnValue_00798CCC;
    for (int i = 0; i < nCount; ++i)
    {
        if (gatReplyEntries[i].f_32 == pReply->f_8)
            return;
    }
    gatReplyEntries[nCount].f_32 = pReply->f_8;
    gatReplyEntries[nCount].nValue = 0;
    gatReplyEntries[nCount].wValue = pReply->wValue;
    strcpy(gatReplyEntries[nCount].szName, pReply->szName);
    strcpy(gatReplyEntries[nCount].szDesc, pReply->szDesc);
    gnValue_00798CCC = nCount + 1;
}

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605
int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4); // 0x004FCD40
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
extern D2LaunchGameRecStrc gaGames[]; // 0x0078A440
extern D2WinControlStrc* gpGameText_00798BC4; // 0x00798BC4
D2WinControlStrc* gpGameList; // 0x00798BC0
int gnLastGameCount; // 0x00798CC8
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00442C20
void __cdecl CHARSEL_FillGameListControl()
{
    char szSel[0x100];
    char szNumber[0x10];

    if (!gpGameList)
        return;

    const Unicode* pSel = sub_004FBB30_GetText(gpGameList);
    int bHaveSel = 0;
    if (pSel)
    {
        sub_00526F70(szSel, pSel, 0x100);
        bHaveSel = 1;
    }

    int nTop = sub_004FB950_GetFirstVisible(gpGameList);
    sub_004FB6A0_ClearText(gpGameList);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    gnLastGameCount = gnValue_00798CCC;
    if (!gnLastGameCount)
        return;

    int bNoNumbers = !sub_00449B30_QueryAddress();
    memcpy(gaGames, gaNewGames, gnValue_00798CCC * sizeof(D2LaunchGameRecStrc));
    for (int i = 0; i < gnLastGameCount; ++i)
    {
        D2Win_10045(gpGameList, gaGames[i].szName);
        int nRow = sub_004FBD20_GetLastRow(gpGameList);
        if (!bNoNumbers)
        {
            _itoa(*(unsigned short*)gaGames[i].wValue0x31, szNumber, 10);
            D2Win_10057(gpGameList, szNumber, nRow, 1);
        }
    }

    if (bHaveSel)
    {
        for (int i = 0; i < gnLastGameCount; ++i)
        {
            if (!strcmp(szSel, gaGames[i].szName))
            {
                sub_004FB9D0_Select(gpGameList, i);
                break;
            }
        }
        D2Win_10053(gpGameList, nTop);
    }
    else
    {
        D2Win_10053(gpGameList, 0);
    }
}

// 0x00442DD0
void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId)
{
    strncpy(gszPendingText, szText, 0x100);
    gnPendingId = wRequestId;
}

// 0x00442E00
void __cdecl CHATDLG_SendPendingText()
{
    if (gnPendingId != -1)
    {
        WINMAIN_SendMcpGameInfoRequest(gszPendingText, gnPendingId);
        gwOtherRequestId = gnPendingId;
        gnPendingId = -1;
    }
}

// 0x00442E30
static void sub_00442E30_ShowGameInfo(int nIndex)
{
    if (!gpGameText_00798BC4)
        return;

    D2LaunchGameRecStrc* pGame = &gaNewGames[nIndex];
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (strlen(&pGame->szName[0x10]))
    {
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &pGame->szName[0x10]);
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &gszEmptyAssertText);
    }
    D2Win_10053(gpGameText_00798BC4, 0);
    if (pGame->szName)
    {
        sub_004FFE10_SetTextA(gpJoinName, pGame->szName);
        CONTROL_SetFocusedEditBox(0);
    }
}

int __stdcall sub_004450D0_OnGameListEvent(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gpGameList@* 0x00798BC0
    const int nSelection = sub_004FB990_GetSelection(gpGameList);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (nSelection != -1)
    {
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
// build: symbol ?gnGameListLastSelection@* 0x0070EBDC
            if (nSelection == gnGameListLastSelection && dwTick - gdwGameListLastClickTick <= 500)
            {
                CHARSEL_JoinByName(0);
                return 0;
            }
            gnGameListLastSelection = nSelection;
            gdwGameListLastClickTick = dwTick;
        }

        if (sub_00449B30_QueryAddress())
        {
            const Unicode* pText = sub_004FBB30_GetText(gpGameList);
            if (pText)
            {
                char szText[0x100];
                sub_00526F70(szText, pText, 0x100);
// build: symbol ?gwRequestId@* 0x0070CD60
                while (++gwRequestId == 0)
                {
                }
                CHATDLG_SetPendingText(szText, gwRequestId);
                sub_004FF5A0_SetEditText(gpJoinName, pText);
                CONTROL_SetFocusedEditBox(0);
            }
        }
        else
        {
            sub_00442E30_ShowGameInfo(nSelection);
        }
    }
    return 0;
}

// 0x00442EB0
void __fastcall sub_00442EB0_ShowGameDetails(D2GameDetailsStrc* pDetails)
{
    char szLine[0x100];

    if (!gpGameInfoText)
        return;

    sub_004FB6A0_ClearText(gpGameInfoText);
    if (strlen(pDetails->szDescription))
    {
        sub_004FCF80_SetTextA(gpGameInfoText, pDetails->szDescription);
        sub_004FCF80_SetTextA(gpGameInfoText, gszEmptyString_006CC837);
    }

    unsigned int nSecondsPerHour = 3600;
    unsigned int nSecondsPerMinute = 60;
    unsigned int dwElapsed = pDetails->dwElapsed;
    unsigned int nHours = dwElapsed / nSecondsPerHour;
    unsigned int nRest = dwElapsed % nSecondsPerHour;
    sprintf(szLine, "Elapsed Time: %d:%02d:%02d", nHours, nRest / 60, dwElapsed % nSecondsPerMinute);
    sub_004FCF80_SetTextA(gpGameInfoText, szLine);

    unsigned char nLevelDiff = pDetails->nLevelDiff;
    if (nLevelDiff < 100)
    {
        if (nLevelDiff)
        {
            int nDiff = nLevelDiff;
            int nLevel = pDetails->nLevel;
            int nMin = nLevel - nDiff;
            if (nMin <= 1)
                nMin = 1;
            int nMax = nDiff + nLevel;
            if (nMax >= 99)
                nMax = 99;
            sprintf(szLine, "Level %d to %d", nMin, nMax);
        }
        else
        {
            sprintf(szLine, "Level %d", pDetails->nLevel);
        }
        sub_004FCF80_SetTextA(gpGameInfoText, szLine);
    }

    if (pDetails->nMaxPlayers > 0 && pDetails->nMaxPlayers < 8)
    {
        sprintf(szLine, "Up to %d Players", pDetails->nMaxPlayers);
        sub_004FCF80_SetTextA(gpGameInfoText, szLine);
    }

    sub_004FCF80_SetTextA(gpGameInfoText, gszEmptyString_006CC837);

    for (int i = 0; i < pDetails->nPlayers; ++i)
    {
        if (pDetails->szNames[i][0])
        {
            sub_004FCF80_SetTextA(gpGameInfoText, pDetails->szNames[i]);
            switch (pDetails->wClass[i])
            {
            case 0:
                sprintf(szLine, "Level %d Amazon", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 1:
                sprintf(szLine, "Level %d Sorceress", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 2:
                sprintf(szLine, "Level %d Necromancer", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 3:
                sprintf(szLine, "Level %d Paladin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 4:
                sprintf(szLine, "Level %d Barbarian", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 5:
                sprintf(szLine, "Level %d Druid", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 6:
                sprintf(szLine, "Level %d Assassin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            default:
                sprintf(szLine, "Level %d", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            }
        }
    }

    D2Win_10053(gpGameInfoText, 0);
}

// 0x00443130
void __cdecl CHATDLG_DestroyJoinControls()
{
    sub_004F95C0_ControlDestroy(&gpJoinGameBckgImage);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD4);
    sub_004F95C0_ControlDestroy(&gpJoinPassword);
    sub_004F95C0_ControlDestroy(&gpControl_00798BC0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BC4);
    sub_004F95C0_ControlDestroy(&gpControl_00798BCC);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD0);
    sub_004F95C0_ControlDestroy(&gpJoinGameTitle);
    sub_004F95C0_ControlDestroy(&gpJoinNameLabel);
    sub_004F95C0_ControlDestroy(&gpJoinPasswordLabel);
    sub_004F95C0_ControlDestroy(&gpControl_00798BE8);
    sub_004FA450_SetActive(gpQuitButton);
}

// 0x00443220
void __cdecl CHATDLG_DestroyCreateControls()
{
    sub_004F95C0_ControlDestroy(&gpControl_00798BEC);
    sub_004F95C0_ControlDestroy(&gpControl_00798BF0);
    sub_004F95C0_ControlDestroy(&gpControl_00798BF4);
    sub_004F95C0_ControlDestroy(&gpCreatePasswordLabel);
    sub_004F95C0_ControlDestroy(&gpCreateDescLabel);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersLabel);
    sub_004F95C0_ControlDestroy(&gpLevelDiffLabel);
    sub_004F95C0_ControlDestroy(&gpControl_00798C08);
    sub_004F95C0_ControlDestroy(&gpControl_00798C2C);
    sub_004F95C0_ControlDestroy(&gpCreatePassword);
    sub_004F95C0_ControlDestroy(&gpCreateDesc);
    sub_004F95C0_ControlDestroy(&gpMaxPlayerControl);
    sub_004F95C0_ControlDestroy(&gpLevelDiffEdit);
    sub_004F95C0_ControlDestroy(&gpControl_00798C28);
    sub_004F95C0_ControlDestroy(&gpControl_00798C48);
    sub_004F95C0_ControlDestroy(&gpLevelDiffCheck);
    sub_004F95C0_ControlDestroy(&gpNormalRadio);
    sub_004F95C0_ControlDestroy(&gpNightmareRadio);
    sub_004F95C0_ControlDestroy(&gpHellRadio);
    sub_004F95C0_ControlDestroy(&gpNormalLabel);
    sub_004F95C0_ControlDestroy(&gpNightmareLabel);
    sub_004F95C0_ControlDestroy(&gpHellLabel);
    sub_004F95C0_ControlDestroy(&gpLevelDiffBoxImage);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersUpButton);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersDownButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffUpButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffDownButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffGreyArrows);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersBoxImage);
    sub_004F95C0_ControlDestroy(&gpControl_00798C10);
    sub_004FA450_SetActive(gpQuitButton);
    sub_0043D990();
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
    if (gpLaunchFuncs->pfn0x8C(&nOut))
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00443D50
void __cdecl CHATDLG_CreateProfileControls()
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
void __cdecl CHATDLG_DestroyProfileControls()
{
    if (gnSubmitMode)
    {
        if (gnSubmitMode == 1)
        {
            sub_004F95C0_ControlDestroy(&gpProfileViewBckg);
            sub_004F95C0_ControlDestroy(&gpControl_00798C68);
            sub_004F95C0_ControlDestroy(&gpControl_00798C6C);
            sub_004F95C0_ControlDestroy(&gpControl_00798C70);
            sub_004F95C0_ControlDestroy(&gpControl_00798C74);
        }
        else
        {
            sub_004F95C0_ControlDestroy(&gpProfileEditBckg);
            sub_004F95C0_ControlDestroy(&gpControl_00798C7C);
            sub_004F95C0_ControlDestroy(&gpSubmitEditA);
            sub_004F95C0_ControlDestroy(&gpSubmitEditB);
            sub_004F95C0_ControlDestroy(&gpSubmitEditC);
            sub_004F95C0_ControlDestroy(&gpRefreshButton);
        }
        gnSubmitMode = 0;
        sub_004F95C0_ControlDestroy(&gpControl_00798C90);
        sub_004F95C0_ControlDestroy(&gpControl_00798C94);
        sub_004F95C0_ControlDestroy(&gpControl_00798C98);
        sub_004F95C0_ControlDestroy(&gpControl_00798C9C);
        sub_004F95C0_ControlDestroy(&gpSubmitButton);
        sub_004F95C0_ControlDestroy(&gpSelectButton);
        sub_004F95C0_ControlDestroy(&gpControl_00798CA8);
    }
    sub_004FA450_SetActive(gpQuitButton);
    sub_0043D990();
}

// 0x00443EF0
int __stdcall sub_00443EF0_OnSelect(int nArg)
{
    CHATDLG_DestroyProfileControls();
    if (gnPendingValueB)
    {
        if (gnPendingValueA)
            CHATDLG_OpenExpansionHardcoreLadder();
        else
            CHATDLG_OpenExpansionLadder();
    }
    else
    {
        if (gnPendingValueA)
            CHATDLG_OpenHardcoreLadder();
        else
            CHATDLG_OpenStandardLadder();
    }
    CHATDLG_SelectEntry(gszPendingEntryName, gnPendingValueA, gnPendingValueB);
    return 1;
}

// 0x00443F50
void __fastcall CHATDLG_CopyName(char* szDest)
{
    SStrCopy(szDest, gszPendingEntryName, 0x7FFFFFFF);
}

// 0x00444E20
int __cdecl CHATDLG_DestroyGameListControls()
{
    sub_004F95C0_ControlDestroy(&gpHelpBckgImage);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB0);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB4);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB8);
    gnValue_00798CC0 = 0;
    sub_004FA450_SetActive(gpQuitButton);
    return 1;
}

// 0x00445550
int __stdcall CHATDLG_OnLevelRestrictToggle(int nArg)
{
    if (sub_00500960_IsPressed(gpLevelDiffCheck))
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 0);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 1);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 1);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 1);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 1);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 1);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x00446810
char* __cdecl CHATDLG_StrChr(const char* szString, int nChar)
{
    return strchr(szString, nChar);
}

// 0x00446820
const char* __fastcall CHATDLG_SkipNamePrefix(const char* szName)
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
void __fastcall CHATDLG_CopyNamePrefix(const char* szName, char* szOut)
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

// 0x00448BD0
void __fastcall CHATDLG_UpdateScroll(int nDelta)
{
    int bUp = 0;
    int bDown = 0;
    const int nOld = gnChannelScroll;
    if (gnChannelUserCount <= 11)
    {
        gnChannelScroll = 0;
    }
    else
    {
        gnChannelScroll = D2_MIN(D2_MAX(gnChannelScroll + nDelta, 0), gnChannelUserCount - 11);
        if (gnChannelScroll > 0)
            bUp = 1;
        if (gnChannelScroll < gnChannelUserCount - 11)
            bDown = 1;
    }
    if (gnChannelScroll != nOld)
// build: symbol ?COMCALLBACK_RefreshChannelList@* 0x00447BB0
        COMCALLBACK_RefreshChannelList();
    CONTROL_SetEnabled(gpChatUpButtonA, bUp);
    CONTROL_SetEnabled(gpChatDownButtonA, bDown);
    CONTROL_SetEnabled(gpChatUpButtonB, bUp);
    CONTROL_SetEnabled(gpChatDownButtonB, bDown);
}

// 0x00449330
int __fastcall CHATDLG_OnShowUser(int nA, int nB, const char* szText, int nLength)
{
    COMCALLBACK_AddChannelUser(szText, nLength, nA);
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

// 0x00449AD0
void __cdecl D2MCPClientCloseMCP()
{
    if (gpMcpConnection)
    {
        sub_006BC780(gpMcpConnection);
        gpMcpConnection = 0;
    }
    if (ghThread)
    {
        WaitForSingleObject(ghThread, 0xFFFFFFFF);
        CloseHandle(ghThread);
        ghThread = 0;
    }
    if (ghConnectEvent)
    {
        CloseHandle(ghConnectEvent);
        ghConnectEvent = 0;
    }
}

// 0x00449BD0
unsigned short __cdecl CHATDLG_GetRequestId()
{
    return gwMcpReplyRequestId;
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

// 0x00449D60
void __cdecl CHATDLG_ClearReply()
{
    memset(gabMcpReply, 0, 0x18C);
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

// 0x0044A130
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghThread)
    {
        gtThreadRecord = *pRecord;
        unsigned long nThreadId;
        ghThread = CreateThread(0, 0, sub_0044A070_ThreadProc, 0, 0, &nThreadId);
    }
}

#include "gen/data/Source/D2Multi/Src/ChatDlg.inc"
