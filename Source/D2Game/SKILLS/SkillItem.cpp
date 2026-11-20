#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2TxtTables.h"

#define IFLAG_TARGETING 4
#define OBJECT_STASH 267
#define UPDATEUI_CLOSEALL 17
#define UPDATEUI_OPENCUBE 21
#define SKILL_FIREBALL 47
#define STAT_HITPOINTS 6
#define STAT_LEVEL 12
#define STAT_ATTACKRATE 68
#define STAT_VALUE 71
#define STATE_SLOWED 24
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;
struct D2MonStatsTxt;
struct D2BooksTxt;
struct D2pSpellTblStrc;
struct D2CurseStrc;
struct D2SkillsTxt;
struct D2MonEquipTxt;
struct Unit005A0180;
union D2SeedStrc;
struct D2UnitStrc;
struct D2GameStrc;
struct D2DataTablesStrc;
struct D2DamageStrc;
struct D2AnimSeqTxt;
struct D2ItemStatCostTxt;



void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem); // 0x0062BB20
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0


int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590


struct D2ItemsTxt
{
    char unk0x00[0x94];
    int dwPspell;
    short wState;
    short wCurseState[2];
    short wStat[3];
    unsigned int dwCalc[3];
    unsigned int dwLen;
};

typedef int (__fastcall* PSPELLFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId);

struct D2pSpellTblStrc
{
    PSPELLFN pfSpellPrepare;
    PSPELLFN pfSpellDo;
};

extern D2pSpellTblStrc gPSpellTable_00741790[]; // 0x00741790
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);


enum D2C_Z09ItemConstants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
    STAT_STAMINA = 0x0A,
    STAT_MAXSTAMINA = 0x0B,
    STAT_STAMINARECOVERYBONUS = 0x1C,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20
int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId); // 0x005BEDA0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0


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

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status); // 0x0055E170
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

struct D2MonStatsTxt
{
    char unk0x000[0x2A];
    short nMonEquipTxtRecordId;
    char unk0x02C[0x22];
    unsigned char nThreat;
    char unk0x04F[0x159];
};

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x3A];
    short wSrvMissile[4];
    char unk0x04E[0x06];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x1BA];
};

enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
    EVENTTYPE_PERIODICSTATS = 9,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0

struct D2MonEquipTxt
{
    char unk0x00[0x1C];
};

struct D2AnimSeqTxt
{
    unsigned short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues); // 0x005BFDA0
extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask); // 0x005A0180
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

struct D2ItemStatCostTxt
{
    char pad00[0x18];
    unsigned char valueShift;
    char pad19[0x19];
    unsigned short maximumStat;
    char pad34[0x110];
};

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc*,D2UnitStrc*,int); // 0x005C6870
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*,unsigned char); // 0x00571A10
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

// 0x005BE130
int __fastcall SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    ITEMS_SetItemFlag(pItem, 4, 1);

    const int nSpellIcon = ITEMS_GetSpellIcon(pItem);
    if (nSpellIcon >= 0)
    {
        D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 64), pItem, nSpellIcon, 0, 1, nSkillId);
    }

    return 1;
}

// 0x005BE180
static int sub_005BE180_INVENTORY_ContainsItem(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        if (INVENTORY_UnitIsItem(pInvItem) == pTarget)
        {
            return 1;
        }
    }

    return 0;
}

// 0x005BE1C0
static void sub_005BE1C0_SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 119, ".\\SKILLS\\SkillItem.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 0);
            D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 122), pItem, -1, 1, 0, -1);
        }
    }
}

// 0x005BE230
int __fastcall SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pTarget, 0x10, 147, ".\\SKILLS\\SkillItem.cpp"))
    {
        return 0;
    }

    if (!sub_005BE180_INVENTORY_ContainsItem(pTarget, pUnit))
    {
        return 0;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pUnit, pTarget);
    return 1;
}

