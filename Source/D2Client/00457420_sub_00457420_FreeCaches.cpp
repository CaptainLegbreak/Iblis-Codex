struct D2CelFileStrc;

struct D2AutomapCellStrc
{
    unsigned int fSaved;
    unsigned short nCellNo;
    unsigned short xPixel;
    unsigned short yPixel;
    unsigned short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
    D2AutomapLayerStrc* pNext;
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00457640(int bForce);                                                                   // 0x00457640
void __cdecl sub_004584C0_ResetA();                                                                         // 0x004584C0
void __cdecl sub_00458680_ResetB();                                                                         // 0x00458680
void __cdecl sub_00470290();                                                                                // 0x00470290
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __cdecl sub_00492C10();                                                                                 // 0x00492C10
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
void __stdcall sub_005FDE10_FreeCache(int bFree);                                                           // 0x005FDE10
void __stdcall sub_005FFE30_FreeTileCache(int bFree);                                                       // 0x005FFE30

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gdwGlobal_007A5150;                                                                              // 0x007A5150
void* gpAutomapSaveBuffer_007A5154;                                                                         // 0x007A5154
extern D2AutomapLayerStrc* gpAutomapNodes_007A5160;                                                         // 0x007A5160
extern D2AutomapLayerStrc* gpAutomapContext_007A5164;                                                       // 0x007A5164
extern D2CelFileStrc* gpAutomapCels_007A5168[4];                                                            // 0x007A5168
extern int gnRevealSkip_007A51A4;                                                                           // 0x007A51A4
int gdwAutoMapFade_007A51A8;                                                                                // 0x007A51A8
int gdwAutoMapFadeSaved_007A51AC;                                                                           // 0x007A51AC
unsigned char gnAutomapColors_007A51B0[1];                                                                  // 0x007A51B0
int gnGlobal_007A51C0;                                                                                      // 0x007A51C0
int gnGlobal_007A51C4;                                                                                      // 0x007A51C4
int gnGlobal_007A51C8;                                                                                      // 0x007A51C8
int gnGlobal_007A51CC;                                                                                      // 0x007A51CC
int gnGlobal_007A51D0;                                                                                      // 0x007A51D0
int gnGlobal_007A51D4;                                                                                      // 0x007A51D4
extern int gnMiniMapY_007A51D8;                                                                             // 0x007A51D8
int gnMiniMapX_007A51DC;                                                                                    // 0x007A51DC
extern int gdwGlobal_007A51E0;                                                                              // 0x007A51E0
int gnGlobal_007A51EC;                                                                                      // 0x007A51EC
int gnGlobal_007A51F0;                                                                                      // 0x007A51F0

// 0x00457420
void __fastcall sub_00457420_FreeCaches(int bFree)
{
    sub_005FDE10_FreeCache(bFree);
    sub_005FFE30_FreeTileCache(bFree);
    sub_00470290();
}

// 0x00457440
void __fastcall sub_00457440_Nop(int nUnused)
{
}

// 0x00457520
void __cdecl sub_00457520_UpdateAutomapLayout()
{
    if (gnGlobal_007A51F0 != sub_00492C10() && gdwGlobal_007A5150 == 1)
    {
        gnGlobal_007A51F0 = sub_00492C10();
        sub_00457640(1);
        return;
    }
    if (gnGlobal_007A51EC != gdwGlobal_007A51E0 && gdwGlobal_007A5150 == 1)
    {
        gnGlobal_007A51EC = gdwGlobal_007A51E0;
        sub_00457640(1);
        return;
    }
    if (gdwGlobal_007A51E0)
    {
        gnMiniMapX_007A51DC = 0;
        gnMiniMapY_007A51D8 = sub_00492C10() ? 0x60 : 0;
    }
    else
    {
        gnMiniMapX_007A51DC = gnGlobal_0071146C * 2 / 3;
        gnMiniMapY_007A51D8 = 0x4E;
    }
    gnGlobal_007A51C0 = gnMiniMapX_007A51DC;
    gnGlobal_007A51C4 = gnMiniMapY_007A51D8;
    switch (gdwGlobal_007A5150)
    {
    case 1:
        gnGlobal_007A51C8 = gnMiniMapX_007A51DC - 8;
        gnGlobal_007A51D0 = gnGlobal_0071146C / 3 + gnMiniMapX_007A51DC;
        gnGlobal_007A51CC = gnMiniMapY_007A51D8;
        gnGlobal_007A51D4 = gnGlobal_00711470 / 3 + gnMiniMapY_007A51D8;
        break;
    default:
        gnGlobal_007A51D0 = gnGlobal_0071146C;
        gnGlobal_007A51C8 = -16;
        gnGlobal_007A51CC = -16;
        gnGlobal_007A51D4 = gnGlobal_00711470;
        break;
    }
}

// 0x004576C0
int __cdecl sub_004576C0()
{
    if (gdwGlobal_007A5150 == 1 && gdwAutoMapFade_007A51A8 == 1)
    {
        gdwAutoMapFade_007A51A8 = gdwAutoMapFadeSaved_007A51AC ? 0 : 2;
    }
    return gdwAutoMapFade_007A51A8;
}

// 0x004576F0
int __fastcall sub_004576F0(int nFade)
{
    if (gdwGlobal_007A5150 == 1 && nFade == 1)
    {
        nFade = gdwAutoMapFadeSaved_007A51AC ? 0 : 2;
        gdwAutoMapFade_007A51A8 = 1;
    }
    SRegSaveValue("Diablo II", "AutoMapFade", 0, nFade);
    gdwAutoMapFadeSaved_007A51AC = nFade;
    gdwAutoMapFade_007A51A8 = nFade;
    return nFade;
}

// 0x00458440
void __fastcall sub_00458440_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount)
{
    if (!pCells)
    {
        return;
    }
    sub_00458440_CountCells(pCells->pPrev, pCount);
    if (!pCells->fSaved)
    {
        *pCount += 6;
    }
    sub_00458440_CountCells(pCells->pNext, pCount);
}

