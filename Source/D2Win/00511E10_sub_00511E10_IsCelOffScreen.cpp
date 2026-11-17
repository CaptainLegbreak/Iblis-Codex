struct D2CelStrc;

int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C

// 0x00511E10
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

// build: context sub_K08_EmitCelClip
extern "C" int __stdcall sub_K08_EmitCelClip(D2CelStrc* pCel, int nX, int nY)
{
    return sub_00511E10_IsCelOffScreen(pCel, nX, nY, 0) + 9;
}
