#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct T00481920;
struct Unicode;
struct D2ItemStatCostTxt;
struct D2CharStatsTxt;
struct D2MonStatsTxt;
struct D2MonTypeTxt;
struct D2SkillsTxt;
struct D2CombinedStatStrc;
struct D2CombinedStatsStrc;
struct D2CombinedStatIdStrc;
struct D2FileIndexTextStrc;

struct T00481920
{
    char unk0x00[0x4];
    int nDaySound;
    int nNightSound;
    int nDayAmbient;
    int nNightAmbient;
    unsigned int nAmbientDelay;
    char unk0x18[0x4];
    int nEntryA;
    int nEntryB;
};

extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
int __cdecl sub_004DF870(); // 0x004DF870
int __cdecl sub_00481780_GetPlayerLevelId(); // 0x00481780
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA950_RefreshHintsInRangeA(int nGroupA, int nGroupB); // 0x004BA950
void __fastcall sub_004BA9D0_RefreshHintsInRangeB(int nGroupA, int nGroupB); // 0x004BA9D0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue); // 0x004B9B50
int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20
void __fastcall sub_004BA840(int nHandle); // 0x004BA840
int __fastcall sub_004E40A0(int nRange); // 0x004E40A0
int __fastcall sub_004E4100(int nMin, int nMax); // 0x004E4100
static void sub_004E4240_ResetEntryPairs(int nIndex); // 0x004E4240

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStatId;
    int nValue;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    char unk0x19[0x1D];
    unsigned char nDescFunc;
    unsigned char nDescVal;
    unsigned short wDescStrPos;
    unsigned short wDescStrNeg;
    unsigned short wDescStr2;
    unsigned short wDescGrp;
    unsigned char nDescGrpFunc;
    unsigned char nDescGrpVal;
    unsigned short wDescGrpStrPos;
    unsigned short wDescGrpStrNeg;
    unsigned short wDescGrpStr2;
    char unk0x48[0x0C];
    unsigned char nOp;
    unsigned char nOpParam;
    unsigned short wOpBase;
    char unk0x58[0xEC];
};

struct D2CharStatsTxt
{
    char unk0x00[0x52];
    unsigned short wStrAllSkills;
    unsigned short wStrSkillTab[3];
    unsigned short wStrClassOnly;
};

struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short wNameStr;
};

struct D2MonTypeTxt
{
    char unk0x00[0x0A];
    unsigned short wStrPlur;
};

struct D2SkillsTxt
{
    char unk0x00[0x0C];
    char nCharClass;
};

struct D2ItemsTxt
{
    char unk0x000[0x112];
    unsigned char nDurability;
    unsigned char nNoDurability;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x28];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
    short* pStatsWithDescFunc;
    int nStatsWithDescFunc;
    char unk0xBE0[0x8C];
    int nStuff;
    int nShiftedStuff;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId); // 0x004833E0
D2MonTypeTxt* __fastcall sub_004E4640_GetMonTypeTxtRecord(int nMonType); // 0x004E4640
void __fastcall sub_004E48B0_BuildText(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0
unsigned short __fastcall sub_004E6CE0_GetStringId(int nId, int nIndex); // 0x004E6CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
extern D2CombinedStatIdStrc gaCombinedStatIds_0072CDD0[]; // 0x0072CDD0
extern D2FileIndexTextStrc gaFileIndexText_0072D6C0[]; // 0x0072D6C0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
static int __stdcall sub_004E4C50_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId); // 0x004E4C50
int __stdcall sub_004E4CE0_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame); // 0x004E4CE0
static __declspec(noinline) void __stdcall sub_004E5E90_BuildFileIndexStatText(D2UnitStrc* pUnit, Unicode* pOut, D2FileIndexTextStrc* pTable);

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __fastcall sub_004E8FE0_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem); // 0x004E8FE0

int gnGlobal_007C8C7C; // 0x007C8C7C

int gnGlobal_007C8C80; // 0x007C8C80

int gnGlobal_007C8C84; // 0x007C8C84

int gnGlobal_007C8C88; // 0x007C8C88

int gnGlobal_007C8C8C; // 0x007C8C8C

int gnGlobal_007C8C90; // 0x007C8C90

unsigned int gnGlobal_007C8C94; // 0x007C8C94

unsigned int gnGlobal_007C8C98; // 0x007C8C98

