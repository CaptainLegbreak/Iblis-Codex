int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* gpGlideBuffer_0087F0C8;                                                                               // 0x0087F0C8
void* gpGlideBuffer_0087F0CC;                                                                               // 0x0087F0CC

// 0x0050A0C0
void __cdecl sub_0050A0C0_FreeSpriteBuffers()
{
    if (gpGlideBuffer_0087F0C8)
    {
        FOG_Free(gpGlideBuffer_0087F0C8, ".\\Src\\glSprite.cpp", 0x74, 0);
        gpGlideBuffer_0087F0C8 = 0;
    }
    if (gpGlideBuffer_0087F0CC)
    {
        FOG_Free(gpGlideBuffer_0087F0CC, ".\\Src\\glSprite.cpp", 0x7A, 0);
        gpGlideBuffer_0087F0CC = 0;
    }
}
