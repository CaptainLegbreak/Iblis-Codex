void* gpOwner_00779324;                                                                                     // 0x00779324
extern char gaTable_0070896C[];                                                                             // 0x0070896C

// 0x0042E590
void* __fastcall sub_0042E590_SetOwner(void* pOwner)
{
    gpOwner_00779324 = pOwner;
    return gaTable_0070896C;
}

#include "gen/data/Source/Storm/0042E590_sub_0042E590_SetOwner.inc"
