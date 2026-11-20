#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct D2MissilesTxt;
struct D2GfxLightStrc;
struct R0052E0F0;
struct R00601DC0;
struct D2MissileStrc;
struct T004013C0;
struct D2PacketUnitRecordStrc;
struct D2AreaScanContextStrc;
struct D2AreaScanFindStrc;
struct D2SkillsTxt;
struct D2MonStats2Txt;
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2ClientSkillArgsStrc;
struct D2PathDirectionStrc;
struct D2StaticPathStrc;
struct D2CollideTypeMaskStrc;
struct D2LobBracketStrc;
struct D2BallisticStrc;
struct D2DrlgCoordsStrc;
struct D2ActiveRoomViewStrc;
struct D2AreaScanStrc;
struct D2StatesTxt;

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[7];
    void (__fastcall* pInitFunc)(D2UnitStrc*, int);
    int pInitArgs;
};

struct T004013C0
{
    char unk0x00[0x0C];
    unsigned int nTotalMemory;
};

T004013C0* __cdecl sub_00407360_GetSystemInfo(); // 0x00407360
void __fastcall sub_00481840_SetCacheMax(unsigned int nSize); // 0x00481840
void __stdcall sub_005FE120_InitCelPool(void* pMemPool, int nArg); // 0x005FE120
void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40
void __fastcall sub_00470200_InitGfxTables(int nSize); // 0x00470200
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



D2UnitStrc* __fastcall sub_004C52E0(D2UnitStrc* pUnit, int* pTargetX, int* pTargetY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

#pragma pack(push, 1)
struct D2PacketUnitRecordStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitId;
};

#pragma pack(pop)
struct D2AreaScanContextStrc
{
    D2UnitStrc* pSource;
    int nHits;
    void* pArg;
    int nRangeSquared;
};

struct D2AreaScanFindStrc
{
    D2UnitStrc* pFirst;
    unsigned int nBest;
    D2UnitStrc* pSecond;
    unsigned int nArgA;
    unsigned int nArgB;
    int nOut;
};

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem); // 0x004C2180
int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit); // 0x004C54F0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0


struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    unsigned char nCharClass;
    char unk0x00D[0xE8 - 0x0D];
    short wAuraFunc;
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    unsigned char unk_F0[0x2];
    short wStartFunc;
    char unk0x0F4[0x08];
    short wStartSound;
    short wStartSoundClass;
    char unk0x100[0x06];
    short wCastOverlay;
    char unk0x108[0x1A];
    short wItemStartSound;
    short wItemCastOverlay;
    unsigned char unk_126[0x22];
    int dwParam[8];
    unsigned char unk_168[0x27];
    unsigned char nLineOfSight;
    char unk0x190[0x23C - 0x190];
};

struct D2MonStats2Txt
{
    unsigned int dwId;
    unsigned char nFlags[4];
    unsigned char unk_08[0x3];
    char nType;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
int __fastcall sub_004CA060(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x004CA060
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_00471EC0_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay); // 0x00471EC0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit); // 0x00621F60
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    union
    {
        unsigned char nMissileFlags[4];
        unsigned char nFlags[4];
    };
    char unk0x08[0x30];
    int dwParam[5];
    unsigned char unk_4C[0xE4];
    unsigned char nLight;
    unsigned char nFlicker;
    unsigned char nRGB[3];
    unsigned char unk_135[0x4E];
    unsigned char nCollideType;
    unsigned char nCollision;
    char unk0x185[0x05];
    unsigned char nSize;
    char unk0x18B[0x19];
};

struct D2AnimSeqTxt
{
    unsigned short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern int gaLevelVisited_007C78B8[]; // 0x007C78B8
extern int gnGlobal_007C88B8; // 0x007C88B8
extern int gnGlobal_007C88BC; // 0x007C88BC
extern int gnGlobal_007C88C0; // 0x007C88C0
extern int gnGlobal_007C88C4; // 0x007C88C4
extern int gnGlobal_007C88C8; // 0x007C88C8
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius); // 0x00474290
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2); // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource); // 0x004743D0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId); // 0x00479150
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __fastcall sub_004C6680_SkillDo(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6680
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __fastcall sub_004C7890(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004C7890
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall sub_00622870_GetMeleeRange(D2UnitStrc* pUnit); // 0x00622870
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall sub_004BA840(void* pUnitSfx); // 0x004BA840
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
    unsigned int dwCode;
    char unk0x014[0x1A8 - 0x14];
};

typedef int (__fastcall* CLIENTSKILLSTARTFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern CLIENTSKILLSTARTFN gpfnClientSkillStartFuncs_00727A90[]; // 0x00727A90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA4C0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, D2PathDirectionStrc tDirection); // 0x00648820
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0


struct D2CollideTypeMaskStrc
{
    int nCollisionMask;
    int unk0x04;
};

struct D2LobBracketStrc
{
    int nMaxDistance;
    int nMultiplier;
    int nAddend;
};

struct D2BallisticStrc
{
    unsigned int dwFlags;
    int f_4;
    int f_8;
    int nVelocity;
    int nVelA;
    int nVelB;
    int nStartVelocity;
    int unk0x1C[2];
    int f_24;
    int unk0x28[8];
    int nFrames;
};

extern const int gaSpiralOuterY_006DADC0[7]; // 0x006DADC0
extern const int gaSpiralOuterX_006DADE0[7]; // 0x006DADE0
extern const int gaSpiralOuterB_006DAE00[7]; // 0x006DAE00
extern const int gaSpiralInnerY_006DAE1C[4]; // 0x006DAE1C
extern const int gaSpiralOuterA_006DAE2C[7]; // 0x006DAE2C
extern const int gaSpiralInnerX_006DAE48[4]; // 0x006DAE48
extern D2LobBracketStrc gaLobBrackets_006DAE70[2]; // 0x006DAE70
extern D2CollideTypeMaskStrc gaCollideTypeMasks_0072A354[]; // 0x0072A354
void __fastcall sub_004CEA00(int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CEA00
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004DA200
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0
D2BallisticStrc* __fastcall sub_0046F060(D2UnitStrc* pUnit); // 0x0046F060
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall sub_006444A0(D2UnitStrc* pUnit); // 0x006444A0
int __stdcall sub_006444D0(D2UnitStrc* pUnit); // 0x006444D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648C30
void __stdcall sub_00649D00(int nArg1, int nArg2, int nArg3, int nArg4, D2UnitStrc* pUnit, int nArg6); // 0x00649D00
void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
int __fastcall sub_004C5910(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB); // 0x004C5910
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster); // 0x0063EDC0


void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

enum
{
};

struct D2ActiveRoomViewStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2AreaScanStrc
{
    D2UnitStrc* pUnit;
    int nCount;
    void* pArg;
};

typedef int (__fastcall* AREASCANFN)(D2AreaScanStrc* pScan, D2UnitStrc* pUnit);
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
int __fastcall sub_004C5960_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags); // 0x004C5960
static int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius); // 0x004C5BD0

