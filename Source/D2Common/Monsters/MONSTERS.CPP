#include "D2Common.h"

#define UNIT_MONSTER 1
#define CHECK(p,line) if (!(p)) { sub_00408A60(text_006CC837,sub_00408090(),line); sub_00681E09(-1); }
struct Unicode;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct D2LevelsTxt;
struct Coord;

struct Unicode
{
    unsigned short wChar;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    Unicode* wszMonName;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0xAC];
    unsigned int dwFlagEx;
};
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

struct D2MonStatsTxt
{
    char unk0x00[0x02];
    short nBaseId;
    short nNextInClass;
    unsigned char unk_06[0x6];
    unsigned char nMonStatsFlags[4];
    unsigned char unk_10[0x9A];
    short nLevel[3];
    char unk0xB0[0xF8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0xA80 - 0xA78 - 4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268

struct D2LevelsTxt
{
    char unk0x00[0x16];
    short wMonLvl;
    char unk0x18[0x1B];
    unsigned char nNumNormalMonsters;
    char unk0x34[0x02];
    short wNormalMonsters[25];
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset); // 0x006510C0

struct Unit { int type, classId; };

struct Coord { int x,y; };

extern Coord table_006EA9D0[4]; // 0x006EA9D0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09
extern "C" const char text_006CC837[]; // 0x006CC837
int __stdcall sub_006510C0(int,int*,int*); // 0x006510C0

// 0x0063E810
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData)
    {
        if (wszName)
        {
            const int nLength = sub_00526800(wszName);
            pMonster->pMonsterData->wszMonName = (Unicode*)FOG_Alloc((nLength + 1) * sizeof(Unicode), ".\\Monsters\\MONSTERS.CPP", 195, 0);
            sub_005267E0(pMonster->pMonsterData->wszMonName, wszName);
        }
    }
}

static __forceinline void MONSTERS_GetFlagEx31(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = pUnit ? (pUnit->dwFlagEx >> 31) & 1 : 0;
}

// 0x0063E860
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nMonsterId = pMonster->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[8 >> 3] & gdwBitMasks[8 & 7])
    {
        return 1;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[10 >> 3] & gdwBitMasks[10 & 7])
    {
        return 1;
    }

    int bFlag;
    MONSTERS_GetFlagEx31(pMonster, &bFlag);
    return bFlag != 0;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int MONSTERS_GetBaseIdFromMonsterIdInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

// 0x0063EC70
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId)
{
    int nMonstersInChain;

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    const unsigned char nNumNormalMonsters = pLevelsTxtRecord->nNumNormalMonsters;
    if (!nNumNormalMonsters)
    {
        return nMonsterId;
    }

    const int nClassId = MONSTERS_GetBaseIdFromMonsterIdInline(nMonsterId);
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    for (int i = 0; i < nNumNormalMonsters; ++i)
    {
        const int nMonster = pLevelsTxtRecord->wNormalMonsters[i];
        if (MONSTERS_GetBaseIdFromMonsterIdInline(nMonster) == nClassId)
        {
            return nMonster;
        }
    }

    int nNextInClass = pMonStatsTxtRecord->nNextInClass;
    DATATBLS_GetMonsterChainInfo(nMonsterId, &nMonstersInChain, 0);

    for (int i = 0; i < nMonstersInChain; ++i)
    {
        pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nNextInClass);
        if (!pMonStatsTxtRecord)
        {
            break;
        }
        if (pMonStatsTxtRecord->nLevel[0] > pLevelsTxtRecord->wMonLvl + 1)
        {
            return nMonsterId;
        }
        nMonsterId = nNextInClass;
        nNextInClass = pMonStatsTxtRecord->nNextInClass;
    }

    return nMonsterId;
}

// 0x0063EE10
void __stdcall sub_0063EE10(Unit* unit,int* x,int* y)
{
    const int type=unit?unit->type:6;
    CHECK(type==1,0x2bc);
    int index;
    const int classId=unit?unit->classId:-1;
    sub_006510C0(classId,0,&index);
    CHECK(index<4,0x2c8);
    CHECK(index>=0,0x2c9);
    *x=table_006EA9D0[index].x;
    *y=table_006EA9D0[index].y;
}

#include "gen/data/Source/D2Common/Monsters/MONSTERS.inc"
