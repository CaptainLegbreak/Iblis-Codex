typedef void (__fastcall *D2DestroyFn)(void*);
void __fastcall sub_0040EB60_DestroyCriticalSection(void*); // 0x0040EB60
void __stdcall sub_00686AD1_DestroyArray(void*, unsigned int, int, D2DestroyFn); // 0x00686AD1
extern unsigned char gaCriticalSections_0088C7A8[]; // 0x0088C7A8
// 0x006CB4A0
void __cdecl sub_006CB4A0_DestroyCriticalSections()
{
    sub_00686AD1_DestroyArray(gaCriticalSections_0088C7A8, 24, 32, sub_0040EB60_DestroyCriticalSection);
}
