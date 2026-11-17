void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMaxLength); // 0x004135D0

// 0x00414930
int __stdcall sub_00414930_GetRegistryRoot(unsigned int nFlags, char* szDest, unsigned int nMaxLength)
{
    int nValid = (__int64)szDest ? -1 : 0;
    nValid &= nMaxLength ? -1 : 0;
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    if (nFlags & 2)
        SStrCopy(szDest, "Software\\Battle.net\\", nMaxLength);
    else
        SStrCopy(szDest, "Software\\Blizzard Entertainment\\", nMaxLength);
    return nValid ? 1 : 0;
}
