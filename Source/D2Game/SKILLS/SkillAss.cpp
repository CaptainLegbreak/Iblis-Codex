#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PATHTYPE_CHARGEDBOLT 10
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2CurseStrc;
struct D2EffectStrc;
struct D2UnitFindArgStrc;
struct D2AuraCallbackStrc;
struct D2SrvDo47Strc;
struct D2SrvDo51Strc;
struct D2SrvDo142Strc;
struct D2SrvDo06Strc;
struct D2MonStats2Txt;
struct D2AiCmdStrc;
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2MonEquipTxt;
struct D2MonsterItemCodeStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned __int64 lSeed;
        };
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
    };
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int unk0x10;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    unsigned char unk_30[0x8];
    int nParityField;
    unsigned char unk_3C[0xC];
    int dwFrameCountPrecise;
    unsigned char unk_4C[0x14];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x60];
    unsigned int dwFlags;
    unsigned char unk_C8[0x8];
    int dwNodeIndex;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2EffectStrc
{
    unsigned int nFlags;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nX;
    int nY;
    int nParam;
    int nSkillLevel;
    int unk0x1C;
    void* pfAreaEffect;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pUnit, int nArg);

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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
    int unk0x2C;
    int unk0x30;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2SrvDo51Strc
{
    D2DamageStrc* pDamage;
    int nMonCurseResSubstraction;
    int nParam1;
    int nParam2;
};

struct D2SrvDo142Strc
{
    D2DamageStrc* pDamage;
    int nToHit;
    unsigned short nResultFlags;
    unsigned short unk0x0A;
    unsigned int nHitFlags;
    unsigned char nSrcDam;
    unsigned char unk0x11;
    unsigned short unk0x12;
};

struct D2SrvDo06Strc
{
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraTargetState;
    int nAuraStatId;
    int nAuraStatCalcValue;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2MonStats2Txt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissileA;
    short wSrvMissileB;
    short wSrvMissileC;
    char unk0x04E[0x02];
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    short wAuraTargetState;
    char unk0x084[0x38];
    short wSummon;
    signed char nPetType;
    signed char nSumMode;
    char unk0x0C0[0x6E];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    int dwParam[8];
    char unk0x168[0x3C];
    unsigned char nToHitShift;
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATLIST_GetSkillId(D2StatListStrc* pStatList); // 0x006260E0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __fastcall sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nState, int nSkillId, int nSkillLevel); // 0x00570590
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_6FD140D0(int* pX, int* pY); // 0x0056D370
void __fastcall sub_6FD14120(int* pX, int* pY); // 0x0056D3B0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __fastcall sub_6FD149B0(D2GameStrc* pGame, D2EffectStrc* pEffect); // 0x0056DCC0
int __fastcall SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nUnused); // 0x005D2E50
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, int a7, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20
void __fastcall sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3DA0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs, int a9, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall sub_6FD0B250(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3370
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall sub_005D5E10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005D5E10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
int __fastcall SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D7680
int __fastcall sub_005D7C40(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D7C40
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboredRooms); // 0x0064E7B0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus); // 0x005DB6A0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __fastcall sub_005D40F0_RingMissileInit(D2UnitStrc* pMissile, int nInitSeed);
void __fastcall SKILLS_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed); // 0x005D4680
static __declspec(noinline) void __stdcall SKILLS_CreateChargedBoltMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed); // 0x005D4150
void __fastcall sub_005D3AC0_SKILLS_PrepareStrikeDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
void __fastcall sub_005D3BA0_SKILLS_FinishStrikeDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0

struct D2MonEquipTxt
{
    short nMonster;
    short wLevel;
    unsigned char nOnInit;
    char unk0x05[3];
    unsigned int dwItem[3];
    char nLoc[3];
    char nMod[3];
    char unk0x1A[2];
};

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
    unsigned char unk0x05;
};

typedef char D2MonEquipTxt_size_check[sizeof(D2MonEquipTxt) == 0x1C ? 1 : -1];