struct D2StatesTxt
{
    char unk0x00[0x34];
    short wCltActiveFunc;
    char unk0x36[0x06];
};

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[]; // 0x00727BA8
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0
void __fastcall sub_004C7470_SetMissileDirection(D2UnitStrc* pMissile, int nDirection); // 0x004C7470
extern "C" int __stdcall sub_006492A0(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

// 0x00436E90
int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// 0x004C6020
int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00551FF0
int __stdcall sub_00551FF0_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00643880
int __stdcall sub_00643880_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646260
int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646270
int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

// 0x006436E0
int __fastcall sub_006436E0_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x0064B700
int __fastcall sub_0064B700_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x006436F0
int __fastcall sub_006436F0_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x0064B710
int __fastcall sub_0064B710_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x004C5390
void __fastcall sub_004C5390_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0052E0F0
bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00601DC0
bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00457300
void __fastcall sub_00457300_InitGfxCaches(void* pMemPool, int bCelPool)
{
    T004013C0* pInfo = sub_00407360_GetSystemInfo();
    D2_ASSERT(pInfo, 0x30);
    if (pInfo->nTotalMemory < 0x167D000)
    {
        sub_00410610_WriteLogLine("This machine doesn't have enough physical memory (> %.2f MB) for minimal performance!", (float)pInfo->nTotalMemory / 1048576.0);
        exit(-1);
    }
    unsigned int nSize = pInfo->nTotalMemory - 0xB00000;
    unsigned int nCacheSize = nSize * 10 / 100;
    nCacheSize = D2_MIN(D2_MAX(nCacheSize, 0x300000u), 0x500000u);
    sub_00481840_SetCacheMax(nCacheSize);
    unsigned int nRest = nSize - nCacheSize;
    if (bCelPool)
    {
        nRest -= 0x600000;
        sub_005FE120_InitCelPool(pMemPool, 0x600000);
    }
    nRest -= 0x200000;
    unsigned int nMaxSize = D2_MIN(D2_MAX(nRest / 3, 0x1800000u), 0x4000000u);
    D2CMPSpriteCacheInit(pMemPool, nMaxSize, 0x7D000, nSize);
    sub_00470200_InitGfxTables(0x200000);
}

// 0x004C7400
D2UnitStrc* __fastcall sub_004C7400_CreateTargetedMissile(D2UnitStrc* pUnit, int nMissile, int nSkill, int nSkillLevel,
    int nTargetX, int nTargetY)
{
    D2UnitStrc* pResult;
    if ((nTargetX && nTargetY) || (pResult = sub_004C52E0(pUnit, &nTargetX, &nTargetY)) != 0)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 1;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nX = nTargetX;
        tMissileParams.nY = nTargetY;
        tMissileParams.nSkill = nSkill;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        pResult = sub_004CD540_CreateMissile(&tMissileParams);
    }
    return pResult;
}

// 0x004C51B0
void __fastcall sub_004C51B0_UpdateUnitFromPacket(D2PacketUnitRecordStrc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        sub_004C2180_UpdateCursorItem(pUnit);
    }
}

// 0x004C5E20
int __fastcall sub_004C5E20_CountCallback(void* pArg, D2UnitStrc* pUnit)
{
    *(int*)((D2AreaScanContextStrc*)pArg)->pArg += 1;
    return 1;
}

// 0x004C5E70
int __fastcall sub_004C5E70_FindCallback(void* pArg, D2UnitStrc* pUnit)
{
    D2AreaScanFindStrc* pFind = (D2AreaScanFindStrc*)((D2AreaScanContextStrc*)pArg)->pArg;
    const unsigned int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    if (nUnitId > pFind->nArgB && nUnitId < pFind->nBest)
    {
        pFind->nOut += 1;
        pFind->nBest = nUnitId;
        pFind->pFirst = pUnit;
        return 1;
    }
    if (nUnitId <= pFind->nArgA)
    {
        pFind->nArgA = nUnitId;
        pFind->pSecond = pUnit;
    }
    pFind->nOut += 1;
    return 1;
}

