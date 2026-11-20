#include "D2Game.h"
#include "D2Structs.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2SeedStrc;
struct D2ItemsTxt;



int __fastcall sub_0045ADF0(D2UnitStrc* unit); // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc* unit); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* unit); // 0x00620BB0
int __stdcall sub_0061A1B0(D2ActiveRoomStrc* room); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int level); // 0x006427F0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* room); // 0x0061AB00

struct D2GameStrc { char unk_00[0x1C]; void* pMemoryPool; char unk_20[0x88]; int dwGameFrame; };

void __fastcall sub_00535430_ClearPortal(D2GameStrc* game,D2UnitStrc* unit); // 0x00535430
int __fastcall sub_0056D130(D2GameStrc* game,D2UnitStrc* unit,D2ActiveRoomStrc* room,int x,int y,int level,D2UnitStrc** out,int object,int permanent); // 0x0056D130
void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380
void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* unit,int id); // 0x005353B0
void __fastcall sub_00552AF0_SetOwnerId(D2UnitStrc* unit,int id); // 0x00552AF0
D2UnitStrc* __fastcall sub_00553720_GetPortalPair(D2GameStrc* game,D2UnitStrc* unit); // 0x00553720
void __fastcall sub_0058CF00_UpdatePortal(D2GameStrc* game,D2UnitStrc* unit); // 0x0058CF00
D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0
void __fastcall sub_0053B3D0_SendByte(D2ClientStrc* client,unsigned char code); // 0x0053B3D0

struct D2ItemsTxt { char unk_00[0x98]; short nState; char unk_9A[4]; short nStat[3]; unsigned int dwCalc[3]; unsigned int dwLen; };

struct D2ItemStatCostTxt { char unk_00[0x18]; unsigned char nValShift; char unk_19[0x19]; unsigned short nMaxStat; char unk_34[0x110]; };

struct D2DataTablesStrc { char unk_00[0xC4]; int nStatesCount; char unk_C8[0xB04]; D2ItemStatCostTxt* pItemStatCostTxt; int unk_BD0; int nItemStatCostCount; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
void __fastcall sub_6FD10E50(D2UnitStrc*, int, D2StatListStrc*); // 0x0056E900
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*, unsigned char); // 0x00571A10
unsigned char __fastcall sub_005805D0_GetLifePercent(D2UnitStrc*); // 0x005805D0
int __fastcall sub_005C6870_FeedBloodGolem(D2GameStrc*, D2UnitStrc*, int); // 0x005C6870
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, void(__fastcall*)(D2UnitStrc*, int, D2StatListStrc*)); // 0x00625CE0
int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, unsigned short); // 0x00625D00
int __stdcall D2COMMON_10473(D2StatListStrc*); // 0x00626090
void __stdcall D2COMMON_10476(D2StatListStrc*, int); // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc*, D2UnitStrc*, unsigned int); // 0x00627C20
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc*, int); // 0x0062A5D0
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc*, int); // 0x0062A620
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[11];
    int dwFrzLen;
    int unk0x38[14];
};
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

static __forceinline int GetUnitType(D2UnitStrc* unit) { return unit?unit->dwUnitType:6; }

static __forceinline int GetItemType(D2UnitStrc* pItem)
{
    int nType = 6;
    if (pItem)
    {
        nType = pItem->dwUnitType;
    }
    return nType;
}

// 0x005BE290
int __fastcall sub_005BE290_CreateTownPortal(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,int unused1,int unused2,int unused3,int unused4)
{
 if(GetUnitType(unit)!=0) return 0;
 unit->dwFlags|=0x40;
 D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
 unsigned char act=DRLG_GetActNoFromLevelId(sub_0061A1B0(room));
 int town=DUNGEON_GetTownLevelIdFromActNo(act);
 if(DUNGEON_IsRoomInTown(room) || sub_0061A1B0(room)==136) {
  sub_00553380_SendEvent(unit,24,unit);return 0;
 }
 sub_00535430_ClearPortal(game,unit);
 D2UnitStrc* portal=0;
 int result=sub_0056D130(game,unit,room,sub_0045ADF0(unit),sub_0045AE20(unit),town,&portal,59,0);
 sub_00553380_SendEvent(unit,7,0);
 if(result) {
  PLAYER_SetUniqueIdInPlayerData(unit,!portal?-1:portal->dwUnitId);
  if(portal) {
   sub_00552AF0_SetOwnerId(portal,unit->dwUnitId);
   D2UnitStrc* other=sub_00553720_GetPortalPair(game,portal);
   if(other) {
    sub_00552AF0_SetOwnerId(other,unit->dwUnitId);
    sub_0058CF00_UpdatePortal(game,other);
   }
   sub_0058CF00_UpdatePortal(game,portal);
  }
 }
 if(item) {
  const int nItemId = item->dwUnitId;
  const int nItemType = GetItemType(item);
  D2ClientStrc* client=sub_005531C0_GetClient(unit,".\\SKILLS\\SkillItem.cpp",218,nItemType,nItemId);
  sub_0053B3D0_SendByte(client,124);
 }
 return result;
}

