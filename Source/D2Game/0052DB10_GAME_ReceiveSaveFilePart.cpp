struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* pOwningThread;
    void* pLockSemaphore;
    unsigned long nSpinCount;
};

#pragma pack(push, 1)
struct D2GSPacketClt6B
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned int nTotalSize;
    unsigned char saveData[8192];
};
#pragma pack(pop)

typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);     // 0x006CC210
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall sub_0052B5C0_SetServerHandler(D2NET_Unk_Callback pfCallback);                                                   // 0x0052B5C0
int __stdcall sub_005300F0_RemoveClientById(int nClientId, int a2, int a3);                                 // 0x005300F0
void __fastcall SUNITPROXY_FillGlobalItemCache();                                                           // 0x00536F80
void __fastcall CLIENTS_Initialize();                                                                       // 0x005376C0
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7); // 0x00538CE0

extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
unsigned long gdwPlayerPos_00883D4C;                                                                        // 0x00883D4C

// 0x0052DB10
int __fastcall GAME_ReceiveSaveFilePart(int nClientId, D2GSPacketClt6B* pPacket)
{
    return CLIENTS_AttachSaveFile(nClientId, pPacket->saveData, pPacket->nSize, pPacket->nTotalSize, 0, 0, 0);
}

// 0x00530690
int __stdcall GAME_Initialize()
{
    SRegLoadValue("Diablo II", "PlayerPos", 0, &gdwPlayerPos_00883D4C);
    for (int i = 0; i < 1024; ++i)
    {
        gnGamesGUIDs_6FD447F8[i] = 0;
    }
    InitializeCriticalSection(&gCriticalSection_6FD45800);
    CLIENTS_Initialize();
    sub_0052B5C0_SetServerHandler((D2NET_Unk_Callback)sub_005300F0_RemoveClientById);
    SUNITPROXY_FillGlobalItemCache();
    return 1;
}
