extern unsigned int gnListTerminator_00708424; // 0x00708424
extern void* gpListHead_00708428; // 0x00708428
void __cdecl sub_006CB2A0_DestroyList(); // 0x006CB2A0
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA8A0
void __cdecl sub_006CA8A0_InitializeList()
{
    gpListHead_00708428 = (void*)~(unsigned int)&gnListTerminator_00708424;
    atexit(sub_006CB2A0_DestroyList);
}

#include "gen/data/Source/Storm/006CA8A0_sub_006CA8A0_InitializeList.inc"
