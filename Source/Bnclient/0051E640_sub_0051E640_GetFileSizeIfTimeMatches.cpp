extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite); // 0x006CC2F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pHigh);   // 0x006CC2F0

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0

// 0x0051E640
static __declspec(noinline) unsigned long sub_0051E640_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime)
{
    void* hFile = sub_00406960_CreateFile(szFile, 0x80000000, 3, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
        return 0;

    __int64 nWriteTime;
    GetFileTime(hFile, 0, 0, &nWriteTime);
    __int64 nDiff = nWriteTime - *pFileTime;
    if (nDiff < 0)
        nDiff = -nDiff;
    const unsigned __int64 nAbs = nDiff;

    if (!(unsigned long)(nAbs >> 32) && (unsigned long)nAbs <= 40000000)
    {
        const unsigned long nFileSize = GetFileSize(hFile, 0);
        sub_004069A0_CloseFile(hFile);
        return nFileSize;
    }

    sub_004069A0_CloseFile(hFile);
    return 0;
}

unsigned long __fastcall sub_H04_Emit_0051E640(const char* szFile, const __int64* pFileTime)
{
    return sub_0051E640_GetFileSizeIfTimeMatches(szFile, pFileTime);
}
