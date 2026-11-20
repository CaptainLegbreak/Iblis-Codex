#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2ClientUi.h"

struct D2CellNodeStrc;
struct D2CellGridViewStrc;
struct D2SlotObjectStrc;
struct D2SlotStrc;
struct S;
struct D2MissilesTxt;
struct D2StringSoundStrc;
struct D2ClientModuleListStrc;
struct D2StaticPathStrc;
union D2SeedStrc;
struct D2SkillsTxt;
struct D2MissileStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
};

struct D2SlotObjectStrc
{
    char unk0x00[0x2C];
    int nField0x2C;
    int nField0x30;
};

struct S { int pad; int type; };

extern int gdwGlobal_007C8C78; // 0x007C8C78
void __cdecl sub_004DFA60(); // 0x004DFA60
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
int __fastcall sub_004E0000_SetSoundMode(int nMode); // 0x004E0000
void __fastcall sub_00515F50_FadeOutMaster(int nTime); // 0x00515F50

struct D2MissilesTxt
{
    char unk0x000[0x3C];
    int nRange;
    char unk0x040[0x5A];
    unsigned char nVel;
    char unk0x09B[0xDD];
    unsigned char nAnimLen;
    char unk0x179[0x2B];
};

struct D2StringSoundStrc
{
    int f_0;
    unsigned short nStringId;
    char unk0x06[0x02];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2StringSoundStrc gaStringSounds_0072B0E0[]; // 0x0072B0E0
extern int gnGlobal_007C8C7C; // 0x007C8C7C
extern int gnGlobal_007C8C80; // 0x007C8C80
extern int gnGlobal_007C8C84; // 0x007C8C84
extern int gnGlobal_007C8C88; // 0x007C8C88
extern int gnGlobal_007C8C8C; // 0x007C8C8C
extern int gnGlobal_007C8C90; // 0x007C8C90
extern int gnGlobal_007C8C94; // 0x007C8C94
extern int gnGlobal_007C8C98; // 0x007C8C98
void __fastcall sub_004BA840(int nHandle); // 0x004BA840

struct D2ClientModuleListStrc
{
    void* pBase;
    void* pUnknown04;
    int nModuleCount;
};
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned int nSize, unsigned int nFreeType); // 0x006CC220

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall sub_006445A0(D2SkillStrc*, int); // 0x006445A0

enum { SUCCESS_VALUE = 1 };

struct D2SkillsTxt
{
    char unk0x00[0x11];
    unsigned char nMonAnim;
    unsigned char unk_12[0xD8];
    short wCltMissileA;
    short wCltMissileB;
    char unk0x0EE[0x26];
    unsigned int dwCltCalc1;
    char unk0x118[0x20];
    unsigned int dwCltCalc2;
    char unk0x13C[0x100];
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0
void __fastcall sub_004E1970_SetInfernoFrames(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x004E1970
extern const int gaMissileVelocityPair_006DBAA0[]; // 0x006DBAA0
extern const int gaMissileVelocityCharged_006DBB38[]; // 0x006DBB38

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short wMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x000[0x109];
    unsigned char nInfernoAnim;
    char unk0x10A[0x2A];
};

int gdwGlobal_007C8C78; // 0x007C8C78

// 0x004DF4B0
static __forceinline void sub_004DF4B0_DrawCellNode(D2CellGridViewStrc* pView, D2CellNodeStrc* pNode, int nArg)
{
    const int bMode = sub_004F51D0_IsPerspective();
    if (pNode->dwFlags & 1)
    {
        if (bMode)
        {
            sub_004F6980(pNode->pPos->f_18, pNode->nA, pNode->nB, 4, nArg);
        }
        else
        {
            sub_004F6980(pNode->pPos->f_18, pView->nOffsetX - pView->nScrollX + pNode->pPos->nX, pNode->pPos->nY - pView->nScrollY + pView->nOffsetY, 4, nArg);
        }
    }
    else if (pNode->dwFlags & 2)
    {
        sub_00471620(pNode->pPos);
    }
}

void __stdcall sub_M114_Emit_004DF4B0(D2CellGridViewStrc* pView, D2CellNodeStrc* pNode, int nArg)
{
    sub_004DF4B0_DrawCellNode(pView, pNode, nArg);
}

// 0x004DF790
void __fastcall sub_004DF790_ReleaseSlotObject(D2SlotStrc* pSlot)
{
    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF900
unsigned int __fastcall sub_004DF900_GetSlotSampleCount(D2SlotStrc* pSlot)
{
    return sub_005159B0_GetSoundSampleCount(pSlot->pSound);
}

// 0x004DF910
int __cdecl sub_004DF910_GetSoundMode()
{
    return sub_00514C90_GetSoundMode();
}

// 0x004DF940
int __cdecl sub_004DF940()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }
    return sub_00513B60();
}

