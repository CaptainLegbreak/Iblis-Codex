#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0xD0];
    D2SeedStrc pGameSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName); // 0x006220F0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed); // 0x00552DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerGuid); // 0x0063D430
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int bCorpseItems, int* pReadSize); // 0x005337F0

#define SYSERROR_UNK_14 14
#define SYSERROR_CORPSES 6
#define STATE_PLAYERBODY 118

__declspec(noinline) static int __stdcall sub_00533850_ReadCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int dwVersion, int nRemainingSize, int* pSectionSize);
static int __stdcall sub_00533850_ReadCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int dwVersion, int nRemainingSize, int* pSectionSize)
{
    const int nClassId = pPlayer ? pPlayer->dwClassId : -1;

    D2UnitStrc* pPlayerBody = SUNIT_AllocUnitData(0, nClassId, 0, 0, pGame, 0, 1, 0, 0);
    if (!pPlayerBody)
    {
        return SYSERROR_CORPSES;
    }

    D2InventoryStrc* pBodyInventory = pPlayerBody->pInventory;
    pPlayerBody->dwFlags &= 0xFFFFFFFB;
    INVENTORY_SetOwnerId(pBodyInventory, -1);
    SUNIT_InitSeed(pPlayerBody, &pGame->pGameSeed);
    INVENTORY_SetOwnerId(pBodyInventory, 0);
    STATES_ToggleState(pPlayerBody, STATE_PLAYERBODY, 1);
    INVENTORY_SetOwnerId(pBodyInventory, 1);
    pPlayerBody->dwFlags &= 0xFFFFFFEF;
    INVENTORY_SetOwnerId(pBodyInventory, -1);

    int nReadSize = 0;
    const int nErrorCode = sub_005337F0_ReadItems(pGame, pPlayerBody, pData + 12, dwVersion, nRemainingSize - 12, 1, &nReadSize);
    if (nErrorCode)
    {
        return nErrorCode;
    }

    INVENTORY_CreateCorpseForPlayer(pBodyInventory, pPlayerBody->dwUnitId, 0, 1);
    INVENTORY_SetOwnerId(pBodyInventory, 2);
    D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, -1, pPlayerBody->dwUnitId, 1);
    *pSectionSize = nReadSize + 12;
    return 0;
}

// 0x005339A0
int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nRemainingSize, int* pSize)
{
    *pSize = 0;

    if (dwVersion < 71 || dwVersion > 96)
    {
        return 1;
    }

    if (*(unsigned short*)pSection != 'MJ')
    {
        return SYSERROR_UNK_14;
    }

    pSection += 2;
    const unsigned short nCount = *(unsigned short*)pSection;
    pSection += 2;
    nRemainingSize -= 4;
    int nSize = 4;

    for (unsigned int i = 0; i < nCount; ++i)
    {
        int nSectionSize;
        const int nErrorCode = sub_00533850_ReadCorpse(pGame, pPlayer, pSection, dwVersion, nRemainingSize, &nSectionSize);
        if (nErrorCode)
        {
            return nErrorCode;
        }

        nSize += nSectionSize;
        pSection += nSectionSize;
        nRemainingSize -= nSectionSize;
    }

    *pSize = nSize;
    return 0;
}
