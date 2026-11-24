#include "D2Sound.h"

extern int gnNpcSpeech;                                                                              // 0x008817BC

extern int gdwGlobal_008817AC; // 0x008817AC
extern int gnMasterVolume; // 0x008817B0
extern int gdwGlobal_008817B4; // 0x008817B4
extern int gnPositionalBias; // 0x008817B8
extern int gdwGlobal_008817C0; // 0x008817C0

// 0x00514C90
int __cdecl D2SOUND_GetSoundMixerOption()
{
    return gdwGlobal_008817AC;
}

// 0x00514CC0
int __cdecl D2SOUND_GetMasterVolumeOption()
{
    return gnMasterVolume;
}

// 0x00514CF0
int __cdecl D2SOUND_GetMusicVolumeOption()
{
    return gdwGlobal_008817B4;
}

// 0x00514D20
int __cdecl D2SOUND_GetPositionalBiasOption()
{
    return gnPositionalBias;
}

// 0x00514D50
int __cdecl D2SOUND_GetNpcSpeechOption()
{
    return gnNpcSpeech;
}

// 0x00514D60
int __fastcall sub_00514D60_SetNpcSpeech(int nValue)
{
    SRegSaveValue("Diablo II", "NPC Speech", 0, nValue);
    gnNpcSpeech = nValue;
    return nValue;
}

// 0x00514D80
int __cdecl D2SOUND_GetOptionsMusicOption()
{
    return gdwGlobal_008817C0;
}