// 0x00458470
void __fastcall sub_00458470_StoreCells(D2AutomapCellStrc* pCells)
{
    if (!pCells)
    {
        return;
    }
    sub_00458470_StoreCells(pCells->pPrev);
    if (!pCells->fSaved)
    {
        unsigned short* pBuffer = (unsigned short*)gpAutomapSaveBuffer_007A5154;
        *pBuffer = pCells->nCellNo;
        ++pBuffer;
        *pBuffer = pCells->xPixel;
        ++pBuffer;
        *pBuffer = pCells->yPixel;
        ++pBuffer;
        gpAutomapSaveBuffer_007A5154 = pBuffer;
    }
    sub_00458470_StoreCells(pCells->pNext);
}

// 0x00459140
void __cdecl sub_00459140_Refresh()
{
    gnRevealSkip_007A51A4 = 2;
}

// 0x0045A5C0
void __cdecl sub_0045A5C0_FreeAutomap()
{
    sub_004584C0_ResetA();
    sub_00458680_ResetB();
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
        {
            sub_00478A00(gpAutomapCels_007A5168[i]);
        }
        gpAutomapCels_007A5168[i] = 0;
    }
    D2AutomapLayerStrc* pLayer = gpAutomapNodes_007A5160;
    while (pLayer)
    {
        D2AutomapLayerStrc* pFree = pLayer;
        pLayer = pLayer->pNext;
        FOG_Free(pFree, ".\\UI\\automap.cpp", 0xC06, 0);
    }
    gpAutomapNodes_007A5160 = 0;
    gpAutomapContext_007A5164 = 0;
}

// 0x0045A620
void __cdecl sub_0045A620_InitAutomapColors()
{
    gnAutomapColors_007A51B0[0] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gnAutomapColors_007A51B0[1] = D2Win_10034_MixRGB(0xFF, 0, 0);
    gnAutomapColors_007A51B0[2] = D2Win_10034_MixRGB(0xFF, 0, 0xFF);
    gnAutomapColors_007A51B0[3] = D2Win_10034_MixRGB(0, 0xFF, 0);
    gnAutomapColors_007A51B0[4] = D2Win_10034_MixRGB(0x44, 0x70, 0x74);
    gnAutomapColors_007A51B0[5] = D2Win_10034_MixRGB(0x48, 0xA0, 0x34);
    gnAutomapColors_007A51B0[6] = D2Win_10034_MixRGB(0xF4, 0xF4, 0xF4);
    gnAutomapColors_007A51B0[7] = D2Win_10034_MixRGB(0x80, 0x80, 0x80);
    gnAutomapColors_007A51B0[8] = D2Win_10034_MixRGB(0xF4, 0xF4, 0);
    gnAutomapColors_007A51B0[9] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gnAutomapColors_007A51B0[10] = D2Win_10034_MixRGB(0, 0xFF, 0);
}
