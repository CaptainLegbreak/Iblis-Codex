extern unsigned int gnListTerminator_00708358; // 0x00708358
extern void* gpListHead_0070835C; // 0x0070835C
void __cdecl sub_006CB0C0_DestroyList(); // 0x006CB0C0
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA7B0
void __cdecl sub_006CA7B0_InitializeList()
{
    gpListHead_0070835C = (void*)~(unsigned int)&gnListTerminator_00708358;
    atexit(sub_006CB0C0_DestroyList);
}

#include "gen/data/Source/Storm/006CA7B0_sub_006CA7B0_InitializeList.inc"
