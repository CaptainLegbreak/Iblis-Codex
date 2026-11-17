extern unsigned int gaMaskTable_0074C3F0[]; // 0x0074C3F0

struct D2MaskKeyStrc
{
    unsigned int nValue;
};

struct D2MaskPairStrc
{
    D2MaskKeyStrc tKey;
    unsigned int nMaskIndex;
};

struct D2MaskPairListStrc
{
    char unk0x00[0x48];
    D2MaskPairStrc aPairs[0x100];
    int nCount;

    int __thiscall sub_006BF660_HasMaskedKey(unsigned int nMask);
};

// 0x006BF660
int __thiscall D2MaskPairListStrc::sub_006BF660_HasMaskedKey(unsigned int nMask)
{
    const int n = nCount;
    for (int i = 0; i < n; ++i)
    {
        const D2MaskKeyStrc tKey = aPairs[i].tKey;
        if ((gaMaskTable_0074C3F0[aPairs[i].nMaskIndex] & nMask) == tKey.nValue)
            return 1;
    }
    return 0;
}

#include "gen/data/Source/Storm/006BF660_sub_006BF660_HasMaskedKey.inc"
