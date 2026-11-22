#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"

#pragma intrinsic(memcpy)

#define NUM_HOTKEYS 114

#define NUM_HOTKEY_COMMANDS 0x39

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HotkeyCommandStrc;

struct D2HotkeyStrc;

struct D2MsgHandlerEntryStrc;

typedef void (__cdecl* HOTKEYCOMMANDFN)();

struct D2HotkeyCommandStrc
{
    HOTKEYCOMMANDFN pfnCommand;
    HOTKEYCOMMANDFN pfnUnk0x04;
    int nModeFlag;
};

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" int __cdecl isalpha(int c); // 0x00686DA5

int __cdecl sub_004F59A0(); // 0x004F59A0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl sub_0046AAE0_LoadKeyConfig(); // 0x0046AAE0

extern D2HotkeyCommandStrc gtHotkeyCommands_00712698[]; // 0x00712698

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7404; // 0x007A7404

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7408; // 0x007A7408

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B10; // 0x007A6B10

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A740C; // 0x007A740C

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7414; // 0x007A7414

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B14; // 0x007A6B14

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7410; // 0x007A7410

extern D2MsgHandlerEntryStrc gtHotkeyHandlers_00712944[4]; // 0x00712944

extern D2MsgHandlerEntryStrc gtHotkeyHandlers_00712974[2]; // 0x00712974

void __cdecl sub_00469780_SaveKeyConfig(); // 0x00469780

void __cdecl CMDTBL_BindMouseHotkeys(); // 0x004694A0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __cdecl sub_0044C6B0(); // 0x0044C6B0

void __cdecl TEXT_ClearListFlags(); // 0x004A01E0

void __fastcall sub_0044BEA0_SetValue(int nValue); // 0x0044BEA0

void __stdcall CMDTBL_LoadKeyConfig(int bInstallDir); // 0x004698D0

extern D2HotkeyStrc gtHotkeysSaved_007A6B18[NUM_HOTKEYS]; // 0x007A6B18

#define HOTKEY_COMMAND_LIMIT 0x38

struct D2KeyBindingStrc;

struct D2HotkeyActionStrc;

int __fastcall CMDTBL_IsValidKey(unsigned short nKey); // 0x00469AE0


typedef void (__cdecl* D2HotkeyCallback)();

#pragma pack(push, 1)

struct D2KeyBindingStrc { int nAction; unsigned short nKey; char unk_06[4]; };

#pragma pack(pop)

struct D2HotkeyActionStrc { D2HotkeyCallback pfnCallback; int bAllowed; int f_8; };

extern D2HotkeyActionStrc gaActions_0071269C[]; // 0x0071269C

extern int gnMode_007A7418; // 0x007A7418

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

struct Unicode;

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern Unicode gwszKeyText_007A741C[4]; // 0x007A741C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
struct D2KeyConfigFileStrc
{
    unsigned short wTag;
    unsigned short wVersion;
    unsigned short wSize;
    unsigned char aBody[0x474];
};
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0

// 0x004690A0
void __cdecl CMDTBL_HotkeyClearScreen()
{
    sub_0044C6B0();
}

// 0x004691B0
void __cdecl CMDTBL_HotkeyClearMessages()
{
    TEXT_ClearListFlags();
}

// 0x00469200
void __cdecl CMDTBL_HotkeyStandStillRelease()
{
    sub_0044BEA0_SetValue(0);
}

HOTKEYCOMMANDFN gpfnBoundCommand_007A6F8C; // 0x007A6F8C

int gnGlobal_007A7418; // 0x007A7418

int gnGlobal_007A7424; // 0x007A7424

int gnGlobal_007A7428; // 0x007A7428

// 0x00469370
void __cdecl CMDTBL_CallBoundCommand()
{
    if (gpfnBoundCommand_007A6F8C)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnBoundCommand_007A6F8C), 0x375);
        gpfnBoundCommand_007A6F8C();
    }
}

static inline int HOTKEY_CheckWheelKey(int nCommand, int nKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gtHotkeyCommands_00712698[nCommand].pfnUnk0x04)
        {
            return 0;
        }
        break;
    }
    return 1;
}

