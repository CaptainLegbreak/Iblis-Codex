extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
void __cdecl sub_00410660_Log(const char* szChannel, const char* szFormat, ...); // 0x00410660
extern const char gszHackChannel_006FC4A8[]; // 0x006FC4A8
extern const char gszHackListSizeFormat_006FC4B0[]; // 0x006FC4B0
extern unsigned long gdwLastLogTick_00989C34; // 0x00989C34

// 0x006BE6C0
void __stdcall sub_006BE6C0_LogHackListSize(int nSize)
{
    const unsigned long dwNow = GetTickCount();
    if (dwNow - gdwLastLogTick_00989C34 > 2000)
    {
        sub_00410660_Log(gszHackChannel_006FC4A8, gszHackListSizeFormat_006FC4B0, nSize);
        gdwLastLogTick_00989C34 = dwNow;
    }
}
