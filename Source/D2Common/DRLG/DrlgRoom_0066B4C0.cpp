#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgTiles.h"


struct D2DrlgRoomStrc;





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
        if (pDrlgOrth->pRoom == pDrlgRoom2)
        {
            return;
        }
    }

    D2DrlgOrthStrc* pNew = (D2DrlgOrthStrc*)sub_0040B430(pDrlgRoom1->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgOrthStrc), ".\\DRLG\\DrlgRoom.cpp", 212, 0);
    memset(pNew, 0, sizeof(D2DrlgOrthStrc));
    pNew->pNext = pDrlgRoom1->pDrlgOrth;
    pDrlgRoom1->pDrlgOrth = pNew;
    pNew->pRoom = pDrlgRoom2;
    pNew->nDirection = nDirection;
    pNew->bInit = 1;
    pNew->pBox = &pDrlgRoom2->pDrlgCoord;
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
    if (pDrlgOrth->bInit == 1 && pDrlgOrth->pRoom == pDrlgRoom)
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

        while (pNext->bInit != 1 || pNext->pRoom != pDrlgRoom)
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
    for (D2DrlgRoomStrc* pCurrentRoomEx = pLevel->ptRoomFirst; pCurrentRoomEx; pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext)
    {
        if (pCurrentRoomEx != pDrlgRoom1 && pCurrentRoomEx != pIgnoredRoom)
        {
            int nDistanceX;
            if (pDrlgRoom1->pDrlgCoord.nPosX < pCurrentRoomEx->pDrlgCoord.nPosX)
            {
                nDistanceX = pCurrentRoomEx->pDrlgCoord.nPosX - pDrlgRoom1->pDrlgCoord.nWidth - pDrlgRoom1->pDrlgCoord.nPosX;
            }
            else
            {
                nDistanceX = pDrlgRoom1->pDrlgCoord.nPosX - pCurrentRoomEx->pDrlgCoord.nWidth - pCurrentRoomEx->pDrlgCoord.nPosX;
            }

            int nDistanceY;
            if (pDrlgRoom1->pDrlgCoord.nPosY < pCurrentRoomEx->pDrlgCoord.nPosY)
            {
                nDistanceY = pCurrentRoomEx->pDrlgCoord.nPosY - pDrlgRoom1->pDrlgCoord.nHeight - pDrlgRoom1->pDrlgCoord.nPosY;
            }
            else
            {
                nDistanceY = pDrlgRoom1->pDrlgCoord.nPosY - pCurrentRoomEx->pDrlgCoord.nHeight - pCurrentRoomEx->pDrlgCoord.nPosY;
            }

            if (!(nDistanceX >= nMargin || nDistanceY >= nMargin))
            {
                return 0;
            }
        }
    }

    return 1;
}
