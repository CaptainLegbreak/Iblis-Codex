extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);                      // 0x006CC2E4
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                   // 0x006867B2
void __stdcall sub_00414930_GetRegBasePath(unsigned int nFlags, char* szBuffer, unsigned int nSize);        // 0x00414930
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
extern "C" const char gszFmtUnsigned_006CEF68[];                                                            // 0x006CEF68

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEKEEP(x) nValid = (x) ? nValid : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00414B00
static int __stdcall sub_00414B00_SRegLoadEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pType, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    *pcbData = 0;
    char szKey[0x104];
    void* hKey = 0;
    long nError = 0x3F3;
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        sub_00414930_GetRegBasePath(nFlags, szKey, 0x104);
    }
    sub_00413800(szKey, szKeyName, 0x104);
    if (!(nFlags & 4))
    {
        nError = RegOpenKeyExA((void*)0x80000001, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            *pcbData = nSize;
            nError = RegQueryValueExA(hKey, szValueName, 0, pType, pData, pcbData);
            RegCloseKey(hKey);
        }
    }
    if (nError && !(nFlags & 1))
    {
        nError = RegOpenKeyExA((void*)0x80000002, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            *pcbData = nSize;
            nError = RegQueryValueExA(hKey, szValueName, 0, pType, pData, pcbData);
            RegCloseKey(hKey);
        }
    }
    if (!nError)
    {
        return 1;
    }
    SetLastError(nError);
    return 0;
}

// 0x00414DE0
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    __assume(szKeyName != 0);
    VALIDATE(*szKeyName);
    __assume(*szKeyName != 0);
    VALIDATE(szValueName);
    __assume(szValueName != 0);
    VALIDATE(*szValueName);
    __assume(*szValueName != 0);
    VALIDATEEND;

    unsigned long dwType;
    unsigned long dwBytesRead;
    if (!pcbData)
        pcbData = &dwBytesRead;
    return sub_00414B00_SRegLoadEntry(szKeyName, szValueName, nFlags, &dwType, pData, nSize, pcbData);
}

// build: context SRegLoadValue
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*(const char*)szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*(const char*)szValueName);
    VALIDATE(pValue);
    VALIDATEEND;

    unsigned long nType;
    unsigned long cbData;
    char szData[0x100];
    szData[0] = 0;
    if (!sub_00414B00_SRegLoadEntry(szKeyName, szValueName, nFlags, &nType, (unsigned char*)szData, 0x100, &cbData))
    {
        return 0;
    }
    switch (nType)
    {
    case 4:
        *pValue = *(unsigned long*)szData;
        break;
    case 1:
        *pValue = strtoul(szData, 0, 0);
        break;
    }
    return nValid ? 1 : 0;
}
