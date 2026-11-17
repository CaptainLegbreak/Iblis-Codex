extern unsigned int gnListTerminator_00708864; // 0x00708864
extern void* gpListHead_00708868; // 0x00708868
void __cdecl sub_006CB310_DestroyList(); // 0x006CB310
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA8E0
void __cdecl sub_006CA8E0_InitializeList()
{
    gpListHead_00708868 = (void*)~(unsigned int)&gnListTerminator_00708864;
    atexit(sub_006CB310_DestroyList);
}
