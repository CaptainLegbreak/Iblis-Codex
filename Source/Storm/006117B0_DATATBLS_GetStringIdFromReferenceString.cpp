struct _iobuf;

struct D2StatesTxt
{
    unsigned short wState;
    char unk0x02[0xE];
    unsigned char nStateFlags[8];
    char unk0x18[0x24];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                              // 0x0068239A
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fclose(_iobuf* pFile);                                                              // 0x00681FDC
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);            // 0x006CC468
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText);               // 0x00524D30
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

extern "C" const char gszPathFormat_006D4124[];                                                            // 0x006D4124
extern "C" const char gszExcelDirectory_006D8ED4[];                                                        // 0x006D8ED4
extern "C" const char gszFileModeWb_006D69E0[];                                                            // 0x006D69E0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2StatesTxt* gpStatesTxt;                                                                            // 0x0096BCEC
int gnStatesTxtRecordCount;                                                                                 // 0x0096BCF4

// 0x006117B0
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference)
{
    const wchar_t* pUnicode;
    unsigned short nIndex = sub_00524D30_FindString(szReference, &pUnicode);
    if (!nIndex)
        nIndex = 5382;
    return nIndex;
}

// 0x006118B0
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize)
{
    while (*pSize + nBufferSize >= *pSizeEx)
    {
        *pSizeEx += 1024;
        if (*pSizeEx >= 0x7FFFFFFF)
            return 0;
        *ppCodes = (char*)FOG_ReallocPool(0, *ppCodes, *pSizeEx, ".\\DATATBLS\\DataTbls.cpp", 658, 0);
    }
    int nResult = *pSize;
    memcpy(*ppCodes + nResult, pBuffer, nBufferSize);
    *pSize += nBufferSize;
    return nResult;
}

// 0x00611DC0
void __fastcall sub_00611DC0_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1611, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x00611E60
void __fastcall sub_00611E60_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1634, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (*(short*)((char*)&pStatesTxt[i] + nFieldOffset) > 0)
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x006121F0
void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount)
{
    char szFilePath[260];
    wsprintfA(szFilePath, gszPathFormat_006D4124, gszExcelDirectory_006D8ED4, szFileName);
    _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(&nRecordCount, sizeof(nRecordCount), 1, pFile);
        fwrite(pWriteBuffer, nBufferSize, 1, pFile);
        fclose(pFile);
    }
}
