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
