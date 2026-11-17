struct D2ClientStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0xD0];
    int nGameSeed[2];
};

extern "C" const char gszPlrSaveFile_006E09AC[];                                                           // 0x006E09AC
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed);                                              // 0x00552DF0
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);                     // 0x00553180
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName);                                  // 0x006220F0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerId);                             // 0x0063D430
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int a3, int a4);    // 0x0063D470
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x00533350
int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x005335E0

// 0x005337F0
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize)
{
    int nResult;
    if (nVersion == 0x47)
        nResult = PLRSAVE_ReadLegacyItems(pGame, pUnit, pSection, 0x47, nSize, nUnused, pReadSize);
    else if (nVersion < 0x48 || nVersion > 0x60)
        return 1;
    else
        nResult = sub_005335E0(pGame, pUnit, pSection, nVersion, nSize, nUnused, pReadSize);
    return nResult;
}

static __declspec(noinline) int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize);

// 0x00533850
static int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pUnit, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    *pReadSize = 0;
    pData += 12;
    nSize -= 12;

    D2UnitStrc* pPlayer = pUnit;
    pUnit = SUNIT_AllocUnitData(0, !pPlayer ? -1 : pPlayer->dwClassId, 0, 0, pGame, 0, 1, 0x11, 0);
    if (!pUnit)
    {
        return 8;
    }

    pUnit->dwFlags &= ~4;
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszPlrSaveFile_006E09AC, 0x1511);
        SUNIT_InitClientInPlayerData(pUnit, pClient);
        char* const szName = CLIENTS_GetName(pClient);
        UNITS_SetNameInPlayerData(pUnit, szName);
    }
    SUNIT_InitSeed(pUnit, pGame->nGameSeed);
    STATES_ToggleState(pUnit, 7, 1);
    pUnit->dwFlags &= ~0x10;
    INVENTORY_SetOwnerId(pUnit->pInventory, !pPlayer ? -1 : pPlayer->dwUnitId);

    {
        int nRead = 0;
        const int nResult = sub_005337F0_ReadItems(pGame, pUnit, pData, nVersion, nSize, 1, &nRead);
        if (nResult)
        {
            return nResult;
        }

        nSize = nRead + 12;
        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pUnit ? -1 : pUnit->dwUnitId, 0, 1);
        const int nCorpseId = !pUnit ? -1 : pUnit->dwUnitId;
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nPlayerId, nCorpseId, 1);
        *pReadSize = nSize;
        return 0;
    }
}

// build: context sub_00533850_EmitCaller
int __fastcall sub_00533850_EmitCaller(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    return sub_00533850_ReadCorpse(pPlayer, pGame, pData, nVersion, nSize, pReadSize);
}
