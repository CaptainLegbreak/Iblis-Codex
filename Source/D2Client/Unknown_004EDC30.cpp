#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2Txt.h"

struct Unicode;
struct D2SkillsTxt;
struct D2SkillDescTxt;
union D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

extern "C" const char szFmtRange_006D9D70[]; // 0x006D9D70

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_004EDEA0_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nArg3, int nArg4, int nLine, int nArg5); // 0x004EDEA0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*,int,int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*,D2SkillStrc*,int); // 0x006442A0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int); // 0x004AA8B0
void __fastcall sub_004521C0_SetTextColor(Unicode*,int); // 0x004521C0
int __stdcall sub_004ED480_HasClassSkill(D2UnitStrc*); // 0x004ED480
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode*, int); // 0x004521C0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern const int gnVelocityBonus_006DBF38[5]; // 0x006DBF38
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg); // 0x00465BF0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

static int __stdcall sub_004E73E0_FormatValue(Unicode* pDest, int bPlus, int nValue)
{
    char szText[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szText, "+%d", nValue);
    }
    else
    {
        wsprintfA(szText, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E7430_FormatDecimal(Unicode* pDest, int bPlus, int nWhole, int nFraction)
{
    char szText[32];
    if (bPlus && nWhole >= 0)
    {
        wsprintfA(szText, "+%d.%d", nWhole, nFraction);
    }
    else
    {
        wsprintfA(szText, "%d.%d", nWhole, nFraction);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004EDB30_AddSeconds(unsigned short nString, int bPlus, int nFrames, Unicode* wszText)
{
    Unicode wszNumber[32];
    const int nSeconds = nFrames / 25;
    const int nTenths = nFrames % 25 * 10 / 25;
    if (!nSeconds && !nTenths)
    {
        return 0;
    }

    if (nTenths)
    {
        sub_004E7430_FormatDecimal(wszNumber, bPlus, nSeconds, nTenths);
    }
    else
    {
        sub_004E73E0_FormatValue(wszNumber, bPlus, nSeconds);
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nSeconds == 1 && !nTenths ? 0x10AB : 0x10AC));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EDC30
static int sub_004EDC30_AddSecondsPlus(unsigned short nString, int nFrames, Unicode* wszText)
{
    return sub_004EDB30_AddSeconds(nString, 1, nFrames, wszText);
}

int __fastcall sub_M214_Emit_004EDEA0(Unicode* wszText, unsigned short nString, int nFrames)
{
    return sub_004EDC30_AddSecondsPlus(nString, nFrames, wszText);
}

static unsigned short sub_004E6F60_GetElemDamageText(int nElemType)
{
    switch (nElemType)
    {
    case 1:
        return 0x10A1;
    case 2:
        return 0x10A3;
    case 4:
        return 0x10A2;
    case 3:
        return 0x10C3;
    case 5:
        return 0x10A4;
    case 6:
        return 0xDC4;
    }
    return 0;
}

static int __stdcall sub_004EC140_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nString)
    {
        nString = sub_004E6F60_GetElemDamageText(nElemType);
        if (!nString)
        {
            return 0;
        }
    }

    if ((nMin || nMax) && nMin != nMax)
    {
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EDC40
static int __stdcall sub_004EDC40_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId, D2UnitStrc* pUnit)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    if (nLength)
    {
        unsigned short nString;
        switch (pSkillsTxt->nEType)
        {
        case 5:
            nString = 0x10AA;
            break;
        case 4:
            nString = 0x10A9;
            break;
        default:
            return 0;
        }

        return sub_004EDB30_AddSeconds(nString, 0, nLength, wszText);
    }

    return 0;
}

static int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    sub_004EDB30_AddSeconds(0x2B0E, 0, nLength, wszText);
    sub_004EC140_AddElemRange(nMin, 0, nMax, wszText, pSkillsTxt->nEType);
    return 1;
}

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nLine, int nCalcA, int nCalcB, unsigned short nStringA)
{
    switch (nLine)
    {
    case 1:
        sub_004EDC40_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        return 1;
    case 2:
        sub_004EDCA0_AddElemDamageOverTime(pUnit, wszText, pSkillsTxt, nSkillLevel, nSkillId);
        return 1;
    case 3:
        sub_004EDB30_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 4:
        sub_004EC140_AddElemRange(nCalcA, nStringA, nCalcB, wszText, pSkillsTxt->nEType);
        return 1;
    }
    return 0;
}

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

