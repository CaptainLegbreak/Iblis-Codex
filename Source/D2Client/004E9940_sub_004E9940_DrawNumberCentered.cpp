struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00711470;                                                                               // 0x00711470

// 0x004E9940
static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, gszFormatD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000)
    {
        sub_00502EF0(1);
    }
    else
    {
        sub_00502EF0(0);
    }
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + nY - 480,
                            gnGlobal_007A2858 + nRight, wszText, nColor);
}

void sub_I08_Emit_004E9940(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    sub_004E9940_DrawNumberCentered(nColor, nLeft, nY, nRight, nValue);
}
