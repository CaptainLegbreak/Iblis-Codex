#include "D2Multi.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2Win32Types.h"

void __stdcall sub_005052B0(void* pObject, int nValue); // 0x005052B0

void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB); // 0x005066C0


static void __cdecl CHATDLG_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo); // 0x0043DC50


void __cdecl CHARSEL_ClearHistory(); // 0x0043F4D0

int __cdecl CHATDLG_ConnectRealm(); // 0x00441A90

void __cdecl COMCALLBACK_ClearChannel(); // 0x004495A0

#define CREATE_CELL_FILE CHATDLG_CreateChatCellFile

void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0

void __fastcall D2SOUND_10034(int nArg); // 0x005148F0

int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80

void __cdecl D2SOUND_InitWaveSlots(); // 0x00514DB0

void __fastcall D2SOUND_PreloadWave(const char* szFile); // 0x00514E10

void __stdcall D2Win_10146(); // 0x00505100

void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220

void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40

void __cdecl VIEW_SendMcpCancelGameCreate(); // 0x0044AA80

void __cdecl VIEW_SendMcpMotdRequest(); // 0x0044AA50

D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050

extern D2WinControlInitStrc gatChatControlInits_0070CE50[17]; // 0x0070CE50

static int gdwGlobal_0077BBF8; // 0x0077BBF8

D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40

D2WinControlStrc* gpNamesButton; // 0x0077BD08

extern D2WinControlStrc* gpQuitButton; // 0x0077B080

char gszText_0077B0B4[28]; // 0x0077B0B4

char gszText_0077B1D0[8]; // 0x0077B1D0

extern D2WinControlInitStrc gtBlankBckgImageInit; // 0x0070D300

extern D2WinControlInitStrc gtChatEditInit; // 0x0070D270

extern D2WinControlInitStrc gtChatTextBoxInit; // 0x0070D240

extern D2WinControlInitStrc gtControlInit_0070D210; // 0x0070D210

extern D2WinControlInitStrc gtControlInit_0070D2A0; // 0x0070D2A0

extern D2WinControlInitStrc gtControlInit_0070D2D0; // 0x0070D2D0

extern D2WinControlInitStrc gtControlInit_0070D330; // 0x0070D330

extern D2WinControlInitStrc gtControlInit_0070D360; // 0x0070D360

extern D2WinControlInitStrc gtGemButtonInit; // 0x0070D390

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

void __cdecl sub_0043D510_FreeCellFiles(); // 0x0043D510

void __cdecl sub_0043DDD0_CreateCharControls(); // 0x0043DDD0

void __fastcall sub_0043E4C0(void* pA, void* pB); // 0x0043E4C0

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590

void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

void __cdecl sub_00515070(); // 0x00515070

