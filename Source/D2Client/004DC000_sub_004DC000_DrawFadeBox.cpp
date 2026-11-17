extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
unsigned int gdwFadeTick_007C89CC;                                                                          // 0x007C89CC
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340

// 0x004DC000
void __cdecl sub_004DC000_DrawFadeBox()
{
    if (!gdwFadeTick_007C89CC)
    {
        return;
    }

    unsigned int dwNow = GetTickCount();
    if (dwNow > gdwFadeTick_007C89CC)
    {
        gdwFadeTick_007C89CC = 0;
        return;
    }

    int nRemaining = gdwFadeTick_007C89CC - dwNow;
    int nYEnd = gnGlobal_00711470 - 47;
    int nXEnd = gnGlobal_0071146C;
    int nXStart = 0;
    switch (sub_0045AE90())
    {
    case 1:
        nXEnd -= gnGlobal_0071146C / 2;
        break;

    case 2:
        nXStart = gnGlobal_0071146C / 2;
        break;
    }

    D2GFX_DrawBoxAlpha(nXStart, 0, nXEnd, nYEnd, 0, nRemaining * 255 / 500);
}
