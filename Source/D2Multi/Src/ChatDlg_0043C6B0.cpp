#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CharSaveHeaderStrc;
struct D2CharSaveFileStrc;
struct D2LaunchCharInfoStrc;
struct Unicode;
struct D2ChatMessageStrc;
struct _FILETIME;
struct _SYSTEMTIME;
struct D2LaunchFuncsStrc;
struct SMSGHANDLER_PARAMS;

struct D2WinControlInitStrc
{
    char data[0x30];
};

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

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    char szText0x8D[0x10];
    unsigned char unk_9D[0x20];
    char szText0xBD[0x170];
    char szText0x22D[0x10];
};
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
void* __fastcall sub_00406960_CreateFile(const char* szPath, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nSize, unsigned long* pRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nSize, unsigned long* pWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pDistanceHigh, unsigned long dwMethod); // 0x004069F0
unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize); // 0x00411130
D2CellFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0
void __stdcall sub_00504D30(D2CellFileStrc* pCellFileA, D2CellFileStrc* pCellFileB); // 0x00504D30
int __stdcall sub_005041B0_Destroy(D2CellFileStrc* pCellFile, int nFlag); // 0x005041B0
int __stdcall sub_004F91C0(void* pEditBox); // 0x004F91C0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __cdecl sub_0043E130_Reset(); // 0x0043E130
void __cdecl sub_004477A0_Refresh(); // 0x004477A0
int __stdcall sub_00448C70_ButtonCallback(void* pMsg); // 0x00448C70
extern "C" const char szDataGlobal_006D4118[]; // 0x006D4118
extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230
extern D2WinControlInitStrc gtControlTemplates_00708D10[]; // 0x00708D10
extern D2WinControlStrc* gapChatButtons_0077AD78[]; // 0x0077AD78
extern D2WinControlStrc* gpChatControl_0077B058; // 0x0077B058
extern D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C
extern D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064
extern D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068
extern D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern int gbToggle_0077BBEC; // 0x0077BBEC
extern D2CellFileStrc* gpChatCellFile_0077BBFC; // 0x0077BBFC
extern D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44
extern D2WinControlStrc* gpChatControl_0077BC48; // 0x0077BC48
extern D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94
extern D2CellFileStrc* gpCellFile_0077BC04; // 0x0077BC04
extern D2CellFileStrc* gpCellFile_0077BC08; // 0x0077BC08
extern D2CellFileStrc* gpCellFile_0077BC0C; // 0x0077BC0C
extern D2CellFileStrc* gpCellFile_0077BC10; // 0x0077BC10
extern D2CellFileStrc* gpCellFile_0077BC14; // 0x0077BC14
extern D2CellFileStrc* gpCellFile_0077BC18; // 0x0077BC18
extern D2CellFileStrc* gpCellFile_0077BC1C; // 0x0077BC1C
extern D2CellFileStrc* gpCellFile_0077BC20; // 0x0077BC20
extern D2CellFileStrc* gpCellFile_0077BC28; // 0x0077BC28
extern D2CellFileStrc* gpCellFile_0077BC2C; // 0x0077BC2C
extern D2CellFileStrc* gpCellFile_0077BC30; // 0x0077BC30
extern D2CellFileStrc* gpCellFile_0077BC34; // 0x0077BC34
extern D2CellFileStrc* gpCellFile_0077BC38; // 0x0077BC38
extern D2CellFileStrc* gpCellFile_0077BC3C; // 0x0077BC3C
extern D2CellFileStrc* gpCellFile_0077BC50; // 0x0077BC50
extern D2CellFileStrc* gpCellFile_0077BC54; // 0x0077BC54
extern D2CellFileStrc* gpCellFile_0077BC58; // 0x0077BC58
extern D2CellFileStrc* gpCellFile_0077BC5C; // 0x0077BC5C
extern D2CellFileStrc* gpCellFile_0077BC60; // 0x0077BC60
extern D2CellFileStrc* gpCellFile_0077BC64; // 0x0077BC64
extern D2CellFileStrc* gpCellFile_0077BC68; // 0x0077BC68
extern D2CellFileStrc* gpCellFile_0077BC6C; // 0x0077BC6C
extern D2CellFileStrc* gpCellFile_0077BC70; // 0x0077BC70
extern D2CellFileStrc* gpCellFile_0077BC74; // 0x0077BC74
extern D2CellFileStrc* gpCellFile_0077BC78; // 0x0077BC78
extern D2CellFileStrc* gpCellFile_0077BC7C; // 0x0077BC7C
extern D2CellFileStrc* gpCellFile_0077BC80; // 0x0077BC80
extern D2CellFileStrc* gpCellFile_0077BC84; // 0x0077BC84
extern D2CellFileStrc* gpCellFile_0077BC88; // 0x0077BC88
extern D2CellFileStrc* gpCellFile_0077BC8C; // 0x0077BC8C
extern D2CellFileStrc* gpCellFile_0077BC90; // 0x0077BC90
extern D2CellFileStrc* gpCellFile_0077BC94; // 0x0077BC94
extern D2CellFileStrc* gpCellFile_0077BCB8; // 0x0077BCB8
extern D2CellFileStrc* gpCellFile_0077BCBC; // 0x0077BCBC
extern D2CellFileStrc* gpCellFile_0077BCC0; // 0x0077BCC0
extern D2CellFileStrc* gpCellFile_0077BCC4; // 0x0077BCC4
extern D2CellFileStrc* gpCellFile_0077BCC8; // 0x0077BCC8
extern D2CellFileStrc* gpCellFile_0077BCCC; // 0x0077BCCC
extern D2CellFileStrc* gpCellFile_0077BCD0; // 0x0077BCD0
extern D2CellFileStrc* gpCellFile_0077BCD4; // 0x0077BCD4
extern D2CellFileStrc* gpCellFile_0077BCD8; // 0x0077BCD8
extern D2CellFileStrc* gpCellFile_0077BD0C; // 0x0077BD0C
extern D2CellFileStrc* gpCellFile_0077BD10; // 0x0077BD10
extern D2CellFileStrc* gpCellFile_0077BD18; // 0x0077BD18
extern D2CellFileStrc* gpCellFile_0077BD2C; // 0x0077BD2C
extern D2CellFileStrc* gpCellFile_0077BD30; // 0x0077BD30
extern D2CellFileStrc* gpCellFile_0077BD34; // 0x0077BD34
extern D2CellFileStrc* gpCellFile_0077BD38; // 0x0077BD38
extern D2CellFileStrc* gpCellFile_0077BD3C; // 0x0077BD3C
extern D2CellFileStrc* gpCellFile_0077BD40; // 0x0077BD40
extern D2CellFileStrc* gpCellFile_0077BD44; // 0x0077BD44
extern D2CellFileStrc* gpCellFile_0077BD48; // 0x0077BD48
extern D2CellFileStrc* gpCellFile_0077BD4C; // 0x0077BD4C
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct Unicode
{
    unsigned short wChar;
    Unicode();                                                                                              // 0x0042F530
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

struct _SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) unsigned int __stdcall GetACP(); // 0x006CC32C
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, unsigned short* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall GetDateFormatA(unsigned long nLocale, unsigned long dwFlags, const _SYSTEMTIME* pDate, const char* szFormat, char* szDate, int nDate); // 0x006CC330
extern "C" __declspec(dllimport) int __stdcall FileTimeToSystemTime(const _FILETIME* pFileTime, _SYSTEMTIME* pSystemTime); // 0x006CC334
extern "C" __declspec(dllimport) int __stdcall FileTimeToLocalFileTime(const _FILETIME* pFileTime, _FILETIME* pLocalFileTime); // 0x006CC338
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax); // 0x004135D0
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    void (__fastcall* pfn0x14)(const char* szText);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

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
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void __fastcall sub_004411E0_Use(const char* szText); // 0x004411E0
void __fastcall sub_0043E5F0_PrintMessage(const Unicode* pText, int nColor); // 0x0043E5F0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
extern char gaszHistory_0077B1D8[10][0x100]; // 0x0077B1D8
extern int gnHistoryCount_0077BD50; // 0x0077BD50
extern int gbShowJoinLeave_0077BD54; // 0x0077BD54
extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C
extern char gszLastWhisperer_0077B0D0[]; // 0x0077B0D0
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern unsigned char gnSelectModeA_0070CD62; // 0x0070CD62
extern int gnGlobal_0077B0A0; // 0x0077B0A0

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" int __cdecl strcmp(const char*, const char*);
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __cdecl sub_0043EBA0_ResetControls(); // 0x0043EBA0
void __cdecl sub_0043EB30_CreateControls(); // 0x0043EB30
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
Unicode* __fastcall D2Win_10196(D2WinControlStrc* pTextBox, int nLineNum, int nColumnNum); // 0x004FBB90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __fastcall sub_0044AA10_SendPacket11(unsigned char nArg1, unsigned short nArg2); // 0x0044AA10
extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070
extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078
extern D2WinControlStrc* gpList_0077BD00; // 0x0077BD00
extern int gnColor_0077AD74; // 0x0077AD74
extern int gnSelectLine_0070CD68; // 0x0070CD68
extern int gnSelectLinePrev_0070CD64; // 0x0070CD64
extern int gnSelection_0077BBF4; // 0x0077BBF4

