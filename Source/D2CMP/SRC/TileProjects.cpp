struct D2CmpTileLibraryStrc;
struct D2CmpFindTilesNodeStrc;

struct D2TileRecordStrc
{
    char szName[0x104];
    D2CmpTileLibraryStrc* pLibrary;
    D2CmpFindTilesNodeStrc** ppFindTiles;
    D2TileRecordStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall TileProjectDestroy(D2CmpTileLibraryStrc* pLibrary, int bKeep);                    // 0x00609E90
void __fastcall sub_0060CE00_FreeFindTilesTable(D2CmpFindTilesNodeStrc** ppBuckets);                        // 0x0060CE00
D2TileRecordStrc* gpTileRecords_008ADBB4;                                                                   // 0x008ADBB4

// 0x006006B0
void __cdecl D2CMPDestroyTileHeaders()
{
    D2TileRecordStrc* pRecord = gpTileRecords_008ADBB4;
    while (pRecord)
    {
        D2TileRecordStrc* pNext = pRecord->pNext;
        TileProjectDestroy(pRecord->pLibrary, 0);
        pRecord->pLibrary = 0;
        sub_0060CE00_FreeFindTilesTable(pRecord->ppFindTiles);
        pRecord->ppFindTiles = 0;
        FOG_Free(pRecord, ".\\SRC\\TileProjects.cpp", 0x2A, 0);
        pRecord = pNext;
    }
    gpTileRecords_008ADBB4 = 0;
}
