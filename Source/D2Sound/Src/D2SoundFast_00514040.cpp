#include "D2Sound.h"

struct D2SoundStrc;
int __cdecl sub_00515D60_GetMasterVolume();                                                                  // 0x00515D60
int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound);                                                // 0x00516140
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
int __fastcall sub_00515D70_StartStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0

D2SoundStrc* gpSoundChannel_00881794;                                                                       // 0x00881794
extern int gdwGlobal_008817B0;                                                                              // 0x008817B0
extern int gdwGlobal_008817B8;                                                                              // 0x008817B8
extern D2SoundStrc* gapWaveSlots_008817DC[8];                                                               // 0x008817DC
extern int gbWaveSlotsInit_008817FC;                                                                        // 0x008817FC

// 0x00514040
void __cdecl sub_00514040_Nothing()
{
}

// 0x00514050
void __cdecl sub_00514050_Nothing()
{
}

// 0x005147D0
int __fastcall sub_005147D0_PlayStream(const char* szFile, int bLoop)
{
    if (gpSoundChannel_00881794 && sub_00515D60_GetMasterVolume() && !sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794) && szFile)
    {
        sub_00516140_ResetSound(gpSoundChannel_00881794);
        sub_005157B0_SetSoundVolume(gpSoundChannel_00881794, 0x6E);
        if (sub_00515D70_StartStream(gpSoundChannel_00881794, szFile, 0, bLoop))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00514CD0
int __fastcall sub_00514CD0_SetMasterVolume(int nValue)
{
    SRegSaveValue("Diablo II", "Master Volume", 0, nValue);
    gdwGlobal_008817B0 = nValue;
    return nValue;
}

// 0x00514D30
int __fastcall sub_00514D30_SetPositionalBias(int nValue)
{
    SRegSaveValue("Diablo II", "Positional Bias", 0, nValue);
    gdwGlobal_008817B8 = nValue;
    return nValue;
}

// 0x00514FF0
void __cdecl sub_00514FF0_StopAllWaves()
{
    if (gbWaveSlotsInit_008817FC)
    {
        for (int i = 0; i < 8; ++i)
        {
            sub_00515EE0_StopSound(gapWaveSlots_008817DC[i]);
        }
    }
}
