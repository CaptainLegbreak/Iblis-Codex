#pragma pack(push, 1)
struct D2TargaHeaderStrc
{
    unsigned char nIdLength;
    unsigned char nColorMapType;
    unsigned char nImageType;
    unsigned short nColorMapFirst;
    unsigned short nColorMapLength;
    unsigned char nColorMapDepth;
    unsigned short nXOrigin;
    unsigned short nYOrigin;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned char nPixelDepth;
    unsigned char nDescriptor;
};
#pragma pack(pop)

static __declspec(noinline) int sub_006C50D0_IsSupportedTgaHeader(const D2TargaHeaderStrc* pHeader);

// 0x006C50D0
static int sub_006C50D0_IsSupportedTgaHeader(const D2TargaHeaderStrc* pHeader)
{
    const unsigned char nType = pHeader->nImageType;
    if (nType == 1 || nType == 2 || nType == 9 || nType == 10)
    {
        if ((pHeader->nColorMapType == 0
                && ((pHeader->nPixelDepth == 24 && !(pHeader->nDescriptor & 0x0F))
                    || (pHeader->nPixelDepth == 32 && (pHeader->nDescriptor & 0x0F) == 8)))
            || (pHeader->nColorMapType == 1 && pHeader->nPixelDepth == 8
                && pHeader->nColorMapLength + pHeader->nColorMapFirst <= 0x100
                && (pHeader->nColorMapDepth == 24 || pHeader->nColorMapDepth == 32)))
        {
            if (!(pHeader->nDescriptor & 0xC0))
            {
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall sub_006C50D0_Emit(const D2TargaHeaderStrc* pHeader, int nFallback)
{
    if (sub_006C50D0_IsSupportedTgaHeader(pHeader))
    {
        return 1;
    }
    return nFallback;
}
