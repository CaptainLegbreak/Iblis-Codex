int gnStormDirectFlags_00779058;                                                                            // 0x00779058
int __cdecl sub_00418B50();                                                                         // 0x00418B50
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
int __stdcall sub_0041AF60_StormLoadFile(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped, int nArg8); // 0x0041AF60

// 0x00415F70
int __stdcall sub_00415F70(int nFlags)
{
    gnStormDirectFlags_00779058 = nFlags;
    return 1;
}

// 0x00419980
int __stdcall sub_00419980(const char* szFileName, void** phFile)
{
    return SFileOpenFileEx(0, szFileName, sub_00418B50(), phFile);
}

// 0x0041B680
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped)
{
    return sub_0041AF60_StormLoadFile(hMpq, szFileName, ppBuffer, pnSize, nExtraBytes, nFlags, pOverlapped, 0);
}
