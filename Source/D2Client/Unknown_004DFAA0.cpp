#include "D2Client.h"
#include "D2Path.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SlotStrc;
union D2SeedStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2SlotStrc gaSlots[16]; // 0x007C8A78
extern int gbSoundSystemInit; // 0x007C8C78
void __fastcall sub_00514CA0(int nMode); // 0x00514CA0
D2SoundStrc* __fastcall sub_00515530(int nType, int nArg); // 0x00515530
void __cdecl sub_004DFA60(); // 0x004DFA60

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

int gnSoundRestartArg; // 0x007C8A70

// 0x004DFAA0
static int sub_004DFAA0_InitSoundChannels(int nMode)
{
// build: symbol ?D2SOUND_GetDirectSound@* 0x00513B50
    if (!D2SOUND_GetDirectSound())
        return 0;

    D2_ASSERT(!gbSoundSystemInit, 204);

    for (int i = 0; i < 16; ++i)
    {
        gaSlots[i].nType = 0;
        if (i < 4)
            gaSlots[i].nType = 1;
        else if (nMode == 1)
            gaSlots[i].nType = 2;
        else
            gaSlots[i].nType = nMode == 2 ? 6 : 0;

        gaSlots[i].pSound = sub_00515530(gaSlots[i].nType, gnSoundRestartArg);
        if (!gaSlots[i].pSound)
        {
            sub_004DFA60();
            return 0;
        }
    }

    sub_004DF6C0(0);
    gbSoundSystemInit = 1;
    return 1;
}

// 0x004E0000
int __fastcall sub_004E0000_SetSoundMode(int nMode)
{
// build: symbol ?D2SOUND_IsPositionalSoundEnabled@* 0x00513B60
    if (nMode == 1 && !D2SOUND_IsPositionalSoundEnabled())
        return 0;

    if (nMode == 2 && !sub_00513B70_IsSoundEnvironEnabled())
        return 0;

    sub_004DFA60();
    if (!sub_004DFAA0_InitSoundChannels(nMode))
        return 0;

    if (sub_00514C90_GetSoundMode() != nMode)
        sub_00514CA0(nMode);

    return 1;
}

// 0x004E0050
void __fastcall sub_004E0050_RestartSound(int nArg)
{
    gnSoundRestartArg = nArg;
    if (!sub_004E0000_SetSoundMode(sub_00514C90_GetSoundMode()))
        sub_004E0000_SetSoundMode(0);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x004E12D0
int __fastcall sub_004E12D0_SkillClearTargetFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~0xEu;
    }
    return 1;
}

// 0x004E1720
int __fastcall sub_004E1720_SkillSetTargetFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0xEu;
    }
    return 1;
}

// 0x004E1740
int __fastcall sub_004E1740_SkillNeedTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlagEx &= ~0x40000u;
    }
    return 1;
}

// 0x004E1C80
void __fastcall sub_004E1C80_CltMissileInitDiabWall(D2UnitStrc* pMissile, int nInitSeed)
{
    if (pMissile)
    {
        int nFrames = MISSILE_GetTotalFrames(pMissile);
        if (nFrames >= 78)
        {
            nFrames = 77;
            MISSILE_SetTotalFrames(pMissile, 77);
            MISSILE_SetCurrentFrame(pMissile, 77);
        }

        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        SEED_InitLowSeed(&pMissile->pSeed, nInitSeed + D2COMMON_10175_PathGetFirstPointX(pPath));

        if ((int)(SEED_RollRandomNumber(&pMissile->pSeed) % 100) >= 20)
        {
            PATH_SetType(pPath, 10);
            PATH_SetNewDistance(pPath, nFrames);
            D2Common_10142(pPath, pMissile, 0);
        }
    }
}

// 0x004E1E30
int __fastcall sub_004E1E30_SkillClearSkillFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0);
    return 1;
}
