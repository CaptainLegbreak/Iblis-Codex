extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode);                      // 0x006CC2E4

int gbStormSuppress_007790F0;                                                                               // 0x007790F0
extern unsigned long gdwStormLastError_007790F4;                                                            // 0x007790F4

// 0x0041C340
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode)
{
    gdwStormLastError_007790F4 = dwErrCode;
    SetLastError(dwErrCode);
}

// 0x0041C360
void __stdcall sub_0041C360_SetSuppress(int bSuppress)
{
    gbStormSuppress_007790F0 = bSuppress;
}
