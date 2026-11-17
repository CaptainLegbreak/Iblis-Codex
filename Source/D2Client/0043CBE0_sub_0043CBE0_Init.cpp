struct D2ModuleInterfaceStrc;

void* gpInstance_0077AD68;                                                                                  // 0x0077AD68
extern D2ModuleInterfaceStrc gtInterface_0070CD14;                                                          // 0x0070CD14

// 0x0043CBE0
D2ModuleInterfaceStrc* __fastcall sub_0043CBE0_Init(void* hInstance)
{
    gpInstance_0077AD68 = hInstance;
    return &gtInterface_0070CD14;
}

#include "gen/data/Source/D2Client/0043CBE0_sub_0043CBE0_Init.inc"
