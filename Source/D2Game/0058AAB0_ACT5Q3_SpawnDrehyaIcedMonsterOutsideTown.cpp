struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2MonsterInteractStrc;
struct D2DynamicPathStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    void* unk0x00;
    void* pPosition;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0x84];
    int unk0x84;
    int unk0x88;
    int nTimerInvocations;
    unsigned char bDrehyaIcedMonsterSpawned;
    unsigned char bDrehyaMonsterInTownSpawned;
    unsigned char bNilathakOutsideTownSpawned;
    unsigned char bNihlathakMonsterInTownSpawned;
    int nDrehyaMonsterInTownGUID;
    int nDrehyaIcedMonsterGUID;
    int NihlathakMonsterInTownGUID;
    int nNihlathakOutsideTownGUID;
    unsigned char bFrozenAnyaObjectSpawned;
    unsigned char pad0xA5[3];
    int nFrozenDrehyaObjectGUID;
    unsigned char bMalahIntroActivated;
    unsigned char bChangeToSpecialObjectModeOutsideTown;
    unsigned char bChangeToSpecialObjectModeInTown;
    unsigned char pad0xAF;
    unsigned char unused0xB0;
    unsigned char bDrehyaPortalOutsideTownSpawned;
    unsigned char bDrehyaPortalInTownSpawned;
    unsigned char unused0xB3;
    int nDrehyaPortalInTownGUID;
    char unk0xB8[0x29];
    unsigned char bDrehyaInTownInitialized;
    unsigned char bDefrostPotionAcquired;
    unsigned char bDrehyaIcedRemoved;
    int nDrehyaObjectInTownGUID;
    D2CoordStrc pDrehyaObjectInTownCoords;
    D2CoordStrc pDrehyaObjectOutsideTownCoords;
    int nDrehyaObjectOutsideTownGUID;
    int nFrozenAnyaObjectGUID;
    unsigned char bTimerActive;
    unsigned char bMalahActivated;
    unsigned char bRewarded;
    unsigned char pad0x103;
    D2MapAIStrc* pDrehyaMapAI;
    D2MapAIStrc* pNilathakMapAI;
    unsigned char bDrehyaMapAIChanged;
    unsigned char bNilathakMapAIChanged;
    unsigned char pad0x10E[2];
    int nNihlathakObjectInTownGUID;
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
    D2Act5Quest3Strc* pQuestDataEx;
    char unk0x1C[0xC4];
    int nQuestFilter;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall QUESTS_SpawnCriticalMonster(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int a5, int nMonsterId); // 0x005459A0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                       // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);               // 0x00666120
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x00589160

// 0x0058AAB0
bool __fastcall ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaIcedMonsterSpawned)
    {
        D2UnitStrc* pFrozenDrehya = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nFrozenAnyaObjectGUID);
        if (!pQuestDataEx->nTimerInvocations)
        {
            if (pFrozenDrehya)
            {
                UNITS_ChangeAnimMode(pFrozenDrehya, 2);
                UNITS_FreeCollisionPath(pFrozenDrehya);
            }

            pQuestDataEx->nTimerInvocations = 1;
        }
        else if (pQuestDataEx->nTimerInvocations == 1)
        {
            pQuestDataEx->nTimerInvocations = 2;
            if (pFrozenDrehya)
            {
                D2UnitStrc* pDrehya = QUESTS_SpawnCriticalMonster(pGame, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY, UNITS_GetRoom(pFrozenDrehya), 1, 0x20F);
                if (pDrehya)
                {
                    const int nUnitGUID = pFrozenDrehya->dwUnitId;
                    const int nUnitType = pFrozenDrehya->dwUnitType;
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pFrozenDrehya), nUnitType, nUnitGUID);
                    UNITROOM_RemoveUnitFromRoom(pFrozenDrehya);

                    D2MapAIStrc* pMapAi = AIGENERAL_GetMapAiFromUnit(pDrehya);
                    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
                    {
                        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, pMapAi);
                        pQuestDataEx->bDrehyaMapAIChanged = 1;
                    }

                    const int nDrehyaGUID = (pDrehya ? pDrehya->dwUnitId : -1);
                    pQuestDataEx->nDrehyaIcedMonsterGUID = nDrehyaGUID;
                    pQuestDataEx->bDrehyaIcedMonsterSpawned = 1;
                    ACT5Q3_SeqCallback(pQuestData);
                    pQuestDataEx->bTimerActive = 0;
                    return true;
                }
            }
        }
    }

    return false;
}
