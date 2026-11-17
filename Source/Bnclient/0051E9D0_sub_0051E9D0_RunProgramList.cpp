extern "C" __declspec(dllimport) struct HINSTANCE__* __stdcall ShellExecuteA(struct HWND__* hWnd, const char* szOperation, const char* szFile, const char* szParameters, const char* szDirectory, int nShowCmd); // 0x006CC438
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
bool __fastcall sub_00516DE1_CanRunSurvey(const char* szExePath);                                           // 0x00516DE1

// 0x0051E9D0
static int sub_0051E9D0_RunProgramList(const char* szDirectory, const char* szList)
{
    while (*szList)
    {
        if (!sub_00516DE1_CanRunSurvey(szList))
            return 0;

        if ((int)ShellExecuteA(0, 0, szList, 0, szDirectory, 1) <= 0x20)
            return 0;

        szList += SStrLen(szList) + 1;
    }

    return 1;
}

int __cdecl sub_B03_Emit_0051E9D0(const char* szDirectory, const char* szList)
{
    return sub_0051E9D0_RunProgramList(szDirectory, szList);
}