typedef char D2UnitStrc_inventory_check[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

D2MonEquipTxt* __fastcall sub_005D30A0_GetMonEquipTxtRecord(int nMonsterId);
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pItemCode, int nItemLevel, int nMod); // 0x00573B20
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall sub_6FD154D0(D2UnitStrc* pUnit); // 0x0056E580
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
void __fastcall SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D7310

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

inline int SKILLS_GetLinearParam45(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
}

inline int SKILLS_GetParam3FromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

inline int SKILLS_GetParam4FromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x005D21B0
void __fastcall sub_6FD01B00(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nStateId, 0);

    int nSummonId = 551;
    int nMonMode = 1;
    if (pStatList)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(STATLIST_GetSkillId(pStatList));
        if (pSkillsTxtRecord)
        {
            if (pSkillsTxtRecord->wSummon > 0 && pSkillsTxtRecord->wSummon < sgptDataTables->nMonStatsTxtRecordCount)
            {
                nSummonId = pSkillsTxtRecord->wSummon;
            }

            if (pSkillsTxtRecord->nSumMode >= 0 && pSkillsTxtRecord->nSumMode < 16)
            {
                nMonMode = pSkillsTxtRecord->nSumMode;
            }
        }
    }

    if (SUNIT_IsDead(pUnit))
    {
        sub_6FC6A150(SUNIT_GetGameFromUnit(pUnit), pUnit, nSummonId, nMonMode, 1, 0);
    }
}

// 0x005D2250
int __fastcall SKILLS_SrvDo133_Impregnate(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!sub_6FD01910(pUnit, pTarget))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nStat = -1;
    curse.nState = 110;
    curse.pStateRemoveCallback = sub_6FD01B00;
    sub_0056E970(&curse);
    return 1;
}

// 0x005D2320
int __fastcall SKILLS_SrvDo134_SiegeBeastStomp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags |= 1;
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    sub_6FD10200(pGame, pUnit, 0, 0, nRange, &damage, 0);
    return 1;
}

// 0x005D26F0
int __fastcall SKILLS_SrvDo137_FenrisRage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11018(pTarget))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 104, 1);
    UNITROOM_RefreshUnit(pTarget);
    sub_6FD10250(pGame, pUnit, pUnit, pSkillsTxtRecord->nAuraState, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D27B0
int __fastcall sub_005D27B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 1;
    }

    int nXDiff = nX - CLIENTS_GetUnitX(pUnit);
    int nYDiff = nY - CLIENTS_GetUnitY(pUnit);
    sub_6FD140D0(&nXDiff, &nYDiff);
    sub_6FD14120(&nXDiff, &nYDiff);
    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    nX += nXDiff * nSubMissiles / -2;
    nY += nYDiff * nSubMissiles / -2;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nRange = nRange;

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        nX += nXDiff;
        nY += nYDiff;
    }

    if (STATES_CheckState(pUnit, 12))
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x600;
    }

    return 1;
}

// 0x005D2940
int __fastcall SKILLS_SrvDo139_BaalColdMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nDiffX = nTargetX - CLIENTS_GetUnitX(pUnit);
    const int nDiffY = nTargetY - CLIENTS_GetUnitY(pUnit);
    D2UnitStrc* pMissile = sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -nDiffY);
    MISSILE_SetTargetY(pMissile, nDiffX);
    return 1;
}

// 0x005D2A10
int __fastcall SKILLS_SrvSt63_Corpse_VineCycler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || STATES_CheckState(pTarget, 118))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pTarget;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    sub_6FCC6300(pUnit, pTarget, nSkillId, 1, 0, 0, 0);
    return 1;
}

// 0x005D2E80
int __fastcall SKILLS_SrvDo141_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2EffectStrc effect = {};
    effect.nFlags = 0x3002;
    effect.nX = UNITS_GetXPositionInline(pUnit);
    effect.nY = UNITS_GetYPositionInline(pUnit);
    effect.pUnit = pUnit;
    effect.nSkillId = 285;
    effect.nSkillLevel = nSkillLevel;
    effect.pfAreaEffect = SKILLS_AreaEffect_BaalCorpseExplode;
    effect.nParam = SKILLS_GetLinearParam45(nSkillId, nSkillLevel);
    sub_6FD149B0(pGame, &effect);
    return 1;
}

