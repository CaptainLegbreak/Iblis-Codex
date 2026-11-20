#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct Unicode { unsigned short wChar; Unicode(unsigned short ch = 0) : wChar(ch) {} };
struct UnicodeChar : Unicode { UnicodeChar(); // 0x0042F530
};
struct D2SkillDescTxt { char unknown00[0x0E]; unsigned short wStrAlt; char unknown10[2]; unsigned short wDamageFunc, wDescFunc; char unknown16[0x120-0x16]; };
struct D2SkillTextPositionStrc { int nLeft, nY, nRight; };
typedef void (__fastcall* SKILLDAMAGEFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int, int, int);
typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern SKILLDAMAGEFN gpfSkillDamageFuncs_0072D768[]; // 0x0072D768
extern SKILLDESCFN gpfSkillDescFuncs_0072D7F8[]; // 0x0072D7F8
extern D2SkillTextPositionStrc gtSkillTextPositions_0072D840[]; // 0x0072D840
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
extern const char gszSkillDescFile_006DBF24[]; // 0x006DBF24
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...); // 0x006CC468
void __fastcall sub_00452180_StrToUpper(Unicode*); // 0x00452180
void __fastcall sub_004A7080(int, int, int, const Unicode*, int); // 0x004A7080
int __fastcall sub_004A7660_SplitAtNewline(Unicode*, Unicode**); // 0x004A7660
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int); // 0x004A89D0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc*, D2SkillStrc*); // 0x004D9FC0
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode*, const Unicode*, int, int, int, int, int); // 0x004E9870
int __fastcall sub_00502EF0(int); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode*, const char*, int); // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode*, const Unicode*); // 0x005267E0
void __cdecl sub_005269D0(int, Unicode*, const Unicode*, ...); // 0x005269D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*, const char*, int); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc*); // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

// 0x004E6E30
static __declspec(noinline) unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }
    if (!pSkillDescTxtRecord) return 0x1506;
    return pSkillDescTxtRecord->wStrAlt;
}

static __declspec(noinline) void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue); // 0x004E9940

// build: context sub_004E9940_DrawNumberCentered
static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, gszFormatD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000) sub_00502EF0(1);
    else sub_00502EF0(0);
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + nY - 480, gnGlobal_007A2858 + nRight, wszText, nColor);
}

#define TP gtSkillTextPositions_0072D840
#define DRAW_SKILL_TEXT(i, text) sub_004A7080(TP[i].nLeft + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C + TP[i].nY - 480, TP[i].nRight + gnGlobal_007A2858, text, 0)

// 0x004ED570
void __fastcall sub_004ED570_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot)
{
    int nValue1, nValue2, nColor1, nColor2;
    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt) return;
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile_006DBF24, 0x1588);
    D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pDesc) return;
    sub_00502EF0(6);
    Unicode wszName[32];
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(sub_004E6E30_GetSkillDescAltStr(nSkillId)));
    sub_00452180_StrToUpper(wszName);
    int nIndex = nSlot;
    DRAW_SKILL_TEXT(nIndex, wszName);
    int bDamage = 0;
    int bDescription = 0;
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 0: case 1: case 6: case 8:
        bDamage = 1;
        bDescription = 1;
        break;
    }
    if (pDesc->wDamageFunc >= 144 || !gpfSkillDamageFuncs_0072D768[pDesc->wDamageFunc]) bDamage = 0;
    if (pDesc->wDescFunc >= 72 || !gpfSkillDescFuncs_0072D7F8[pDesc->wDescFunc]) bDescription = 0;
    ++nIndex;
    if (bDamage)
        DRAW_SKILL_TEXT(nIndex, D2LANG_GetStringFromTblIndex(0xFDD));
    ++nIndex;
    if (bDamage)
        gpfSkillDamageFuncs_0072D768[pDesc->wDamageFunc](pUnit, pSkill, pSkillsTxt, nLevel, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight);
    if (!bDescription)
        return;
    UnicodeChar wszDescription[200];
    nValue1 = 0;
    nValue2 = 0;
    nColor1 = 0;
    nColor2 = 0;
    gpfSkillDescFuncs_0072D7F8[pDesc->wDescFunc](pUnit, pSkill, pSkillsTxt, nLevel, &nValue1, &nColor1, &nValue2, &nColor2);
    ++nIndex;
    if (nValue1 || nValue2)
    {
        sub_00502EF0(6);
        if (nSkillId)
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFDF), wszName);
        else
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFE1), wszName);
        wszDescription[199].wChar = 0;
        Unicode* pNext;
        if (sub_004A7660_SplitAtNewline(wszDescription, &pNext))
        {
            sub_004A7080(TP[nIndex].nLeft + gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 + TP[nIndex].nY - 484, TP[nIndex].nRight + gnGlobal_007A2858, wszDescription, 0);
            sub_004A7080(TP[nIndex].nLeft + gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 + TP[nIndex].nY - 476, TP[nIndex].nRight + gnGlobal_007A2858, pNext, 0);
        }
        else
            DRAW_SKILL_TEXT(nIndex, wszName);
    }
    nIndex += 2;
    if (nValue2)
    {
        UnicodeChar wszValue1[32];
        UnicodeChar wszValue2[32];
        char szValue[32];
        wsprintfA(szValue, gszFormatD_006D57BC, nValue1);
        sub_00526320_ToUnicode(wszValue1, szValue, 32);
        wsprintfA(szValue, gszFormatD_006D57BC, nValue2);
        sub_00526320_ToUnicode(wszValue2, szValue, 32);
        sub_004E9870_DrawTwoTexts(wszValue1, wszValue2, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nColor1, nColor2);
    }
    else if (nValue1)
        sub_004E9940_DrawNumberCentered(nColor1, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nValue1);
}

#include "gen/data/Source/D2Client/UI/SkillDesc_004ED570.inc"
