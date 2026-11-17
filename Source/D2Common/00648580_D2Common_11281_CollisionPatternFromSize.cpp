struct D2DynamicPathStrc
{
    char unk0x00[0x38];
    int unk0x38;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const int gaCollisionPatternsFromSize[4];                                                            // 0x006EB3DC
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster);                                                  // 0x0063E860
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2);                                                    // 0x00650350
int __stdcall D2Common_10227(D2UnitStrc* pUnit);                                                            // 0x00650540

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define COLLISION_UNIT_SIZE_COUNT 4
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1
#define COLLISION_PATTERN_BIG_UNIT_PRESENCE 2
#define COLLISION_PATTERN_SMALL_PET_PRESENCE 3
#define COLLISION_PATTERN_BIG_PET_PRESENCE 4
#define MONSTATSFLAGINDEX_INTERACT 9
#define UNITFLAG_ISASYNC 0x00200000
#define UNITFLAGEX_UNK_PATH_RELATED 0x00002000

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00648580
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize)
{
    if (nSize < 0 || nSize >= COLLISION_UNIT_SIZE_COUNT)
    {
        return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
    }

    int nCollisionPattern = gaCollisionPatternsFromSize[nSize];
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && MONSTERS_CanBeInTown(pUnit) && !sub_00457490_CheckMonStatsFlag(pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT))
    {
        switch (nCollisionPattern)
        {
        case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
            break;
        case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
            break;
        }
    }

    return nCollisionPattern;
}

// 0x00649210
void __stdcall D2Common_10213(D2UnitStrc* pUnit)
{
    if (pUnit && !UNIT_HasFlag(pUnit, UNITFLAG_ISASYNC) && UNIT_HasFlagEx(pUnit, UNITFLAGEX_UNK_PATH_RELATED))
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        D2_ASSERT(pDynamicPath, 2485);

        ++pDynamicPath->unk0x38;
        if (pDynamicPath->unk0x38 > 1)
        {
            pDynamicPath->unk0x38 = 0;
            if (!D2Common_10227(pUnit))
            {
                if (D2Common_10236(pUnit, PATH_GetTargetUnit(pUnit->pDynamicPath) != 0))
                {
                    UNITS_ChangeAnimMode(pUnit, 2);
                }
            }
        }
    }
}
