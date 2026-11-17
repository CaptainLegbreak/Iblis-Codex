extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegDeleteValueA(void* hKey, const char* szValueName);      // 0x006CC018
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);                      // 0x006CC2E4
void __stdcall sub_00414930_GetRegBasePath(unsigned int nFlags, char* szBuffer, unsigned int nSize);        // 0x00414930
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800

// 0x00414990
int __fastcall sub_00414990_SRegDeleteEntry(unsigned int nFlags, const char* szKeyName, const char* szValueName)
{
    const char* szValue = szValueName;
    int bResult = 0;
    char szKey[0x104];
    void* hKey;
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        sub_00414930_GetRegBasePath(nFlags, szKey, 0x104);
    }
    sub_00413800(szKey, szKeyName, 0x104);

    long nUserError = 0;
    if ((nFlags & 5) != 4)
    {
        long nError = RegOpenKeyExA((void*)0x80000001, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            nError = RegDeleteValueA(hKey, szValue);
            if (nError)
            {
                nUserError = nError;
            }
            nError = RegCloseKey(hKey);
        }
        if (nError)
        {
            nUserError = nError;
        }
        if (!nUserError)
        {
            bResult = 1;
        }
    }

    long nMachineError = 0;
    if ((nFlags & 5) != 1)
    {
        long nError = RegOpenKeyExA((void*)0x80000002, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            nError = RegDeleteValueA(hKey, szValue);
            if (nError)
            {
                nMachineError = nError;
            }
            nError = RegCloseKey(hKey);
        }
        if (nError)
        {
            nMachineError = nError;
        }
        if (!nMachineError)
        {
            return 1;
        }
    }

    if (bResult)
    {
        return bResult;
    }

    if (nUserError)
    {
        SetLastError(nUserError);
    }
    else
    {
        SetLastError(nMachineError);
    }
    return *(volatile int*)&bResult;
}
