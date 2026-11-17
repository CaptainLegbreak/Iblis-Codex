extern unsigned int gnListTerminator_007088EC; // 0x007088EC
extern void* gpListHead_007088F0; // 0x007088F0
void __cdecl sub_006CB380_DestroyList(); // 0x006CB380
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA900
void __cdecl sub_006CA900_InitializeList()
{
    gpListHead_007088F0 = (void*)~(unsigned int)&gnListTerminator_007088EC;
    atexit(sub_006CB380_DestroyList);
}
