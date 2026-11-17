struct D2ChainRecordStrc
{
    unsigned short wId;
    unsigned short wParent;
    unsigned short wNext;
    char unk0x06[0x4A - 0x06];
    unsigned char nDepth;
    unsigned char nRoot;
    char unk0x4C[0x1A8 - 0x4C];
};

extern D2ChainRecordStrc* gpChainTable_0096C6A8; // 0x0096C6A8
extern int gnChainCount_0096C6B0; // 0x0096C6B0

// 0x00651040
void __cdecl sub_00651040_ComputeDepths()
{
    for (short i = 0; i < gnChainCount_0096C6B0; ++i)
    {
        unsigned short nNext = gpChainTable_0096C6A8[i].wParent;
        int nDepth = 0;
        unsigned int nId = nNext;
        __assume(nId != 0x10000);
        do
        {
            if ((short)nId == i)
            {
                gpChainTable_0096C6A8[i].nRoot = nDepth;
            }
            nNext = gpChainTable_0096C6A8[(short)nId].wNext;
            ++nDepth;
            if ((short)nId == (short)nNext)
            {
                break;
            }
            nId = nNext;
            if (nDepth > 255)
            {
                break;
            }
        }
        while ((short)nId >= 0);
        gpChainTable_0096C6A8[i].nDepth = nDepth;
    }
}
