struct D2MonsterRegionStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC5C];
    int nLevelsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

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
