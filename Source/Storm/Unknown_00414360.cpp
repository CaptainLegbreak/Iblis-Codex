#include "Storm.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2StormQuadStrc;
extern "C" int gnBufferBase_007D5448;
extern "C" int gnSoundFlag_007C545C;
extern "C" int gnSoundSerial_007C5460;
extern "C" int gnSubsystemActive_007A0458;
void __cdecl sub_004142A0_InitPowTable(); // 0x004142A0
extern "C" void __cdecl sub_004F7CC0(); // 0x004F7CC0
extern "C" void __cdecl sub_004E4280(); // 0x004E4280
int __stdcall GAME_Shutdown(); // 0x0052C030
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegDeleteValueA(void* hKey, const char* szValueName); // 0x006CC018
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode); // 0x006CC2E4
int __stdcall sub_00414930_GetRegistryRoot(unsigned int nFlags, char* szDest, unsigned int nMaxLength); // 0x00414930
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
extern "C" const char gszFmtUnsigned_006CEF68[]; // 0x006CEF68
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004
extern "C" __declspec(dllimport) long __stdcall RegFlushKey(void* hKey); // 0x006CC008
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
extern "C" const char gszEmptyString_006CC837; // 0x006CC837
int __fastcall sub_00414990_SRegDeleteEntry(unsigned int nFlags, const char* szKeyName, const char* szValueName);

struct D2StormQuadStrc {
 int n00,n04,n08,n0C;
 D2StormQuadStrc& __thiscall sub_00415160_Copy(const D2StormQuadStrc& source);
};

// 0x00414360
extern "C" void __cdecl sub_00414360_CallThenSetFlag()
{
    sub_004142A0_InitPowTable();
    gnFlag_007788DC = 1;
}

// build: context sub_004F8DC0_InitLookupTable
extern "C" void __cdecl sub_004F8DC0_InitLookupTable()
{
    sub_004F7CC0();
    gnBufferBase_007D5448 = 0;
}

// build: context sub_004B9D00_ResetSoundState
extern "C" void __cdecl sub_004B9D00_ResetSoundState()
{
    gnSoundFlag_007C545C = 1;
    gnSoundSerial_007C5460 = 0;
    sub_004E4280();
}

// build: context sub_0044BB80_ShutdownIfActive
extern "C" int __cdecl sub_0044BB80_ShutdownIfActive()
{
    if (gnSubsystemActive_007A0458 == 0)
        return 0;
    gnSubsystemActive_007A0458 = 0;
    return GAME_Shutdown();
}

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
        sub_00414930_GetRegistryRoot(nFlags, szKey, 0x104);
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
        sub_00414930_GetRegistryRoot(nFlags, szKey, 0x104);
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

// calling-convention shim (not game code)
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    unsigned long nType;
    unsigned long cbData;
    if (!pcbData)
    {
        pcbData = &cbData;
    }
    return sub_00414B00_SRegLoadEntry(szKeyName, szValueName, nFlags, &nType, pData, nSize, pcbData);
}

// calling-convention shim (not game code)
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName || !szBuffer || !nBufferSize)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    unsigned long nType;
    unsigned long cbData;
    if (!sub_00414B00_SRegLoadEntry(szKeyName, szValueName, nFlags, &nType, (unsigned char*)szBuffer, nBufferSize, &cbData))
    {
        return 0;
    }
    switch (nType)
    {
    case 1:
    {
        unsigned long nEnd = nBufferSize - 1;
        if (nEnd >= cbData)
        {
            nEnd = cbData;
        }
        szBuffer[nEnd] = 0;
        break;
    }
    case 4:
        wsprintfA(szBuffer, gszFmtUnsigned_006CEF68, *(unsigned long*)szBuffer);
        return 1;
    }
    return 1;
}

// calling-convention shim (not game code)
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue)
{
    if (!szKeyName || !*szKeyName || !szValueName || !*szValueName || !pValue)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
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
    case 1:
        *pValue = strtoul(szData, 0, 0);
        break;
    case 4:
        *pValue = *(unsigned long*)szData;
        break;
    }
    return 1;
}

#include "gen/data/Source/Storm/Unknown_00414360.inc"

// 0x00414C70
static int __stdcall sub_00414C70_SRegSaveEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwType, const unsigned char* pData, unsigned long cbData)
{
    char szKey[0x104];
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        sub_00414930_GetRegistryRoot(nFlags, szKey, 0x104);
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

// 0x00414D90
int __stdcall sub_00414D90_RegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int nFlags)
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
    return sub_00414990_SRegDeleteEntry(nFlags, szKeyName, szValueName);
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

// 0x00415160
D2StormQuadStrc& __thiscall D2StormQuadStrc::sub_00415160_Copy(const D2StormQuadStrc& source) {
 n00=source.n00;
 n04=source.n04;
 n08=source.n08;
 n0C=source.n0C;
 return *this;
}
