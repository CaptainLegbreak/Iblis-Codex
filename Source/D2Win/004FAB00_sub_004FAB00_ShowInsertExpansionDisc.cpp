int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

// 0x004FAB00
int __cdecl sub_004FAB00_ShowInsertExpansionDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Expansion Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB30
int __cdecl sub_004FAB30_ShowInsertPlayDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Play Disc", "Diablo II", 0x31) == 1;
}
