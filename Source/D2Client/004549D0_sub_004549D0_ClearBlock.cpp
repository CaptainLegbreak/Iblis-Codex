struct D2Block0xA0Strc
{
    unsigned short wData[0x50];
};

// 0x004549D0
D2Block0xA0Strc* __fastcall sub_004549D0_ClearBlock(D2Block0xA0Strc* pBlock)
{
    for (int i = 0; i < 0x50; ++i)
        pBlock->wData[i] = 0;
    return pBlock;
}
