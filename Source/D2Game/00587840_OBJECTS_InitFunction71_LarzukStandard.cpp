struct D2ActiveRoomStrc;
struct D2GameStrc;
struct Unit0058F000;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x4];
    int dwUnitId;
    char pad0x10[0xB4];
    unsigned int dwFlags;
};

struct D2MapAIStrc
{
    int nPathNodes;
    void* pPosition;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    char pad0x0C[0x8];
    int nX;
    int nY;
};

struct D2QuestDataStrc
{
    char pad0x00[0x18];
    void* pQuestDataEx;
};

struct D2Act5Quest1Strc
{
    D2MapAIStrc* pLarzukMapAI;
    D2ActiveRoomStrc* pRoom;
    char pad0x08[0x8];
    int nLarzukGUID;
    char pad0x14[0x1];
    unsigned char bLarzukSpawned;
    char pad0x16[0x1];
    unsigned char bLarzukMapAIChanged;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
extern "C" unsigned int* __stdcall sub_0058F000(Unit0058F000* pUnit);                                    // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);               // 0x00666120

// 0x00587840
void __fastcall OBJECTS_InitFunction71_LarzukStandard(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x1F);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;
    QUESTS_GetFreePosition(pOp->pRoom, &pCoord, 2, 0x100, &pRoom, 16, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pLarzuk = D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pRoom, pCoord.nX, pCoord.nY, 0x1FF, 1, 5, 0);
    if (!pLarzuk)
    {
        return;
    }

    pQuestDataEx->bLarzukSpawned = 1;
    pQuestDataEx->nLarzukGUID = !pLarzuk ? -1 : pLarzuk->dwUnitId;
    pLarzuk->dwFlags |= 0x3000000;

    if (pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, (D2MapAIStrc*)sub_0058F000((Unit0058F000*)pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}
