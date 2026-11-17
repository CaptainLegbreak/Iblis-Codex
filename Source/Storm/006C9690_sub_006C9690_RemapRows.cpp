struct D2RgbColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

struct D2SmackStrc
{
    int nVersion;
    int nWidth;
    int nHeight;
    int nFrames;
    unsigned char unk0x10[0x58];
    int bNewPalette;
    D2RgbColorStrc aPalette[256];
    unsigned char unk0x36C[8];
    int nFrameNum;
};

struct D2GdiSmackStrc
{
    D2SmackStrc* hSmack;
    unsigned char nType;
    unsigned char unk0x05[3];
    int nX;
    int nY;
};

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __fastcall sub_006C9640_GdiCloseSmacker(D2GdiSmackStrc* pRecord);                                      // 0x006C9640

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern unsigned char gabRemapTable_0098A178[256];                                                           // 0x0098A178
extern unsigned char* gpRemapSource_0098A278;                                                               // 0x0098A278
extern int gbRemapValid_0098A27C;                                                                           // 0x0098A27C
extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144

static __forceinline void sub_006C9690_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        --nCount;
        *pDst++ = gabRemapTable_0098A178[*pSrc++];
    }
}

static __declspec(noinline) void __stdcall sub_006C9690_RemapRows(int nWidth, D2GdiSmackStrc* pRect, unsigned int nRows);

// 0x006C9690
static void __stdcall sub_006C9690_RemapRows(int nWidth, D2GdiSmackStrc* pRect, unsigned int nRows)
{
    unsigned char* pSrc = gpRemapSource_0098A278;
    unsigned char* pDst = (pRect->nY - nRows) * gnScreenWidth_007C9138 + pRect->nX + gpScreenBuffer_007C9154;
    unsigned int nLeft = nRows;
    while (nLeft)
    {
        --nLeft;
        sub_006C9690_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnScreenWidth_007C9138;
        pSrc += nWidth;
    }
}

// 0x006C9900
void __fastcall sub_006C9900_GdiPlaySmacker(D2GdiSmackStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = pRecord->hSmack;
        if (!hSmack)
            return;
        if (!SmackWait(hSmack))
        {
            if (!gbSurfaceActive_007C9140)
                return;
            if (hSmack->bNewPalette)
            {
                for (int i = 0; i < 256; ++i)
                {
                    gabRemapTable_0098A178[i] = sub_00605210_FindNearestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbRemapValid_0098A27C = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                sub_006C9640_GdiCloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
        if (gbRenderPaused_007C9144)
            return;
        if (!gbRemapValid_0098A27C)
            return;
        sub_006C9690_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused_007C9144)
            sub_006C9690_RemapRows(468, pRecord, 60);
        break;
    }
}
