#include "D2GameTypes.h"
#include "D2SFileTypes.h"
#include "D2StormTypes.h"

struct D2StormHashBufferStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile);
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __fastcall sub_0041D3B0_NewHashBuffer(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize);
unsigned int __fastcall sub_0041D410_GetWindow(D2StormHashBufferStrc* pBuffer);
void __fastcall sub_0041D420_HashBuffered(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize);
int __fastcall sub_0041D6D0_VerifyHashBuffer(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus);
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags);

extern "C" const unsigned char gabSignatureModulus_006CEF78[0x100];                                         // 0x006CEF78
extern "C" const unsigned char gabSignatureExponent_006CF078[4];                                            // 0x006CF078
extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
void* gpDirectSound_00778F20;                                                                               // 0x00778F20

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return nValid; }

static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

// 0x00415BB0
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (!nArg3 && !nArg5)
    {
        nArg3 = (int)gabSignatureModulus_006CEF78;
        nArg4 = 0x100;
        nArg5 = (int)gabSignatureExponent_006CF078;
        nArg6 = 4;
    }
    if (!pnResult)
    {
        unsigned int nDummy;
        pnResult = &nDummy;
    }
    *pnResult = 0;
    D2StormArchiveRecStrc* pArchive;
    if (!sub_00415930_GetArchiveRec(hArchive, &pArchive))
    {
        return 0;
    }
    D2StormHashBufferStrc* pHash = 0;
    sub_0041D3B0_NewHashBuffer(&pHash, nArg4, nArg6);
    EnterCriticalSection(&gBasePathLock_00779068);
    char* pBuffer = (char*)SMemAlloc(0x10000, ".\\SOURCE\\SFILE.CPP", 0xB33, 0);
    unsigned long nPosition = SetFilePointer(pArchive->hFile, 0, 0, 1);
    if (nPosition != (unsigned long)-1 && SetFilePointer(pArchive->hFile, pArchive->nArchiveOffset, 0, 0) != (unsigned long)-1)
    {
        unsigned int nRemaining = sub_0041D410_GetWindow(pHash) + pArchive->pHeader->nArchiveSize;
        while (nRemaining)
        {
            unsigned int nChunk = nRemaining > 0x10000 ? 0x10000 : nRemaining;
            unsigned long nRead = 0;
            nRemaining -= nChunk;
            if (!ReadFile(pArchive->hFile, pBuffer, nChunk, &nRead, 0) || nRead != nChunk)
            {
                goto done;
            }
            sub_0041D420_HashBuffered(pHash, pBuffer, nChunk);
        }
        SetFilePointer(pArchive->hFile, nPosition, 0, 0);
    }
done:
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB59, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    unsigned int nResult = sub_0041D6D0_VerifyHashBuffer(pHash, (const void*)nArg3, (const void*)nArg5) ? 5 : 1;
    *pnResult = nResult;
    return nResult == 5;
}

// 0x00415D50
unsigned int __stdcall sub_00415D50_ChecksumFile(const char* szFileName)
{
    int nValid = (__int64)szFileName ? -1 : 0;
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    unsigned int nCrc = 0;
    unsigned long nSize = GetFileSize(hFile, 0);
    if (nSize != (unsigned long)-1)
    {
        unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, ".\\SOURCE\\SFILE.CPP", 0xB83, 0);
        sub_0041D810_Crc32(0, 0, &nCrc, 1);
        while (nSize > 0)
        {
            unsigned long nChunk = nSize < 0x1000 ? nSize : 0x1000;
            unsigned long nRead;
            ReadFile(hFile, pBuffer, nChunk, &nRead, 0);
            if (nChunk != nRead)
            {
                if (pBuffer)
                {
                    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB8D, 0);
                }
                CloseHandle(hFile);
                LeaveCriticalSection(&gBasePathLock_00779068);
                return 0;
            }
            sub_0041D810_Crc32(pBuffer, nChunk, &nCrc, 2);
            nSize -= nChunk;
        }
        sub_0041D810_Crc32(0, 0, &nCrc, 4);
        if (pBuffer)
        {
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB97, 0);
        }
    }
    CloseHandle(hFile);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nCrc;
}

// 0x00415EE0
extern "C" int __stdcall SFileDdaInitialize(int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(nValue);
    VALIDATEEND;
    gpDirectSound_00778F20 = (void*)nValue;
    return nValid ? 1 : 0;
}

#include "gen/data/Source/Storm/SOURCE/SFILE_00415BB0.inc"
