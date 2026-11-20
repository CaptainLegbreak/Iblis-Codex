#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2EventTimer.h"

struct D2EventTimerSlabListStrc;
struct D2EventTimerQueueStrc;
struct D2Unk00540B70Obj;
struct D2Unk00540B70Owner;

typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc)==0xA20)?1:-1];

struct D2Unk00540B70Obj
{
    char unk0x000[0x504];
    int f_504[1];
};

struct D2Unk00540B70Owner
{
    char unk0x00[0xB8];
    D2Unk00540B70Obj* pObj;
};

// 0x00540B30
static D2EventTimerStrc** __fastcall sub_00540B30_GetTimerListHead(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
    const int nRow = gaSlotRows_006E0B9C[nUnitType];
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
        return &pQueue->pInfinite[nRow];
    return &pQueue->pHead[nRow][nExpireFrame % 64];
}

D2EventTimerStrc** __fastcall sub_M400_Emit_00540B30(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
    return sub_00540B30_GetTimerListHead(pGame, nExpireFrame + 7, nUnitType);
}

// 0x00540B70
static int* __stdcall sub_00540B70_GetSlot(D2Unk00540B70Owner* pOwner, int nType, int nIndex)
{
    if (nIndex == -1)
    {
        return 0;
    }
    return &pOwner->pObj->f_504[gaSlotRows_006E0B9C[nType] * 64 + nIndex % 64];
}

int* __fastcall sub_K10_EmitGetSlot(D2Unk00540B70Owner* pOwner, int nType)
{
    return sub_00540B70_GetSlot(pOwner, nType, nType + 1);
}
