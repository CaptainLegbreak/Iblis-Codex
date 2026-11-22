extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
struct WNDREC
{
    WNDREC* pPrevLink;
    WNDREC* pNext;
    int nId;
};
struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};
extern D2StormListStrc gIdList_00708860; // 0x00708860

// 0x004209E0
WNDREC* __fastcall FindWindow(int nId)
{
    for (WNDREC* pNode = (WNDREC*)gIdList_00708860.Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
            return pNode;
    }
    return 0;
}
