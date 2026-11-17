#include "D2Client.h"

int gdwGlobal_007A277C;                                                                                     // 0x007A277C
extern int gdwGlobal_007A2784;                                                                              // 0x007A2784
int gnRecordInitSeed_007A2778;                                                                              // 0x007A2778

void __cdecl sub_00451710_ReadRecordFile();                                                                 // 0x00451710

// 0x004518E0
void __cdecl sub_004518E0_StartPlayback()
{
    if (gdwGlobal_007A277C)
        gdwGlobal_007A277C = 0;
    else
    {
        gdwGlobal_007A2784 = 1;
        sub_00451710_ReadRecordFile();
        GAME_SetInitSeed(gnRecordInitSeed_007A2778);
    }
}
