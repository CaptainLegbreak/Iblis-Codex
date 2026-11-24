#include "Storm.h"

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

inline void operator delete(void*, void*) throw()
{
}
inline void operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

struct BigBuffer
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

// build: symbol ??0BigBuffer@@QAE@XZ 0x00421B50
    BigBuffer() : f_0(0), f_4(0), f_8(0), f_C(0), m_offset(0)
    {
    }
    // 0x00421810
    ~BigBuffer()
    {
        if (f_8)
            SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
    }
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigStack() : nUsed(0)
    {
    }
};

struct D2StormByteArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    D2StormByteArrayStrc() : f_0(0), f_4(0), f_8(0), f_C(0)
    {
    }
};

struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
    D2StormByteArrayStrc tOutput;

    D2StormBigStrc();
    ~D2StormBigStrc();                                                                                      // 0x00421D80
};

int __stdcall sub_004242C0_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, BigStack* pStack); // 0x004242C0
int __stdcall sub_00424700_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, BigStack* pStack); // 0x00424700
int __stdcall sub_00424B00_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, BigStack* pStack); // 0x00424B00

// build: symbol ??3@YAXPAX0@Z 0x0040EB30
// 0x00421E10
D2StormBigStrc::D2StormBigStrc()
{
}

// 0x00423950
void __stdcall SBigNew(D2StormBigStrc** ppBig)
{
    *ppBig = new (SMemAlloc(sizeof(D2StormBigStrc), ".\\SOURCE\\SBig.cpp", 0x521, 0)) D2StormBigStrc;
}

// 0x00424E40
void __stdcall SBigDel(D2StormBigStrc* pBig)
{
    delete pBig;
}

// 0x00424F10
int __stdcall SBigMul(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_004242C0_BigOp(pResult, pA, pB, &pResult->tStack);
}

// 0x00424F70
int __stdcall SBigRand(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_00424700_BigOp(pResult, pA, pB, &pResult->tStack);
}

// 0x00424F90
int __stdcall SBigSquare(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    return sub_00424B00_BigOp(pResult, pA, &pResult->tStack);
}
