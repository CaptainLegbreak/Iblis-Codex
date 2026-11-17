struct D2Object006BE390Strc
{
    unsigned char unk_000[0xBA8];
    int anSlots[1];
};

// 0x006BE390
int __stdcall sub_006BE390_SwapSlot(D2Object006BE390Strc* pObject, int nIndex, int nValue)
{
    int nOld = pObject->anSlots[nIndex];
    if (nValue)
        pObject->anSlots[nIndex] = nValue;
    return nOld;
}
