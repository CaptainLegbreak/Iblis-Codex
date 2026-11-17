struct D2UnitStrc;
struct D2CelFileStrc;

struct D2ViewStrc
{
    char unk0x00[0x24];
    int nPosX;
    int nPosY;
};

unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
void __fastcall sub_004FAAE0_FreeCellFile(D2CelFileStrc* pCellFile);                                        // 0x004FAAE0

D2CelFileStrc* ghPentagramCellFile;                                                                         // 0x0087E96C
extern unsigned char gabBeltHotkey_007BEFB0[];                                                              // 0x007BEFB0
extern int gnBeltBox_0072235C;                                                                              // 0x0072235C
extern int gnBeltRectX_00722360;                                                                            // 0x00722360
extern int gnBeltRectY_00722364;                                                                            // 0x00722364
extern int gnBeltHover_007BEF94;                                                                            // 0x007BEF94
extern D2UnitStrc* gpBeltItemA_007BEFA8;                                                                    // 0x007BEFA8
extern int gdwGlobal_007BEFAC;                                                                              // 0x007BEFAC
extern int gnGlobal_007BEECC;                                                                               // 0x007BEECC
extern unsigned char gnLifeColorHigh_007BEED0;                                                              // 0x007BEED0
extern unsigned char gnLifeColorMid_007BEED1;                                                               // 0x007BEED1
extern unsigned char gnLifeColorLow_007BEED2;                                                               // 0x007BEED2
extern unsigned char gbLifeColorsInit_007BEED3;                                                             // 0x007BEED3
extern unsigned char gnTextColorRed_007BEFBA;                                                               // 0x007BEFBA
extern unsigned char gabBeltColors_007BEF6C[4];                                                             // 0x007BEF6C
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4
extern int gdwGlobal_007BCBF8;                                                                              // 0x007BCBF8

// 0x004760C0
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY)
{
    *pX = pView->nPosX;
    *pY = pView->nPosY;
}

// 0x00507140
void __stdcall LIST_UnloadPentspinCellfile()
{
    sub_004FAAE0_FreeCellFile(ghPentagramCellFile);
    ghPentagramCellFile = 0;
}

// 0x00498D50
void __fastcall sub_00498D50(int nX, int nArg)
{
    if ((unsigned int)nX < 4)
        gabBeltHotkey_007BEFB0[nX] = (unsigned char)nArg;
}

// 0x00498D60
void __cdecl sub_00498D60()
{
    gnBeltBox_0072235C = -1;
    gnBeltRectX_00722360 = -1;
    gnBeltRectY_00722364 = -1;
    gnBeltHover_007BEF94 = 0;
    gpBeltItemA_007BEFA8 = 0;
    gdwGlobal_007BEFAC = 0;
}

// 0x00492C10
int __cdecl sub_00492C10()
{
    return gnGlobal_007BEECC != 2;
}

// 0x00492F40
void __fastcall sub_00492F40_SetFade(int nMode)
{
    if (!nMode)
    {
        if (gbLifeColorsInit_007BEED3)
            return;
        gbLifeColorsInit_007BEED3 = 1;
    }

    gnLifeColorHigh_007BEED0 = D2Win_10034_MixRGB(0, 0x80, 0);
    gnLifeColorMid_007BEED1 = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
    gnLifeColorLow_007BEED2 = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00492F90
void __cdecl sub_00492F90()
{
    gbLifeColorsInit_007BEED3 = 0;
}

// 0x00497250
void __cdecl sub_00497250_InitTextColorRed()
{
    gnTextColorRed_007BEFBA = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x004972B0
void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x004879D0
void __fastcall sub_004879D0(D2UnitStrc* pUnit)
{
    if (gdwGlobal_007BCBF4 == pUnit)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x00487CA0
int __cdecl sub_00487CA0_SetNpcState6()
{
    if (gdwGlobal_007BCBF0 == 6)
        return 0;
    gdwGlobal_007BCBF0 = 6;
    return 1;
}
