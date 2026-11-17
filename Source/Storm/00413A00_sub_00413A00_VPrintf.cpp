typedef unsigned int size_t;
typedef char* va_list;
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340

// 0x00413A00
static int sub_00413A00_VPrintf(char* szDest, size_t nSize, const char* szFormat, va_list args)
{
    if (nSize)
    {
        if (nSize != 0x7FFFFFFF)
        {
            size_t nResult = _vsnprintf(szDest, nSize, szFormat, args);
            if (nResult >= nSize)
            {
                nResult = nSize - 1;
                szDest[nResult] = 0;
            }
            return nResult;
        }
        return vsprintf(szDest, szFormat, args);
    }
    return 0;
}

// calling-convention shim (not game code)
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...)
{
    if (!szDest || !szFormat)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00413A00_VPrintf(szDest, nMaxCount, szFormat, (va_list)(&szFormat + 1));
}

// calling-convention shim (not game code)
extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list args)
{
    if (!szDest || !szFormat)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00413A00_VPrintf(szDest, nMaxCount, szFormat, args);
}
