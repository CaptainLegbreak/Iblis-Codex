extern const unsigned char gnCdKeyMap_006D59F0[256];                                                        // 0x006D59F0

unsigned int __fastcall sub_00449840_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

// 0x00449890
void __fastcall sub_00449890_CdKeyChecksum(char* szKey, unsigned int* pChecksum)
{
    unsigned int nBit = 1;
    *pChecksum = 0;
    for (int i = 0; i < 16; i += 2, nBit <<= 1)
    {
        unsigned int nValue = (char)gnCdKeyMap_006D59F0[(unsigned char)szKey[i]] * 3;
        nValue = (char)gnCdKeyMap_006D59F0[(unsigned char)szKey[i + 1]] + nValue * 8;
        if (nValue >= 0x100)
        {
            nValue -= 0x100;
            *pChecksum |= nBit;
        }
        szKey[i] = (char)sub_00449840_NibbleToHex(nValue >> 4);
        szKey[i + 1] = (char)sub_00449840_NibbleToHex(nValue);
    }
}
