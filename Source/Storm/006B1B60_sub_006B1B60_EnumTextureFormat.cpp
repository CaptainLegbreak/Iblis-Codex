struct D2PixelFormat006B1B60Strc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};
extern D2PixelFormat006B1B60Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned long gnFormatCap_006CE28C; // 0x006CE28C

// 0x006B1B60
int __stdcall sub_006B1B60_EnumTextureFormat(D2PixelFormat006B1B60Strc* pFormat, unsigned long* pFlags)
{
    if (!pFlags)
    {
        return 1;
    }
    if (pFormat->dwFlags != gtWantedFormat_0074C024.dwFlags)
    {
        return 1;
    }
    if (pFormat->dwRGBBitCount != gtWantedFormat_0074C024.dwRGBBitCount)
    {
        return 1;
    }
    if (pFormat->dwRBitMask != gtWantedFormat_0074C024.dwRBitMask)
    {
        return 1;
    }
    if (pFormat->dwGBitMask != gtWantedFormat_0074C024.dwGBitMask)
    {
        return 1;
    }
    if (pFormat->dwBBitMask != gtWantedFormat_0074C024.dwBBitMask)
    {
        return 1;
    }
    if (pFormat->dwRGBAlphaBitMask != gtWantedFormat_0074C024.dwRGBAlphaBitMask)
    {
        return 1;
    }
    *pFlags |= gnFormatCap_006CE28C;
    return 1;
}

#include "gen/data/Source/Storm/006B1B60_sub_006B1B60_EnumTextureFormat.inc"