// 0x005BE7B0
int __fastcall SKILLITEM_pSpell04_ApplyPotionStats(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,D2UnitStrc* target,int x,int y,int skillId)
{
 D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1:item->dwClassId);
 if(!record)return 0;
 int duration=ITEMMODS_EvaluateItemFormula(unit,item,record->dwLen);
 int state=record->wState;
 D2StatListStrc* list=0;
 int remaining=0;
 if(duration>0){
  if(state<=0 || state>=sgptDataTables->nStatesTxtRecordCount)return 0;
  list=STATLIST_GetStatListFromUnitAndState(unit,state);
  if(list)remaining=D2COMMON_10473(list)-game->dwGameFrame;
 }
 int changed=0,updateLife=0;
 for(int i=0;i<3;++i){
  int stat=record->wStat[i];
  if(stat<0 || stat>=sgptDataTables->nItemStatCostTxtRecordCount)break;
  D2ItemStatCostTxt* cost=&sgptDataTables->pItemStatCostTxt[stat];
  if(!cost)continue;
  int value=ITEMMODS_EvaluateItemFormula(unit,item,record->dwCalc[i]);
  if(stat==26 || stat==74)value<<=8;
  value=value<<cost->valueShift;
  if(value<=0)continue;
  switch(stat){
   case 6:updateLife=1;
   case 74:if(!sub_0044BE50_GetUnitTypeOrInvalid(unit))value=SKILLS_SharePotionLifeWithBloodGolem(game,unit,value);break;
  }
  if(duration<=0){
   const int current=STATLIST_UnitGetStatValue(unit,stat,0);
   if(cost->maximumStat<sgptDataTables->nItemStatCostTxtRecordCount){
    int maximum=STATLIST_UnitGetStatValue(unit,cost->maximumStat,0);
    if(current+value>maximum)value=maximum-current;
   }
   STATLIST_AddUnitStat(unit,stat,value,0);
   changed=1;
  }else{
   int expiry=game->dwGameFrame+remaining+duration;
   if(!list){
    int const nUnitGUID = sub_00451F50_GetUnitGUID(unit);
    list=STATLIST_AllocStatList(game->pMemoryPool,2,expiry,sub_0044BE50_GetUnitTypeOrInvalid(unit),nUnitGUID);
    if(!list)continue;
    STATLIST_SetState(list,state);
    STATES_ToggleState(unit,state,1);
    if(sub_0044BE50_GetUnitTypeOrInvalid(unit)){
     sub_00540E60(game,unit,3,0);
     EVENT_SetEvent(game,unit,3,game->dwGameFrame+1,0,0);
    }
    STATLIST_SetStatRemoveCallback(list,sub_6FD10E50);
    D2COMMON_10475_PostStatToStatList(unit,list,1);
   }
   D2COMMON_10476(list,expiry);
   int total=STATLIST_GetStatValue(list,stat,0)*remaining+value;
   if(i==0)EVENT_SetEvent(game,unit,12,expiry,0,0);
   if(duration+remaining>0)STATLIST_SetStat(list,stat,total/(duration+remaining),0);
   changed=1;
  }
 }
 if(updateLife && unit && unit->dwUnitType==0){
  unsigned char previous=(unsigned char)STATLIST_UnitGetStatValue(unit,352,0);
  unsigned char life=MONSTERMODE_GetHpPercent128(unit);
  int difference=(int)previous-(int)life;
  if(difference<0)difference=-difference;
  if(difference>4){
   SUNITMSG_QueueLifeUpdate(unit,life);
   STATLIST_SetUnitStat(unit,352,life,0);
  }
 }
 return changed;
}

// build: context SKILLS_GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId < 0)
    {
        return 0;
    }

    if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

