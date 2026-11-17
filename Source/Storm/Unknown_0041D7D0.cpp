#include "Storm.h"

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

struct D2StormHashCtxStrc
{
    unsigned int nBitCountLo;
    unsigned int nBitCountHi;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
};

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
    char* pBuffer;
    int unk0x14;
    D2StormHashCtxStrc tHash;
    int f_74;

    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew, -1, 0);
    }
};

// 0x0041D3B0
void __fastcall sub_0041D3B0_NewHashBuffer(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize)
{
    *ppBuffer = new D2StormHashBufferStrc;
    (*ppBuffer)->nSignSize = nSignSize;
    (*ppBuffer)->nModulusSize = nModulusSize;
    (*ppBuffer)->nUsed = 0;
    (*ppBuffer)->nWindow = nSignSize + 4;
    (*ppBuffer)->pBuffer = (char*)SMemAlloc((*ppBuffer)->nWindow, ".\\SOURCE\\SSignature.cpp", 0x57, 8);
    (*ppBuffer)->tHash.sub_00425D90_Init();
}
int __fastcall sub_0041D420_HashBuffered(void* pHash, const void* pData, int nSize); // 0x0041D420
int __fastcall sub_0041D6D0_VerifyHashBuffer(void* pHash, const void* pSignature, int nSignatureSize); // 0x0041D6D0

// 0x0041D7D0
int __fastcall sub_0041D7D0_VerifySignature(const void* pData, int nSize, const void* pSignature, int nAlgorithm, int nSignatureSize, int nFlags)
{
    D2StormHashBufferStrc* pHash;
    sub_0041D3B0_NewHashBuffer(&pHash, nAlgorithm, nFlags);
    sub_0041D420_HashBuffered(pHash, pData, nSize);
    return sub_0041D6D0_VerifyHashBuffer(pHash, pSignature, nSignatureSize);
}
