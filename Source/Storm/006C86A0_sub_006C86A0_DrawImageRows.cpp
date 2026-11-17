struct D2CelStrc;

struct D2CelContextStrc
{
    int unk0x00[0x0F];
    D2CelStrc* pCel;
};

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                               // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                                // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                                // 0x00601950
void __stdcall sub_00601650_DrawCelClipped(D2CelContextStrc* pContext, int nX, int nY, int nOriginX, int nModeWidth, unsigned char* pBuffer, int nHeight, int nWidth, int nArg9, unsigned char* pCaps, int nSkipTop, int nDrawHeight, int nArg13); // 0x00601650

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern int gnOriginX_0098A168;                                                                              // 0x0098A168
extern int gnModeWidth_0098A16C;                                                                            // 0x0098A16C

struct D2Config006C8250Strc
{
    int n000;
    int n004;
    int n008;
    unsigned char unk_00C[0xF8];
    int n104;
    int n108;
    int n10C;
};
extern int gaSelectorValues_0074C5A0[];                                                                     // 0x0074C5A0
extern D2Config006C8250Strc* gpConfig_007C9150;                                                             // 0x007C9150

int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue)
{
    *pValue = gaSelectorValues_0074C5A0[nSelector];
    switch (nSelector)
    {
    case 0:
        return gpConfig_007C9150->n008;
    case 1:
        return gpConfig_007C9150->n004;
    case 2:
        return gpConfig_007C9150->n000;
    case 3:
        return gpConfig_007C9150->n104;
    case 4:
        return gpConfig_007C9150->n108;
    case 6:
        return gpConfig_007C9150->n10C;
    }
    return 0;
}

static int __stdcall sub_006C86A0_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = sub_006018C0(pCel);
    int nHeight = sub_006018F0(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += sub_00601920(pCel);
    if (nX < gnScreenWidth_007C9138 && nWidth + nX >= 0)
    {
        int nTop = sub_00601950(pCel) + nY;
        if (nTop >= 0 && nTop - nHeight < gnScreenHeight_007C913C)
            return 0;
    }

    return 1;
}

// 0x006C86A0
void __fastcall sub_006C86A0_DrawImageRows(D2CelContextStrc* pContext, int nX, int nY, int nSkipTop, int nDrawHeight, int nDrawMode)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_006C86A0_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return;

    sub_00601650_DrawCelClipped(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C, gpScreenBuffer_007C9154,
        gnScreenHeight_007C913C, gnScreenWidth_007C9138, 0, (unsigned char*)sub_006C8250_GetSetting(nDrawMode, &nDrawHeight),
        nSkipTop, nDrawHeight, 0);
}
