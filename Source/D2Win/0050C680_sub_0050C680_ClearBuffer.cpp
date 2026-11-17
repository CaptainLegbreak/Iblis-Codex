extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int color, unsigned int alpha, unsigned int depth); // 0x0087EB88

// 0x0050C680
void __cdecl sub_0050C680_ClearBuffer()
{
    gpfGlideBufferClear_0087EB88(0, 0, 0);
}
