struct D2CriticalSectionStrc
{
    char data[0x18];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC
extern D2CriticalSectionStrc gCriticalSection_0077930C; // 0x0077930C

// 0x006CB370
void __cdecl sub_006CB370_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_0077930C);
}
