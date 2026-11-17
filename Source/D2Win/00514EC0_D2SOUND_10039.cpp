struct D2CriticalSectionStrc { unsigned int opaque[6]; };

struct D2DSoundBufferStrc;

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    int unk0x04[6];
    int bPlaying;
    int unk0x20[5];
    unsigned int dwFlags;
    int f_38;
    int unk0x3C[3];
    void* hStream;
};

struct D2WaveStrc
{
    char szName[0x50];
    void* pData;
    unsigned int nSize;
    unsigned int nType;
    D2WaveStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

int __fastcall sub_005155D0_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize);       // 0x005155D0
int __fastcall sub_005156A0_PlaySound(D2SoundStrc* pSound);                                                 // 0x005156A0
int __fastcall sub_00515710_GetSoundPlaying(D2SoundStrc* pSound);                                           // 0x00515710
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140

D2CriticalSectionStrc gWaveLock_008817C4;                                                                   // 0x008817C4
extern D2SoundStrc* gapWaveSlots_008817DC[8];                                                               // 0x008817DC
extern int gbWaveSlotsInit_008817FC;                                                                        // 0x008817FC
extern D2WaveStrc* gpWaveList_00881800;                                                                     // 0x00881800

// 0x00514EC0
void __fastcall D2SOUND_10039(const char* szName)
{
    if (!gbWaveSlotsInit_008817FC)
        return;

    EnterCriticalSection(&gWaveLock_008817C4);

    D2WaveStrc* pWave = gpWaveList_00881800;
    if (gpWaveList_00881800)
    {
        int bFound = 0;
        for (; pWave; pWave = pWave->pNext)
        {
            if (!strcmp(pWave->szName, szName))
            {
                bFound = 1;
                break;
            }
        }

        if (bFound)
        {
        int i;
        for (i = 0; i < 8; ++i)
        {
            if (gapWaveSlots_008817DC[i]->dwFlags == pWave->nType && !sub_00515710_GetSoundPlaying(gapWaveSlots_008817DC[i]))
                break;
        }

        if (i < 8)
        {
            D2SoundStrc* pSound = gapWaveSlots_008817DC[i];
            sub_00516140_ResetSound(pSound);
            sub_005155D0_SetSoundData(pSound, pWave->pData, pWave->nSize);
            sub_005157B0_SetSoundVolume(pSound, 0xFF);
            sub_005156A0_PlaySound(pSound);
        }
        }
    }

    LeaveCriticalSection(&gWaveLock_008817C4);
}
