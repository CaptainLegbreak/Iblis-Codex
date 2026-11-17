struct D2SkillStrc;
struct D2SkillListStrc;
struct D2DynamicPathStrc;
struct T00620190;
struct D2BitBufferStrc;
struct D2WaypointDataStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
};

struct D2ObjectsTxt
{
    char unk0x00[288];
    unsigned char nHasCollision[8];
    char unk0x128[63];
    unsigned char nSubClass;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};

struct D2ItemsTxt
{
    char unk0x00[304];
    unsigned char nBelt;
};

struct D2PlayerDataStrc
{
    char szName[16];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
    char unk0x28[104];
    int nWeaponGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2PlayerDataStrc* pPlayerData;
        D2ObjectDataStrc* pObjectData;
    };
    char unk0x18[20];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    T00620190* pAnimSeq;
    char unk0x34[12];
    int dwSeqMode;
    char unk0x44[100];
    D2SkillListStrc* pSkills;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2SkillStrc* __fastcall SKILLS_GetLeftSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643930
D2SkillStrc* __fastcall SKILLS_GetRightSkillFromSkillList(D2SkillListStrc* pSkillList);                     // 0x00643960
D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x006439A0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2);                                    // 0x0064FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord);                       // 0x0065C490
void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData);                       // 0x00660FD0
void __fastcall sub_0066A260_PlayerDataFreeHook(D2UnitStrc* pUnit);                                        // 0x0066A260

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define TRUE 1
#define FALSE 0
#define OBJSUBCLASS_SHRINE 0x01

inline T00620190* UNITS_GetAnimSeq(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pAnimSeq;
    }

    return 0;
}

inline int UNITS_GetPositionX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetPositionY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00620190
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1601);
    return SKILLS_GetLeftSkillFromSkillList(pUnit->pSkills);
}

// 0x006201D0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1610);
    return SKILLS_GetRightSkillFromSkillList(pUnit->pSkills);
}

// 0x00620250
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1628);
    return SKILLS_GetUsedSkillFromSkillList(pUnit->pSkills);
}

// 0x00620C10
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(pUnit, 2220);
    D2_ASSERT((pUnit->dwUnitType == UNIT_PLAYER) || (pUnit->dwUnitType == UNIT_MONSTER) || (pUnit->dwUnitType == UNIT_MISSILE), 2222);
    PATH_SetTargetUnit(pUnit->pDynamicPath, pTargetUnit);
}

// 0x00621190
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (UNITS_GetAnimSeq(pUnit))
    {
        return pUnit->dwSeqMode;
    }

    return pUnit->dwAnimMode;
}

// 0x006219C0
int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt->nHasCollision[pUnit->dwAnimMode];
    }

    return TRUE;
}

// 0x00621B00
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT && pUnit->pObjectData->pObjectTxt->nSubClass & OBJSUBCLASS_SHRINE)
    {
        return TRUE;
    }

    return FALSE;
}

// 0x00621DC0
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY)
{
    const int nX = UNITS_GetPositionX(pUnit);
    const int nY = UNITS_GetPositionY(pUnit);

    return PATH_ComputeDirection(nX, nY, nNewX, nNewY);
}

// 0x00621ED0
int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit)
{
    D2_ASSERT((pUnit ? pUnit->dwUnitType : UNIT_INVALID) == UNIT_ITEM, 3872);

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3876);

    return pItemsTxtRecord->nBelt;
}

// 0x00622060
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pPlayer, 3947);
    D2_ASSERT(pPlayer->pPlayerData, 3949);

    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_FreeRecord(pMemPool, pPlayer->pPlayerData->pQuestData[i]);
        WAYPOINTS_FreeWaypointData(pMemPool, pPlayer->pPlayerData->pWaypointData[i]);
    }

    sub_0066A260_PlayerDataFreeHook(pPlayer);

    FOG_FreeServerMemory(pMemPool, pPlayer->pPlayerData, ".\\UNITS\\Units.cpp", 3958, 0);
    pPlayer->pPlayerData = 0;
}

// 0x00623410
int __stdcall UNITS_GetWeaponGUID(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4020);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4022);
    D2_ASSERT(pUnit->pPlayerData, 5335);

    return pUnit->pPlayerData->nWeaponGUID;
}
