struct TSLink
{
    void* m_prevlink;
    unsigned int m_next;
};

struct D2ListStrc
{
    int nLinkOffset;
    TSLink tTerminator;
};

extern D2ListStrc gFaultHandlerList; // 0x0072FA14
void __cdecl sub_006CB401_StaticFini_gFaultHandlerList(); // 0x006CB401
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

// 0x006CAE5F
void __cdecl sub_006CAE5F_StaticInit_gFaultHandlerList()
{
    gFaultHandlerList.tTerminator.m_next = ~(unsigned int)&gFaultHandlerList.tTerminator;
    atexit(sub_006CB401_StaticFini_gFaultHandlerList);
}
