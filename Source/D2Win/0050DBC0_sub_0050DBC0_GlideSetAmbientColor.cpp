extern unsigned char gnGlideAmbient_00880B58;                                                               // 0x00880B58
extern unsigned char gnGlideAmbient_00880B59;                                                               // 0x00880B59
extern unsigned char gnGlideAmbient_00880B5A;                                                               // 0x00880B5A

// 0x0050DBC0
void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue)
{
    gnGlideAmbient_00880B5A = nRed;
    gnGlideAmbient_00880B58 = nGreen;
    gnGlideAmbient_00880B59 = nBlue;
}
