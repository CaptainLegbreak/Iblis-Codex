#include "D2Client.h"

#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    char unk0x00[0x18];
    int nState;
    char unk0x1C[0x84];
    char szName[0x19];
    int nClass;
    int nLevel;
    int nLevelId;
    char unk0xC5[8];
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId);                                          // 0x00453E70
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
int __fastcall sub_0047A5B0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5B0
void __stdcall sub_0049A690_DrawRosterButtons(D2RosterUnitStrc* pRow);                                      // 0x0049A690
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);          // 0x006CC468
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2RosterUnitStrc* gpRosterUnits_007BF014;                                                            // 0x007BF014

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
