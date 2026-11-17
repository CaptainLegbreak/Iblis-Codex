#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand;
    unsigned short nKey;
    int nMode;
};
#pragma pack(pop)

#define NUM_HOTKEYS 114

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)
void __cdecl sub_004694A0_BindMouseHotkeys();                                                               // 0x004694A0

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90
extern D2HotkeyStrc gtHotkeysSaved_007A6B18[NUM_HOTKEYS];                                                   // 0x007A6B18

// 0x00469D20
void __cdecl sub_00469D20_SaveHotkeys()
{
    memcpy(gtHotkeysSaved_007A6B18, gtHotkeys_007A6F90, sizeof(gtHotkeys_007A6F90));
    sub_004694A0_BindMouseHotkeys();
}

// 0x00469D50
void __cdecl sub_00469D50_RestoreHotkeys()
{
    memcpy(gtHotkeys_007A6F90, gtHotkeysSaved_007A6B18, sizeof(gtHotkeys_007A6F90));
    sub_004694A0_BindMouseHotkeys();
}