// 0x004EEF00
void __fastcall sub_004EEF00_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int nHeight;
    int nWidth;
    char szNumber[32];
    if(!pUnit)return;
    D2SkillsTxt* pSkillsTxt=CLIENT_GetSkillsTxtRecord(nSkillId);
    if(!pSkillsTxt)return;
    D2SkillStrc* pBonusSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bGranted;
    if(pBonusSkill){
        if(SKILLS_GetSkillLevel(pUnit,pBonusSkill,1) && !SKILLS_GetSkillLevel(pUnit,pBonusSkill,0))bGranted=1;
        else bGranted=0;
    } else bGranted=0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText,D2LANG_GetStringFromTblIndex(0x109C));
    D2SkillStrc* pSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bMaxed;
    if(pSkill && SKILLS_GetSkillLevel(pUnit,pSkill,0)>=sub_004AA8B0_GetSkillMaxLevel(nSkillId))bMaxed=1;
    else bMaxed=0;
    int bFound=0;
    for(int i=16;i>=10;--i)
        if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bFound=1;
    if(bFound)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    if(!bMaxed)
    {
        int bNext=0;
        for(int i=0;i<6;++i)
            if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bNext=1;
        if(bNext)
        {
            int nPrefixId=0x109D;
            if(!nSkillLevel)nPrefixId=0x10AD;
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(nPrefixId));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    if(nSkillLevel>0)
    {
        int bCurrent=0;
        for(int i=0;i<6;++i)
            if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel,nArg,i,0))bCurrent=1;
        if(bCurrent)
        {
            wsprintfA(szNumber,gszFormatD_006D57BC,nSkillLevel);
            sub_00526320_ToUnicode(wszNumber,szNumber,32);
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x109E));
            sub_00526700(wszText,wszNumber);
            if(bGranted)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1112));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    int bSynergy=0;
    for(int i=6;i<10;++i)
        if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bSynergy=1;
    if(bSynergy)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    D2SkillDescTxt* pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrLong));
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    Unicode wszName[1024];
    pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_005267E0(wszName,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrName));
    sub_004521C0_SetTextColor(wszName,2);
    sub_00526700(wszText,wszName);
    if(bGranted)
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1113));
    }
    if(!sub_004ED480_HasClassSkill(pUnit))
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText,&nWidth,&nHeight);
    D2Win_10129_DrawFramedText(wszText,nX-24,nHeight+nY+3,0,0);
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline D2SkillDescTxt* GetSkillDescription(int nSkillId) {
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (pRecord) {
        int nDesc = pRecord->wSkillDesc;
        if (nDesc >= 0 && nDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return &sgptDataTables->pSkillDescTxt[nDesc];
    }
    return 0;
}

static inline int GetMaximumSkillLevel(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) {
        int nLevel = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nLevel > 0) return nLevel;
    }
    return 20;
}

