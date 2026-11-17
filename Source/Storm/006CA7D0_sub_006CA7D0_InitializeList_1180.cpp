extern unsigned int gnListTerminator_00708364; // 0x00708364
extern void* gpListHead_00708368; // 0x00708368
void __cdecl sub_006CB120_DestroyList(); // 0x006CB120
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA7D0
void __cdecl sub_006CA7D0_InitializeList()
{
    gpListHead_00708368 = (void*)~(unsigned int)&gnListTerminator_00708364;
    atexit(sub_006CB120_DestroyList);
}
