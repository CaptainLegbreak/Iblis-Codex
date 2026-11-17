extern unsigned int gnListTerminator_00708370; // 0x00708370
extern void* gpListHead_00708374; // 0x00708374
void __cdecl sub_006CB180_DestroyList(); // 0x006CB180
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA810
void __cdecl sub_006CA810_InitializeList()
{
    gpListHead_00708374 = (void*)~(unsigned int)&gnListTerminator_00708370;
    atexit(sub_006CB180_DestroyList);
}
