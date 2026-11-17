extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) long __stdcall RegFlushKey(void* hKey);                                    // 0x006CC008
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);                      // 0x006CC2E4
void __stdcall sub_00414930_GetRegBasePath(unsigned int nFlags, char* szBuffer, unsigned int nSize);        // 0x00414930
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
extern "C" const char gszEmptyString_006CC837;                                                              // 0x006CC837

// 0x00414C70
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

// calling-convention shim (not game code)
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    if (!pData)
    {
        pData = &gszEmptyString_006CC837;
    }
    return sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, (nFlags | 0x60) >> 5, (const unsigned char*)pData, nSize);
}

// calling-convention shim (not game code)
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName || !szString)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, 1, (const unsigned char*)szString, SStrLen(szString) + 1);
}

// calling-convention shim (not game code)
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00414C70_SRegSaveEntry(szKeyName, szValueName, nFlags, 4, (const unsigned char*)&dwValue, 4);
}