// 0x005BEAC0
int __fastcall SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    const int nState = pItemsTxtRecord->wState;

    D2StatListStrc* pStatList = 0;
    int nRemainingDuration = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
        {
            return 0;
        }

        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            nRemainingDuration = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
        }
    }

    int nResult = 0;
    int bAffectsHitpoints = 0;

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->maximumStat < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nPercentage = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nPercentage > 0)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, pItemStatCostTxtRecord->maximumStat, 0);
                int nAddValue = DATATBLS_ApplyRatio(nMaxValue, nPercentage, 100);
                if (nPercentage == 100)
                {
                    nAddValue = nMaxValue;
                }

                switch (nStatId)
                {
                case 6:
                    bAffectsHitpoints = 1;
                case 74:
                    if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                    {
                        nAddValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nAddValue);
                    }
                    break;
                }

                if (nLength <= 0)
                {
                    const int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
                    if (nOldValue + nAddValue > nMaxValue)
                    {
                        nAddValue = nMaxValue - nOldValue;
                    }

                    STATLIST_AddUnitStat(pUnit, nStatId, nAddValue, 0);
                    nResult = 1;
                }
                else
                {
                    const int nExpireFrame = pGame->dwGameFrame + nRemainingDuration + nLength;
                    if (!pStatList)
                    {
                        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                        if (!pStatList)
                        {
                            continue;
                        }

                        STATLIST_SetState(pStatList, nState);
                        STATES_ToggleState(pUnit, nState, 1);

                        if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                        {
                            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                            EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                        }

                        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
                        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    }

                    D2COMMON_10476(pStatList, nExpireFrame);

                    const int nTimeDependentValue = nAddValue + nRemainingDuration * STATLIST_GetStatValue(pStatList, nStatId, 0);
                    if (!i)
                    {
                        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
                    }

                    if (nRemainingDuration + nLength > 0)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, nStatId, nTimeDependentValue / (nRemainingDuration + nLength), 0);
                    }

                    nResult = 1;
                }
            }
        }
    }

    if (bAffectsHitpoints && pUnit && pUnit->dwUnitType == 0)
    {
        const unsigned char nNewSentHpPct = MONSTERMODE_GetHpPercent128(pUnit);
        SUNITMSG_QueueLifeUpdate(pUnit, nNewSentHpPct);
        STATLIST_SetUnitStat(pUnit, 352, nNewSentHpPct, 0);
    }

    return nResult;
}

int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nItemType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemType != UNIT_ITEM)
    {
        return 0;
    }

    int nPSpell = -1;
    int nSkillId = -1;

    if (ITEMSIsA(pItem, ITEMTYPE_BOOK) || ITEMSIsA(pItem, ITEMTYPE_SCROLL))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            nPSpell = pBooksTxtRecord->dwPSpell;
            nSkillId = pBooksTxtRecord->dwBookSkillId;
        }
    }

    if (nPSpell <= 0)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord)
        {
            nPSpell = pItemsTxtRecord->dwPspell;
        }

        if (nPSpell <= 0)
        {
            return 0;
        }
    }

    if (nPSpell >= gnPSpellTableCount_0074178C)
    {
        return 0;
    }

    if (gPSpellTable_00741790[nPSpell].pfSpellPrepare && !ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 1130, ".\\SKILLS\\SkillItem.cpp"))
    {
        if (!gPSpellTable_00741790[nPSpell].pfSpellPrepare(pGame, pUnit, pItem, 0, nX, nY, nSkillId))
        {
            sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1135), 0x7C, pItem->dwUnitType, pItem->dwUnitId);
        }

        return 0;
    }

    if (!gPSpellTable_00741790[nPSpell].pfSpellDo)
    {
        return 0;
    }

    ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 1);

    const int nResult = gPSpellTable_00741790[nPSpell].pfSpellDo(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
    if (!nResult)
    {
        sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1151), 0x7C, pItem->dwUnitType, pItem->dwUnitId);
    }

    return nResult;
}

// 0x005BEDA0
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nState = pItemsTxtRecord->wState;
    if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    if (nLength <= 0)
    {
        return 0;
    }

    sub_6FD11C90(pUnit, nState, 0);

    int nRemaining = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        nRemaining = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }

    const int nEndFrame = pGame->dwGameFrame + nRemaining + nLength;

    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nState);
        STATES_ToggleState(pUnit, nState, 1);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    if (nEndFrame)
    {
        D2COMMON_10476(pStatList, nEndFrame);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nEndFrame, 0, 0);
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount && sub_0045C4F0_GetItemStatCostTxtRecord(nStatId))
        {
            const int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_STAMINARECOVERYBONUS && nValue > 0)
                {
                    const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
                    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
                    {
                        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina + 0x100, 0);
                    }
                }
            }
        }
    }

    return 1;
}

