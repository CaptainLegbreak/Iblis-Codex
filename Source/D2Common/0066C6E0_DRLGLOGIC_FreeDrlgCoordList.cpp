struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int dwFlags;
};

struct D2RoomCoordListStrc
{
    char unk0x00[0x28];
    int nIndex;
    D2RoomCoordListStrc* pNext;
};

struct D2DrlgLogicalRoomInfoStrc
{
    int dwFlags;
    int nLists;
    D2DrlgGridStrc pIndexX;
    D2DrlgGridStrc pIndexY;
    D2RoomCoordListStrc* pCoordList;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    int nTileXPos;
    int nTileYPos;
    char unk0x3C[0x1C];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x8];
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo;
};

struct D2LogicTargetStrc
{
    char unk0x00[0x10];
    D2RoomCoordListStrc* pCoordList;
};

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                  // 0x00681EF0
#pragma function(memset)
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                           // 0x0067C570
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);                           // 0x0067CD90

// 0x0066C660
D2DrlgLogicalRoomInfoStrc* __fastcall sub_0066C660(void* pMemPool, int nUnused, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = (D2DrlgLogicalRoomInfoStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgLogicalRoomInfoStrc), ".\\DRLG\\DrlgLogic.cpp", 223, 0);
    memset(pLogicalRoomInfo, 0, sizeof(D2DrlgLogicalRoomInfoStrc));
    pDrlgRoom->pLogicalRoomInfo = pLogicalRoomInfo;
    return pLogicalRoomInfo;
}

// 0x0066C6E0
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = pDrlgRoom->pLogicalRoomInfo;

    if (pLogicalRoomInfo)
    {
        if (pLogicalRoomInfo->dwFlags & 2)
        {
            DRLGGRID_FreeGrid(pMemPool, &pLogicalRoomInfo->pIndexX);
            DRLGGRID_FreeGrid(pMemPool, &pLogicalRoomInfo->pIndexY);
        }

        D2RoomCoordListStrc* pRoomCoordList = pLogicalRoomInfo->pCoordList;
        while (pRoomCoordList)
        {
            D2RoomCoordListStrc* pNext = pRoomCoordList->pNext;
            sub_0040B480(pMemPool, pRoomCoordList, ".\\DRLG\\DrlgLogic.cpp", 257, 0);
            pRoomCoordList = pNext;
        }

        sub_0040B480(pMemPool, pLogicalRoomInfo, ".\\DRLG\\DrlgLogic.cpp", 262, 0);
        pDrlgRoom->pLogicalRoomInfo = 0;
    }
}

D2RoomCoordListStrc* __fastcall sub_0066CEB0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);

// 0x0066CE30
int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 668);
        exit(-1);
    }

    D2RoomCoordListStrc* pRoomCoordList;
    if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
    {
        pRoomCoordList = pDrlgRoom->pLogicalRoomInfo->pCoordList;
    }
    else
    {
        int nTileX = nX / 5 - pDrlgRoom->nTileXPos;
        int nTileY = nY / 5 - pDrlgRoom->nTileYPos;
        pRoomCoordList = (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nTileX, nTileY);
    }

    if (pRoomCoordList)
    {
        return pRoomCoordList->nIndex;
    }

    return -1;
}

// 0x0066CEB0
D2RoomCoordListStrc* __fastcall sub_0066CEB0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 668);
        exit(-1);
    }

    if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
    {
        return pDrlgRoom->pLogicalRoomInfo->pCoordList;
    }

    int nTileX = nX / 5 - pDrlgRoom->nTileXPos;
    int nTileY = nY / 5 - pDrlgRoom->nTileYPos;
    return (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nTileX, nTileY);
}

// 0x0066CF30
D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordList(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 717);
        exit(-1);
    }

    return pDrlgRoom->pLogicalRoomInfo->pCoordList;
}
