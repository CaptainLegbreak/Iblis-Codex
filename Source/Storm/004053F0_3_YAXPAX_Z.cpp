typedef unsigned int size_t;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650
void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020

extern "C" const char gszNew_006CC82C[];                                                                    // 0x006CC82C

// build: symbol ??3@YAXPAX@Z 0x004053F0
void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
}

// build: symbol ??2@YAPAXI@Z 0x00405410
void* __cdecl operator new(size_t nSize)
{
    return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
}
