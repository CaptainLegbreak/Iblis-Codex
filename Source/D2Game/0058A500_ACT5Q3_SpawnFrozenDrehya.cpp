struct D2ActiveRoomStrc;
struct D2MapAIPathPositionStrc;
struct D2ObjectControlStrc;
struct D2ObjectsTxt;

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xC4 - 0x10];
    unsigned int dwFlags;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

struct D2Act5Quest3Strc
{
    char pad0x00[0x88];
    int unk0x88;
    char pad0x8C[0x6];
    unsigned char bNilathakOutsideTownSpawned;
    unsigned char bNihlathakMonsterInTownSpawned;
    char pad0x94[0x8];
    int NihlathakMonsterInTownGUID;
    int nNihlathakOutsideTownGUID;
    unsigned char bFrozenAnyaObjectSpawned;
    char pad0xA5[0x3];
    int nFrozenDrehyaObjectGUID;
    char pad0xAC[0x108 - 0xAC];
    D2MapAIStrc* pNilathakMapAI;
    char pad0x10C[0x1];
    unsigned char bNilathakMapAIChanged;
    char pad0x10E[0x2];
    int nNihlathakObjectInTownGUID;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    char unk0x0A[0x18 - 0x0A];
    void* pQuestDataEx;
};

struct D2DataTablesStrc
{
    char unk0x000[0xAE0];
    unsigned short nSuperUniqueIds[66];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
D2UnitStrc* __fastcall QUESTS_SpawnCriticalMonster(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int a5, int nMonsterId); // 0x005459A0
extern "C" D2MapAIStrc* __stdcall sub_0058F000(D2UnitStrc* pUnit);                                        // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);               // 0x00666120
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique);                                       // 0x00659B80
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

int __fastcall sub_00586B30_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}

// 0x0058A500
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bFrozenAnyaObjectSpawned)
    {
        return;
    }

    D2UnitStrc* pFrozenDrehya = SUNIT_AllocUnitData(2, 558, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), pGame, UNITS_GetRoom(pUnit), 1, 0, 0);
    if (pFrozenDrehya)
    {
        pFrozenDrehya->dwFlags |= 0x3000000;
        pQuestDataEx->bFrozenAnyaObjectSpawned = 1;
        pQuestDataEx->nFrozenDrehyaObjectGUID = !pFrozenDrehya ? -1 : pFrozenDrehya->dwUnitId;
    }
    else
    {
        sub_005417D0_DirectDated(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0058A610
void __fastcall OBJECTS_InitFunction68_NihlathakStartInTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nNihlathakObjectInTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestDataEx->unk0x88 || pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pNihlathak = QUESTS_SpawnCriticalMonster(pOp->pGame, pOp->nX, pOp->nY, pOp->pRoom, 1, 514);
    if (!pNihlathak)
    {
        return;
    }

    pQuestDataEx->NihlathakMonsterInTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
    pQuestDataEx->bNihlathakMonsterInTownSpawned = 1;

    D2MapAIStrc* pMapAI = sub_0058F000(pNihlathak);
    if (pQuestDataEx->pNilathakMapAI && pQuestDataEx->pNilathakMapAI->pPosition && !pQuestDataEx->bNilathakMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNilathakMapAI, pMapAI);
        pQuestDataEx->bNilathakMapAIChanged = 1;
    }
}

// 0x0058A6C0
void __fastcall OBJECTS_InitFunction69_NihlathakStartOutsideTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x88 != 1 || pQuestDataEx->bNilathakOutsideTownSpawned)
    {
        return;
    }

    const int nMonsterId = DATATBLS_MapSuperUniqueId(2, sub_00586B30_GetSuperUniqueId(60));
    const int nY = pOp->nY;
    const int nX = pOp->nX;
    D2UnitStrc* pNihlathak = D2GAME_SpawnPresetMonster_6FC66560(pOp->pGame, pOp->pRoom, nMonsterId, nX, nY, 1);
    if (pNihlathak)
    {
        pQuestDataEx->nNihlathakOutsideTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
        pQuestDataEx->bNilathakOutsideTownSpawned = 1;
    }
}
