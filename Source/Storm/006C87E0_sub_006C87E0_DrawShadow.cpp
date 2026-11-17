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

struct D2GfxPaletteView006C85A0Strc
{
    unsigned char* pShadowTable;
    int nValue04;
    int nValue08;
    unsigned char* pGammaTables[0x31];
    unsigned char* pPalettes[0x12];
    unsigned char* pMode7Table;
};

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950
void __stdcall sub_00601730_DrawCelShadow(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, unsigned char* pShadowTable, int nArg10); // 0x00601730
int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2GfxPaletteView006C85A0Strc* gpGfxPaletteView_007C9150;                                             // 0x007C9150
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern int gnOriginX_0098A168;                                                                              // 0x0098A168
extern int gnModeWidth_0098A16C;                                                                            // 0x0098A16C

static int __stdcall sub_006C85A0_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
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

// 0x006C87E0
void __fastcall sub_006C87E0_DrawShadow(void* pData, int nX, int nY)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_006C85A0_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    unsigned char* pShadowTable = 0;
    if (sub_006C8A50_GetBlendedShadows())
        pShadowTable = gpGfxPaletteView_007C9150->pShadowTable;

    sub_00601730_DrawCelShadow(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, pShadowTable, 0);
}
