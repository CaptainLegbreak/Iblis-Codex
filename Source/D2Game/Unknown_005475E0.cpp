#include "D2Structs.h"
// build: context MonStats
// build: context RollLimited
// build: context Roll

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
struct D2MonStatsTxt { char pad00[0xC]; unsigned char flags[4]; char pad10[0x1E]; unsigned char rarity; char pad2F[0x179]; };
struct D2DataTablesStrc { char pad00[0xA78]; D2MonStatsTxt* monStats; int padA7C; int monCount; char padA84[0x1D8]; int levelCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnSpawnMask; // 0x006CE268
extern const unsigned char gnRangedMask; // 0x006CE278
extern const char gszMonsterRegion[]; // 0x006E0CF8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0
extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
void* __fastcall FOG_AllocPool(void*,int,const char*,int,int); // 0x0040B430
void __fastcall SEED_InitLowSeed(D2SeedStrc*,unsigned int); // 0x00650E40
void* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int); // 0x0061DB70
void __stdcall sub_005BDB20_GenerateComponentVariants(D2SeedStrc*,D2MonRegDataStrc*,int); // 0x005BDB20
static __forceinline unsigned __int64 Roll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    return (unsigned int)((((unsigned int)nMax - 1) & (unsigned int)nMax) ? (unsigned int)Roll(pSeed) % nMax : Roll(pSeed) & (nMax - 1));
}
static __forceinline D2MonStatsTxt* MonStats(int id) {
 if(id<0||id>=sgptDataTables->monCount)return 0;
 return &sgptDataTables->monStats[id];
}
__declspec(noinline) static void __stdcall sub_005475E0_SelectMonsters(D2SeedStrc*,int,D2LevelsTxt*,D2MonsterRegionStrc*);
static void __stdcall sub_005475E0_SelectMonsters(D2SeedStrc*,int,D2LevelsTxt*,D2MonsterRegionStrc*); // 0x005475E0
// 0x005475E0
static void __stdcall sub_005475E0_SelectMonsters(D2SeedStrc* seed,int higher,D2LevelsTxt* levels,D2MonsterRegionStrc* region)
{
 int toSpawn=levels->numMon;
 if(toSpawn>13)toSpawn=13;
 int available=levels->normalCount;
 if(higher)available=levels->nightCount;
 if(toSpawn>available)toSpawn=available;
 short ids[25];
 D2MonRegDataStrc* entry=region->data;
 if(higher) {
  for(int k=0;k<levels->nightCount;++k)ids[k]=levels->night[k];
 } else {
  for(int k=0;k<levels->normalCount;++k)ids[k]=levels->normal[k];
 }
 for(int i=0;i<toSpawn&&available>0;++i) {
  int index=RollLimited(seed,available);
  short id=ids[index];
  if(!i&&levels->ranged) {
   for(int j=0;j<20;++j) {
    D2MonStatsTxt* mon=MonStats(id);
    if(mon&&(mon->flags[3]&gnRangedMask))break;
    index=RollLimited(seed,available);id=ids[index];
   }
  }
  --available;
  if(index<available)memmove(&ids[index],&ids[index+1],2*(available-index));
  D2MonStatsTxt* mon=MonStats(id);
  if(mon&&(mon->flags[0]&gnSpawnMask)) {
   entry->id=id;entry->rarity=mon->rarity;
   region->totalRarity+=mon->rarity;++region->spawnCount;++region->monCount;++entry;
  }
 }
}

// 0x005479C0
void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion)
{
 SEED_InitLowSeed(seed,lowSeed);
 ++regions;
 if(!DATATBLS_GetDifficultyLevelsTxtRecord(difficulty)) {
  sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x83);exit(-1);
 }
 for(int level=1;level<sgptDataTables->levelCount;++level) {
  D2MonsterRegionStrc* region=(D2MonsterRegionStrc*)FOG_AllocPool(pool,sizeof(D2MonsterRegionStrc),gszMonsterRegion,0x87,0);
  memset(region,0,sizeof(D2MonsterRegionStrc));
  D2LevelsTxt* levels=DATATBLS_GetLevelsTxtRecord(level);
  region->act=levels->act;region->level=level;
  region->density=levels->density[difficulty];region->bossMin=levels->bossMin[difficulty];region->bossMax=levels->bossMax[difficulty];
  region->wander=levels->wander;region->quest=levels->quest;region->flags=-1;region->unknown0C=-1;
  if(expansion) {region->dungeonLevel=levels->monLevelEx[difficulty];region->dungeonLevelEx=levels->monLevelEx[difficulty];}
  else {region->dungeonLevel=levels->monLevel[difficulty];region->dungeonLevelEx=levels->monLevel[difficulty];}
  sub_005475E0_SelectMonsters(seed,difficulty>0,levels,region);
  D2MonRegDataStrc* entry=region->data;
  for(int i=0;i<region->monCount;++i){sub_005BDB20_GenerateComponentVariants(seed,entry,3);++entry;}
  *regions=region;++regions;
 }
}
