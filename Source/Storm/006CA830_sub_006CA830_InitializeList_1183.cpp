extern unsigned int gnListTerminator_0070837C; // 0x0070837C
extern void* gpListHead_00708380; // 0x00708380
void __cdecl sub_006CB1E0_DestroyList(); // 0x006CB1E0
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA830
void __cdecl sub_006CA830_InitializeList()
{
    gpListHead_00708380 = (void*)~(unsigned int)&gnListTerminator_0070837C;
    atexit(sub_006CB1E0_DestroyList);
}
