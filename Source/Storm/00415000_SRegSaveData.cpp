extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition);
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData);
extern "C" __declspec(dllimport) long __stdcall RegFlushKey(void* hKey);
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);
void __stdcall sub_00414930_GetRegBasePath(unsigned int nFlags, char* szBuffer, unsigned int nSize);
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
extern "C" const char gszEmptyString_006CC837;                                                              // 0x006CC837

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

static int __stdcall sub_00414C70_SRegSaveEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwType, const unsigned char* pData, unsigned long cbData)
{
    char szKey[0x104];
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        sub_00414930_GetRegBasePath(nFlags, szKey, 0x104);
    }
    sub_00413800(szKey, szKeyName, 0x104);
    void* hKey;
    unsigned long nDisposition;
    long nError = RegCreateKeyExA((nFlags & 4) ? (void*)0x80000002 : (void*)0x80000001, szKey, 0, 0, 0, 0x20006, 0, &hKey, &nDisposition);
    if (!nError)
    {
        nError = RegSetValueExA(hKey, szValueName, 0, dwType, pData, cbData);
        if (!nError)
        {
            if (nFlags & 8)
            {
                nError = RegFlushKey(hKey);
            }
            if (!nError)
            {
                nError = RegCloseKey(hKey);
                if (!nError)
                {
                    return 1;
                }
            }
        }
        RegCloseKey(hKey);
    }
    SetLastError(nError);
    return 0;
}

// 0x00415000
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    __assume((szKeyName) != 0);
    VALIDATE(*szKeyName);
    __assume((*szKeyName) != 0);
    VALIDATE(szValueName);
    __assume((szValueName) != 0);
    VALIDATE(*szValueName);
    __assume((*szValueName) != 0);
    VALIDATEEND;
    if (!pData)
    {
        pData = &gszEmptyString_006CC837;
    }
    return sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, ((nFlags & 0x80) | 0x60) >> 5, (const unsigned char*)pData, nSize);
}

// 0x00415070
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    __assume((szKeyName) != 0);
    VALIDATE(*szKeyName);
    __assume((*szKeyName) != 0);
    VALIDATE(szValueName);
    __assume((szValueName) != 0);
    VALIDATE(*szValueName);
    __assume((*szValueName) != 0);
    VALIDATE(szString);
    __assume((szString) != 0);
    VALIDATEEND;
    return nValid ? sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, 1, (const unsigned char*)szString, SStrLen(szString) + 1) : 0;
}

// 0x004150E0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    __assume((szKeyName) != 0);
    VALIDATE(*szKeyName);
    __assume((*szKeyName) != 0);
    VALIDATE(szValueName);
    __assume((szValueName) != 0);
    VALIDATE(*szValueName);
    __assume((*szValueName) != 0);
    VALIDATEEND;
    return sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, 4, (const unsigned char*)&dwValue, 4);
}
