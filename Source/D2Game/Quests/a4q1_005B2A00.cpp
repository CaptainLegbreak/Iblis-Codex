#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
struct D2UnitStrc;
struct D2ActiveRoomStrc { char unknown00[0x6c]; D2SeedStrc pSeed; };
struct D2RectStrc { int left,top,right,bottom; };
struct D2CoordPairStrc { int x,y; };
struct D2DrlgCoordsStrc { int nX,nY,nWidth,nHeight,nTileX,nTileY,nTileWidth,nTileHeight; };
struct D2RoomCoordListStrc { D2RectStrc box[2]; char unknown20[8]; int nIndex; };
struct D2GameStrc { char unknown00[0x6d]; unsigned char nDifficulty; char unknown6e[0x82]; void* pMonReg[1]; };
struct D2MonsterSpawnParamsStrc { D2GameStrc* pGame; D2ActiveRoomStrc* pRoom; D2RoomCoordListStrc* pRoomCoordList; int nMonsterId,nAnimMode,nUnitGUID,nX,nY,nMaxSearchRings; short nFlags; };
typedef D2MonsterSpawnParamsStrc D2UnkMonCreateStrc;
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned char gbNeverCount_006CE270; // 0x006CE270
extern unsigned int gdwSetBoss_006CE278; // 0x006CE278
extern unsigned int gdwBossTransfer_006CE27C; // 0x006CE27C
extern "C" __declspec(dllimport) int __stdcall CopyRect(D2RectStrc*,const D2RectStrc*);
extern "C" __declspec(dllimport) int __stdcall PtInRect(const D2RectStrc*,D2CoordPairStrc);
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730
void __stdcall sub_00643560_GameTileToSubtileCoords(int*,int*); // 0x00643560
void __stdcall sub_005B2700_FindPosition(D2ActiveRoomStrc*,int*,int*); // 0x005B2700
D2ActiveRoomStrc* __fastcall sub_00463740_GetRoomAtPosition(D2ActiveRoomStrc*,int,int); // 0x00463740
int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc*,int); // 0x0045C3E0
int __stdcall D2Common_10095(D2ActiveRoomStrc*,int,int); // 0x0061B130
int __fastcall sub_005FD350_CanSpawn(int,D2ActiveRoomStrc*,int,int,int); // 0x005FD350
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064D9B0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230
void __fastcall sub_00547D90_RegisterSpawn(void**,D2ActiveRoomStrc*,D2UnitStrc*,int); // 0x00547D90
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc*,int,int); // 0x0061AD30
void __fastcall sub_00552D60_SetVision(D2UnitStrc*,D2RoomCoordListStrc*); // 0x00552D60
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc*,unsigned char,int); // 0x005543B0
void __stdcall DATATBLS_GetMonsterChainInfo(int,int*,int*); // 0x006510C0
int __fastcall sub_00463830_GetBaseId(int); // 0x00463830
int __fastcall sub_004CC790_RollRange(D2SeedStrc*,int,int); // 0x004CC790
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100
int __fastcall sub_005B2570_SpawnTentacles(D2GameStrc*,D2UnitStrc*,int,int,int,int,short); // 0x005B2570
D2UnitStrc* __fastcall sub_005B23C0_SpawnAtUnit(D2GameStrc*,D2UnitStrc*,int,int,int,short); // 0x005B23C0
int __fastcall sub_00451F50_GetUnitId(D2UnitStrc*); // 0x00451F50
static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B21B0
static void MONSTERSPAWN_SetupBossMods(D2MonsterSpawnParamsStrc*,D2UnitStrc*); // 0x005B1CF0
static void MONSTERSPAWN_SpawnMinionParty(D2MonsterSpawnParamsStrc*,D2UnitStrc*); // 0x005B2830
static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc*); // 0x005B1C50
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850
// build: context DATATBLS_GetMonStatsTxtRecord_Inline
static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// build: context MONSTERREGION_SanitizeMonsterId_Inline
static __forceinline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

static __declspec(noinline) void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit);
// 0x005B21B0
static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x5B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x14, 0);
        break;
    case 0x18:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xD, 0);
        break;
    case 0x60:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xA, 0);
        break;
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14A:
    case 0x162:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xE, 0);
        break;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xF, 0);
        break;
    case 0x1CD:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x21, 0);
        break;
    case 0x1B4:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x22, 0);
        break;
    case 0x1F5:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x23, 0);
        break;
    case 0xD3:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xB, 0);
    case 0x21C:
    case 0x21D:
    case 0x21E:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        break;
    }
}


struct D2MonsterItemCodeStrc
{
    unsigned int dwCode;
    int nUnk0x04;
};
extern D2MonsterItemCodeStrc gaAncientBarbItems_006E1BB0[4][3];                                             // 0x006E1BB0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
void __fastcall sub_00573B20_GiveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pCode, int nLevel, int nFlags); // 0x00573B20
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet);                         // 0x00573570
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId);    // 0x005447A0

