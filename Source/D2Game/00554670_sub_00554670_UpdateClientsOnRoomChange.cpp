extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x50];
    int unk0x50;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x48];
    D2ClientStrc** ppClients;
    char unk0x4C[0x2C];
    unsigned int nNumClients;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall sub_005545C0_GetValidNextRoom(D2GameStrc* pGame, D2UnitStrc* pUnit);          // 0x005545C0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571600
void __stdcall sub_00648B40_roomInvalid(D2DynamicPathStrc* pPath, int bValue);                              // 0x00648B40

static __forceinline D2MonsterDataStrc* sub_00554670_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x00554670
void __fastcall sub_00554670_UpdateClientsOnRoomChange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    if (!UNITS_IsCurrentRoomInvalid(pUnit))
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        pRoom = sub_005545C0_GetValidNextRoom(pGame, pUnit);
    }
    if (pRoom && pCurrentRoom == pRoom)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = sub_00554670_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->unk0x50 = 0;
        }
    }

    D2ClientStrc** ppNewClients = 0;
    unsigned int nNewClients = 0;
    if (pCurrentRoom)
    {
        ppNewClients = pCurrentRoom->ppClients;
        nNewClients = pCurrentRoom->nNumClients;
    }

    D2ClientStrc** ppOldClients = 0;
    unsigned int nOldClients = 0;
    if (pRoom)
    {
        ppOldClients = pRoom->ppClients;
        nOldClients = pRoom->nNumClients;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    while (i < nNewClients && j < nOldClients)
    {
        D2_ASSERT(ppNewClients, 262);
        D2_ASSERT(ppOldClients, 263);
        D2ClientStrc* pNewClient = ppNewClients[i];
        D2ClientStrc* pOldClient = ppOldClients[j];
        if (pNewClient < pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pNewClient, 0))
            {
                sub_00571F90(pGame, pUnit, ppNewClients[i]);
            }
            ++i;
        }
        else if (pNewClient > pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pOldClient, 0))
            {
                sub_00571600(pUnit, ppOldClients[j]);
            }
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }

    while (i < nNewClients)
    {
        D2_ASSERT(ppNewClients, 283);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppNewClients[i], 0))
        {
            sub_00571F90(pGame, pUnit, ppNewClients[i]);
        }
        ++i;
    }

    while (j < nOldClients)
    {
        D2_ASSERT(ppOldClients, 289);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppOldClients[j], 0))
        {
            sub_00571600(pUnit, ppOldClients[j]);
        }
        ++j;
    }

    sub_00648B40_roomInvalid(pUnit->pDynamicPath, 0);
}
