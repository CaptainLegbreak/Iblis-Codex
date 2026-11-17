int __stdcall sub_00419980(const char* szFileName, void** phFile);                                       // 0x00419980
int __stdcall sub_0041AAD0_StormReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);                        // 0x00416370

// 0x004068E0
int __fastcall sub_004068E0(const char* szFileName, void** phFile)
{
    return sub_00419980(szFileName, phFile);
}

// 0x00406900
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6)
{
    return sub_0041AAD0_StormReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped, nArg6, nArg7);
}

// 0x00406930
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh)
{
    return sub_00416370_StormGetFileSize(hFile, pnSizeHigh);
}
