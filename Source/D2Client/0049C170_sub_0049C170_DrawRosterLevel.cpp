#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    char unk0x00[0xBD];
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
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);          // 0x006CC468
extern "C" const char gszFormat2u_006DA0CC[];                                                               // 0x006DA0CC
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C

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

void __cdecl sub_Z12_EmitRosterRows(D2RosterUnitStrc* pEntry, int nColor)
{
    int nY = 0x3A;
    for (; pEntry; pEntry = pEntry->pNext)
    {
        sub_0049C170_DrawRosterLevel(nY + 0xE, pEntry->nLevel, nColor);
        sub_0049A830_DrawRosterArea(nY, pEntry, nColor);
        nY += 0x22;
    }
}
