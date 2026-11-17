#define D2_IMPORT __declspec(dllimport)

extern "C" D2_IMPORT void* __stdcall VirtualAlloc(void* address, unsigned int size, unsigned int allocationType, unsigned int protection); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned int size, unsigned int freeType); // 0x006CC220

// 0x00517993
void* __fastcall sub_00517993_AllocateVirtualMemory(unsigned int size)
{
    return VirtualAlloc(0, size, 0x3000, 0x40);
}

// 0x005179A4
void __fastcall sub_005179A4_FreeVirtualMemory(void* address)
{
    VirtualFree(address, 0, 0x8000);
}
