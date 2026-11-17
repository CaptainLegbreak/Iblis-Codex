int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* pFile);                          // 0x00516E84
unsigned int __fastcall sub_00516EAB_FileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                // 0x0040B380

// 0x00517079
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine)
{
    void* hFile;
    if (!sub_00516E46_OpenFile(hArchive, szFilePath, &hFile, 0))
    {
        return 0;
    }

    unsigned int dwFileSizeHigh;
    unsigned int dwFileSize = sub_00516EAB_FileSize(hArchive, hFile, &dwFileSizeHigh);
    void* pBuffer = FOG_Alloc(dwFileSize + 800, ".\\SRC\\Archive.cpp", 207, 0);
    if (!pBuffer)
    {
        return 0;
    }

    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwFileSize);
    sub_00516E84_CloseFile(hArchive, hFile);

    if (pdwBytesWritten)
    {
        *pdwBytesWritten = dwFileSize;
    }

    return pBuffer;
}
