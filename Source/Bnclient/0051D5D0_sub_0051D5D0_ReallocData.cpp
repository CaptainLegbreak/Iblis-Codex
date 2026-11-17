inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

extern char gszTypeNameNewsTableItem_0072FF8C[];                                                            // 0x0072FF8C

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    void sub_0051D5D0_ReallocData(unsigned int nCount);
};

// 0x0051D5D0
void D2StormArray408Strc::sub_0051D5D0_ReallocData(unsigned int nAlloc)
{
    D2Storm408ElemStrc* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (D2Storm408ElemStrc*)SMemReAlloc(pOld, nAlloc * sizeof(D2Storm408ElemStrc), gszTypeNameNewsTableItem_0072FF8C, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2Storm408ElemStrc*)SMemAlloc(nAlloc * sizeof(D2Storm408ElemStrc), gszTypeNameNewsTableItem_0072FF8C, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
                new (&f_8[i]) D2Storm408ElemStrc(pOld[i]);
            SMemFree(pOld, gszTypeNameNewsTableItem_0072FF8C, -2, 0);
        }
    }
}
