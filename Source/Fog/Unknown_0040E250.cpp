extern "C" void* __cdecl memset(void* p, int n, unsigned int nSize);
extern "C" int __cdecl strcmp(const char* a, const char* b);
#pragma intrinsic(memset, strcmp)

// 0x0040E250
int __cdecl sub_0040E250_GetCpuVendor()
{
    char szVendor[16];
    memset(szVendor, 0, sizeof(szVendor));
    __asm
    {
        mov eax, 0
        cpuid
        mov dword ptr szVendor[0], ebx
        mov dword ptr szVendor[4], edx
        mov dword ptr szVendor[8], ecx
    }
    if (!strcmp(szVendor, "GenuineIntel")) return 1;
    if (!strcmp(szVendor, "AuthenticAMD")) return 2;
    return !strcmp(szVendor, "CyrixInstead") ? 3 : 0;
}

// 0x0040E960
__declspec(noinline) unsigned int __cdecl sub_0040E960_GetCpuSignature()
{
    unsigned int nSignature;
    __asm
    {
        mov eax, 1
        cpuid
        mov nSignature, eax
    }
    return nSignature;
}

// 0x0040E980
unsigned int __cdecl sub_0040E980_GetCpuidEbxIfBrandIndexed()
{
    unsigned int nResult = 0;
    const unsigned int nSignature = sub_0040E960_GetCpuSignature();
    const unsigned int nFamily = (nSignature >> 8) & 0xF;
    if (sub_0040E250_GetCpuVendor() == 1 && (nFamily >= 7 || (nFamily == 6 && (nSignature & 0xF0) >= 0x80)))
    {
        __asm
        {
            mov eax, 1
            cpuid
            mov nResult, ebx
        }
    }
    return nResult;
}
