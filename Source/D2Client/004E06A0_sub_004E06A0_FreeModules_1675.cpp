struct D2ClientModuleListStrc
{
    void* f_0;
    void* pUnknown04;
    int f_8;
};

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned int nSize, unsigned int nFreeType); // 0x006CC220

// 0x004E06A0
void __fastcall sub_004E06A0_FreeModules(D2ClientModuleListStrc* pList)
{
    if (!pList->f_0)
        return;
    unsigned char* pNames = (unsigned char*)pList->f_0 + *(unsigned int*)((unsigned char*)pList->f_0 + 0x1C);
    void* (__stdcall *pGetModuleHandleA)(const char*) = GetModuleHandleA;
    while (pList->f_8 > 0)
    {
        pList->f_8--;
        const char* szName = (const char*)((unsigned char*)pList->f_0 + *(unsigned int*)(pNames + pList->f_8 * 8));
        FreeLibrary(pGetModuleHandleA(szName));
    }
    VirtualFree(pList->f_0, 0, 0x8000);
    pList->f_0 = 0;
    pList->pUnknown04 = 0;
}
