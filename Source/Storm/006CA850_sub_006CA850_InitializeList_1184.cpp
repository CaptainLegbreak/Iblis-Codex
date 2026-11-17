extern unsigned int gnListTerminator_00708388; // 0x00708388
extern void* gpListHead_0070838C; // 0x0070838C
void __cdecl sub_006CB240_DestroyList(); // 0x006CB240
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
// 0x006CA850
void __cdecl sub_006CA850_InitializeList()
{
    gpListHead_0070838C = (void*)~(unsigned int)&gnListTerminator_00708388;
    atexit(sub_006CB240_DestroyList);
}