// 0x005BEF90
int __fastcall sub_005BEF90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nResult = 0;
    for (int i = 0; i < 2; ++i)
    {
        const int nCurseState = pItemsTxtRecord->wCurseState[i];
        if (nCurseState > 0 && nCurseState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nCurseState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            if (STATES_CheckState(pUnit, nCurseState))
            {
                STATES_ToggleState(pUnit, nCurseState, 0);
            }

            nResult = 1;
        }
    }

    if (SKILLITEM_pSpell09_StaminaPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId))
    {
        nResult = 1;
    }

    return nResult;
}

// 0x005BF060
int __fastcall sub_005BF060(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    const int nStatId = ITEMS_GetFileIndex(pItem);
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        const int nValue = STATLIST_UnitGetStatValue(pItem, STAT_VALUE, 0);
        if (nValue)
        {
            STATLIST_AddUnitStat(pUnit, nStatId, nValue, 0);
            return 1;
        }
    }

    return 0;
}

// 0x005BF0C0
int __fastcall SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        if (!pInteractUnit || pInteractUnit->dwUnitType != UNIT_OBJECT || pInteractUnit->dwClassId != OBJECT_STASH)
        {
            return 0;
        }

        SUNIT_ResetInteractInfo(pUnit);
        sub_6FC4B830(pGame, pUnit);
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 947), UPDATEUI_CLOSEALL);
    }

    SUNIT_SetInteractInfo(pUnit, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 961), UPDATEUI_OPENCUBE);
    sub_6FC4B830(pGame, pUnit);
    return 0;
}

// 0x005BF170
int __fastcall SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit)
    {
        return SKILLITEM_CastSkillOnTarget(pUnit, SKILL_FIREBALL, 1, pTargetUnit, 0);
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), 0);
}

// 0x005BF1F0
int __fastcall SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, unsigned short nX, unsigned short nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, nX, nY, 0);
}

// 0x005BF3D0
int __fastcall SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInvItem;
    D2UnitStrc* pItem;
    for (pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        pItem = INVENTORY_UnitIsItem(pInvItem);
        if (ITEMSIsA(pItem, ITEMTYPE_BOOK))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwBookSkillId == nSkillId && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
            {
                break;
            }
        }
        else if (ITEMSIsA(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwScrollSkillId == nSkillId)
            {
                break;
            }
        }
    }

    if (pInvItem)
    {
        switch (INVENTORY_GetItemNodePage(pInvItem))
        {
        case 1:
        {
            int nUnused;
            ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused);
            return 1;
        }
        case 2:
        {
            int nUnused;
            ITEMMODE_UseBeltItem(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused, 0);
            return 1;
        }
        }
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005BF510
void __fastcall SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a5);
    const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, a5, nSkillId);

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
    {
        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 1, 0);
    }
}

// 0x005BF670
int __fastcall SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwPhysDamage = nDamage << 8;
    damage.dwHitClass = 0x8D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF720
int __fastcall SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwLtngDamage = nDamage << 8;
    damage.dwHitClass = 0x4D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF7D0
int __fastcall SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwFireDamage = nDamage << 8;
    damage.dwHitClass = 0x2D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF880
int __fastcall SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nLength = 25;
    if (nAttackerLevel > nDefenderLevel)
    {
        const int nLevelDiff = nAttackerLevel - nDefenderLevel;
        nLength += 10 * nLevelDiff;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwColdLen = nLength;
    damage.dwColdDamage = nDamage << 8;
    damage.dwHitClass = 0x3D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BFAA0
int __fastcall SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        goto ReturnZero;
    }

    if (!pUnit)
    {
        goto ReturnZero;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
ReturnZero:
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nChance = 5 * (nAttackerLevel + 4 * nValue - STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) + 6);
    if (nEvent == 6 && nChance > 0)
    {
        nChance /= 3;
    }

    nChance = D2_MIN(D2_MAX(nChance, 1), 99);

    const int nRoll = SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 100);
    if (nRoll >= nChance)
    {
        return 0;
    }

    int nLevel = (nChance - nRoll) / 5 + 1;
    nLevel = D2_MIN(D2_MAX(nLevel, 1), 20);

    sub_6FD0B9F0(pGame, pAttacker, pUnit, nLevel);
    return 1;
}

