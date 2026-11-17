extern int gnResolutionMode_007C8CC4; // 0x007C8CC4
extern int gnScreen_7C9780; // 0x007C9780
extern int gnScreen_7C9784; // 0x007C9784
extern int gnScreen_7C9788; // 0x007C9788
extern int gnScreen_7C978C; // 0x007C978C
extern int gnScreen_7C9790; // 0x007C9790
extern int gnScreen_7C9794; // 0x007C9794
extern int gnScreen_7C9798; // 0x007C9798
extern int gnScreen_7C979C; // 0x007C979C
extern int gnScreen_7C97A0; // 0x007C97A0
extern int gnScreen_7C97A4; // 0x007C97A4
extern int gnScreen_7CA318; // 0x007CA318
extern int gnScreen_7CA31C; // 0x007CA31C
extern int gnScreen_7D2320; // 0x007D2320
extern int gnScreen_7D2324; // 0x007D2324
extern int gnScreen_7D2328; // 0x007D2328
extern int gnScreen_7D232C; // 0x007D232C
extern int gnScreen_7D2330; // 0x007D2330
extern int gnScreen_7D2334; // 0x007D2334
extern int gnScreen_7D2338; // 0x007D2338
extern int gnScreen_7D233C; // 0x007D233C

// 0x004F7DA0
void __fastcall sub_004F7DA0_SetPanelCoords(int nWidth, int nHeight)
{
    int nLeft = 0;
    int nRight = nWidth;
    const int nBottom = nHeight - 0x2F;
    if (gnResolutionMode_007C8CC4 == 1)
    {
        nRight -= nWidth / 2;
    }
    else if (gnResolutionMode_007C8CC4 == 2)
    {
        nLeft = nWidth / 2;
    }
    gnScreen_7D2338 = nBottom;
    gnScreen_7C97A4 = nLeft;
    gnScreen_7D2328 = nLeft;
    gnScreen_7CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnScreen_7D232C = -0x20;
    gnScreen_7D2324 = nRight;
    gnScreen_7C978C = nBottom;
    gnScreen_7CA31C = 0;
    gnScreen_7C9794 = nLeft - 0x20;
    gnScreen_7C9790 = nBottom - 0x20;
    gnScreen_7C9784 = nRight - 0x20;
    gnScreen_7D2334 = 0;
    gnScreen_7D233C = nRight;
    gnScreen_7C97A0 = nBottom;
}
