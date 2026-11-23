#include "D2GameTypes.h"
#include "D2SoundTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SoundStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" int __cdecl rand();                                                                              // 0x00687461
int __cdecl D2SOUND_IsExpansion();                                                                                  // 0x00513AE0
void __cdecl D2SOUND_ClearChannelTable();                                                               // 0x00514860
void __fastcall D2SOUND_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
int __fastcall D2SOUND_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
int __cdecl D2SOUND_GetMasterVolume();                                                                  // 0x00515D60
int __fastcall D2SOUND_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall D2SOUND_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140

static int gnChannelCountA;                                                                        // 0x0072F874
extern D2SoundChannelEntryStrc gaChannelTableA[8];                                                 // 0x0072F878
extern D2SoundChannelEntryStrc gaChannelTableB[8];                                                 // 0x0072F8B8
extern int gnChannelCountB;                                                                        // 0x0072F8F8
extern D2CriticalSectionStrc gtSoundLock;                                                           // 0x0088174C
static D2SoundStrc* gpSoundChannel;                                                                // 0x00881794
extern int gnChannelValue;                                                                         // 0x00881798
extern int gbChannelFlag;                                                                          // 0x0088179C
extern int gnChannelTableSel;                                                                      // 0x008817A4
extern int gbChannelTableInit;                                                                     // 0x008817A8

// 0x005147D0
int __fastcall D2SOUND_PlayStreamChannel(const char* szFile, int bLoop)
{
    if (gpSoundChannel && D2SOUND_GetMasterVolume() && !D2SOUND_IsSoundStreaming(gpSoundChannel) && szFile)
    {
        D2SOUND_ResetSound(gpSoundChannel);
        D2SOUND_SetSoundVolume(gpSoundChannel, 0x6E);
        if (D2SOUND_StartSoundStream(gpSoundChannel, szFile, 0, bLoop))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00514840
int __cdecl D2SOUND_IsStreamChannelPlaying()
{
    if (gpSoundChannel && D2SOUND_IsSoundStreaming(gpSoundChannel))
        return 1;
    return 0;
}

__declspec(noinline) static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex);
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex); // 0x00514710

// 0x00514710
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit)
    {
        gbChannelTableInit = 1;
        gnChannelTableSel = D2SOUND_IsExpansion();
    }
    D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA, 0x53);
    if (gnChannelTableSel)
        return &gaChannelTableB[nIndex];
    return &gaChannelTableA[nIndex];
}

// 0x00514990
int __cdecl sub_00514990_PickRandomChannel()
{
    D2SoundChannelEntryStrc* pEntry;
    const char* szFile;
    int nIndex;
    int bCleared;

    EnterCriticalSection(&gtSoundLock);
    if (!gpSoundChannel || !D2SOUND_GetMasterVolume() || D2SOUND_IsStreamChannelPlaying())
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }

    bCleared = 0;
    for (;;)
    {
        for (nIndex = 0; nIndex < gnChannelCountA; ++nIndex)
        {
            pEntry = sub_00514710_GetChannelEntry(nIndex);
            if (!pEntry->bBusy)
                goto found;
        }
        if (bCleared)
        {
            gnChannelValue = 0;
            LeaveCriticalSection(&gtSoundLock);
            return 0;
        }
        D2SOUND_ClearChannelTable();
        ++bCleared;

    found:
        if (gbChannelFlag)
        {
            pEntry = sub_00514710_GetChannelEntry(0);
            gbChannelFlag = 0;
        }
        else
        {
            nIndex = rand() % gnChannelCountA;
            for (;;)
            {
                if (!gbChannelTableInit)
                {
                    gbChannelTableInit = 1;
                    gnChannelTableSel = D2SOUND_IsExpansion();
                }
                D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
                D2_ASSERT(nIndex < gnChannelCountA, 0x53);
                if (gnChannelTableSel)
                    pEntry = &gaChannelTableB[nIndex];
                else
                    pEntry = &gaChannelTableA[nIndex];
                if (!pEntry->bBusy)
                    break;
                if (++nIndex >= gnChannelCountA)
                    nIndex = 0;
            }
        }

        szFile = pEntry->szFile;
        pEntry->bBusy = 1;
        if (D2SOUND_PlayStreamChannel(szFile, 0))
        {
            LeaveCriticalSection(&gtSoundLock);
            return 1;
        }
    }
}