D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10; // 0x0077AC10

D2WinControlStrc* gpChatControl_0077B060; // 0x0077B060

D2WinControlStrc* gpChatControl_0077B084; // 0x0077B084

D2WinControlStrc* gpChatControl_0077B088; // 0x0077B088

D2WinControlStrc* gpChatControl_0077B08C; // 0x0077B08C

D2WinControlStrc* gpChatControl_0077B090; // 0x0077B090

int gbChatSetup_0077BBF8; // 0x0077BBF8

// 0x0043C6B0
int __fastcall sub_0043C6B0_WriteSaveHeader(const char* szName)
{
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwWritten;

    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = sub_00406960_CreateFile(szPath, 0x40000000, 0, 0, 2, 0x8000000, 0);
    if (!hFile)
        return 0;

    gtCharSaveHeader_0077AC10.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&gtCharSaveHeader_0077AC10, 0x14F);
    sub_004069D0_WriteFile(hFile, &gtCharSaveHeader_0077AC10, 0x14F, &dwWritten, 0);
    sub_004069A0_CloseFile(hFile);
    return 1;
}

// 0x0043CAA0
int __fastcall sub_0043CAA0_UpdateSaveFlags(const char* szName)
{
    D2CharSaveFileStrc tSave;
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwFlags;
    unsigned long dwWritten;
    unsigned long dwRead;

    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = sub_00406960_CreateFile(szPath, 0xC0000000, 0, 0, 3, 0x8000000, 0);
    if (!hFile)
        return 0;

    sub_004069B0_ReadFile(hFile, &tSave, 0x2000, &dwRead, 0);
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
        sub_004069F0_SetFilePointer(hFile, 0x18, 0, 0);
        nResult = sub_004069D0_WriteFile(hFile, &dwFlags, 4, &dwWritten, 0);
    }
    else
    {
        if (dwRead < 0x14F)
            return 0;
        tSave.dwFlags |= 0x20;
        tSave.dwChecksum = 0;
        tSave.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&tSave, dwRead);
        sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
        nResult = sub_004069D0_WriteFile(hFile, &tSave, dwRead, &dwWritten, 0);
    }

    sub_004069A0_CloseFile(hFile);
    return nResult;
}

