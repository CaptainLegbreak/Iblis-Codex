void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);                       // 0x004192F0
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);                       // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
int __stdcall sub_0041AAD0_StormReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7);
int __stdcall sub_004198D0(void* pArg);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x0041AF60
int __stdcall sub_0041AF60_StormLoadFile(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, void* pOverlapped, int nArg8)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    if (ppBuffer)
        *ppBuffer = 0;
    else
        nValid = 0;
    VALIDATEEND;
    if (pSize)
        *pSize = 0;
    void* pBuffer = 0;
    void* hFile = 0;
    if (SFileOpenFileEx(hMpq, szFileName, nFlags, &hFile))
    {
        unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
        pBuffer = SMemAlloc(nSize + nExtraSize, ".\\SOURCE\\SFILE.CPP", 0xFEA, 0);
        if (sub_0041AAD0_StormReadFile(hFile, pBuffer, nSize, 0, pOverlapped, nArg8, 0))
        {
            if (nExtraSize)
                SMemZero(nSize + (char*)pBuffer, nExtraSize);
            *ppBuffer = pBuffer;
            if (pSize)
                *pSize = nSize;
        }
        else if (pBuffer)
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1000, 0);
    }
    if (hFile)
        sub_004198D0(hFile);
    return *ppBuffer != 0;
}
