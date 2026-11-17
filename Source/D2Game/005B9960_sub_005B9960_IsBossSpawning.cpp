struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    unsigned char bGidbinnObjectActivated;
    unsigned char bBossIsSpawning;
    unsigned char bSpawnTimerStarted;
    unsigned char bAltarCanBeActivated;
    unsigned char bGidbinnBroughtToOrmus;
    int nGidbinnX;
    int nGidbinnY;
    int nAltarX;
    int nAltarY;
    unsigned char bGidbinnObjectInitialized;
    unsigned char pad0x19[3];
    int nGidbinnsInGame;
    unsigned char bPlayerWithGidbinnDropped;
    unsigned char pad0x21[3];
    int nFetishBossGUID;
    int nAltarGUID;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x005B9960
unsigned char __fastcall sub_005B9960_IsBossSpawning(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        return ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bBossIsSpawning;
    }
    return 0;
}

// 0x005B9C50
bool __fastcall sub_005B9C50_GetBossGUID(D2GameStrc* pGame, int* pGUID)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return false;
    }
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bBossHasSpawned)
    {
        return false;
    }
    *pGUID = pQuestDataEx->nFetishBossGUID;
    return true;
}

// 0x005B9C80
void __fastcall sub_005B9C80_ClearBossSpawned(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBossHasSpawned == 1 && pQuestDataEx->nFetishBossGUID == (!pUnit ? -1 : pUnit->dwUnitId))
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}
