typedef void (__cdecl* ExitCallback)();
typedef void (__stdcall* ElementCallback)(void*);
extern unsigned char gArray_0088C7A8[]; // 0x0088C7A8
void __stdcall sub_0040EB50_ConstructElement(void*); // 0x0040EB50
void __stdcall sub_0040EB60_DestroyElement(void*); // 0x0040EB60
void __stdcall sub_006869FC_ConstructArray(void*, unsigned int, unsigned int, ElementCallback, ElementCallback); // 0x006869FC
int __cdecl sub_00683824_RegisterExit(ExitCallback); // 0x00683824
void __cdecl sub_006CB4A0_DestroyCriticalSections(); // 0x006CB4A0

// 0x006CAF90
void __cdecl sub_006CAF90_InitializeArray()
{
    sub_006869FC_ConstructArray(gArray_0088C7A8, 24, 32, sub_0040EB50_ConstructElement, sub_0040EB60_DestroyElement);
    sub_00683824_RegisterExit(sub_006CB4A0_DestroyCriticalSections);
}
