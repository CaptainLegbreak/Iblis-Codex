#include "D2Client.h"

void* ghAccelerators;                                                                                    // 0x007A0708
extern void* ghLngModule;                                                                          // 0x007A070C

// 0x00451290
void __cdecl sub_00451290_FreeLngModule()
{
    if (ghLngModule)
        FreeLibrary(ghLngModule);
    ghLngModule = 0;
    ghAccelerators = 0;
}
