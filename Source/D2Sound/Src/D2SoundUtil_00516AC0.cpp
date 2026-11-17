#include "D2Sound.h"

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* lpFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* lpSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) void* __stdcall CreateFileMappingA(void* hFile, void* lpAttributes, unsigned long flProtect, unsigned long dwMaximumSizeHigh, unsigned long dwMaximumSizeLow, const char* lpName); // 0x006CC314
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(void* hFileMappingObject, unsigned long dwDesiredAccess, unsigned long dwFileOffsetHigh, unsigned long dwFileOffsetLow, unsigned long dwNumberOfBytesToMap); // 0x006CC310
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(const void* lpBaseAddress); // 0x006CC2F8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
struct D2VxdResourceStrc
{
    int unk0x00[2];
    unsigned long nSize;
    unsigned char pData[4];
};
struct D2VxdHeaderStrc
{
    unsigned long dwSignature;
    unsigned char unk0x04[0xB4];
    unsigned long dwResourceOffset;
    unsigned long dwResourceLength;
};
struct D2DosHeaderStrc
{
    unsigned short f_0;
    unsigned short unk0x02[29];
    long nHeaderOffset;
};

// 0x00516AC0
int __fastcall sub_00516AC0_ReadVxdVersionResource(const char* szFileName, unsigned long* pSize, void* pBuffer)
{
    void* hFile = 0;
    void* hMapping = 0;
    void* pView = 0;
    int bResult = 0;
    __try
    {
        hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0, 0);
        if (hFile == (void*)-1)
            __leave;

        hMapping = CreateFileMappingA(hFile, 0, 2, 0, 0, 0);
        if (!hMapping)
            __leave;

        pView = MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (!pView)
            __leave;

        const D2DosHeaderStrc* pDos = (const D2DosHeaderStrc*)pView;
        if (pDos->f_0 != 0x5A4D)
        {
            SetLastError(0x0B);
            __leave;
        }

        const D2VxdHeaderStrc* pHeader = (const D2VxdHeaderStrc*)((const char*)pDos + pDos->nHeaderOffset);
        if (pHeader->dwSignature != 0x454C)
        {
            SetLastError(0x0B);
            __leave;
        }

        if (!pHeader->dwResourceLength)
        {
            *pSize = 0;
            SetLastError(0x714);
            __leave;
        }

        const D2VxdResourceStrc* pResource = (const D2VxdResourceStrc*)((const char*)pDos + pHeader->dwResourceOffset);
        const unsigned long nSize = pResource->nSize;
        const unsigned char* pData = pResource->pData;
        if (pBuffer && *pSize >= nSize)
        {
            memset(pBuffer, 0, *pSize);
            memcpy(pBuffer, pData, nSize);
            *pSize = nSize;
            SetLastError(0);
            bResult = 1;
        }
        else
        {
            *pSize = nSize;
            SetLastError(0x7A);
        }
    }
    __finally
    {
        const unsigned long dwError = GetLastError();
        if (pView)
            UnmapViewOfFile(pView);
        if (hMapping)
            CloseHandle(hMapping);
        if (hFile != (void*)-1)
            CloseHandle(hFile);
        SetLastError(dwError);
    }

    return bResult;
}