// 0x0043FC20
void __cdecl sub_0043FC20()
{
    char szText[0x100];

    if (!gbChatSetup_0077BBF8)
        return;

    gbChatSetup_0077BBF8 = 0;
    sprintf(szText, "%s,%s", gpCharInfo_0077BBD8->szText0x22D, gpCharInfo_0077BBD8->szText0xBD);
    sub_0043E130_Reset();

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
    sub_004F96F0_ControlClearState(gpChatControl_0077B074, 1);

    gpChatEdit_0077BD94 = CONTROL_Create(&gtControlTemplates_00708D10[0x172]);
    sub_004FDAD0_SetKeyCallback(gpChatEdit_0077BD94, sub_0043F9B0_EditKey);
    sub_004FDB00_SetEnterCallback(gpChatEdit_0077BD94, sub_0043DB90);
    sub_004F91C0(gpChatEdit_0077BD94);
    sub_004FDD50_SetMaxLength(gpChatEdit_0077BD94, 0xC8);
    sub_004477A0_Refresh();

    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B084, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B088, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B08C, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B090, 1);

    D2WinControlStrc** ppButton = gapChatButtons_0077AD78;
    for (int nX = 0x28; nX < 0x2BC; nX += 0x3C)
    {
        *ppButton++ = BUTTON_Create(nX, 0x24F, 0x3C, 0x64, 0, (int)sub_00448C70_ButtonCallback, 0, 0, 4, 0, 0);
    }

    gpChatControl_0077BC44 = CONTROL_Create(&gtControlTemplates_00708D10[0x170]);
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    gpChatControl_0077BC48 = CONTROL_Create(&gtControlTemplates_00708D10[0x178]);
    if (gbToggle_0077BBEC)
        sub_00500B20_SetValue(gpChatControl_0077BC48, 2);
}

