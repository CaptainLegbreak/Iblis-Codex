#include "SValidate.h"

#define OVERLAP(a, b, n) ((a) + (n) > (b) && (b) + (n) > (a))

typedef void (__fastcall* PFNSCOMPCOMPRESS)(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int* pnCmpType, int nCmpLevel);

struct D2SCompCompStrc
{
    unsigned int dwMask;
    PFNSCOMPCOMPRESS pfnCompress;
};

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                         // 0x0041C340
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0

// build: symbol _gtCompTable_006CFE9C 0x006CFE9C
#include "gen/data/Source/Storm/Unknown_0041E570.static/gtCompTable_006CFE9C.inc"
#include "D2GameTypes.h"


void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" const char gszSCompFile_006CFEEC[];                                                              // 0x006CFEEC
static unsigned int gnWorkBufferSize_00779208;                                                              // 0x00779208
static void* gpWorkBuffer_0077920C;                                                                         // 0x0077920C
static unsigned long gdwWorkBufferOwner_00779210;                                                           // 0x00779210
static D2CriticalSectionStrc gtWorkBufferLock_00779214;                                                     // 0x00779214

static void* s_AllocDecompressBuffer(unsigned int nSize, int* pbShared);
static void __stdcall sub_0041E510_FreeWorkBuffer(int bShared, void* pBuffer);

// 0x0041E440
static void* s_AllocDecompressBuffer(unsigned int nSize, int* pbShared)
{
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    const unsigned long dwThreadId = GetCurrentThreadId();
    if (!gpWorkBuffer_0077920C)
    {
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x620, 0);
        gdwWorkBufferOwner_00779210 = 0;
    }
    else if (gdwWorkBufferOwner_00779210)
    {
        void* pBuffer = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x626, 0);
        *pbShared = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return pBuffer;
    }
    if (gnWorkBufferSize_00779208 < nSize)
    {
        SMemFree(gpWorkBuffer_0077920C, ".\\SOURCE\\SCOMP.CPP", 0x62F, 0);
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x631, 0);
    }
    *pbShared = 1;
    gdwWorkBufferOwner_00779210 = dwThreadId;
    void* pBuffer = gpWorkBuffer_0077920C;
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
    return pBuffer;
}

// 0x0041E510
static void __stdcall sub_0041E510_FreeWorkBuffer(int bShared, void* pBuffer)
{
    if (!pBuffer)
    {
        return;
    }
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    if (bShared)
    {
        gdwWorkBufferOwner_00779210 = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return;
    }
    SMemFree(pBuffer, ".\\SOURCE\\SCOMP.CPP", 0x647, 0);
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
}

// 0x0041E570
int __stdcall SCompCompress(unsigned char* pDest, unsigned int* pdwDestSize, unsigned char* pSrc, unsigned int dwSrcSize, unsigned int dwMask, int nCmpType, int nCmpLevel)
{
    VALIDATEBEGIN;
    VALIDATE(pDest);
    VALIDATE(pdwDestSize);
    VALIDATE(*pdwDestSize >= dwSrcSize);
    VALIDATE(pSrc);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }

    unsigned int nCount = 0;
    unsigned int dwUnknown = dwMask;
    for (int i = 0; i < 5; ++i)
    {
        if (dwMask & gtCompTable_006CFE9C[i].dwMask)
            ++nCount;
        dwUnknown &= ~gtCompTable_006CFE9C[i].dwMask;
    }
    if (dwUnknown)
        return 0;

    int bShared = 0;
    unsigned char* pWork = 0;
    if (nCount >= 2 || (OVERLAP(pDest, pSrc, dwSrcSize) && nCount))
        pWork = (unsigned char*)s_AllocDecompressBuffer(dwSrcSize, &bShared);

    unsigned char* pIn = pSrc;
    unsigned int cbIn = dwSrcSize;
    for (int i = 0; i < 5; ++i)
    {
        if (gtCompTable_006CFE9C[i].dwMask & dwMask)
        {
            --nCount;
            unsigned char* pOut = (nCount & 1) ? pWork : pDest + 1;
            if (OVERLAP(pOut, pIn, cbIn))
                pOut = OVERLAP(pOut, pWork, cbIn) ? pDest + 1 : pWork;
            unsigned int cbOut = cbIn - 1;
            gtCompTable_006CFE9C[i].pfnCompress(pOut, &cbOut, pIn, cbIn, &nCmpType, nCmpLevel);
            if (cbOut + 1 < cbIn)
            {
                pIn = pOut;
                cbIn = cbOut;
            }
            else
            {
                dwMask &= ~gtCompTable_006CFE9C[i].dwMask;
            }
        }
    }

    if (pIn != pDest)
    {
        if (pIn == pDest + 1)
        {
            *pDest = (unsigned char)dwMask;
            ++cbIn;
        }
        else if (dwMask)
        {
            SMemCopy(pDest + 1, pIn, cbIn);
            *pDest = (unsigned char)dwMask;
            ++cbIn;
        }
        else
        {
            SMemCopy(pDest, pIn, cbIn);
        }
    }
    *pdwDestSize = cbIn;
    sub_0041E510_FreeWorkBuffer(bShared, pWork);
    return 1;
}