// build: context SKILLS_FindUseableCorpse
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nUnitSize)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nX = UNITS_GetXPositionInline(pUnit);
    const int nY = UNITS_GetYPositionInline(pUnit);

    D2UnitFindArgStrc unitFindArg;
    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nFlags = 0x1002;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nUnitSize;

    D2UnitFindDataStrc unitFindData;
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nUnitSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    for (int i = 0; i < unitFindData.nIndex; ++i)
    {
        D2UnitStrc* pResult = unitFindData.pUnitsArray[i];
        if (UNITS_IsCorpseUseable(pResult) && sub_00554200(pGame, pUnit, pResult))
        {
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return pResult;
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
    return 0;
}

// 0x005D3880
void __stdcall sub_005D3880_ProgressiveElemental(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nMaxSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nMaxSkillLevel > nSkillLevel)
    {
        nSkillLevel = nMaxSkillLevel;
    }

    if (nSkillLevel <= 0 || pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType == 4)
    {
        switch (nValue)
        {
        case 2:
        case 3:
        {
            const int nDivisor = sub_004EFC20_GetSkillParam2(nSkillId);
            if (nDivisor)
            {
                pDamage->dwFrzLen += pDamage->dwColdLen / nDivisor;
            }
            break;
        }
        }
    }

    pDamage->wResultFlags |= 0x4000;
}

// 0x005D3CB0
int __fastcall sub_005D3CB0_AuraDamageCopy(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    sub_6FD10140(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

// 0x005D3E80
int __fastcall SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= 1;
    damage.dwHitFlags |= 1;
    sub_6FD0FE80(pGame, pUnit, nX, nY, nRange, pSkillsTxtRecord->dwAuraFilter, sub_005D3CB0_AuraDamageCopy, &damage, 0, ".\\SKILLS\\SkillAss.cpp", 772);
    return 1;
}

// 0x005D6020
int __fastcall SKILLS_SrvDo044_BladeSentinel(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    if (D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0) < 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2UnitStrc* pMonster = sub_005D5E10(pGame, pUnit, 0, 0, pSkillsTxtRecord, nSkillId, nSkillLevel);
    if (!pMonster)
    {
        return 0;
    }

    STATLIST_SetUnitStat(pMonster, 12, STATLIST_UnitGetStatValue(pUnit, 12, 0), 0);
    sub_6FCBDFE0(pGame, pMonster, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 0);

    D2AiCmdStrc aiCmd = {};
    aiCmd.nCmdParam[0] = 0;
    aiCmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
    aiCmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
    aiCmd.nCmdParam[3] = nTargetX;
    aiCmd.nCmdParam[4] = nTargetY;
    AIGENERAL_CopyAiCommand(pGame, pMonster, &aiCmd);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
    EVENT_SetEvent(pGame, pMonster, 2, pGame->dwGameFrame + 1, 0, 0);
    pMonster->dwFlags &= 0xFFFFFFF7;
    return 1;
}

// 0x005D6520
int __fastcall SKILLS_AuraCallback_CloakOfShadows(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo47Strc* pArgs = (D2SrvDo47Strc*)pAuraCallback->pArgs;
    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAuraCallback->pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStat[0];
    if (curse.nStat <= 0)
    {
        curse.nStat = -1;
    }
    curse.nStatValue = pArgs->nAuraStatCalcValue[0];
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = sub_6FD0B250;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0)
        {
            STATLIST_SetStatIfListIsValid(pStatList, pArgs->nAuraStat[i], pArgs->nAuraStatCalcValue[i], 0);
        }
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && sub_6FD15190(pUnit, 10))
    {
        AITHINK_ExecuteAiFn(pAuraCallback->pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 10);
    }

    return 1;
}

