struct D2BnSizedReplyStrc;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern D2BnSizedReplyStrc* gpSizedReply_008818D4;                                                           // 0x008818D4
extern int gbDnsPending_008818E0;                                                                           // 0x008818E0
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0

// 0x0051B3B0
void __cdecl sub_0051B3B0_FreeSizedReply()
{
    if (gpSizedReply_008818D4)
    {
        FOG_Free(gpSizedReply_008818D4, ".\\BnSend.cpp", 0x3B2, 0);
    }
    gpSizedReply_008818D4 = 0;
}

// 0x0051BEA0
long __cdecl sub_0051BEA0_GetConnected()
{
    return InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
}

// 0x0051BED0
void __fastcall sub_0051BED0_SetDnsPending(int bPending)
{
    gbDnsPending_008818E0 = bPending;
    Sleep(10);
}
