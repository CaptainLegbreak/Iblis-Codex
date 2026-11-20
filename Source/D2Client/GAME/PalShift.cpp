#include "D2DataTbls.h"
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2DataTablesStrc;
struct D2ShiftRowsStrc;
struct D2PalShiftStrc;
struct D2PalShiftNodeStrc;
struct T0044A980;

struct D2MonStatsTxt
{
    char unk0x00[0x18];
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

struct D2PalShiftStrc
{
    int unk0x000;
    D2ShiftRowsStrc tBase;
    D2ShiftRowsStrc tBlood;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned char* gpBloodRemap_007BB384; // 0x007BB384
void __fastcall sub_00477060_EmitSink(D2PalShiftStrc* pShift);
static __declspec(noinline) void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftStrc* pShift);

struct D2PalShiftNodeStrc
{
    int nId;
    char unk0x04[0x1000];
    D2PalShiftNodeStrc* pNext;
};

struct T0044A980
{
    int nId;
    int nValue;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_00477170_LoadPalShift(int nMonsterId); // 0x00477170
extern D2PalShiftNodeStrc* gpPalShiftList_007B957C; // 0x007B957C

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

// 0x00477060
static void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftStrc* pShift)
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

// build: context sub_00477060_Shim
// calling-convention shim (not game code)
void __fastcall sub_00477060_Shim(D2PalShiftStrc* pShift, int nMonsterId)
{
    sub_00477060_BuildBloodShift(nMonsterId, pShift);
    sub_00477060_EmitSink(pShift);
}

T0044A980* gpPalShiftEntries_007B9578; // 0x007B9578

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
    T0044A980* pEntries = gpPalShiftEntries_007B9578;
    const int nSize = nCount * sizeof(T0044A980);
    if (!pEntries)
    {
        pEntries = (T0044A980*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x11F, 0);
        gpPalShiftEntries_007B9578 = pEntries;
    }
    memset(pEntries, 0, nSize);
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }

    sub_00477170_LoadPalShift(0x16B);
    sub_00477170_LoadPalShift(0x16C);
    sub_00477170_LoadPalShift(0x1A4);
    sub_00477170_LoadPalShift(0x1A5);
}