// 0x005D7180
int __fastcall SKILLS_SrvDo050_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (!pDamage)
    {
        return 0;
    }

    D2DamageStrc physDamage = *pDamage;
    sub_6FCF77E0(pGame, pUnit, pDamage);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    if (SUNIT_IsDead(pUnit))
    {
        return 1;
    }

    D2DamageStrc fireDamage;
    memset(&fireDamage, 0, sizeof(fireDamage));
    fireDamage.dwFireDamage = DATATBLS_ApplyRatio(physDamage.dwPhysDamage, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 329, 0), 100);
    fireDamage.wResultFlags = 9;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    sub_6FD10200(pGame, pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nRange, &fireDamage, 0);
    return 1;
}

// 0x005D7310
void __fastcall SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FCBDD30(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 109);
    if (pStatList)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, 176, 0);
        const int nConversionMaxHp = STATLIST_GetStatValue(pStatList, 177, 0);
        const int nNewHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
        int nHp = DATATBLS_ApplyRatio(nConversionMaxHp, STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8, nNewHp);
        nHp = D2_MIN(D2_MAX(nHp, 1), nNewHp);

        STATLIST_SetUnitStat(pUnit, 12, nLevel, 0);
        STATLIST_SetUnitStat(pUnit, 6, nHp << 8, 0);
        STATLIST_SetUnitStat(pUnit, 7, nConversionMaxHp << 8, 0);
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    for (D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8); pList; pList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8))
    {
        D2Common_10474(pUnit, pList);
        STATLIST_FreeStatList(pList);
    }
}

// 0x005D76E0
int __fastcall SKILLS_SrvDo051_MindBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;

    D2SrvDo51Strc args;
    args.pDamage = &damage;
    args.nMonCurseResSubstraction = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nSkillId);
    args.nParam1 = SKILLS_GetParam3FromSkillId(nSkillId);
    args.nParam2 = SKILLS_GetParam4FromSkillId(nSkillId);

    sub_6FD0FE80(pGame, pUnit, nX, nY, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_MindBlast, &args, 0, ".\\SKILLS\\SkillAss.cpp", 2883);
    return 1;
}

// 0x005D7B60
int __fastcall sub_005D7B60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags = 2;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    sub_6FD0FE80(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, sub_005D3CB0_AuraDamageCopy, &damage, 0, ".\\SKILLS\\SkillAss.cpp", 3066);
    return 1;
}

// 0x005D7CE0
int __fastcall sub_005D7CE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags = 2;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    D2SrvDo142Strc args;
    args.pDamage = &damage;
    args.nResultFlags = pSkillsTxtRecord->wResultFlags;
    args.nHitFlags = pSkillsTxtRecord->dwHitFlags;
    args.nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!(pSkillsTxtRecord->wResultFlags & 1))
    {
        args.nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    }

    sub_6FD0FE80(pGame, pUnit, 0, 0, nRange, pSkillsTxtRecord->dwAuraFilter, sub_005D7C40, &args, 0, ".\\SKILLS\\SkillAss.cpp", 3151);
    return 1;
}

// 0x005D88B0
int __fastcall SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pItem = sub_6FC7C7B0(pUnit);
    if (!pItem)
    {
        return 0;
    }

    const int nMissileId = ITEMS_GetMissileType(pItem);
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pMissile;
    if (ITEMS_CheckItemTypeId(pItem, 38))
    {
        pMissile = sub_6FD11710(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    if (pMissile)
    {
        STATLIST_AddUnitStat(pMissile, 19, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        STATLIST_AddUnitStat(pMissile, 25, nDamagePercent, 0);
    }

    return 1;
}

// 0x005D89B0
int __fastcall SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11018(pTarget))
    {
        return 0;
    }

    D2CoordStrc coords;
    coords.nX = CLIENTS_GetUnitX(pTarget);
    coords.nY = CLIENTS_GetUnitY(pTarget);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = D2GAME_GetRoom_6FC52070(pRoom, coords.nX, coords.nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!COLLISION_GetFreeCoordinates(pRoom, &coords, 2, 0x1000, 1))
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nFlags[11 >> 3] & gdwBitMasks[11 & 7])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileC;
    }
    else if (pMonStats2TxtRecord->nFlags[10 >> 3] & gdwBitMasks[10 & 7])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 1;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = coords.nX;
    missileParams.nY = coords.nY;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    STATES_ToggleState(pTarget, 104, 1);
    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);
    return 1;
}

