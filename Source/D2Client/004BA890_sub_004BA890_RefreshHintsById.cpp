struct D2HintCursorStrc
{
    char unk0x00[0x40];
    unsigned char nRefreshCount;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x24];
    int nState;
    char unk0x34[9];
    char f_3D[4];
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
int __fastcall sub_00481890_GetHintGroup(int nId);                                                          // 0x00481890
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0

extern D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                       // 0x007C5458

// 0x004BA890
void __fastcall sub_004BA890_RefreshHintsById(int nHintId)
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (pEntry->nHintId == nHintId)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}

// 0x004BA950
void __fastcall sub_004BA950_RefreshHintsInRangeA(int nGroupA, int nGroupB)
{
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (!gpTimedHintList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (sub_00481890_GetHintGroup(pEntry->nHintId) != nGroupA && sub_00481890_GetHintGroup(pEntry->nHintId) != nGroupB
            && pEntry->nHintId >= 0x34 && pEntry->nHintId <= 0x47)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}

// 0x004BA9D0
void __fastcall sub_004BA9D0_RefreshHintsInRangeB(int nGroupA, int nGroupB)
{
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (!gpTimedHintList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (sub_00481890_GetHintGroup(pEntry->nHintId) != nGroupA && sub_00481890_GetHintGroup(pEntry->nHintId) != nGroupB
            && pEntry->nHintId >= 0x48 && pEntry->nHintId <= 0xC9)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}
