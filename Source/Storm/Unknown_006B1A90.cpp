typedef void* HKEY;
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY hKey);
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(HKEY hKey, const char* lpSubKey, DWORD Reserved, char* lpClass, DWORD dwOptions, DWORD samDesired, void* lpSecurityAttributes, HKEY* phkResult, DWORD* lpdwDisposition);

class CRegKey
{
public:
    HKEY m_hKey;

    long Close() throw()
    {
        long lRes = 0;
        if (m_hKey != 0)
        {
            lRes = RegCloseKey(m_hKey);
            m_hKey = 0;
        }
        return lRes;
    }
    long Create(HKEY hKeyParent, const char* lpszKeyName, char* lpszClass, DWORD dwOptions, DWORD samDesired, void* lpSecAttr, DWORD* lpdwDisposition) throw();
};

// 0x006B1A90
long CRegKey::Create(HKEY hKeyParent, const char* lpszKeyName, char* lpszClass, DWORD dwOptions, DWORD samDesired, void* lpSecAttr, DWORD* lpdwDisposition) throw()
{
    DWORD dw;
    HKEY hKey = 0;
    long lRes = RegCreateKeyExA(hKeyParent, lpszKeyName, 0, lpszClass, dwOptions, samDesired, lpSecAttr, &hKey, &dw);
    if (lpdwDisposition != 0)
        *lpdwDisposition = dw;
    if (lRes == 0)
    {
        lRes = Close();
        m_hKey = hKey;
    }
    return lRes;
}
