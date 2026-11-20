#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
struct D2MonsterRegionStrc;
struct D2SeedStrc;
struct D2MonRegDataStrc;
struct D2LevelsTxt;
struct D2MonStatsTxt;
struct D2DataTablesStrc;


struct D2MonRegDataStrc { short id; unsigned char rarity; char pad03[0x31]; };

struct D2MonsterRegionStrc {
 unsigned char act; char pad01[0xB]; int unknown0C;
 unsigned char monCount,totalRarity,spawnCount; char pad13;
 D2MonRegDataStrc data[13]; int density;
 unsigned char bossMin,bossMax,wander; char pad2BF;
 int level; char pad2C4[0x10]; int flags; unsigned char quest; char pad2D9[3];
 int dungeonLevel,dungeonLevelEx;
};

struct D2LevelsTxt {
 char pad00[3]; unsigned char act; char pad04[0xC];
 short monLevel[3],monLevelEx[3]; int density[3]; unsigned char bossMin[3],bossMax[3];
 unsigned char wander; char pad2F; unsigned char quest,ranged,numMon,normalCount,nightCount;
 char pad35; short normal[25],night[25];
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszMonsterRegion[]; // 0x006E0CF8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
void* __fastcall FOG_AllocPool(void*,int,const char*,int,int); // 0x0040B430
void __fastcall SEED_InitLowSeed(D2SeedStrc*,unsigned int); // 0x00650E40
void* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int); // 0x0061DB70
void __stdcall sub_005BDB20_GenerateComponentVariants(D2SeedStrc*,D2MonRegDataStrc*,int); // 0x005BDB20
__declspec(noinline) static void __stdcall sub_005475E0_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2MonsterRegionStrc* pRegion, D2LevelsTxt* pLevels);
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// build: context sub_005475E0_SelectMonsters
// calling-convention shim (not game code)
static void __stdcall sub_005475E0_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2MonsterRegionStrc* pRegion, D2LevelsTxt* pLevels)
{
    SEED_InitLowSeed((D2SeedStrc*)bHigher, (unsigned int)pRegion);
    D2LevelsTxt* pA = DATATBLS_GetLevelsTxtRecord((int)pLevels);
    D2LevelsTxt* pB = DATATBLS_GetLevelsTxtRecord((int)pA);
    SEED_InitLowSeed((D2SeedStrc*)pA, (unsigned int)pB);
    SEED_InitLowSeed((D2SeedStrc*)pB, (unsigned int)pA);
    SEED_InitLowSeed((D2SeedStrc*)pA, (unsigned int)pB);
    SEED_InitLowSeed((D2SeedStrc*)pB, (unsigned int)pA);
    SEED_InitLowSeed(pSeed, pSeed->nHighSeed + (unsigned int)pB);
}

// 0x005479C0
void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion)
{
 SEED_InitLowSeed(seed,lowSeed);
 ++regions;
 if(!DATATBLS_GetDifficultyLevelsTxtRecord(difficulty)) {
  sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x83);exit(-1);
 }
 for(int level=1;level<sgptDataTables->nLevelsTxtRecordCount;++level) {
  D2MonsterRegionStrc* region=(D2MonsterRegionStrc*)FOG_AllocPool(pool,sizeof(D2MonsterRegionStrc),gszMonsterRegion,0x87,0);
  memset(region,0,sizeof(D2MonsterRegionStrc));
  D2LevelsTxt* levels=DATATBLS_GetLevelsTxtRecord(level);
  region->act=levels->act;region->level=level;
  region->density=levels->density[difficulty];region->bossMin=levels->bossMin[difficulty];region->bossMax=levels->bossMax[difficulty];
  region->wander=levels->wander;region->quest=levels->quest;region->flags=-1;region->unknown0C=-1;
  if(expansion) {region->dungeonLevel=levels->monLevelEx[difficulty];region->dungeonLevelEx=levels->monLevelEx[difficulty];}
  else {region->dungeonLevel=levels->monLevel[difficulty];region->dungeonLevelEx=levels->monLevel[difficulty];}
  sub_005475E0_SelectMonsters(seed,difficulty>0,region,levels);
  D2MonRegDataStrc* entry=region->data;
  for(int i=0;i<region->monCount;++i){sub_005BDB20_GenerateComponentVariants(seed,entry,3);++entry;}
  *regions=region;++regions;
 }
}

// 0x00547B50
void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion)
{
    ++ppMonsterRegion;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i, ++ppMonsterRegion)
    {
        if (*ppMonsterRegion)
        {
            FOG_FreeServerMemory(pMemPool, *ppMonsterRegion, ".\\MONSTER\\MonsterRegion.cpp", 197, 0);
        }
    }
}
