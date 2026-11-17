typedef unsigned int size_t;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650
void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020

// build: symbol ??_U@YAPAXI@Z 0x00527680
// build: symbol ??_V@YAXPAX@Z 0x00527660
// 0x00527660
void __cdecl operator delete[](void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete[]", -1, 0);
    }
}

// 0x00527680
void* __cdecl operator new[](size_t nSize)
{
    return SMemAlloc(nSize, "new[]", -1, 0);
}
