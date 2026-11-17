extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840

struct D2StormBlockEntryStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;
    unsigned int nFileSize;
    unsigned int dwFlags;
};

struct D2StormBlockStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;

    unsigned int nFileSize;
    unsigned int dwFlags;
    unsigned int unk0x10;
    unsigned int unk0x14;
    unsigned int nCrc;
    unsigned int unk0x1C[4];

    void sub_004156A0_ExpandEntries(unsigned int nCount);
};

// 0x004156A0
void D2StormBlockStrc::sub_004156A0_ExpandEntries(unsigned int nCount)
{
    D2StormBlockEntryStrc* pSrc = (D2StormBlockEntryStrc*)this + nCount - 1;
    D2StormBlockStrc* pRec = this + nCount - 1;
    if (nCount > 1)
    {
        unsigned int* pClear = &pRec->unk0x1C[2];
        unsigned int nLeft = nCount - 1;
        do
        {
            memmove(pRec, pSrc, sizeof(D2StormBlockEntryStrc));
            --pSrc;
            pClear[-4] = 0;
            pClear[-5] = 0;
            pClear[-3] = 0;
            pClear[-2] = 0;
            pClear[-1] = 0;
            pClear[0] = 0;
            pClear[1] = 0;
            --pRec;
            pClear -= sizeof(D2StormBlockStrc) / sizeof(unsigned int);
        } while (--nLeft);
    }
    if (nCount)
    {
        pRec->unk0x14 = 0;
        pRec->unk0x10 = 0;
        pRec->nCrc = 0;
        pRec->unk0x1C[0] = 0;
        pRec->unk0x1C[1] = 0;
        pRec->unk0x1C[2] = 0;
        pRec->unk0x1C[3] = 0;
    }
}