// 0x0043CC30
void __cdecl sub_0043CC30_LoadFrontEndCels()
{
    char szPath[0x104];

    sprintf(szPath, "%s\\UI\\FrontEnd\\PopUpLargest2", szDataGlobal_006D4118);
    gpCellFile_0077BC0C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FrontEnd\\MediumButtonBlank2", szDataGlobal_006D4118);
    gpCellFile_0077BC10 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\bnet", szDataGlobal_006D4118);
    gpCellFile_0077BC04 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\waitingroombkgd", szDataGlobal_006D4118);
    gpCellFile_0077BC08 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\ohand", szDataGlobal_006D4118);
    gpCellFile_0077BC14 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\lrotate", szDataGlobal_006D4118);
    gpCellFile_0077BC18 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\scrollbar", szDataGlobal_006D4118);
    gpCellFile_0077BC1C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", szDataGlobal_006D4118);
    gpCellFile_0077BC20 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons", szDataGlobal_006D4118);
    gpCellFile_0077BC28 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons1", szDataGlobal_006D4118);
    gpCellFile_0077BC2C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons2", szDataGlobal_006D4118);
    gpCellFile_0077BC30 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrightbuttons", szDataGlobal_006D4118);
    gpCellFile_0077BC34 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrighttopbuttons", szDataGlobal_006D4118);
    gpCellFile_0077BC38 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatarrows", szDataGlobal_006D4118);
    gpCellFile_0077BC3C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingamebckg", szDataGlobal_006D4118);
    gpCellFile_0077BC50 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GameButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077BC5C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingameclickbox", szDataGlobal_006D4118);
    gpCellFile_0077BC60 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", szDataGlobal_006D4118);
    gpCellFile_0077BCC0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", szDataGlobal_006D4118);
    gpCellFile_0077BCC4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", szDataGlobal_006D4118);
    gpCellFile_0077BCC8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", szDataGlobal_006D4118);
    gpCellFile_0077BCCC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numbergreyarrows", szDataGlobal_006D4118);
    gpCellFile_0077BCD0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GreyLevelBox", szDataGlobal_006D4118);
    gpCellFile_0077BC64 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\createjoinbckg", szDataGlobal_006D4118);
    gpCellFile_0077BCD4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\okaybutton", szDataGlobal_006D4118);
    gpCellFile_0077BCD8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebckg", szDataGlobal_006D4118);
    gpCellFile_0077BD0C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebutton", szDataGlobal_006D4118);
    gpCellFile_0077BD10 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\widebuttonblank", szDataGlobal_006D4118);
    gpCellFile_0077BD18 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\CancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077BD2C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\yesnobuttonblank", szDataGlobal_006D4118);
    gpCellFile_0077BD30 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBlackBnet", szDataGlobal_006D4118);
    gpCellFile_0077BD48 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBnet", szDataGlobal_006D4118);
    gpCellFile_0077BD4C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\blankbckg2", szDataGlobal_006D4118);
    gpCellFile_0077BC54 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\gembutton", szDataGlobal_006D4118);
    gpCellFile_0077BC58 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\LadderChoiceEXP", szDataGlobal_006D4118);
    gpCellFile_0077BD34 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HardcoreLadderBckg", szDataGlobal_006D4118);
    gpCellFile_0077BD38 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", szDataGlobal_006D4118);
    gpCellFile_0077BD40 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", szDataGlobal_006D4118);
    gpCellFile_0077BD3C = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HelpBckg", szDataGlobal_006D4118);
    gpCellFile_0077BD44 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobutton", szDataGlobal_006D4118);
    gpCellFile_0077BC68 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobuttonGrey", szDataGlobal_006D4118);
    gpCellFile_0077BC6C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\PopUpOK", szDataGlobal_006D4118);
    gpCellFile_0077BC70 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\CancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077BC74 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\overalltab", szDataGlobal_006D4118);
    gpCellFile_0077BC78 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\amazontab", szDataGlobal_006D4118);
    gpCellFile_0077BC7C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\sorceresstab", szDataGlobal_006D4118);
    gpCellFile_0077BC80 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\necromancertab", szDataGlobal_006D4118);
    gpCellFile_0077BC84 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\paladintab", szDataGlobal_006D4118);
    gpCellFile_0077BC88 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\barbariantab", szDataGlobal_006D4118);
    gpCellFile_0077BC8C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\druidtab", szDataGlobal_006D4118);
    gpCellFile_0077BC90 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\assassintab", szDataGlobal_006D4118);
    gpCellFile_0077BC94 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SquelchAura", szDataGlobal_006D4118);
    gpCellFile_0077BCB8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SelectAura", szDataGlobal_006D4118);
    gpCellFile_0077BCBC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sub_00504D30(gpCellFile_0077BCB8, gpCellFile_0077BCBC);
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043C6B0.inc"

static D2CriticalSectionStrc gtChatLock_0077AE28; // 0x0077AE28

static D2ChatMessageStrc* gpChatQueueHead_0077BDAC; // 0x0077BDAC

static D2ChatMessageStrc* gpChatQueueTail_0077BDB0; // 0x0077BDB0

// 0x0043E250
static D2ChatMessageStrc* __stdcall sub_0043E250_CreateChatMessage(const char* szText, int nColor, int bClear)
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
static void sub_0043E310_PostChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = sub_0043E250_CreateChatMessage(szText, nColor, bClear);
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

// 0x0043E450
static void __stdcall sub_0043E450_FileTimeToText(char* szDate, int nSize, const _FILETIME* pFileTime)
{
    unsigned short wszDate[0x100];
    for (int i = 0; i < 0x100; i++)
        wszDate[i] = 0;
    _SYSTEMTIME tSystemTime;
    FileTimeToSystemTime(pFileTime, &tSystemTime);
    GetDateFormatA(0x400, 2, &tSystemTime, 0, szDate, nSize);
    MultiByteToWideChar(GetACP(), 1, szDate, -1, wszDate, 0x100);
    sub_005263E0(szDate, (Unicode*)wszDate, nSize);
}

// 0x0043E4C0
int __fastcall sub_0043E4C0_OnChatTime(unsigned int nTime, const char* szText)
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
        sub_0043E450_FileTimeToText(szDate, 0x40, &tLocalTime);
        sub_0043E310_PostChatMessage(szDate, 0, 0);
        sub_0043E310_PostChatMessage(szText, 4, 0);
        sub_0043E310_PostChatMessage(&gszEmptyAssertText, 0, 0);
    }
    return 1;
}

