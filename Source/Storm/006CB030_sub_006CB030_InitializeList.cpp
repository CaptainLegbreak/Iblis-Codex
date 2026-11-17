extern unsigned int gnListTerminator_0074C490; // 0x0074C490
extern void* gpListHead_0074C494; // 0x0074C494
void __cdecl sub_006CB4F0_DestroyList(); // 0x006CB4F0
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CB030
void __cdecl sub_006CB030_InitializeList()
{
    gpListHead_0074C494 = (void*)~(unsigned int)&gnListTerminator_0074C490;
    atexit(sub_006CB4F0_DestroyList);
}

#include "gen/data/Source/Storm/006CB030_sub_006CB030_InitializeList.inc"
