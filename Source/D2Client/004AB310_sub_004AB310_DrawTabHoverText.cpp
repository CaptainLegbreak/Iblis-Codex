struct Unicode
{
    unsigned short wChar;
};

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern unsigned char gbColor_007C0C50;                                                                      // 0x007C0C50

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

// 0x004AB310
void __stdcall sub_004AB310_DrawTabHoverText(int nMode)
{
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    int bHover = 0;
    int bShow1082 = 0;
    int bShow1081 = 0;
    int bShow1080 = 0;
    int nBoxY = 0;

LOOP:
    gbColor_007C0C50 = D2Win_10034_MixRGB(0, 0, 0);
    if (nX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0x59 && nX <= gnGlobal_0071146C - gnGlobal_007A2858 + 1)
    {
        if (nMode == 1)
        {
            if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x9C && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x108)
            {
                bShow1081 = 1;
                if (nMode != 1) goto LOOP;
                goto Box1081;
            }
            else if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x108 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x174)
            {
            Show1080:
                bShow1080 = 1;
                nBoxY = gnGlobal_00711470 + gnGlobal_007A285C - 0x174;
                bHover = 1;
                goto Done;
            }
            if (nMode != 1) goto LOOP;
            goto Done;
        }
        else if (nMode == 2)
        {
            if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x108 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x174)
            {
                goto Show1080;
            }
            else if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x30 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x9C)
            {
                bShow1082 = 1;
                if (nMode != 2) goto LOOP;
                goto Box1082;
            }
        }
        else if (nMode == 3)
        {
            if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x9C && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x108)
            {
                bShow1081 = 1;
            Box1081:
                nBoxY = gnGlobal_00711470 + gnGlobal_007A285C - 0x108;
                bHover = 1;
                goto Done;
            }
            else if (nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x30 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x9C)
            {
                bShow1082 = 1;
            Box1082:
                nBoxY = gnGlobal_00711470 + gnGlobal_007A285C - 0x9C;
                bHover = 1;
                goto Done;
            }
        }
    }
Done:
    sub_00502EF0(1);
    if (!bHover)
    {
        return;
    }

    sub_0046EFD0_DrawFramedBox(gnGlobal_0071146C - gnGlobal_007A2858 - 0x59, nBoxY + 5, 0x5A, 0x14, gbColor_007C0C50, 6);
    if (bShow1082)
    {
        sub_004A7080(gnGlobal_0071146C - gnGlobal_007A2858 - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1082), 0);
    }
    if (bShow1081)
    {
        sub_004A7080(gnGlobal_0071146C - gnGlobal_007A2858 - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1081), 0);
    }
    if (bShow1080)
    {
        sub_004A7080(gnGlobal_0071146C - gnGlobal_007A2858 - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1080), 0);
    }
}
