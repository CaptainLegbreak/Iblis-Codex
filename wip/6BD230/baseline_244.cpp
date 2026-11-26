void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

// 0x006BD230
int __stdcall sub_006BD230_AddCode(D2TxtLinkStrc* pLink, unsigned int nKey)
{
    D2_ASSERT(pLink, 0x3D1);
    D2_ASSERT(!pLink->pFirstNode, 0x3D8);

    if (pLink->unk_04 <= pLink->count)
    {
        int nNewCapacity = pLink->unk_04 + 0x40;
        pLink->entries = (D2TxtLinkEntryStrc*)FOG_ReallocPool(0, pLink->entries,
            nNewCapacity * sizeof(D2TxtLinkEntryStrc), ".\\Src\\Excel\\Excel.cpp", 0x3DF, 0);
        memset(&pLink->entries[pLink->unk_04], 0, 0x40 * sizeof(D2TxtLinkEntryStrc));
        pLink->unk_04 = nNewCapacity;
    }

    int nLow;
    for (;;)
    {
        D2TxtLinkEntryStrc* pEntries = pLink->entries;
        nLow = 0;
        int nHigh = pLink->count;
        while (nLow < nHigh)
        {
            int nMid = nLow + (nHigh - nLow) / 2;
            unsigned int nMidKey = pEntries[nMid].nCode;
            if (nKey > nMidKey)
                nLow = nMid + 1;
            else if (nKey < nMidKey)
                nHigh = nMid;
            else
                goto found;
        }
        break;
    found:
        ++nKey;
    }

    if (nLow < pLink->count)
    {
        memmove(&pLink->entries[nLow + 1], &pLink->entries[nLow],
            (pLink->count - nLow) * sizeof(D2TxtLinkEntryStrc));
    }

    pLink->entries[nLow].nCode = nKey;
    return pLink->entries[nLow].index = pLink->count++;
}