// 0x004C5F30
int __fastcall sub_004C5F30_CheckWeaponStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        if (!sub_004C54F0_CanThrow(pUnit))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
        if (pWeapon && ITEMSIsA(pWeapon, 0x26))
        {
            return 0;
        }
    }
    return 1;
}

// 0x004C5F70
int __fastcall sub_004C5F70_CheckThrowStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_004C54F0_CanThrow(pUnit))
    {
        return 0;
    }
    return sub_00623990_GetWeapon(pUnit, 0) != 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C5620
void __stdcall sub_004C5620_SetSpeedToTarget(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    int nTargetX;
    int nTargetY;
    if (sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
        if (nDistance < 1)
        {
            nDistance = 1;
        }
        UNITS_SetAnimationSpeed(pMissile, 0xA00 / nDistance);
        MISSILE_SetCurrentFrame(pMissile, nDistance + 2);
        pMissile->nSeqCurrentFramePrecise = 0x200;
    }
}

// 0x004C7E10
int __fastcall sub_004C7E10_FireWeaponMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pItem = sub_00623990_GetWeapon(pUnit, 1);
    if (!pItem)
    {
        return 0;
    }

    ITEMS_CheckIfThrowable(pItem);
    if ((pUnit->dwSeqFrame & ~0xFF) >= 0x900)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!ITEMS_CheckIfThrowable(pItem) && STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0))
    {
        return 0;
    }

    const int nMissile = ITEMS_GetMissileType(pItem);
    if (nMissile <= 0)
    {
        return 0;
    }

    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (ITEMSIsA(pItem, 0x26))
    {
        if (!sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0))
        {
            return 0;
        }
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004C7F50
int __fastcall sub_004C7F50_SpawnPairAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsSoftMonster(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2CoordStrc tCoord;
    tCoord.nX = CLIENTS_GetUnitX(pTarget);
    tCoord.nY = CLIENTS_GetUnitY(pTarget);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, tCoord.nX, tCoord.nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!COLLISION_GetFreeCoordinates(pRoom, &tCoord, 2, 0x1000, 1))
    {
        return 0;
    }

    if (pTarget->dwUnitType != 1)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[3])
    {
        nMissile = pSkillsTxtRecord->wCltMissileC;
    }
    else if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[2])
    {
        nMissile = pSkillsTxtRecord->wCltMissileB;
    }

    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x2001;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        tMissileParams.nX = tCoord.nX;
        tMissileParams.nY = tCoord.nY;
        sub_004CD540_CreateMissile(&tMissileParams);
        tMissileParams.nMissile = 0x73;
        sub_004CD540_CreateMissile(&tMissileParams);
        return 1;
    }

    return 0;
}

// 0x004C9060
void __fastcall sub_004C9060_DrawRotated(D2UnitStrc* pUnit, int nArg, int bForward)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    const int nDirection = PATH_GetDirection(pPath);
    sub_006488A0_SetDirection(pPath, (bForward ? nDirection + 0x15 : nDirection + 0x2A) % 64);

    int nX;
    int nY;
    if (sub_004F51D0_IsPerspective())
    {
        SCALE_ScalePerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0x60, &nX, &nY, 0);
        nX += sub_0045AFC0();
        nY += sub_0045AFD0_GetMouseYOffset();
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit);
        nY = UNITS_GetClientCoordY(pUnit);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    sub_00471EC0_DrawUnit(pUnit, nArg, nX, nY, nUnitType == 0, 0);
    sub_006488A0_SetDirection(pPath, nDirection);
}

// 0x004CA200
int __fastcall sub_004CA200_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5)
{
    if (pArg1 && nArg4)
    {
        return sub_004CA060(pArg1, nArg2, nArg3, nArg4, 0, 0, nArg5);
    }
    return 0;
}

// 0x004CA230
int __fastcall sub_004CA230_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (pArg1 && nArg4 && nArg5)
    {
        return sub_004CA060(pArg1, nArg2, nArg3, 0, nArg4, nArg5, nArg6);
    }
    return 0;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004C5680
void __fastcall sub_004C5680_AttachMissileLight(D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (pMissilesTxt->nLight)
    {
        D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, 1, 1, 0xFF, pMissilesTxt->nRGB[0], pMissilesTxt->nRGB[1], pMissilesTxt->nRGB[2]);
        sub_00474290(pLight, pMissilesTxt->nLight);
        void* pOld = D2Common_10958(pUnit, pLight);
        if (pOld)
            sub_004743D0_ReleaseOverlayResource(pOld);
    }
}

// 0x004C5910
int __fastcall sub_004C5910(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB)
{
    int nUnitIdB;
    if (!pUnitB)
    {
        nUnitIdB = -1;
    }
    else
    {
        nUnitIdB = pUnitB->dwUnitId;
        if (pUnitB->dwUnitType == 1)
        {
            nUnitIdB = sub_00479150_FindRosterIndex(nUnitIdB);
            if (nUnitIdB == -1)
                return 0;
        }
    }
    return sub_0047A520(!pUnitA ? -1 : pUnitA->dwUnitId, nUnitIdB) != 0;
}

