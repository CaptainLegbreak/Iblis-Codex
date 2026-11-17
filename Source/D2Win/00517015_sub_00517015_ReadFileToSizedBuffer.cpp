extern "C" const char gszEmptyAssertText;                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* pFile);                          // 0x00516E84
unsigned int __fastcall sub_00516EAB_FileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

// 0x00517015
unsigned int __fastcall sub_00517015_ReadFileToSizedBuffer(void* hArchive, const char* szFilePath, void* pBuffer, unsigned int dwBufferSize)
{
    void* hFile;
    sub_00516E46_OpenFile(hArchive, szFilePath, &hFile, 0);
    D2_ASSERT(dwBufferSize >= sub_00516EAB_FileSize(hArchive, hFile, 0), 0xA5);
    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwBufferSize);
    sub_00516E84_CloseFile(hArchive, hFile);
    return dwBufferSize;
}
