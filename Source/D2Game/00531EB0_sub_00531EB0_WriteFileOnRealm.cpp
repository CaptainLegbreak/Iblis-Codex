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
int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0
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
extern int gnGlobal_007310CC;                                                                               // 0x007310CC
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern "C" const char gszSaveFormat_006D4230[];
extern "C" const char gszFileModeWb_006D69E0[];
extern "C" const char gszSaveOpenError_006E09C4[];
extern "C" const char szPlrSaveCppFile_006E09AC[];                                                          // 0x006E09AC

struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;
struct D2ClientInfoStrc;
struct D2SaveHeaderStrc
{
    unsigned int dwHeader;
    unsigned int dwVersion;
    unsigned int dwSize;
    int dwChecksum;
    char pad10[0x20];
    int dwLasTime;
    int dwPlayTime;
    char pad38[0x73];
    char dwMapSeed[4];
};
typedef int (__stdcall* FARPROC)();
typedef void (__fastcall* RealmSaveCallback)(unsigned int*, const char*, char*, void*, int, unsigned int);
typedef void (__fastcall* RealmUpdateCallback)(unsigned int*, const char*, char*);
struct D2ServerCallbackFunctions
{
    char pad00[0x0C];
    RealmSaveCallback pfSave;
    char pad10[0x28];
    RealmUpdateCallback pfUpdate;
};
extern int gnGlobal_007310CC; // 0x007310CC
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
extern int gnGlobal_00883D6C; // 0x00883D6C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char szPlrSaveCppFile_006E09AC[]; // 0x006E09AC
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned int __fastcall D2GAME_GetSaveChecksumFromClient_6FC33940(D2ClientStrc* pClient); // 0x00538350
int __fastcall D2GAME_SAVE_CalculateChecksum_6FC8A140(D2SaveHeaderStrc* pSaveHeader, int nSize); // 0x00531E30
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient); // 0x00538E00
int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* pClient); // 0x00538E30
void __fastcall sub_00539320(D2ClientStrc* pClient, unsigned int nClientInfo); // 0x00539320
void __fastcall D2GAME_SetSaveFileChecksum_6FC33970(D2ClientStrc* pClient, unsigned int nChecksum); // 0x00538380
void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* pClient, const void* pData, unsigned int nSize); // 0x00538E60

static __declspec(noinline) int __stdcall sub_00531EB0_WriteFileOnRealm(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, char* szAccountName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo);