static void sub_004E4240_ResetEntryPairs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        sub_004822B0(nId, 1);
        sub_004822B0(nId + 0x18, 1);
        nId += 0x30;
    }
}

static __forceinline float GetEnvironVolume_Inline()
{
    return sub_00473C40() ? sub_00473C80() : 0.0f;
}

// 0x004E42E0
void __fastcall sub_004E42E0_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870())
        return;
    const int nLevelId = sub_00481780_GetPlayerLevelId();
    if (!nLevelId)
        return;
    int nSound = 0;
    int nAmbient = 0;
    int nVolume = 0;
    int bNight;
    switch (ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634))
    {
    case 1:
    case 2:
    case 3:
        bNight = 0;
        break;
    default:
        bNight = 1;
        break;
    }
    const int nEnviron = sub_004817A0_GetPlayerSoundEnviron();
    T00481920* pEnv = sub_00481920_GetSoundEnvironTxtRecord(nEnviron);
    if (pEnv)
    {
        if (bNight)
        {
            nAmbient = pEnv->nNightAmbient;
            nSound = pEnv->nNightSound;
        }
        else
        {
            nAmbient = pEnv->nDayAmbient;
            nSound = pEnv->nDaySound;
        }
    }
    int nSecond = sub_00473C40() ? 0x40 : 0;
    if (GetEnvironVolume_Inline() != 0.0f)
    {
        const float fVolume = !sub_00473C40() ? 0.0f : sub_00473C80();
        nVolume = (int)(fVolume * 255.0);
    }
    if (nSound != gnGlobal_007C8C88)
    {
        int bCross = 0;
        if (nSound == pEnv->nDaySound && gnGlobal_007C8C88 == pEnv->nNightSound)
            bCross = 1;
        if (nSound == pEnv->nNightSound && gnGlobal_007C8C88 == pEnv->nDaySound)
            bCross = 1;
        if (bCross)
        {
            sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0, 0, 0xFA);
        }
        else
        {
            sub_004BA950_RefreshHintsInRangeA(nSound, nSecond);
            sub_004BA9D0_RefreshHintsInRangeB(nAmbient, 0);
        }
        if (nSound != gnGlobal_007C8C88)
        {
            if (nSound)
            {
                gnGlobal_007C8C80 = sub_004B9A00(nSound, 0, 0, 0, 0);
                if (bCross)
                {
                    sub_004B9B50_SetHintValue(gnGlobal_007C8C80, 0);
                    sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0xFF, 0, 0xFA);
                }
                gnGlobal_007C8C88 = nSound;
            }
            else
            {
                gnGlobal_007C8C80 = 0;
                gnGlobal_007C8C88 = 0;
            }
        }
    }
    if (nSecond)
    {
        if (nVolume && !gnGlobal_007C8C84)
        {
            gnGlobal_007C8C84 = sub_004B9A00(gnGlobal_007C8C8C, 0, 0, 0, 0);
            if (gnGlobal_007C8C84)
                sub_004B9B50_SetHintValue(gnGlobal_007C8C84, nVolume);
        }
        if (gnGlobal_007C8C84)
        {
            const int nCurrent = sub_004B9B20(gnGlobal_007C8C84);
            int nNext;
            if (nVolume > nCurrent)
                nNext = nVolume < nCurrent + 6 ? nVolume : nCurrent + 6;
            else
                nNext = nVolume > nCurrent - 6 ? nVolume : nCurrent - 6;
            if (nNext)
            {
                sub_004B9B50_SetHintValue(gnGlobal_007C8C84, nNext);
            }
            else
            {
                sub_004BA840(gnGlobal_007C8C84);
                gnGlobal_007C8C84 = 0;
            }
        }
        gnGlobal_007C8C8C = nSecond;
    }
    else
    {
        sub_004BA840(gnGlobal_007C8C84);
        gnGlobal_007C8C84 = 0;
        gnGlobal_007C8C8C = 0;
    }
    sub_004DF6C0(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnGlobal_007C8C90)
        {
            gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            gnGlobal_007C8C98 = dwTick - sub_004E40A0(gnGlobal_007C8C94);
            gnGlobal_007C8C90 = nAmbient;
        }
        if (dwTick - gnGlobal_007C8C98 >= gnGlobal_007C8C94)
        {
            const int nHandle = sub_004B9A00(gnGlobal_007C8C90, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0(2) ? 1 : -1;
                const int nPan = sub_004E4100(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
                sub_004B99A0(nHandle, nPan, nPanVolume, 0);
                gnGlobal_007C8C98 = dwTick;
                gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            }
        }
    }
    if (nLevelId != gnGlobal_007C8C7C)
    {
        const int nEntryA = pEnv->nEntryA;
        const int nEntryB = pEnv->nEntryB;
        for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
            sub_00482370(nId);
        if (nEntryA)
            sub_004E4240_ResetEntryPairs(nEntryA);
        if (nEntryB)
            sub_004E4240_ResetEntryPairs(nEntryB);
        gnGlobal_007C8C7C = nLevelId;
    }
}

