struct D2LaunchAddressStrc
{
    int nData0;
    int nData1;
    int nData2;
    int nData3;
};

void* __stdcall sub_006BC810_LookupHandle(int nKey);                                                        // 0x006BC810
int __fastcall sub_0040DEE0_QueryAddress(void* pHandle, D2LaunchAddressStrc* pAddress, int* pSize);         // 0x0040DEE0
extern int gnLaunchKey_00798FB4;                                                                            // 0x00798FB4

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
