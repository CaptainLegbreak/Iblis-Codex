struct D2DrlgStrc;
struct D2ActiveRoomStrc;
struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc
{
    char unk0x000[0x1D0];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x08];
    D2DrlgRoomStrc** ppRoomsNear;
    unsigned short wRoomsInList[4];
    char unk0x14[0x18];
    int nRoomsNear;
    char unk0x30[0x28];
    D2DrlgLevelStrc* pLevel;
};

extern void (__fastcall* gRoomExUnsetStatus[4])(D2DrlgRoomStrc*);                                           // 0x00744394
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel); // 0x00642C30
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                      // 0x0061B730

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
    if (pDrlgRoomHint && pDrlgRoomHint->pLevel->nLevelId != nLevelId)
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

#include "gen/data/Source/D2Common/0061B5B0_DRLGACTIVATE_RoomExPropagateUnsetStatus.inc"
