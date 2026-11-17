struct D2CmpRawFrameStrc
{
    int unk0x00;
    D2CmpRawFrameStrc* pNext;
    int f_8;
    int nWidth;
    int nHeight;
    int unk0x14;
    int nOffsetX;
    int nOffsetY;
    void* pData;
};

struct D2CmpRawStrc
{
    char unk0x00[0x24];
    unsigned int nFrames;
    unsigned int nDirections;
    char unk0x2C[0x08];
    D2CmpRawFrameStrc* pFirst;
};

struct D2CmpDC6FrameStrc
{
    int f_0;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int unk0x14;
    int nNext;
    unsigned int nLength;
    unsigned char pPixels[4];
};

struct D2CmpDC6HeaderStrc
{
    char unk0x00[0x18];
    D2CmpDC6FrameStrc* pFrames[1];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90

// 0x0060D190
void __fastcall sub_0060D190_BuildDC6FromRaw(D2CmpRawStrc* pRaw, D2CmpDC6HeaderStrc* pDC6)
{
    unsigned int nPerDir = pRaw->nFrames / pRaw->nDirections;
    unsigned int nFrame = 0;

    for (D2CmpRawFrameStrc* pRawFrame = (D2CmpRawFrameStrc*)((((int)pRaw->pFirst <= 0) - 1) & (int)pRaw->pFirst);
         (int)pRawFrame > 0; pRawFrame = pRawFrame->pNext)
    {
        unsigned int nLength = pRawFrame->nWidth * pRawFrame->nHeight * 3;
        D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)FOG_Alloc(nLength + 0x23, ".\\SRC\\Raw.cpp", 0x22, 0);
        pFrame->f_0 = pRawFrame->f_8;
        pFrame->nWidth = pRawFrame->nWidth;
        pFrame->nHeight = pRawFrame->nHeight;
        pFrame->nOffsetX = pRawFrame->nOffsetX;
        pFrame->nOffsetY = pRawFrame->nOffsetY;
        pFrame->unk0x14 = 0;
        pFrame->nNext = 0;
        pFrame->nLength = nLength;
        memcpy(pFrame->pPixels, pRawFrame->pData, nLength);

        unsigned int nDirections = pRaw->nDirections;
        int nDirection;
        if (nDirections > 1)
        {
            nDirection = ((nFrame / nPerDir) << 6) / nDirections;
        }
        else
        {
            nDirection = 1;
        }

        int nIndex = sub_00600C90_GetDirectionIndex64(nDirection, nDirections);
        pDC6->pFrames[nIndex * nPerDir + nFrame % nPerDir] = pFrame;
        ++nFrame;
    }
}