static __declspec(noinline) void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit);
struct D2MonsterEquipmentStrc
{
	int nItemCode;
	unsigned char nBodyLoc;
	unsigned char unk0x05;
	unsigned char unk0x06;
	unsigned char unk0x07;
};

extern const D2MonsterEquipmentStrc gtAncientEquipment[12]; // 0x006E2C90
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterEquipmentStrc* pItemInfo, int nLevel, unsigned int nFlags); // 0x00573B20

// 0x005B1C50
static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
	const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
	const D2MonsterEquipmentStrc* pItemInfo = &gtAncientEquipment[nClassId - 540];

	int nItemId;
	int nCount = 4;
	do
	{
		D2MonsterEquipmentStrc itemInfo = *pItemInfo;
		D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemInfo->nItemCode, &nItemId);
		switch (pGame->nDifficulty)
		{
		case 1:
			itemInfo.nItemCode = pItemsTxtRecord->dwUberCode;
			break;

		case 2:
			itemInfo.nItemCode = pItemsTxtRecord->dwUltraCode;
			break;
		}

		sub_6FC61190(pGame, pUnit, &itemInfo, nLevel, 4);
		pItemInfo += 3;
		--nCount;
	}
	while (nCount);
}

// build: context MONSTERS_GetMonStatsTxtRecord_Inline
static __forceinline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// build: context MONSTERS_ValidateMonsterId_Inline
static __forceinline int MONSTERS_ValidateMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

// build: context MONSTERUNIQUE_ToggleUnitFlag_Inline
static __forceinline void MONSTERUNIQUE_ToggleUnitFlag_Inline(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

static __declspec(noinline) void MONSTERSPAWN_SetupBossMods(D2MonsterSpawnParamsStrc* pMonCreate, D2UnitStrc* pUnit);
// 0x005B1CF0
static void MONSTERSPAWN_SetupBossMods(D2MonsterSpawnParamsStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    void* pRoom = pMonCreate->pRoom;
    const int nMonsterId = pMonCreate->nMonsterId;

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecord_Inline(nMonsterId);
    int nBaseId;
    if (!pMonStatsTxtRecord)
    {
        nBaseId = nMonsterId;
    }
    else
    {
        nBaseId = pMonStatsTxtRecord->nBaseId;
    }

    switch (MONSTERS_ValidateMonsterId_Inline(nBaseId))
    {
    case 0xD3:
        if (nMonsterId != 0x2C4)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0xD);
            QUESTS_CreateChainRecord(pGame, pUnit, 9);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0xAF:
    {
        const int nWarrivId = MONSTERS_ValidateMonsterId_Inline(0xAF);
        QUESTS_WarrivSpawn(pGame, pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nWarrivId);
        return;
    }
    case 0xFA:
        QUESTS_CreateChainRecord(pGame, pUnit, 0xC);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x800);
        MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
        return;
    case 0xF3:
        if (nMonsterId != 0x2C1)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x17);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x16E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x13);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        return;
    case 0xF2:
        if (nMonsterId != 0x2C0)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x14);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1E, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x11, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x9C:
        if (nMonsterId != 0x2C3)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 6);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1D, 1);
        return;
    case 0x199:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x18);
        return;
    case 0x100:
        if (nMonsterId != 0x2C2)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x16);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0x197:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x11);
        return;
    case 0xE5:
        QUESTS_CreateChainRecord(pGame, pUnit, 8);
        return;
    case 0x10B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xC, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        QUESTS_CreateChainRecord(pGame, pUnit, 2);
        STATES_ToggleState(pUnit, 0x76, 1);
        return;
    case 0x11C:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x124:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1F, 0);
        return;
    case 0x192:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x1B2:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x20);
        return;
    case 0x20E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x22);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x21C:
        MONSTERSPAWN_EquipAncientBarbarians(pUnit);
        return;
    case 0x220:
        if (nMonsterId != 0x2C5)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x24);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    }
}

static __declspec(noinline) void MONSTERSPAWN_SpawnMinionParty(D2MonsterSpawnParamsStrc* pCreate,D2UnitStrc* pUnit);

