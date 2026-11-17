typedef void* HKEY;
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY hKey);

class CRegKey
{
public:
    HKEY m_hKey;
    long Close() throw();
};

// 0x006B1A70
long CRegKey::Close() throw()
{
    long lRes = 0;
    if (m_hKey != 0)
    {
        lRes = RegCloseKey(m_hKey);
        m_hKey = 0;
    }
    return lRes;
}
