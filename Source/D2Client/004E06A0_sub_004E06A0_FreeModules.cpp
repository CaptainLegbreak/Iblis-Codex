struct D2ClientModuleListStrc
{
    void* pBase;
    void* pUnknown04;
    int nModuleCount;
};

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned int nSize, unsigned int nFreeType); // 0x006CC220

// 0x004E06A0
void __fastcall sub_004E06A0_FreeModules(D2ClientModuleListStrc* pList)
{
    if (!pList->pBase)
        return;
    unsigned char* pNames = (unsigned char*)pList->pBase + *(unsigned int*)((unsigned char*)pList->pBase + 0x1C);
    void* (__stdcall *pGetModuleHandleA)(const char*) = GetModuleHandleA;
    while (pList->nModuleCount > 0)
    {
        pList->nModuleCount--;
        const char* szName = (const char*)((unsigned char*)pList->pBase + *(unsigned int*)(pNames + pList->nModuleCount * 8));
        FreeLibrary(pGetModuleHandleA(szName));
    }
    VirtualFree(pList->pBase, 0, 0x8000);
    pList->pBase = 0;
    pList->pUnknown04 = 0;
}
