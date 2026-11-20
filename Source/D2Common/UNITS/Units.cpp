#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#define FP16_SHIFT 16
#define OBJSUBCLASS_SHRINE 0x01
#define MONSTER_SHADOWWARRIOR 0x1A1
#define MONSTER_SHADOWMASTER 0x1A2
#define STAT_HITPOINTS 6
#define STAT_LEVEL 0x0C
#define MONSTER_FIRST_EXPANSION 410
#define SKILLSFLAGINDEX_USEATTACKRATE 3
#define MONSTATS2FLAGINDEX_SOFT 0xC
struct D2SkillListStrc;
struct D2WaypointDataStrc;
struct D2PlayerDataStrc;
struct D2MonsterDataStrc;
struct D2InventoryStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2ObjectsTxt;
struct D2ObjectDataStrc;
struct D2ItemsTxt;
struct D2SkillsTxt;
struct D2AnimUnkStrc;
struct D2ValueRecordStrc;
struct D2MonStats2Txt;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
    int dwUnk0x14;
    int dwUnk0x18;
    unsigned char nDirection;
    unsigned char unk_1D[0x3];
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszUnitsSourceFile; // 0x006E8E10
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit); // 0x00626D10
void __stdcall SKILLS_FreeSkillList(D2UnitStrc* pUnit); // 0x00643A60
int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* pPath); // 0x00648940
int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* pPath); // 0x00648970
int __stdcall PATH_GetClientCoordX(D2DynamicPathStrc* pPath); // 0x006489C0
int __stdcall PATH_GetClientCoordY(D2DynamicPathStrc* pPath); // 0x006489D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX); // 0x006489E0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY); // 0x006489F0
void __stdcall PATH_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pRoom); // 0x00648A90
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID); // 0x00648BB0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

struct D2ObjectsTxt
{
    unsigned char unk_00[0xD8];
    int dwFrameCnt[8];
    unsigned char unk_F8[0x28];
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

D2SkillStrc* __fastcall SKILLS_GetLeftSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643930
D2SkillStrc* __fastcall SKILLS_GetRightSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643960
D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x006439A0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490
void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData); // 0x00660FD0
void __fastcall sub_0066A260_PlayerDataFreeHook(D2UnitStrc* pUnit); // 0x0066A260



int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __fastcall SKILLS_SetUsedSkillInSkillList(D2SkillListStrc* pSkillList, D2SkillStrc* pUsedSkill); // 0x00643990
extern struct D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2SkillsTxt
{
    char unk0x00[6];
    unsigned char dwFlags[8];
    unsigned char unk_0E[0x15A];
    unsigned char nWeapSel;
};

struct D2AnimUnkStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2AnimUnkStrc gaPlayerModesAnimModulators[]; // 0x006E8A00
extern D2AnimUnkStrc gaMonModesAnimModulators[]; // 0x006E8B90
extern D2AnimUnkStrc gaMonModesAnimModulatorsExpansion[]; // 0x006E8CD0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

struct Unit { int type; int classId; void* pMemoryPool; int id; int mode; void* monsterData; };

extern void __stdcall sub_00626D10_FreeStatList(Unit*);
extern void __stdcall sub_00643A60_FreeSkillList(Unit*);
extern void __fastcall sub_0040B480_FreePool(void*,void*,const char*,int,int);

struct D2ValueRecordStrc
{
    int nValues[5];
};

extern const D2ValueRecordStrc gTable_006E8B90[]; // 0x006E8B90
extern const D2ValueRecordStrc gTable_006E8CD0[]; // 0x006E8CD0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwState); // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);

struct D2MonStats2Txt
{
    char unknown0[14];
    unsigned char meleeRange;
    unsigned char unk_0F[0x5];
    unsigned char nHitClass;
};
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc*, D2UnitStrc**, int*, int*); // 0x0063C9B0
unsigned char __stdcall ITEMS_GetMeleeRange(D2UnitStrc*); // 0x006288D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648810
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* pItem); // 0x0062A180

// 0x00620100
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 955);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        return pUnit->pStaticPath->nDirection;

    default:
        return PATH_GetDirection(pUnit->pDynamicPath);
    }
}

// 0x00620150
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1592);
    return SKILLS_GetFirstSkillFromSkillList(hUnit->pSkills);
}

// 0x00620360
void __fastcall sub_00620360(D2UnitStrc* pUnit, int nX, int nY, int nUnk0x14, int nUnk0x18)
{
    D2_ASSERT(pUnit, 1711);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 1713);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->tGameCoords.nX = nX;
    pStaticPath->tGameCoords.nY = nY;
    pStaticPath->dwUnk0x14 = nUnk0x14;
    pStaticPath->dwUnk0x18 = nUnk0x18;
}