// 0x004694A0
void __cdecl CMDTBL_BindMouseHotkeys()
{
    gpfnBoundCommand_007A7404 = 0;
    gpfnBoundCommand_007A7408 = 0;
    gpfnBoundCommand_007A6B10 = 0;
    gpfnBoundCommand_007A740C = 0;
    gpfnBoundCommand_007A7414 = 0;
    gpfnBoundCommand_007A6B14 = 0;
    gpfnBoundCommand_007A7410 = 0;
    gpfnBoundCommand_007A6F8C = 0;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey > 0xDF && gtHotkeys_007A6F90[i].nCommand < NUM_HOTKEY_COMMANDS)
        {
            switch (gtHotkeys_007A6F90[i].nKey)
            {
            case 0x100:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A6B10 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A740C = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x101:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7414 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A6B14 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x102:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7410 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A6F8C = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_UP:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7404 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_DOWN:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7408 = gtHotkeyCommands_00712698[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            }
        }
    }
}


// 0x004698D0
void __stdcall CMDTBL_LoadKeyConfig(int bInstallDir)
{
    char szLang[4];
    char szPath[0x104];
    D2KeyConfigFileStrc tFile;
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
    void* pData;
    int bLoaded = 0;
    if (bInstallDir)
    {
        FOG_GetInstallPath(szPath, 0xDC);
        strcat(szPath, "default.key");
        void* hFile = FOG_CreateFileA(szPath, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            unsigned long nRead;
            FOG_ReadFile(hFile, &tFile, sizeof(tFile), &nRead, 0);
            FOG_CloseFile(hFile);
            if (nRead == sizeof(tFile))
            {
                pData = FOG_AllocPool(0, sizeof(tFile), ".\\UI\\CmdTbl.cpp", 0x50F, 0);
                memcpy(pData, &tFile, sizeof(tFile));
                bLoaded = 1;
            }
        }
    }
    if (!bLoaded)
    {
        sprintf(szPath, "%s\\CMD\\%s\\default.key", szDataLocal_006D41A8, szLang);
        pData = ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, 0, ".\\UI\\CmdTbl.cpp", 0x51E);
    }
    if (!pData)
        return;
    D2KeyConfigFileStrc* pFile = (D2KeyConfigFileStrc*)pData;
    if (pFile->wTag == 0x5357 && pFile->wVersion == 0x25 && pFile->wSize == sizeof(D2KeyConfigFileStrc))
    {
        memcpy(gaKeyTable_00712220, pFile->aBody, sizeof(gaKeyTable_00712220));
        FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x52C, 0);
        return;
    }
    FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x531, 0);
}

// 0x00469A50
static inline void CMDTBL_LoadKeyConfigInline(int bInstallDir)
{
    CMDTBL_LoadKeyConfig(bInstallDir);
}

// 0x00469A60
void __fastcall CMDTBL_ResetKeyConfig(int bInstallDir)
{
    CMDTBL_LoadKeyConfig(bInstallDir);
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(gtHotkeys_007A6F90, gaKeyTable_00712220, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

// 0x00469AE0
int __fastcall CMDTBL_IsValidKey(unsigned short nKey)
{
    switch (nKey)
    {
    case 0x08: case 0x09: case 0x0C: case 0x0D: case 0x10: case 0x11:
    case 0x12: case 0x13: case 0x14: case 0x20: case 0x21: case 0x22:
    case 0x23: case 0x24: case 0x2A: case 0x2C: case 0x2D: case 0x2E:
    case 0x2F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: case 0x70:
    case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76:
    case 0x77: case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C:
    case 0x7D: case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82:
    case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x91:
    case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
    case 0xC0: case 0xDB: case 0xDC: case 0xDD: case 0xDE: case 0x100:
    case 0x101: case 0x102: case 0x103: case 0x104:
        return 1;
    case 0x01: case 0x02: case 0x03: case 0x04: case 0x15: case 0x17:
    case 0x18: case 0x19: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29:
    case 0x2B: case 0x5B: case 0x5C: case 0x5D: case 0x90:
        return 0;
    }
    if (isalpha(nKey) || isdigit(nKey))
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00469420_CheckWheelKey(int nId, unsigned short nKey, unsigned short* pKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gtHotkeyCommands_00712698[nId].pfnUnk0x04)
        {
            if (pKey)
            {
                *pKey = 0xF8A;
            }
            return 0;
        }
        break;
    }
    return 1;
}

// 0x00469C20
int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey)
{
    const unsigned short nKey = (unsigned short)nCommand;
    if (pKey)
    {
        *pKey = 0;
    }
    if (nId > HOTKEY_COMMAND_LIMIT || nId == HOTKEY_COMMAND_LIMIT)
    {
        return 0;
    }

    int bError = 1;
    if (CMDTBL_IsValidKey(nKey))
    {
        if (!sub_00469420_CheckWheelKey(nId, nKey, pKey))
        {
            return 0;
        }
        bError = nKey == 0x2C && gtHotkeyCommands_00712698[nId].pfnCommand;
    }
    if (bError)
    {
        if (pKey)
        {
            *pKey = 0xF8B;
        }
        return 0;
    }

    int nFree = NUM_HOTKEYS;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey == nKey)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
            nFree = i;
            break;
        }
    }
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            gtHotkeys_007A6F90[i].nKey = nKey;
            return 1;
        }
    }
    if (nFree != NUM_HOTKEYS)
    {
        gtHotkeys_007A6F90[nFree].nKey = nKey;
    }
    return 0;
}

