struct D2CmpSubTileHeaderStrc
{
    int unk0x00;
    int unk0x04;
    unsigned short nFlags;
    unsigned short nLength;
    int unk0x0C;
};

struct D2CmpSubTileRecordStrc
{
    D2CmpSubTileHeaderStrc tHeader;
    unsigned char* pData;
};

struct D2CmpTileBlockStrc
{
    char unk0x00[0x48];
    int f_48;
    int nSubBytes;
    int nSubs;
    D2CmpSubTileRecordStrc* pSubs;
    char* pName;
    void* pExtra;
};

// 0x0060A260
static __forceinline int sub_0060A260_RelocateSubTileData(D2CmpTileBlockStrc* pBlock, unsigned char* pData)
{
    int nSize = pBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
    for (int j = 0; j < pBlock->nSubs; j++)
    {
        D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
        pSub->pData += (int)pData;
        nSize += pSub->tHeader.nLength;
    }
    return nSize;
}

// 0x0060A620
static __forceinline int sub_0060A620_IsSubTileDataEmpty(const D2CmpSubTileRecordStrc* pRecord)
{
    const unsigned char* pData = pRecord->pData;
    for (int i = 0; i < pRecord->tHeader.nLength; i++)
    {
        if (*pData)
        {
            return 0;
        }
        pData++;
    }
    return 1;
}

int __stdcall sub_M213_Emit_0060A260(D2CmpTileBlockStrc* pBlock, unsigned char* pData)
{
    return sub_0060A260_RelocateSubTileData(pBlock, pData);
}

void __fastcall sub_M213_Emit_0060A620(const D2CmpSubTileRecordStrc* pRecord, int* pResult)
{
    *pResult = sub_0060A620_IsSubTileDataEmpty(pRecord);
}
