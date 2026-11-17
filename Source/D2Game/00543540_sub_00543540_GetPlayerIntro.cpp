struct D2PlrIntroStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
};

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

struct D2UnitStrc
{
    char unk0x00[0x74];
    D2QuestChainStrc* pQuestEventList;
};

struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
    unsigned int dwClass;
    unsigned int dwHcIdx;
    char unk0x0C[0x28];
};

struct D2DataTablesStrc
{
    char unk0x000[0xAD4];
    D2SuperUniquesTxt* pSuperUniquesTxt;
    char unk0xAD8[0x4];
    int nSuperUniquesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

// 0x00543540
D2PlrIntroStrc* __fastcall sub_00543540_GetPlayerIntro(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
}

// 0x00543560
int __fastcall sub_00543560_GetSuperUniqueHcIdx(int nSuperUnique)
{
    if (nSuperUnique >= 0 && nSuperUnique < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUnique].dwHcIdx;
    }
    return -1;
}

// 0x00543690
D2QuestDataStrc* __fastcall sub_00543690_FindQuestEvent(D2UnitStrc* pUnit, int nQuestId)
{
    for (D2QuestChainStrc* i = pUnit->pQuestEventList; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }

        if (i->pQuestData->nQuestNo == nQuestId)
        {
            return i->pQuestData;
        }
    }

    return 0;
}