// 0x004DF960
int __cdecl sub_004DF960()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }
    return sub_00513B70_IsSoundEnvironEnabled();
}

// 0x004DF770
__declspec(noinline) static bool __fastcall sub_004DF770(S* p, char unused, int x) { return p->type == x; }

// build: context sub_004DF770_Shim
// calling-convention shim (not game code)
void sub_004DF770_Shim(S* p, int x) { (void)sub_004DF770(p, 0, x); }

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl sub_0063A800_Nop()
{
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl sub_00587830_Nop()
{
}

// 0x004DF980
int __cdecl sub_004DF980_IsSoundMode1Or2()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    const int nMode = sub_00514C90_GetSoundMode();
    if (nMode == 1 || nMode == 2)
    {
        return 1;
    }

    return 0;
}

// 0x004DF9B0
int __cdecl sub_004DF9B0_IsSoundMode2()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    return sub_00514C90_GetSoundMode() == 2;
}

// 0x004E0690
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue)
{
    gdwGlobal_0072AE24 = nValue;
}

// 0x004E00C0
void __cdecl sub_004E00C0_CloseSoundChannels()
{
    sub_004DFA60();
}

long gnGlobal_007C8A74; // 0x007C8A74

// 0x004E00D0
int __cdecl sub_004E00D0_ToggleSoundMode01()
{
    if (!gdwGlobal_007C8C78 || gnGlobal_007C8A74)
        return 0;

    InterlockedIncrement(&gnGlobal_007C8A74);
    const int nOld = sub_00514C90();
    int nNew;
    if (nOld == 0)
        nNew = 1;
    else
        nNew = 0;
    sub_00515F50_FadeOutMaster(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
    sub_00515CE0_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnGlobal_007C8A74);
    return nResult;
}

// 0x004E0140
int __cdecl sub_004E0140_ToggleSoundMode12()
{
    if (!gdwGlobal_007C8C78 || gnGlobal_007C8A74)
        return 0;

    InterlockedIncrement(&gnGlobal_007C8A74);
    const int nOld = sub_00514C90();
    int nNew;
    if (nOld == 2)
        nNew = 1;
    else
        nNew = 2;
    sub_00515F50_FadeOutMaster(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
    sub_00515CE0_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnGlobal_007C8A74);
    return nResult;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E0650
int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId)
{
    if (gdwGlobal_0072AE24)
    {
        for (D2StringSoundStrc* pEntry = gaStringSounds_0072B0E0; pEntry; ++pEntry)
        {
            if (!pEntry->f_0)
            {
                break;
            }

            if (pEntry->nStringId == nStringId)
            {
                return pEntry->f_0;
            }
        }
    }

    return 0;
}

// 0x004E3170
void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor)
{
    if (pMissile && pMissile->dwUnitType == 3 && nDivisor)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord_Inline(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            UNITS_SetAnimationSpeed(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nDivisor);
        }
    }
}

// 0x004E4020
void __fastcall sub_004E4020(D2UnitStrc* pUnit)
{
}

// 0x004E4050
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
}

// 0x004E4280
extern "C" void __cdecl sub_004E4280()
{
    gnGlobal_007C8C7C = 0;
    gnGlobal_007C8C90 = 0;
    gnGlobal_007C8C94 = 0;
    gnGlobal_007C8C98 = 0;
    if (gnGlobal_007C8C80)
    {
        sub_004BA840(gnGlobal_007C8C80);
        gnGlobal_007C8C80 = 0;
    }

    gnGlobal_007C8C88 = 0;
    if (gnGlobal_007C8C84)
    {
        sub_004BA840(gnGlobal_007C8C84);
        gnGlobal_007C8C84 = 0;
    }

    gnGlobal_007C8C8C = 0;
}

#include "gen/data/Source/D2Client/Unknown_004DF4B0.inc"
struct D2UnitStrc;

// 0x004E06A0
void __fastcall sub_004E06A0_FreeModules(D2ClientModuleListStrc* pList)
{
    if (!pList->pBase)
        return;
    unsigned char* pNames = (unsigned char*)pList->pBase + *(unsigned int*)((unsigned char*)pList->pBase + 0x1C);
    void* (__stdcall *pGetModuleHandleA)(const char*) = GetModuleHandleA;
    while (pList->nModuleCount > 0)
    {
        pList->nModuleCount--;
        const char* szName = (const char*)((unsigned char*)pList->pBase + *(unsigned int*)(pNames + pList->nModuleCount * 8));
        FreeLibrary(pGetModuleHandleA(szName));
    }
    VirtualFree(pList->pBase, 0, 0x8000);
    pList->pBase = 0;
    pList->pUnknown04 = 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004E0A30
int __fastcall sub_004E0A30_CltDoClearSeqSpeed(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->dwSeqSpeed = 0;
    return 1;
}

// 0x004E0BD0
int __fastcall sub_004E0BD0_CltStartClearCollision(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~0x0E;
    }

    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), 5, 0x1000);
    return 1;
}

