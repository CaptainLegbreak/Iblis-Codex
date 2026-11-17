struct D2FixedFileInfoStrc
{
    unsigned int dwSignature;
    unsigned int dwStrucVersion;
    unsigned short wFileVersionMSLow;
    unsigned short wFileVersionMSHigh;
    unsigned short wFileVersionLSLow;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_00516AC0_ReadVxdVersionResource(const char* szFileName, unsigned long* pSize, void* pBuffer); // 0x00516AC0
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);                      // 0x006CC2E4
extern "C" int __stdcall VerQueryValueA(const void* pBlock, const char* szSubBlock, void** ppBuffer, unsigned int* puLen); // 0x006B01A4

extern "C" const char szD2SoundUtilFile_006DEB68[];                                                         // 0x006DEB68

// 0x00516C40
unsigned long __fastcall sub_00516C40_GetVersionInfoSize(const char* szPath)
{
    unsigned long nSize = 0;
    if (!sub_00516AC0_ReadVxdVersionResource(szPath, &nSize, 0) && GetLastError() == 0x7A)
    {
        SetLastError(0);
        return nSize;
    }
    return 0;
}

// 0x00516C80
int __fastcall sub_00516C80_GetVersionInfo(const char* szPath, unsigned long nSize, void* pBuffer)
{
    return sub_00516AC0_ReadVxdVersionResource(szPath, &nSize, pBuffer);
}

// 0x00516CA0
int __fastcall sub_00516CA0_GetFileVersion(const char* szPath, unsigned int* pMajor, unsigned int* pMinor, unsigned int* pBuild)
{
    unsigned long nSize = sub_00516C40_GetVersionInfoSize(szPath);
    if (!nSize)
        return 0;

    void* pBuffer = FOG_Alloc(nSize, szD2SoundUtilFile_006DEB68, 0x21C, 0);
    if (!sub_00516C80_GetVersionInfo(szPath, nSize, pBuffer))
    {
        FOG_Free(pBuffer, szD2SoundUtilFile_006DEB68, 0x221, 0);
        return 0;
    }

    D2FixedFileInfoStrc* pInfo;
    unsigned int nInfoLen;
    if (!VerQueryValueA(pBuffer, "\\", (void**)&pInfo, &nInfoLen))
    {
        FOG_Free(pBuffer, szD2SoundUtilFile_006DEB68, 0x229, 0);
        return 0;
    }

    *pMajor = pInfo->wFileVersionMSHigh;
    *pMinor = pInfo->wFileVersionMSLow;
    *pBuild = pInfo->wFileVersionLSLow;
    return 1;
}
