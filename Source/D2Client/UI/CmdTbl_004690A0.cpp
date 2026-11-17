#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};
#pragma pack(pop)

#define NUM_HOTKEYS 114
#define HOTKEY_UNBOUND 0xFFFF

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)
void __cdecl sub_0044C6B0();                                                                                // 0x0044C6B0
void __cdecl sub_004A01E0_ClearListFlags();                                                                 // 0x004A01E0
void __fastcall sub_0044BEA0_SetValue(int nValue);                                                          // 0x0044BEA0
void __stdcall sub_004698D0_LoadKeyConfig(int bInstallDir);                                                 // 0x004698D0
void __cdecl sub_004694A0_BindMouseHotkeys();                                                               // 0x004694A0

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
extern unsigned char gaKeyTable_00712220[0x474];                                                            // 0x00712220

// 0x004690A0
void __cdecl sub_004690A0_HotkeyCmd4()
{
    sub_0044C6B0();
}

// 0x004691B0
void __cdecl sub_004691B0_HotkeyClearListFlags()
{
    sub_004A01E0_ClearListFlags();
}

// 0x00469200
void __cdecl sub_00469200_HotkeyClearValue()
{
    sub_0044BEA0_SetValue(0);
}

// 0x00469A50
static __forceinline void sub_00469A50_LoadKeyConfig(int bInstallDir)
{
    sub_004698D0_LoadKeyConfig(bInstallDir);
}

// 0x00469A60
void __fastcall sub_00469A60_ResetKeyConfig(int bInstallDir)
{
    sub_004698D0_LoadKeyConfig(bInstallDir);
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(gtHotkeys_007A6F90, gaKeyTable_00712220, sizeof(gtHotkeys_007A6F90));
    sub_004694A0_BindMouseHotkeys();
}

void __fastcall sub_M110_Emit_00469A50(int bInstallDir)
{
    sub_00469A50_LoadKeyConfig(bInstallDir + 1);
}