int __fastcall sub_005259C0(void* pArg, int nArg); // 0x005259C0

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
extern D2WinControlInitStrc gatControlTemplates[]; // 0x00708D10
extern D2WinControlStrc* gapChatButtons[]; // 0x0077AD78
extern D2WinControlStrc* gapChatDlgControls[17]; // 0x0077B058
extern D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C
extern D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064
extern D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068
extern D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2LaunchCharInfoStrc* gpCharInfo;                                                                  // 0x0077BBD8
extern int gbGemToggle; // 0x0077BBEC
extern D2CelFileStrc* gpChatCellFile; // 0x0077BBFC
extern D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44
extern D2WinControlStrc* gpGemButton; // 0x0077BC48
extern D2WinControlStrc* gpChatEdit; // 0x0077BD94
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
extern char gaszHistory[10][0x100]; // 0x0077B1D8
extern int gnHistoryCount; // 0x0077BD50
extern int gbShowJoinLeave; // 0x0077BD54
extern D2WinControlStrc* gpChatTextBox; // 0x0077BD8C
extern char gszLastWhisperer[]; // 0x0077B0D0
extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C
extern unsigned char gnSelectModeA; // 0x0070CD62
extern int gnGlobal_0077B0A0;                                                                                      // 0x0077B0A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" int __cdecl strcmp(const char*, const char*);
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __cdecl CHATDLG_ResetControls(); // 0x0043EBA0
void __cdecl CHATDLG_CreateControls(); // 0x0043EB30
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
Unicode* __fastcall D2Win_10196(D2WinControlStrc* pTextBox, int nLineNum, int nColumnNum); // 0x004FBB90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __fastcall VIEW_SendMcpLadderRequest(unsigned char nArg1, unsigned short nArg2); // 0x0044AA10
extern D2WinControlStrc* gpCreateScreenButton; // 0x0077B070
extern D2WinControlStrc* gpJoinScreenButton; // 0x0077B078
extern D2WinControlStrc* gbSelectActive; // 0x0077BD00
extern int gnColor; // 0x0077AD74
extern int gnSelectLine; // 0x0070CD68
extern int gnSelectLinePrev; // 0x0070CD64
extern int gnSelection;                                                                                   // 0x0077BBF4
extern D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10
extern D2WinControlStrc* gpChatControl_0077B060; // 0x0077B060
extern D2WinControlStrc* gpChatUpButtonA; // 0x0077B084
extern D2WinControlStrc* gpChatDownButtonA; // 0x0077B088
extern D2WinControlStrc* gpChatUpButtonB; // 0x0077B08C
extern D2WinControlStrc* gpChatDownButtonB; // 0x0077B090
extern int gbChatSetup; // 0x0077BBF8
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
int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0
int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0
int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380
int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50
void* __stdcall COMCALLBACK_AddChannelUser(const char* szText, int nLength, int nA); // 0x00449050
unsigned long __stdcall sub_0044A070_ThreadProc(void* pParameter); // 0x0044A070
extern char gKey_0070CD54; // 0x0070CD54
extern char gszSelectName[16];                                                                            // 0x0077B040
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
extern char gKey_0077B0A8; // 0x0077B0A8
extern unsigned short gwSavedRequestId;                                                                   // 0x0077BBDC
extern int gnChatLaunchMode;                                                                                  // 0x0077BBE4
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
extern void* ghThread; // 0x007992A4
extern int gnValue_007992A8; // 0x007992A8
extern int gnValue_007992E0; // 0x007992E0
extern int gnValue_007992E8; // 0x007992E8
extern int gnValue_007992F0; // 0x007992F0
extern D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98
void __fastcall sub_004423B0_RunCommand(char* szText); // 0x004423B0
void __fastcall COMCALLBACK_PrintOwnLine(const char* szText); // 0x004481F0
int __fastcall sub_004FB910_GetLineCount(D2WinControlStrc* pTextBox); // 0x004FB910
extern D2WinButtonStrc* gapClassButtons[8]; // 0x0077BC98
static int gbExpansionClasses; // 0x0070CD70
extern char gszChatBuffer[0x200]; // 0x0077AE40
extern int gnGlobal_0077AD70;                                                                                      // 0x0077AD70
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
extern D2LaunchNameNodeStrc* gpNameList; // 0x0077BDB4
void __cdecl COMCALLBACK_UpdateNameListText(); // 0x0043F730
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern int gpWaitText; // 0x0077BD9C
extern D2LaunchCallback gpfnLaunchCallback; // 0x0077BDA4
extern int gnResult_00798F58; // 0x00798F58
extern char gszText_00798F60[28]; // 0x00798F60
extern char gszText_00799294[4]; // 0x00799294
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
static int __stdcall CHATDLG_FindHashedWord(char* szText, unsigned int nHash, int nLength); // 0x0043E860
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
extern unsigned long gdwConnectTime;                                                                      // 0x0077BBF0
struct UnicodeChar : Unicode
{
    UnicodeChar();
};
extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* pButton, int nValue); // 0x00500B20
extern "C" int __cdecl rand();
extern D2WinControlStrc* gapControls[32]; // 0x0077ADA8
extern int gnControlCount; // 0x0077BBE8
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
extern unsigned long gdwSelectTime; // 0x0077BD5C
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
void* __cdecl GAME_GetMcpGameServerIP();                                                                               // 0x00449BC0
unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0
void* __cdecl GAME_GetMcpReply();                                                                               // 0x00449D50
void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60
int __cdecl GAME_GetMcpGameHash();                                                                                 // 0x00449DE0
extern unsigned short gwOtherRequestId;                                                                   // 0x0077BBE0
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
int __fastcall CHATDLG_WriteSaveHeader(const char* szName); // 0x0043C6B0
int __fastcall CHATDLG_UpdateSaveFlags(const char* szName); // 0x0043CAA0
void __cdecl CHATDLG_LoadFrontEndCels(); // 0x0043CC30
int __stdcall CHATDLG_OnRealmConnectCancel(SMSGHANDLER_PARAMS* pMsg); // 0x0043D9A0
int __stdcall CHATDLG_NextRequestCallback(int nArg); // 0x0043D9B0
int __stdcall CHATDLG_ScrollPageUp(SMSGHANDLER_PARAMS* pMsg); // 0x0043D9E0
int __stdcall sub_0043DAF0_OnConnect(int nArg); // 0x0043DAF0
int __stdcall sub_0043DB90(int nArg); // 0x0043DB90
// build: symbol ?CHATDLG_PopChatMessage@* 0x0043E370
static D2ChatMessageStrc* CHATDLG_PopChatMessage()
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
void __cdecl CHATDLG_FlushChatMessages(); // 0x0043E3A0
int __fastcall CHATDLG_OnChatTime(unsigned int nTime, const char* szText); // 0x0043E4C0
struct D2WinControlStrc;
int __cdecl CHATDLG_PostClearMessage(); // 0x0043E570
int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor); // 0x0043E5F0
int __fastcall CHATDLG_PrintText(Unicode* pText, int nColor); // 0x0043E610
int __fastcall CHATDLG_ShowChannelText(Unicode* pText); // 0x0043E630
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
// build: symbol ?CHATDLG_NotifyCommand@* 0x0043E780
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
// build: symbol ?CHATDLG_FindHashedWord@* 0x0043E860
static int __stdcall CHATDLG_FindHashedWord(char* szText, unsigned int nHash, int nLength)
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
int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper); // 0x004428D0
// build: symbol ?CHATDLG_CreateControl@* 0x0043E9D0
static D2WinControlStrc* CHATDLG_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gatChatControlInits[nIndex]);
    gapControls[gnControlCount++] = pControl;
    return pControl;
}
void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText); // 0x0043EA70
int __stdcall CHATDLG_RunCallback(int nArg); // 0x0043EB10
void __cdecl CHATDLG_CreateControls(); // 0x0043EB30
int __cdecl CHATDLG_ResetControls(); // 0x0043EBA0
void __fastcall CHATDLG_SelectEntry(const char* szName, int nB, int nC); // 0x0043EC60
// build: symbol ?CHATDLG_PushHistory@* 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory[1], gaszHistory[0], 0x900);
    strcpy(gaszHistory[0], szText);
    if (++gnHistoryCount >= 10)
        gnHistoryCount = 10;
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
// build: symbol ?CHATDLG_ReplyCommand@* 0x00442180
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
        if (!SStrCmpI(&szName[1], gpCharInfo->szText0x8D, 0x7FFFFFFF))
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
int __stdcall CHATDLG_ScrollLadderUp(int a); // 0x0043ECE0
int __stdcall CHATDLG_ScrollLadderDown(int nUnused); // 0x0043ED10
void __cdecl CHATDLG_CreateClassButtons(); // 0x0043ED60
void __cdecl CHATDLG_ReleaseClassButtons(); // 0x0043F060
void __cdecl CHATDLG_ClearLadderList(); // 0x0043F0E0
int __stdcall CHATDLG_OnOverallLadderButton(D2WinMsgStrc* pMsg); // 0x0043F1D0
int __stdcall CHATDLG_OnAmazonLadderButton(D2WinMsgStrc* pMsg); // 0x0043F230
int __stdcall CHATDLG_OnSorceressLadderButton(D2WinMsgStrc* pMsg); // 0x0043F290
int __stdcall CHATDLG_OnNecromancerLadderButton(D2WinMsgStrc* pMsg); // 0x0043F2F0
int __stdcall CHATDLG_OnPaladinLadderButton(D2WinMsgStrc* pMsg); // 0x0043F350
int __stdcall CHATDLG_OnBarbarianLadderButton(D2WinMsgStrc* pMsg); // 0x0043F3B0
int __stdcall CHATDLG_OnDruidLadderButton(D2WinMsgStrc* pMsg); // 0x0043F410
int __stdcall CHATDLG_OnAssassinLadderButton(D2WinMsgStrc* pMsg); // 0x0043F470
int __stdcall CHATDLG_GetUserDataReply(int nUnused); // 0x0043F590
void __cdecl CHATDLG_FreeNameList(); // 0x0043F800
static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox)
        D2Win_10051((D2WinTextBoxStrc*)gpChatTextBox, pText, nColor, 0, 1);
}
int __stdcall CHATDLG_OnToggleButton(int nArg); // 0x0043F630
// build: symbol ?CHATDLG_SaveDefaultChannel@* 0x0043F8A0
static inline void CHATDLG_SaveDefaultChannel(const char* szChannel)
{
    SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
}
int __stdcall CHATDLG_SetCallback(int nUnused, D2LaunchCallback pfnCallback); // 0x0043F930
void __cdecl CHATDLG_CreateChatScreen(); // 0x0043FC20
int __stdcall CHATDLG_ChatEditKeyCallback(void* pArg, int nCursor, const char* pKey); // 0x0043F9B0
int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD); // 0x0043F5F0
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0
int __stdcall CHATDLG_OnEditChange(SMSGHANDLER_PARAMS* pMsg); // 0x00440110
int __stdcall CHATDLG_OnClearEdit(SMSGHANDLER_PARAMS* pMsg); // 0x00440120
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
int __stdcall CHATDLG_OnReset(SMSGHANDLER_PARAMS* pMsg); // 0x00440240
int __stdcall CHATDLG_OnBack(SMSGHANDLER_PARAMS* pMsg); // 0x00440260
int __cdecl CHATDLG_FindDashLine(); // 0x004402A0
int __stdcall CHATDLG_OnIdle(SMSGHANDLER_PARAMS* pMsg); // 0x00440350
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
int __stdcall CHATDLG_OnResetCallback(int nArg); // 0x004403E0
void __fastcall CHATDLG_FillLadderList(int nStart, int nCount, int nNameLength, unsigned char nMode, D2LadderEntryStrc* pEntries); // 0x004403F0
void __cdecl CHATDLG_CreateClassScreen(); // 0x004406F0
void __cdecl CHATDLG_OpenStandardLadder(); // 0x004408B0
void __cdecl CHATDLG_OpenHardcoreLadder(); // 0x00440980
void __cdecl CHATDLG_OpenExpansionLadder(); // 0x00440A50
void __cdecl CHATDLG_OpenExpansionHardcoreLadder(); // 0x00440B30
int __stdcall CHATDLG_ShowStandardLadder(int nArg); // 0x00440C10
int __stdcall CHATDLG_ShowExpansionLadder(int nArg); // 0x00440C40
int __stdcall CHATDLG_ShowExpansionHardcoreLadder(int nArg); // 0x00440C70
void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    CHATDLG_SaveDefaultChannel(szFirst);
    CHATDLG_SaveDefaultChannel(szSecond);
}
int __stdcall CHATDLG_OnQuitMessage(int nArg); // 0x00440DB0
void __stdcall CHATDLG_EnableConnection(int bEnable); // 0x004413E0
void __fastcall CHATDLG_SetPlayerName(void* pArg); // 0x00440D10
int __stdcall CHATDLG_OnTick(int nUnused); // 0x00441500
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord); // 0x0044A130
int __stdcall CHATDLG_RequestCharLogon(int nA); // 0x00449E10
void __stdcall sub_00449E30_SetValue(int nValue); // 0x00449E30
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
int __cdecl CHATDLG_SendChatBuffer(); // 0x00442810
int __fastcall CHATDLG_IsCharOverLimit(const unsigned char* pChar); // 0x00442B20
int __stdcall CHATDLG_IsPrintableChar(int nA, int nB, const char* pChar); // 0x00443600
int __stdcall CHATDLG_CheckStartAdvResult(int nUnused); // 0x00443840
char* __cdecl CHATDLG_StrChr(const char* szString, int nChar); // 0x00446810
void __stdcall CHATDLG_RemoveTableString(Unicode* pText); // 0x00446A90
// 0x0043DC50
static void __cdecl CHATDLG_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo)
{
    int nMode = 5;
    const unsigned short wFlags = *(unsigned short*)pInfo->wFlags0x3CB;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if ((wFlags & 4) && !(wFlags & 8) && (FOG_IsExpansion() || pInfo->nValue0x1EE < 5))
        nMode = 1;
    gpChatCellFile = (D2CelFileStrc*)sub_005066C0(pInfo->nValue0x1EE, nMode, pInfo->szText0x3A1, (char*)&pInfo->nComponentColors);
    if (gpChatCellFile)
    {
        sub_005052B0(gpChatCellFile, 0x42);
        sub_005052F0(gpChatCellFile, 0x23B);
        sub_005051A0(gpChatCellFile, 0);
        sub_00505260(gpChatCellFile, 0);
    }
}