// 0x006203B0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1732);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->tGameCoords.nX << FP16_SHIFT;

    default:
        return PATH_GetPrecisionX(ptUnit->pDynamicPath);
    }
}

// 0x00620410
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1754);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->tGameCoords.nY << FP16_SHIFT;

    default:
        return PATH_GetPrecisionY(ptUnit->pDynamicPath);
    }
}

// 0x00620470
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* ptUnit, int nX)
{
    D2_ASSERT(ptUnit, 1775);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        ptUnit->pStaticPath->tGameCoords.nX = nX;
        break;

    default:
        D2_ASSERT(0, 1786);
    }
}

// 0x006204C0
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* ptUnit, int nY)
{
    D2_ASSERT(ptUnit, 1798);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        ptUnit->pStaticPath->tGameCoords.nY = nY;
        break;

    default:
        D2_ASSERT(0, 1809);
    }
}

// 0x00620650
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1909);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->dwClientCoordX;

    default:
        return PATH_GetClientCoordX(ptUnit->pDynamicPath);
    }
}

// 0x006206B0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1930);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->dwClientCoordY;

    default:
        return PATH_GetClientCoordY(ptUnit->pDynamicPath);
    }
}

// 0x00620710
int __stdcall UNITS_GetAbsoluteXDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nX1;
    int nX2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX1 = pUnit1->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nX1 = PATH_GetXPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nX1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX2 = pUnit2->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nX2 = PATH_GetXPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nX2 = 0;
        }
        break;
    }

    int nDistance = nX1 - nX2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x00620780
int __stdcall UNITS_GetAbsoluteYDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nY1;
    int nY2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY1 = pUnit1->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nY1 = PATH_GetYPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nY1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY2 = pUnit2->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nY2 = PATH_GetYPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nY2 = 0;
        }
        break;
    }

    int nDistance = nY1 - nY2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x006207F0
void __stdcall UNITS_SetTargetX(D2UnitStrc* ptUnit, int nTargetX)
{
    D2_ASSERT(ptUnit, 1970);

    PATH_SetClientCoordX(ptUnit->pDynamicPath, nTargetX);
}

// 0x00620830
void __stdcall UNITS_SetTargetY(D2UnitStrc* ptUnit, int nTargetY)
{
    D2_ASSERT(ptUnit, 1982);

    PATH_SetClientCoordY(ptUnit->pDynamicPath, nTargetY);
}

// 0x00620870
void __stdcall UNITS_GetCoords(D2UnitStrc* ptUnit, D2CoordStrc* pCoord)
{
    D2_ASSERT(ptUnit, 1994);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = ptUnit->pStaticPath;
            pCoord->nX = pStaticPath->tGameCoords.nX;
            pCoord->nY = pStaticPath->tGameCoords.nY;
        }
        break;

    default:
        if (ptUnit->pDynamicPath)
        {
            pCoord->nX = PATH_GetXPosition(ptUnit->pDynamicPath);
            pCoord->nY = PATH_GetYPosition(ptUnit->pDynamicPath);
        }
        else
        {
            pCoord->nX = 0;
            pCoord->nY = 0;
        }
        break;
    }
}

// 0x00620900
void __stdcall UNITS_GetClientCoords(D2UnitStrc* ptUnit, D2CoordStrc* pClientCoords)
{
    D2_ASSERT(ptUnit, 2023);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = ptUnit->pStaticPath;
            pClientCoords->nX = pStaticPath->dwClientCoordX;
            pClientCoords->nY = pStaticPath->dwClientCoordY;
        }
        break;

    default:
        pClientCoords->nX = PATH_GetClientCoordX(ptUnit->pDynamicPath);
        pClientCoords->nY = PATH_GetClientCoordY(ptUnit->pDynamicPath);
        break;
    }
}

// 0x00620980
void __fastcall sub_00620980(D2UnitStrc* pUnit, int nClientX, int nClientY)
{
    D2_ASSERT(pUnit, 2047);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 2049);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->dwClientCoordX = nClientX;
    pStaticPath->dwClientCoordY = nClientY;
}

// 0x00620B50
void __stdcall UNITS_ResetRoom(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 2173);

    switch (hUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        hUnit->pStaticPath->pRoom = 0;
        break;

    default:
        if (hUnit->pDynamicPath)
        {
            PATH_SetRoom(hUnit->pDynamicPath, 0);
        }
        break;
    }
}

