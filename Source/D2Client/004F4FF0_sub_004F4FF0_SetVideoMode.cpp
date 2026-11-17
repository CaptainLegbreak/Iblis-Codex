struct D2GraphicsInterfaceStrc;

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
extern D2GraphicsInterfaceStrc* gapGraphicsInterfaces_0072DA80[];                                           // 0x0072DA80

// 0x004F4FF0
int __fastcall sub_004F4FF0_SetVideoMode(int nMode)
{
    D2GraphicsInterfaceStrc* pInterface = gapGraphicsInterfaces_0072DA80[nMode];
    if (!pInterface)
    {
        sub_00410610_WriteLogLine("Unsupported video mode - %d", nMode);
        return 0;
    }
    gpGraphicsInterface = pInterface;
    return 1;
}

#include "gen/data/Source/D2Client/004F4FF0_sub_004F4FF0_SetVideoMode.inc"
