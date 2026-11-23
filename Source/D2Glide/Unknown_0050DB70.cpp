#include "D2Glide.h"
#include "D2DrlgMaps.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern unsigned char* gpMulTable_00880B5C; // 0x00880B5C
extern unsigned char gbGlideAmbientGreen; // 0x00880B58
extern unsigned char gbGlideAmbientBlue; // 0x00880B59
extern unsigned char gbGlideAmbientRed; // 0x00880B5A
extern int* gpnPerspectiveTable; // 0x00880B6C

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette); // 0x00511FB0
extern int gnProjectOriginX; // 0x00880B60
extern int gnProjectOriginY; // 0x00880B68


int gnProjectOriginX; // 0x00880B60

int gnGlideSpriteScale; // 0x00880B64

int gnProjectOriginY; // 0x00880B68

// 0x0050DF00
void __cdecl sub_0050DF00_ResetSpriteScale()
{
    gnGlideSpriteScale = 0x100;
}


// 0x0050F980
void __stdcall sub_0050F980_DecodeTileBlocks(D2TileLibraryEntryStrc* pTile, unsigned char* pDst)
{
    memset(pDst, 0, 0x8000);

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
        unsigned char* p = pBlock->nPosX + ((pBlock->nPosY << 8) + pDst);
        const unsigned short nFormat = pBlock->nFormat;
        if (!(nFormat & 1))
        {
            continue;
        }

        if (nFormat & 4)
        {
            const unsigned char* pSrc = pBlock->pData;
            int nRows = 15;
            unsigned char* pRow = p;
            do
            {
                const unsigned char nGap = *pSrc++;
                unsigned char nCount = *pSrc++;
                if (!nGap && !nCount)
                {
                    --nRows;
                    pRow += 0x100;
                    p = pRow;
                }
                else
                {
                    p += nGap;
                    while (nCount--)
                    {
                        *p++ = *pSrc++;
                    }
                }
            }
            while (nRows);
        }
        else
        {
            const unsigned char* pSrc = pBlock->pData;
            p += 0x0E;
            int nLength = 4;
            D2_ASSERT(pSrc, 0xA8);
            D2_ASSERT(pDst, 0xA9);
            for (int nRow = 0; nRow < 15; ++nRow)
            {
                memcpy(p, pSrc, nLength);
                pSrc += nLength;
                if (nRow < 7)
                {
                    p += 0xFE;
                    nLength += 4;
                }
                else
                {
                    p += 0x102;
                    nLength -= 4;
                }
            }
        }
    }
}

// 0x00512410
int __fastcall sub_00512410_ForwardToDrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nScreenMode, void* pPalette)
{
    return sub_00511FB0_DrawImage(pData, nX, nY, dwGamma, nDrawMode, pPalette);
}
