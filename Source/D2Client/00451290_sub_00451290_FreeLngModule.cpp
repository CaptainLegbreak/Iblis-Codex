extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
void* gxGlobal_007A0708;                                                                                    // 0x007A0708
extern void* ghLngModule_007A070C;                                                                          // 0x007A070C

// 0x00451290
void __cdecl sub_00451290_FreeLngModule()
{
    if (ghLngModule_007A070C)
        FreeLibrary(ghLngModule_007A070C);
    ghLngModule_007A070C = 0;
    gxGlobal_007A0708 = 0;
}
