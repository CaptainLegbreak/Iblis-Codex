typedef struct HKEY__* HKEY;
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY hKey);

// 0x006B2F40
void __fastcall sub_006B2F40_CloseKey(HKEY* phKey)
{
    if (*phKey)
    {
        RegCloseKey(*phKey);
        *phKey = 0;
    }
}
