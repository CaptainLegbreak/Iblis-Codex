#include "Fog.h"
#include "D2GameTypes.h"
#include "D2Primitives.h"
#include "D2StormTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct T00410B70;
struct D2BitBufferStrc;
struct D2BitCodeStrc;
struct Obj00410E90;
struct D2TimedRecordStrc;
struct D2CriticalSectionStrc;

struct T00410B70 { unsigned char bytes[1]; };

enum { BIT_MASK = 7 };

typedef unsigned char Byte;

typedef unsigned int Word;

enum { ROUND_BITS = 7, TAIL_HIGH = 2 };

struct D2BitCodeStrc
{
    int nValue;
    int nBits;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwLowMasks_006CE368[]; // 0x006CE368
unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00410F60

struct Obj00410E90 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    int nValue08;
    int nFlag0C;
};

struct D2TimedRecordStrc
{
    __int64 qwValue;
    char unk0x08[0x10];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
extern "C" void* __cdecl memset(void*, int, unsigned int);

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __cdecl SMemInitialize(); // 0x00411CD0
void __cdecl sub_00411A20_InitPageSize(); // 0x00411A20
void __fastcall sub_00411A80_ReleaseBlock(D2SMemHeapStrc** ppLink); // 0x00411A80
void __cdecl AUTOMAP_ReleaseFreeBlocks(); // 0x00412000
extern "C" const char szSMemAlloc_006CEDCC[]; // 0x006CEDCC
extern int gbCallerFirst_00708340; // 0x00708340
extern unsigned int gnHeapId_00708344; // 0x00708344
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern unsigned int gnPageSize_00776CB8; // 0x00776CB8
extern int gnFlag2_00776CBC; // 0x00776CBC
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern int gnFlag1_007784C0; // 0x007784C0
extern int gnFlag0_007784C4; // 0x007784C4
extern int gabFreeBlockDirty[0x100]; // 0x007784C8
extern D2SMemHeapStrc* gpFreeBlockSweep_007788C8; // 0x007788C8
extern int gnFlag3_007788CC; // 0x007788CC
extern int gbHeapInitialized_007788D0; // 0x007788D0
extern int gnFlag_00779098; // 0x00779098
static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError);
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);

void* __stdcall SMemHeapAlloc(unsigned int hHeap, unsigned int dwFlags, unsigned int nSize);

// 0x00410B70
void __stdcall sub_00410B70(T00410B70* buffer,int bit)
{
    buffer->bytes[bit >> 3] ^= (unsigned char)gdwBitMasks[bit & BIT_MASK];
}

// 0x00410B90
void __stdcall sub_00410B90(const Byte* first,const Byte* second,Byte* output,int bitCount)
{
    bitCount=(bitCount+ROUND_BITS)/8;
    int wholeBytes=(bitCount/4)*4;
    int i=0;
    for (;i<wholeBytes;i+=4) *(Word*)(output+i)=*(const Word*)(first+i)&*(const Word*)(second+i);
    switch (bitCount-wholeBytes) {
    case 3: output[i+TAIL_HIGH]=first[i+TAIL_HIGH]&second[i+TAIL_HIGH];
    case 2: output[i+1]=first[i+1]&second[i+1];
    case 1: output[i]=first[i]&second[i];
    }
}

// 0x00410D90
void __stdcall sub_00410D90_XorBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] ^ *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] ^ pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] ^ pB[i + 1];
    case 1:
        pOut[i] = pA[i] ^ pB[i];
    }
}

// 0x00410E40
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize)
{
    D2_ASSERT(pBuffer, 316);
    pBuffer->pBuffer = pBitStream;
    pBuffer->nBits = 8 * nSize;
    pBuffer->nPos = 0;
    pBuffer->nPosBits = 0;
    pBuffer->bFull = 0;
}

// 0x00410EB0
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits)
{
    if (pBuffer->nPosBits + 8 * pBuffer->nPos + nBits > pBuffer->nBits)
    {
        pBuffer->bFull = 1;
        pBuffer->nPos = pBuffer->nBits / 8;
        pBuffer->nPosBits = 0;
        return;
    }
    if (!pBuffer->nPosBits)
    {
        *pBuffer->pBuffer = 0;
    }
    while (nBits > 0)
    {
        int n = 8 - pBuffer->nPosBits;
        if (n > nBits)
        {
            n = nBits;
        }
        *pBuffer->pBuffer |= (unsigned char)(gdwLowMasks_006CE368[n] & nValue) << pBuffer->nPosBits;
        pBuffer->nPosBits += n;
        if (pBuffer->nPosBits != 8)
        {
            break;
        }
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
        nValue >>= n;
        nBits -= n;
    }
}

