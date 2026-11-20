#include "D2Hell.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837

int __fastcall sub_004068F0(void* pArg); // 0x004068F0

// 0x00516E84
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* hFile)
{
    if (!hFile)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 73);
        exit(-1);
    }

    sub_004068F0(hFile);
}