static void __stdcall sub_004E49C0_CollectCombinedStats(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2CombinedStatsStrc* pCombined)
{
    memset(pCombined, 0, sizeof(D2CombinedStatsStrc));

    for (int i = 0; i < gnCombinedStatCount_0072CDCC; ++i)
    {
        const int nStatId = gaCombinedStatIds_0072CDD0[i].nStatId;
        if (nStatId == -1)
            continue;

        switch (nStatId)
        {
        case 48:
            pCombined->tFire.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 49:
            pCombined->tFire.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 50:
            pCombined->tLightning.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 51:
            pCombined->tLightning.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 52:
            pCombined->tMagic.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 53:
            pCombined->tMagic.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 54:
            pCombined->tCold.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 55:
            pCombined->tCold.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 57:
            pCombined->tPoison.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 58:
            pCombined->tPoison.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 59:
            pCombined->tPoison.nLength = STATLIST_GetStatValue(pStatList, nStatId, 0);
            pCombined->tPoison.nCount = STATLIST_UnitGetStatValue(pUnit, 326, 0);
            break;
        case 21:
            pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMin)
                pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, 23, 0);
            break;
        case 22:
            pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMax)
                pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, 24, 0);
            break;
        case 18:
            pCombined->tDamagePercent.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 17:
            pCombined->tDamagePercent.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        }
    }

    if (pCombined->tDamage.nMin > 0 && pCombined->tDamage.nMax > 0)
        pCombined->tDamage.bCombined = 1;
    if (pCombined->tDamagePercent.nMin > 0 && pCombined->tDamagePercent.nMax > 0)
        pCombined->tDamagePercent.bCombined = 1;
    if (pCombined->tCold.nMin > 0 && pCombined->tCold.nMax > 0)
        pCombined->tCold.bCombined = 1;
    if (pCombined->tLightning.nMin > 0 && pCombined->tLightning.nMax > 0)
        pCombined->tLightning.bCombined = 1;
    if (pCombined->tFire.nMin > 0 && pCombined->tFire.nMax > 0)
        pCombined->tFire.bCombined = 1;
    if (pCombined->tPoison.nMin > 0 && pCombined->tPoison.nMax > 0)
        pCombined->tPoison.bCombined = 1;
    if (pCombined->tMagic.nMin > 0 && pCombined->tMagic.nMax > 0)
        pCombined->tMagic.bCombined = 1;
}

static int __stdcall sub_004E4C50_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId)
{
    if (pRecord->nOp >= 2 && pRecord->nOp <= 5)
    {
        const int nOpBase = pRecord->wOpBase;
        D2ItemStatCostTxt* pBase = (nOpBase >= 0 && nOpBase < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nOpBase] : 0;
        if (!pBase)
            return 0;

        nValue = (STATLIST_UnitGetStatValue(sub_00463DD0(), nOpBase, 0) >> pBase->nValShift) * nValue >> pRecord->nOpParam;
    }

    nValue >>= pRecord->nValShift;
    if (nStatId == 122 && pUnit && pUnit->dwUnitType == 4 && ITEMS_CheckItemTypeId(pUnit, 57))
        nValue += 50;

    return nValue;
}

