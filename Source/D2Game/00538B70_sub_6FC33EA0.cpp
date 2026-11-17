struct D2CriticalSectionStrc
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x68];
    D2ClientStrc* pClientList;
    int nClients;
};

struct D2ClientKeySkillStrc
{
    short nSkill;
    unsigned char nHand;
    unsigned char unk0x03;
    int nItemGUID;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char nClassId;
    unsigned char unk0x009[3];
    unsigned char nCharTemplate;
    char szName[16];
    char szAccount[16];
    char unk0x02D[0x33];
    int nCharSaveTransactionToken;
    int unk0x064;
    void* pClientInfo;
    char unk0x06C[0x13C];
    D2GameStrc* pGame;
    char unk0x1AC[0x0C];
    void* pPacketDataHead;
    void* pPacketDataTail;
    void* pPacketDataPool;
    char unk0x1C4[0x214];
    unsigned int dwLastPacketTick;
    D2ClientKeySkillStrc HotkeySkills[16];
    char unk0x45C[0x4C];
    D2ClientStrc* pNext;
    D2ClientStrc* pServerNext;
    D2ClientStrc* pServerNextByName;
    char unk0x4B4[0x58];
    unsigned int dwLocale;
    char f_510[0x08];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString);                                      // 0x004112C0
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame);                           // 0x0053FE70
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame);                                                    // 0x0053FEA0
int __fastcall DATATBLS_GetClassFromCharTemplateTxtRecord(int nTemplate, int nLevel);                       // 0x006657C0

int gbClientListInitialized_008846D8;                                                                       // 0x008846D8
extern D2CriticalSectionStrc gClientListLock_008846A8;                                                      // 0x008846A8
D2ClientStrc* gpClientList_008842A8[256];                                                                   // 0x008842A8
extern D2CriticalSectionStrc gSrvClientListByNameLock_008846C0;                                             // 0x008846C0
D2ClientStrc* gpClientListByName_00883EA8[256];                                                             // 0x00883EA8

// 0x00538B70
int __fastcall sub_6FC33EA0(int nClientId, char* szName)
{
    if (!gbClientListInitialized_008846D8)
    {
        return 1;
    }

    int nResult = 1;
    EnterCriticalSection(&gClientListLock_008846A8);

    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (!nResult)
        {
            break;
        }

        if (pClient->dwClientId == nClientId)
        {
            if (szName)
            {
                SStrCopy(szName, pClient->szName, sizeof(pClient->szName));
            }

            nResult = 0;
        }
    }

    LeaveCriticalSection(&gClientListLock_008846A8);
    return nResult;
}

// 0x00539A30
D2ClientStrc* __fastcall CLIENTS_AddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9)
{
    if (!gbClientListInitialized_008846D8 || !pGame)
    {
        return 0;
    }

    if (pGame->nClients >= 8)
    {
        return 0;
    }

    D2ClientStrc* pClient = (D2ClientStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ClientStrc), ".\\GAME\\Clients.cpp", 0x347, 0);
    memset(pClient, 0, sizeof(D2ClientStrc));

    pClient->dwClientId = nClientId;
    pClient->dwLastPacketTick = GetTickCount() + 180000;
    pClient->pGame = pGame;

    if (ARENA_ShouldTreatClassIdAsTemplateId(pGame))
    {
        pClient->nCharTemplate = nClassIdOrCharTemplate;
        pClient->nClassId = DATATBLS_GetClassFromCharTemplateTxtRecord(nClassIdOrCharTemplate, ARENA_GetTemplateType(pGame));
    }
    else
    {
        pClient->nClassId = nClassIdOrCharTemplate;
    }

    SStrCopy(pClient->szName, szClientName, 0x7FFFFFFF);
    SStrCopy(pClient->szAccount, szAccount, 0x7FFFFFFF);

    pClient->nCharSaveTransactionToken = nCharSaveTransactionToken;
    pClient->pClientInfo = 0;
    pClient->dwLocale = nLocale;
    pClient->dwClientState = 0;
    pClient->pPacketDataHead = 0;
    pClient->pPacketDataTail = 0;
    pClient->pPacketDataPool = 0;

    for (int i = 0; i < 16; ++i)
    {
        pClient->HotkeySkills[i].nSkill = -1;
        pClient->HotkeySkills[i].nHand = 0;
        pClient->HotkeySkills[i].nItemGUID = -1;
    }

    pClient->pNext = pGame->pClientList;
    pGame->pClientList = pClient;

    const int nClientIndex = nClientId & 0xFF;
    EnterCriticalSection(&gClientListLock_008846A8);
    pClient->pServerNext = gpClientList_008842A8[nClientIndex];
    gpClientList_008842A8[nClientIndex] = pClient;
    LeaveCriticalSection(&gClientListLock_008846A8);

    const int nIndex = FOG_ComputeStringCRC16(szClientName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);
    pClient->pServerNextByName = gpClientListByName_00883EA8[nIndex];
    gpClientListByName_00883EA8[nIndex] = pClient;
    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);

    ++pGame->nClients;

    return pClient;
}
