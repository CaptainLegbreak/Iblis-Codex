struct TSLink
{
    TSLink* pPrevLink;
    TSLink* pNextLink;
    void Unlink(); // 0x005174E2
    TSLink* sub_005176B4_DeletingDtor(unsigned int nFlags);
};

void __cdecl operator delete(void* pMemory);
// build: symbol ??3@YAXPAX@Z 0x004053F0

// 0x005176B4
TSLink* TSLink::sub_005176B4_DeletingDtor(unsigned int nFlags)
{
    Unlink();
    if (nFlags & 1)
        operator delete(this);
    return this;
}
