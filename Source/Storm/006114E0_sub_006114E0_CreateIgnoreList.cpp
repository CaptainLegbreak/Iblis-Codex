typedef unsigned int size_t;

inline void* __cdecl operator new(size_t nSize, void* pWhere) throw()
{
    return pWhere;
}

inline void __cdecl operator delete(void* pMemory, void* pWhere) throw()
{
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

struct D2CommonIgnoreListStrc
{
    D2CommonIgnoreListStrc();                                                                               // 0x00611200

    char unk0x00[0x188];
};

D2CommonIgnoreListStrc* gpIgnoreList_0096BC20;                                                              // 0x0096BC20

// build: symbol ??3@YAXPAX0@Z 0x0040EB30
// 0x006114E0
void sub_006114E0_CreateIgnoreList()
{
    gpIgnoreList_0096BC20 = new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x41, 0))
        D2CommonIgnoreListStrc;
}

// 0x00611560
D2CommonIgnoreListStrc* sub_00611560_GetOrCreateIgnoreList()
{
    if (!gpIgnoreList_0096BC20)
    {
        gpIgnoreList_0096BC20 = new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x48, 0))
            D2CommonIgnoreListStrc;
    }
    return gpIgnoreList_0096BC20;
}