void __fastcall sub_M110_Emit_00469A50(int bInstallDir)
{
    CMDTBL_LoadKeyConfigInline(bInstallDir + 1);
}

// 0x00469D20
void __cdecl CMDTBL_SaveHotkeys()
{
    memcpy(gtHotkeysSaved_007A6B18, gtHotkeys_007A6F90, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

// 0x00469D40
void __cdecl CMDTBL_SaveAndBindHotkeys()
{
    sub_00469780_SaveKeyConfig();
    CMDTBL_BindMouseHotkeys();
}

// 0x00469D50
void __cdecl CMDTBL_RestoreHotkeys()
{
    memcpy(gtHotkeys_007A6F90, gtHotkeysSaved_007A6B18, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

static inline unsigned short sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469DE0
const Unicode* __fastcall CMDTBL_GetKeyText(int nA, int nB)
{
    const unsigned short nKey = sub_00469AA0(nA, nB);
    if (nKey == 0xFFFF)
    {
        return D2LANG_GetStringFromTblIndex(0xEB2);
    }

    if (nKey > 0xDF)
    {
        switch (nKey)
        {
        case 0x103:
            return D2LANG_GetStringFromTblIndex(0xEB9);

        case 0x104:
            return D2LANG_GetStringFromTblIndex(0xEBA);

        case 0x100:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x101:
            return D2LANG_GetStringFromTblIndex(0xEB7);

        case 0x102:
            return D2LANG_GetStringFromTblIndex(0xEB8);
        }
    }
    else
    {
        switch (nKey)
        {
        case 0x1:
            return D2LANG_GetStringFromTblIndex(0xEB3);

        case 0x2:
            return D2LANG_GetStringFromTblIndex(0xEB4);

        case 0x3:
            return D2LANG_GetStringFromTblIndex(0xEB5);

        case 0x4:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x15:
            return D2LANG_GetStringFromTblIndex(0xEBB);

        case 0x17:
            return D2LANG_GetStringFromTblIndex(0xEBC);

        case 0x18:
            return D2LANG_GetStringFromTblIndex(0xEBD);

        case 0x19:
            return D2LANG_GetStringFromTblIndex(0xEBE);

        case 0x1B:
            return D2LANG_GetStringFromTblIndex(0xEBF);

        case 0x1C:
            return D2LANG_GetStringFromTblIndex(0xEC0);

        case 0x1D:
            return D2LANG_GetStringFromTblIndex(0xEC1);

        case 0x1E:
            return D2LANG_GetStringFromTblIndex(0xEC2);

        case 0x1F:
            return D2LANG_GetStringFromTblIndex(0xEC3);

        case 0x25:
            return D2LANG_GetStringFromTblIndex(0xEC4);

        case 0x26:
            return D2LANG_GetStringFromTblIndex(0xEC5);

        case 0x27:
            return D2LANG_GetStringFromTblIndex(0xEC6);

        case 0x28:
            return D2LANG_GetStringFromTblIndex(0xEC7);

        case 0x29:
            return D2LANG_GetStringFromTblIndex(0xEC8);

        case 0x2B:
            return D2LANG_GetStringFromTblIndex(0xEC9);

        case 0x5B:
            return D2LANG_GetStringFromTblIndex(0xECA);

        case 0x5C:
            return D2LANG_GetStringFromTblIndex(0xECB);

        case 0x5D:
            return D2LANG_GetStringFromTblIndex(0xECC);

        case 0x90:
            return D2LANG_GetStringFromTblIndex(0xECD);

        case 0x8:
            return D2LANG_GetStringFromTblIndex(0xECE);

        case 0x9:
            return D2LANG_GetStringFromTblIndex(0xECF);

        case 0xC:
            return D2LANG_GetStringFromTblIndex(0xED0);

        case 0xD:
            return D2LANG_GetStringFromTblIndex(0xED1);

        case 0x10:
            return D2LANG_GetStringFromTblIndex(0xED2);

        case 0x11:
            return D2LANG_GetStringFromTblIndex(0xED3);

        case 0x12:
            return D2LANG_GetStringFromTblIndex(0xED4);

        case 0x13:
            return D2LANG_GetStringFromTblIndex(0xED5);

        case 0x14:
            return D2LANG_GetStringFromTblIndex(0xED6);

        case 0x20:
            return D2LANG_GetStringFromTblIndex(0xED7);

        case 0x21:
            return D2LANG_GetStringFromTblIndex(0xED8);

        case 0x22:
            return D2LANG_GetStringFromTblIndex(0xED9);

        case 0x23:
            return D2LANG_GetStringFromTblIndex(0xEDA);

        case 0x24:
            return D2LANG_GetStringFromTblIndex(0xEDB);

        case 0x2A:
            return D2LANG_GetStringFromTblIndex(0xEDC);

        case 0x2C:
            return D2LANG_GetStringFromTblIndex(0xEDD);

        case 0x2D:
            return D2LANG_GetStringFromTblIndex(0xEDE);

        case 0x2E:
            return D2LANG_GetStringFromTblIndex(0xEDF);

        case 0x2F:
            return D2LANG_GetStringFromTblIndex(0xEE0);

        case 0x60:
            return D2LANG_GetStringFromTblIndex(0xEE1);

        case 0x61:
            return D2LANG_GetStringFromTblIndex(0xEE2);

        case 0x62:
            return D2LANG_GetStringFromTblIndex(0xEE3);

        case 0x63:
            return D2LANG_GetStringFromTblIndex(0xEE4);

        case 0x64:
            return D2LANG_GetStringFromTblIndex(0xEE5);

        case 0x65:
            return D2LANG_GetStringFromTblIndex(0xEE6);

        case 0x66:
            return D2LANG_GetStringFromTblIndex(0xEE7);

        case 0x67:
            return D2LANG_GetStringFromTblIndex(0xEE8);

        case 0x68:
            return D2LANG_GetStringFromTblIndex(0xEE9);

        case 0x69:
            return D2LANG_GetStringFromTblIndex(0xEEA);

        case 0x6A:
            return D2LANG_GetStringFromTblIndex(0xEEB);

        case 0x6B:
            return D2LANG_GetStringFromTblIndex(0xEEC);

        case 0x6C:
            return D2LANG_GetStringFromTblIndex(0xEED);

        case 0x6D:
            return D2LANG_GetStringFromTblIndex(0xEEE);

        case 0x6E:
            return D2LANG_GetStringFromTblIndex(0xEEF);

        case 0x6F:
            return D2LANG_GetStringFromTblIndex(0xEF0);

        case 0x70:
            return D2LANG_GetStringFromTblIndex(0xEF1);

        case 0x71:
            return D2LANG_GetStringFromTblIndex(0xEF2);

        case 0x72:
            return D2LANG_GetStringFromTblIndex(0xEF3);

        case 0x73:
            return D2LANG_GetStringFromTblIndex(0xEF4);

        case 0x74:
            return D2LANG_GetStringFromTblIndex(0xEF5);

        case 0x75:
            return D2LANG_GetStringFromTblIndex(0xEF6);

        case 0x76:
            return D2LANG_GetStringFromTblIndex(0xEF7);

        case 0x77:
            return D2LANG_GetStringFromTblIndex(0xEF8);

        case 0x78:
            return D2LANG_GetStringFromTblIndex(0xEF9);

        case 0x79:
            return D2LANG_GetStringFromTblIndex(0xEFA);

        case 0x7A:
            return D2LANG_GetStringFromTblIndex(0xEFB);

        case 0x7B:
            return D2LANG_GetStringFromTblIndex(0xEFC);

        case 0x7C:
            return D2LANG_GetStringFromTblIndex(0xEFD);

        case 0x7D:
            return D2LANG_GetStringFromTblIndex(0xEFE);

        case 0x7E:
            return D2LANG_GetStringFromTblIndex(0xEFF);

        case 0x7F:
            return D2LANG_GetStringFromTblIndex(0xF00);

        case 0x80:
            return D2LANG_GetStringFromTblIndex(0xF01);

        case 0x81:
            return D2LANG_GetStringFromTblIndex(0xF02);

        case 0x82:
            return D2LANG_GetStringFromTblIndex(0xF03);

        case 0x83:
            return D2LANG_GetStringFromTblIndex(0xF04);

        case 0x84:
            return D2LANG_GetStringFromTblIndex(0xF05);

        case 0x85:
            return D2LANG_GetStringFromTblIndex(0xF06);

        case 0x86:
            return D2LANG_GetStringFromTblIndex(0xF07);

        case 0x87:
            return D2LANG_GetStringFromTblIndex(0xF08);

        case 0x91:
            return D2LANG_GetStringFromTblIndex(0xF09);

        case 0xBA:
            return D2LANG_GetStringFromTblIndex(0xF0A);

        case 0xBB:
            return D2LANG_GetStringFromTblIndex(0xF0B);

        case 0xBC:
            return D2LANG_GetStringFromTblIndex(0xF0C);

        case 0xBD:
            return D2LANG_GetStringFromTblIndex(0xF0D);

        case 0xBE:
            return D2LANG_GetStringFromTblIndex(0xF0E);

        case 0xBF:
            return D2LANG_GetStringFromTblIndex(0xF0F);

        case 0xC0:
            return D2LANG_GetStringFromTblIndex(0xF10);

        case 0xDB:
            return D2LANG_GetStringFromTblIndex(0xF11);

        case 0xDC:
            return D2LANG_GetStringFromTblIndex(0xF12);

        case 0xDD:
            return D2LANG_GetStringFromTblIndex(0xF13);

        case 0xDE:
            return D2LANG_GetStringFromTblIndex(0xF14);
        }
    }

    memset(gwszKeyText_007A741C, 0, sizeof(gwszKeyText_007A741C));
    gwszKeyText_007A741C[0].wChar = (unsigned char)nKey;
    return gwszKeyText_007A741C;
}

static inline unsigned short FindHotkeyKey_Inline(int nId, int nMode)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }
    return 0xFFFF;
}

// 0x0046A530
const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB)
{
    switch (FindHotkeyKey_Inline(nA, nB))
    {
    case 0x100:
        return D2LANG_GetStringFromTblIndex(0xF15);
    case 0x101:
        return D2LANG_GetStringFromTblIndex(0xF16);
    case 0x102:
        return D2LANG_GetStringFromTblIndex(0xF17);
    case 0x103:
        return D2LANG_GetStringFromTblIndex(0xF18);
    case 0x104:
        return D2LANG_GetStringFromTblIndex(0xF19);
    case 0x11:
        return D2LANG_GetStringFromTblIndex(0xF30);
    case 0x21:
        return D2LANG_GetStringFromTblIndex(0xF34);
    case 0x22:
        return D2LANG_GetStringFromTblIndex(0xF35);
    case 0x1B:
        return D2LANG_GetStringFromTblIndex(0xF1E);
    case 0x90:
        return D2LANG_GetStringFromTblIndex(0xF2B);
    case 0x8:
        return D2LANG_GetStringFromTblIndex(0xF2C);
    case 0x10:
        return D2LANG_GetStringFromTblIndex(0xF2F);
    case 0x60:
        return D2LANG_GetStringFromTblIndex(0xF3B);
    case 0x61:
        return D2LANG_GetStringFromTblIndex(0xF3C);
    case 0x62:
        return D2LANG_GetStringFromTblIndex(0xF3D);
    case 0x63:
        return D2LANG_GetStringFromTblIndex(0xF3E);
    case 0x64:
        return D2LANG_GetStringFromTblIndex(0xF3F);
    case 0x65:
        return D2LANG_GetStringFromTblIndex(0xF40);
    case 0x66:
        return D2LANG_GetStringFromTblIndex(0xF41);
    case 0x67:
        return D2LANG_GetStringFromTblIndex(0xF42);
    case 0x68:
        return D2LANG_GetStringFromTblIndex(0xF43);
    case 0x69:
        return D2LANG_GetStringFromTblIndex(0xF44);
    case 0x6A:
        return D2LANG_GetStringFromTblIndex(0xF45);
    case 0x6B:
        return D2LANG_GetStringFromTblIndex(0xF46);
    case 0x6C:
        return D2LANG_GetStringFromTblIndex(0xF48);
    case 0x6D:
        return D2LANG_GetStringFromTblIndex(0xF47);
    case 0x6F:
        return D2LANG_GetStringFromTblIndex(0xF49);
    case 0x91:
        return D2LANG_GetStringFromTblIndex(0xF4A);
    case 0x2C:
        return D2LANG_GetStringFromTblIndex(0xF37);
    case 0x2D:
        return D2LANG_GetStringFromTblIndex(0xF38);
    case 0x2E:
        return D2LANG_GetStringFromTblIndex(0xF39);
    }
    return CMDTBL_GetKeyText(nA, nB);
}

D2KeyBindingStrc gaBindings_007A6F90[114]; // 0x007A6F90

// 0x0046A940
void __stdcall CMDTBL_DispatchHotkey(SMSGHANDLER_PARAMS* pMsg)
{
    int nKey = pMsg->wParam;
    for (int i = 0; i < 114; ++i)
    {
        if (gaBindings_007A6F90[i].nKey != nKey)
            continue;
        int nAction = gaBindings_007A6F90[i].nAction;
        if (nAction != 0xFFFF && nAction < 0x39 && nAction <= 0xDF && gaActions_0071269C[nAction].pfnCallback)
        {
            if (gnMode_007A7418 == 2 && !gaActions_0071269C[gaBindings_007A6F90[i].nAction].bAllowed)
                return;
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback), 0x81C);
            gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

// 0x0046AA20
void __fastcall CMDTBL_SetHotkeyHandlers(int bEnable, int bFlag)
{
    gnGlobal_007A7418 = bEnable;
    if (bEnable)
    {
        if (gnGlobal_007A7428 == 0)
        {
            gnGlobal_007A7428 = 1;
            if (bFlag && gnGlobal_007A7424 != 0)
            {
                sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712974, 2);
                gnGlobal_007A7424 = 0;
            }
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
        }
    }
    else
    {
        if (gnGlobal_007A7428 == 1)
        {
            gnGlobal_007A7428 = 0;
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
            if (bFlag && gnGlobal_007A7424 == 0)
            {
                sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712974, 2);
                gnGlobal_007A7424 = 1;
            }
        }
    }
}

// 0x0046AC70
void __cdecl CMDTBL_EnableHotkeyHandlers()
{
    sub_0046AAE0_LoadKeyConfig();
    gnGlobal_007A7418 = 1;
    if (gnGlobal_007A7428 == 0)
    {
        gnGlobal_007A7428 = 1;
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
    }
}

// 0x0046ACB0
void __cdecl CMDTBL_DisableHotkeyHandlers()
{
    gnGlobal_007A7418 = 0;
    if (gnGlobal_007A7428 == 1)
    {
        gnGlobal_007A7428 = 0;
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHotkeyHandlers_00712944, 4);
    }
}

#include "gen/data/Source/D2Client/UI/CmdTbl.inc"