int __stdcall sub_004E4CE0_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame)
{
    if (!pRecord->wDescGrp)
        return 0;

    for (int i = sgptDataTables->nItemStatCostTxtRecordCount - 1; i >= 0; --i)
    {
        D2ItemStatCostTxt* pOther = (i >= 0 && i < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[i] : 0;
        if (!pOther)
            return 0;

        if (pRecord->wDescGrp == pOther->wDescGrp)
        {
            *pIsSame = i == nStatId;
            const int nStat = STATLIST_GetStatValue(pStatList, i, 0);
            if (nValue != sub_004E4C50_GetStatDisplayValue(nStat, pOther, pUnit, i))
                return 0;
        }
    }

    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004E4D80
static int __stdcall sub_004E4D80_BuildStatText(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nLayer, int nValue, Unicode* pOut)
{
    pOut[0] = 0;

    D2ItemStatCostTxt* pRecord = (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nStatId] : 0;
    if (!pRecord)
        return 0;

    int nDisplay = sub_004E4C50_GetStatDisplayValue(nValue, pRecord, pUnit, nStatId);
    int bIsSame = 1;
    const int bUniform = sub_004E4CE0_IsStatGroupUniform(pUnit, pStatList, nStatId, nDisplay, pRecord, &bIsSame);
    if (bUniform && !bIsSame)
        return 0;

    int nDescFunc = pRecord->nDescFunc;
    int nDescVal = pRecord->nDescVal;
    unsigned short wDescStr2 = pRecord->wDescStr2;
    const Unicode* pText;
    if (bUniform)
    {
        nDescFunc = pRecord->nDescGrpFunc;
        nDescVal = pRecord->nDescGrpVal;
        wDescStr2 = pRecord->wDescGrpStr2;
        if (nDisplay >= 0)
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescGrpStrPos);
        else
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescGrpStrNeg);
    }
    else
    {
        if (nDisplay >= 0)
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescStrPos);
        else
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescStrNeg);
    }

    char szNumber[10];
    SStrPrintf(szNumber, 10, szIntFormat_006D6454, nDisplay);
    Unicode wszNumber[10];
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);

    const Unicode* pPercent = D2LANG_GetStringFromTblIndex(0xFA1);
    const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);

    switch (nDescFunc)
    {
    case 1:
    case 6:
    case 12:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            if (nDescFunc != 12 || nDisplay > 1)
            {
                sub_005267E0(wszValue, pPlus);
                sub_00526700(wszValue, wszNumber);
            }
        }
        else
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 4:
    case 8:
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 20:
    case 21:
        nDisplay = -nDisplay;
        SStrPrintf(szNumber, 10, szIntFormat_006D6454, nDisplay);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 2:
    case 7:
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 3:
    case 9:
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 5:
    case 10:
        SStrPrintf(szNumber, 10, szIntFormat_006D6454, nDisplay * 100 / 128);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 11:
        if (nDisplay > 0)
        {
            const int nRate = 2500 / nDisplay;
            if (nRate <= 30)
            {
                const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52F9);
                sub_005269D0(128, pOut, pFormat, 1);
            }
            else
            {
                const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52FA);
                sub_005269D0(128, pOut, pFormat, 1, (nRate + 12) / 25);
            }
        }
        else
        {
            const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52F9);
            sub_005269D0(128, pOut, pFormat, 25);
        }
        break;
    case 13:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else if (nDisplay < 0)
        {
            sub_005267E0(wszValue, wszNumber);
        }
        else
        {
            return 0;
        }

        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nLayer);
        if (!pCharStats)
            return 0;

        const Unicode* pAllSkills = D2LANG_GetStringFromTblIndex(pCharStats->wStrAllSkills);
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pAllSkills);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pAllSkills);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 14:
    {
        const int nTab = nLayer & 7;
        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nLayer >> 3);
        if (!pCharStats)
            return 0;
        if (nTab < 0 || nTab > 2)
            return 0;

        sub_005269D0(256, pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrSkillTab[nTab]), nDisplay);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrClassOnly));
        break;
    }
    case 15:
    {
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
            return 0;

        sub_005269D0(256, pOut, D2LANG_GetStringFromTblIndex(pRecord->wDescStrPos), nDisplay, 0, nLevel, D2LANG_GetStringFromTblIndex(sub_004E6CE0_GetStringId(nSkillId, 0)));
        break;
    }
    case 16:
    {
        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(sub_004E6CE0_GetStringId(nLayer, 0));
        if (!pSkillName)
            return 0;

        sub_005269D0(256, pOut, pText, nDisplay, pSkillName);
        break;
    }
    case 17:
    case 18:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        int nPeriodOfDay = 0;
        int nBaseTime = 0;
        if (gpAct_007A0634)
            nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(gpAct_007A0634, &nBaseTime);

        int nMin;
        int nMax;
        int nAmount = ITEMMODS_GetByTimeAdjustment(nDisplay, nPeriodOfDay, nBaseTime, &nPeriodOfDay, &nMin, &nMax);
        if (!gpAct_007A0634)
            nAmount = nMin;

        const int nPeriod = nPeriodOfDay > 0 ? nPeriodOfDay : 0;
        nPeriodOfDay = nPeriod < 3 ? nPeriod : 3;
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(gawPeriodOfDayStr_006DBD88[nPeriodOfDay]));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9E));

        SStrPrintf(szNumber, 10, szIntFormat_006D6454, nAmount);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nAmount >= 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else if (nDisplay < 0)
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescFunc == 18)
            sub_00526700(wszValue, pPercent);

        if (nDescVal == 1)
        {
            sub_00526700(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_00526700(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 19:
        sub_005269D0(256, pOut, pText, nDisplay);
        break;
    case 22:
    {
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }

        D2MonTypeTxt* pMonType = sub_004E4640_GetMonTypeTxtRecord(nLayer);
        if (!pMonType)
            break;

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pMonType->wStrPlur));
        break;
    }
    case 23:
    {
        D2MonStatsTxt* pMonStats = DATATBLS_GetMonStatsTxtRecord(nLayer);
        if (!pMonStats)
            return 0;

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pMonStats->wNameStr));
        break;
    }
    case 24:
    {
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(sub_004E6CE0_GetStringId(nSkillId, 0));
        if (!pSkillName)
            break;

        Unicode wszValue[256];
        wszValue[0] = 0;
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x5301));
        sub_00526700(pOut, pSpace);
        SStrPrintf(szNumber, 10, szIntFormat_006D6454, nLevel);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        sub_00526700(pOut, wszNumber);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        sub_00526700(pOut, pSpace);
        sub_005269D0(128, wszValue, pText, nDisplay & 0xFF, nDisplay >> 8);
        sub_00526700(pOut, wszValue);
        break;
    }
    case 25:
    case 26:
    {
        Unicode wszValue[256];
        nDisplay = -nDisplay;
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    {
    int nCharClass;
    case 27:
    {
        const Unicode* pTo = D2LANG_GetStringFromTblIndex(0xFA3);
        if (!pTo)
            break;
        if (!nDisplay)
            break;

        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(sub_004E6CE0_GetStringId(nLayer, 0));
        if (!pSkillName)
            break;

        if (nDisplay > 0)
        {
            sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, wszNumber);
        }
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pTo);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        sub_00526700(pOut, pSpace);

        nCharClass = 7;
        if (!sub_00645080_GetSkillCharClass(nLayer, &nCharClass))
            break;
        if (nCharClass < 0 || nCharClass > 6)
            break;

        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nCharClass);
        if (!pCharStats)
            break;

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrClassOnly));
        break;
    }
    case 28:
    {
        if (!nDisplay)
            break;

        D2SkillsTxt*& pSkillsTxt = (D2SkillsTxt*&)nCharClass;
        pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nLayer);
        if (!pSkillsTxt)
            break;

        D2UnitStrc* pPlayer = pUnit;
        if (!pPlayer || pPlayer->dwUnitType != 0)
            pPlayer = sub_00463DD0();

        const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
        if (pSkillsTxt->nCharClass == nClass && nDisplay > 3)
            nDisplay = 3;

        const Unicode*& pTo = (const Unicode*&)nCharClass;
        pTo = D2LANG_GetStringFromTblIndex(0xFA3);
        if (!pTo)
            break;

        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(sub_004E6CE0_GetStringId(nLayer, 0));
        if (!pSkillName)
            break;

        SStrPrintf(szNumber, 10, szIntFormat_006D6454, nDisplay);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDisplay > 0)
        {
            sub_005267E0(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, wszNumber);
        }
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pTo);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        break;
    }
    }
    default:
        return 0;
    }

    if (nDescFunc >= 6 && (nDescFunc <= 10 || nDescFunc == 21))
    {
        if (wDescStr2 != 0x1506)
        {
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(wDescStr2));
        }
        else
        {
            const Unicode* pStr2 = D2LANG_GetStringFromTblIndex(0x2B53);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pStr2);
        }
    }

    return 1;
}