// 0x005BFDA0
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues)
{
    if (nLevel <= 1 || !pValues)
    {
        return 0;
    }

    if (nLevel > 60)
    {
        return (pValues[4] * (nLevel - 60)) + 15 * (pValues[1] + pValues[2] + pValues[3]) + 14 * pValues[0];
    }

    if (nLevel > 45)
    {
        return (pValues[3] * (nLevel - 45)) + 15 * (pValues[1] + pValues[2]) + 14 * pValues[0];
    }

    if (nLevel > 30)
    {
        return 15 * pValues[1] + pValues[2] * (nLevel - 30) + 14 * pValues[0];
    }

    if (nLevel > 15)
    {
        return pValues[1] * (nLevel - 15) + 14 * pValues[0];
    }

    return pValues[0] * (nLevel - 1);
}

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BFE60
int __fastcall SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    const int nValues[] = { 9, 18, 27, 36, 45 };
    int nHpRegen = SKILLITEM_CalculateOpenWoundsHpRegen(nLevel, nValues) + 40;
    if (pUnit->dwUnitType == 0)
    {
        nHpRegen /= 4;
        if (nEvent == 6)
        {
            nHpRegen /= 2;
        }
    }
    else if (pUnit->dwUnitType == 1 && sub_005A0180((Unit005A0180*)pUnit, 0x0C))
    {
        nHpRegen /= 2;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 200;
    curse.nStat = 74;
    curse.nStatValue = -nHpRegen;
    curse.nState = 62;
    sub_0056E970(&curse);
    return 1;
}

// 0x005BFFC0
int __fastcall SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nDivisor = 4;
    if (pUnit->dwUnitType == 0)
    {
        nDivisor = 10;
    }
    else if (pUnit->dwUnitType == 1)
    {
        if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            nDivisor = 10;
        }
        else
        {
            if (MONSTERS_IsBoss(0, pUnit) || sub_005A0180((Unit005A0180*)pUnit, 2))
            {
                nDivisor = 8;
            }

            int nPlayerCount = STATLIST_UnitGetStatValue(pUnit, 100, 0);
            if (nPlayerCount < 1)
            {
                nPlayerCount = 1;
            }

            const int nHpBonus = MONSTER_GetHpBonus(nPlayerCount);
            if (nHpBonus)
            {
                nDivisor += DATATBLS_ApplyRatio(nDivisor, nHpBonus, 100);
            }
        }
    }

    if (nEvent == 6)
    {
        nDivisor *= 2;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    int nCrushingBlowHp = nHitpoints / nDivisor;

    int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
    if (nDamageResist >= 100)
    {
        nDamageResist = 100;
    }

    if (nDamageResist > 0)
    {
        nCrushingBlowHp -= DATATBLS_ApplyRatio(nCrushingBlowHp, nDamageResist, 100);
    }

    int nNewHp = nHitpoints - nCrushingBlowHp;
    nNewHp = nNewHp > 0 ? nNewHp : 0;
    STATLIST_SetUnitStat(pUnit, 6, nNewHp, 0);

    if (nNewHp <= 0 && pDamage)
    {
        pDamage->wResultFlags |= 2;
    }

    if (nCrushingBlowHp > 0)
    {
        UNITS_SetOverlay(pUnit, 147, 0);
    }

    return 1;
}

// 0x005C0130
int __fastcall sub_005C0130_RestoreManaAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || pAttacker->dwUnitType != 0)
        return 0;
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, 8, 0);
    if (nMana >= nMaxMana)
        return 0;
    nMana += nValue << 8;
    nMana = nMana > 0 ? nMana : 0;
    STATLIST_SetUnitStat(pAttacker, 8, nMana < nMaxMana ? nMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}

