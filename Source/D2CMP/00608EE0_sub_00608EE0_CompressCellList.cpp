extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl sub_006829C0_memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D280
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0

struct D2GfxCellStrc
{
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    int nXOffset;
    int nYOffset;
    unsigned int unk0x14;
    unsigned int dwParent;
    unsigned int dwLength;
    unsigned char pPixels[1];
};

struct D2CellFileStrc
{
    unsigned int dwVersion;
    unsigned int dwFlags;
    unsigned int eFormat;
    unsigned int dwTermination;
    unsigned int nDirections;
    unsigned int nFrames;
    D2GfxCellStrc* pGfxCells[1];
};

struct D2CmpColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

extern "C" const char szFastCmpFile[];                                                                      // 0x006E5F08

// 0x00606A10
static __declspec(noinline) void __stdcall sub_00606A10_EncodeRleCell(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc((2 * nWidth + 1) * nHeight, szFastCmpFile, 37, 0);
    int nStride;
    unsigned char* pOut = pBuffer;
    int nRestReachedEnd;
    int nRunReachedEnd;
    unsigned int nRow = 0;
    if (!(dwFlags & 1))
    {
        pSrc += (nHeight - 1) * nWidth;
        nStride = -(int)nWidth;
    }
    else
    {
        nStride = nWidth;
    }

    const unsigned char* pNextRow = pSrc + nStride;
    const unsigned char* pRowEnd = pSrc + nWidth;
    while (nRow < nHeight)
    {
        if (*pSrc == 0)
        {
            const int nRun = sub_0060D280_ScanSameRun(pSrc, pRowEnd, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            if (!nRestReachedEnd && !nRunReachedEnd)
            {
                *pOut++ = (unsigned char)(nRun | 0x80);
                pSrc += nRun;
            }
            else
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
        else
        {
            const unsigned int nRun = sub_0060D3A0_ScanOtherRun(pSrc, pRowEnd, 0, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            *pOut++ = (unsigned char)nRun;
            for (unsigned int i = 0; i < nRun; ++i)
            {
                *pOut++ = *pSrc++;
            }

            if (nRunReachedEnd)
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
    }

    *ppOut = pBuffer;
    *pnSize = pOut - pBuffer;
}

struct D2CmpCellNodeStrc
{
    D2CmpCellNodeStrc* pPrev;
    D2CmpCellNodeStrc* pNext;
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    unsigned int unk0x14;
    int nXOffset;
    int nYOffset;
    const unsigned char* pPixels;
};

struct D2CmpCellListStrc
{
    char unk0x00[0x18];
    unsigned int dwFlags;
    char unk0x1C[0x08];
    unsigned int nCells;
    unsigned int nDirections;
    char unk0x2C[0x08];
    D2CmpCellNodeStrc* pHead;
};

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90

// 0x00608EE0
void __fastcall sub_00608EE0_CompressCellList(D2CmpCellListStrc* pSrcList, D2CellFileStrc* pDstFile)
{
    D2_ASSERT(!(pSrcList->dwFlags & 4), 0x72);
    const unsigned int nFrames = pSrcList->nCells / pSrcList->nDirections;
    unsigned int i = 0;
    for (D2CmpCellNodeStrc* pNode = (D2CmpCellNodeStrc*)((((int)pSrcList->pHead <= 0) - 1) & (int)pSrcList->pHead); (int)pNode > 0; pNode = pNode->pNext)
    {
        unsigned char* pRle;
        unsigned int nRleSize;
        sub_00606A10_EncodeRleCell(pNode->pPixels, pNode->dwWidth, pNode->dwHeight, pNode->dwFlags, &pRle, &nRleSize);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 0x82, 0);
        pNew->dwFlags = pNode->dwFlags;
        pNew->dwWidth = pNode->dwWidth;
        pNew->dwHeight = pNode->dwHeight;
        pNew->nXOffset = pNode->nXOffset;
        pNew->nYOffset = pNode->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        sub_006829C0_memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 0x8D, 0);

        const unsigned int nDirections = pSrcList->nDirections;
        const int nDirection = nDirections > 1 ? ((i / nFrames) << 6) / nDirections : 1;
        pDstFile->pGfxCells[sub_00600C90_GetDirectionIndex64(nDirection, nDirections) * nFrames + i % nFrames] = pNew;
        ++i;
    }
}
