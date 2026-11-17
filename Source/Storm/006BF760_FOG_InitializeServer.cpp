struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
struct D2WSADataStrc
{
    unsigned short wVersion;
    unsigned short wHighVersion;
    char szDescription[257];
    char szSystemStatus[129];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    char pad0x18A[2];
    char* lpVendorInfo;
};
struct QServer;
struct D2PacketBufferStrc;
struct D2QNodeStrc;
struct D2QClientStrc;
typedef int (__fastcall* D2NET_ValidatePacketCallback)(D2PacketBufferStrc*, int, int*, int*, int*, int*, int, int, int);
typedef int (__fastcall* D2NET_ClientCallback)(QServer*, int, const char*, int);
typedef int (__fastcall* D2NET_PacketCallback)(int, int, int, int);
typedef int (__fastcall* D2NET_ReadPacketCallback)(QServer*, D2PacketBufferStrc*, int);
struct QServer
{
    int bUseNt;
    int unk004;
    int nClientCapacity;
    int nValue00C;
    int nValue010;
    D2QClientStrc** ppClientSlots;
    int nClientSlotCount;
    D2CriticalSectionStrc* pLocks;
    void** ppSlots020;
    int nSlotCount024;
    D2CriticalSectionStrc tLock028;
    void** ppSlots040;
    int nSlotCount044;
    char unk048[0x804];
    D2QNodeStrc* pChain84C;
    D2QNodeStrc* pChain850;
    D2CriticalSectionStrc tLock854;
    int nState;
    void** ppSlots870;
    void** ppSlots874;
    D2QClientStrc* pClients;
    int nSlotCount87C;
    int nValue880;
    int bStarted884;
    unsigned int nSocket888;
    D2QNodeStrc* pChain88C;
    int nValue890;
    D2CriticalSectionStrc tLock894;
    D2QNodeStrc** ppBuckets;
    int nBuckets;
    D2CriticalSectionStrc tLock8B4;
    char unk8CC[0x2C4];
    unsigned int aSockets[4];
    char unkBA0[0x20];
    D2NET_ValidatePacketCallback pfCallback1;
    D2NET_ClientCallback pfCallback2;
    D2NET_PacketCallback pfCallback3;
    D2NET_ReadPacketCallback pfReadPacket;
    int nValueBD0;
    char unkBD4[0x44];
    int nValueC18;
    char unkC1C[0x30];
};
extern "C" void* __cdecl memset(void* pMemory, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
int __cdecl sub_00410960_IsPlatformNT(); // 0x00410960
void __cdecl sub_006BE300_Nop(const char* szTag, const char* szFormat, QServer* pServer); // 0x006BE300
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3360_Startup(QServer* pServer, int nPort); // 0x006C3360
int __fastcall sub_006C3B50_StartServer(QServer* pServer, int nPort); // 0x006C3B50

static int gnLockCount_0074C3E0; // 0x0074C3E0
static int gnGlobal_0074C3E4; // 0x0074C3E4
static int gnGlobal_0074C3E8; // 0x0074C3E8
static int gnGlobal_0074C3EC; // 0x0074C3EC
static int gnGlobal_00989C28; // 0x00989C28
extern "C" const char gszQServerFile_006FC460[]; // 0x006FC460
extern "C" const char gszQServerTag_006FC47C[]; // 0x006FC47C
extern "C" const char gszQServerAllocated_006FC548[]; // 0x006FC548

struct D2QServerConfigStrc
{
    int nClientCapacity;
    int nValue04;
    int nValue08;
    int nValue0C;
};

// 0x006BE310
void __stdcall sub_006BE310_SetServerConfig(D2QServerConfigStrc* pConfig)
{
    gnLockCount_0074C3E0 = pConfig->nClientCapacity;
    gnGlobal_0074C3E4 = pConfig->nClientCapacity - 1;
    gnGlobal_0074C3E8 = pConfig->nValue04;
    gnGlobal_0074C3EC = pConfig->nValue08;
    gnGlobal_00989C28 = pConfig->nValue0C;
}

// 0x006BF760
QServer* __stdcall FOG_InitializeServer(int nState, int nSlots, int nPort, int bDisableNt, D2NET_ValidatePacketCallback pfCallback1, D2NET_ClientCallback pfCallback2, D2NET_PacketCallback pfCallback3, D2NET_ReadPacketCallback pfReadPacket)
{
    D2WSADataStrc tWsaData;
    QServer* pServer = (QServer*)FOG_Alloc(sizeof(QServer), gszQServerFile_006FC460, 148, 0);
    memset(pServer, 0, sizeof(QServer));
    pServer->nClientCapacity = gnLockCount_0074C3E0;
    pServer->nValue00C = gnGlobal_0074C3E4;
    pServer->nValue010 = gnGlobal_0074C3E8;
    pServer->nValueC18 = gnGlobal_00989C28;
    pServer->nClientSlotCount = gnLockCount_0074C3E0;
    pServer->ppClientSlots = (D2QClientStrc**)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(D2QClientStrc*), gszQServerFile_006FC460, 159, 0);
    memset(pServer->ppClientSlots, 0, gnLockCount_0074C3E0 * sizeof(D2QClientStrc*));
    pServer->pLocks = (D2CriticalSectionStrc*)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(D2CriticalSectionStrc), gszQServerFile_006FC460, 162, 0);
    memset(pServer->pLocks, 0, gnLockCount_0074C3E0 * sizeof(D2CriticalSectionStrc));
    for (int i = 0; i < gnLockCount_0074C3E0; ++i)
        InitializeCriticalSection(&pServer->pLocks[i]);
    pServer->nSlotCount024 = gnLockCount_0074C3E0;
    pServer->ppSlots020 = (void**)FOG_Alloc(gnLockCount_0074C3E0 * sizeof(void*), gszQServerFile_006FC460, 169, 0);
    memset(pServer->ppSlots020, 0, gnLockCount_0074C3E0 * sizeof(void*));
    InitializeCriticalSection(&pServer->tLock028);
    pServer->nSlotCount044 = gnGlobal_0074C3E8;
    pServer->ppSlots040 = (void**)FOG_Alloc(gnGlobal_0074C3E8 * sizeof(void*), gszQServerFile_006FC460, 175, 0);
    memset(pServer->ppSlots040, 0, gnGlobal_0074C3E8 * sizeof(void*));
    pServer->nBuckets = gnGlobal_0074C3EC;
    pServer->ppBuckets = (D2QNodeStrc**)FOG_Alloc(gnGlobal_0074C3EC * sizeof(D2QNodeStrc*), gszQServerFile_006FC460, 180, 0);
    memset(pServer->ppBuckets, 0, gnGlobal_0074C3EC * sizeof(D2QNodeStrc*));
    sub_006BE300_Nop(gszQServerTag_006FC47C, gszQServerAllocated_006FC548, pServer);
    pServer->nValue880 = 0;
    pServer->pChain84C = 0;
    pServer->pChain850 = 0;
    pServer->pfCallback1 = pfCallback1;
    pServer->pfCallback2 = pfCallback2;
    pServer->pfCallback3 = pfCallback3;
    pServer->pfReadPacket = pfReadPacket;
    pServer->nSocket888 = -1;
    pServer->nValue890 = 0;
    pServer->nValueBD0 = 1;
    InitializeCriticalSection(&pServer->tLock894);
    InitializeCriticalSection(&pServer->tLock8B4);
    pServer->aSockets[0] = -1;
    pServer->aSockets[1] = -1;
    pServer->aSockets[2] = -1;
    pServer->aSockets[3] = -1;
    pServer->ppSlots870 = (void**)FOG_Alloc(nSlots * sizeof(void*), gszQServerFile_006FC460, 218, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppSlots870[i] = 0;
    pServer->ppSlots874 = (void**)FOG_Alloc(nSlots * sizeof(void*), gszQServerFile_006FC460, 222, 0);
    for (int i = 0; i < nSlots; ++i)
        pServer->ppSlots874[i] = 0;
    pServer->nSlotCount87C = nSlots;
    pServer->pClients = 0;
    pServer->pChain88C = 0;
    InitializeCriticalSection(&pServer->tLock854);
    if (sub_00410960_IsPlatformNT() && !bDisableNt)
        pServer->bUseNt = 1;
    else
        pServer->bUseNt = 0;
    pServer->nState = nState;
    if (nState != 1 && nState != 2)
    {
        if (!WSAStartup(0x101, &tWsaData))
        {
            if (pServer->bUseNt)
                sub_006C3360_Startup(pServer, nPort);
            else
                sub_006C3B50_StartServer(pServer, nPort);
        }
    }
    return pServer;
}

#include "gen/data/Source/Storm/006BF760_FOG_InitializeServer.inc"