static int __stdcall sub_0043E6E0_CompareCommand(const char* szText, const char* szCommand)
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
static int sub_0043E780_NotifyCommand(const char* szCommand, const char* szText)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0043E6E0_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        if (!sub_0043E6E0_CompareCommand(szText, szCommand))
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

static void sub_0043F510_PushHistory(const char* szText)
{
    memmove(gaszHistory_0077B1D8[1], gaszHistory_0077B1D8[0], 0x900);
    strcpy(gaszHistory_0077B1D8[0], szText);
    if (++gnHistoryCount_0077BD50 >= 10)
        gnHistoryCount_0077BD50 = 10;
}

static void __stdcall sub_0043F870_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

static int sub_00442180_ReplyCommand(const char* szCommand, const char* szText)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0043E6E0_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        char szMessage[0x100];
        if (!strlen(gszLastWhisperer_0077B0D0))
        {
            unsigned short wszMessage[0x100];
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            sprintf(szMessage, gszNobodyToReply_006D561C);
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x100);
            if (gpChatTextBox_0077BD8C)
                sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, (Unicode*)wszMessage, 1, 0, 1);
        }
        else
        {
            char szPrefix[0x100];
            char szCopy[0x100];
            sprintf(szPrefix, gszCommandSpace_006D5618, szCommand);
            strcpy(szCopy, szText);
            char szDelim[2] = " ";
            int nCount = 0;
            char* pToken = strtok(szCopy, szDelim);
            while (pToken)
            {
                ++nCount;
                if (nCount == 2)
                    break;
                pToken = strtok(0, szDelim);
            }

            if (!pToken)
            {
                Unicode wszMessage[0x100];
                sprintf(szMessage, gszCorrectUsage_006D55F8, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox_0077BD8C)
                    sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, wszMessage, 1, 0, 1);
                return 1;
            }

            const char* pMessage = szText + (pToken - szCopy);
            if (!gpLaunchFuncs_0077B09C->pfn0x68())
            {
                sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }
            sprintf(szMessage, gszReplyFormat_006D55EC, gszLastWhisperer_0077B0D0, pMessage);
            gpLaunchFuncs_0077B09C->pfn0x14(szMessage);
        }
        return 1;
    }
    return 0;
}

