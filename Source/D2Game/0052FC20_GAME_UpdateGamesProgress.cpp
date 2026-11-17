extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

union D2LargeIntegerUnion
{
    struct
    {
        unsigned long LowPart;
        long HighPart;
    };
    __int64 QuadPart;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerUnion* pCount);        // 0x006CC25C
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);                                // 0x006CC544

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0x1D9C];
    unsigned int nLastUpdateSystemTimeMs;
    unsigned int nCreationTimeMs_Or_CPUTargetRatioFP10;
};

extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
int dword_6FD45844;                                                                                         // 0x00883D58
int gnTargetMsPerFrame_6FD457F8;                                                                            // 0x00883D60
extern int dword_6FD2CA10;                                                                                  // 0x0073100C

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame);                                                     // 0x0052D870
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860

// 0x0052FC20
int __stdcall GAME_UpdateGamesProgress(int a1)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const int nSysTimeMs = timeGetTime() & 0x7FFFFFFF;
    if (!dword_6FD45844)
    {
        dword_6FD45844 = nSysTimeMs;
    }

    const int nElapsed = nSysTimeMs - dword_6FD45844;
    if (nElapsed < gnTargetMsPerFrame_6FD457F8)
    {
        return 0;
    }

    unsigned int nLate = nElapsed - gnTargetMsPerFrame_6FD457F8;
    if (a1 && nLate >= gnTargetMsPerFrame_6FD457F8)
    {
        nLate = gnTargetMsPerFrame_6FD457F8;
    }

    dword_6FD45844 = nSysTimeMs - nLate;

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* pGame = GAME_LockGame(nGUID))
            {
                bQueryPerformance = 1;

                if (!dword_6FD2CA10)
                {
                    if (pGame->nLastUpdateSystemTimeMs)
                    {
                        pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = ((nSysTimeMs - pGame->nLastUpdateSystemTimeMs) << 10) / gnTargetMsPerFrame_6FD457F8;
                        if (pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 < 10)
                        {
                            pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 10;
                        }
                        else if (pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 > 0x800)
                        {
                            pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x800;
                        }
                    }

                    pGame->nLastUpdateSystemTimeMs = nSysTimeMs;
                }
                else
                {
                    pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x400;
                }

                GAME_UpdateProgress(pGame);

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}

#include "gen/data/Source/D2Game/0052FC20_GAME_UpdateGamesProgress.inc"
