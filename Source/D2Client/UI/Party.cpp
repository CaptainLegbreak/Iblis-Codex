#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
struct D2StoredUnitRecordStrc;

struct Unicode;
struct D2RosterUnitStrc;
struct D2SevenIntStrc;
struct D2RosterSlotStrc;
struct D2CelContextStrc;


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
    union
    {
        struct
        {
            D2RosterSlotStrc f_0[5];
        };
        struct
        {
            unsigned char unk_00[0x18];
            int nState;
        };
    };
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
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
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
const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId); // 0x00453E70
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_0047A5B0(D2StoredUnitRecordStrc* pEntry); // 0x0047A5B0
void __stdcall sub_0049A690_DrawRosterButtons(D2RosterUnitStrc* pRow); // 0x0049A690
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

extern "C" size_t __cdecl strlen(const char* szString);
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0

// 0x00499FC0
static void __stdcall sub_00499FC0_DrawPanelCel(void* pCellFile, int nX, int nFrame, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = nFrame;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + nX, nY - gnGlobal_007A285C, -1, 5, 0);
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

// 0x0049A2A0
int __cdecl sub_0049A2A0_IsFirstEntryAtLeastNine()
{
    return sub_00479B90(sub_004795A0_GetNextEntry(0)) >= 9;
}

// 0x0049A2C0
static void __stdcall sub_0049A2C0_DrawRosterName(int nY, int nColor, int bShort, const char* szName)
{
    Unicode wszName[100];
    sub_00526320_ToUnicode(wszName, szName, 100);
    Unicode* pEnd = &wszName[99];
    char szDots[5] = "...";
    Unicode wszDots[5];
    const int nWidth = sub_00501820(wszName);
    if (bShort)
    {
        if (nWidth > 0x5F)
        {
            while (sub_00501820(wszName) > 0x5F)
            {
                --pEnd;
                *pEnd = 0;
            }
            sub_00526320_ToUnicode(wszDots, szDots, 5);
            sub_00526700(wszName, wszDots);
        }
    }
    else if (nWidth > 0x87)
    {
        while (sub_00501820(wszName) > 0x87)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        sub_00526700(wszName, wszDots);
    }
    sub_00502320(wszName, gnGlobal_007A2858 + 0x24, nY - gnGlobal_007A285C - 2, nColor, 0);
}

// 0x0049A3D0
static void __stdcall sub_0049A3D0_DrawRosterClass(int nColor, int nY, int nClass)
{
    int nStringId;
    switch (nClass)
    {
    case 0:
        nStringId = 0x103A;
        break;
    case 1:
        nStringId = 0x103B;
        break;
    case 2:
        nStringId = 0x103D;
        break;
    case 3:
        nStringId = 0x103E;
        break;
    case 4:
        nStringId = 0x103C;
        break;
    case 5:
        nStringId = 0x2771;
        break;
    case 6:
        nStringId = 0x2772;
        break;
    default:
        return;
    }
    sub_00502320(D2LANG_GetStringFromTblIndex(nStringId), gnGlobal_007A2858 + 0x24, nY - gnGlobal_007A285C, nColor, 0);
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


// 0x0049A580
void __cdecl sub_0049A580_DrawPlayerName()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    const char* szName = sub_0047A210(pPlayer);
    if (!szName)
        return;
    unsigned int nLen = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
    if (nLen > 11)
    {
        if (nLen >= 14)
            sub_00502EF0(6);
        else
            sub_00502EF0(0);
    }
    Unicode* wszName = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLen, ".\\UI\\Party.cpp", 0x211, 0);
    sub_00526320_ToUnicode(wszName, szName, nLen);
    sub_004A7080(gnGlobal_007A2858 + 0x14, 0x1F - gnGlobal_007A285C, gnGlobal_007A2858 + 0xBE, wszName, 0);
    sub_00502EF0(0);
    FOG_Free(wszName, ".\\UI\\Party.cpp", 0x21A, 0);
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

