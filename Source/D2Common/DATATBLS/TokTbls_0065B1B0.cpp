struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2ObjModeTypeTxt
{
    char szName[32];
    unsigned int dwToken;
    char unk0x24[16];
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
int gnObjModeTypeTxtRecordCount;                                                                            // 0x0096D4C8
D2ObjModeTypeTxt* gpObjModeTypeTxt;                                                                         // 0x0096D4CC
D2ObjModeTypeTxt* gpObjType;                                                                                // 0x0096D4D0
D2ObjModeTypeTxt* gpObjMode;                                                                                // 0x0096D4D4
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
#pragma function(memcpy)
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065B1B0
void __fastcall DATATBLS_LoadObjType_ModeTxt(void* hArchive)
{
    int nTypeRecords;
    int nModeRecords;
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2ObjModeTypeTxt* pType = (D2ObjModeTypeTxt*)DATATBLS_CompileTxt(hArchive, "objtype", pTbl, &nTypeRecords, sizeof(D2ObjModeTypeTxt));
    D2ObjModeTypeTxt* pModeSrc = (D2ObjModeTypeTxt*)DATATBLS_CompileTxt(hArchive, "objmode", pTbl, &nModeRecords, sizeof(D2ObjModeTypeTxt));

    int nTotal = nModeRecords + nTypeRecords;
    D2ObjModeTypeTxt* pTxt = (D2ObjModeTypeTxt*)FOG_AllocPool(0, sizeof(D2ObjModeTypeTxt) * nTotal, ".\\DATATBLS\\TokTbls.cpp", 148, 0);
    TBL_ASSERT(pTxt, 149);

    memcpy(pTxt, pType, sizeof(D2ObjModeTypeTxt) * nTypeRecords);
    D2ObjModeTypeTxt* pMode = pTxt + nTypeRecords;
    memcpy(pMode, pModeSrc, sizeof(D2ObjModeTypeTxt) * nModeRecords);

    DATATBLS_UnloadBin(pType);
    DATATBLS_UnloadBin(pModeSrc);

    gpObjMode = pMode;
    gpObjModeTypeTxt = pTxt;
    gpObjType = pTxt;
    gnObjModeTypeTxtRecordCount = nTotal;
}
