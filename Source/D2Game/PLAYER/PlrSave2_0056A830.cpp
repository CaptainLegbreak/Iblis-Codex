#include "D2Game.h"

struct D2UnitStrc { int dwUnitType; int dwClassId; int unk08; int dwUnitId; char unk10[0x50]; D2InventoryStrc* pInventory; char unk64[0x60]; unsigned int dwFlags; };
struct D2GameStrc { char unk00[0xD0]; int pGameSeed; };
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName); // 0x006220F0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed); // 0x00552DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwner); // 0x0063D430
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0

// 0x0056A830
int __fastcall PLRSAVE2_ReadCorpses(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int* pDetailError)
{
    struct
    {
        int nCount;
        int nErrorCode;
        int i;
        D2ClientStrc* pClient;
        unsigned char* pData;
    } t;
    unsigned char* pDataStart = *ppSection;
    t.pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x733);

    if (!t.pClient)
    {
        if (pDetailError)
        {
            *pDetailError = 101;
        }

        return 21;
    }

    if (pDataStart + 4 > pEnd)
    {
        if (pDetailError)
        {
            *pDetailError = 102;
        }

        return 21;
    }

    if (*(unsigned short*)pDataStart != 'MJ')
    {
        if (pDetailError)
        {
            *pDetailError = 103;
        }

        return 21;
    }

    pDataStart += 2;
    const unsigned short nCount = *(unsigned short*)pDataStart;
    pDataStart += 2;
    if (nCount > 1)
    {
        if (pDetailError)
        {
            *pDetailError = 104;
        }

        return 21;
    }

    for (t.i = 0, t.nCount = nCount; t.i < t.nCount; ++t.i)
    {
        if (pDataStart + 12 > pEnd)
        {
            if (pDetailError)
            {
                *pDetailError = 105;
            }

            return 21;
        }

        t.pData = pDataStart + 12;
        D2UnitStrc* pPlayerBody = SUNIT_AllocUnitData(0, sub_00451F60_UnitClassId(pPlayer), 0, 0, pGame, 0, 1, 17, 0);
        if (!pPlayerBody)
        {
            if (pDetailError)
            {
                *pDetailError = 106;
            }

            return 21;
        }

        D2ClientStrc* const pBodyClient = t.pClient;
        pPlayerBody->dwFlags &= 0xFFFFFFFBu;

        SUNIT_InitClientInPlayerData(pPlayerBody, pBodyClient);
        UNITS_SetNameInPlayerData(pPlayerBody, CLIENTS_GetName(t.pClient));
        SUNIT_InitSeed(pPlayerBody, &pGame->pGameSeed);
        STATES_ToggleState(pPlayerBody, 7, 1);

        pPlayerBody->dwFlags &= 0xFFFFFFEFu;

        INVENTORY_SetOwnerId(pPlayerBody->pInventory, sub_00451F50_GetUnitGUID(pPlayer));

        t.nErrorCode = 0;
        if (sub_0056A7E0(pGame, pPlayerBody, &t.pData, pEnd, nVersion, 1, &t.nErrorCode))
        {
            if (pDetailError)
            {
                *pDetailError = t.nErrorCode;
            }

            return 21;
        }

        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pPlayerBody ? -1 : pPlayerBody->dwUnitId, 0, 1);
        const int nPlayerBodyId = pPlayerBody->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, sub_00451F50_GetUnitGUID(pPlayer), nPlayerBodyId, 1);
        pDataStart = t.pData;
    }

    *ppSection = pDataStart;
    return 0;
}
