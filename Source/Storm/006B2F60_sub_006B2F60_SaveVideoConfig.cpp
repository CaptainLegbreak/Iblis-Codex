struct D2DDrawDeviceStrc
{
    unsigned int dwFlags;
    unsigned char guid[0x10];
    char unk0x014[0x08];
    char szName[0x104];
};

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz);                                    // 0x006CC154

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
__declspec(noreturn) void __cdecl sub_006B1A30_ThrowAtlException(long error);                               // 0x006B1A30

extern D2DDrawDeviceStrc gaDDrawDevices_0096F4E0[];                                                         // 0x0096F4E0

class CRegKeyInline
{
public:
    void* m_hKey;

    CRegKeyInline() : m_hKey(0) {}
    ~CRegKeyInline() { Close(); }

    long Close()
    {
        long lRes = 0;
        if (m_hKey != 0)
        {
            lRes = RegCloseKey(m_hKey);
            m_hKey = 0;
        }
        return lRes;
    }

    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass = 0, unsigned long dwOptions = 0,
        unsigned long samDesired = 0x20006, void* lpSecAttr = 0, unsigned long* lpdwDisposition = 0)
    {
        unsigned long dw;
        void* hKey = 0;
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

    long SetDWORDValue(const char* pszValueName, unsigned long dwValue)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
    }

    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType = 1)
    {
        if (!pszValue)
            sub_006B1A30_ThrowAtlException(0x80004005);
        return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
    }

    long SetBinaryValue(const char* pszValueName, const void* pValue, unsigned long nBytes)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 3, (const unsigned char*)pValue, nBytes);
    }
};

// 0x006B2F60
void __fastcall sub_006B2F60_SaveVideoConfig(int nRender, int nDevice)
{
    int aDeviceName[0x104 / 4];
    int aFlags[0x104 / 4];
    int aGuid[0x104 / 4];
    sprintf((char*)aDeviceName, "DeviceName");
    sprintf((char*)aFlags, "dwFlags");
    sprintf((char*)aGuid, "GUID");

    CRegKeyInline tKey;
    if (tKey.Create((void*)0x80000001, "SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig") == 0)
    {
        tKey.SetDWORDValue("Render", nRender);
        tKey.SetStringValue((const char*)aDeviceName, gaDDrawDevices_0096F4E0[nDevice].szName);
        tKey.SetDWORDValue((const char*)aFlags, gaDDrawDevices_0096F4E0[nDevice].dwFlags);
        tKey.SetBinaryValue((const char*)aGuid, gaDDrawDevices_0096F4E0[nDevice].guid, 0x10);
    }
}
