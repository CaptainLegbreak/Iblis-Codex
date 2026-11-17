extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837

void __fastcall sub_004068F0(void* hFile); // 0x004068F0

// 0x00516E84
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* hFile)
{
    if (!hFile)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 73);
        exit(-1);
    }

    sub_004068F0(hFile);
}