// 0x004C68F0
int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x697);
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    return sub_004C6680_SkillDo(pUnit, nSkillId, nLevel, 0);
}

// 0x004C76D0
void __fastcall sub_004C76D0_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent)
{
    pUnit->nSeqCurrentFramePrecise = (pUnit->nSeqCurrentFramePrecise >> 8) * (100 - nPercent) / 100 << 8;
}

// 0x004C7950
void __fastcall sub_004C7950(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 6, 0x32, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        STATLIST_SetStatRemoveCallback(pStatList, sub_004C7890);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// 0x004C7BD0
int __fastcall sub_004C7BD0_GetMeleeRangePlus4(D2UnitStrc* pUnit)
{
    return sub_00622870_GetMeleeRange(pUnit) + 4;
}

// 0x004C7BE0
void __fastcall sub_004C7BE0_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, 0x44, nValue, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 0x9E5);
    }
}

// 0x004C9420
void __fastcall sub_004C9420(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 1)
            SKILLS_SetFlags(pSkill, nFlags | 2);
    }
    sub_004BA840(sub_004CA900_FindUnitSfxInRange(pUnit, 0x9E3));
}

// 0x004C9460
int __fastcall sub_004C9460_GetSkillParam1(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    return pSkillsTxt->dwParam[0];
}

// 0x004C9D70
int __fastcall sub_004C9D70(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pAnimSeqTxt = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pAnimSeqTxt)
    {
        int nFrames = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nFrames; i += 1)
        {
            if (!pAnimSeqTxt->nEvent)
                return i - 1;
        }
    }
    return 7;
}

// 0x004CA000
void __fastcall sub_004CA000(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
        SKILLS_SetFlags(pSkill, nFlags | 2);
    STATES_ToggleState(pUnit, 0x36, 0);
}

// 0x004CA280
void __cdecl sub_004CA280()
{
    gnGlobal_007C88B8 = 0;
    gnGlobal_007C88BC = 0;
    gnGlobal_007C88C0 = 0x5A;
    gnGlobal_007C88C4 = 0;
    gnGlobal_007C88C8 = 0;
    memset(gaLevelVisited_007C78B8, 0, 0x1000);
}

static __forceinline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return NULL;
}

static __forceinline D2MonStatsTxt* SKILLCLT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

static __forceinline unsigned int SKILLCLT_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned char SKILLCLT_GetUnitTypeByte(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType;
}

static __forceinline int SKILLCLT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline void SKILLCLT_SetCastState(D2UnitStrc* pUnit)
{
    if (pUnit && (pUnit->dwUnitType == 0 || pUnit->dwUnitType == 1))
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
    }
}

// 0x004C5710
static __declspec(noinline) int sub_004C5710_GetAttackMode(D2UnitStrc* pUnit)
{
    int nMode = 7;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    int bRandom = 1;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (pMonStats2TxtRecord->nType == 2)
        {
            nMode = 8;
            bRandom = 0;
        }
        if (pMonStats2TxtRecord->nType == 1)
        {
            bRandom = 0;
        }
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        nMode = 7;
        bRandom = 0;
    }

    D2UnitStrc* pWeapon;
    int nBodyLoc;
    int bIsLeftHand;
    if (!INVENTORY_GetEquippedWeapon(pUnit->pInventory, &pWeapon, &nBodyLoc, &bIsLeftHand))
    {
        return 7;
    }

    if (bRandom)
    {
        const char nRoll = SKILLCLT_RollSeed(&pUnit->pSeed) & 0x3F;
        if (nRoll < 0x20)
        {
            return 8;
        }
    }

    return nMode;
}

