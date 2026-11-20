#include "D2DataTbls.h"
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

struct D2MonStatsTxt
{
    char unk0x00[0x10];
    char szCode[4];
    char unk0x14[0x4];
    short nMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x00[0x11C];
    unsigned char nLocalBlood;
    char unk0x11D[0x134 - 0x11D];
};


struct D2ShiftRowsStrc
{
    unsigned char aRows[8][256];
};

struct D2PalShiftNodeStrc
{
    int nId;
    D2ShiftRowsStrc tBase;
    D2ShiftRowsStrc tBlood;
    D2PalShiftNodeStrc* pNext;
};

struct D2PaletteShiftRecStrc
{
    int nId;
    D2PalShiftNodeStrc* pShift;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall DATATBLS_GetMonStatsTxtRecordCount();                                                        // 0x0045C460
D2PalShiftNodeStrc* __fastcall sub_00477030_FindPalShiftNode(int nId);                                          // 0x00477030
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2PaletteShiftRecStrc* gpPalShiftEntries_007B9578;                                                     // 0x007B9578
extern D2PalShiftNodeStrc* gpPalShiftList_007B957C;                                                             // 0x007B957C
extern unsigned char* gpBloodRemap_007BB384;                                                                // 0x007BB384

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId
static inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

static __declspec(noinline) void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftNodeStrc* pShift);

// 0x00477060
static void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftNodeStrc* pShift)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2TxtRecord || pMonStats2TxtRecord->nLocalBlood != 2)
    {
        return;
    }

    pShift->tBlood = pShift->tBase;

    const unsigned char* pRemap = gpBloodRemap_007BB384;
    for (int nRow = 0; nRow < 8; ++nRow)
    {
        const unsigned char* pSrc = pShift->tBase.aRows[nRow];
        unsigned char* pDst = pShift->tBlood.aRows[nRow];
        for (int i = 0; i < 256; ++i)
        {
            const unsigned char nIndex = pSrc[i];
            if (pRemap[nIndex])
            {
                pDst[i] = pRemap[nIndex];
            }
        }
    }
}

#pragma optimize("", off)
// 0x00477170
void __fastcall sub_00477170_LoadPalShift(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord;
    char szCode[4];
    char szFile[256];
    void* hFile;
    D2PalShiftNodeStrc* pShift;

    pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    if (sub_00477030_FindPalShiftNode(nMonsterId))
    {
        return;
    }

    szCode[0] = pMonStatsTxtRecord->szCode[0] != ' ' ? pMonStatsTxtRecord->szCode[0] : 0;
    szCode[1] = pMonStatsTxtRecord->szCode[1] != ' ' ? pMonStatsTxtRecord->szCode[1] : 0;
    szCode[2] = pMonStatsTxtRecord->szCode[2] != ' ' ? pMonStatsTxtRecord->szCode[2] : 0;
    szCode[3] = 0;
    szCode[2] = 0;

    strcpy(szFile, "Data\\Global\\Monsters\\");
    strcat(szFile, szCode);
    strcat(szFile, "\\Cof\\palshift.dat");

    if (!ARCHIVE_OpenFile(0, szFile, &hFile, 1))
    {
        return;
    }

    pShift = (D2PalShiftNodeStrc*)FOG_Alloc(sizeof(D2PalShiftNodeStrc), ".\\GAME\\PalShift.cpp", 244, 0);
    memset(pShift, 0, sizeof(D2PalShiftNodeStrc));
    ARCHIVE_ReadFileToBuffer(0, hFile, &pShift->tBase, sizeof(pShift->tBase));
    ARCHIVE_CloseFile(0, hFile);
    sub_00477060_BuildBloodShift(nMonsterId, pShift);
    pShift->nId = nMonsterId;
    pShift->pNext = gpPalShiftList_007B957C;
    gpPalShiftList_007B957C = pShift;

    for (int i = 0; i < DATATBLS_GetMonStatsTxtRecordCount(); ++i)
    {
        if (pShift->nId == i)
        {
            gpPalShiftEntries_007B9578[i].pShift = pShift;
        }
    }
}
#pragma optimize("", on)
