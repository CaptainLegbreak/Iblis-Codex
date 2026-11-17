struct D2ActiveRoomStrc;

struct D2LevelsTxt
{
    char unk0x00[0x16];
    short wMonLvl;
    char unk0x18[0x1B];
    unsigned char nNumNormalMonsters;
    char unk0x34[0x02];
    short wNormalMonsters[25];
};

struct D2MonStatsTxt
{
    char unk0x00[0x02];
    short nBaseId;
    short nNextInClass;
    char unk0x06[0xA4];
    short nLevel[3];
    char unk0xB0[0xF8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset);            // 0x006510C0

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
