struct D2SoundStrc;

int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0

extern D2SoundStrc* gpSoundChannel_00881794;                                                                // 0x00881794
extern int gnChannelValue_00881798;                                                                         // 0x00881798

// 0x00514930
void __cdecl sub_00514930_StopChannel()
{
    if (gpSoundChannel_00881794)
    {
        gnChannelValue_00881798 = 0;
        if (sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794))
            sub_00515EE0_StopSound(gpSoundChannel_00881794);
    }
}
