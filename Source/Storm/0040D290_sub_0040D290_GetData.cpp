struct _iobuf;

#pragma pack(push, 1)
struct D2CrashDumpEntryStrc
{
    unsigned short nHits;
    unsigned long f_2;
    unsigned long f_6;
    unsigned long dwType;
    unsigned char nCount;
    unsigned long adwData[8];
};
#pragma pack(pop)

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin);                                     // 0x00684A2A
extern "C" long __cdecl ftell(_iobuf* pFile);                                                               // 0x00684935
extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
int __stdcall SMemCmp(const void* pLocation1, const void* pLocation2, unsigned int nSize);                  // 0x0041D200
extern "C" const char gszReadBinary_006CDC90[];                                                             // 0x006CDC90
extern "C" const char gszExceptionsFile_006CD628[];                                                         // 0x006CD628

// 0x0040D290
int __fastcall sub_0040D290_GetData(char* pBuffer, unsigned int* pnSize)
{
    char szPath[0x104];
    unsigned long adwData[8];

    sub_0040F000_GetLogDirectory(szPath, 0x104);
    sub_00413800(szPath, "Crashdump", 0x104);
    if (GetFileAttributesA(szPath) == 0xFFFFFFFF)
    {
        return 0;
    }

    const unsigned int nMaxSize = *pnSize;
    _iobuf* pFile = fopen(szPath, gszReadBinary_006CDC90);
    if (!pFile)
    {
        return 0;
    }

    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }

    const long nFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    char* pData = (char*)FOG_Alloc(nFileSize, gszExceptionsFile_006CD628, 0x75B, 0);
    fread(pData, 1, nFileSize, pFile);
    fclose(pFile);
    DeleteFileA(szPath);

    *pnSize = 1;
    int nEntries = 0;
    const unsigned long* pEnd = (const unsigned long*)(pData + nFileSize);
    const unsigned long* pRecord = (const unsigned long*)pData;
    if (pRecord < pEnd)
    {
        const char* pLimit = pBuffer + nMaxSize;
        do
        {
            const unsigned long dwHeader0 = *pRecord++;
            const unsigned long dwHeader1 = *pRecord++;
            const unsigned long dwType = *pRecord++;
            const int nCount = *pRecord++;
            const unsigned int nDataSize = nCount * 4;
            SMemCopy(adwData, pRecord, nDataSize);
            pRecord = (const unsigned long*)((const char*)pRecord + nDataSize);

            D2CrashDumpEntryStrc* pEntry = (D2CrashDumpEntryStrc*)(pBuffer + 1);
            int i;
            for (i = 0; i < nEntries; ++i)
            {
                if (pEntry->f_2 == dwHeader0 && pEntry->f_6 == dwHeader1 && pEntry->dwType == dwType
                    && pEntry->nCount == (unsigned char)nCount && !SMemCmp(pEntry->adwData, adwData, nDataSize))
                {
                    ++pEntry->nHits;
                    break;
                }
                pEntry = (D2CrashDumpEntryStrc*)((char*)pEntry + nDataSize + 0xF);
            }

            if (i == nEntries)
            {
                if ((char*)(pEntry + 1) >= pLimit)
                {
                    break;
                }

                pEntry->nHits = 1;
                pEntry->f_2 = dwHeader0;
                pEntry->f_6 = dwHeader1;
                pEntry->dwType = dwType;
                pEntry->nCount = (unsigned char)nCount;
                SMemCopy(pEntry->adwData, adwData, nDataSize);
                ++nEntries;
                *pnSize += nDataSize + 0xF;
            }
        }
        while (pRecord < pEnd);
    }

    *pBuffer = (char)nEntries;
    return 1;
}
