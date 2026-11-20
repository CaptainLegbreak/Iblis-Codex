#include "D2Client.h"
#include "D2Txt.h"


int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bUnused); // 0x00644F20
void __fastcall sub_004EA4A0(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, int a5, int a6, int nParam, int a8, int a9); // 0x004EA4A0
int __fastcall sub_00502EF0(int nFont); // 0x00502EF0
void __fastcall D2Win_10131_GetTextDimensions(const wchar_t* wszText, int* pWidth, int* pHeight); // 0x00502520
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);
void __fastcall sub_00526320_ToUnicode(wchar_t* wszOut, const char* szIn, int nMax); // 0x00526320
extern const char gszFmtOne_006D57BC[]; // 0x006D57BC
extern const char gszFmtRange_006D9D70[]; // 0x006D9D70
extern int gnScreenX_007A2858; // 0x007A2858
extern int gnScreenY_007A285C; // 0x007A285C
extern int gnPanelY_00711470; // 0x00711470
void __fastcall sub_004A7080(int nX, int nY, int nRight, const wchar_t* wszText, int nColor); // 0x004A7080

// build: context sub_004E72D0_AddElemDamage
static void __stdcall sub_004E72D0_AddElemDamage(D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nLevel, int* pMin, int* pMax, int* pType)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nLevel, 1);
        *pType = 2;
        nMin = (nLength * SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1)) >> 8;
        nMax = (SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) * nLength) >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) >> 8;
    }

    if (pType)
    {
        switch (pSkillsTxt->nEType)
        {
        case 1:
            *pType = 1;
            break;
        case 2:
            *pType = 9;
            break;
        case 3:
        case 4:
            *pType = 3;
            break;
        case 5:
            *pType = 2;
            break;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

// build: context sub_004E96E0_DrawDamageRange
static void __fastcall sub_004E96E0_DrawDamageRange(int nMin, int nMax, int nColor, int nY, int nLeft, int nRight)
{
    union
    {
        wchar_t wsz[32];
        int n[16];
    } tText;
    char szText[32];
    for (int i = 0; i < 16; ++i)
    {
        tText.n[i] = 0;
    }
    if (nMin >= nMax)
    {
        nMax = nMin + 1;
    }

    if (nMin == nMax)
    {
        wsprintfA(szText, gszFmtOne_006D57BC, nMin);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", gszEmpty_006CC837, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else if (nMax >= 10000)
    {
        wsprintfA(szText, "%s%d-%dK", gszEmpty_006CC837, nMin, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRange_006D9D70, nMin, nMax);
    }

    sub_00526320_ToUnicode(tText.wsz, szText, 32);
    int nWidth = 0;
    int nHeight = 0;
    D2Win_10131_GetTextDimensions(tText.wsz, &nWidth, &nHeight);
    nWidth = nWidth * 11 / 7;
    if (nWidth > nRight - nLeft)
    {
        sub_00502EF0(6);
        --nY;
    }
    else
    {
        sub_00502EF0(1);
    }

    sub_004A7080(gnScreenX_007A2858 + nLeft, gnScreenY_007A285C + gnPanelY_00711470 + nY - 480, gnScreenX_007A2858 + nRight, tText.wsz, nColor);
}

// 0x004EA990
void __fastcall sub_004EA990_DrawSkillDamage(D2UnitStrc* pUnit, int nParam, D2SkillsTxt* pSkillsTxt, int nLevel, int nLeft, int nY, int nRight)
{
    if (!nParam || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nDamage[2];
    int nType = 0;
    sub_004EA4A0(pUnit, &nDamage[0], &nDamage[1], &nType, 0, 0, nParam, 0, 0);
    nDamage[0] = nDamage[0] * nSrcDam / 128;
    nDamage[1] = nDamage[1] * nSrcDam / 128;
    sub_004E72D0_AddElemDamage(pSkillsTxt, pUnit, nLevel, &nDamage[0], &nDamage[1], &nType);
    sub_004E96E0_DrawDamageRange(nDamage[0], nDamage[1], nType, nY, nLeft, nRight);
}
