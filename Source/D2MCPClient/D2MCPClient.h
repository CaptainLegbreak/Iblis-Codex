#pragma once

char* __fastcall sub_0040E080_AddressToString(int nAddress); // 0x0040E080
int __stdcall sub_006BC8A0_SendBuffer(void* pConnection, const unsigned char* pBuffer, int nSize); // 0x006BC8A0
void __stdcall sub_00449BF0_SetValue(int nValue); // 0x00449BF0
void __stdcall sub_00449C20_SetValue(int nValue); // 0x00449C20
struct D2LaunchAddressStrc
{
    int nData0;
    int nData1;
    int nData2;
    int nData3;
};
struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};