void __fastcall sub_004423B0_RunCommand(char* szText)
{
    sub_0043F510_PushHistory(szText);
    if (sub_00442180_ReplyCommand(gszCmdR_006D56D4, szText))
        return;

    if (sub_00442180_ReplyCommand(gszCmdReply_006D56CC, szText))
        return;

    if (sub_0043E780_NotifyCommand(gszCmdD2Notify_006D56C0, szText))
        return;

    if (!sub_0043E6E0_CompareCommand(szText, "/ignorepersist"))
    {
        sub_00611560_GetSquelchList()->SetPersist(!sub_00611560_GetSquelchList()->GetPersist());
        if (sub_00611560_GetSquelchList()->GetPersist())
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA1), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA2), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, "/ignore ") || !sub_0043E6E0_CompareCommand(szText, gszCmdSquelch_006D5698))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        sub_0043F870_GetArgument(0x11, szName, szText);
        if (!SStrCmpI(&szName[1], gpCharInfo_0077BBD8->szText0x8D, 0x7FFFFFFF))
            return;

        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Squelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
        sub_00526700(wszMessage, wszFormat);
        sub_0043E5F0_PrintMessage(wszMessage, 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, "/unignore ") || !sub_0043E6E0_CompareCommand(szText, gszCmdUnsquelch_006D5680))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        sub_0043F870_GetArgument(0x11, szName, szText);
        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Unsquelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
        sub_00526700(wszMessage, wszFormat);
        sub_0043E5F0_PrintMessage(wszMessage, 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, "/filtermsg "))
    {
        char szFilter[0x104];
        sub_0043F870_GetArgument(0x104, szFilter, szText);
        if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA7), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA8), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, "/unfiltermsg "))
    {
        char szFilter[0x104];
        sub_0043F870_GetArgument(0x104, szFilter, szText);
        if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA9), 3);
        else
            sub_0043E5F0_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BAA), 3);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdHomeChannel_006D5654) || !sub_0043E6E0_CompareCommand(szText, gszCmdDefaultChannel_006D5640) || !sub_0043E6E0_CompareCommand(szText, gszCmdHomeSpace_006D5638))
    {
        char szChannel[0x20];
        sub_0043F870_GetArgument(0x20, szChannel, szText);
        SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
        return;
    }

    if (!sub_0043E6E0_CompareCommand(szText, gszCmdHome_006D5630))
    {
        char szChannel[0x20];
        if (SRegLoadString("Diablo II", "Default Channel", 0, szChannel, 0x20))
            sub_004411E0_Use(szChannel);
        return;
    }

    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
}

// 0x0043ECE0
int __stdcall sub_0043ECE0_Todo(int a)
{
    gnSelectIdA_0070CD7C -= gnGlobal_0077B0A0;
    unsigned char m = gnSelectModeB_0070CD63;
    gnSelectIdA_0070CD7C &= (gnSelectIdA_0070CD7C <= 0) - 1;
    gnSelectModeA_0070CD62 = m;
    return 1;
}

unsigned long gdwSelectTime_0077BD5C; // 0x0077BD5C

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
