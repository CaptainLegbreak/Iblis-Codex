struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MonStatsTxt
{
    char unk0x00[0x32];
    short nVelocity;
    short nRun;
    char unk0x36[0x172];
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    unsigned char nRunSpeed;
    char unk0x42[0x82];
};

extern "C" const char gszSkillsBarSourceFile_006DAE58[];                                                    // 0x006DAE58
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId);                               // 0x004833E0

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

// 0x004C85B0
int __fastcall sub_004C85B0_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0x1101);
    PATH_SetMoveTestCollisionMask(pDynamicPath, 0);
    PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, nX, nY);
    PATH_SetType(pDynamicPath, 9);

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int nClassId = pUnit->dwClassId;
    int nVelocity;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nVelocity = pMonStatsTxtRecord->nRun << 8;
    }
    else
    {
        nVelocity = sub_004833E0_GetCharStatsTxtRecord(nClassId)->nRunSpeed << 8;
    }

    PATH_SetVelocity(pDynamicPath, nVelocity, gszSkillsBarSourceFile_006DAE58, 567);
    D2Common_10142(pDynamicPath, pUnit, 0);
    return 1;
}