// 0x004C58A0
static __declspec(noinline) int sub_004C58A0_CheckTarget(D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 21))
    {
        const int nType = pTarget->dwUnitType;
        if (nType == 1 && pTarget->dwAnimMode == 12)
        {
            return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 24) != 0;
        }

        if (nType == 0)
        {
            return 1;
        }
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_004C6140_StartSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    int nItemSkillArg;
    if (pSkillsTxtRecord->nLineOfSight && sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1:
            nCollisionMask = 4;
            break;
        case 2:
            nCollisionMask = 0x1C09;
            break;
        case 3:
            nCollisionMask = 0x180;
            break;
        case 4:
            nCollisionMask = 0x804;
            break;
        case 5:
            nCollisionMask = 0x805;
            break;
        default:
            return 0;
        }

        if (!sub_00645950_CheckTargetPos(nX, nY, pUnit, nCollisionMask))
        {
            return 0;
        }
    }

    if (!sub_004C58A0_CheckTarget(pUnit, nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x504) != nSkillId)
    {
        pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
        if (!pSkill)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
            if (pSkill && pUnit == sub_00463DD0_GetPlayerUnit() && nOwnerGUID == -1)
            {
                SKILLS_SetFlags(pSkill, 8);
            }

            const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
            if (nSkillLevel > nMaxLevel)
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x513);
                sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
            }
            else
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x518);
            }

            if (!pSkill)
            {
                return 0;
            }
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }

    if (nOwnerGUID != -1)
    {
        if (!SKILLS_GetSkillInfo(pSkill, &nItemSkillArg, &nY, &nSkillLevel, &nX) || !nX)
        {
            return 0;
        }
    }

    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
        if (nSkillLevel > nMaxLevel)
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53A);
            sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
        }
        else
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53F);
        }
    }
    else
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget && !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26) && sub_00464F70_IsTargetBlocked(pUnit, pTarget))
    {
        return 0;
    }

    if (!BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 8) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        UNITS_SetUsedSkill(pUnit, NULL);
        int aArgs[7] = { 0, 0, 0, 0, 0, 0, 0 };
        sub_00480C10_UnitEvent(7, pUnit, aArgs, 0);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            sub_004CB9C0_Request(pUnit, 0x18);
        }
        return 0;
    }

    int nMode;
    if (pUnit && !SKILLCLT_GetUnitTypeByte(pUnit) && !nSkillId)
    {
        nMode = sub_004C5710_GetAttackMode(pUnit);
    }
    else
    {
        nMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    }

    if (nMode)
    {
        sub_00480E70_SetUnitMode(pUnit, nMode);
    }
    else if (!STATES_CheckState(pUnit, 12) || !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 11))
    {
        SKILLCLT_SetCastState(pUnit);
    }

    nY = 1;
    const short nStartFunc = pSkillsTxtRecord->wStartFunc;
    if (nStartFunc >= 0 && nStartFunc < gnClientSkillStartFuncs_00727A8C && gpfnClientSkillStartFuncs_00727A90[nStartFunc])
    {
        nY = gpfnClientSkillStartFuncs_00727A90[nStartFunc](pUnit, nSkillId, nSkillLevel);
        if (!nY)
        {
            UNITS_SetUsedSkill(pUnit, NULL);
            SKILLCLT_SetCastState(pUnit);
            if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 12))
            {
                return nY;
            }
        }
    }

    short nSound = pSkillsTxtRecord->wStartSound;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemStartSound > 0)
    {
        nSound = pSkillsTxtRecord->wItemStartSound;
    }

    if (nSound > 0)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 14))
    {
        const int nSoundId = sub_004CA4C0(pUnit, UNITS_GetHitClass(pUnit));
        if (nSoundId)
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nRate = sub_004CA500_GetAnimRate(pUnit, nDirection);
            sub_004B9A00(nSoundId, pUnit, nRate, 0, 0);
        }
    }

    const short nClassSound = pSkillsTxtRecord->wStartSoundClass;
    if ((nOwnerGUID == -1 || pSkillsTxtRecord->wItemStartSound <= 0) && nClassSound > 0 && pUnit && pUnit->dwUnitType == 0 && pUnit->dwClassId == pSkillsTxtRecord->nCharClass)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nClassSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nClassSound, pUnit, 0, 0, 0);
        }
    }

    int nOverlay = pSkillsTxtRecord->wCastOverlay;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemCastOverlay > 0)
    {
        nOverlay = pSkillsTxtRecord->wItemCastOverlay;
    }

    if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount && !sub_0046E100(pUnit, nOverlay))
    {
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

    if (nY && pSkillsTxtRecord->wAuraFunc > 0)
    {
        sub_004C5680_StartAura(pUnit, pSkillsTxtRecord->wAuraFunc);
    }

    return nY;
}

int __fastcall sub_004C6660_StartSkillWrapper(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID)
{
    return sub_004C6140_StartSkill(nOwnerGUID, nSkillLevel, pUnit, nSkillId);
}

// 0x004C6DE0
static __declspec(noinline) void __stdcall sub_004C6DE0_SwapDualWieldSkill(D2ClientSkillArgsStrc* pArgs, D2UnitStrc* pUnit)
{
    if (pArgs->nSkillId != 0)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightHand = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pRightHand && (!ITEMS_CanBeEquipped(pRightHand) || ITEMS_GetItemType(pRightHand) == 0x26))
    {
        pRightHand = NULL;
    }

    D2UnitStrc* pLeftHand = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pLeftHand && (!ITEMS_CanBeEquipped(pLeftHand) || ITEMS_GetItemType(pLeftHand) == 0x26))
    {
        pLeftHand = NULL;
    }

    if (ITEMSIsA(pRightHand, 0x2D) && ITEMSIsA(pLeftHand, 0x2D))
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        if (!SKILLS_GetParam4(pSkill))
        {
            pArgs->nSkillId = 5;
            SKILLS_SetParam4(pSkill, 5);
            pSkill = SKILLS_GetSkillById(pUnit, 5, -1);
        }
        else
        {
            SKILLS_SetParam4(pSkill, 0);
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }
}

// 0x004C6EB0
int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    if (UNITS_CanDualWield(pUnit) && (!pUnit || pUnit->dwUnitType != 1))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2UnitStrc* pTarget = sub_00463990(pArgs->nArg2, pArgs->nArg1);
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        sub_00465BF0(pUnit, 0);
        return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
    }

    sub_00480C10_UnitEvent(7, pUnit, NULL, 0);
    sub_006248E0_Log(1, 2, 4, 0x40, ".\\SKILLS\\Skills.cpp", 0x7C2, "StartsStartSkillID - Invalid Target");
    return 0;
}

// build: context sub_004C6F40_StartSkillAtPos
int __fastcall sub_004C6F40_StartSkillAtPos(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    const int nX = pArgs->nArg1;
    const int nY = pArgs->nArg2;
    if (UNITS_CanDualWield(pUnit))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    sub_00621C00_SetTargetPos(pUnit, nX, nY);
    if (pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SKILLCLT_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->dwCode == 0x20204250)
        {
            D2PathDirectionStrc tDirection;
            tDirection.nDirection = (PATH_GetNewDirection(pUnit->pDynamicPath) + 0x38) % 64;
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, tDirection);
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, NULL);
    return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004C57B0