// 0x00620C70
int __stdcall UNITS_GetTargetTypeFromDynamicUnit(D2UnitStrc* ptUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(ptUnit, 2233);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2235);

    PATH_GetTargetTypeAndGUID(ptUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitType;
}

// 0x00620CD0
int __stdcall UNITS_GetTargetGUIDFromDynamicUnit(D2UnitStrc* ptUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(ptUnit, 2250);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2252);

    PATH_GetTargetTypeAndGUID(ptUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitGUID;
}

// 0x00620D30
void __stdcall UNITS_SetTargetUnitForPlayerOrMonster(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptUnit, 2268);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER), 2270);

    PATH_SetTargetUnit(ptUnit->pDynamicPath, pTargetUnit);
}

inline D2AnimSeqTxt* UNITS_GetAnimSeq(D2UnitStrc* pUnit)
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
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1601);
    return SKILLS_GetLeftSkillFromSkillList(hUnit->pSkills);
}

// 0x006201D0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1610);
    return SKILLS_GetRightSkillFromSkillList(hUnit->pSkills);
}

// 0x00620250
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1628);
    return SKILLS_GetUsedSkillFromSkillList(hUnit->pSkills);
}

// 0x00620C10
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptUnit, 2220);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2222);
    PATH_SetTargetUnit(ptUnit->pDynamicPath, pTargetUnit);
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
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3947);
    D2_ASSERT(ptUnit->pPlayerData, 3949);

    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_FreeRecord(pMemPool, ptUnit->pPlayerData->pQuestData[i]);
        WAYPOINTS_FreeWaypointData(pMemPool, ptUnit->pPlayerData->pWaypointData[i]);
    }

    sub_0066A260_PlayerDataFreeHook(ptUnit);

    FOG_FreeServerMemory(pMemPool, ptUnit->pPlayerData, ".\\UNITS\\Units.cpp", 3958, 0);
    ptUnit->pPlayerData = 0;
}

// 0x00623410
int __stdcall UNITS_GetWeaponGUID(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 4020);
    D2_ASSERT(ptUnit->dwUnitType == UNIT_PLAYER, 4022);
    D2_ASSERT(ptUnit->pPlayerData, 5335);

    return ptUnit->pPlayerData->nWeaponGUID;
}

// 0x00620210
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* hUnit, D2SkillStrc* pUsedSkill)
{
    D2_ASSERT(hUnit, 1619);
    SKILLS_SetUsedSkillInSkillList(hUnit->pSkills, pUsedSkill);
}

// 0x00621F20
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit)
{
    const int nHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    if (const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8)
    {
        return (100 * nHp) / nMaxHp;
    }

    return 0;
}

// 0x006221A0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4020);

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4022);

    return pUnit->pPlayerData;
}

// 0x00622E70
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit)
{
    return 10000 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
}

// 0x006235A0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nClassId)
        {
        case PCLASS_BARBARIAN:
        case PCLASS_ASSASSIN:
            return TRUE;
        }
        return FALSE;

    case UNIT_MONSTER:
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nClassId)
            {
            case MONSTER_SHADOWWARRIOR:
            case MONSTER_SHADOWMASTER:
                return TRUE;
            }
        }
        return FALSE;
    }

    return FALSE;
}

// 0x00620290
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType)
{
    D2UnitStrc* pUnit = (D2UnitStrc*)sub_0040B430(pMemPool, 0xF4, ".\\UNITS\\Units.cpp", 1646, 0);
    memset(pUnit, 0, 0xF4);

    pUnit->dwUnitType = nUnitType;
    pUnit->pMemoryPool = pMemPool;

    switch (nUnitType)
    {
    case UNIT_MONSTER:
        pUnit->pMonsterData = (D2MonsterDataStrc*)sub_0040B430(pMemPool, 0x60, ".\\UNITS\\Units.cpp", 1659, 0);
        memset(pUnit->pMonsterData, 0, 0x60);
        break;
    }

    return pUnit;
}

// 0x00621580
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimUnkStrc* pAnimModeModulators = 0;
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        pAnimModeModulators = &gaPlayerModesAnimModulators[nAnimMode];
        break;

    case UNIT_MONSTER:
        if (nClassId < MONSTER_FIRST_EXPANSION)
            pAnimModeModulators = &gaMonModesAnimModulators[nAnimMode];
        else
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion[nAnimMode];
        break;

    default:
        D2_ASSERT((nUnitType == UNIT_PLAYER) || (nUnitType == UNIT_MONSTER), 3055);
        return FALSE;
    }

    if (pAnimModeModulators->bCanUseAttackRate)
        return TRUE;

    if (!pAnimModeModulators->bCanUseSkillAttackRate)
        return FALSE;

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
        return FALSE;

    return sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 3066))->dwFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_USEATTACKRATE];
}

