inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

extern char gszTypeNameUInt_00708874[];                                                                     // 0x00708874
extern char gszTypeNameUChar_00708880[];                                                                    // 0x00708880

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    void sub_004216E0_ReallocData(unsigned int nAlloc);
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    void sub_004211C0_ReallocData(unsigned int nAlloc);
};

// 0x004211C0
void D2StormArrayBStrc::sub_004211C0_ReallocData(unsigned int nAlloc)
{
    unsigned char* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (unsigned char*)SMemReAlloc(pOld, nAlloc, gszTypeNameUChar_00708880, -2, 0x10);
    if (!f_8)
    {
        f_8 = (unsigned char*)SMemAlloc(nAlloc, gszTypeNameUChar_00708880, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
                new (&f_8[i]) unsigned char(pOld[i]);
            SMemFree(pOld, gszTypeNameUChar_00708880, -2, 0);
        }
    }
}

// 0x004216E0
void D2StormArrayAStrc::sub_004216E0_ReallocData(unsigned int nAlloc)
{
    unsigned int* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (unsigned int*)SMemReAlloc(pOld, nAlloc * 4, gszTypeNameUInt_00708874, -2, 0x10);
    if (!f_8)
    {
        f_8 = (unsigned int*)SMemAlloc(nAlloc * 4, gszTypeNameUInt_00708874, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
                new (&f_8[i]) unsigned int(pOld[i]);
            SMemFree(pOld, gszTypeNameUInt_00708874, -2, 0);
        }
    }
}

#include "gen/data/Source/Storm/004211C0_sub_004211C0_ReallocData.inc"