static void __stdcall sub_0049A460_DrawPanelLabel(int nY, int bAlt, unsigned short nFlag, int nType)
{
    int nStringId;
    int nColor = 0;
    int nX = 0xBE;
    switch (nType)
    {
    case 1:
        if (nFlag == 0xFFFF)
        {
            return;
        }

        if (bAlt)
        {
            nStringId = 0x1034;
            nColor = 2;
            nX = 0x9B;
        }
        else
        {
            nStringId = 0x1035;
            nColor = 8;
            nX = 0xAF;
        }
        break;
    case 0:
        nStringId = 0x1036;
        break;
    case 2:
        nStringId = 0x1037;
        break;
    case 3:
        nStringId = 0x1038;
        break;
    case 4:
        nStringId = 0x13EF;
        break;
    default:
        sub_00502EF0(0);
        return;
    }

    int nLeft = gnGlobal_007A2858 + nX;
    sub_004A7080(nLeft, nY - gnGlobal_007A285C - 2, nLeft + 0x35, D2LANG_GetStringFromTblIndex(nStringId), nColor);
}

// 0x0049A830
static void __stdcall sub_0049A830_DrawRosterArea(int nY, D2RosterUnitStrc* pEntry, int nColor)
{
    Unicode wszName[0xFF];
    sub_005267E0(wszName, sub_00453E70_GetLevelName(pEntry->nLevelId));
    Unicode* pEnd = &wszName[0xFE];
    if (sub_00501820(wszName) > 0x8C)
    {
        const int nLength = sub_00526800(wszName);
        const Unicode wLast = wszName[nLength - 1];
        char szDots[] = "....";
        Unicode wszDots[5];
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        wszDots[3] = wLast;
        const int nMax = 0x8B - sub_00501820(wszDots);
        while (sub_00501820(wszName) > nMax)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526700(wszName, wszDots);
    }
    sub_00502320(wszName, gnGlobal_007A2858 + 0x7E, nY - gnGlobal_007A285C + 0xC, nColor, 0);
}

// 0x0049C170
static void __stdcall sub_0049C170_DrawRosterLevel(int nY, int nLevel, int nColor)
{
    Unicode wszText[100];
    Unicode wszNumber[10];
    char szNumber[100];
    Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(0xD28), 0x14);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    wsprintfA(szNumber, gszFormat2u_006DA0CC, nLevel);
    sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    sub_00502320(wszText, gnGlobal_007A2858 + 0x10A, nY - gnGlobal_007A285C, nColor, 0);
}

// 0x0049C270
void __cdecl sub_0049C270_DrawPartyRows()
{
    D2RosterUnitStrc* pRow = gpRosterUnits_007BF014;
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    const unsigned short nSelfIndex = sub_00479BC0_GetEntryIndex(pEntry);
    pEntry = sub_004795A0_GetNextEntry(pEntry);
    int nCount = 0;
    while (pRow && pEntry && nCount < 8)
    {
        int nColor = 0;
        int bSelf = 0;
        const unsigned short nIndex = sub_00479BC0_GetEntryIndex(pEntry);
        if (sub_00479BC0_GetEntryIndex(pEntry) != 0xFFFF)
        {
            if (nSelfIndex == nIndex)
            {
                nColor = 2;
                bSelf = 1;
            }
            else
            {
                nColor = 8;
            }
        }
        if (sub_0047A5B0(pEntry))
        {
            nColor = 1;
        }
        sub_00502EF0(0);
        if (nIndex == 0xFFFF)
        {
            sub_0049A2C0_DrawRosterName(nY, nColor, 0, pRow->szName);
        }
        else
        {
            sub_0049A2C0_DrawRosterName(nY, nColor, 1, pRow->szName);
        }
        sub_0049A3D0_DrawRosterClass(nColor, nY + 0xC, pRow->nClass);
        sub_0049C170_DrawRosterLevel(nY + 0xC, pRow->nLevel, nColor);
        if (bSelf && pRow->nLevelId)
        {
            sub_0049A830_DrawRosterArea(nY, pRow, nColor);
        }
        sub_0049A690_DrawRosterButtons(pRow);
        if (nSelfIndex == nIndex)
        {
            sub_0049A460_DrawPanelLabel(nY, 1, nIndex, pRow->nState);
        }
        else
        {
            sub_0049A460_DrawPanelLabel(nY, 0, nIndex, pRow->nState);
        }
        pRow = pRow->pNext;
        ++nCount;
        nY += 0x26;
        pEntry = sub_004795A0_GetNextEntry(pEntry);
        sub_00502EF0(1);
    }
}