static int __stdcall sub_004E5A20_BuildCombinedStatText(int nStatId, Unicode* pOut, D2CombinedStatsStrc* pCombined)
{
    Unicode wszText[256];
    memset(wszText, 0, sizeof(wszText));

    int bAppend = 0;
    switch (nStatId)
    {
    case 49:
        return pCombined->tFire.bCombined;
    case 55:
        return pCombined->tCold.bCombined;
    case 51:
        return pCombined->tLightning.bCombined;
    case 53:
        return pCombined->tMagic.bCombined;
    case 58:
    case 59:
        return pCombined->tPoison.bCombined;
    case 17:
        return pCombined->tDamagePercent.bCombined;
    case 48:
        if (!pCombined->tFire.bCombined)
            return 0;
        if (pCombined->tFire.nMin >= pCombined->tFire.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1C), pCombined->tFire.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1D), pCombined->tFire.nMin, pCombined->tFire.nMax);
        bAppend = 1;
        break;
    case 54:
        if (!pCombined->tCold.bCombined)
            return 0;
        if (pCombined->tCold.nMin >= pCombined->tCold.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1E), pCombined->tCold.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1F), pCombined->tCold.nMin, pCombined->tCold.nMax);
        bAppend = 1;
        break;
    case 50:
        if (!pCombined->tLightning.bCombined)
            return 0;
        if (pCombined->tLightning.nMin >= pCombined->tLightning.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE20), pCombined->tLightning.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE21), pCombined->tLightning.nMin, pCombined->tLightning.nMax);
        bAppend = 1;
        break;
    case 52:
        if (!pCombined->tMagic.bCombined)
            return 0;
        if (pCombined->tMagic.nMin >= pCombined->tMagic.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE22), pCombined->tMagic.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE23), pCombined->tMagic.nMin, pCombined->tMagic.nMax);
        bAppend = 1;
        break;
    case 57:
        if (!pCombined->tPoison.bCombined)
            return 0;
        if (pCombined->tPoison.nCount <= 0)
            pCombined->tPoison.nCount = 1;
        pCombined->tPoison.nLength /= pCombined->tPoison.nCount;
        pCombined->tPoison.nMin = (pCombined->tPoison.nMin * pCombined->tPoison.nLength + 0x80) >> 8;
        pCombined->tPoison.nMax = (pCombined->tPoison.nMax * pCombined->tPoison.nLength + 0x80) >> 8;
        if (pCombined->tPoison.nMin >= pCombined->tPoison.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE24), pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE25), pCombined->tPoison.nMin, pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        bAppend = 1;
        break;
    case 24:
        if (pCombined->tDamage.bShown)
            return 1;
        return pCombined->tDamage.bCombined;
    case 21:
    case 22:
    case 23:
        if (!pCombined->tDamage.bShown)
        {
            if (!pCombined->tDamage.bCombined)
                return 0;
            if (pCombined->tDamage.nMin >= pCombined->tDamage.nMax)
            {
                pCombined->tDamage.bShown = 0;
                pCombined->tDamage.bCombined = 0;
                return 0;
            }
            pCombined->tDamage.bShown = 1;
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE27), pCombined->tDamage.nMin, pCombined->tDamage.nMax);
        }
        bAppend = 1;
        break;
    case 18:
    {
        const Unicode* pPercent = D2LANG_GetStringFromTblIndex(0xFA1);
        const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
        const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
        Unicode wszNumber[10];
        char szNumber[10];
        SStrPrintf(szNumber, 10, szIntFormat_006D6454, pCombined->tDamagePercent.nMin);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (!pCombined->tDamagePercent.bCombined)
            return 0;

        sub_005267E0(wszText, pPlus);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, pPercent);
        sub_00526700(wszText, pSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2727));
        bAppend = 1;
        break;
    }
    }

    if (bAppend)
        sub_00526700(pOut, wszText);

    return bAppend;
}