// 0x00411020
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00410F60_ReadBits(pBuffer, nBits);
}

// 0x00411030
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits)
{
    int nValue = sub_00410F60_ReadBits(pBuffer, nBits);
    if (nBits < 32 && ((1 << (nBits - 1)) & nValue))
    {
        nValue |= ~((1 << nBits) - 1);
    }
    return nValue;
}

// 0x00411070
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer)
{
    if (pBuffer->nPosBits)
    {
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
    }
}

// 0x004110B0
void __stdcall sub_004110B0_WriteCode(D2BitBufferStrc* pBuffer, D2BitCodeStrc* pCodes, int nIndex)
{
    BITMANIP_Write(pBuffer, pCodes[nIndex].nValue, pCodes[nIndex].nBits);
}

// 0x004110D0
int __stdcall sub_004110D0_ReadTreeCode(D2BitBufferStrc* pBuffer, int* pTree)
{
    int nNode = 0;
    for (;;)
    {
        int nBit = (gdwBitMasks[pBuffer->nPosBits] & *pBuffer->pBuffer) >> pBuffer->nPosBits;
        ++pBuffer->nPosBits;
        if (pBuffer->nPosBits == 8)
        {
            ++pBuffer->pBuffer;
            ++pBuffer->nPos;
            pBuffer->nPosBits = 0;
        }
        if (pTree[nBit + nNode] >= 0)
        {
            return pTree[nBit + nNode];
        }
        nNode = 2 * (nBit + nNode) + 2;
    }
}

#include "gen/data/Source/Fog/Unknown_00410B70.inc"

// 0x00410E90
extern "C" __declspec(dllexport) int __stdcall sub_00410E90(Obj00410E90* pObj) {
    return pObj->nFlag0C ? pObj->nValue08 + 1 : pObj->nValue08;
}

D2TimedRecordStrc gaRecords_0075E8A8[4095]; // 0x0075E8A8

unsigned int gnRecordCount_007768A4; // 0x007768A4

int gnTickAtReset_007768A0; // 0x007768A0

// 0x00411280
void __cdecl sub_00411280_ResetRecords()
{
    for (unsigned int i = 0; i < gnRecordCount_007768A4; ++i)
    {
        gaRecords_0075E8A8[i].qwValue = 0;
    }
    gnTickAtReset_007768A0 = GetTickCount();
}

// 0x004113E0
char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote)
{
    const char* pSrc = szSrc;

    D2_ASSERT(szDst, 0xC0);

    if (!szSrc)
    {
        SStrPrintf(szDst, nSize, "<NULL>");
        return szDst;
    }

    int nLeft = nSize - 1;
    if (nSize)
    {
        char* p = szDst;
        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        while (nLeft > 0)
        {
            const char c = *pSrc;
            if (!c)
            {
                break;
            }
            ++pSrc;
            --nLeft;

            if (c >= 0x20)
            {
                *p++ = c;
                continue;
            }

            *p++ = '\\';
            if (!nLeft)
            {
                break;
            }
            --nLeft;

            if (c == '\r')
            {
                *p++ = 'r';
            }
            else if (c == '\n')
            {
                *p++ = 'n';
            }
            else if (c == '\t')
            {
                *p++ = 't';
            }
            else
            {
                if (nLeft < 2)
                {
                    break;
                }
                *p++ = 'x';
                *p++ = ((c & 0xF0) < 0xA0) ? ((unsigned char)c >> 4) + '0' : ((unsigned char)c >> 4) + ('A' - 10);
                *p++ = ((c & 0x0F) < 0x0A) ? (c & 0x0F) + '0' : (c & 0x0F) + ('A' - 10);
                nLeft -= 2;
            }
        }

        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        *p = 0;
        D2_ASSERT(nLeft >= 0, 0x100);
        D2_ASSERT(p - szDst + 1 <= nSize, 0x101);
    }

    return szDst;
}

// 0x00411540
char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue)
{
    char digits[32];
    if (nBufferSize > 32)
        nBufferSize = 32;
    char* pDigit = digits;
    unsigned int nGroup = 0;
    while (nValue)
    {
        if (pDigit >= digits + nBufferSize - 1)
        {
            memset(szBuffer, '*', nBufferSize - 1);
            szBuffer[nBufferSize - 1] = 0;
            return szBuffer;
        }
        *pDigit++ = (char)('0' + nValue % 10);
        nValue /= 10;
        ++nGroup;
        if (nGroup == 3 && nValue)
        {
            *pDigit++ = ',';
            nGroup = 0;
        }
    }
    char* pOut = szBuffer;
    while (pDigit >= digits)
        *pOut++ = *--pDigit;
    *pOut = 0;
    return szBuffer;
}

