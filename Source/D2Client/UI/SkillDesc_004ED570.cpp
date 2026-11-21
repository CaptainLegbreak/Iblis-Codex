#include "D2Client.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameTypes.h"



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

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_005267E0(Unicode*, const Unicode*); // 0x005267E0

void __cdecl sub_005269D0(int, Unicode*, const Unicode*, ...); // 0x005269D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*, const char*, int); // 0x00643CE0

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc*); // 0x00644140

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue); // 0x004E9940

#define TP gtSkillTextPositions_0072D840

#define DRAW_SKILL_TEXT(i, text) sub_004A7080(TP[i].nLeft + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C + TP[i].nY - 480, TP[i].nRight + gnGlobal_007A2858, text, 0)

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissileStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern const unsigned char gbSkillFlagMask_006CE270; // 0x006CE270

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

extern int gnChargedBoltTurnEvery_0072D98C; // 0x0072D98C

extern int gnChargedBoltTurnBase_0072D990; // 0x0072D990

extern const int gnDirectionOffsetY_006DC1E8[]; // 0x006DC1E8

extern const int gnDirectionOffsetX_006DC208[]; // 0x006DC208

unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0

void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints); // 0x00648790

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nFrame); // 0x0064A330

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
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
    if (pDesc->wDescDam >= 144 || !gpfSkillDamageFuncs_0072D768[pDesc->wDescDam]) bDamage = 0;
    if (pDesc->wDescFunc >= 72 || !gpfSkillDescFuncs_0072D7F8[pDesc->wDescFunc]) bDescription = 0;
    ++nIndex;
    if (bDamage)
        DRAW_SKILL_TEXT(nIndex, D2LANG_GetStringFromTblIndex(0xFDD));
    ++nIndex;
    if (bDamage)
        gpfSkillDamageFuncs_0072D768[pDesc->wDescDam](pUnit, pSkill, pSkillsTxt, nLevel, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight);
    if (!bDescription)
        return;
    Unicode wszDescription[200];
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
        Unicode wszValue1[32];
        Unicode wszValue2[32];
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

static inline unsigned int SEED_RollRandomNumber_Spray(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Spray(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static inline int CLIENTS_GetUnitX_Spray(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY_Spray(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    default:
        if (pUnit->pDynamicPath)
            nResult = PATH_GetYPosition(pUnit->pDynamicPath);
        else
            nResult = 0;
        break;
    }
    return nResult;
}

// 0x004F1A30
static void __stdcall sub_004F1A30_CreateSprayMissile(D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    const int nIndex = SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 7;
    const int nUnitX = CLIENTS_GetUnitX_Spray(pUnit);
    const int nUnitY = CLIENTS_GetUnitY_Spray(pUnit);
    const int nOffsetX = gaSprayOffsetX_006DBFA8[nIndex];
    const int nOffsetY = gaSprayOffsetY_006DBFC8[nIndex];
    const int nX = nUnitX + nOffsetX;
    const int nY = nUnitY + nOffsetY;

    int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0)
    {
        return;
    }

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollRandomNumber_Spray(&pUnit->pSeed) % 3)
            {
            case 0:
                nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!(SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 1))
        {
            nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nTargetX = nOffsetY;
    tMissile.nTargetY = -nOffsetX;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissile);
    if (!pMissile)
    {
        return;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[1], nSkillId, nSkillLevel);
    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, SEED_RollLimitedRandomNumber(&pUnit->pSeed, nSpread));
    MISSILE_SetTargetX(pMissile, CLIENTS_GetUnitX_Spray(pUnit));
    MISSILE_SetTargetY(pMissile, CLIENTS_GetUnitY_Spray(pUnit));
}

int __fastcall sub_004F1C80_SkillCltDoSpray(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_Spray(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int bInTown = !pRoom || DUNGEON_IsRoomInTown(pRoom);
    if (pSkillsTxt->wPrgSound > 0)
    {
        void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pUnit, pSkillsTxt->wPrgSound);
        if (bInTown)
        {
            if (pUnitSfx)
            {
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
            }
        }
        else if (!pUnitSfx)
        {
            sub_004B9A00(pSkillsTxt->wPrgSound, pUnit, 0, 0, 0);
        }
    }

    if (bInTown)
    {
        return 0;
    }

    const int nSkill = nSkillId;
    const int nPasses = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkill, nSkillLevel);
    for (int i = 0; i < nPasses; ++i)
    {
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        sub_004F1A30_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
    }

    return 1;
}

// build: context sub_004F21B0_GetSkillsTxtRecord
static inline D2SkillsTxt* sub_004F21B0_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}
	return 0;
}

// 0x004F21B0
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
	D2SkillsTxt* pSkillsTxtRecord = sub_004F21B0_GetSkillsTxtRecord(nSkillId);
	if (!pSkillsTxtRecord)
	{
		return -1;
	}

	if (pSkillsTxtRecord->nFlags[0] & gbSkillFlagMask_006CE270)
	{
		if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
			&& pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
		{
			D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
			if (pStatList)
			{
				int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
				nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
				return pSkillsTxtRecord->wCltMissile[nIndex];
			}
		}
	}

	return pSkillsTxtRecord->wCltMissile[1];
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x004F28A0
void __fastcall sub_004F28A0_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nRadius, int nSkillId, int nSkillLevel)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nSeed);

    const int nRadiusSq = nRadius * nRadius;
    const int nRange = 2 * nRadius;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 1;
    tMissile.pOwner = pUnit;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    for (int i = 0; i < nRadiusSq; ++i)
    {
        const int nOffsetX = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        const int nOffsetY = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        if (nOffsetX * nOffsetX + nOffsetY * nOffsetY <= nRadiusSq)
        {
            tMissile.nX = nX + nOffsetX;
            tMissile.nY = nY + nOffsetY;
            if (sub_00463740_FindRoomAtPoint(pRoom, tMissile.nX, tMissile.nY))
            {
                sub_004CD540_CreateMissile(&tMissile);
            }
        }
    }
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x004F2BE0
void __fastcall sub_004F2BE0_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    sub_00648E70_SetDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    // volatile: the original reads the turn base from memory inside each sum
    int nStep = nRoll % 3 + *(volatile int*)&gnChargedBoltTurnBase_0072D990;
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection & 63);
        nX += gnDirectionOffsetX_006DC208[nIndex];
        nY += gnDirectionOffsetY_006DC1E8[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnChargedBoltTurnEvery_0072D98C))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumber(pSeed) % 3 + *(volatile int*)&gnChargedBoltTurnBase_0072D990;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

#include "gen/data/Source/D2Client/UI/SkillDesc_004ED570.inc"
