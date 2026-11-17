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
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

#define UNIT_MONSTER 1

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
