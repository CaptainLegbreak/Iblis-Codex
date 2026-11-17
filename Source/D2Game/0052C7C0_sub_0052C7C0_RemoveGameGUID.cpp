struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220
void __stdcall D2NET_10016(int nClientId);                                                                  // 0x0052B570

// 0x0052C7C0
static __forceinline void sub_0052C7C0_RemoveGameGUID(int nGameGUID)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] == nGameGUID)
        {
            gnGamesGUIDs_6FD447F8[i] = 0;
        }
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);
}

void __fastcall sub_M117_Emit_0052C7C0(int nGameGUID)
{
    sub_0052C7C0_RemoveGameGUID(nGameGUID + 1);
}

// 0x0052CC10
void __fastcall sub_0052CC10_SendHeaderAndRelease(int nClientId)
{
    sub_0053B220_SendHeaderOnly0xB0(nClientId);
    D2NET_10016(nClientId);
}