D2UnitStrc* __fastcall sub_004C57B0_FireMissileAtTarget(int nMissile, D2UnitStrc* pUnit, int nSkill, int nSkillLevel, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = UNITS_GetUnitXPosition(pUnit) + nOffsetX;
    tMissileParams.nY = UNITS_GetUnitYPosition(pUnit) + nOffsetY;
    tMissileParams.nSkill = nSkill;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    if (nTargetX && nTargetY)
    {
        tMissileParams.nTargetX = nTargetX;
        tMissileParams.nTargetY = nTargetY;
    }
    else if (!sub_004C52E0(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    if (!tMissileParams.nTargetX || !tMissileParams.nTargetY)
    {
        return 0;
    }

    return sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x004C71F0
void __fastcall sub_004C71F0(int nCount, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nCount - 1) / 5 <= 7, 0x848);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    sub_004CD540_CreateMissile(pMissileParams);

    int nRemaining = nCount - 1;
    for (int i = 0; i < 7; i++)
    {
        if (!nRemaining)
        {
            break;
        }

        for (int j = 0; j < 4 && nRemaining > 0; j++)
        {
            pMissileParams->nTargetX = gaSpiralInnerX_006DAE48[j] * gaSpiralOuterA_006DAE2C[i];
            pMissileParams->nTargetY = gaSpiralInnerY_006DAE1C[j] * gaSpiralOuterB_006DAE00[i];
            sub_004CD540_CreateMissile(pMissileParams);
            pMissileParams->nTargetX = gaSpiralInnerX_006DAE48[j] * gaSpiralOuterB_006DAE00[i];
            pMissileParams->nTargetY = gaSpiralInnerY_006DAE1C[j] * gaSpiralOuterA_006DAE2C[i];
            sub_004CD540_CreateMissile(pMissileParams);
            nRemaining -= 2;
        }

        pMissileParams->nTargetX = gaSpiralOuterX_006DADE0[i];
        pMissileParams->nTargetY = gaSpiralOuterY_006DADC0[i];
        sub_004CD540_CreateMissile(pMissileParams);
        nRemaining -= 1;
    }
}

// 0x004C7B20
int __fastcall sub_004C7B20(D2UnitStrc* pUnit, int nMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int nTargetX = 0;
    int nTargetY = 0;

    D2_ASSERT(pMissilesTxtRecord, 0x9BF);

    if (!pRoom)
    {
        return 0;
    }

    sub_004C52E0(pUnit, &nTargetX, &nTargetY);
    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    return !COLLISION_CheckMaskWithSizeXY(pRoom, nTargetX, nTargetY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
}

// 0x004C8670
void __fastcall sub_004C8670_SetLobVelocity(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return;
    }

    const int nX = sub_006444A0(pTarget);
    const int nY = sub_006444D0(pTarget);
    const int nSpeed = PATH_GetVelocity(pDynamicPath) >> 8;
    if (!nSpeed)
    {
        return;
    }

    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    if (nDistance < 1)
    {
        nDistance = 1;
    }

    int nFrames = (nDistance << 0x10) / (nSpeed << 0x0C);
    if (nFrames > 1)
    {
        nFrames -= 1;
    }

    int i = 0;
    for (; i < 1; i++)
    {
        if (nDistance < gaLobBrackets_006DAE70[i].nMaxDistance)
        {
            break;
        }
    }

    int nVelocity = gaLobBrackets_006DAE70[i].nMultiplier * nDistance + gaLobBrackets_006DAE70[i].nAddend;
    if (nVelocity < 0x1F4)
    {
        nVelocity = 0x1F4;
    }

    sub_004DA000(pUnit);
    sub_004DA250(pUnit, 0, 0, -nVelocity, 0);
    sub_004DA5B0_SetBallistic(pUnit, 0, nFrames);
}

// 0x004CD0A0
void __fastcall sub_004CD0A0(D2UnitStrc* pMissile, int nArg, int nTargetX, int nTargetY, int nUnused)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    MISSILE_AllocMissileData(pMissile);
    UNITS_ChangeAnimMode(pMissile, pMissilesTxtRecord->nCollideType);
    sub_00649D00(0, nArg, nTargetX, nTargetY, pMissile, 1);

    D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
    if (pMissilesTxtRecord->nCollision)
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0x40);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    }
    PATH_SetMoveTestCollisionMask(pDynamicPath, gaCollideTypeMasks_0072A354[pMissilesTxtRecord->nCollideType].nCollisionMask);

    if (pMissilesTxtRecord->nMissileFlags[0] & gnBitMasks_006CE268[4])
    {
        pMissile->dwFlags |= 4;
    }
    else
    {
        pMissile->dwFlags &= ~4;
    }

    pMissile->dwFlags = (pMissile->dwFlags & ~0xA) | 0x20;
}

// 0x004CECC0
void __fastcall sub_004CECC0_DispatchPair(int nArg1, int nArg2, int nArg3, int nType)
{
    if ((unsigned int)(nType - 0xC9) <= 0x17)
    {
        sub_004CEA00(nArg1, nArg2, nArg3, 6);
        sub_004CEA00(nArg1, nArg2, nArg3, 6);
        return;
    }

    if (!(nType % 4))
    {
        sub_004CEA00(nArg1, nArg2, nArg3, 0x14);
    }
}