void __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pUnit, Unicode* pOut, int nUnused, int bQuantity, int nState, int nState2, int nFlag, int bNewline)
{
    Unicode wszLine[128];
    Unicode wszQuantity[128];
    D2CombinedStatsStrc tCombined;
    D2StatStrc aStats[511];

    if (ITEMS_GetItemType(pUnit) == 11)
    {
        sub_004E5E90_BuildFileIndexStatText(pUnit, pOut, gaFileIndexText_0072D6C0);
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, nState, nFlag);
    if (!pStatList)
        return;

    D2StatListStrc* pMerged = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    STATLIST_MergeBaseStats(pMerged, pStatList);
    if (nState2)
    {
        D2StatListStrc* pExtra = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, nState2, nFlag);
        if (pExtra)
            STATLIST_MergeBaseStats(pMerged, pExtra);
    }

    if (pUnit && pUnit->dwUnitType == 4 && pUnit->pInventory)
    {
        D2UnitStrc* pSocketed = INVENTORY_GetFirstItem(pUnit->pInventory);
        while (pSocketed)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pSocketed);
            if (!pItem)
                break;

            pSocketed = INVENTORY_GetNextItem(pSocketed);
            D2StatListStrc* pItemStats = STATLIST_GetStatListFromUnitStateAndFlag(pItem, nState, nFlag);
            if (pItemStats)
                STATLIST_MergeBaseStats(pMerged, pItemStats);
        }
    }

    const Unicode* pNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pComma = D2LANG_GetStringFromTblIndex(0xF0C);

    if (bQuantity && ITEMS_CheckItemTypeId(pUnit, 57) && !STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 122, 0))
    {
        sub_004E48B0_BuildText(pUnit, wszQuantity, 128);
        sub_00526700(pOut, wszQuantity);
    }

    sub_004E49C0_CollectCombinedStats(pUnit, pMerged, &tCombined);

    int bAdded = 0;
    for (int i = 0; i < sgptDataTables->nStatsWithDescFunc; ++i)
    {
        const int nStatId = sgptDataTables->pStatsWithDescFunc[i];
        if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            continue;

        const int nCount = D2COMMON_11269_CopyStats(pMerged, nStatId, aStats, 511);
        for (int j = 0; j < nCount; ++j)
        {
            const int nValue = aStats[j].nValue;
            const int nLayer = aStats[j].nLayer;
            if (!nValue)
                continue;

            if (sub_004E5A20_BuildCombinedStatText(nStatId, pOut, &tCombined))
                continue;

            if (!sub_004E4D80_BuildStatText(pUnit, pMerged, nStatId, nLayer, nValue, wszLine))
                continue;

            switch (nStatId)
            {
            case 23:
                if (STATLIST_GetStatValue(pMerged, 21, 0))
                    continue;
                break;
            case 24:
                if (STATLIST_GetStatValue(pMerged, 22, 0))
                    continue;
                break;
            }

            if (bNewline)
                sub_00526700(wszLine, pNewline);

            if (bAdded && !bNewline)
            {
                sub_00526700(pOut, pComma);
                sub_00526700(pOut, pSpace);
            }

            bAdded = 1;
            sub_00526700(pOut, wszLine);
        }
    }

    if (pUnit && pUnit->dwUnitType == 4)
    {
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
        if (!pItemsTxt->nNoDurability && pItemsTxt->nDurability && STATLIST_UnitGetStatValue(pUnit, 152, 0) <= 0 && !STATLIST_GetMaxDurabilityFromUnit(pUnit))
        {
            const Unicode* pIndestructible = D2LANG_GetStringFromTblIndex(0x52F8);
            if (bAdded && !bNewline)
            {
                sub_00526700(pOut, pComma);
                sub_00526700(pOut, pSpace);
            }

            sub_00526700(pOut, pIndestructible);
            if (bNewline)
                sub_00526700(pOut, pNewline);
        }
    }

    D2StatListStrc* const pFree = pMerged;
    STATLIST_FreeStatList(pFree);
}

