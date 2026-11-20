#include "D2Client.h"
#include "D2Structs.h"

struct D2SkillsTxt;
struct D2SkillDescTxt;
struct D2SeedStrc;

typedef unsigned short Unicode;



struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    char unk0x0EC[0x28];
    int dwCltCalc[3];
    unsigned char unk_120[0x74];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    char unk0x00[0x0E];
    unsigned short wStrAlt;
    char unk0x10[0x110];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    unsigned char unk_B70[0x1C];
    D2SkillDescTxt* pSkillDescTxt;
    void* pSkillDescLinker;
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall sub_004BA840(void* pUnitSfx); // 0x004BA840
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

typedef char D2SkillsTxt_size_check[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

extern const int gnDirOffsetY_006DAE88[8]; // 0x006DAE88
extern const int gnDirOffsetX_006DAEA8[8]; // 0x006DAEA8
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

// 0x004C9320
int __fastcall sub_004C9320_SkillCltDoCollide(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill || !pDynamicPath)
        return 0;

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    const int bPlayer = nUnitType == 0;
    const int nMask = bPlayer ? 0x80 : 0x100;
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nFlags = SKILLS_GetFlags(pSkill);
    if ((nFlags & 3) == 3)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nMask);
        PATH_SetFootprintCollisionMask(pDynamicPath, nMask);
        PATH_SetMoveTestCollisionMask(pDynamicPath, bPlayer ? 0x1C09 : 0x3C01);
        SKILLS_SetFlags(pSkill, 0);
        sub_004BA840(sub_004CA900_FindUnitSfxInRange(pUnit, 0x9E3));
    }
    else if (nFlags & 1)
    {
        UNITS_SetAnimationFrame(pUnit, 3);
        pUnit->dwFrameCountPrecise = 0x500;
    }
    return 1;
}

// 0x004E6E30
static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }

    if (!pSkillDescTxtRecord)
        return 0x1506;

    return pSkillDescTxtRecord->wStrAlt;
}

void __fastcall sub_J15_Emit_004E6E30(Unicode* pBuffer, D2SkillStrc* pSkill)
{
    sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(sub_004E6E30_GetSkillDescAltStr(SKILLS_GetSkillIdFromSkill(pSkill, 0, 0x700))));
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C9490
int __fastcall sub_004C9490_MissileAroundUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!sub_004648F0_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    int nDirection;
    if (PATH_GetVelocity(pUnit->pDynamicPath))
    {
        nDirection = UNITS_GetDirection(pUnit) >> 3;
    }
    else
    {
        nDirection = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 8);
    }

    nDirection = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + (nDirection + 4) % 8 - 1) & 7;
    const int nX = CLIENTS_GetUnitX(pUnit) + gnDirOffsetX_006DAEA8[nDirection];
    const int nY = CLIENTS_GetUnitY(pUnit) + gnDirOffsetY_006DAE88[nDirection];
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nBonus > 0)
    {
        nMissile += SEED_RollLimitedRandomNumber(&pUnit->pSeed, nBonus);
    }

    sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004C9320.inc"
