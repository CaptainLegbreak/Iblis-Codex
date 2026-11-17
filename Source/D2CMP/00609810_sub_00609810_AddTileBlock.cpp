extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
struct D2TileListHeaderStrc;
D2TileListHeaderStrc* __cdecl sub_006094B0_AllocTileListHeader();                                           // 0x006094B0
void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2);

struct D2CmpColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

struct D2CmpTileNodeStrc
{
    unsigned short nX;
    unsigned short nY;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short nFormat;
    unsigned short nLength;
    short unk0x0A;
    unsigned char* pData;
    D2CmpTileNodeStrc* pNext;
};

struct D2CmpTileStrc
{
    int nMinX;
    int nMaxY;
    int nMaxX;
    int nMinY;
    char unk0x10[0x24];
    D2CmpColorStrc tColor;
    char unk0x38[0x19];
    unsigned char nFlags;
    char unk0x52[0x02];
    int nCount;
    D2CmpTileNodeStrc* pNodes;
};

static __declspec(noinline) int __stdcall sub_00609770_IsUniformBlock(D2CmpTileStrc* pTile, const unsigned char* pPixels, int nPitch)
{
    const unsigned char nFlags = pTile->nFlags;
    if (nFlags & 2)
    {
        const int nSkip = nPitch - 0x60;
        const unsigned int nColor = (((pTile->tColor.nBlue << 8) + pTile->tColor.nGreen) << 8) + pTile->tColor.nRed;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                const unsigned int nPixel = *(const unsigned int*)pPixels & 0xFFFFFF;
                pPixels += 3;
                if (nPixel != nColor)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    if (nFlags & 1)
    {
        const int nSkip = nPitch - 0x20;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                const char nAlpha = *(const char*)pPixels;
                pPixels++;
                if (nAlpha)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    return 1;
}

// 0x00609810
void __stdcall sub_00609810_AddTileBlock(D2CmpTileStrc* pTile, unsigned char* pPixels, int nPitch, int nX, int nY)
{
    D2_ASSERT(pTile, 0x100);
    D2_ASSERT(pPixels, 0x101);
    if (sub_00609770_IsUniformBlock(pTile, pPixels, nPitch))
        return;
    D2CmpTileNodeStrc* pNode = (D2CmpTileNodeStrc*)sub_006094B0_AllocTileListHeader();
    D2_ASSERT(pNode, 0x109);
    pNode->pNext = pTile->pNodes;
    pTile->nCount++;
    pTile->pNodes = pNode;
    D2_ASSERT(nX < 0x10000 && nY < 0x10000, 0x112);
    pNode->nX = nX;
    pNode->nY = nY;
    unsigned char* pData = (unsigned char*)FOG_Alloc(0xC00, ".\\SRC\\Tilecmp.cpp", 0x119, 0);
    D2_ASSERT(pData, 0x11A);
    memset(pData, 0, 0xC00);
    pNode->nLength = 0xC00;
    pNode->pData = pData;
    pNode->nFormat = 0x1001;
    sub_005179B3_ConvertCelPixels(pData, pPixels, 0x60, nPitch, 0x20, 0x60);
    if (nX < pTile->nMinX)
        pTile->nMinX = nX;
    if (nX + 0x20 > pTile->nMaxX)
        pTile->nMaxX = nX + 0x20;
    if (nY > pTile->nMaxY)
        pTile->nMaxY = nY;
    if (nY - 0x20 < pTile->nMinY)
        pTile->nMinY = nY - 0x20;
}
