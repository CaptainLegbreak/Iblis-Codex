#include "D2CMP.h"

struct D2BitBufferInitStrc;
struct D2CmpByteMapStrc;
struct D2CmpByteMapArgStrc;

struct D2BitBufferInitStrc {
#ifdef MOVED_TEST
 int movedGap;
#endif
 unsigned char* pBuffer; unsigned char* pCurrent; int nBits; int nPos;
};

struct D2CmpByteMapStrc
{
    unsigned char ab[0x100];
    int nCount;
};

struct D2CmpByteMapArgStrc
{
    D2CmpByteMapStrc* p;
};
static __declspec(noinline) void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapArgStrc tInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward);

// 0x0060B160
static __declspec(noinline) void __stdcall sub_0060B160_Copy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {
 dst->pBuffer=src->pBuffer;
 dst->pCurrent=src->pCurrent;
 dst->nBits=src->nBits;
 dst->nPos=src->nPos;
}

void __stdcall EmitCopy(D2BitBufferInitStrc* dst,const D2BitBufferInitStrc* src) {sub_0060B160_Copy(dst,src);}

// 0x0060B5F0
static void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapArgStrc tInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward)
{
    int i;
    int n;
    for (i = 0, n = 0; i < 0x100; ++i)
    {
        if (pFlags[i])
        {
            pForward->ab[i] = (unsigned char)n;
            tInverse.p->ab[n] = (unsigned char)i;
            ++n;
        }
    }
    pForward->nCount = 0x100;
    tInverse.p->nCount = n;
}

// calling-convention shim (not game code)
void __fastcall sub_0060B5F0_Shim(D2CmpByteMapStrc* pInverse, const unsigned int* pBits, D2CmpByteMapStrc* pForward)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    D2CmpByteMapArgStrc tInverse = { pInverse };
    sub_0060B5F0_BuildColorMaps(tInverse, abFlags, pForward);
}
