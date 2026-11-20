#include "D2Txt.h"
struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc;


extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644E40
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId);                                   // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

static __declspec(noinline) int __stdcall sub_004EC540_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax);
static int __stdcall sub_004EC540_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax); // 0x004EC540

static int __stdcall sub_004EC540_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
    }
    else
    {
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10E2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10BE));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static __declspec(noinline) int __stdcall sub_004EC6F0_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel);

// 0x004EC6F0
static int __stdcall sub_004EC6F0_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return sub_004EC540_AddElemRatePerSecond(0x10A1, wszText, nMin, nMax);
}

int __fastcall sub_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, int nLine)
{
    if (nLine == 2)
    {
        sub_004EC6F0_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        return 1;
    }
    return 0;
}
