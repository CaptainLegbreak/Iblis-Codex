#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2DrlgMaps.h"
#include "D2TxtTables.h"

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
    char pad0x781[3];
    int dwExpansion;
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* sz);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern D2DataTablesStrc sgtDataTables;                                                                      // 0x0096BC30

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall sub_0061E520(void* hArchive);

void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles);

// build: symbol ?sub_0061E4A0@@YAXPBDPAD@Z 0x0061E4A0
static void sub_0061E4A0(const char* szDirectory, char* szPath)
{
    char szBuffer[60];
    const int nLength = strlen(szPath);
    if (nLength)
    {
        for (int i = 0; i < nLength; ++i)
        {
            if (szPath[i] == '/')
                szPath[i] = '\\';
        }
    }
    if (nLength > 1)
    {
        wsprintfA(szBuffer, gszPathFormat_006D4124, szDirectory, szPath);
        strcpy(szPath, szBuffer);
    }
}

// 0x0061E520
void __fastcall sub_0061E520(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "File 1", 1, 0x3B, 0, 0 },
        { "File 2", 1, 0x3B, 0x3C, 0 },
        { "File 3", 1, 0x3B, 0x78, 0 },
        { "File 4", 1, 0x3B, 0xB4, 0 },
        { "File 5", 1, 0x3B, 0xF0, 0 },
        { "File 6", 1, 0x3B, 0x12C, 0 },
        { "File 7", 1, 0x3B, 0x168, 0 },
        { "File 8", 1, 0x3B, 0x1A4, 0 },
        { "File 9", 1, 0x3B, 0x1E0, 0 },
        { "File 10", 1, 0x3B, 0x21C, 0 },
        { "File 11", 1, 0x3B, 0x258, 0 },
        { "File 12", 1, 0x3B, 0x294, 0 },
        { "File 13", 1, 0x3B, 0x2D0, 0 },
        { "File 14", 1, 0x3B, 0x30C, 0 },
        { "File 15", 1, 0x3B, 0x348, 0 },
        { "File 16", 1, 0x3B, 0x384, 0 },
        { "File 17", 1, 0x3B, 0x3C0, 0 },
        { "File 18", 1, 0x3B, 0x3FC, 0 },
        { "File 19", 1, 0x3B, 0x438, 0 },
        { "File 20", 1, 0x3B, 0x474, 0 },
        { "File 21", 1, 0x3B, 0x4B0, 0 },
        { "File 22", 1, 0x3B, 0x4EC, 0 },
        { "File 23", 1, 0x3B, 0x528, 0 },
        { "File 24", 1, 0x3B, 0x564, 0 },
        { "File 25", 1, 0x3B, 0x5A0, 0 },
        { "File 26", 1, 0x3B, 0x5DC, 0 },
        { "File 27", 1, 0x3B, 0x618, 0 },
        { "File 28", 1, 0x3B, 0x654, 0 },
        { "File 29", 1, 0x3B, 0x690, 0 },
        { "File 30", 1, 0x3B, 0x6CC, 0 },
        { "File 31", 1, 0x3B, 0x708, 0 },
        { "File 32", 1, 0x3B, 0x744, 0 },
        { "Act", 4, 0, 0x780, 0 },
        { gszTxtField_Expansion, 2, 0, 0x784, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    D2LvlTypesTxt* pLvlTypesTxt = (D2LvlTypesTxt*)DATATBLS_CompileTxt(hArchive, "lvltypes", pTbl, &sgtDataTables.nLvlTypesTxtRecordCount, sizeof(D2LvlTypesTxt));
    sgtDataTables.pLvlTypesTxt = pLvlTypesTxt;
    D2LvlTypesTxt* pRecord = pLvlTypesTxt;
    for (int i = 0; i < sgtDataTables.nLvlTypesTxtRecordCount; ++i)
    {
        for (int j = 0; j < 0x20; ++j)
        {
            sub_0061E4A0("DATA\\GLOBAL\\TILES", pRecord->szFile[j]);
        }
        ++pRecord;
    }
}

// 0x0061EBB0
void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Def", 2, 0, 0, 0 },
        { "LevelId", 2, 0, 4, 0 },
        { "Populate", 2, 0, 8, 0 },
        { "Logicals", 2, 0, 0xC, 0 },
        { "Outdoors", 2, 0, 0x10, 0 },
        { "Animate", 2, 0, 0x14, 0 },
        { "KillEdge", 2, 0, 0x18, 0 },
        { "FillBlanks", 2, 0, 0x1C, 0 },
        { "SizeX", 2, 0, 0x28, 0 },
        { "SizeY", 2, 0, 0x2C, 0 },
        { "AutoMap", 2, 0, 0x30, 0 },
        { "Scan", 2, 0, 0x34, 0 },
        { "Pops", 2, 0, 0x38, 0 },
        { "PopPad", 2, 0, 0x3C, 0 },
        { "Files", 2, 0, 0x40, 0 },
        { "File1", 1, 0x3B, 0x44, 0 },
        { "File2", 1, 0x3B, 0x80, 0 },
        { "File3", 1, 0x3B, 0xBC, 0 },
        { "File4", 1, 0x3B, 0xF8, 0 },
        { "File5", 1, 0x3B, 0x134, 0 },
        { "File6", 1, 0x3B, 0x170, 0 },
        { "Dt1Mask", 2, 0, 0x1AC, 0 },
        { gszTxtField_Expansion, 2, 0, 0x20, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    sgtDataTables.pLvlPrestTxt = (D2LvlPrestTxt*)DATATBLS_CompileTxt(hArchive, "lvlprest", pTbl, &sgtDataTables.nLvlPrestTxtRecordCount, sizeof(D2LvlPrestTxt));
    if (bLoadFiles)
    {
        const int nSize = sizeof(D2DrlgFileStrc*) * 6 * sgptDataTables->nLvlPrestTxtRecordCount;
        sgtDataTables.ppLvlPrestFiles = (D2DrlgFileStrc**)FOG_Alloc(nSize, ".\\DATATBLS\\LvlTbls.cpp", 0x2A7, 0);
        memset(sgtDataTables.ppLvlPrestFiles, 0, nSize);
    }
    D2LvlPrestTxt* pRecord = sgtDataTables.pLvlPrestTxt;
    const int bExpansion = sub_00408F20_HasExpansionMpq();
    for (int i = 0; i < sgptDataTables->nLvlPrestTxtRecordCount; ++i, ++pRecord)
    {
        if (bExpansion || !pRecord->dwExpansion)
        {
            for (unsigned int j = 0; j < 6; ++j)
            {
                sub_0061E4A0("DATA\\GLOBAL\\TILES", pRecord->szFile[j]);
                if (bLoadFiles && strlen(pRecord->szFile[j]) > 1)
                    DRLGPRESET_LoadDrlgFile(&sgtDataTables.ppLvlPrestFiles[j + 6 * i], 0, pRecord->szFile[j]);
            }
        }
    }
}