// 0x004D16C0
void __fastcall sub_004D16C0_SpawnOffsetMissile(int nUnitId, int nUnused, D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    D2UnitStrc* pFound = sub_00463990(nUnitId, 2);
    if (!pFound)
    {
        return;
    }

    const int nOffsetX = UNITS_GetUnitXPosition(pMissile) - UNITS_GetUnitXPosition(pFound);
    const int nOffsetY = UNITS_GetUnitYPosition(pMissile) - UNITS_GetUnitYPosition(pFound);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = 0x179;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pNewMissile)
    {
        sub_004DA000(pNewMissile);
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, 0);
        sub_004DA200_SetMotionVectorB(pNewMissile, 0, 0, 2, 1);
        sub_004DA250(pNewMissile, 0, 0, 0, 1);
        MISSILE_SetTargetX(pNewMissile, nOffsetX);
        MISSILE_SetTargetY(pNewMissile, nOffsetY);
    }
}

// 0x004DA5B0
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames)
{
    D2BallisticStrc* pBallistic = sub_0046F060(pUnit);
    if (!pBallistic)
    {
        return;
    }

    pBallistic->dwFlags |= 2;
    pBallistic->nFrames = nFrames;
    if (nFrames < 1)
    {
        pBallistic->nFrames = 1;
    }

    nSpeed <<= 0x0B;
    pBallistic->f_4 = 0;
    pBallistic->f_8 = 0;
    pBallistic->nVelocity = nSpeed;
    if (!pBallistic->f_24)
    {
        pBallistic->f_24 = -0x1000;
    }

    pBallistic->nVelA = 0;
    pBallistic->nVelB = 0;
    pBallistic->nStartVelocity = (-nSpeed - pBallistic->f_24 * pBallistic->nFrames * pBallistic->nFrames / 2) / pBallistic->nFrames;
}

#include "gen/data/Source/D2Client/SKILLS/Skills.inc"
struct D2ActiveRoomStrc;
struct D2UnitStrc;

static __forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x004C5960
int __fastcall sub_004C5960_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags)
{
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    switch (nType)
    {
    case 0:
    {
        if (!(nFlags & 1))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nFlags & 2))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nFlags & 4 && !MONSTERS_IsUndead(pTarget)
            || nFlags & 0x4000 && MONSTERS_IsBoss(0, pTarget)
            || nFlags & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nFlags & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nFlags & 8))
        {
            return 0;
        }
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nFlags & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nFlags & 0x80 && !UNIT_HasFlag(pTarget, 4))
    {
        return 0;
    }
    if (nFlags & 0x400 && !UNIT_HasFlag(pTarget, 8))
    {
        return 0;
    }
    if (nFlags & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nFlags & 0x10000)
    {
        if (!sub_004C5910(pUnit, pTarget))
        {
            return 0;
        }
        if (pTarget->dwUnitType == 1)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }
    if (nFlags & 0x8000 && !sub_00465C60_CheckUnitPair(pUnit, pTarget))
    {
        return 0;
    }
    if (nFlags & 0x20000 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }
    if (nFlags & 0x80000 && STATES_CheckState(pTarget, 0x56))
    {
        return 0;
    }

    if (nFlags & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }
        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pUnit);
        coords.nY = CLIENTS_GetUnitY(pUnit);
        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);
        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }
    return 1;
}

static __forceinline int U04_IsNearRoomY(const D2DrlgCoordsStrc* pCoords, int nY, int nRadius)
{
    return nY + nRadius >= pCoords->nSubtileY || nY - nRadius <= pCoords->nSubtileHeight + pCoords->nSubtileY;
}

// 0x004C5BD0
static int sub_00641930_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

int __fastcall sub_U04_Emit_00641930(D2ActiveRoomStrc** ppRooms, int nCount, int nX, int nY)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (sub_00641930_IsPointNearRoom(ppRooms[i], nX, nY, 2))
        {
            return i;
        }
    }
    return -1;
}

static __declspec(noinline) int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

static __forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static __forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x004C5C40
void __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType)
{
    if (!pUnit || !pfCallback)
    {
        return;
    }

    if (!nRange)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    D2AreaScanStrc tScan;
    tScan.pArg = pArg;
    tScan.pUnit = pUnit;
    tScan.nCount = 0;
    const int nRangeSq = nRange * nRange;

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if ((nFlags & 0x2000) && DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            continue;
        }

        if (!sub_004C5BD0_IsPointNearRoom(ppRoomList[i], nX, nY, nRange))
        {
            continue;
        }

        D2UnitStrc* pTarget = ((D2ActiveRoomViewStrc*)ppRoomList[i])->pUnitFirst;
        while (pTarget)
        {
            D2UnitStrc* pNext = pTarget->ptRoomNext;
            if (pTarget != pUnit
                && nRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetXPositionInline(pTarget), UNITS_GetYPositionInline(pTarget))
                && sub_004C5960_CanScanUnit(pUnit, pTarget, nFlags)
                && (!bCheckType || pTarget->dwUnitType != UNIT_MONSTER || !sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, 0x1B))
                && pfCallback(&tScan, pTarget))
            {
                ++tScan.nCount;
            }
            pTarget = pNext;
        }
    }
}

