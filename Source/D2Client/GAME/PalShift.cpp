#include "D2MonsterIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2DataTablesStrc;

struct D2ShiftRowsStrc;


struct D2PalShiftNodeStrc;

struct D2PalShiftEntryStrc;

struct D2ShiftRowsStrc
{
    unsigned char aRows[8][256];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned char* gpBloodRemap_007BB384; // 0x007BB384

void __fastcall sub_00477060_EmitSink(D2PalShiftNodeStrc* pShift);

static __declspec(noinline) void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftNodeStrc* pShift);

struct D2PalShiftNodeStrc
{
    int nId;
    D2ShiftRowsStrc tBase;
    D2ShiftRowsStrc tBlood;
    D2PalShiftNodeStrc* pNext;
};

struct D2PalShiftEntryStrc
{
    int nId;
    D2PalShiftNodeStrc* pShift;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_00477170_LoadPalShift(int nMonsterId); // 0x00477170

extern D2PalShiftNodeStrc* gpPalShiftList_007B957C; // 0x007B957C

char gData_007B9580[7680]; // 0x007B9580

extern int gnGlobal_007B957C; // 0x007B957C

int gnGlobal_007BB380; // 0x007BB380

void* gpGlobal_007BB384; // 0x007BB384

D2PalShiftEntryStrc* gpPalShiftEntries_007B9578; // 0x007B9578

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);


struct D2PaletteShiftRecStrc
{
    int nId;
    D2PalShiftNodeStrc* pShift;
};

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

int __fastcall DATATBLS_GetMonStatsTxtRecordCount();                                                        // 0x0045C460

D2PalShiftNodeStrc* __fastcall sub_00477030_FindPalShiftNode(int nId);                                          // 0x00477030

int __fastcall sub_00516E46_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46

void __fastcall sub_00516E84_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84

void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85




// build: context UNITS_GetMonStats2TxtRecordFromMonsterId
static inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

// 0x00476E30
void __cdecl sub_00476E30_LoadGreenBlood()
{
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpGlobal_007BB384 = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile);
    }
}

// 0x00476EA0
void __cdecl sub_00476EA0_LoadPalShift()
{
    int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(D2PalShiftEntryStrc);
    D2PalShiftEntryStrc* pEntries = (D2PalShiftEntryStrc*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x63, 0);
    gpPalShiftEntries_007B9578 = pEntries;
    memset(pEntries, 0, nSize);
    int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }
    gnGlobal_007B957C = 0;
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\RandTransforms.dat", &hFile, 1))
    {
        ARCHIVE_ReadFileToBuffer(0, hFile, gData_007B9580, 0x1E00);
        ARCHIVE_CloseFile(0, hFile);
        gnGlobal_007BB380 = 1;
    }
    void* hFile2;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile2, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpGlobal_007BB384 = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile2, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile2);
    }
}

// 0x00476FB0
void __cdecl sub_00476FB0()
{
    while (gpPalShiftList_007B957C)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList_007B957C->pNext;
        FOG_Free(gpPalShiftList_007B957C, ".\\GAME\\PalShift.cpp", 0x84, 0);
        gpPalShiftList_007B957C = pNext;
    }
    if (gpPalShiftEntries_007B9578)
    {
        FOG_Free(gpPalShiftEntries_007B9578, ".\\GAME\\PalShift.cpp", 0x8A, 0);
        gpPalShiftEntries_007B9578 = 0;
    }
    if (gpGlobal_007BB384)
    {
        FOG_Free(gpGlobal_007BB384, ".\\GAME\\PalShift.cpp", 0x90, 0);
        gpGlobal_007BB384 = 0;
    }
}

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

// The original builds this function without optimization (its code keeps every value on the stack).
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

    if (!sub_00516E46_OpenFile(0, szFile, &hFile, 1))
    {
        return;
    }

    pShift = (D2PalShiftNodeStrc*)FOG_Alloc(sizeof(D2PalShiftNodeStrc), ".\\GAME\\PalShift.cpp", 244, 0);
    memset(pShift, 0, sizeof(D2PalShiftNodeStrc));
    ARCHIVE_ReadFileToBuffer(0, hFile, &pShift->tBase, sizeof(pShift->tBase));
    sub_00516E84_CloseFile(0, hFile);
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

// build: context sub_00477060_Shim
// calling-convention shim (not game code)
void __fastcall sub_00477060_Shim(D2PalShiftNodeStrc* pShift, int nMonsterId)
{
    sub_00477060_BuildBloodShift(nMonsterId, pShift);
    sub_00477060_EmitSink(pShift);
}

// 0x00477470
void __cdecl sub_00477470_InitPalShifts()
{
    while (gpPalShiftList_007B957C)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList_007B957C->pNext;
        FOG_Free(gpPalShiftList_007B957C, ".\\GAME\\PalShift.cpp", 0x117, 0);
        gpPalShiftList_007B957C = pNext;
    }

    const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    D2PalShiftEntryStrc* pEntries = gpPalShiftEntries_007B9578;
    const int nSize = nCount * sizeof(D2PalShiftEntryStrc);
    if (!pEntries)
    {
        pEntries = (D2PalShiftEntryStrc*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x11F, 0);
        gpPalShiftEntries_007B9578 = pEntries;
    }
    memset(pEntries, 0, nSize);
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }

    sub_00477170_LoadPalShift(MONSTER_NECROSKELETON);
    sub_00477170_LoadPalShift(MONSTER_NECROMAGE);
    sub_00477170_LoadPalShift(MONSTER_SPIRITWOLF);
    sub_00477170_LoadPalShift(MONSTER_FENRIS);
}

