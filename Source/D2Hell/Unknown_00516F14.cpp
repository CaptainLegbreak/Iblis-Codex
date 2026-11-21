#include "D2Hell.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940
int __stdcall sub_00416230_GetFileName(void*, char*, unsigned int); // 0x00416230
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* pFile); // 0x00516E84
unsigned int __fastcall sub_00516EAB_FileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

// 0x00516F14
int __fastcall sub_00516F14_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod)
{
    char name[0x104];
    D2_ASSERT(file, 0x70);
    int nResult = sub_00406940_mpqSetFilePointer(file, nOffset, pnOffsetHigh, nMethod);
    if (nResult != -1)
    {
        return nResult;
    }

    sub_00416230_GetFileName(file, name, 0x104);
    D2_ASSERT(0, 0x79);
}

// 0x00516F85
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead)
{
    D2_ASSERT(hFile, 0x87);

    int dwBytes;
    if (!sub_00406900(hFile, pBuffer, dwBytesToRead, &dwBytes, 0, 0, 0))
    {
        char szArchivePath[0x104];
        sub_00416230_GetFileName(hFile, szArchivePath, sizeof(szArchivePath));
        D2_ASSERT(0, 0x8F);
    }

    D2_ASSERT(dwBytesToRead == dwBytes, 0x92);
}

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
