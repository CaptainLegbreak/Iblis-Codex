extern int gnDDrawOriginX_0088129C;                                                                         // 0x0088129C
int gnDDrawModeWidth_008812A0;                                                                              // 0x008812A0

// 0x00511DF0
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode)
{
    if (nResolutionMode == 0)
    {
        gnDDrawOriginX_0088129C = 0;
        gnDDrawModeWidth_008812A0 = 640;
    }
    else
    {
        gnDDrawOriginX_0088129C = 0;
        gnDDrawModeWidth_008812A0 = 800;
    }
}
