extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern unsigned char* gpBuffer_007C9154; // 0x007C9154
extern int gnStride_007C9138; // 0x007C9138
extern int gnRows_007C913C; // 0x007C913C

// 0x006C9220
void __stdcall sub_006C9220_ClearBuffer(int bPartial)
{
    if (bPartial)
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * (gnRows_007C913C - 47));
    }
    else
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * gnRows_007C913C);
    }
}
