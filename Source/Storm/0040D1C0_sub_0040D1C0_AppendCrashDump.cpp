struct _iobuf;

struct T0040D1C0
{
    unsigned long f_0;
    unsigned long f_4;
    unsigned long dwType;
    int nCount;
    unsigned long adwData[8];
};

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x0041D2A0

// 0x0040D1C0
void __fastcall sub_0040D1C0_AppendCrashDump(unsigned long dwHeader0, unsigned long dwHeader1, unsigned long dwType, int nCount, const void* pData)
{
    char szPath[0x104];
    T0040D1C0 tRecord;
    sub_0040F000_GetLogDirectory(szPath, 0x104);
    sub_00413800(szPath, "Crashdump", 0x104);
    _iobuf* pFile = fopen(szPath, "ab");
    if (pFile)
    {
        tRecord.f_0 = dwHeader0;
        tRecord.f_4 = dwHeader1;
        tRecord.dwType = dwType;
        tRecord.nCount = nCount;
        sub_0041D2A0_MemCopy(tRecord.adwData, pData, nCount * 4);
        fwrite(&tRecord, nCount * 4 + 0x10, 1, pFile);
        fclose(pFile);
    }
}
