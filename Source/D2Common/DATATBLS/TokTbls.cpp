#include "D2Common.h"
#include "D2Records.h"

struct D2BinFieldStrc;

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
extern void* gpCompositTxt; // 0x0096D4EC
extern void* gpArmtypeTxt; // 0x0096D4E8

void* gpMonmodeTxt; // 0x0096D4BC

void* gpMonmodeTxtAlias1; // 0x0096D4C0

void* gpMonmodeTxtAlias2; // 0x0096D4C4

int gnMonmodeTxtRecordCount; // 0x0096D4B8

// 0x0065AEF0
void __fastcall DATATBLS_LoadMonModeTxt(void* hArchive)
{
    int nRecordCount;
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { "DT_Dir", 6, 0, 36, 0 },
        { "NU_Dir", 6, 0, 37, 0 },
        { "WL_Dir", 6, 0, 38, 0 },
        { "GH_Dir", 6, 0, 39, 0 },
        { "A1_Dir", 6, 0, 40, 0 },
        { "A2_Dir", 6, 0, 41, 0 },
        { "BL_Dir", 6, 0, 42, 0 },
        { "SC_Dir", 6, 0, 43, 0 },
        { "S1_Dir", 6, 0, 44, 0 },
        { "S2_Dir", 6, 0, 45, 0 },
        { "S3_Dir", 6, 0, 46, 0 },
        { "S4_Dir", 6, 0, 47, 0 },
        { "DD_Dir", 6, 0, 48, 0 },
        { "KB_Dir", 6, 0, 49, 0 },
        { "SQ_Dir", 6, 0, 50, 0 },
        { "RN_Dir", 6, 0, 51, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonmodeTxt = DATATBLS_CompileTxt(hArchive, "monmode", pTbl, &nRecordCount, 52);
    gnMonmodeTxtRecordCount = nRecordCount;
    gpMonmodeTxtAlias1 = gpMonmodeTxt;
    gpMonmodeTxtAlias2 = gpMonmodeTxt;
}

// 0x0065B2E0
void __fastcall DATATBLS_LoadCompositTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCompositTxt = DATATBLS_CompileTxt(hArchive, "composit", pTbl, 0, 52);
}

// 0x0065B350
void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpArmtypeTxt = DATATBLS_CompileTxt(hArchive, "armtype", pTbl, 0, 52);
}
