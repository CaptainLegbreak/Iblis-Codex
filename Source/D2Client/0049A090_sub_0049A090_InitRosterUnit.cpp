struct D2StoredUnitRecordStrc;

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);                           // 0x004795C0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
int __fastcall sub_00479BA0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479BA0
int __fastcall sub_00479C20(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C20
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C60
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CA0
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CE0
int __fastcall sub_00479D20(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479D20
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                               // 0x0047A0C0
int __fastcall sub_0047A1E0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A1E0
void __cdecl sub_0049A020_FreeRosterUnits();                                                                // 0x0049A020
extern D2RosterUnitStrc* gpRosterUnits_007BF014;                                                            // 0x007BF014
extern void* gpCelFile_007BF01C;                                                                            // 0x007BF01C
void* gpCelFile_007BF020;                                                                                   // 0x007BF020

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
