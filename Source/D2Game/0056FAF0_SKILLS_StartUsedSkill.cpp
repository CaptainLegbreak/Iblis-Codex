struct D2GameStrc;
struct D2SkillStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x230];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef char H15_CheckSkillsTxtSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];
typedef char H15_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];
typedef char H15_CheckSkillsCount[(int)&((D2DataTablesStrc*)0)->nSkillsTxtRecordCount == 0xBA0 ? 1 : -1];

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

enum
{
    MONMODE_DEAD = 12,
    UNITFLAG_TARGETABLE = 0x00000002,
    PLRMODE_TOWNNEUTRAL = 5,
    SKILLSFLAGINDEX_INTOWN = 8,
    SKILLSFLAGINDEX_TARGETABLEONLY = 20,
    SKILLSFLAGINDEX_TARGETCORPSE = 24,
    SKILLSFLAGINDEX_TARGETALLY = 26,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
int __fastcall sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5);   // 0x0056F640

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_H15(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int UNIT_HasFlag_H15(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056CC60
static int __stdcall sub_0056CC60_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETABLEONLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETABLEONLY & 7])
    {
        if (!sub_00554200(pGame, pUnit, pTarget) && !SUNIT_CanPetBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId) && !SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId))
        {
            return 0;
        }
    }

    if (!UNIT_HasFlag_H15(pTarget, UNITFLAG_TARGETABLE))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
    else
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7]))
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
        else
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7])
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
    }

    return 1;
}

// 0x0056FAF0
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xBFF);
    if (!sub_0056CC60_CheckUsedSkillTarget(pGame, pUnit, nSkillId))
    {
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
        }
        return 0;
    }

    int nOwnerGUID;
    int nInfoSkillId;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nCharges;
    if (SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, &nInfoSkillId, &nSkillLevel, &nCharges) && !nCharges)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]) && SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTargetUnit, nSkillId))
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]))
    {
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            int nType = UNIT_INVALID;
            if (pUnit)
            {
                nType = pUnit->dwUnitType;
            }
            switch (nType)
            {
            case UNIT_PLAYER:
                sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                break;
            case UNIT_MONSTER:
                return 0;
            }
            return 0;
        }
    }

    const int nResult = sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && !nResult)
    {
        sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
    }
    return nResult;
}
