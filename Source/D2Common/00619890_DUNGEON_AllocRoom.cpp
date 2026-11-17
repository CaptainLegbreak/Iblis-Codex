struct D2DrlgRoomStrc;
struct D2DrlgRoomTilesStrc;
struct D2DrlgActStrc;

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    char unk0x04[4];
    D2DrlgRoomTilesStrc* pRoomTiles;
    char unk0x0C[4];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[16];
    int nNumRooms;
    char unk0x28[4];
    D2DrlgActStrc* pAct;
    char unk0x30[4];
    unsigned int dwFlags;
    char unk0x38[20];
    D2DrlgCoordsStrc tCoords;
    D2SeedStrc tSeed;
    char f_74[8];
    D2ActiveRoomStrc* pRoomNext;
};

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

struct D2DrlgActStrc
{
    char unk0x00[16];
    D2ActiveRoomStrc* pRoom;
    char unk0x14[56];
    ACTCALLBACKFN pfnActCallBack;
    char unk0x50[4];
    int bHasPendingRoomsUpdates;
    char unk0x58[4];
    void* pMemPool;
};

typedef char sub_G03_AssertRoomSize[sizeof(D2ActiveRoomStrc) == 0x80 ? 1 : -1];
typedef char sub_G03_AssertRoomSeed[(int)&((D2ActiveRoomStrc*)0)->tSeed == 0x6C ? 1 : -1];
typedef char sub_G03_AssertRoomNext[(int)&((D2ActiveRoomStrc*)0)->pRoomNext == 0x7C ? 1 : -1];
typedef char sub_G03_AssertActPool[(int)&((D2DrlgActStrc*)0)->pMemPool == 0x5C ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall COLLISION_AllocRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom);                  // 0x0064C900
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0066BCF0
int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc** ppRoomList);      // 0x0066BD00
void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom);                       // 0x0066BFC0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00619800
static void __stdcall sub_00619800(void* pMemory, D2ActiveRoomStrc* pRoom)
{
    const int nNear = sub_0066BCF0(pRoom->pDrlgRoom);
    pRoom->ppRoomList = (D2ActiveRoomStrc**)FOG_AllocPool(pMemory, sizeof(D2ActiveRoomStrc*) * nNear, ".\\DUNGEON\\Dungeon.cpp", 256, 0);
    pRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pRoom->pDrlgRoom, pRoom->ppRoomList);
    for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pAdjacentRoom = pRoom->ppRoomList[i];
        D2_ASSERT(pAdjacentRoom, 264);
        if (pAdjacentRoom != pRoom)
            pAdjacentRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pAdjacentRoom->pDrlgRoom, pAdjacentRoom->ppRoomList);
    }
}

// 0x00619890
D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* pAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgRoomTilesStrc* pRoomTiles, int nLowSeed, unsigned int dwFlags)
{
    D2_ASSERT(pAct, 281);

    D2ActiveRoomStrc* pRoom = (D2ActiveRoomStrc*)FOG_AllocPool(pAct->pMemPool, sizeof(D2ActiveRoomStrc), ".\\DUNGEON\\Dungeon.cpp", 245, 0);
    memset(pRoom, 0, sizeof(D2ActiveRoomStrc));

    pRoom->dwFlags = dwFlags;
    SEED_InitLowSeed(&pRoom->tSeed, nLowSeed);

    pRoom->pDrlgRoom = pDrlgRoom;
    pRoom->tCoords = *pDrlgCoords;
    pRoom->pRoomTiles = pRoomTiles;
    pRoom->pRoomNext = pAct->pRoom;
    pAct->pRoom = pRoom;
    pAct->bHasPendingRoomsUpdates = 1;
    pRoom->pAct = pAct;

    DRLGROOM_SetRoom(pDrlgRoom, pRoom);
    sub_00619800(pAct->pMemPool, pRoom);
    COLLISION_AllocRoomCollisionGrid(pAct->pMemPool, pRoom);

    if (pAct->pfnActCallBack)
    {
        pAct->pfnActCallBack(pRoom);
    }

    return pRoom;
}
