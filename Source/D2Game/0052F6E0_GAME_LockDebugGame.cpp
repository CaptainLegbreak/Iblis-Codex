extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2GameReservedSlotHandle (-1)

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0xC];
    unsigned short nGameId;
    char szGameName[16];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
int __stdcall SERVER_GetClientGameGUID(int nClientId);                                                      // 0x0052B610
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId);                         // 0x005381C0

extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern D2GameStrc* gpGame_6FD457FC;                                                                         // 0x00882D34
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38

// 0x0052F6E0
D2GameStrc* __fastcall GAME_LockDebugGame()
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);

    if (*gnGamesGUIDs_6FD447F8 && *gnGamesGUIDs_6FD447F8 != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs_6FD447F8;
    }

    LeaveCriticalSection(&gCriticalSection_6FD45800);

    gpGame_6FD457FC = GAME_LockGame(nGUID);
    return gpGame_6FD457FC;
}

// 0x0052F8B0
int __fastcall sub_0052F8B0_IsGameNameUnused(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            if (pGame)
            {
                if (!SStrCmpI(szGameName, pGame->szGameName, 16))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return 0;
                }

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 1;
}

// 0x0052FEE0
D2GameStrc* __fastcall GAME_GetGameByClientId(int nClientId)
{
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);

    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (!pGame)
    {
        return 0;
    }

    if (sub_005381C0(pGame, nClientId))
    {
        return pGame;
    }

    GAME_LeaveGamesCriticalSection(pGame);

    return 0;
}