// 0x004C60A0
int __fastcall sub_004C60A0_ThrowWeapon(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    int nX;
    int nY;
    D2UnitStrc* pItem;
    int nMissile;

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    pItem = sub_00623990_GetWeapon(pUnit, 0);
    if (!pItem)
    {
        return 0;
    }

    nMissile = ITEMS_GetMissileType(pItem);
    if (ITEMS_GetItemType(pItem) == 0x26)
    {
        sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY);
        sub_004CDC30(pUnit, nMissile, 0, 0, nX, nY, nSkillId, 1, 0);
        return 1;
    }

    sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, 1);
    return 1;
}

inline D2StatesTxt* SKILLS_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004C72F0
void __fastcall sub_004C72F0(D2UnitStrc* pUnit)
{
    if (!sub_0063A340(pUnit))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nActionStates; ++i)
    {
        const short nState = sgptDataTables->pActionStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nState);
            if (pStatesTxtRecord && pStatesTxtRecord->wCltActiveFunc >= 0 && pStatesTxtRecord->wCltActiveFunc < gnClientSkillDoFuncs_00727DB0
                && gpfnClientSkillDoFuncs_00727BA8[pStatesTxtRecord->wCltActiveFunc])
            {
                int nA = 0;
                int nB = 1;
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
                if (pStatList)
                {
                    nA = STATLIST_GetStatValue(pStatList, 0x15E, 0);
                    nB = STATLIST_GetStatValue(pStatList, 0x15F, 0);
                }
                gpfnClientSkillDoFuncs_00727BA8[pStatesTxtRecord->wCltActiveFunc](pUnit, nA, nB);
            }
        }
    }
}

// 0x004C7470
void __fastcall sub_004C7470_SetMissileDirection(D2UnitStrc* pMissile, int nDirection)
{
    sub_006488A0_SetDirection(pMissile->pDynamicPath, nDirection);
}

// 0x004C7C90
int __fastcall sub_004C7C90_TestTarget11018(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11018(pTarget) != 0;
}

// 0x004C7CB0
int __fastcall sub_004C7CB0_SetTargetMode5(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
    return 1;
}

// 0x004C7D50
int __fastcall sub_004C7D50_LeapToTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if ((pUnit->dwSeqFrame & ~0xFF) < 0x600)
    {
        sub_004B9A00(sub_004CA4C0(pUnit, UNITS_GetHitClass(pUnit)), pUnit, 4, 0, 0);
        D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
        if (pTarget && pUnit->pDynamicPath)
        {
            D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    int nUnitId = -1;
    if (pTarget)
    {
        nUnitId = pTarget->dwUnitId;
    }
    D2UnitStrc* pDest = sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 0, nUnitId, 0);
    if (pDest && pUnit->pDynamicPath)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pDest), CLIENTS_GetUnitY(pDest), 0);
    }
    return 1;
}

// 0x004C7EE0
int __fastcall sub_004C7EE0_TestTarget11019(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11019(pTarget) != 0;
}

// 0x004C7F00
int __fastcall sub_004C7F00_SetSoftTargetMode5(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsSoftMonster(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
    return 1;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

// 0x004C7480
void __fastcall sub_004C7480_SpawnMissileRing(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nRange, int nCount)
{
    int nDirection = SEED_RollRandomNumber(&pUnit->pSeed) & 3;
    const int nX = pMissileParams->nX;
    const int nY = pMissileParams->nY;
    for (int i = 0; i < nCount; ++i)
    {
        int nOffsetX;
        int nOffsetY;
        switch (nDirection)
        {
        case 0:
            nOffsetX = -16;
            nOffsetY = -16;
            break;
        case 1:
            nOffsetX = -16;
            nOffsetY = 16;
            break;
        case 2:
            nOffsetX = 16;
            nOffsetY = 16;
            break;
        case 3:
            nOffsetX = 16;
            nOffsetY = -16;
            break;
        default:
            nOffsetX = 0;
            nOffsetY = 0;
            break;
        }

        nDirection = (nDirection + 1) % 4;
        pMissileParams->nX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) - nRange + nX;
        pMissileParams->nY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) - nRange + nY;
        pMissileParams->nTargetX = pMissileParams->nX + nOffsetX;
        pMissileParams->nTargetY = pMissileParams->nY + nOffsetY;
        pMissileParams->pInitFunc = sub_004C7470_SetMissileDirection;
        pMissileParams->pInitArgs = nDirection << 4;
        sub_004CD540_CreateMissile(pMissileParams);
    }
}

// 0x004C7630
int __fastcall sub_004C7630(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int args[7];
    memset(args, 0, sizeof(args));
    args[0] = 0;
    args[1] = -1;
    int nType = 6;
    if (pTarget)
    {
        nType = pTarget->dwUnitType;
    }
    args[2] = nType;
    int nId;
    if (!pTarget)
    {
        nId = -1;
    }
    else
    {
        nId = pTarget->dwUnitId;
    }
    args[3] = nId;
    args[4] = 1;
    sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    return 1;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x004C7700
int __fastcall sub_004C7700(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pMissile, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nTargetX);
    for (int i = 0; i < nCount; ++i)
    {
        const int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nRange) - nRange + nTargetX;
        const int nY = SEED_RollLimitedRandomNumber(pSeed, 2 * nRange) - nRange + nTargetY;
        if (sub_006492A0(CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), nX, nY) >= 4)
        {
            sub_004CDC30(pMissile, nMissile, 0, 0, nX, nY, nSkill, nSkillLevel, 0);
        }
    }

    return 1;
}
