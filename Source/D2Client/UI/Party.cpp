#include "D2Client.h"

struct Unicode;
struct D2RosterUnitStrc;
struct D2SevenIntStrc;
struct D2RosterSlotStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern void* gpCelFile_007BF01C; // 0x007BF01C

struct D2RosterSlotStrc
{
    int bFlag;
    int nX;
    int nY;
    void* pCellFile;
    int nFrame;
    int nType;
    int nState;
    int bActive;
};

#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    D2RosterSlotStrc f_0[5];
    char szName[0x19];
    int nClass;
    int nLevel;
    int nLevelId;
    int nId;
    int nY;
    D2RosterUnitStrc* pNext;
};

#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SevenIntStrc
{
    int n0;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
};

void __cdecl sub_K04_EmitUse(D2SevenIntStrc* pRecord);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry); // 0x00479B90
int __fastcall sub_00479BA0(D2StoredUnitRecordStrc* pEntry); // 0x00479BA0
int __fastcall sub_00479C20(D2StoredUnitRecordStrc* pEntry); // 0x00479C20
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry); // 0x00479C60
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry); // 0x00479CA0
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry); // 0x00479CE0
int __fastcall sub_00479D20(D2StoredUnitRecordStrc* pEntry); // 0x00479D20
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0
int __fastcall sub_0047A1E0(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0
void __cdecl sub_0049A020_FreeRosterUnits(); // 0x0049A020
extern D2RosterUnitStrc* gpRosterUnits_007BF014; // 0x007BF014

// 0x00499FC0
static __declspec(noinline) void __stdcall sub_00499FC0_DrawPanelCel(void* pCellFile, int nX, int nFrame, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = nFrame;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + nX, nY - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0049A510
void __cdecl sub_0049A510_DrawPartyButtons()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    sub_00502EF0(0);
    if (sub_00479BC0_GetEntryIndex(pEntry) != 0xFFFF)
    {
        sub_00499FC0_DrawPanelCel(gpCelFile_007BF01C, 0xE3, 0, 0x23);
        sub_004A7080(gnGlobal_007A2858 + 0xE3, 0x21 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x118, D2LANG_GetStringFromTblIndex(0x1038), 2);
    }
    sub_00502EF0(1);
}

D2RosterUnitStrc* gpRosterUnits_007BF014; // 0x007BF014

// 0x0049A020
void __cdecl sub_0049A020_FreeRosterUnits()
{
    D2RosterUnitStrc* pUnit = gpRosterUnits_007BF014;
    while (pUnit)
    {
        D2RosterUnitStrc* pNext = pUnit->pNext;
        FOG_Free(pUnit, ".\\UI\\Party.cpp", 0x108, 0);
        pUnit = pNext;
    }
    gpRosterUnits_007BF014 = 0;
}

// 0x0049A060
static void __stdcall sub_0049A060_FillRecord(D2SevenIntStrc* pRecord, int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    pRecord->n0 = n0;
    pRecord->n1 = n1;
    pRecord->n2 = n2;
    pRecord->n3 = n3;
    pRecord->n4 = n4;
    pRecord->n5 = n5;
    pRecord->n6 = n6;
}

void __cdecl sub_K04_EmitFillRecord(int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    D2SevenIntStrc tRecord;
    sub_0049A060_FillRecord(&tRecord, n0, n1, n2, n3, n4, n5, n6);
    sub_K04_EmitUse(&tRecord);
}

void* gpCelFile_007BF020; // 0x007BF020

static void sub_L04_InitSlot(D2RosterSlotStrc* pSlot, int bFlag, int nX, int nY, void* pCellFile, int nFrame, int nType, int nState)
{
    pSlot->bFlag = bFlag;
    pSlot->nX = nX;
    pSlot->nY = nY;
    pSlot->pCellFile = pCellFile;
    pSlot->nFrame = nFrame;
    pSlot->nType = nType;
    pSlot->nState = nState;
}

// 0x0049A090
static void sub_0049A090_InitRosterUnit(D2StoredUnitRecordStrc* pEntry, D2RosterUnitStrc* pUnit, int nY)
{
    pUnit->nY = nY + 0xD;
    sub_L04_InitSlot(&pUnit->f_0[0], 1, 0xBE, nY, gpCelFile_007BF01C, 0, 0, sub_00479D20(pEntry));
    sub_L04_InitSlot(&pUnit->f_0[1], 0, 0xE, nY + 7, gpCelFile_007BF020, sub_00479CE0(pEntry) ? 6 : 4, 1, 0);
    sub_L04_InitSlot(&pUnit->f_0[2], 0, 0xF5, nY, gpCelFile_007BF020, sub_00479C20(pEntry) ? 0xE : 0xC, 2, 0);
    sub_L04_InitSlot(&pUnit->f_0[3], 0, 0x10A, nY, gpCelFile_007BF020, sub_00479C60(pEntry) ? 2 : 0, 3, 0);
    sub_L04_InitSlot(&pUnit->f_0[4], 0, 0x11F, nY, gpCelFile_007BF020, sub_00479CA0(pEntry) ? 0xA : 8, 4, 0);
    pUnit->nId = sub_0047A0C0_GetRecordUnitId(pEntry);
}

// 0x0049A1D0
static void sub_0049A1D0_AddRosterUnit(int nY, D2StoredUnitRecordStrc* pEntry)
{
    D2RosterUnitStrc* pLast = gpRosterUnits_007BF014;
    D2RosterUnitStrc* pUnit = (D2RosterUnitStrc*)FOG_Alloc(sizeof(D2RosterUnitStrc), ".\\UI\\Party.cpp", 0x14D, 0);
    memset(pUnit, 0, sizeof(D2RosterUnitStrc));
    sub_0049A090_InitRosterUnit(pEntry, pUnit, nY);
    strcpy(pUnit->szName, sub_004795C0_GetEntryName(pEntry));
    pUnit->nClass = sub_00479BA0(pEntry);
    pUnit->nLevel = sub_00479B90(pEntry);
    pUnit->nLevelId = sub_0047A1E0(pEntry);
    if (pLast)
    {
        while (pLast->pNext)
            pLast = pLast->pNext;
        pLast->pNext = pUnit;
    }
    else
    {
        gpRosterUnits_007BF014 = pUnit;
    }
}

// 0x0049A640
void __cdecl sub_0049A640()
{
    sub_0049A020_FreeRosterUnits();
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(sub_004795A0_GetNextEntry(0));
    for (int i = 0; pEntry || i > 8; ++i)
    {
        sub_0049A1D0_AddRosterUnit(nY, pEntry);
        nY += 0x26;
        pEntry = sub_004795A0_GetNextEntry(pEntry);
    }
}

// 0x0049A2A0
int __cdecl sub_0049A2A0_IsFirstEntryAtLeastNine()
{
    return sub_00479B90(sub_004795A0_GetNextEntry(0)) >= 9;
}