// 0x004EF410
void __fastcall sub_004EF410_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];
    if (!pUnit) return;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    D2SkillStrc* pBonusSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int bBonusOnly;
    if (pBonusSkill) {
        if (SKILLS_GetSkillLevel(pUnit, pBonusSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pBonusSkill, 0))
            bBonusOnly = 1;
        else bBonusOnly = 0;
    } else bBonusOnly = 0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109c));
    bFound = 0;
    for (int i = 16; i >= 10; --i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel + 1, nArg, i, 1))
            bFound = 1;
    }
    if (bFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    int bCurrentFound = 0;
    for (int i = 0; i < 6; ++i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bCurrentFound = 1;
    }
    if (bCurrentFound) {
        if (nSkillLevel <= 0) {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10ad));
        } else {
            wsprintfA(szNumber, gszFormatD_006D57BC, nSkillLevel);
            sub_00526320_ToUnicode(wszNumber, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109e));
            sub_00526700(wszText, wszNumber);
        }
        if (bBonusOnly) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1112));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    }
    int bRemainingFound = 0;
    for (int i = 6; i < 10; ++i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bRemainingFound = 1;
    }
    if (bRemainingFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= GetMaximumSkillLevel(nSkillId)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1111));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    } else {
        int nRequired = pSkillsTxt->wReqLevel + nSkillLevel;
        Unicode wszRequired[32];
        if (nRequired) {
            wsprintfA(szNumber, gszFormatD_006D57BC, nRequired);
            sub_00526320_ToUnicode(wszRequired, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105b));
            sub_00526700(wszText, wszRequired);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        }
    }
    D2SkillDescTxt* pDescription = GetSkillDescription(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrLong));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    Unicode wszName[256];
    pDescription = GetSkillDescription(nSkillId);
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrName));
    sub_004521C0_PrefixLevelText(wszName, 2);
    sub_00526700(wszText, wszName);
    if (bBonusOnly) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1113));
    }
    if (!sub_004ED480_HasClassSkill(pUnit)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    D2Win_10129_DrawFramedText(wszText, nX, nHeight + nY + 3, 1, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004EFDF0
int __fastcall sub_004EFDF0_LobMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc tMissileParams;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMissile = pSkillsTxtRecord->wCltMissileA;
        D2MissilesTxt* pMissilesTxtRecord;
        int nMissilesCount;
        if (nMissile >= 0 && nMissile < (nMissilesCount = sgptDataTables->nMissilesTxtRecordCount)
            && (pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile]) != 0)
        {
            int nAltMissile = pSkillsTxtRecord->wCltMissileB;
            if (nAltMissile < 0 || nAltMissile >= nMissilesCount)
            {
                nAltMissile = -1;
            }

            D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
            if (pTarget)
            {
                D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
                sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 1);
            }

            int nTargetX;
            int nTargetY;
            if (sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
            {
                if (!pTarget)
                {
                    UNITS_UpdateDirectionAndSpeed(pUnit, nTargetX, nTargetY);
                }

                sub_00681EF0_Memset(&tMissileParams, 0, sizeof(tMissileParams));
                tMissileParams.dwFlags = 0x25;
                tMissileParams.pOwner = pUnit;
                tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
                tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
                tMissileParams.nSkill = nSkillId;
                tMissileParams.nSkillLevel = nSkillLevel;
                tMissileParams.nTargetX = nTargetX;
                tMissileParams.nTargetY = nTargetY;

                const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel) + sub_004DA150_GetMotionAZ(pUnit);
                const int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
                int nSpeed = pMissilesTxtRecord->nAnimLen << 8;
                int nFall = -2 * nHeight;
                if (nFrames)
                {
                    nSpeed /= nFrames;
                    nFall /= nFrames;
                }

                D2SeedStrc* pSeed = &pUnit->pSeed;
                tMissileParams.nMissile = nMissile;
                if (nAltMissile > 0 && SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    tMissileParams.nMissile = nAltMissile;
                }

                tMissileParams.nVelocity = pMissilesTxtRecord->nVel + gnVelocityBonus_006DBF38[SEED_RollRandomNumber(pSeed) % 5];

                D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pMissile)
                {
                    sub_00648E70_SetDistance(pMissile->pDynamicPath, nFrames);
                    UNITS_SetAnimationSpeed(pMissile, nSpeed);
                    MISSILE_SetTotalFrames(pMissile, nFrames);
                    MISSILE_SetCurrentFrame(pMissile, nFrames);
                    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nHeight);
                    sub_004DA350_UpdateMotion(pMissile);
                    sub_004DA200_SetMotionVectorB(pMissile, 0, 0, nFall, 1);
                }

                return 1;
            }
        }
    }

    return 0;
}

#include "gen/data/Source/D2Client/Unknown_004EDC30.inc"

static __forceinline void sub_004F0050_LaunchMotion(D2UnitStrc* pMissile, int nHeight, int nVelocity)
{
    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nHeight);
    sub_004DA200_SetMotionVectorB(pMissile, 0, 0, nVelocity, 1);
    sub_004DA350_UpdateMotion(pMissile);
}

// 0x004F0050
int __fastcall sub_004F0050_LaunchMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pMissile = sub_004CDD10_CreateMissileAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nFrames = MISSILE_GetTotalFrames(pMissile);
    const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + sub_004DA150_GetMotionAZ(pUnit);
    sub_004F0050_LaunchMotion(pMissile, nHeight, nFrames ? -(nHeight / nFrames) : -(nHeight / 2));
    return 1;
}

static __forceinline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

static __forceinline int GetUnitClass(D2UnitStrc* unit)
{
    return !unit ? -1 : unit->dwClassId;
}

// 0x004F0F10
int __fastcall sub_004F0F10_IsTargetObject(D2UnitStrc* unit, void* unused)
{
    if (GetUnitType(unit) != 3)
        return 0;
    return GetUnitClass(unit) == 468;
}
