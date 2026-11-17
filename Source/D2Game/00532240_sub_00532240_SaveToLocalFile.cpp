struct D2ClientStrc;
struct D2SaveHeaderStrc;
struct D2ServerCallbackFunctions;
struct _iobuf;

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
};

struct D2UnitStrc
{
    char unk0x00[0xC8];
    unsigned int dwFlagEx;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile);
extern "C" int __cdecl fclose(_iobuf* pFile);
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                           // 0x00407050
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
__declspec(noalias) int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient);                                                  // 0x00538590
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int a5, int a6, int a7); // 0x00538CE0
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient);                                  // 0x00538E00
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient);                                              // 0x00538F10
void __fastcall D2GAME_SetSaveLoadComplete_6FC34300(D2ClientStrc* pClient);                                 // 0x00538F80
extern "C" int __stdcall sub_00554100(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                 // 0x00554100
extern "C" void __fastcall sub_00539300(D2ClientStrc* pClient, unsigned int* pOut);                       // 0x00539300
extern "C" void __fastcall sub_00539310(D2ClientStrc* pClient, unsigned int* pOut);                       // 0x00539310
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer);                     // 0x005392F0
int __fastcall sub_00531EB0_WriteFileOnRealm(D2GameStrc* pGame, char* szAccountName, D2UnitStrc* pPlayer, const char* szName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo);
extern int gnGlobal_007310CC;                                                                               // 0x007310CC
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern "C" const char gszSaveFormat_006D4230[];                                                             // 0x006D4230
extern "C" const char gszFileModeWb_006D69E0[];                                                             // 0x006D69E0
extern "C" const char gszSaveOpenError_006E09C4[];                                                          // 0x006E09C4
extern "C" const char szPlrSaveCppFile_006E09AC[];

static __declspec(noinline) void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName);

// 0x00532240
static void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    if (!gnGlobal_007310CC)
    {
        return;
    }

    char szPath[0x400];
    char szFile[0x1F4];
    unsigned char pData[0x2000];
    unsigned int nSize;

    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFile, gszSaveFormat_006D4230, szPath, szName);
    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0)
    {
        return;
    }

    _iobuf* pFile = fopen(szFile, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(pData, nSize, 1, pFile);
        fclose(pFile);
    }
    else
    {
        sub_00410610_WriteLogLine(gszSaveOpenError_006E09C4, szFile);
    }
}

// 0x00532340
static __declspec(noinline) void __stdcall sub_00532340_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    unsigned char pData[0x2000];
    unsigned int nSize;

    if (CLIENTS_GetSaveHeader(pClient))
    {
        CLIENTS_FreeSaveHeader(pClient);
    }

    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, 0);
    const int nFileSize = nSize;
    D2_ASSERT(nFileSize > 0, 2866);
    const int nClientId = CLIENTS_GetClientId(pClient);
    CLIENTS_AttachSaveFile(nClientId, pData, nFileSize, nFileSize, 0, 0, 0);
    D2GAME_SetSaveLoadComplete_6FC34300(pClient);
}

// build: context D2GAME_SAVE_WriteFile_6FC8A500
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg)
{
    if (!pPlayer)
    {
        return 0;
    }

    pPlayer->dwFlagEx &= ~2;

    int bInteractsWithPlayer = 0;
    int nUnitType = 6;
    int nUnitGUID;
    if (sub_00554100(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 0)
    {
        bInteractsWithPlayer = 1;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, szPlrSaveCppFile_006E09AC, 2919);
    char szAccountName[50];
    CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
    unsigned int nToken;
    sub_00539300(pClient, &nToken);
    unsigned int nClientInfo;
    sub_00539310(pClient, &nClientInfo);

    int nResult = 1;
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        sub_00532340_SaveToClient(bInteractsWithPlayer, pGame, pClient, pPlayer);
    }
    else if (gpD2EventCallbackTable_6FD45830)
    {
        nResult = sub_00531EB0_WriteFileOnRealm(pGame, szAccountName, pPlayer, szName, bInteractsWithPlayer, nToken, dwArg, nClientInfo);
    }
    else
    {
        sub_00532240_SaveToLocalFile(bInteractsWithPlayer, dwArg, pGame, pPlayer, szName);
    }

    return nResult;
}

#include "gen/data/Source/D2Game/00532240_sub_00532240_SaveToLocalFile.inc"
