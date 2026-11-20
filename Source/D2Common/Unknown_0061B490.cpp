#include "D2Common.h"

struct D2DrlgStrc;

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int eLevelId;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x08];
    D2DrlgRoomStrc** ppRoomsNear;
    unsigned short wRoomsInList[4];
    char unk0x14[0x18];
    int nRoomsNear;
    char unk0x30[0x14];
    unsigned char fRoomStatus;
    char unk0x45[0x13];
    D2DrlgLevelStrc* ptDrlgLevel;
};
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel); // 0x00642C30
void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B5B0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730

static bool RoomExHasRefCount(D2DrlgRoomStrc* pDrlgRoom, int nMaxStatus)
{
    for (int i = 0; i <= nMaxStatus; i++)
    {
        if (pDrlgRoom->wRoomsInList[i])
        {
            return true;
        }
    }
    return false;
}

// 0x0061B490
static void DRLGACTIVATE_RoomSetAndPropagateStatus(unsigned char nStatus, D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExPropagateSetStatus(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, pDrlgRoom, nStatus + 1);
    const int nIndex = nStatus;
    if (pDrlgRoom->fRoomStatus >= nIndex)
    {
        if (!RoomExHasRefCount(pDrlgRoom, nIndex))
        {
            gRoomExSetStatus[nIndex](pDrlgRoom);
        }
    }
    ++pDrlgRoom->wRoomsInList[nIndex];
}

void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoomHint)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (pDrlgRoomHint && pDrlgRoomHint->ptDrlgLevel->eLevelId != nLevelId)
    {
        pDrlgRoomHint = 0;
    }
    D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, pDrlgRoomHint, pLevel);
    if (!pDrlgRoom->wRoomsInList[1])
    {
        DRLGACTIVATE_RoomSetAndPropagateStatus(1, pDrlgRoom);
    }
}

void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pPreviousRoom, D2DrlgRoomStrc* pNewRoom)
{
    if (pPreviousRoom == pNewRoom)
    {
        return;
    }
    if (pNewRoom)
    {
        DRLGACTIVATE_RoomSetAndPropagateStatus(0, pNewRoom);
    }
    if (pPreviousRoom && pPreviousRoom->wRoomsInList[0])
    {
        --pPreviousRoom->wRoomsInList[0];
        gRoomExUnsetStatus[0](pPreviousRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pPreviousRoom, 1);
    }
}

// 0x0061B5B0
void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        D2DrlgRoomStrc* pNearRoom = pDrlgRoom->ppRoomsNear[i];
        if (pNearRoom)
        {
            --pNearRoom->wRoomsInList[nStatus];
            gRoomExUnsetStatus[nStatus](pNearRoom);
            if (nStatus < 3)
            {
                DRLGACTIVATE_RoomExPropagateUnsetStatus(pNearRoom, nStatus + 1);
            }
        }
    }
}

// 0x0061B690
void __fastcall DRLGACTIVATE_UnsetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoomHint)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (pDrlgRoomHint && pDrlgRoomHint->ptDrlgLevel->eLevelId != nLevelId)
    {
        pDrlgRoomHint = 0;
    }
    D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, pDrlgRoomHint, pLevel);
    if (pDrlgRoom && pDrlgRoom->wRoomsInList[1])
    {
        --pDrlgRoom->wRoomsInList[1];
        gRoomExUnsetStatus[1](pDrlgRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pDrlgRoom, 2);
    }
}

// 0x0061B7B0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_StreamRoomAtCoords(D2DrlgStrc* pDrlg, int nX, int nY)
{
    if (D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, 0, 0))
    {
        return DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
    }
    return 0;
}

#include "gen/data/Source/D2Common/Unknown_0061B490.inc"

// 0x0061BAE0
unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->fRoomStatus;
}