// 0x005DA940
int __fastcall SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, pSkillsTxtRecord->nSrcDam);
    return 1;
}

// 0x005DAF40
int __fastcall SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nAuraRange = sub_6FD15460(pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, 0x20003, -1, 0);
    }

    if (!pTarget)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    int nUnitType = UNIT_INVALID;
    if (pTarget)
    {
        nUnitType = pTarget->dwUnitType;
    }
    SKILLS_SetParam2(pSkill, nUnitType);
    int nUnitGUID;
    if (!pTarget)
    {
        nUnitGUID = -1;
    }
    else
    {
        nUnitGUID = pTarget->dwUnitId;
    }
    SKILLS_SetParam3(pSkill, nUnitGUID);
    return 1;
}

// 0x005DB150
int __fastcall SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo06Strc* pArgs = (D2SrvDo06Strc*)pAuraCallback->pArgs;

    D2CurseStrc curse = {};
    curse.pUnit = pAuraCallback->pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStatId;
    curse.nStatValue = pArgs->nAuraStatCalcValue;
    curse.nState = pArgs->nAuraTargetState;
    sub_0056E970(&curse);
    return 1;
}

// 0x005DB1C0
int __fastcall SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    D2SrvDo06Strc args;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    args.nAuraStatId = pSkillsTxtRecord->wAuraStat[0];
    args.nAuraStatCalcValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    sub_6FD0FE80(pGame, pUnit, 0, 0, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_InnerSight_SlowMissiles, &args, 1, ".\\SKILLS\\SkillAma.cpp", 527);
    return 1;
}

// 0x005DB6D0
int __fastcall SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wSrvMissileB >= 0)
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.pTarget = pTarget;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nTargetX = nTargetX;
    missileParams.nTargetY = nTargetY;
    missileParams.nMissile = nMissileId;

    if (nParam)
    {
        missileParams.pInitFunc = SKILLS_AddDamagePercentBonus;
    }
    missileParams.pInitArgs = nParam;

    if (!pTarget)
    {
        missileParams.dwFlags = 0x420;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        if (pTarget)
        {
            MISSILE_SetTargetX(pMissile, 1);
        }
        else
        {
            MISSILE_SetTargetX(pMissile, 2);
        }

        const short nDiffX = nTargetX - CLIENTS_GetUnitX(pUnit);
        const short nDiffY = nTargetY - CLIENTS_GetUnitY(pUnit);
        MISSILE_SetTargetY(pMissile, nDiffX + (nDiffY << 16));
    }

    return 1;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005D3F90
int __fastcall SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber(&pUnit->pSeed);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2MissileStrc missileParams = {};

    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2SeedStrc seed;
    SEED_InitLowSeed(&seed, nRand);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nArea = nRange * nRange;
    for (int i = 0; i < nArea; ++i)
    {
        const int nX = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);
        const int nY = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);

        if (nX * nX + nY * nY <= nArea)
        {
            missileParams.nX = nTargetX + nX;
            missileParams.nY = nTargetY + nY;

            if (D2GAME_GetRoom_6FC52070(pRoom, missileParams.nX, missileParams.nY))
            {
                MISSILES_CreateMissileFromParams(pGame, &missileParams);
            }
        }
    }

    return 1;
}

// 0x005D40F0
void __fastcall sub_005D40F0_RingMissileInit(D2UnitStrc* pMissile, int nLowSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nTotalFrames = MISSILE_GetTotalFrames(pMissile);
    if (nTotalFrames >= 78)
    {
        nTotalFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, nLowSeed);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nTotalFrames);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x005D4150
