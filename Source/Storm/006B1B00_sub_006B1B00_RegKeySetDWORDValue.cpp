extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034

struct CRegKey006B1B00Strc
{
    void* m_hKey;
};

// 0x006B1B00
long __fastcall sub_006B1B00_RegKeySetDWORDValue(CRegKey006B1B00Strc* pKey, int nUnused, const char* pszValueName, unsigned long dwValue)
{
    return RegSetValueExA(pKey->m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
}