// 0x00531EB0
static int __stdcall sub_00531EB0_WriteFileOnRealm(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, char* szAccountName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo)
{
    unsigned char pData[0x2000];
    if (!gnGlobal_007310CC) return 0;
    unsigned int nTotalSize;
    {
    unsigned int nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData + 2, &nSize, 0x2000, bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0) return 0;
    nTotalSize = nSize + 2;
    }
    *(unsigned short*)pData = (unsigned short)nTotalSize;
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, szPlrSaveCppFile_006E09AC, 0xA3B);
    unsigned int nOldChecksum = D2GAME_GetSaveChecksumFromClient_6FC33940(pClient);
    unsigned int nChecksum = D2GAME_SAVE_CalculateChecksum_6FC8A140((D2SaveHeaderStrc*)(pData + 2), nTotalSize - 2);
    int bMatching = nChecksum == nOldChecksum;
    if (bMatching)
    {
        D2SaveHeaderStrc* pOldHeader = CLIENTS_GetSaveHeader(pClient);
        int nOldSize = CLIENTS_GetSaveHeaderSize(pClient);
        D2_ASSERT(pOldHeader, 0xA46);
        bMatching = 1;
        if (nOldSize == nTotalSize - 2)
        {
            const unsigned int nOldVersion = pOldHeader->dwVersion;
            int nOldCheck = 0;
            int nOldLast = 0;
            int nOldPlay = 0;
            int nOldMap = 0;
            if (nOldVersion > 91)
            {
                nOldCheck = pOldHeader->dwChecksum;
                nOldLast = pOldHeader->dwLasTime;
                nOldPlay = pOldHeader->dwPlayTime;
                nOldMap = *(int*)pOldHeader->dwMapSeed;
                pOldHeader->dwChecksum = 0;
                pOldHeader->dwLasTime = 0;
                pOldHeader->dwPlayTime = 0;
                *(int*)pOldHeader->dwMapSeed = 0;
            }
            D2SaveHeaderStrc* pNewHeader = (D2SaveHeaderStrc*)(pData + 2);
            const unsigned int nNewVersion = pNewHeader->dwVersion;
            int nNewCheck = 0;
            int nNewLast = 0;
            int nNewPlay = 0;
            int nNewMap = 0;
            if (nNewVersion > 91)
            {
                nNewCheck = pNewHeader->dwChecksum;
                nNewLast = pNewHeader->dwLasTime;
                nNewPlay = pNewHeader->dwPlayTime;
                nNewMap = *(int*)pNewHeader->dwMapSeed;
                pNewHeader->dwChecksum = 0;
                pNewHeader->dwLasTime = 0;
                pNewHeader->dwPlayTime = 0;
                *(int*)pNewHeader->dwMapSeed = 0;
            }
            for (int i = 0; i < nOldSize; ++i)
            {
                if (((unsigned char*)pOldHeader)[i] != pData[i + 2])
                {
                    bMatching = 0;
                    break;
                }
            }
            if (nOldVersion > 91)
            {
                pOldHeader->dwChecksum = nOldCheck;
                pOldHeader->dwLasTime = nOldLast;
                pOldHeader->dwPlayTime = nOldPlay;
                *(int*)pOldHeader->dwMapSeed = nOldMap;
            }
            if (nNewVersion > 91)
            {
                pNewHeader->dwChecksum = nNewCheck;
                pNewHeader->dwLasTime = nNewLast;
                pNewHeader->dwPlayTime = nNewPlay;
                *(int*)pNewHeader->dwMapSeed = nNewMap;
            }
        }
        else bMatching = 0;
    }
    if (bMatching)
    {
        ++gnGlobal_00883D6C;
        if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdate)
        {
            gpD2EventCallbackTable_6FD45830->pfUpdate(&nClientInfo, szName, szAccountName);
        }
        sub_00539320(pClient, nClientInfo);
        return 0;
    }
    sub_00539320(pClient, nClientInfo);
    D2GAME_SetSaveFileChecksum_6FC33970(pClient, nChecksum);
    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfSave)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfSave), 0xADC);
        gpD2EventCallbackTable_6FD45830->pfSave(&nClientInfo, szName, szAccountName, pData, nTotalSize, nToken);
        CLIENTS_CopySaveDataToClient(pClient, pData + 2, nTotalSize - 2);
    }
    return 1;
}

// build: context sub_00532240_SaveToLocalFile

static __declspec(noinline) void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
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
    const int nFileSize = nSize;
    if (nFileSize > 0)
    {
        _iobuf* pFile = fopen(szFile, gszFileModeWb_006D69E0);
        if (pFile)
        {
            fwrite(pData, nFileSize, 1, pFile);
            fclose(pFile);
            return;
        }

        sub_00410610_WriteLogLine(gszSaveOpenError_006E09C4, szFile);
    }
}

// build: context sub_00532340_SaveToClient
static __declspec(noinline) void __stdcall sub_00532340_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
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
        sub_00532340_SaveToClient(bInteractsWithPlayer, pGame, pPlayer, pClient);
    }
    else if (gpD2EventCallbackTable_6FD45830)
    {
        nResult = sub_00531EB0_WriteFileOnRealm(pGame, pPlayer, szName, szAccountName, bInteractsWithPlayer, nToken, dwArg, nClientInfo);
    }
    else
    {
        sub_00532240_SaveToLocalFile(bInteractsWithPlayer, (dwArg), pGame, pPlayer, szName);
    }

    return nResult;
}
