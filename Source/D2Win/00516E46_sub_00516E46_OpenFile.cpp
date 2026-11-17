typedef unsigned long DWORD;
extern "C" __declspec(dllimport) DWORD __stdcall GetLastError(void);

int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

// 0x00516E46
int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing)
{
    if (sub_004068E0(szFileName, phFile))
        return 1;

    DWORD dwError = GetLastError();
    if (!bAllowMissing || dwError != 2)
        sub_00410610_WriteLogLine("Error opening file: %s", szFileName);
    return 0;
}
