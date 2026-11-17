#include "D2Client.h"

struct D2LaunchAddressStrc;

struct D2LaunchAddressStrc
{
    int nData0;
    int nData1;
    int nData2;
    int nData3;
};

void* __stdcall sub_006BC810_LookupHandle(int nKey); // 0x006BC810
int __fastcall sub_0040DEE0_QueryAddress(void* pHandle, D2LaunchAddressStrc* pAddress, int* pSize); // 0x0040DEE0
extern int gnLaunchKey_00798FB4; // 0x00798FB4

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

// 0x00449B30
int __cdecl sub_00449B30_QueryAddress()
{
    void* pHandle = sub_006BC810_LookupHandle(gnLaunchKey_00798FB4);
    if (!pHandle)
        return 0;
    D2LaunchAddressStrc tAddress;
    int nSize = sizeof(tAddress);
    return sub_0040DEE0_QueryAddress(pHandle, &tAddress, &nSize);
}
