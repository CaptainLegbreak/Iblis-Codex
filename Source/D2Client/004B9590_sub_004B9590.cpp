struct D2HintRecordStrc
{
    int unk0x00;
    int nValue;
};

struct D2TimedHintEntryStrc
{
    int bUsed;
    int nHintId;
    int nKey;
    char unk0x0C[0x10];
    int nValue1C;
    char unk0x20[0x08];
    D2HintRecordStrc* pRecord;
    void* f_2C;
    int nState;
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                              // 0x007C5458

// 0x004B9590
int __fastcall sub_004B9590(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->f_0;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nState == 1;
            }
        }
    }
    return 0;
}

// 0x004B9610
void* __fastcall sub_004B9610(int nHintId)
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (pEntry->nHintId == nHintId)
        {
            return (void*)pEntry->nKey;
        }
    }
    return 0;
}

// 0x004B9B20
int __fastcall sub_004B9B20(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->f_0;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nValue1C;
            }
        }
    }
    return 0;
}

// 0x004B9BE0
int __fastcall sub_004B9BE0_HasActiveHint(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->f_0;
            if (pEntry->nKey == nKey)
            {
                D2HintRecordStrc* pRecord = pEntry->pRecord;
                if (pRecord && pRecord->nValue)
                {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

// 0x004B9C20
int __cdecl sub_004B9C20_IsSpeechPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0xB76 && pEntry->nHintId <= 0x1230)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9C60
int __cdecl sub_004B9C60_IsSongPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0x1231 && pEntry->nHintId <= 0x125A)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9CA0
int __fastcall sub_004B9CA0_GetHintIdByKey(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->f_0;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nHintId;
            }
        }
    }
    return 0;
}