// build: context GetItemStatCost
static __forceinline D2ItemStatCostTxt* GetItemStatCost(int nStat)
{
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostCount)
        return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

// 0x005BE3F0
int __fastcall sub_005BE3F0_ApplyPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int a4, int a5, int a6, int a7)
{
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxt) return 0;
    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwLen);
    const int nState = pItemsTxt->nState;
    D2StatListStrc* pStatList = 0;
    int nOldLength = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesCount) return 0;
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList) nOldLength = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }
    int nResult = 0;
    int bUpdateLife = 0;
    for (int i = 0; i < 3; ++i)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const int nStat = pItemsTxt->nStat[i];
        if (nStat < 0 || nStat >= sgptDataTables->nItemStatCostCount) break;
        D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
        if (!pCost) continue;
        int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwCalc[i]);
        switch (nStat)
        {
        case 74: nValue <<= 8;
        case 6:
        {
            nValue = ITEMS_GetBonusLifeBasedOnClass(pUnit, nValue);
            const int nVitality = STATLIST_UnitGetStatValue(pUnit, 3, 0);
            if (nVitality > 0)
            {
                const unsigned int nChance = ITEMS_RollLimitedRandomNumber(pSeed, nVitality) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        case 26: nValue <<= 8;
        case 8:
        {
            nValue = ITEMS_GetBonusManaBasedOnClass(pUnit, nValue);
            const int nEnergy = STATLIST_UnitGetStatValue(pUnit, 1, 0);
            if (nEnergy > 0)
            {
                const unsigned int nChance = ITEMS_RollLimitedRandomNumber(pSeed, nEnergy) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        }
        nValue <<= pCost->nValShift;
        if (nValue <= 0) continue;
        switch (nStat)
        {
        case 6: bUpdateLife = 1;
        case 74:
            if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                nValue = sub_005C6870_FeedBloodGolem(pGame, pUnit, nValue);
            break;
        }
        if (nLength <= 0)
        {
            const int nCurrent = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            const int nMaxStat = pCost->nMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostCount)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nCurrent + nValue > nMaxValue)
                    nValue = nMaxValue - nCurrent;
            }
            STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
            nResult = 1;
        }
        else
        {
            const int nExpireFrame = pGame->dwGameFrame + nOldLength + nLength;
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                if (!pStatList) continue;
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
            const int nTotalValue = STATLIST_GetStatValue(pStatList, nStat, 0) * nOldLength + nValue;
            if (i == 0) EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
            const int nTotalLength = nLength + nOldLength;
            if (nTotalLength > 0) STATLIST_SetStat(pStatList, nStat, nTotalValue / nTotalLength, 0);
            nResult = 1;
        }
    }
    if (bUpdateLife && pUnit && pUnit->dwUnitType == 0)
    {
        const unsigned char nOldLife = STATLIST_UnitGetStatValue(pUnit, 352, 0);
        const unsigned char nNewLife = sub_005805D0_GetLifePercent(pUnit);
        int nDifference = nOldLife - nNewLife;
        if (nDifference < 0) nDifference = -nDifference;
        if (nDifference > 4)
        {
            SUNITMSG_QueueLifeUpdate(pUnit, nNewLife);
            STATLIST_SetUnitStat(pUnit, 352, nNewLife, 0);
        }
    }

    return nResult;
}

// 0x005BFC60
int __fastcall sub_005BFC60_EventFuncFreeze(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
    {
        return 0;
    }

    int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);

    int nBonus = nValue - 1;
    if (nBonus < 0)
    {
        nBonus = 0;
    }

    if (nEvent == 6)
    {
        nAttackerLevel -= nEvent;
    }

    int nChance = 5 * (4 * nBonus - nUnitLevel + nAttackerLevel + 10);
    if (nEvent == 6)
    {
        nChance /= 3;
    }

    int nPercent = D2_MIN(D2_MAX(nChance, 0), 100);

    const unsigned __int64 lSeed = (unsigned __int64)pAttacker->pSeed.nHighSeed + (unsigned __int64)pAttacker->pSeed.nLowSeed * 0x6AC690C5;
    pAttacker->pSeed.nLowSeed = (unsigned int)lSeed;
    pAttacker->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    const int nRoll = (int)((unsigned int)lSeed % 100);
    if (nRoll >= nPercent)
    {
        return 0;
    }

    int nLength = 2 * (nPercent - nRoll) + 25;
    nLength = D2_MIN(D2_MAX(nLength, 25), 250);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFrzLen = nLength;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    return 1;
}
