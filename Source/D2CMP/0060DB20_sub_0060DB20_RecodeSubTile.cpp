extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" const char szTileCodecFile[]; // 0x006E61F8
void* __fastcall FOG_Alloc(int, const char*, int, int); // 0x0040B380
int __fastcall FOG_Free(void*, const char*, int, int); // 0x0040B3C0
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int); // 0x006829C0

struct D2CmpColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};
typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char, unsigned char, unsigned char);
struct D2CmpSubTileHeaderStrc
{
    int unk0x00;
    int unk0x04;
    unsigned short nFlags;
    unsigned short nLength;
    int unk0x0C;
};
struct D2CmpSubTileRecordStrc
{
    D2CmpSubTileHeaderStrc tHeader;
    unsigned char* pData;
};
struct D2CmpTileBlockStrc
{
    char reserved[0x46];
    unsigned char nFlags;
    char pad47[9];
    int nSubs;
    D2CmpSubTileRecordStrc* pSubs;
};

int __fastcall sub_0060D310_CountTransparent(unsigned char, const unsigned char*, const unsigned char*, int, int*, int*); // 0x0060D310
int __fastcall sub_0060D3A0_CountOpaque(const unsigned char*, const unsigned char*, unsigned char, int, int*, int*); // 0x0060D3A0
unsigned char* __stdcall sub_0060D6F0_MapPixels(const unsigned char*, int, D2CmpColorStrc, D2CmpMapColorFn); // 0x0060D6F0
void __stdcall sub_0060D9C0_PackSolid(D2CmpSubTileRecordStrc*, const unsigned char*); // 0x0060D9C0

// @ref 0x0060D7E0
static __declspec(noinline) int sub_0060D7E0_HasTransparent(const unsigned char* pData)
{
    int nOffset = 14;
    int nWidth = 4;
    for (int nRow = 0; nRow < 15; ++nRow)
    {
        for (int nPixel = 0; nPixel < nWidth; ++nPixel)
            if (!pData[nOffset + nPixel])
                return 1;
        pData += 32;
        if (nRow < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }
    return 0;
}

// @ref 0x0060D840
static __declspec(noinline) void __stdcall sub_0060D840_PackTransparent(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x5AF, szTileCodecFile, 0x128, 0);
    D2_ASSERT(pBuffer, 0x129);
    memset(pBuffer, 0, 0x5AF);
    unsigned char* pOut = pBuffer;
    const unsigned char* pNextRow = pSrc + 32;
    const unsigned char* pEnd = pNextRow;
    unsigned int nRow = 0;
    do
    {
        int nAtEnd;
        int nRestTransparent;
        int nSkip = sub_0060D310_CountTransparent(0, pSrc, pEnd, 0x7F, &nAtEnd, &nRestTransparent);
        pSrc += nSkip;
        if (!nAtEnd && !nRestTransparent)
        {
            if (nSkip == 0x7F)
            {
                *pOut++ = (unsigned char)nSkip;
                continue;
            }
            int nCopy = sub_0060D3A0_CountOpaque(pSrc, pEnd, 0, 0x7F, &nAtEnd, &nRestTransparent);
            *pOut++ = (unsigned char)nSkip;
            *pOut++ = (unsigned char)nCopy;
            while (nCopy > 0)
            {
                *pOut++ = *pSrc++;
                --nCopy;
            }
        }
        if (nAtEnd || nRestTransparent)
        {
            pEnd += 32;
            *pOut++ = 0;
            *pOut++ = 0;
            pSrc = pNextRow;
            pNextRow += 32;
            ++nRow;
        }
    } while (nRow < 15);
    int nLength = pOut - pBuffer;
    D2_ASSERT(nLength < 0x10000, 0x166);
    unsigned char* pData = (unsigned char*)FOG_Alloc(nLength, szTileCodecFile, 0x169, 0);
    D2_ASSERT(pData, 0x16A);
    memset(pData, 0, nLength);
    memcpy(pData, pBuffer, nLength);
    pDst->tHeader.nFlags |= 5;
    pDst->pData = pData;
    pDst->tHeader.nLength = (unsigned short)nLength;
    FOG_Free(pBuffer, szTileCodecFile, 0x176, 0);
}

// @ref 0x0060DA80
static __declspec(noinline) void __stdcall sub_0060DA80_MapSubTile(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc)
{
    unsigned char* pData = sub_0060D6F0_MapPixels(pSrc->pData, pSrc->tHeader.nLength, tColor, pfnMap);
    const unsigned char* p = pData;
    int nPixel;
    for (nPixel = 0; nPixel < 0x200; ++nPixel)
    {
        if (*p)
            break;
        ++p;
    }
    if (nPixel == 0x200)
    {
        pDst->tHeader.nFlags = 0;
        pDst->tHeader.nLength = 0;
        pDst->pData = 0;
        FOG_Free(pData, szTileCodecFile, 0x1B8, 0);
        return;
    }
    if (sub_0060D7E0_HasTransparent(pData))
        sub_0060D840_PackTransparent(pDst, pData);
    else
        sub_0060D9C0_PackSolid(pDst, pData);
    FOG_Free(pData, szTileCodecFile, 0x1C7, 0);
}

// 0x0060DB20
void __fastcall sub_0060DB20_RecodeSubTile(D2CmpSubTileRecordStrc* pRecord)
{
    unsigned char* pData = pRecord->pData;
    if (sub_0060D7E0_HasTransparent(pData))
        sub_0060D840_PackTransparent(pRecord, pData);
    else
        sub_0060D9C0_PackSolid(pRecord, pData);
    FOG_Free(pData, szTileCodecFile, 0x1DE, 0);
}

// @ref 0x0060DB60
void __fastcall sub_0060DB60_MapBlock(D2CmpTileBlockStrc* pSrc, D2CmpTileBlockStrc* pDst, D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap)
{
    D2_ASSERT(pSrc, 0x1EC);
    D2_ASSERT(pDst, 0x1ED);
    D2_ASSERT(pfnMap, 0x1EE);
    D2_ASSERT(pSrc->nFlags & 8, 0x1EF);
    for (int i = 0; i < pSrc->nSubs; ++i)
    {
        const D2CmpSubTileRecordStrc* pSrcSub = &pSrc->pSubs[i];
        D2CmpSubTileRecordStrc* pDstSub = &pDst->pSubs[i];
        pDstSub->tHeader = pSrcSub->tHeader;
        pDstSub->pData = 0;
        if (pSrcSub->pData)
        {
            sub_0060DA80_MapSubTile(tColor, pfnMap, pDstSub, pSrcSub);
            if (pDstSub->tHeader.nFlags & 4)
                pDst->nFlags |= 0x10;
        }
    }
}
