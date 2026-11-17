struct D2CriticalSectionStrc
{
    char data[0x18];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC
extern D2CriticalSectionStrc gCriticalSection_0075E850; // 0x0075E850

// 0x006CB080
void __cdecl sub_006CB080_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_0075E850);
}
