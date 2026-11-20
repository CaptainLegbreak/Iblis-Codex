#include "D2Client.h"
#include "D2ClientMenus.h"

#pragma pack(push, 2)

struct D2HotkeyFileStrc
{
    unsigned short nVersion;
    D2HotkeyStrc aKeys[114];
};

struct D2KeyConfigHeaderStrc
{
    unsigned short f_0;
    unsigned short nVersion;
    unsigned short nSize;
};
#pragma pack(pop)

#define NUM_HOTKEYS 114
#define HOTKEY_FILE_VERSION 0x25
#define HOTKEY_NUM_COMMANDS 0x39
#define INVALID_HANDLE_VALUE ((void*)-1)
#define GENERIC_READ 0x80000000
#define OPEN_EXISTING 3
#define FILE_ATTRIBUTE_NORMAL 0x80
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nSize, unsigned long* pWritten, void* pOverlapped); // 0x004069D0
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
void __stdcall sub_004698D0_LoadKeyConfig(int bInstallDir);                                                 // 0x004698D0
void __cdecl sub_004694A0_BindMouseHotkeys();                                                               // 0x004694A0

extern char gszAccountFolder_007A0500[];                                                                    // 0x007A0500
extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90

// 0x00469650
static void* sub_00469650_OpenKeyFile(unsigned long dwDesiredAccess, unsigned long dwCreationDisposition)
{
    char szSavePath[0x104] = { 0 };
    char szFileName[0x104] = { 0 };
    char szDir[0x104] = { 0 };
    sub_00407050_GetSavePath(szSavePath, sizeof(szSavePath));
    if (gszAccountFolder_007A0500[0])
    {
        SStrPrintf(szDir, sizeof(szDir), "%s%s\\", szSavePath, gszAccountFolder_007A0500);
        sub_00406A10_CreateDirectoryTree(szDir);
        SStrPrintf(szFileName, sizeof(szFileName), "%s%s.key", szDir, gszCharName_007A05C4);
        void* hFile = sub_00406960_CreateFile(szFileName, dwDesiredAccess, 0, 0, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, 0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            return hFile;
        }
    }

    SStrPrintf(szFileName, sizeof(szFileName), "%s%s.key", szSavePath, gszCharName_007A05C4);
    return sub_00406960_CreateFile(szFileName, dwDesiredAccess, 0, 0, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, 0);
}

// 0x00469780
void __cdecl sub_00469780_SaveKeyConfig()
{
    void* hFile = sub_00469650_OpenKeyFile(GENERIC_WRITE, CREATE_ALWAYS);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return;
    }

    D2HotkeyFileStrc tFile = { 0 };
    unsigned long nWritten = 0;
    tFile.nVersion = HOTKEY_FILE_VERSION;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        tFile.aKeys[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(tFile.aKeys, gtHotkeys_007A6F90, sizeof(tFile.aKeys));
    sub_004069D0_WriteFile(hFile, &tFile, sizeof(tFile), &nWritten, 0);
    sub_004069A0_CloseFile(hFile);

    char szPath[0x104];
    FOG_GetInstallPath(szPath, 0xDC);
    strcat(szPath, "default.key");
    hFile = sub_00406960_CreateFile(szPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return;
    }

    D2KeyConfigHeaderStrc tHeader;
    tHeader.f_0 = 0x5357;
    tHeader.nVersion = HOTKEY_FILE_VERSION;
    tHeader.nSize = 0x47A;
    sub_004069D0_WriteFile(hFile, &tHeader, sizeof(tHeader), &nWritten, 0);
    sub_004069D0_WriteFile(hFile, gtHotkeys_007A6F90, sizeof(gtHotkeys_007A6F90), &nWritten, 0);
    sub_004069A0_CloseFile(hFile);
}

// 0x0046AAE0
void __cdecl sub_0046AAE0_LoadKeyConfig()
{
    void* hFile = sub_00469650_OpenKeyFile(GENERIC_READ, OPEN_EXISTING);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        D2HotkeyFileStrc tFile = { 0 };
        unsigned long nRead = 0;
        sub_004069B0_ReadFile(hFile, &tFile, sizeof(tFile), &nRead, 0);
        sub_004069A0_CloseFile(hFile);
        if (nRead != sizeof(tFile) || tFile.nVersion != HOTKEY_FILE_VERSION)
        {
            goto LOAD_DEFAULT;
        }

        for (int nCommand = 0; nCommand < HOTKEY_NUM_COMMANDS; ++nCommand)
        {
            int bFound = 0;
            for (int i = 0; i < NUM_HOTKEYS && !bFound; ++i)
            {
                if (tFile.aKeys[i].nCommand == nCommand)
                {
                    bFound = 1;
                }
            }

            if (!bFound)
            {
                goto LOAD_DEFAULT;
            }
        }

        for (int i = 0; i < NUM_HOTKEYS; ++i)
        {
            for (int j = 0; j < NUM_HOTKEYS; ++j)
            {
                if (tFile.aKeys[i].nKey != HOTKEY_UNBOUND && i != j && tFile.aKeys[i].nKey == tFile.aKeys[j].nKey)
                {
                    goto LOAD_DEFAULT;
                }
            }
        }

        for (int i = 0; i < NUM_HOTKEYS; ++i)
        {
            gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
        }
        memcpy(gtHotkeys_007A6F90, tFile.aKeys, sizeof(gtHotkeys_007A6F90));
        sub_004694A0_BindMouseHotkeys();
        return;
    }

LOAD_DEFAULT:
    sub_004698D0_LoadKeyConfig(1);
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(gtHotkeys_007A6F90, gaKeyTable_00712220, sizeof(gtHotkeys_007A6F90));
    sub_004694A0_BindMouseHotkeys();
    sub_00469780_SaveKeyConfig();
}
