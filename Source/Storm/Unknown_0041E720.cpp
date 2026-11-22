#include "SValidate.h"

#define OVERLAP(a, b, n) ((a) + (n) > (b) && (b) + (n) > (a))

typedef void (__fastcall* PFNSCOMPDECOMPRESS)(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int nExtra);

struct D2SCompDecompStrc
{
    unsigned int dwMask;
    PFNSCOMPDECOMPRESS pfnDecompress;
};

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                         // 0x0041C340
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __fastcall PkwareDecompress(char* pDst, unsigned int* pDstLen, char* pSrc, unsigned int nSrcLen, int nUnused); // 0x0041E000
int __fastcall ZlibDecompress(unsigned char* pOut, unsigned long* pOutSize, const unsigned char* pIn, unsigned long nInSize, int nUnused); // 0x0041E340
void __fastcall ImaAdpcmMonoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused); // 0x0041E3A0
void __fastcall ImaAdpcmStereoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused); // 0x0041E400
void __fastcall HuffmanDecompress(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int nExtra); // 0x0041F9E0

// build: symbol _gtDecompTable_006CFEC4 0x006CFEC4
#include "gen/data/Source/Storm/Unknown_0041E720.static/gtDecompTable_006CFEC4.inc"
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
        gpWorkBuffer_0077920C = SMemAlloc(nSize, gszSCompFile_006CFEEC, 0x620, 0);
        gdwWorkBufferOwner_00779210 = 0;
    }
    else if (gdwWorkBufferOwner_00779210)
    {
        void* pBuffer = SMemAlloc(nSize, gszSCompFile_006CFEEC, 0x626, 0);
        *pbShared = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return pBuffer;
    }
    if (gnWorkBufferSize_00779208 < nSize)
    {
        SMemFree(gpWorkBuffer_0077920C, gszSCompFile_006CFEEC, 0x62F, 0);
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, gszSCompFile_006CFEEC, 0x631, 0);
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
    SMemFree(pBuffer, gszSCompFile_006CFEEC, 0x647, 0);
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
}

// 0x0041E720
int __stdcall SCompDecompress(void* pDest, unsigned int* pdwDestSize, unsigned char* pSrc, unsigned int dwSrcSize, int nExtra)
{
    unsigned int dwDestSize = *pdwDestSize;
    VALIDATEBEGIN;
    VALIDATE(pDest);
    VALIDATE(dwDestSize >= dwSrcSize);
    VALIDATE(pSrc);
    VALIDATE(dwSrcSize >= sizeof(unsigned char));
    VALIDATEEND;

    if (dwSrcSize == dwDestSize)
    {
        if (pDest != pSrc)
            SMemCopy(pDest, pSrc, dwSrcSize);
        return 1;
    }

    unsigned int dwTypes = *pSrc++;
    dwSrcSize--;
    unsigned int nCount = 0;
    unsigned int dwUnknown = dwTypes;
    for (int i = 4; i >= 0; --i)
    {
        if (dwTypes & gtDecompTable_006CFEC4[i].dwMask)
            ++nCount;
        dwUnknown &= ~gtDecompTable_006CFEC4[i].dwMask;
    }
    if (dwUnknown)
        return 0;

    int bShared = 0;
    unsigned char* pWork = 0;
    if (nCount >= 2 || (OVERLAP((unsigned char*)pDest, pSrc, dwSrcSize) && nCount))
        pWork = (unsigned char*)s_AllocDecompressBuffer(dwDestSize, &bShared);

    unsigned char* pIn = pSrc;
    unsigned int cbIn = dwSrcSize;
    for (int i = 4; i >= 0; --i)
    {
        if (dwTypes & gtDecompTable_006CFEC4[i].dwMask)
        {
            --nCount;
            unsigned char* pOut = (nCount & 1) ? pWork : (unsigned char*)pDest;
            if (OVERLAP(pOut, pIn, cbIn))
                pOut = OVERLAP(pOut, pWork, cbIn) ? (unsigned char*)pDest : pWork;
            unsigned int cbOut = dwDestSize;
            gtDecompTable_006CFEC4[i].pfnDecompress(pOut, &cbOut, pIn, cbIn, nExtra);
            cbIn = cbOut;
            pIn = pOut;
        }
    }

    if (pIn != pDest)
        SMemCopy(pDest, pIn, cbIn);
    *pdwDestSize = cbIn;
    sub_0041E510_FreeWorkBuffer(bShared, pWork);
    return 1;
}
