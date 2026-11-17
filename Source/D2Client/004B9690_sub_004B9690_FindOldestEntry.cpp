struct D2HintCursorStrc
{
    char unk0x00[0x60];
    int nGroup;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x1C];
    void* pKeyList;
    char unk0x2C[4];
    int nState;
    unsigned int dwTick;
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
int __fastcall sub_005169D0_ListHasKey(void* pKeyList, int nKey);                                           // 0x005169D0

extern D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                       // 0x007C5458

// 0x004B9690
D2TimedHintEntryStrc* __stdcall sub_004B9690_FindOldestEntry(int nGroup, int nKey, D2TimedHintEntryStrc* pExclude)
{
    D2TimedHintEntryStrc* pOldest = 0;
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (gpTimedHintList_007C5458)
    {
        for (; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->f_0;
            if (sub_00481860(pEntry->nHintId)->nGroup == nGroup && pEntry != pExclude && pEntry->nState == 1
                && (!nKey || sub_005169D0_ListHasKey(pEntry->pKeyList, nKey)) && (!pOldest || pEntry->dwTick < pOldest->dwTick))
            {
                pOldest = pEntry;
            }
        }
    }

    return pOldest;
}
