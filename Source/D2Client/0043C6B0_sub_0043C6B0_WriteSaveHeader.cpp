struct D2WinControlStrc;
struct D2CellFileStrc;

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
    char unk0x000[0xBD];
    char szText0xBD[0x170];
    char szText0x22D[0x10];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468

void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050
void* __fastcall sub_00406960_CreateFile(const char* szPath, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x00406960
int __fastcall sub_004069A0_CloseHandle(void* hFile);                                                       // 0x004069A0
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nSize, unsigned long* pRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nSize, unsigned long* pWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pDistanceHigh, unsigned long dwMethod); // 0x004069F0
unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize);                 // 0x00411130
D2CellFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType);                       // 0x004FA9B0
void __stdcall sub_00504D30(D2CellFileStrc* pCellFileA, D2CellFileStrc* pCellFileB);                        // 0x00504D30
int __stdcall sub_005041B0_Destroy(D2CellFileStrc* pCellFile, int nFlag);                                   // 0x005041B0
int __stdcall BACKGROUND_SetCellFile(D2CellFileStrc* pCellFile);                                            // 0x004F9140
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
void __fastcall sub_00500B20_SetValue(D2WinControlStrc* pControl, int nValue);                              // 0x00500B20
D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10, int a11); // 0x00501290
void __cdecl sub_0043E130_Reset();                                                                          // 0x0043E130
int __stdcall sub_0043DB90(int nArg);                                                                       // 0x0043DB90
int __stdcall sub_0043F9B0_EditKey(D2WinControlStrc* pControl, int nPos, const char* pKey);                 // 0x0043F9B0
void __cdecl sub_004477A0_Refresh();                                                                        // 0x004477A0
int __stdcall sub_00448C70_ButtonCallback(void* pMsg);                                                      // 0x00448C70

extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszSaveFormat_006D4230[];                                                             // 0x006D4230
extern D2WinControlInitStrc gtControlTemplates_00708D10[];                                                  // 0x00708D10
D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10;                                                             // 0x0077AC10
extern D2WinControlStrc* gapChatButtons_0077AD78[];                                                         // 0x0077AD78
extern D2WinControlStrc* gpChatControl_0077B058;                                                            // 0x0077B058
extern D2WinControlStrc* gpChatControl_0077B05C;                                                            // 0x0077B05C
D2WinControlStrc* gpChatControl_0077B060;                                                                   // 0x0077B060
extern D2WinControlStrc* gpChatControl_0077B064;                                                            // 0x0077B064
extern D2WinControlStrc* gpChatControl_0077B068;                                                            // 0x0077B068
extern D2WinControlStrc* gpChatControl_0077B06C;                                                            // 0x0077B06C
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
D2WinControlStrc* gpChatControl_0077B084;                                                                   // 0x0077B084
D2WinControlStrc* gpChatControl_0077B088;                                                                   // 0x0077B088
D2WinControlStrc* gpChatControl_0077B08C;                                                                   // 0x0077B08C
D2WinControlStrc* gpChatControl_0077B090;                                                                   // 0x0077B090
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern int gbToggle_0077BBEC;                                                                               // 0x0077BBEC
int gbChatSetup_0077BBF8;                                                                                   // 0x0077BBF8
extern D2CellFileStrc* gpChatCellFile_0077BBFC;                                                             // 0x0077BBFC
extern D2CellFileStrc* gpChatBackground_0077BC04;                                                           // 0x0077BC04
extern D2WinControlStrc* gpChatControl_0077BC44;                                                            // 0x0077BC44
extern D2WinControlStrc* gpChatControl_0077BC48;                                                            // 0x0077BC48
extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern D2CellFileStrc* gpCellFile_0077BC04;                                                                 // 0x0077BC04
extern D2CellFileStrc* gpCellFile_0077BC08;                                                                 // 0x0077BC08
extern D2CellFileStrc* gpCellFile_0077BC0C;                                                                 // 0x0077BC0C
extern D2CellFileStrc* gpCellFile_0077BC10;                                                                 // 0x0077BC10
extern D2CellFileStrc* gpCellFile_0077BC14;                                                                 // 0x0077BC14
extern D2CellFileStrc* gpCellFile_0077BC18;                                                                 // 0x0077BC18
extern D2CellFileStrc* gpCellFile_0077BC1C;                                                                 // 0x0077BC1C
extern D2CellFileStrc* gpCellFile_0077BC20;                                                                 // 0x0077BC20
extern D2CellFileStrc* gpCellFile_0077BC28;                                                                 // 0x0077BC28
extern D2CellFileStrc* gpCellFile_0077BC2C;                                                                 // 0x0077BC2C
extern D2CellFileStrc* gpCellFile_0077BC30;                                                                 // 0x0077BC30
extern D2CellFileStrc* gpCellFile_0077BC34;                                                                 // 0x0077BC34
extern D2CellFileStrc* gpCellFile_0077BC38;                                                                 // 0x0077BC38
extern D2CellFileStrc* gpCellFile_0077BC3C;                                                                 // 0x0077BC3C
extern D2CellFileStrc* gpCellFile_0077BC50;                                                                 // 0x0077BC50
extern D2CellFileStrc* gpCellFile_0077BC54;                                                                 // 0x0077BC54
extern D2CellFileStrc* gpCellFile_0077BC58;                                                                 // 0x0077BC58
extern D2CellFileStrc* gpCellFile_0077BC5C;                                                                 // 0x0077BC5C
extern D2CellFileStrc* gpCellFile_0077BC60;                                                                 // 0x0077BC60
extern D2CellFileStrc* gpCellFile_0077BC64;                                                                 // 0x0077BC64
extern D2CellFileStrc* gpCellFile_0077BC68;                                                                 // 0x0077BC68
extern D2CellFileStrc* gpCellFile_0077BC6C;                                                                 // 0x0077BC6C
extern D2CellFileStrc* gpCellFile_0077BC70;                                                                 // 0x0077BC70
extern D2CellFileStrc* gpCellFile_0077BC74;                                                                 // 0x0077BC74
extern D2CellFileStrc* gpCellFile_0077BC78;                                                                 // 0x0077BC78
extern D2CellFileStrc* gpCellFile_0077BC7C;                                                                 // 0x0077BC7C
extern D2CellFileStrc* gpCellFile_0077BC80;                                                                 // 0x0077BC80
extern D2CellFileStrc* gpCellFile_0077BC84;                                                                 // 0x0077BC84
extern D2CellFileStrc* gpCellFile_0077BC88;                                                                 // 0x0077BC88
extern D2CellFileStrc* gpCellFile_0077BC8C;                                                                 // 0x0077BC8C
extern D2CellFileStrc* gpCellFile_0077BC90;                                                                 // 0x0077BC90
extern D2CellFileStrc* gpCellFile_0077BC94;                                                                 // 0x0077BC94
extern D2CellFileStrc* gpCellFile_0077BCB8;                                                                 // 0x0077BCB8
extern D2CellFileStrc* gpCellFile_0077BCBC;                                                                 // 0x0077BCBC
extern D2CellFileStrc* gpCellFile_0077BCC0;                                                                 // 0x0077BCC0
extern D2CellFileStrc* gpCellFile_0077BCC4;                                                                 // 0x0077BCC4
extern D2CellFileStrc* gpCellFile_0077BCC8;                                                                 // 0x0077BCC8
extern D2CellFileStrc* gpCellFile_0077BCCC;                                                                 // 0x0077BCCC
extern D2CellFileStrc* gpCellFile_0077BCD0;                                                                 // 0x0077BCD0
extern D2CellFileStrc* gpCellFile_0077BCD4;                                                                 // 0x0077BCD4
extern D2CellFileStrc* gpCellFile_0077BCD8;                                                                 // 0x0077BCD8
extern D2CellFileStrc* gpCellFile_0077BD0C;                                                                 // 0x0077BD0C
extern D2CellFileStrc* gpCellFile_0077BD10;                                                                 // 0x0077BD10
extern D2CellFileStrc* gpCellFile_0077BD18;                                                                 // 0x0077BD18
extern D2CellFileStrc* gpCellFile_0077BD2C;                                                                 // 0x0077BD2C
extern D2CellFileStrc* gpCellFile_0077BD30;                                                                 // 0x0077BD30
extern D2CellFileStrc* gpCellFile_0077BD34;                                                                 // 0x0077BD34
extern D2CellFileStrc* gpCellFile_0077BD38;                                                                 // 0x0077BD38
extern D2CellFileStrc* gpCellFile_0077BD3C;                                                                 // 0x0077BD3C
extern D2CellFileStrc* gpCellFile_0077BD40;                                                                 // 0x0077BD40
extern D2CellFileStrc* gpCellFile_0077BD44;                                                                 // 0x0077BD44
extern D2CellFileStrc* gpCellFile_0077BD48;                                                                 // 0x0077BD48
extern D2CellFileStrc* gpCellFile_0077BD4C;                                                                 // 0x0077BD4C

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
    sub_004069A0_CloseHandle(hFile);
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

    sub_004069A0_CloseHandle(hFile);
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

#include "gen/data/Source/D2Client/0043C6B0_sub_0043C6B0_WriteSaveHeader.inc"