#include "gen/data/Source/D2Client/Unknown_004E42E0.inc"

// 0x004E5E90
static void __stdcall sub_004E5E90_BuildFileIndexStatText(D2UnitStrc* pUnit, Unicode* pOut, D2FileIndexTextStrc* pTable)
{
    struct
    {
        int nDelta;
        const Unicode* pPlus;
        const Unicode* pNewline;
        int nFileIndex;
        const Unicode* pSpace;
    } tLocals;
    struct
    {
        Unicode wszLine[128];
        Unicode wszValue[128];
    } tText;
    tLocals.pNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    tLocals.pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    tLocals.pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
    tLocals.nFileIndex = ITEMS_GetFileIndex(pUnit);

    unsigned int i = 0;
    if (i < gnFileIndexTextCount_0072D720)
    {
        tLocals.nDelta = (char*)&gaFileIndexText_0072D6C0[0].nPos - (char*)pTable;
        do
        {
            if (pTable->nFileIndex == tLocals.nFileIndex)
            {
                tText.wszLine[0] = 0;
                tText.wszValue[0] = 0;
                int nValue = STATLIST_UnitGetStatValue(pUnit, 71, 0);
                const int nType = pTable->nFileIndex;
                if (nType == 8 || nType == 9)
                    nValue >>= 8;
                if (nType == 6 || nType == 7)
                    nValue >>= 8;
                if (nType == 10 || nType == 11)
                    nValue >>= 8;

                const Unicode* pText = 0;
                if (nValue > 0)
                    pText = D2LANG_GetStringFromTblIndex(pTable->wStrPos);
                else if (nValue < 0)
                    pText = D2LANG_GetStringFromTblIndex(pTable->wStrNeg);

                if (nValue)
                {
                    Unicode wszNumber[10];
                    char szNumber[10];
                    SStrPrintf(szNumber, 10, szIntFormat_006D6454, nValue);
                    sub_00526320_ToUnicode(wszNumber, szNumber, 9);

                    switch (pTable->nMode)
                    {
                    case 1:
                        if (nValue > 0)
                        {
                            sub_005267E0(tText.wszValue, tLocals.pPlus);
                            sub_00526700(tText.wszValue, wszNumber);
                        }
                        else
                        {
                            sub_005267E0(tText.wszValue, wszNumber);
                        }

                        if (*(int*)((char*)pTable + tLocals.nDelta) == 2)
                        {
                            sub_005267E0(tText.wszLine, pText);
                            sub_00526700(tText.wszLine, tLocals.pSpace);
                            sub_00526700(tText.wszLine, tText.wszValue);
                            sub_00526700(tText.wszLine, tLocals.pNewline);
                            sub_00526700(pOut, tText.wszLine);
                        }
                        else
                        {
                            D2_ASSERT(0, 0x13D);
                        }
                        break;
                    default:
                        D2_ASSERT(0, 0x141);
                        break;
                    }
                }
            }
        }
        while (++pTable, ++i < gnFileIndexTextCount_0072D720);
    }
}

