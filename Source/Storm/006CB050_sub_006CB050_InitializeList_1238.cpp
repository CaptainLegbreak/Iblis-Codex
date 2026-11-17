extern unsigned int gnListTerminator_0074C49C; // 0x0074C49C
extern void* gpListHead_0074C4A0; // 0x0074C4A0
void __cdecl sub_006CB550_DestroyList(); // 0x006CB550
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CB050
void __cdecl sub_006CB050_InitializeList()
{
    gpListHead_0074C4A0 = (void*)~(unsigned int)&gnListTerminator_0074C49C;
    atexit(sub_006CB550_DestroyList);
}
