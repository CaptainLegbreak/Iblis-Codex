extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned int size, unsigned int freeType); // 0x006CC220

// 0x005179A4
void __fastcall sub_005179A4_FreeVirtualMemory(void* address)
{
    VirtualFree(address, 0, 0x8000);
}
