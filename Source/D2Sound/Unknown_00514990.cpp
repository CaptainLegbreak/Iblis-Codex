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

static int gnChannelCountA_0072F874;                                                                        // 0x0072F874
extern D2SoundChannelEntryStrc gaChannelTableA_0072F878[8];                                                 // 0x0072F878
extern D2SoundChannelEntryStrc gaChannelTableB_0072F8B8[8];                                                 // 0x0072F8B8
extern int gnChannelCountB_0072F8F8;                                                                        // 0x0072F8F8
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
static D2SoundStrc* gpSoundChannel_00881794;                                                                // 0x00881794
extern int gnChannelValue_00881798;                                                                         // 0x00881798
extern int gbChannelFlag_0088179C;                                                                          // 0x0088179C
extern int gnChannelTableSel_008817A4;                                                                      // 0x008817A4
extern int gbChannelTableInit_008817A8;                                                                     // 0x008817A8

// 0x005147D0
int __fastcall D2SOUND_PlayStreamChannel(const char* szFile, int bLoop)
{
    if (gpSoundChannel_00881794 && D2SOUND_GetMasterVolume() && !D2SOUND_IsSoundStreaming(gpSoundChannel_00881794) && szFile)
    {
        D2SOUND_ResetSound(gpSoundChannel_00881794);
        D2SOUND_SetSoundVolume(gpSoundChannel_00881794, 0x6E);
        if (D2SOUND_StartSoundStream(gpSoundChannel_00881794, szFile, 0, bLoop))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00514840
int __cdecl D2SOUND_IsStreamChannelPlaying()
{
    if (gpSoundChannel_00881794 && D2SOUND_IsSoundStreaming(gpSoundChannel_00881794))
        return 1;
    return 0;
}

__declspec(noinline) static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex);
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex); // 0x00514710

// 0x00514710
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit_008817A8)
    {
        gbChannelTableInit_008817A8 = 1;
        gnChannelTableSel_008817A4 = D2SOUND_IsExpansion();
    }
    D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA_0072F874, 0x53);
    if (gnChannelTableSel_008817A4)
        return &gaChannelTableB_0072F8B8[nIndex];
    return &gaChannelTableA_0072F878[nIndex];
}

// 0x00514990
int __cdecl sub_00514990_PickRandomChannel()
{
    D2SoundChannelEntryStrc* pEntry;
    const char* szFile;
    int nIndex;
    int bCleared;

    EnterCriticalSection(&gSoundLock_0088174C);
    if (!gpSoundChannel_00881794 || !D2SOUND_GetMasterVolume() || D2SOUND_IsStreamChannelPlaying())
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }

    bCleared = 0;
    for (;;)
    {
        for (nIndex = 0; nIndex < gnChannelCountA_0072F874; ++nIndex)
        {
            pEntry = sub_00514710_GetChannelEntry(nIndex);
            if (!pEntry->bBusy)
                goto found;
        }
        if (bCleared)
        {
            gnChannelValue_00881798 = 0;
            LeaveCriticalSection(&gSoundLock_0088174C);
            return 0;
        }
        D2SOUND_ClearChannelTable();
        ++bCleared;

    found:
        if (gbChannelFlag_0088179C)
        {
            pEntry = sub_00514710_GetChannelEntry(0);
            gbChannelFlag_0088179C = 0;
        }
        else
        {
            nIndex = rand() % gnChannelCountA_0072F874;
            for (;;)
            {
                if (!gbChannelTableInit_008817A8)
                {
                    gbChannelTableInit_008817A8 = 1;
                    gnChannelTableSel_008817A4 = D2SOUND_IsExpansion();
                }
                D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
                D2_ASSERT(nIndex < gnChannelCountA_0072F874, 0x53);
                if (gnChannelTableSel_008817A4)
                    pEntry = &gaChannelTableB_0072F8B8[nIndex];
                else
                    pEntry = &gaChannelTableA_0072F878[nIndex];
                if (!pEntry->bBusy)
                    break;
                if (++nIndex >= gnChannelCountA_0072F874)
                    nIndex = 0;
            }
        }

        szFile = pEntry->szFile;
        pEntry->bBusy = 1;
        if (D2SOUND_PlayStreamChannel(szFile, 0))
        {
            LeaveCriticalSection(&gSoundLock_0088174C);
            return 1;
        }
    }
}
