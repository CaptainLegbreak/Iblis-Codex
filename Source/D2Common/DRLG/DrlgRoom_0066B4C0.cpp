struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc
{
    char unk0x00[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x14[0x8];
    D2DrlgCoordStrc tCoords;
    char unk0x2C[0x188];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgOrthStrc
{
    void* pTarget;
    int nDirection;
    int bPreset;
    int bInit;
    D2DrlgCoordStrc* pBox;
    D2DrlgOrthStrc* pNext;
};

struct D2RoomTileStrc
{
    void* pUnused;
    D2RoomTileStrc* pNext;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    char unk0x04[0x20];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    int unk0x2C;
    void* pRoom;
    D2DrlgCoordStrc tCoords;
    char unk0x44[0x8];
    D2RoomTileStrc* pRoomTiles;
    char unk0x50[0x8];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x4];
    unsigned int dwOtherFlags;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom);                       // 0x0066F1A0

// 0x0066B4C0
void __fastcall sub_0066B4C0(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags)
{
    pDrlgRoom->pRoom = 0;
    pDrlgRoom->dwOtherFlags = nFlags & 1;
    if (pDrlgRoom->dwFlags & 0x100000)
    {
        DRLGROOMTILE_FreeRoom(pDrlgRoom, bClient == 0);
    }
}

// 0x0066B4F0
void __fastcall DRLGROOM_FreeRoomTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles;
    while (pRoomTile)
    {
        D2RoomTileStrc* pFree = pRoomTile;
        pRoomTile = pRoomTile->pNext;
        sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgRoom.cpp", 88, 0);
    }

    pDrlgRoom->pRoomTiles = 0;
}

// 0x0066B530
void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2DrlgOrthStrc* pDrlgRoomData)
{
    D2DrlgOrthStrc* pRoomData = pDrlgRoomData;
    while (pRoomData)
    {
        D2DrlgOrthStrc* pFree = pRoomData;
        pRoomData = pRoomData->pNext;
        sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgRoom.cpp", 189, 0);
    }
}

// 0x0066B560
void __fastcall sub_0066B560(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection)
{
    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom1->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->pTarget == pDrlgRoom2)
        {
            return;
        }
    }

    D2DrlgOrthStrc* pNew = (D2DrlgOrthStrc*)sub_0040B430(pDrlgRoom1->pLevel->pDrlg->pMempool, sizeof(D2DrlgOrthStrc), ".\\DRLG\\DrlgRoom.cpp", 212, 0);
    memset(pNew, 0, sizeof(D2DrlgOrthStrc));
    pNew->pNext = pDrlgRoom1->pDrlgOrth;
    pDrlgRoom1->pDrlgOrth = pNew;
    pNew->pTarget = pDrlgRoom2;
    pNew->nDirection = nDirection;
    pNew->bInit = 1;
    pNew->pBox = &pDrlgRoom2->tCoords;
}

// 0x0066B5E0
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection)
{
    sub_0066B560(pDrlgRoom1, pDrlgRoom2, nDirection);
    sub_0066B560(pDrlgRoom2, pDrlgRoom1, (nDirection - 2) & 3);
}

// 0x0066B610
void __fastcall sub_0066B610(void* pMemPool, D2DrlgOrthStrc** ppDrlgOrth, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgOrthStrc* pDrlgOrth = *ppDrlgOrth;
    D2DrlgOrthStrc* pNext = pDrlgOrth->pNext;
    if (pDrlgOrth->bInit == 1 && pDrlgOrth->pTarget == pDrlgRoom)
    {
        *ppDrlgOrth = pNext;
        pNext = pDrlgOrth;
    }
    else
    {
        if (!pNext)
        {
            return;
        }

        while (pNext->bInit != 1 || pNext->pTarget != pDrlgRoom)
        {
            pDrlgOrth = pNext;
            pNext = pNext->pNext;
            if (!pNext)
            {
                return;
            }
        }

        pDrlgOrth->pNext = pNext->pNext;
    }

    sub_0040B480(pMemPool, pNext, ".\\DRLG\\DrlgRoom.cpp", 277, 0);
}

// 0x0066B670
void __fastcall sub_0066B670(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    sub_0066B610(pMemPool, &pDrlgRoom1->pDrlgOrth, pDrlgRoom2);
    sub_0066B610(pMemPool, &pDrlgRoom2->pDrlgOrth, pDrlgRoom1);
}

// 0x0066B900
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pIgnoredRoom, int nMargin)
{
    for (D2DrlgRoomStrc* pCurrentRoomEx = pLevel->pFirstRoomEx; pCurrentRoomEx; pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext)
    {
        if (pCurrentRoomEx != pDrlgRoom1 && pCurrentRoomEx != pIgnoredRoom)
        {
            int nDistanceX;
            if (pDrlgRoom1->tCoords.nPosX < pCurrentRoomEx->tCoords.nPosX)
            {
                nDistanceX = pCurrentRoomEx->tCoords.nPosX - pDrlgRoom1->tCoords.nWidth - pDrlgRoom1->tCoords.nPosX;
            }
            else
            {
                nDistanceX = pDrlgRoom1->tCoords.nPosX - pCurrentRoomEx->tCoords.nWidth - pCurrentRoomEx->tCoords.nPosX;
            }

            int nDistanceY;
            if (pDrlgRoom1->tCoords.nPosY < pCurrentRoomEx->tCoords.nPosY)
            {
                nDistanceY = pCurrentRoomEx->tCoords.nPosY - pDrlgRoom1->tCoords.nHeight - pDrlgRoom1->tCoords.nPosY;
            }
            else
            {
                nDistanceY = pDrlgRoom1->tCoords.nPosY - pCurrentRoomEx->tCoords.nHeight - pCurrentRoomEx->tCoords.nPosY;
            }

            if (!(nDistanceX >= nMargin || nDistanceY >= nMargin))
            {
                return 0;
            }
        }
    }

    return 1;
}
