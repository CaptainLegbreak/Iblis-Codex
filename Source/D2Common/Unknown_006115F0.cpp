#include "D2Common.h"
#include "D2ProfileCounter.h"

struct D2GameStrc;
struct D2ProfileCounterStrc;


typedef int (__cdecl* PROFHOOK0096BC24FN)();

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800
void __cdecl PROFCORE_WriteProfileCounters(); // 0x006116B0
void __cdecl LOGGING_CloseLog(); // 0x00624B20
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC
extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C
extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

// 0x006115F0
void __cdecl sub_006115F0_Empty()
{
}

PROFHOOK0096BC24FN gpfnProfSecondaryHook; // 0x0096BC24

#include "gen/data/Source/D2Common/Unknown_006115F0.inc"

// 0x00611760
static void sub_00611760_MakeCalcCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// 0x006119F0
int __fastcall DATATBLS_SkillsCalcParamCallback(char* szText, int* pResult, int nType, int nKeywordNumber)
{
    char szCode[4];
    if (nType == 1)
    {
        switch (nKeywordNumber)
        {
        case 3:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 4:
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 5:
        {
            if (gpItemStatCostLinker)
            {
                const int nRow = FOG_GetRowFromTxt(gpItemStatCostLinker, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            if (!SStrCmpI(szText, "base", 32))
            {
                *pResult = 0;
                return 1;
            }
            if (!SStrCmpI(szText, "mod", 32))
            {
                *pResult = 0;
                return 2;
            }
            SStrCmpI(szText, "accr", 32);
            *pResult = 0;
            return 0;
        }
        case 6:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        }
    }
    sub_00611760_MakeCalcCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
    *pResult = 0;
    return nIndex;
}
