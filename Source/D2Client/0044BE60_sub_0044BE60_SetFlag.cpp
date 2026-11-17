typedef void (__fastcall* D2ClientCallbackFn)(void* pArg);

void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0
int __stdcall sub_00420320_RegisterHandlers(void* pContext);                                                // 0x00420320

extern int gdwGlobal_007A065C;                                                                              // 0x007A065C
int gnClientState_007A0480;                                                                                 // 0x007A0480
extern D2ClientCallbackFn gpfnClientCallback_007A0484;                                                      // 0x007A0484
extern D2ClientCallbackFn gpfnClientCallbacks_0070EF0C[3];                                                  // 0x0070EF0C
int gdwGlobal_007A2784;                                                                                     // 0x007A2784
extern int gdwGlobal_007A277C;                                                                              // 0x007A277C

// 0x0044BE60
void __fastcall sub_0044BE60_SetFlag(int nValue)
{
    gdwGlobal_007A065C = nValue;
}

// 0x0044C930
void __fastcall sub_0044C930_SetClientState(int nState)
{
    gnClientState_007A0480 = nState;
    gpfnClientCallback_007A0484 = gpfnClientCallbacks_0070EF0C[nState];
}

// 0x004519A0
void __cdecl sub_004519A0_ToggleFlags()
{
    if (gdwGlobal_007A2784)
        gdwGlobal_007A2784 = 0;
    else
        gdwGlobal_007A277C = 1;
}

// 0x00451F20
void __cdecl sub_00451F20_RegisterWindowHandlers()
{
    sub_00420320_RegisterHandlers(sub_004F59A0());
}

#include "gen/data/Source/D2Client/0044BE60_sub_0044BE60_SetFlag.inc"
