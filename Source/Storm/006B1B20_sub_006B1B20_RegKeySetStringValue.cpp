extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154

__declspec(noreturn) void __cdecl sub_006B1A30_ThrowAtlException(long error); // 0x006B1A30

struct CRegKey006B1B20Strc
{
    void* m_hKey;
};

// 0x006B1B20
long __fastcall sub_006B1B20_RegKeySetStringValue(CRegKey006B1B20Strc* pKey, int nUnused, const char* pszValueName, const char* pszValue, unsigned long dwType)
{
    if (!pszValue)
        sub_006B1A30_ThrowAtlException(0x80004005);
    return RegSetValueExA(pKey->m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
}
