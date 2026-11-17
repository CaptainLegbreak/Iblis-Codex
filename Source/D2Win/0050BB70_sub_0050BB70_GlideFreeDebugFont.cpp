int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern unsigned char* gpGlideDebugFontGlyphs_0088044C;                                                      // 0x0088044C

// 0x0050BB70
void __cdecl sub_0050BB70_GlideFreeDebugFont()
{
    if (gpGlideDebugFontGlyphs_0088044C)
    {
        FOG_Free(gpGlideDebugFontGlyphs_0088044C, ".\\Src\\glDebugFont.cpp", 0xFB, 0);
        gpGlideDebugFontGlyphs_0088044C = 0;
    }
}