// 0x004E0EB0
int __fastcall sub_004E0EB0_CltStartPathToTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_004648F0_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    PATH_SetNewDistance(pPath, 5);
    PATH_SetType(pPath, 2);
    D2Common_10142(pPath, pUnit, 0);
    if (PATH_GetNumberOfPathPoints(pPath) <= 0)
    {
        PATH_SetType(pPath, 1);
        D2Common_10142(pPath, pUnit, 0);
        if (PATH_GetNumberOfPathPoints(pPath) <= 0)
        {
            return 0;
        }
    }

    SKILLS_SetFlags(pSkill, 1);
    return 1;
}

// 0x004E0C90
int __fastcall sub_004E0C90(D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2UnitStrc* target = sub_004648F0_GetPathTargetUnit(unit);
    if (!target) return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill) return 0;
    SKILLS_SetParam1(skill, UNITS_GetUnitXPosition(target));
    sub_006445A0(skill, UNITS_GetUnitYPosition(target));
    return SUCCESS_VALUE;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_004E1400_SetMissileFrames(D2UnitStrc* pUnit, int nSkillLevel, D2UnitStrc* pMissile, int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        return 0;
    }

    int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc2, nSkillId, nSkillLevel);
    if (nFrames <= 0)
    {
        nFrames = pMissilesTxt->nRange + nSkillLevel - 1;
    }

    nFrames = nFrames > 1 ? (nFrames < 0xFF ? nFrames : 0xFF) : 1;

    PATH_SetNewDistance(pMissile->pDynamicPath, nFrames);
    sub_00621780_SetMissileArg(pMissile, (pMissilesTxt->nAnimLen << 8) / nFrames);
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);
    return 1;
}

// 0x004E14D0
static D2UnitStrc* __stdcall sub_004E14D0_CreateSkillMissile(const int* pVelocityTable, int nTargetX, int nTargetY, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x25;
    tMissile.pOwner = pUnit;
    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) > 0)
    {
        tMissile.dwFlags = 0x4025;
    }

    tMissile.nMissile = nMissileId;
    tMissile.nX = CLIENTS_GetUnitX(pUnit);
    tMissile.nY = CLIENTS_GetUnitY(pUnit);
    tMissile.nTargetX = nTargetX;
    tMissile.nTargetY = nTargetY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;

    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxt)
    {
        return 0;
    }

    tMissile.nVelocity = pMissilesTxt->nVel + pVelocityTable[SEED_RollLimitedRandomNumber(&pUnit->pSeed, 5)];
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissile);
    if (!pMissile)
    {
        return 0;
    }

    sub_004E1400_SetMissileFrames(pUnit, nSkillLevel, pMissile, nSkillId);
    return pMissile;
}

// 0x004E1620
int __fastcall sub_004E1620_SkillCltDoMissilePair(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissileA = pSkillsTxt->wCltMissileA;
    if (nMissileA < 0 || nMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    for (int nCount = 2; nCount; --nCount)
    {
        int nMissile = nMissileA;
        if (nMissileB > 0 && (SEED_RollRandomNumber(&pUnit->pSeed) & 1))
        {
            nMissile = nMissileB;
        }

        sub_004E14D0_CreateSkillMissile(gaMissileVelocityPair_006DBAA0, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    }

    return 1;
}

// 0x004E1A20
int __fastcall sub_004E1A20_SkillCltDoChargedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc1, nSkillId, nSkillLevel);
    const int nParam = SKILLS_GetParam1(pSkill) + 1;
    if (nParam < nMax)
    {
        SKILLS_SetParam1(pSkill, nParam);
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    sub_004E14D0_CreateSkillMissile(gaMissileVelocityCharged_006DBB38, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    sub_004E1970_SetInfernoFrames(pSkillsTxt, pUnit);
    return 1;
}

static D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x004E1970
void __fastcall sub_004E1970_SetInfernoFrames(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_J03(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            if (pSkillsTxtRecord->nMonAnim == 0xE)
            {
                UNITS_SetAnimationFrame(pUnit, pMonStats2TxtRecord->nInfernoAnim - 1);
                pUnit->dwFrameCountPrecise = (pMonStats2TxtRecord->nInfernoAnim + 1) << 8;
            }
            else
            {
                pUnit->nSeqCurrentFramePrecise = (pMonStats2TxtRecord->nInfernoAnim - 1) << 8;
            }
        }

        return;
    }

    UNITS_SetAnimationFrame(pUnit, 8);
    pUnit->dwFrameCountPrecise = 0x500;
}
