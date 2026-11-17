struct D2CelStrc;
struct D2CmpCelContextStrc
{
    char unk_00[0x3C];
    D2CelStrc* pCel;
};
int __stdcall sub_006001F0(D2CmpCelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel); // 0x00601950
int __cdecl sub_00512700_DDrawGetBlendedShadows(); // 0x00512700
void __stdcall sub_00601730_DrawCelShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor); // 0x00601730
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int* gpShadowTable_007C9150; // 0x007C9150
extern unsigned char* gpSurface_007C9154; // 0x007C9154
extern int gnClipLeft_0088129C; // 0x0088129C
extern int gnClipRight_008812A0; // 0x008812A0

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

// 0x005122E0
void __fastcall sub_005122E0_DrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    int nTable = 0;
    if (sub_00512700_DDrawGetBlendedShadows())
        nTable = *gpShadowTable_007C9150;
    sub_00601730_DrawCelShadow(pContext, nX, nY, gnClipLeft_0088129C, gnClipRight_008812A0, gpSurface_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, nTable, 0);
}
