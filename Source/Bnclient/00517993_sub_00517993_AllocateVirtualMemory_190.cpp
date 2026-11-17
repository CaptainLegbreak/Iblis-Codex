#define D2_IMPORT __declspec(dllimport)
extern "C" D2_IMPORT void* __stdcall VirtualAlloc(void* address, unsigned int size, unsigned int allocationType, unsigned int protection); // 0x006CC21C

// 0x00517993
void* __fastcall sub_00517993_AllocateVirtualMemory(unsigned int size)
{
    return VirtualAlloc(0, size, 0x3000, 0x40);
}
