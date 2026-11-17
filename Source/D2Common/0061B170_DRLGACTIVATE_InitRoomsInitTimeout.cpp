struct D2DrlgStrc;
struct D2DrlgLevelStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x08];
    D2DrlgRoomStrc** ppRoomsNear;
    unsigned short wRoomsInList[4];
    char unk0x14[0x08];
    D2DrlgRoomStrc* pStatusNext;
    char unk0x20[0x0C];
    int nRoomsNear;
    char unk0x30[0x14];
    unsigned char fRoomStatus;
    char unk0x45[0x13];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x90];
};

struct D2DrlgStrc
{
    char unk0x000[0x08];
    int nRoomCount08;
    char unk0x00C[0x94];
    D2DrlgRoomStrc tStatusRoomsLists[4];
    char unk0x450[0x0C];
    unsigned char nRoomsInitTimeout;
    char unk0x45D[0x0B];
    int nRoomCount468;
};

struct D2DrlgTableRefStrc
{
    char unk0x00[0x28];
    int nValue;
    int nIndex;
};

extern void (__fastcall* gRoomExSetStatus[4])(D2DrlgRoomStrc*);                                             // 0x00744384
extern void (__fastcall* gRoomExUnsetStatus[4])(D2DrlgRoomStrc*);                                           // 0x00744394
extern int gaTable_007443E4[];                                                                              // 0x007443E4
static int gnRoomStats_0096C8B8;                                                                            // 0x0096C8B8
static int gnRoomStats_0096C8BC;                                                                            // 0x0096C8BC
static int gnRoomStats_0096C8C0;                                                                            // 0x0096C8C0
static int gnRoomStats_0096C8C4;                                                                            // 0x0096C8C4
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg);                                                          // 0x00642A00
int __fastcall DRLG_IsTownLevel(int nLevelId);                                                              // 0x006426A0
void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus);  // 0x0061B5B0

// 0x0061B170
static __forceinline void DRLGACTIVATE_InitRoomsInitTimeout(D2DrlgStrc* pDrlg)
{
    pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) ? 5 : 7;
}

void __stdcall sub_M121_Emit_0061B170(D2DrlgStrc* pDrlg) { DRLGACTIVATE_InitRoomsInitTimeout(pDrlg); }

// 0x0061B360
static __forceinline void sub_0061B360_SetStatusIfUnreferenced(D2DrlgRoomStrc* pDrlgRoom, int nStatus)
{
    if (pDrlgRoom->fRoomStatus >= nStatus)
    {
        for (int i = 0; i <= nStatus; ++i)
        {
            if (pDrlgRoom->wRoomsInList[i])
            {
                return;
            }
        }
        gRoomExSetStatus[nStatus](pDrlgRoom);
    }
}

void __stdcall sub_M121_Emit_0061B360(D2DrlgRoomStrc* pDrlgRoom, int nStatus) { sub_0061B360_SetStatusIfUnreferenced(pDrlgRoom, nStatus); }

// 0x0061B5A0
static __forceinline void sub_0061B5A0_CallUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    gRoomExUnsetStatus[nStatus](pDrlgRoom);
}

void __stdcall sub_M121_Emit_0061B5A0(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { sub_0061B5A0_CallUnsetStatus(pDrlgRoom, nStatus); }

// 0x0061B610
static __forceinline void sub_0061B610_RoomUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->wRoomsInList[nStatus])
    {
        --pDrlgRoom->wRoomsInList[nStatus];
        gRoomExUnsetStatus[nStatus](pDrlgRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pDrlgRoom, nStatus + 1);
    }
}

void __stdcall sub_M121_Emit_0061B610(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { sub_0061B610_RoomUnsetStatus(pDrlgRoom, nStatus); }

// 0x0061B810
static __forceinline D2DrlgRoomStrc* DRLGACTIVATE_RoomExStatusList_GetFirst(D2DrlgStrc* pDrlg, unsigned char nStatus)
{
    if (pDrlg->tStatusRoomsLists[nStatus].pStatusNext != &pDrlg->tStatusRoomsLists[nStatus])
    {
        return pDrlg->tStatusRoomsLists[nStatus].pStatusNext;
    }
    return 0;
}

D2DrlgRoomStrc* __stdcall sub_M121_Emit_0061B810(D2DrlgStrc* pDrlg, unsigned char nStatus) { return DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, nStatus); }

// 0x0061B8B0
static __forceinline void sub_0061B8B0_UpdateRoomStats(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnRoomStats_0096C8B8 = pDrlg->nRoomCount08;
        gnRoomStats_0096C8BC = pDrlg->nRoomCount468;
    }
    else
    {
        gnRoomStats_0096C8C4 = pDrlg->nRoomCount08;
        gnRoomStats_0096C8C0 = pDrlg->nRoomCount468;
    }
}

void __stdcall sub_M121_Emit_0061B8B0(D2DrlgStrc* pDrlg) { sub_0061B8B0_UpdateRoomStats(pDrlg); }

// 0x0061BA10
static __forceinline int sub_0061BA10_CanUntileLevel(int nLevelId)
{
    if (DRLG_IsTownLevel(nLevelId))
    {
        return 0;
    }
    return nLevelId != 120;
}

int __stdcall sub_M121_Emit_0061BA10(int nLevelId) { return sub_0061BA10_CanUntileLevel(nLevelId); }

// 0x0061BB50
static __forceinline void sub_0061BB50_SetFieldFromTable(D2DrlgTableRefStrc* pRecord)
{
    pRecord->nValue = gaTable_007443E4[pRecord->nIndex];
}

void __stdcall sub_M121_Emit_0061BB50(D2DrlgTableRefStrc* pRecord) { sub_0061BB50_SetFieldFromTable(pRecord); }

#include "gen/data/Source/D2Common/0061B170_DRLGACTIVATE_InitRoomsInitTimeout.inc"
