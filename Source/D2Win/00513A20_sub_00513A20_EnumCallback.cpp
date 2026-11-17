extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern int gdwGlobal_0072F830;                                                                              // 0x0072F830
int gbSoundEnumDone_00881780;                                                                               // 0x00881780
extern int gbCheckEmu10k1_00881788;                                                                         // 0x00881788
int gbCheckCrlds3d_0088178C;                                                                                // 0x0088178C

// 0x00513A20
int __stdcall sub_00513A20_EnumCallback(void* pGuid, const char* szDescription, const char* szModule, void* pContext)
{
    if (pGuid && !gbSoundEnumDone_00881780)
    {
        if (!strcmp(szModule, "EMU10K1.VXD"))
            gbCheckEmu10k1_00881788 = 1;
        if (!strcmp(szModule, "es197x.vxd"))
            gbCheckCrlds3d_0088178C = 1;
        if (!strcmp(szDescription, "Crystal SoundFusion(tm)"))
            gbCheckCrlds3d_0088178C = 1;
        if (!strcmp(szModule, "YDSXG.VXD"))
            gdwGlobal_0072F830 = 0;
        if (!strcmp(szModule, "RIPTIDE.VXD"))
            gdwGlobal_0072F830 = 0;
        gbSoundEnumDone_00881780 = 1;
    }
    return 1;
}

#include "gen/data/Source/D2Win/00513A20_sub_00513A20_EnumCallback.inc"