// build: context MONSTERSPAWN_SpawnMinionParty
static void MONSTERSPAWN_SpawnMinionParty(D2MonsterSpawnParamsStrc* pCreate,D2UnitStrc* pUnit)
{
    const int nMonsterId=pCreate->nMonsterId;
    D2MonStatsTxt* pRecord=DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    if(!pRecord) return;
    int nChain;
    DATATBLS_GetMonsterChainInfo(nMonsterId,0,&nChain);
    D2GameStrc* pGame=pCreate->pGame;
    const unsigned short nFlags=pCreate->nFlags;
    if(pRecord->wMinion[0]<0 || pRecord->wMinion[0]>=sgptDataTables->nMonStatsTxtRecordCount) return;
    const int nBase=sub_00463830_GetBaseId(nMonsterId);
    if(nBase>=0 && nBase<sgptDataTables->nMonStatsTxtRecordCount && nBase==0x105)
    {
        AIGENERAL_SetOwnerData(pGame,pUnit,pUnit?pUnit->dwUnitId:-1,1,1,pRecord->nMonStatsFlags[0]&gdwBossTransfer_006CE27C);
        const int nCount=sub_004CC790_RollRange(&pUnit->pSeed,pRecord->nPartyMin,pRecord->nPartyMax);
        sub_005B2570_SpawnTentacles(pGame,pUnit,pRecord->wMinion[0],1,nCount,(~(nFlags>>2))&1,0x40);
        return;
    }
    if(pRecord->nMonStatsFlags[0]&gdwSetBoss_006CE278)
        AIGENERAL_SetOwnerData(pGame,pUnit,pUnit?pUnit->dwUnitId:-1,1,1,pRecord->nMonStatsFlags[0]&gdwBossTransfer_006CE27C);
    int nIndex=0,nThreshold=0;
    if(pRecord->wMinion[1]>=0 && pRecord->wMinion[1]<sgptDataTables->nMonStatsTxtRecordCount) nThreshold=1;
    int nCount=sub_004CC790_RollRange(&pUnit->pSeed,pRecord->nPartyMin,pRecord->nPartyMax);
    while(nCount>0)
    {
        D2UnitStrc* pMinion=sub_005B23C0_SpawnAtUnit(pGame,pUnit,pRecord->wMinion[nIndex],1,4,0x40);
        if(pMinion && (pRecord->nMonStatsFlags[0]&(unsigned char)gdwSetBoss_006CE278))
        {
            AIGENERAL_SetOwnerData(pGame,pMinion,sub_00451F50_GetUnitId(pUnit),1,0,0);
            AIGENERAL_AllocMinionList(pGame,pUnit,pMinion);
        }
        if(++nIndex>nThreshold) nIndex=0;
        --nCount;
    }
}
// build: context GetMonStats2
static __forceinline D2MonStats2Txt* GetMonStats2(int nId)
{
    if(nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nIndex=sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if(nIndex<0 || nIndex>=sgptDataTables->nMonStats2TxtRecordCount) return 0;
    return &sgptDataTables->pMonStats2Txt[nIndex];
}
// build: context SEED_RollRandomNumber
static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}
// build: context ITEMS_RollRandomNumber
static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed);
}
// 0x005B2A00
D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2MonsterSpawnParamsStrc* pCreate)
{
    D2MonStatsTxt* pRecord=DATATBLS_GetMonStatsTxtRecord_Inline(pCreate->nMonsterId);
    if(!pRecord) return 0;
    D2MonStats2Txt* pRecord2=GetMonStats2(pCreate->nMonsterId);
    if(!pRecord2) return 0;
    const unsigned short nFlags=pCreate->nFlags;
    D2ActiveRoomStrc* pRoom=pCreate->pRoom;
    unsigned int nCollisionMask;
    switch(pRecord2->nSpawnCol)
    {
    case 1:nCollisionMask=0x1c0;break;
    case 2:nCollisionMask=0x3f11;break;
    case 3:nCollisionMask=0;break;
    case 0:nCollisionMask=0x3c01;break;
    default:nCollisionMask=0x3c01;break;
    }
    D2RectStrc area;
    int nAreaTile,bCheckTile;
    if(!pCreate->pRoomCoordList)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom,&coords);
        area.bottom=coords.nY+coords.nHeight;area.left=coords.nX;area.right=coords.nX+coords.nWidth;area.top=coords.nY;
        nAreaTile=0;bCheckTile=0;
    }
    else
    {
        CopyRect(&area,&pCreate->pRoomCoordList->box[1]);
        sub_00643560_GameTileToSubtileCoords(&area.left,&area.top);
        sub_00643560_GameTileToSubtileCoords(&area.right,&area.bottom);
        nAreaTile=pCreate->pRoomCoordList->nIndex;bCheckTile=1;
    }
    if (!pRoom)
        return 0;
    if (!&pRoom->pSeed)
        return 0;
    int nRadius,nMaxRadius;
    if(pCreate->nMaxSearchRings<0) nRadius=0; else nRadius=3;
    if(!nRadius) nMaxRadius=0; else nMaxRadius=3*pCreate->nMaxSearchRings;
    {
    int nSpawnY=0,nSpawnX=0;
    if(pRecord2->nSpawnCol==1 && !(pCreate->nMonsterId>=0x102 && pCreate->nMonsterId<=0x107) && pCreate->nMonsterId!=0x99)
    {
        sub_005B2700_FindPosition(pRoom,&nSpawnX,&nSpawnY);
        pRoom=sub_00463740_GetRoomAtPosition(pRoom,nSpawnX,nSpawnY);
    }
    else
    {
        if(nRadius>nMaxRadius) return 0;
        do
        {
            D2SeedStrc* pSeed=&pRoom->pSeed;
            int nX=pCreate->nX,nY=pCreate->nY;
            const int nDiameter=2*nRadius;
            int nOffsetX,nOffsetY,nStepX,nStepY;
            if(ITEMS_RollRandomNumber(pSeed)&1)
            {
                nOffsetX=nRadius; if (nX) nOffsetY=sub_0045C3E0_RollLimited(pSeed,nDiameter>>1); else nOffsetY=sub_0045C3E0_RollLimited(pSeed,nDiameter>>1); nStepX=0; nStepY=1;
            }
            else
            {
                if (nX && nRadius) nOffsetX=sub_0045C3E0_RollLimited(pSeed,nDiameter>>1); else nOffsetX=sub_0045C3E0_RollLimited(pSeed,nDiameter>>1);nOffsetY=nRadius;nStepX=1;nStepY=0;
            }
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetX=-nOffsetX;
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetY=-nOffsetY;
            nX+=nOffsetX;nY+=nOffsetY;
            const int nMinX=pCreate->nX-nRadius,nMaxX=nMinX+nDiameter;
            const int nMinY=pCreate->nY-nRadius,nMaxY=nMinY+nDiameter;
            int nSteps=4*nDiameter;
            if(!nSteps) nSteps=1;
            while(nSteps>0)
            {
                if(nX==nMinX && nY==nMinY) {nStepX=1;nStepY=0;}
                if(nX==nMaxX)
                {
                    if(nY==nMinY) {nStepX=0;nStepY=1;}
                    if(nY==nMaxY) {nStepX=-1;nStepY=0;}
                }
                if(nX==nMinX)
                {
                    if(nY==nMaxY) {nStepX=0;nStepY=-1;}
                    if(nY==nMinY && nX==nMaxX && nY==nMaxY) {nStepX=0;nStepY=0;}
                }
                nX+=nStepX;nY+=nStepY;
                D2CoordPairStrc point;point.x=nX;point.y=nY;
                if(PtInRect(&area,point) && (!bCheckTile || D2Common_10095(pRoom,nX,nY)==nAreaTile)
                    && sub_005FD350_CanSpawn(pCreate->nMonsterId,pRoom,nX,nY,1)
                    && (!COLLISION_CheckMaskWithSize(pRoom,nX,nY,pRecord2->nSizeX,nCollisionMask) || (pCreate->nFlags&0x80)))
                {
                    nSpawnX=nX;nSpawnY=nY;nRadius=nMaxRadius;break;
                }
                --nSteps;
            }
            const int nNext=nRadius+3;
            *(int volatile*)&nRadius=nNext;
            if(nStepX && nStepY && nFlags){if(nNext>nMaxRadius)break;}else{if(nNext>nMaxRadius)break;}
        }while(1);
    }
    if(!nSpawnX || !nSpawnY) return 0;
    if(nFlags&1) return (D2UnitStrc*)1;
    int nAllocFlags=1;if(nFlags&0x20)nAllocFlags=3;
    D2UnitStrc* pMonster=SUNIT_AllocUnitData(1,pCreate->nMonsterId,nSpawnX,*(int volatile*)&nSpawnY,pCreate->pGame,pRoom,nAllocFlags,pCreate->nAnimMode,pCreate->nUnitGUID);
    if(pMonster)
    {
        int bNeverCount=nFlags&8;
        if(pRecord->nMonStatsFlags[2]&gbNeverCount_006CE270) bNeverCount=1;
        sub_00547D90_RegisterSpawn(pCreate->pGame->pMonReg,pRoom,pMonster,bNeverCount);
        D2RoomCoordListStrc* pList=pCreate->pRoomCoordList;
        if(!pList) pList=D2Common_10096(pRoom,nSpawnX,nSpawnY);
        sub_00552D60_SetVision(pMonster,pList);
        switch(pRecord->nAlign)
        {
        default:sub_005543B0_AssignAlignment(pMonster,0,1);break;
        case 2:sub_005543B0_AssignAlignment(pMonster,1,1);break;
        case 1:sub_005543B0_AssignAlignment(pMonster,2,1);pMonster->dwFlags|=0x20000;break;
        }
        if(!(nFlags&2)) MONSTERSPAWN_SetupNormalMods(pCreate,pMonster);
        MONSTERSPAWN_SetupBossMods(pCreate,pMonster);
        if(!(nFlags&0x40)) MONSTERSPAWN_SpawnMinionParty(pCreate,pMonster);
    }
    return pMonster;
    }
}
