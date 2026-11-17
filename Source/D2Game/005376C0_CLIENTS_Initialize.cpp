extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x8];
    int dwUnitId;
};

struct D2ClientStrc
{
    int dwClientId;
    char unk0x004[0x9];
    char szName[16];
    char unk0x01D[0x3];
    int nResult_020;
    char unk0x024[0x64];
    int nValue_088;
    int nValue_08C;
    char unk0x090[0xDC];
    int dwUnitType;
    int dwUnitGUID;
    D2UnitStrc* pPlayer;
    char unk0x178[0x25C];
    unsigned char nFlags;
    char unk0x3D5[0xD3];
    D2ClientStrc* pNext;
    char unk0x4AC[0x4];
    D2ClientStrc* pServerNextByName;
};

struct D2GameStrc
{
    char unk0x00[0x88];
    D2ClientStrc* pClientList;
};

struct D2ServerCallbackFunctions
{
    char unk0x00[0x34];
    int (__stdcall* pfGetValue)();
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString);                                      // 0x004112C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590

extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern D2ClientStrc* gpClientListByName_00883EA8[256];                                                      // 0x00883EA8
extern D2ClientStrc* gpClientList_008842A8[256];                                                            // 0x008842A8
extern D2CriticalSectionStrc gClientListLock_008846A8;                                                      // 0x008846A8
D2CriticalSectionStrc gSrvClientListByNameLock_008846C0;                                                    // 0x008846C0
extern int gbClientListInitialized_008846D8;                                                                // 0x008846D8

// 0x005376C0
void __fastcall CLIENTS_Initialize()
{
    InitializeCriticalSection(&gClientListLock_008846A8);

    EnterCriticalSection(&gClientListLock_008846A8);
    for (int i = 0; i < 256; ++i)
    {
        gpClientList_008842A8[i] = 0;
    }
    LeaveCriticalSection(&gClientListLock_008846A8);

    InitializeCriticalSection(&gSrvClientListByNameLock_008846C0);

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);
    for (int i = 0; i < 256; ++i)
    {
        gpClientListByName_00883EA8[i] = 0;
    }
    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);

    gbClientListInitialized_008846D8 = 1;
}

static D2ClientStrc* __fastcall CLIENTS_GetClientFromClientListWithId(D2ClientStrc* pClientList, int nClientId)
{
    for (D2ClientStrc* pClient = pClientList; pClient != 0; pClient = pClient->pNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }

    return 0;
}

// 0x00537810
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId)
{
    D2_ASSERT(pGame, 0xE9);
    return CLIENTS_GetClientFromClientListWithId(pGame->pClientList, nClientId);
}

// 0x005378E0
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pClient, 0x114);

    if (pUnit)
    {
        pClient->dwUnitType = pUnit->dwUnitType;
        pClient->dwUnitGUID = pUnit->dwUnitId;
        pClient->pPlayer = pUnit;
    }
    else
    {
        pClient->pPlayer = 0;
    }
}

// 0x005379A0
void __fastcall sub_005379A0_ResetClient(D2ClientStrc* pClient)
{
    pClient->nValue_08C = 0;
    pClient->nValue_088 = 0;
    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfGetValue)
    {
        pClient->nResult_020 = gpD2EventCallbackTable_6FD45830->pfGetValue();
    }
}

// 0x005388C0
unsigned int __fastcall sub_6FC33C10(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0xA05);
    return (pClient->nFlags >> 2) & 1;
}

// 0x00538BF0
int __fastcall CLIENTS_GetClientIdByName(const char* szName)
{
    int nClientId = 0;
    const int nIndex = FOG_ComputeStringCRC16(szName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);

    for (D2ClientStrc* pClient = gpClientListByName_00883EA8[nIndex]; pClient; pClient = pClient->pServerNextByName)
    {
        if (nClientId)
        {
            break;
        }

        if (!SStrCmpI(pClient->szName, szName, 16))
        {
            nClientId = pClient->dwClientId;
        }
    }

    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);
    return nClientId;
}
