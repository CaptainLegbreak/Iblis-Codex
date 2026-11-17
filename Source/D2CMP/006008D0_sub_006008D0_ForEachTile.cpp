struct D2TileLibraryHashStrc;

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x60];
};

struct D2TileLibraryHeaderStrc
{
    int dwVersion;
    int dwFlags;
    char szLibraryName[260];
    int nTiles;
    D2TileLibraryEntryStrc* pFirst;
};

struct D2TileRecordStrc
{
    char szLibraryName[260];
    D2TileLibraryHeaderStrc* pLibrary;
    D2TileLibraryHashStrc* pHashBlock;
    D2TileRecordStrc* pPrev;
};

typedef void (__fastcall* TILEFN)(D2TileLibraryEntryStrc* pTile, void* pArg);

static D2TileRecordStrc* gpTileRecords_008ADBB4;                                                            // 0x008ADBB4

void __stdcall sub_P11_EmitSetTileRecords(D2TileRecordStrc* pRecords)
{
    gpTileRecords_008ADBB4 = pRecords;
}

// 0x006008D0
int __stdcall sub_006008D0_ForEachTile(TILEFN pfnTile, void* pArg)
{
    D2TileRecordStrc* pRecord = gpTileRecords_008ADBB4;
    int nCount = 0;
    if (!pfnTile)
    {
        return 0;
    }

    for (; pRecord; pRecord = pRecord->pPrev)
    {
        D2TileLibraryHeaderStrc* pLibrary = pRecord->pLibrary;
        for (int i = 0; i < pLibrary->nTiles; ++i)
        {
            pfnTile(&pLibrary->pFirst[i], pArg);
            ++nCount;
        }
    }

    return nCount;
}
