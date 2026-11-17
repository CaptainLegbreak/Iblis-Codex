#ifdef MOVED_TEST
#define BUCKETS 132
#define INFO_DESCRIPTION_SIZE 40
#define GAME_ID_BIAS 3
#define UNLOCK_LINE 4200
#else
#define BUCKETS 128
#define INFO_DESCRIPTION_SIZE 16
#define GAME_ID_BIAS 1
#define UNLOCK_LINE 4196
#endif
struct D2UnitStrc;
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct D2GameStrc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    char unk0x0000[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x001C[0x1104];
    D2UnitStrc* pUnitList[5][BUCKETS];
};

struct D2UnitInfoStrc
{
    int nUnitType;
    int nClassId;
    int nUnitGUID;
    int nAnimMode;
    int nX;
    int nY;
    int nOwnerType;
    int nOwnerGUID;
    int unk0x20;
    char szDescription[INFO_DESCRIPTION_SIZE];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pUnitInfo);                           // 0x00553F30
extern D2CriticalSectionStrc gCriticalSection_6FD45800;  // 0x00882D18
extern int gnGamesGUIDs_6FD447F8[1024];  // 0x00882D38
// 0x0052F080
int __stdcall sub_0052F080_GetPlayerUnitInfo(unsigned short nGameId, D2UnitInfoStrc* pUnitInfo, int nMaxCount)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS] && gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS] != -1)
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS];
    LeaveCriticalSection(&gCriticalSection_6FD45800);
    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nCount = 0;
    if (pGame)
    {
        for (int i = 0; i < BUCKETS; ++i)
        {
            if (nCount >= nMaxCount) break;
            for (D2UnitStrc* pUnit = pGame->pUnitList[0][i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                if (nCount >= nMaxCount) break;
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nCount]);
                ++nCount;
            }
        }
        D2_ASSERT(pGame->lpCriticalSection, UNLOCK_LINE);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }
    return nCount;
}
