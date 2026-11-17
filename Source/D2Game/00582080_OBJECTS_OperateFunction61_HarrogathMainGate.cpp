struct D2ActiveRoomStrc;
struct D2DrlgActStrc;
struct D2ObjectControlStrc;
struct D2SeedStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xC0];
    unsigned int dwTickCount;
};

struct D2GameStrc
{
    char unk0x00[0x78];
    unsigned short wItemFormat;
    char unk0x7A[0x2E];
    int dwGameFrame;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2);                                    // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);  // 0x00558D90

// 0x00582080
int __fastcall OBJECTS_OperateFunction61_HarrogathMainGate(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->pObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(pOp->pObject);
    const int nSizeY = UNITS_GetUnitSizeY(pOp->pObject);
    const unsigned int nTickCount = GetTickCount();
    const int nAnimMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;

    if (nTickCount < pOp->pObject->dwTickCount + 500)
    {
        return 1;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    switch (nAnimMode)
    {
    case 0:
        UNITS_FreeCollisionPath(pOp->pObject);
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        pOp->pObject->dwTickCount = nTickCount;
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        break;

    case 2:
        UNITS_BlockCollisionPath(pOp->pObject, pRoom, pCoord.nX, pCoord.nY);
        UNITS_ChangeAnimMode(pOp->pObject, 0);
        pOp->pObject->dwTickCount = nTickCount;
        break;
    }

    return 1;
}

// 0x00585A80
D2UnitStrc* __fastcall sub_00585A80_DropItemWithIdAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemId, int nItemQuality)
{
    if (nItemId < 0)
    {
        return 0;
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2CoordStrc pReturnCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
    if (!pRoom)
    {
        return 0;
    }

    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));
    itemDrop.wItemFormat = pGame->wItemFormat;
    itemDrop.nId = nItemId;
    itemDrop.pUnit = pUnit;
    itemDrop.pSeed = 0;
    itemDrop.pGame = pGame;
    itemDrop.nSpawnType = 3;
    itemDrop.nX = pReturnCoords.nX;
    itemDrop.nY = pReturnCoords.nY;
    itemDrop.pRoom = pRoom;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.nQuality = nItemQuality;
    itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

    return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
}
