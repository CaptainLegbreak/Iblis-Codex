struct D2BinFieldStrc;
struct D2BinFileStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void* __stdcall sub_005043E0_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize); // 0x005043E0
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile);                                                    // 0x006BCDA0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile);                                       // 0x006BCDE0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize);                             // 0x006BD640
void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780

extern "C" const char gszExcelDirectory_006D8ED4[];                                                         // 0x006D8ED4
extern "C" const char szBinExtension_006DCC68[];                                                            // 0x006DCC68
extern int gbD2WinBinMode_0072EF2C;                                                                         // 0x0072EF2C

// 0x00504430
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize)
{
    unsigned int nFileSize = 0;
    void* pFileData;
    if (gbD2WinBinMode_0072EF2C)
    {
        char szFilename[260];
        wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szBinExtension_006DCC68);
        pFileData = sub_00517079_LoadFile(hArchive, szFilename, &nFileSize, ".\\Src\\D2Comp.cpp", 0x958);
    }
    else if (!_stricmp(szName, "leveldefs"))
    {
        pFileData = sub_005043E0_LoadExcelFile(hArchive, "levels", ".txt", &nFileSize);
    }
    else
    {
        pFileData = sub_005043E0_LoadExcelFile(hArchive, szName, ".txt", &nFileSize);
    }

    D2_ASSERT(pFileData, 0x9E3);

    int nRecordCount;
    void* pBinData;
    if (gbD2WinBinMode_0072EF2C)
    {
        nRecordCount = *(int*)pFileData;
        pBinData = (char*)pFileData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pFileData, nFileSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        const int nSize = nRecordCount * nRecordSize;
        pBinData = FOG_AllocPool(0, nSize, ".\\Src\\D2Comp.cpp", 0x9FA, 0);
        memset(pBinData, 0, nSize);
        FOG_10207(pBinFile, pBinField, pBinData, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pBinData;
}

#include "gen/data/Source/D2Win/00504430_sub_00504430_CompileTxt.inc"
