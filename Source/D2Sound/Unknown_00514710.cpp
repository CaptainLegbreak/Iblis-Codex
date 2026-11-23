#include "D2Sound.h"
#include "D2SoundTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2SoundStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" int __cdecl rand();                                                                              // 0x00687461
void __cdecl D2SOUND_ClearChannelTable();                                                               // 0x00514860
void __fastcall D2SOUND_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
int __fastcall D2SOUND_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
int __cdecl D2SOUND_GetMasterVolume();                                                                  // 0x00515D60
int __fastcall D2SOUND_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall D2SOUND_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140
extern D2SoundChannelEntryStrc gaChannelTableA[8];                                                 // 0x0072F878
extern D2SoundChannelEntryStrc gaChannelTableB[8];                                                 // 0x0072F8B8
extern D2CriticalSectionStrc gtSoundLock;                                                           // 0x0088174C
extern D2SoundStrc* gpSoundChannel;                                                                // 0x00881794
extern int gnChannelValue;                                                                         // 0x00881798
extern int gbChannelFlag;                                                                          // 0x0088179C
extern int gnChannelTableSel;                                                                      // 0x008817A4
extern int gbChannelTableInit;                                                                     // 0x008817A8

// 0x00514710
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit)
    {
        gbChannelTableInit = 1;
// build: symbol ?D2SOUND_IsExpansion@* 0x00513AE0
        gnChannelTableSel = D2SOUND_IsExpansion();
    }
// build: symbol ?gnChannelCountA@* 0x0072F874
// build: symbol ?gnChannelCountB@* 0x0072F8F8
    D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA, 0x53);
    if (gnChannelTableSel)
        return &gaChannelTableB[nIndex];
    return &gaChannelTableA[nIndex];
}

int __cdecl sub_00514990_PickRandomChannel()
{
    EnterCriticalSection(&gtSoundLock);
    if (!gpSoundChannel || !D2SOUND_GetMasterVolume() || (gpSoundChannel && D2SOUND_IsSoundStreaming(gpSoundChannel)))
    {
        LeaveCriticalSection(&gtSoundLock);
        return 0;
    }

    int bCleared = 0;
    for (;;)
    {
        for (int i = 0; i < gnChannelCountA; ++i)
        {
            if (!sub_00514710_GetChannelEntry(i)->bBusy)
                goto found;
        }
        if (bCleared)
        {
            gnChannelValue = 0;
            LeaveCriticalSection(&gtSoundLock);
            return 0;
        }
        D2SOUND_ClearChannelTable();
        bCleared = 1;

    found:
        D2SoundChannelEntryStrc* pEntry;
        if (gbChannelFlag)
        {
            pEntry = sub_00514710_GetChannelEntry(0);
            gbChannelFlag = 0;
        }
        else
        {
            int n = rand() % gnChannelCountA;
            for (;;)
            {

                if (!gbChannelTableInit)
                {
                    gbChannelTableInit = 1;
                    gnChannelTableSel = D2SOUND_IsExpansion();
                }
                D2_ASSERT(gnChannelCountA == gnChannelCountB, 0x52);
                D2_ASSERT(n < gnChannelCountA, 0x53);
                if (gnChannelTableSel)
                    pEntry = &gaChannelTableB[n];
                else
                    pEntry = &gaChannelTableA[n];
                if (!pEntry->bBusy)
                    break;
                if (++n >= gnChannelCountA)
                    n = 0;
            }
        }

        const char* szFile = pEntry->szFile;
        pEntry->bBusy = 1;
        if (!gpSoundChannel || !D2SOUND_GetMasterVolume() || D2SOUND_IsSoundStreaming(gpSoundChannel) || !szFile)
            continue;

        D2SOUND_ResetSound(gpSoundChannel);
        D2SOUND_SetSoundVolume(gpSoundChannel, 0x6E);
        if (!D2SOUND_StartSoundStream(gpSoundChannel, szFile, 0, 0))
            continue;

        LeaveCriticalSection(&gtSoundLock);
        return 1;
    }
}

#include "gen/data/Source/D2Sound/Unknown_00514710.inc"
