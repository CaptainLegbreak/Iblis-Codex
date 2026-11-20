#include "D2Structs.h"
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct D2DynamicPathStrc;

struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    unsigned int dwSkillMode;
    unsigned int dwFlags;
    unsigned int unk0x10[2];
    unsigned int nXpos;
    unsigned int nYpos;
    unsigned int nPar3;
    unsigned int nPar4;
    int nSkillLevel;
    unsigned int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

// build: context SKILLS_GetSkill
static __forceinline D2SkillStrc* SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                return pSkill;
            }
        }
    }

    return 0;
}

// 0x00645390
void __stdcall D2Common_11015(D2UnitStrc* pUnit, int a2, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
    int nPosition;
    if (a2)
    {
        const int nType = pUnit->dwUnitType;
        const int nId = pUnit->dwUnitId;
        _ReadWriteBarrier();
        nPosition = (nType << 16) + nId;
    }
    else
    {
        const int nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        const int nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
        nPosition = nX + 3 * nY;
    }

    D2_ASSERT(pSkill, 0xA52);

    if (pSkill->nXpos == nPosition)
    {
        const unsigned int nYpos = pSkill->nYpos + 7;
        pSkill->nXpos = nPosition;
        _ReadWriteBarrier();
        pSkill->nYpos = nYpos;
    }
    else
    {
        _ReadWriteBarrier();
        pSkill->nYpos = nPosition;
        pSkill->nXpos = nPosition;
    }

    SEED_InitLowSeed(&pUnit->pSeed, pSkill->nYpos);
}
