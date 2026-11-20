#include "D2CMP.h"
struct D2CmpTileLibraryStrc;
struct D2CmpFindTilesNodeStrc;

struct D2TileRecordStrc
{
    char szName[0x104];
    D2CmpTileLibraryStrc* pLibrary;
    D2TileLibraryHashStrc* pHashBlock;
    D2TileRecordStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall TileProjectDestroy(D2CmpTileLibraryStrc* pLibrary, int bKeep);                    // 0x00609E90
void __fastcall sub_0060CE00_FreeFindTilesTable(D2CmpFindTilesNodeStrc** ppBuckets);                        // 0x0060CE00
static D2TileRecordStrc* gpTileRecords_008ADBB4;                                                                   // 0x008ADBB4

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall sub_005FDF80_GetTileLibrarySize(const char* szFilePath);                                     // 0x005FDF80

void __stdcall sub_0060A390(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName); // 0x0060A390
D2TileLibraryHashStrc* __fastcall sub_0060A440_CreateTileHashBlock(D2CmpTileLibraryStrc* pLibrary);        // 0x0060A440

// 0x006006B0
void __cdecl D2CMPDestroyTileHeaders()
{
    D2TileRecordStrc* pRecord = gpTileRecords_008ADBB4;
    while (pRecord)
    {
        D2TileRecordStrc* pNext = pRecord->pNext;
        TileProjectDestroy(pRecord->pLibrary, 0);
        pRecord->pLibrary = 0;
        sub_0060CE00_FreeFindTilesTable((D2CmpFindTilesNodeStrc**)pRecord->pHashBlock);
        pRecord->pHashBlock = 0;
        FOG_Free(pRecord, ".\\SRC\\TileProjects.cpp", 0x2A, 0);
        pRecord = pNext;
    }
    gpTileRecords_008ADBB4 = 0;
}

// 0x00600710
static D2TileRecordStrc* sub_00600710_FindTileRecord(const char* szName)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords_008ADBB4; pRecord; pRecord = pRecord->pNext)
    {
        if (!strcmp(pRecord->szName, szName))
        {
            return pRecord;
        }
    }
    return 0;
}

// 0x00600760
D2TileLibraryHashStrc* __stdcall sub_00600760_GetTileHashBlock(const char* szName)
{
    D2TileRecordStrc* pRecord = sub_00600710_FindTileRecord(szName);
    if (pRecord)
    {
        return pRecord->pHashBlock;
    }
    return 0;
}

// 0x00600790
D2CmpTileLibraryStrc* __stdcall D2CMPLoadProjectRecord(D2TileLibraryHashStrc** ppHashBlock, const char* szName)
{
    D2CmpTileLibraryStrc* pLibrary = 0;
    void* hFile = 0;
    D2TileRecordStrc* pRecord = sub_00600710_FindTileRecord(szName);
    if (pRecord)
    {
        *ppHashBlock = pRecord->pHashBlock;
        return pRecord->pLibrary;
    }
    const int nSize = sub_005FDF80_GetTileLibrarySize(szName);
    void* ptData = FOG_Alloc(nSize, ".\\SRC\\TileProjects.cpp", 0x6B, 0);
    D2_ASSERT(ptData, 0x6C);
    memset(ptData, 0, nSize);
    ARCHIVE_OpenFile(0, szName, &hFile, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, ptData, nSize);
    ARCHIVE_CloseFile(0, hFile);
    sub_0060A390((D2CmpTileLibraryStrc*)ptData, &pLibrary, szName);
    D2TileLibraryHashStrc* pHashBlock = sub_0060A440_CreateTileHashBlock(pLibrary);
    D2TileRecordStrc* pNew = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\TileProjects.cpp", 0x7B, 0);
    D2_ASSERT(pNew, 0x7C);
    memset(pNew, 0, sizeof(D2TileRecordStrc));
    pNew->pNext = gpTileRecords_008ADBB4;
    pNew->pLibrary = pLibrary;
    pNew->pHashBlock = pHashBlock;
    gpTileRecords_008ADBB4 = pNew;
    strcpy(pNew->szName, szName);
    *ppHashBlock = pNew->pHashBlock;
    return pLibrary;
}
