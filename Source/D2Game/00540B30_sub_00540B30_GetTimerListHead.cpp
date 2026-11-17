struct D2EventTimerStrc;
struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc
{
    int nArrayIndex;
    D2EventTimerStrc* pHead[5][64];
    D2EventTimerStrc* pTail[5][64];
    D2EventTimerStrc* pInfinite[5];
    D2EventTimerStrc* pCurrent;
    D2EventTimerSlabListStrc* pSlabListHead;
};
struct D2GameStrc
{
    char padding0x00[0x1C];
    void* pMemoryPool;
    char padding0x20[0x88];
    int dwGameFrame;
    char padding0xAC[0x0C];
    D2EventTimerQueueStrc* pTimerQueue;
};
typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc)==0xA20)?1:-1];

extern const int gaSlotRows_006E0B9C[]; // 0x006E0B9C

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
