#pragma function(memcpy)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

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

static __declspec(noinline) void __stdcall sub_00606A10_EncodeRleCell(unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize, const unsigned char* pSrc)
{
    int nStride = *(volatile unsigned int*)&nWidth;
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc((2 * nStride + 1) * nHeight, ".\\SRC\\FastCmp.cpp", 37, 0);
    unsigned char* pOut = pBuffer;
    int nRestReachedEnd;
    int nRunReachedEnd;
    unsigned int nRow = 0;
    if (!(dwFlags & 1))
    {
        pSrc += (nHeight - 1) * nStride;
        nStride = -nStride;
    }

    const unsigned char* pNextRow = pSrc + nStride;
    const unsigned char* pRowEnd = pSrc + *(volatile unsigned int*)&nWidth;
    while (nRow < nHeight)
    {
        if (*pSrc == 0)
        {
            const int nRun = sub_0060D280_ScanSameRun(pSrc, pRowEnd, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            if (!nRestReachedEnd && !nRunReachedEnd)
            {
                *pOut++ = (unsigned char)(nRun | 0x80);
                pSrc += nRun;
                continue;
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

            if (!nRunReachedEnd)
            {
                continue;
            }
        }

        *pOut++ = 0x80;
        ++nRow;
        pSrc = pNextRow;
        pNextRow += nStride;
        pRowEnd += nStride;
    }

    *ppOut = pBuffer;
    *pnSize = pOut - pBuffer;
}

// 0x00606B50
void __fastcall sub_00606B50_CompressCellFile(D2CellFileStrc* pSrcFile, D2CellFileStrc* pDstFile, D2CmpMapColorFn pfnMapColor, D2CmpColorStrc tTransparent)
{
    D2_ASSERT(pSrcFile->dwFlags & 4, 206);
    for (unsigned int i = 0; i < pSrcFile->nDirections * pSrcFile->nFrames; ++i)
    {
        const unsigned int nPixels = pSrcFile->pGfxCells[i]->dwHeight * pSrcFile->pGfxCells[i]->dwWidth;
        unsigned char* pIndexed = (unsigned char*)FOG_Alloc(nPixels, ".\\SRC\\FastCmp.cpp", 212, 0);
        const unsigned char* pRgb = pSrcFile->pGfxCells[i]->pPixels;
        unsigned char* pWrite = pIndexed;
        for (unsigned int j = 0; j < nPixels; ++j)
        {
            if (pRgb[0] == tTransparent.nRed && pRgb[1] == tTransparent.nGreen && pRgb[2] == tTransparent.nBlue)
            {
                *pWrite++ = 0;
            }
            else
            {
                const unsigned char nIndex = pfnMapColor(pRgb[0], pRgb[1], pRgb[2]);
                D2_ASSERT(nIndex, 224);
                *pWrite++ = nIndex;
            }

            pRgb += 3;
        }

        unsigned char* pRle;
        unsigned int nRleSize;
        sub_00606A10_EncodeRleCell(pSrcFile->pGfxCells[i]->dwWidth, pSrcFile->pGfxCells[i]->dwHeight, pSrcFile->pGfxCells[i]->dwFlags, &pRle, &nRleSize, pIndexed);
        FOG_Free(pIndexed, ".\\SRC\\FastCmp.cpp", 240, 0);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 242, 0);
        pNew->dwFlags = pSrcFile->pGfxCells[i]->dwFlags;
        pNew->dwWidth = pSrcFile->pGfxCells[i]->dwWidth;
        pNew->dwHeight = pSrcFile->pGfxCells[i]->dwHeight;
        pNew->nXOffset = pSrcFile->pGfxCells[i]->nXOffset;
        pNew->nYOffset = pSrcFile->pGfxCells[i]->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 253, 0);
        pDstFile->pGfxCells[i] = pNew;
    }
}
