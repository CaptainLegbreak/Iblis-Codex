struct D2ValueNodeStrc
{
    char unk0x00[8];
    int nKey;
    char unk0x0C[0x10];
    int nValue;
};

struct D2ValueLinkStrc
{
    D2ValueNodeStrc* pValue;
    D2ValueLinkStrc* pNext;
};

extern D2ValueLinkStrc* gpValueList_007C5458; // 0x007C5458

// 0x004B9B50
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue)
{
    if (!nKey)
        return;
    D2ValueLinkStrc* pLink = gpValueList_007C5458;
    if (!pLink)
        return;
    do
    {
        D2ValueNodeStrc* pValue = pLink->pValue;
        if (pValue->nKey == nKey)
        {
            pValue->nValue = nValue;
            return;
        }
        pLink = pLink->pNext;
    } while (pLink);
}
