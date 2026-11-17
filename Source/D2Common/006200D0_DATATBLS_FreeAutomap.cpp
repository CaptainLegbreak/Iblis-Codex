struct D2SkillsTxt;
struct D2AutomapShortStrc;
struct D2DrlgStrc;
struct D2LvlMazeTxt;

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    int dwSkillMode;
    int dwFlags;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    char unk0x0C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2LvlMazeTxt* pMaze;
    char unk0x18[0x19C];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0xC];
    D2SeedStrc pSeed;
    void* pBuild;
    int nLevelId;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040

extern D2AutomapShortStrc* gpAutomap_0096CA28;                                                              // 0x0096CA28

// 0x006200D0
void __fastcall DATATBLS_FreeAutomap()
{
    if (gpAutomap_0096CA28)
    {
        FOG_FreeServerMemory(0, gpAutomap_0096CA28, ".\\DATATBLS\\LvlTbls.cpp", 0x551, 0);
    }

    gpAutomap_0096CA28 = 0;
}

// 0x00644140
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->pSkillsTxt;
}

// 0x006446A0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        return pSkill->dwFlags;
    }

    return 0;
}

// 0x00673FE0
void __fastcall DRLGMAZE_ResetMazeRecord(D2DrlgLevelStrc* pLevel, int bKeepMazeRecord)
{
    if (!bKeepMazeRecord)
    {
        pLevel->pMaze = 0;
    }
}

// 0x00673FF0
int __fastcall sub_00673FF0_GetVisFlagToLevel(D2DrlgLevelStrc* pLevel, D2DrlgLevelStrc* pOtherLevel)
{
    int* pLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
    int i = 0;
    for (; i < 8; ++i)
    {
        if (pLevelIds[i] == pOtherLevel->nLevelId)
        {
            break;
        }
    }

    if (i == 8)
    {
        return 0;
    }

    return 1 << (i + 4);
}

static __forceinline unsigned int MAZE_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int MAZE_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return MAZE_RollRandomNumberInline(pSeed) % nMax;
    }

    return MAZE_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x006711A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel)
{
    int i = MAZE_RollLimitedRandomNumberInline(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    for (; i; --i)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }

    return pDrlgRoom;
}