// 0x00620300
void __stdcall sub_00620300_FreeUnit(Unit* unit)
{
    if (unit) {
        sub_00626D10_FreeStatList(unit);
        sub_00643A60_FreeSkillList(unit);
        unsigned typeDelta=(unsigned)unit->type-1u;
        if (!typeDelta) {
            sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit->monsterData,".\\UNITS\\Units.cpp",0x69a,(int)typeDelta);
        }
        unit->type=6;
        unit->id=-1;
        sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit,".\\UNITS\\Units.cpp",0x6a4,0);
    }
}

// 0x00621420
static const D2ValueRecordStrc* __stdcall sub_00621420_GetRecordForValue(int nIndex, int nValue)
{
    if (nValue < 0x19A)
        return &gTable_006E8B90[nIndex];
    return &gTable_006E8CD0[nIndex];
}

// calling-convention shim (not game code)
int __stdcall sub_K14_EmitGetRecordForValue(int nIndex, int nValue)
{
    return sub_00621420_GetRecordForValue(nIndex, nValue)->nValues[0] + sub_00621420_GetRecordForValue(nIndex + 1, nValue)->nValues[1];
}

#include "gen/data/Source/D2Common/UNITS/Units.inc"

// 0x00621450
static __forceinline int UNITS_IsAnimModeKnockBack(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0x13)
            return 1;
        break;
    case 1:
        if (nAnimMode == 0x0D)
            return 1;
        break;
    }
    return 0;
}

// 0x00621480
static __forceinline int sub_00621480(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0x0F:
        return 1;
    }
    return 0;
}

// 0x00621680
static __forceinline int UNITS_IsAnimModeGetHit(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 4)
            return 1;
        break;
    case 1:
        if (nAnimMode == 3)
            return 1;
        break;
    }
    return 0;
}

int __stdcall sub_M110_Emit_00621450(int nUnitType, int nAnimMode)
{
    if (UNITS_IsAnimModeKnockBack(nUnitType, nAnimMode))
        return 7;
    if (UNITS_IsAnimModeGetHit(nUnitType, nAnimMode))
        return 9;
    return sub_00621480(nAnimMode);
}

// 0x006216B0
static __forceinline int sub_006216B0_IsModeValue(int nMode, int nValue)
{
    switch (nMode)
    {
    case 0:
        if (nValue == 9)
        {
            return 1;
        }
        break;
    case 1:
        if (nValue == 6)
        {
            return 1;
        }
        break;
    }
    return 0;
}

int __fastcall sub_M119_Emit_006216B0(int nMode, int nValue, int nOther)
{
    return sub_006216B0_IsModeValue(nMode, nOther) + nValue;
}

// 0x00621870
void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount)
{
    if (!pUnit)
    {
        *pFrame = 0;
        *pFrameCount = 0;
        return;
    }

    if (pUnit->dwUnitType == 2)
    {
        *pFrame = pUnit->nSeqCurrentFramePrecise;
        *pFrameCount = pUnit->pObjectData->pObjectTxt->dwFrameCnt[pUnit->dwAnimMode];
        return;
    }

    *pFrame = pUnit->nSeqCurrentFramePrecise;
    *pFrameCount = pUnit->dwFrameCountPrecise;
}

static __forceinline int sub_T03_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitType;
}

static __forceinline int sub_T03_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

static __forceinline void* sub_M442_GetMemPool(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->pMemoryPool;
}

// 0x00621C30
static void __stdcall UNITS_StoreOwnerInfo(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    D2StatListStrc* pStatList = 0;

    if (pUnit)
    {
        pUnit->dwOwnerType = nOwnerType;
        pUnit->dwOwnerGUID = nOwnerId;

        if (pUnit->pStatListEx)
        {
            STATES_ToggleState(pUnit, 0x62, 1);
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(sub_M442_GetMemPool(pUnit), 0, 0, sub_T03_GetUnitType(pUnit), sub_T03_GetUnitId(pUnit));
                if (!pStatList)
                    return;

                sub_006252D0(pStatList, 0x62);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, 0x161, nOwnerType, 0);
            STATLIST_SetStatIfListIsValid(pStatList, 0x162, nOwnerId, 0);
        }

        pUnit->dwFlagEx |= 0x400;
    }
}

