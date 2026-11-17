int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
struct SCompBufferState
{
#ifdef MOVED_TEST
    unsigned int moved_prefix;
#endif
    void* pMemory;
};
SCompBufferState gSCompBuffer_0077920C;         // 0x0077920C
#ifdef MOVED_TEST
#define FREE_LINE 0x735
#else
#define FREE_LINE 0x733
#endif
// 0x0041E8C0
extern "C" int __cdecl sub_0041E8C0_ReleaseBuffer()
{
    if (gSCompBuffer_0077920C.pMemory)
    {
        SMemFree(gSCompBuffer_0077920C.pMemory, ".\\SOURCE\\SCOMP.CPP", FREE_LINE, 0);
        gSCompBuffer_0077920C.pMemory = 0;
    }
    return 1;
}
