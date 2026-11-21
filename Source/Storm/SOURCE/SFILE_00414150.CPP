#include "D2GameTypes.h"
struct D2StormSoundBuffer;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* lpRootPathName, unsigned long* lpSectorsPerCluster, unsigned long* lpBytesPerSector, unsigned long* lpNumberOfFreeClusters, unsigned long* lpTotalNumberOfClusters); // 0x006CC270
extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char* lpRootPathName, char* lpVolumeNameBuffer, unsigned long nVolumeNameSize, unsigned long* lpVolumeSerialNumber, unsigned long* lpMaximumComponentLength, unsigned long* lpFileSystemFlags, char* lpFileSystemNameBuffer, unsigned long nFileSystemNameSize); // 0x006CC2E8
extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char* lpRootPathName);         // 0x006CC2EC

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __fastcall bjhash(const unsigned char* k, unsigned int nLength, unsigned int nInitVal); // 0x00413F30
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

// 0x00414150
unsigned int __stdcall SStrHashHT(const char* szPath)
{
    char szBuffer[0x400];
    char* p = szBuffer;
    unsigned int nLength = 0;
    unsigned int c;
    while ((c = (unsigned char)*szPath) != 0)
    {
        ++szPath;
        if (nLength >= 0x3FF)
            break;
        if (c - 'a' <= 25)
            c -= 0x20;
        else if (c == '/')
            c = '\\';
        *p++ = (char)c;
        ++nLength;
    }
    *p = 0;
    return bjhash((const unsigned char*)szBuffer, nLength, 0);
}

struct D2StormExplodeParamStrc
{
    const char* pSource;
    unsigned int nSourcePos;
    char* pDest;
    unsigned int nDestPos;
    unsigned int nSourceSize;
};

extern char* gpStormExplodeWork;                                                                            // 0x0077903C
D2CriticalSectionStrc gStormExplodeLock;                                                                    // 0x00779080

unsigned int __cdecl sub_004151D0_ExplodeRead(char* pBuffer, unsigned int* pnSize, void* pParam);          // 0x004151D0
void __cdecl sub_00415210_ExplodeWrite(char* pBuffer, unsigned int* pnSize, void* pParam);                 // 0x00415210
extern "C" unsigned int __cdecl sub_006B01B0_Explode(unsigned int (__cdecl* pRead)(char*, unsigned int*, void*), void (__cdecl* pWrite)(char*, unsigned int*, void*), char* pWork, void* pParam); // 0x006B01B0

// 0x00415240
int __stdcall sub_00415240_Explode(char* pDest, const char* pSource, unsigned int nSourceSize)
{
    EnterCriticalSection(&gStormExplodeLock);
    if (!gpStormExplodeWork)
        gpStormExplodeWork = (char*)SMemAlloc(0x3134, ".\\SOURCE\\SFILE.CPP", 0x2C9, 0);
    D2StormExplodeParamStrc tParam;
    tParam.pSource = pSource;
    tParam.nSourcePos = 0;
    tParam.pDest = pDest;
    tParam.nDestPos = 0;
    tParam.nSourceSize = nSourceSize;
    sub_006B01B0_Explode(sub_004151D0_ExplodeRead, sub_00415210_ExplodeWrite, gpStormExplodeWork, &tParam);
    LeaveCriticalSection(&gStormExplodeLock);
    return 1;
}

// 0x00415960
int __stdcall sub_00415960_CheckVolume(const char* szPath)
{
    char szRoot[4];
    SStrCopy(szRoot, szPath, 4);
    unsigned int nDriveType = GetDriveTypeA(szRoot);
    char szFileSystem[0x104];
    unsigned long dwFlags = 0;
    SMemZero(szFileSystem, 0x104);
    if (!GetVolumeInformationA(szRoot, 0, 0, 0, 0, &dwFlags, szFileSystem, 0x104))
        return 0;
    unsigned long dwSectorsPerCluster = 0;
    unsigned long dwBytesPerSector = 0;
    unsigned long dwFreeClusters = 0;
    unsigned long dwTotalClusters = 0;
    if (!GetDiskFreeSpaceA(szRoot, &dwSectorsPerCluster, &dwBytesPerSector, &dwFreeClusters, &dwTotalClusters))
        return 0;
    unsigned int nKey = (dwFlags & 4) ^ *(unsigned int*)szFileSystem ^ dwFreeClusters ^ dwBytesPerSector ^ nDriveType;
    unsigned short wKey = (unsigned short)((nKey >> 16) ^ nKey);
    return wKey == 0x1F00 || wKey == 0x805;
}

int __cdecl sub_00418B50();                                                                         // 0x00418B50
int __stdcall sub_0041AAD0_StormReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0
int __stdcall SFileLoadFileEx2(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, void* pOverlapped, int nArg8); // 0x0041AF60
int __stdcall SFileDdaBeginEx(void* hFile, unsigned int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2StormSoundBuffer* pBuffer); // 0x0041B280

// 0x0041B050
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped)
{
    return sub_0041AAD0_StormReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped, 0, 0);
}

// 0x0041B080
int __stdcall SFileReadFileEx(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6)
{
    return sub_0041AAD0_StormReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped, 0, nArg6);
}

// 0x0041B650
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped)
{
    return SFileLoadFileEx2(0, szFileName, ppBuffer, pSize, nExtraSize, sub_00418B50(), pOverlapped, 0);
}

// 0x0041BA30
int __stdcall SFileDdaBegin(void* hFile, int nBufferSize, unsigned int nFlags)
{
    return SFileDdaBeginEx(hFile, nBufferSize, nFlags, 0, 0x7FFFFFFF, 0x7FFFFFFF, 0);
}
