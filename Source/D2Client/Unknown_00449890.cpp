#include "D2Client.h"

struct D2LaunchAddressStrc;

void* __stdcall sub_006BC810_LookupHandle(int nKey); // 0x006BC810
int __fastcall sub_0040DEE0_QueryAddress(void* pHandle, D2LaunchAddressStrc* pAddress, int* pSize); // 0x0040DEE0
extern int gnLaunchKey_00798FB4; // 0x00798FB4

// build: symbol ?COMCALLBACK_NibbleToHex@* 0x00449840
unsigned int __fastcall COMCALLBACK_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
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
