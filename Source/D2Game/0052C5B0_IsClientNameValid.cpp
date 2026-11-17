typedef int (__stdcall* FARPROC)();

struct D2ServerCallbackFunctions
{
    void* pfCloseGame;
    void* pfLeaveGame;
    void* pfGetDatabaseCharacter;
    void* pfSaveDatabaseCharacter;
    void* pfServerLogMessage;
    void* pfEnterGame;
    int (__fastcall* pfFindPlayerToken)(const char* szClientName, int nTokenId, int nGameId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, int* a6, int* a7, int* a8, int* a9);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId);                                          // 0x0052C060
int __fastcall sub_6FC33EA0(int nClientId, char* szName);                                                   // 0x00538B70
int __fastcall sub_6FC33F90(const char* szName, char* szGameName);                                          // 0x00538C60
int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize);                               // 0x0053EFC0

extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50

// 0x0052C5B0
static int IsClientNameValid(const char* szClientName, int nLength)
{
    int bContainsSpecialCharacter = 0;
    for (int i = 0; i < nLength; ++i)
    {
        switch (*szClientName++)
        {
        case '\'':
        case '-':
        case '_':
            if (bContainsSpecialCharacter || i == 0 || *szClientName == '\0')
            {
                return 0;
            }
            bContainsSpecialCharacter = 1;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I':
        case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i':
        case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
        case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            break;
        case '\0':
            return i != 0;
        default:
            return 0;
        }
    }
    return 0;
}

// 0x0052C690
int __fastcall GAME_VerifyJoinGame(int nClientId, unsigned short nGameId, unsigned char nPlayerClass, const char* szClientName, int nTokenId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, unsigned char nLocale, int* a9, int* a10, int* a11, int* a12, int a13)
{
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (nLocale >= 14)
    {
        return 0;
    }
    char szGameName[16];
    if (!sub_6FC33EA0(nClientId, szGameName))
    {
        return 0;
    }
    if (!sub_6FC33F90(szClientName, szGameName))
    {
        return 0;
    }
    if (!GAME_GetGameGUIDFromGameId(nGameId))
    {
        return 0;
    }
    if (nPlayerClass >= 7)
    {
        return 0;
    }
    if (!IsClientNameValid(szClientName, 16))
    {
        return 0;
    }
    if (gpD2EventCallbackTable_6FD45830)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfFindPlayerToken), 1883);
        if (!gpD2EventCallbackTable_6FD45830->pfFindPlayerToken(szClientName, nTokenId, nGameId, pszInOutAccountName, pOutCharSaveTransactionToken, a9, a10, a11, a12))
        {
            return 0;
        }
    }
    return 1;
}