void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    UNITS_StoreOwnerInfo(pUnit, nOwnerType, nOwnerId);
}

// 0x00621CE0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    D2StatListStrc* pStatList = 0;

    if (pOwner)
    {
        UNITS_StoreOwnerInfo(pUnit, sub_T03_GetUnitType(pOwner), sub_T03_GetUnitId(pOwner));
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwOwnerType = 0;
            pUnit->dwOwnerGUID = 0;

            if (pUnit->pStatListEx)
            {
                STATES_ToggleState(pUnit, 0x62, 0);

                pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }

            pUnit->dwFlagEx &= ~0x400;
        }
    }
}

// 0x00621F60
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_SOFT) != 0;
}

// 0x00622870
int __stdcall sub_00622870_GetMeleeRange(D2UnitStrc* hUnit)
{
    if (!hUnit) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x11be); exit(-1); }
    int range;
    switch (hUnit->dwUnitType) {
    case 1: {
        D2MonStats2Txt* record = UNITS_GetMonStats2TxtRecordFromMonsterId(hUnit->dwClassId);
        if (!record) goto fail;
        range = record->meleeRange;
        if (range == 255) {
            int weaponClass;
            COMPOSIT_GetWeaponClassId(hUnit, hUnit->pInventory, &weaponClass, -1, 1);
            return weaponClass == 6 ? 2 : 0;
        }
        break;
    }
    case 0: {
        D2UnitStrc* weapon;
        int type, flags;
        if (!INVENTORY_GetEquippedWeapon(hUnit->pInventory, &weapon, &type, &flags)) {
fail:
            return 0;
        }
        range = ITEMS_GetMeleeRange(weapon);
        break;
    }
    default:
        goto fail;
    }
    return range;
}

// 0x00623460
extern "C" __declspec(dllexport) int __stdcall sub_00623460(int nUnused) {
    return 2500000;
}

// 0x006238C0
int __stdcall UNITS_GetNewDirection(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 3715);

    const int nX = UNITS_GetPositionX(hUnit);
    if (D2COMMON_10175_PathGetFirstPointX(hUnit->pDynamicPath) == nX)
    {
        const int nY = UNITS_GetPositionY(hUnit);
        if (D2COMMON_10176_PathGetFirstPointY(hUnit->pDynamicPath) == nY)
        {
            return PATH_GetNewDirection(hUnit->pDynamicPath);
        }
    }

    return UNITS_GetDirectionToCoords(hUnit, D2COMMON_10175_PathGetFirstPointX(hUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(hUnit->pDynamicPath));
}

// 0x00623990
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2)
{
    D2UnitStrc* pItem;
    int nBodyLoc;
    int bIsLeftHandItem;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = SKILLS_GetUsedSkillFromSkillList(pUnit->pSkills);
        if (!pSkill)
        {
            return pItem;
        }
        D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (!pSkillsTxtRecord)
        {
            return pItem;
        }

        D2UnitStrc* pWeapon = 0;
        switch (pSkillsTxtRecord->nWeapSel)
        {
        case 1:
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            break;

        case 2:
        {
            const int nFlags = SKILLS_GetFlags(pSkill) & 0x2000;
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            D2UnitStrc* pHandItem = sub_0063C050_GetBodyLocItem(pInventory, 6);
            if (!pWeapon || !ITEMSIsA(pWeapon, 45) || pHandItem && ITEMSIsA(pHandItem, 45) && nFlags)
            {
                pWeapon = pHandItem;
            }
            break;
        }

        case 3:
        {
            const int nFrame = pUnit->dwSeqFrame >> 8;
            int bOther;
            if (sub_00463720_TestUnitFlagEx(pUnit, 0x4000000))
            {
                bOther = nFrame % 2;
            }
            else
            {
                bOther = nFrame > 5;
            }

            if (nFrame && (!a2 || bOther))
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            }
            else
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            }
            break;
        }

        case 4:
            pItem = 0;
            break;

        default:
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            if (!pWeapon || !ITEMSIsA(pWeapon, 45))
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            }
            break;
        }

        if (ITEMSIsA(pWeapon, 45) && sub_0062A4E0_TestItem(pWeapon))
        {
            return pWeapon;
        }
        return pItem;
    }
    return pItem;
}

// 0x00623C20
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == 0)
        {
            if (D2UnitStrc* pItem = D2Common_10434(pUnit, 0))
                return ITEMS_GetHitClassFromItem(pItem);
            else
                return 1;
        }
        else if (pUnit->dwUnitType == 1)
        {
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
                return pMonStats2TxtRecord->nHitClass;
        }
    }
    return 0;
}
