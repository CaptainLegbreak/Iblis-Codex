void __cdecl sub_0041A880_StartThread();                                                                    // 0x0041A880

static void* ghStormThread_00779034; // 0x00779034
static unsigned long gdwStormThreadId_00779040; // 0x00779040

// 0x0041A8D0
void __fastcall sub_0041A8D0_GetThread(unsigned long* pdwThreadId, void** phThread)
{
    sub_0041A880_StartThread();
    *pdwThreadId = gdwStormThreadId_00779040;
    *phThread = ghStormThread_00779034;
}