static D2UnitStrc* sub_004E9260_MergeOtherHandWeapon(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (!pOther || pOther == pWeapon)
        return 0;

    if (!ITEMS_CheckItemTypeId(pOther, 45))
        return 0;

    if (!sub_0062A4E0_TestItem(pWeapon) || !sub_0062A4E0_TestItem(pOther))
        return 0;

    if (STATLIST_GetOwner(pWeapon, 0))
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
    if (STATLIST_GetOwner(pOther, 0))
        STATLIST_MergeStatLists(pUnit, pOther, 1);
    return pOther;
}

static D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (pOther && pOther != pWeapon)
    {
        if (ITEMS_CheckItemTypeId(pOther, 45))
        {
            if (sub_0062A4E0_TestItem(pWeapon) && sub_0062A4E0_TestItem(pOther))
            {
                STATLIST_MergeStatLists(pUnit, pOther, 0);
                STATLIST_MergeStatLists(pUnit, pWeapon, 1);
                return pWeapon;
            }
        }
    }

    if (sub_0062A4E0_TestItem(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// 0x004E93A0
static int __stdcall sub_004E93A0_EvaluateForEachWeapon(int* pValue1, int* pValue2, int nArg3, int* pValue3, int* pValue4, int nArg6, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nArg9, D2UnitStrc* pUnit, int nLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!sub_0062A4E0_TestItem(pRight) || ITEMS_CheckItemTypeId(pRight, 0x26))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!sub_0062A4E0_TestItem(pLeft) || ITEMS_CheckItemTypeId(pLeft, 0x26))
        pLeft = 0;

    if (pRight && pLeft)
    {
        D2UnitStrc* pItem = sub_004E9260_MergeOtherHandWeapon(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue3, pValue4, nArg6, nArg9, nLevel, pSkill, 0, pItem);
        }
        else
        {
            *pValue3 = 0;
            *pValue4 = 0;
        }

        pItem = sub_004E9300_MergeWeaponPair(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, pItem);
        }
        else
        {
            *pValue1 = 0;
            *pValue2 = 0;
        }
        return 1;
    }

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pWeapon && sub_0062A4E0_TestItem(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, 0);
    return 1;
}

static int __stdcall sub_004E94E0_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel)
{
    return sub_004E93A0_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, sub_004E8FE0_AttackRatingCallback, 0, pUnit, nLevel);
}

void __fastcall sub_H14_Emit_004E9510(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    if (UNITS_CanDualWield(pUnit))
    {
        sub_004E94E0_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
        return;
    }

    sub_004E93A0_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, sub_004E8FE0_AttackRatingCallback, 0, pUnit, nLevel);
}
