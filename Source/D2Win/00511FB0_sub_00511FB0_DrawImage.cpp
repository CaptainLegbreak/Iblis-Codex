struct D2CelStrc;
struct D2CmpCelContextStrc;

struct D2CelContextStrc
{
    int nArg0;
    unsigned char nFlags;
    unsigned char nComponent;
    short unk0x06;
    int nType;
    int nClass;
    int nMode;
    int nOverlay;
    int nArg18;
    int nArg1C;
    unsigned int dwToken;
    unsigned int dwModeToken;
    unsigned int dwCode;
    const char* szName;
    int nFrames;
    int nArg34;
    int unk0x38;
    D2CelStrc* pCel;
    int nArg40;
    int unk0x44;
};

struct D2DDrawCapsStrc
{
    int nValue00;
    int nValue04;
    int nValue08;
    unsigned char* pGammaTables[0x3E];
    int nValue104;
    int nValue108;
    int nValue10C;
    int unk0x110[2];
    unsigned char* pMode7Table;
};

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950
void __stdcall sub_006014C0(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType);                                           // 0x00511D70

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2DDrawCapsStrc* gpDDrawCaps_007C9150;                                                               // 0x007C9150
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern int gnDDrawOriginX_0088129C;                                                                         // 0x0088129C
extern int gnDDrawModeWidth_008812A0;                                                                       // 0x008812A0

static int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
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
        nY += sub_00601950(pCel);
        if (nY >= 0 && nY - nHeight < gnScreenHeight_007C913C)
            return 0;
    }

    return 1;
}

// 0x00511FB0
int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = sub_00511D70_GetCapsValue(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpDDrawCaps_007C9150->pGammaTables[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpDDrawCaps_007C9150->pMode7Table;

    sub_006014C0((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawOriginX_0088129C, gnDDrawModeWidth_008812A0,
        gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}