static __declspec(noinline) void __stdcall SKILLS_CreateChargedBoltMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nLowSeed);

    D2MissileStrc missileParams = {};
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pInitFunc = sub_005D40F0_RingMissileInit;

    const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        const unsigned __int64 lSeed = tSeed.nHighSeed + 0x6AC690C5i64 * tSeed.nLowSeed;
        tSeed.lSeed = lSeed;
        missileParams.pInitArgs = (unsigned int)lSeed;

        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        MISSILE_SetTargetX(pMissile, sub_004EFC20_GetSkillParam2(0x118) + 1);
    }
}

int __fastcall sub_M269_Emit_005D4150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed)
{
    SKILLS_CreateChargedBoltMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nStep, nLowSeed ^ 0x5A5);
    return 0x3C1;
}

// 0x005D4870
static void __stdcall SKILLS_CreateCurvingMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, unsigned int nLowSeed)
{
    D2SeedStrc seed;
    SEED_InitLowSeed(&seed, nLowSeed);

    D2MissileStrc missileParams = {};
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pInitFunc = SKILLS_MissileInit_CurvingPath;

    const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
    };

    const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
    };

    for (int i = 0; i < 64; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        missileParams.pInitArgs = SEED_RollRandomNumber(&seed);

        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pMissile && nMissileId == 0x238)
        {
            MISSILE_SetTargetX(pMissile, sub_004EFC20_GetSkillParam2(0x118) + 1);
        }
    }
}

// 0x005D4F40
int __fastcall SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nLowSeed = SEED_RollRandomNumber(&pUnit->pSeed);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    SKILLS_CreateCurvingMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nAuraRange, nLowSeed);
    return 1;
}

// 0x005D4E70
int __fastcall SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nLowSeed = SEED_RollRandomNumber(&pUnit->pSeed);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    SKILLS_CreateChargedBoltMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nAuraRange, nLowSeed);
    return 1;
}

// 0x005D6200
static void __stdcall sub_005D6200_SKILLS_StrikeDamage(D2GameStrc* pGame, D2UnitStrc* pTarget, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 325, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        sub_005D3AC0_SKILLS_PrepareStrikeDamage(pUnit, &damage);
        damage.dwEnDmgPct += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        sub_005D3BA0_SKILLS_FinishStrikeDamage(pUnit, &damage);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
}

// 0x005D6340
int __fastcall sub_005D6340_SKILLS_SrvDo_AlternatingStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((pUnit->nParityField >> 8) % 2 == 0)
    {
        sub_005D6200_SKILLS_StrikeDamage(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags &= ~0x40;
    }
    else
    {
        sub_005D6200_SKILLS_StrikeDamage(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}

// 0x005D6330
int __fastcall SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}

// 0x005D69B0
void __fastcall sub_005D69B0_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
}

// 0x005D6B60
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel, int bCheckOnInit)
{
    const int nType = pPet ? pPet->dwUnitType : 6;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    const int nClassId = pPet->dwClassId;
    D2MonEquipTxt* pRecord = sub_005D30A0_GetMonEquipTxtRecord(nClassId);
    if (!pRecord)
    {
        return;
    }

    if (bCheckOnInit && !pRecord->nOnInit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPet->pInventory;
    if (!pInventory)
    {
        return;
    }

    while (pRecord->nMonster == nClassId && pRecord->wLevel > nSkillLevel)
    {
        ++pRecord;
    }

    for (; pRecord->nMonster == nClassId; ++pRecord)
    {
        int nMax = 0;
        while (nMax < 3 && pRecord->nLoc[nMax] > 0 && pRecord->nLoc[nMax] < 11)
        {
            ++nMax;
        }

        if (nMax <= 0)
        {
            continue;
        }

        unsigned int nIndex;
        if ((nMax - 1) & nMax)
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed % nMax;
        }
        else
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed & (nMax - 1);
        }

        const int nBodyLoc = pRecord->nLoc[nIndex];
        if (INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc))
        {
            continue;
        }

        int nMod = pRecord->nMod[nIndex];
        if (nMod < 0 || nMod >= 8)
        {
            nMod = 0;
        }

        unsigned int nItemCode = pRecord->dwItem[nIndex];
        if (nItemCode == 0x20202020 && pUnit)
        {
            if (!pUnit->pInventory)
            {
                continue;
            }

            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
            if (!pItem)
            {
                continue;
            }

            nItemCode = ITEMS_GetBaseCode(pItem);
        }

        D2MonsterItemCodeStrc tItemCode;
        tItemCode.nItemCode = nItemCode;
        tItemCode.nBodyLoc = nBodyLoc;
        tItemCode.unk0x05 = 1;
        sub_6FC61190(pGame, pPet, &tItemCode, nItemLevel, nMod);
    }
}