// 0x00441B70
int __fastcall CHATDLG_RunChat(D2LaunchCharInfoStrc* pInfo)
{
    char szTitle[256];
    D2WinControlStrc* pControl8;
    D2WinControlStrc* pControl4;

    GetTickCount();
    if (!sub_005259C0(sub_004FAC80(FOG_IsExpansion()), 0))
        return 1;

    gnChatLaunchMode = 0;
    gbDone = 0;
    gdwGlobal_0077BBF8 = 1;
    gpLaunchFuncs = *(D2LaunchFuncsStrc**)((char*)pInfo + 0x225);
    D2_ASSERT(gpLaunchFuncs, 3303);
    if (!gpLaunchFuncs->pfn0x68())
        gbDone = 4;
    else
    {
    CHATDLG_LoadFrontEndCels();
    sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);
    gpChatTextBox = 0;
    if (gpCharInfo->szRealm0x361[0])
        BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    else
        BACKGROUND_SetCellFile(gpWaitingRoomBkgdCelFile);
    if (gpCharInfo->szRealm0x361[0])
    {
        for (int i = 0; i < 17; i++)
            gapChatDlgControls[i] = CONTROL_Create(&gatChatControlInits_0070CE50[i]);
        gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    }
    else
    {
        sub_0043DDD0_CreateCharControls();
        CREATE_CELL_FILE(pInfo);
    }
    gpChatTextBox = CONTROL_Create(&gtChatTextBoxInit);
    if (gpCharInfo->szRealm0x361[0])
    {
        gpChatEdit = CONTROL_Create(&gtChatEditInit);
        sub_004FDAD0_SetKeyCallback(gpChatEdit, sub_0043F9B0_EditKey);
        sub_004FDB00_SetEnterCallback(gpChatEdit, sub_0043DB90);
        CONTROL_SetFocusedEditBox(gpChatEdit);
        sub_004FDD50_SetMaxLength(gpChatEdit, 200);
        COMCALLBACK_RefreshChatButtons();
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonA, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonA, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonB, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonB, 1);
        D2WinControlStrc** ppButton = gapChatButtons;
        for (int nX = 40; nX < 700; nX += 60, ppButton++)
            *ppButton = BUTTON_Create(nX, 591, 60, 100, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
        gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
        sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
        gpGemButton = CONTROL_Create(&gtGemButtonInit);
        if (gbGemToggle)
            sub_00500B20_SetValue(gpGemButton, 2);
    }
    CHARSEL_ClearHistory();
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnChatLaunchMode = 0;
    pControl8 = CONTROL_Create(&gtControlInit_0070D2D0);
    gpNamesButton = CONTROL_Create(&gtBlankBckgImageInit);
    gpControlMain_0077BC4C = CONTROL_Create(&gtControlInit_0070D330);
    GAME_SetMcpChatCallback(CHATDLG_SetPlayerName);
    VIEW_SendMcpMotdRequest();
    COMCALLBACK_UpdateNameListText();
    pControl4 = CONTROL_Create(&gtControlInit_0070D360);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo->wFlags;
    if ((wFlags & 8) && (wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpCreateScreenButton, 0);
        CONTROL_SetEnabled(gpJoinScreenButton, 0);
    }
    sub_004FA450_SetActive(gpQuitButton);
    gszText_0077B1D0[0] = 0;
    gszText_0077B0B4[0] = 0;
    D2SOUND_InitWaveSlots();
    D2SOUND_PreloadWave("data\\global\\sfx\\cursor\\button.wav");
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    gbCheck = gpCharInfo->nType0x35E == 4;
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck == 0);
    if (CHATDLG_ConnectRealm())
    {
        sprintf(szTitle, "%s,%s", pInfo->szRealm0x22D, pInfo->szName0xBD);
        int nFlags = 0;
        if (*(unsigned short*)pInfo->wFlags & 0x20)
            nFlags = 1;
        if (gpCharInfo->szRealm0x361[0])
            nFlags |= 2;
        gpLaunchFuncs->pfn0x54(pInfo->szName0xBD, szTitle, 0x25, pInfo->szRealm0x361, nFlags);
    }
    else
    {
        sub_00410610_WriteLogLine("[D2MULTI]  Could not restore MCP connection.");
        gpLaunchFuncs->pfn0x10();
    }
    if (gpLaunchFuncs->pfn0x68())
    {
        sub_00449E50_SetValue(0);
        InitializeCriticalSection(&gtChatLock);
        if (!gpCharInfo->szRealm0x361[0])
// build: symbol ?CHATDLG_PostClearMessage@* 0x0043E570
            gpLaunchFuncs->pfn0xA8(sub_0043E4C0, (void (__cdecl*)())CHATDLG_PostClearMessage);
        sub_004FA590_RunLoop(CHATDLG_OnTick);
// build: symbol ?GAME_IsMcpCreateQueued@* 0x00449E40
        if (GAME_IsMcpCreateQueued())
        {
            VIEW_SendMcpCancelGameCreate();
            sub_00449E50_SetValue(0);
        }
        if (!gpCharInfo->szRealm0x361[0])
            gpLaunchFuncs->pfn0xAC();
        DeleteCriticalSection(&gtChatLock);
        gpLaunchFuncs->pfn0x58();
        if (gbDone != 4)
            D2MCPClientCloseMCP();
    }
    else
        gbDone = 4;

    GetTickCount();
    sub_00515070();
    COMCALLBACK_ClearChannel();
    D2Win_10146();
    CHARSEL_ResetLaunchState();
    CHATDLG_FreeNameList();
    sub_004F95C0_ControlDestroy(&gpChatTextBox);
    if (gpControl_0077BD98)
        sub_004F95C0_ControlDestroy(&gpControl_0077BD98);
    sub_004F95C0_ControlDestroy(&pControl8);
    sub_004F95C0_ControlDestroy(&pControl4);
    sub_004F95C0_ControlDestroy(&gpNamesButton);
    sub_004F95C0_ControlDestroy(&gpControlMain_0077BC4C);
    if (gpGemButton)
        sub_004F95C0_ControlDestroy(&gpGemButton);
    if (gpChatEdit)
        sub_004F95C0_ControlDestroy(&gpChatEdit);
    for (int j = 0; j < 11; j++)
    {
        if (gapChatButtons[j])
            sub_004F95C0_ControlDestroy(&gapChatButtons[j]);
        gapChatButtons[j] = 0;
    }
    sub_004F95C0_ControlDestroy(&gpChatControl_0077BC44);
    for (int k = 0; k < 17; k++)
    {
        if (gapChatDlgControls[k])
            sub_004F95C0_ControlDestroy(&gapChatDlgControls[k]);
        gapChatDlgControls[k] = 0;
    }
    if (!gpCharInfo->szRealm0x361[0])
    {
        for (int m = 0; m <= 1; m++)
        {
            if (gapControls_0077B050[m])
            {
                sub_004F95C0_ControlDestroy(&gapControls_0077B050[m]);
                gapControls_0077B050[m] = 0;
            }
        }
        if (gpControl_0077BC40)
        {
            sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
            gpControl_0077BC40 = 0;
        }
    }
    BACKGROUND_SetCellFile(0);
    sub_004F9160_SetLoopValue(0);
    sub_0043D510_FreeCellFiles();
    }
    STRTABLE_UnloadStringTables();
    return 1;
}


// 0x00447700
int __fastcall CHATDLG_OnChannelDoesNotExist(int nA, int nB, const char* szText, int nLength)
{
    gpLaunchFuncs->pfn0x1C(nLength, 1, 0);
    CHATDLG_RefreshChatScreen();
    return 1;
}
int __fastcall CHATDLG_OnShowUser(int nA, int nB, const char* szText, int nLength); // 0x00449330
void __fastcall CHATDLG_MixChar(char* pChar, int nBits, unsigned int* pPool); // 0x004497F0
void __stdcall CHATDLG_SetMcpResult(int nValue); // 0x00449BF0
void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80
void __stdcall sub_00449C90_SetValue(int nValue); // 0x00449C90
void __stdcall sub_00449CC0_SetValue(int nValue); // 0x00449CC0
int __stdcall CHATDLG_GetMcpTexts(char* szText1, char* szText2); // 0x00449CD0
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2); // 0x00449D10
void __stdcall sub_00449D90_SetValue(int nValue); // 0x00449D90
void __stdcall sub_00449DB0_SetValue(int nValue); // 0x00449DB0
void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0
int __stdcall CHATDLG_RequestCharCreate(int nA, int nB, int nC); // 0x00449DF0
