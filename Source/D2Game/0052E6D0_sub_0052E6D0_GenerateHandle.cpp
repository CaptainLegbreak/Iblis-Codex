typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0xC];
    unsigned short nGameId;
    char unk0x2A[0x46];
    int bExpansion;
    char f_74[0x1C];
    int dwLastUsedUnitGUID[6];
    int dwGameFrame;
};

struct D2HashKeyNoneStrc
{
    char unk0x00;
};

struct D2GameDataTableStrc
{
    char unk0x00[0x44];
    D2HashKeyNoneStrc f_44;
    char unk0x45[0x3];
    unsigned int nSequence;
    int bWrapped;
    D2CriticalSectionStrc f_50;

    void DeleteUnlock(D2GameStrc* pGame, int nLockHandle);                                                  // 0x0052E5D0
    D2GameStrc* Ptr(unsigned int nHashValue, const D2HashKeyNoneStrc* pKey);                                // 0x0052E650
    unsigned int sub_0052E6D0_GenerateHandle();

    D2GameStrc* LockInline(unsigned int nHashValue, int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&f_50);
        *pLockHandle = bForWriting ? 1 : -1;
        D2GameStrc* pGame = Ptr(nHashValue, &f_44);
        if (!pGame)
        {
            if (*pLockHandle)
            {
                LeaveCriticalSection(&f_50);
            }
            *pLockHandle = 0;
        }
        return pGame;
    }
};

struct D2ServerCallbackFunctions
{
    void (__fastcall* pfCloseGame)(int nGameId, int nProgramId, int nLastUnitGUID, int nSeconds);
};

void __fastcall GAME_FreeGame(int nGameGUID, D2GameStrc* pGame);                                            // 0x0052C7F0

D2GameDataTableStrc* gpGameDataTbl_6FD45818;                                                                // 0x00883D38
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50

// 0x0052E6D0
unsigned int D2GameDataTableStrc::sub_0052E6D0_GenerateHandle()
{
    while (1)
    {
        nSequence += 1;
        if (!nSequence)
        {
            bWrapped = 1;
            continue;
        }

        if (!bWrapped)
        {
            return nSequence;
        }

        if (!Ptr(nSequence, &f_44))
        {
            return nSequence;
        }
    }
}

// 0x0052E770
void __fastcall GAME_CloseGame(int nGameGUID)
{
    if (gpGameDataTbl_6FD45818)
    {
        int hLock;
        D2GameStrc* pGame = gpGameDataTbl_6FD45818->LockInline(nGameGUID, &hLock, 0);
        if (pGame)
        {
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfCloseGame)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfCloseGame), 0x107C);
                gpD2EventCallbackTable_6FD45830->pfCloseGame(pGame->nGameId, pGame->bExpansion ? 0x44325850 : 0x44324456, pGame->dwLastUsedUnitGUID[UNIT_PLAYER], pGame->dwGameFrame / 25);
            }

            D2_ASSERT(pGame->lpCriticalSection, 0x108D);
            EnterCriticalSection(pGame->lpCriticalSection);

            GAME_FreeGame(nGameGUID, pGame);

            gpGameDataTbl_6FD45818->DeleteUnlock(pGame, hLock);
        }
    }
}

// 0x0052E860
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return 0;
    }

    int hLock;
    D2GameStrc* pGame = gpGameDataTbl_6FD45818->LockInline(nGameGUID, &hLock, 1);
    if (pGame)
    {
        D2_ASSERT(pGame->lpCriticalSection, 0x1181);
        EnterCriticalSection(pGame->lpCriticalSection);
        if (hLock)
        {
            LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);
        }
    }
    return pGame;
}
