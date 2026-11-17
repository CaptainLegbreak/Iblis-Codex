struct D2CriticalSectionStrc
{
    char data[0x18];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC
extern D2CriticalSectionStrc gCriticalSection_00779214; // 0x00779214

// 0x006CB300
void __cdecl sub_006CB300_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_00779214);
}
