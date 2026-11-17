struct D2BinFieldStrc;
struct D2BinFileStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall sub_00612280_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, int* pSize, const char* szFile, int nLine); // 0x00612280
void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount); // 0x006121F0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize);                             // 0x006BD640
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile);                                       // 0x006BCDE0
void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile);                                                    // 0x006BCDA0

extern int gbCompileTxt;                                                                                    // 0x0096C8B4
extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308

// 0x006122F0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize)
{
    int nDataSize = 0;
    void* pData;
    void* pTxt;
    int nRecordCount;
    char szPath[256];

    if (gbCompileTxt)
    {
        if (!_stricmp(szName, "leveldefs"))
        {
            pData = sub_00612280_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2233);
        }
        else
        {
            pData = sub_00612280_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2240);
        }
        D2_ASSERT(pData, 2242);

        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2249, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);

        strcpy(szPath, szName);
        strcat(szPath, ".bin");
        DATATBLS_WriteBinFile(szPath, pTxt, nRecordSize * nRecordCount, nRecordCount);
        sub_0040B480(0, pTxt, ".\\DATATBLS\\DataTbls.cpp", 2262, 0);
    }

    if (DATATBLS_LoadFromBin)
    {
        pData = sub_00612280_ReadExcelFile(hArchive, szName, ".bin", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2270);
    }
    else
    {
        if (!_stricmp(szName, "leveldefs"))
            pData = sub_00612280_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2274);
        else
            pData = sub_00612280_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2276);
    }
    D2_ASSERT(pData, 2279);

    if (DATATBLS_LoadFromBin)
    {
        nRecordCount = *(int*)pData;
        pTxt = (char*)pData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2308, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pTxt;
}
