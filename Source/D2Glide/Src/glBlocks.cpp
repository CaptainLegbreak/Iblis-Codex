#include "D2Glide.h"

unsigned char* gpGlideTileDecodeBuffer_00880BFC;                                                            // 0x00880BFC
unsigned char* gpGlideFloorDecodeBuffer_00880C00;                                                           // 0x00880C00

extern D2GrTexInfoStrc gGlideFloorTexInfo_0072F6BC; // 0x0072F6BC

extern D2GrTexInfoStrc gGlideTileTexInfo_0072F6A8; // 0x0072F6A8

// 0x0050F8C0
void __cdecl GLIDE_FreeBlockBuffers()
{
    if (gpGlideTileDecodeBuffer_00880BFC)
    {
        FOG_Free(gpGlideTileDecodeBuffer_00880BFC, ".\\Src\\glBlocks.cpp", 0x3F, 0);
        gpGlideTileDecodeBuffer_00880BFC = 0;
    }
    if (gpGlideFloorDecodeBuffer_00880C00)
    {
        FOG_Free(gpGlideFloorDecodeBuffer_00880C00, ".\\Src\\glBlocks.cpp", 0x45, 0);
        gpGlideFloorDecodeBuffer_00880C00 = 0;
    }
}

// 0x0050F870
void __cdecl GLIDE_InitBlockBuffers()
{
    gpGlideTileDecodeBuffer_00880BFC = (unsigned char*)FOG_Alloc(0x400, ".\\Src\\glBlocks.cpp", 0x33, 0);
    gpGlideFloorDecodeBuffer_00880C00 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glBlocks.cpp", 0x34, 0);
    gGlideTileTexInfo_0072F6A8.pData = gpGlideTileDecodeBuffer_00880BFC;
    gGlideFloorTexInfo_0072F6BC.pData = gpGlideFloorDecodeBuffer_00880C00;
}
