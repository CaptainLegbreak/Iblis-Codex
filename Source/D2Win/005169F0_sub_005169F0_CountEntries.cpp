struct T00516950
{
    void* pData;
    T00516950* pNext;
};

// 0x005169F0
int __fastcall sub_005169F0_CountEntries(T00516950* pNode)
{
    int nCount = 0;
    while (pNode)
    {
        pNode = pNode->pNext;
        ++nCount;
    }

    return nCount;
}
