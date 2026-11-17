int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned char* gpGlideTileDecodeBuffer_00880BFC;                                                            // 0x00880BFC
unsigned char* gpGlideFloorDecodeBuffer_00880C00;                                                           // 0x00880C00

// 0x0050F8C0
void __cdecl sub_0050F8C0_GlideShutdownStep()
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
