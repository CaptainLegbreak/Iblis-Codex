#include "D2Sound.h"
#include "D2SoundTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2SoundStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" int __cdecl rand();                                                                              // 0x00687461
void __cdecl sub_00514860_ClearChannelTable();                                                               // 0x00514860
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
int __cdecl sub_00515D60_GetMasterVolume();                                                                  // 0x00515D60
int __fastcall sub_00515D70_StartStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140
extern D2SoundChannelEntryStrc gaChannelTableA_0072F878[8];                                                 // 0x0072F878
extern D2SoundChannelEntryStrc gaChannelTableB_0072F8B8[8];                                                 // 0x0072F8B8
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
extern D2SoundStrc* gpSoundChannel_00881794;                                                                // 0x00881794
extern int gnChannelValue_00881798;                                                                         // 0x00881798
extern int gbChannelFlag_0088179C;                                                                          // 0x0088179C
extern int gnChannelTableSel_008817A4;                                                                      // 0x008817A4
extern int gbChannelTableInit_008817A8;                                                                     // 0x008817A8

// 0x00514710
static D2SoundChannelEntryStrc* sub_00514710_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit_008817A8)
    {
        gbChannelTableInit_008817A8 = 1;
        gnChannelTableSel_008817A4 = sub_00513AE0();
    }
    D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA_0072F874, 0x53);
    if (gnChannelTableSel_008817A4)
        return &gaChannelTableB_0072F8B8[nIndex];
    return &gaChannelTableA_0072F878[nIndex];
}

int __cdecl sub_00514990_PickRandomChannel()
{
    EnterCriticalSection(&gSoundLock_0088174C);
    if (!gpSoundChannel_00881794 || !sub_00515D60_GetMasterVolume() || (gpSoundChannel_00881794 && sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794)))
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }

    int bCleared = 0;
    for (;;)
    {
        for (int i = 0; i < gnChannelCountA_0072F874; ++i)
        {
            if (!sub_00514710_GetChannelEntry(i)->bBusy)
                goto found;
        }
        if (bCleared)
        {
            gnChannelValue_00881798 = 0;
            LeaveCriticalSection(&gSoundLock_0088174C);
            return 0;
        }
        sub_00514860_ClearChannelTable();
        bCleared = 1;

    found:
        D2SoundChannelEntryStrc* pEntry;
        if (gbChannelFlag_0088179C)
        {
            pEntry = sub_00514710_GetChannelEntry(0);
            gbChannelFlag_0088179C = 0;
        }
        else
        {
            int n = rand() % gnChannelCountA_0072F874;
            for (;;)
            {

                if (!gbChannelTableInit_008817A8)
                {
                    gbChannelTableInit_008817A8 = 1;
                    gnChannelTableSel_008817A4 = sub_00513AE0();
                }
                D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
                D2_ASSERT(n < gnChannelCountA_0072F874, 0x53);
                if (gnChannelTableSel_008817A4)
                    pEntry = &gaChannelTableB_0072F8B8[n];
                else
                    pEntry = &gaChannelTableA_0072F878[n];
                if (!pEntry->bBusy)
                    break;
                if (++n >= gnChannelCountA_0072F874)
                    n = 0;
            }
        }

        const char* szFile = pEntry->szFile;
        pEntry->bBusy = 1;
        if (!gpSoundChannel_00881794 || !sub_00515D60_GetMasterVolume() || sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794) || !szFile)
            continue;

        sub_00516140_ResetSound(gpSoundChannel_00881794);
        sub_005157B0_SetSoundVolume(gpSoundChannel_00881794, 0x6E);
        if (!sub_00515D70_StartStream(gpSoundChannel_00881794, szFile, 0, 0))
            continue;

        LeaveCriticalSection(&gSoundLock_0088174C);
        return 1;
    }
}

#include "gen/data/Source/D2Sound/Unknown_00514710.inc"