// 0x005C0260
int __fastcall SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !MONSTERS_IsDemon(pUnit))
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_HITPOINTS, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C0310
int __fastcall SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    int nSlowValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nSlowValue)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
    {
        if (nSlowValue >= 50)
        {
            nSlowValue = 50;
        }
    }
    else if (nUnitType == UNIT_MONSTER)
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 12))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_IsBoss(0, pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
        {
            if (nSlowValue >= 75)
            {
                nSlowValue = 75;
            }
        }
        else
        {
            if (nSlowValue >= 90)
            {
                nSlowValue = 90;
            }
        }
    }
    else
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 750;
    curse.nStat = STAT_VELOCITYPERCENT;
    curse.nStatValue = -nSlowValue;
    curse.nState = STATE_SLOWED;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_006270B0(pStatList, STAT_ATTACKRATE, -nSlowValue, 0);
    sub_006270B0(pStatList, STAT_OTHER_ANIMRATE, -nSlowValue, 0);
    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillItem.cpp", 2186);
    return 1;
}

// 0x005C32A0
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != 4)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != 3)
    {
        return 0;
    }

    if (!ITEMS_IsMetalItem(pTarget->dwClassId))
    {
        return 0;
    }

    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 256, ".\\SKILLS\\SkillNec.cpp"))
    {
        return 0;
    }

    return !STATLIST_GetOwner(pTarget, 0);
}

// 0x005CF8C0
int __fastcall sub_005CF8C0_GetSeqEventFrame(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pMonSeqTxtRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pMonSeqTxtRecord)
    {
        const int nSequenceFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nSequenceFrameCount; ++i)
        {
            if (!pMonSeqTxtRecord->nEvent)
            {
                return i - 1;
            }
        }
    }

    return 7;
}

// 0x005D2140
int __fastcall SKILLS_CanImpregnateTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget || pTarget->dwUnitType != 1 || SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    int nBaseId = sub_00463860(pTarget);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    switch (nBaseId)
    {
    case 546:
    case 551:
        return 0;
    }

    if (STATES_CheckState(pTarget, 110))
    {
        return 0;
    }

    return STATLIST_GetUnitAlignment(pTarget) != 2;
}

// 0x005D30A0
D2MonEquipTxt* __fastcall sub_005D30A0_GetMonEquipTxtRecord(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonEquipTxtRecordId < 0)
    {
        return 0;
    }

    return &sgptDataTables->pMonEquipTxt[pMonStatsTxtRecord->nMonEquipTxtRecordId];
}

// build: context SKILLS_SrvSt22_PsychicHammer
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_IsRoomInTown(pUnitRoom))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pTargetUnit);
    if (DUNGEON_IsRoomInTown(pTargetRoom))
    {
        return 0;
    }

    if (pTargetUnit->dwUnitType != 0 && pTargetUnit->dwUnitType != 1)
    {
        return 0;
    }

    return 1;
}

// build: context SKILLS_GetProgressiveSkillMissileId
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                if (nIndex > 1)
                {
                    if (nIndex >= 3)
                    {
                        nIndex = 3;
                    }
                }
                else
                {
                    nIndex = 1;
                }

                return pSkillsTxtRecord->wSrvMissile[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wSrvMissile[1];
}

// 0x005DC5C0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* hUnit, int nX, int nY)
{
    D2_ASSERT(hUnit, 267);
    D2DynamicPathStrc* hPath = hUnit->pDynamicPath;
    D2_ASSERT(hPath, 270);

    int nXDiff = PATH_GetXPosition(hPath) - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    int nYDiff = PATH_GetYPosition(hPath) - nY;
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x005DC920
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwUnitType)
    {
    case 0:
        return 14;

    case 1:
    {
        const int nClassId = pUnit->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nThreat;
        }
        break;
    }

    default:
        break;
    }

    return 0;
}
