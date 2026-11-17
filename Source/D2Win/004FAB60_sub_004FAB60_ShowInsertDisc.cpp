int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

// 0x004FAB60
int __cdecl sub_004FAB60_ShowInsertDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Cinematics Disc", "Diablo II", 0x31) == 1;
}
