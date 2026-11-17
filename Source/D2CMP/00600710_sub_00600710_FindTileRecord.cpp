extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
int __fastcall sub_005FDF80_GetTileLibrarySize(const char* szFilePath);                                     // 0x005FDF80

struct D2CmpTileLibraryStrc;
struct D2TileLibraryHashStrc;

void __stdcall sub_0060A390(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName); // 0x0060A390
D2TileLibraryHashStrc* __fastcall sub_0060A440_CreateTileHashBlock(D2CmpTileLibraryStrc* pLibrary);        // 0x0060A440

struct D2TileRecordStrc
{
    char szLibraryName[260];
    D2CmpTileLibraryStrc* pLibrary;
    D2TileLibraryHashStrc* pHashBlock;
    D2TileRecordStrc* pPrev;
};

static D2TileRecordStrc* gpTileRecords_008ADBB4;                                                            // 0x008ADBB4

// 0x00600710
static D2TileRecordStrc* sub_00600710_FindTileRecord(const char* szName)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords_008ADBB4; pRecord; pRecord = pRecord->pPrev)
    {
        if (!strcmp(pRecord->szLibraryName, szName))
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
D2CmpTileLibraryStrc* __stdcall sub_00600790_LoadTileLibrary(D2TileLibraryHashStrc** ppHashBlock, const char* szName)
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
    void* pData = FOG_Alloc(nSize, ".\\SRC\\TileProjects.cpp", 0x6B, 0);
    D2_ASSERT(pData, 0x6C);
    memset(pData, 0, nSize);
    ARCHIVE_OpenFile(0, szName, &hFile, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, pData, nSize);
    ARCHIVE_CloseFile(0, hFile);
    sub_0060A390((D2CmpTileLibraryStrc*)pData, &pLibrary, szName);
    D2TileLibraryHashStrc* pHashBlock = sub_0060A440_CreateTileHashBlock(pLibrary);
    D2TileRecordStrc* pNew = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\TileProjects.cpp", 0x7B, 0);
    D2_ASSERT(pNew, 0x7C);
    memset(pNew, 0, sizeof(D2TileRecordStrc));
    pNew->pPrev = gpTileRecords_008ADBB4;
    pNew->pLibrary = pLibrary;
    pNew->pHashBlock = pHashBlock;
    gpTileRecords_008ADBB4 = pNew;
    strcpy(pNew->szLibraryName, szName);
    *ppHashBlock = pNew->pHashBlock;
    return pLibrary;
}