// 0x005D72B0
static int __stdcall sub_005D72B0_CanConvertTarget(D2UnitStrc* pOwner, int nChance, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (MONSTERS_GetHirelingTypeId(pUnit))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 0;
    }

    if (!sub_6FD15190(pUnit, 11))
    {
        return 0;
    }

    return (int)SEED_RollLimitedRandomNumber(&pOwner->pSeed, 100) <= nChance;
}

// 0x005D7430
static int __stdcall sub_005D7430_ApplyConversion(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, D2SrvDo51Strc* pArgs)
{
    if (!sub_005D72B0_CanConvertTarget(pOwner, pArgs->nMonCurseResSubstraction, pUnit))
    {
        return 0;
    }

    const int nExpireFrame = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pArgs->nParam2) + pGame->dwGameFrame + pArgs->nParam1;
    D2StatListStrc* pConversionStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x35);
    if (!pConversionStatList)
    {
        const int nUnitGUID = !pOwner ? -1 : pOwner->dwUnitId;
        const int nUnitType = !pOwner ? 6 : pOwner->dwUnitType;

        pConversionStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitGUID);
        if (!pConversionStatList)
        {
            return 0;
        }

        STATLIST_SetState(pConversionStatList, 0x35);
        STATLIST_SetStatRemoveCallback(pConversionStatList, SKILLS_StatRemoveCallback_MindBlast);
        D2COMMON_10475_PostStatToStatList(pUnit, pConversionStatList, 1);
        STATES_ToggleState(pUnit, 0x35, 1);
    }

    D2COMMON_10476(pConversionStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    sub_6FD154D0(pUnit);
    sub_6FCBDD30(pUnit, 2, 1);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pOwner->dwNodeIndex);

    for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8))
    {
        D2Common_10474(pUnit, i);
        STATLIST_FreeStatList(i);
    }

    UNITS_SetTargetUnitForDynamicUnit(pOwner, 0);

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    const int nOwnerLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0);
    if (!nLevel || nOwnerLevel >= nLevel || STATLIST_GetStatListFromUnitAndState(pUnit, 0x6D))
    {
        return 1;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

    D2StatListStrc* pConversionSaveStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nUnitType, nUnitGUID);
    if (!pConversionSaveStatList)
    {
        return 1;
    }

    STATLIST_SetState(pConversionSaveStatList, 0x6D);
    D2COMMON_10475_PostStatToStatList(pUnit, pConversionSaveStatList, 1);
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    STATLIST_SetStat(pConversionSaveStatList, 0xB0, nLevel, 0);
    STATLIST_SetStat(pConversionSaveStatList, 0xB1, nMaxHp, 0);

    int nNewHitpoints = DATATBLS_ApplyRatio(nHitpoints, nOwnerLevel, nLevel) << 8;
    int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nOwnerLevel, nLevel) << 8;
    if (nNewMaxHp < 1)
    {
        nNewMaxHp = 1;
    }

    nNewHitpoints = MIN(MAX(nNewHitpoints, 1), nNewMaxHp);

    STATLIST_SetUnitStat(pUnit, 12, nOwnerLevel, 0);
    STATLIST_SetUnitStat(pUnit, 6, nNewHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, 7, nNewMaxHp, 0);
    return 1;
}

// 0x005D7680
int __fastcall SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo51Strc* pArgs = (D2SrvDo51Strc*)pAuraCallback->pArgs;

    if (!sub_005D7430_ApplyConversion(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, pArgs))
    {
        D2DamageStrc damage = *pArgs->pDamage;
        SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage);
    }

    return 1;
}
