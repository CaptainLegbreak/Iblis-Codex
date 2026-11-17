struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2PlayerListStrc
{
    int nUnitGUID;
    unsigned int dwFlags;
    int field_8;
    int field_C;
    D2PlayerListStrc* pNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x38];
    D2PlayerListStrc* pPlayerList;
};

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
void __fastcall D2GAME_PACKETS_SendPacket0x8C_6FC3F8B0(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState); // 0x0053DE50
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer);             // 0x0053DF00
short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00540710
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3);                           // 0x0055B3A0
void __fastcall sub_6FCBAA20(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                   // 0x0055B440
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

inline D2PlayerListStrc* sub_0055B110(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    const int nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    if (pPlayer1 != pPlayer2)
    {
        for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
        {
            if (pPlayerList->nUnitGUID == nUnitGUID)
            {
                return pPlayerList;
            }
        }
    }

    return 0;
}

// 0x0055B1E0
void __fastcall PLAYERLIST_IterateCallback_FreePlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2UnitStrc* pPlayerArg = (D2UnitStrc*)pArg;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2PlayerListStrc* pPrevious = 0;
    const int nUnitGUID = !pPlayerArg ? -1 : pPlayerArg->dwUnitId;

    if (pPlayer == pPlayerArg)
    {
        return;
    }

    for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        if (pPlayerList->nUnitGUID == nUnitGUID)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pPlayerList->pNext;
            }
            else
            {
                pPlayerData->pPlayerList = pPlayerList->pNext;
            }

            FOG_FreePool(pGame->pMemoryPool, pPlayerList, ".\\UNIT\\PlayerList.cpp", 0x97, 0);
            return;
        }

        pPrevious = pPlayerList;
    }
}

// 0x0055B540
void __fastcall sub_0055B540_UpdatePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2UnitStrc* pOther = (D2UnitStrc*)pArg;

    PLAYERLIST_AllocPlayerList(pGame, pPlayer, pOther);
    PLAYERLIST_AllocPlayerList(pGame, pOther, pPlayer);
    D2GAME_PACKETS_SendPacket0x8D_6FC3F960(pOther, pPlayer);

    D2PlayerListStrc* pRecord = sub_0055B110(pPlayer, pOther);
    if (pPlayer != pOther && pRecord)
    {
        pRecord->field_C = 0;
    }

    if (SUNIT_GetPartyId(pPlayer) == -1)
    {
        sub_6FCBA980(pOther, pPlayer, 0);
    }
    else
    {
        sub_6FCBA980(pOther, pPlayer, 1);
    }

    sub_6FCBAA20(pOther, pPlayer);
    sub_6FCBAA20(pPlayer, pOther);

    for (D2PlayerListStrc* pPlayerList = UNITS_GetPlayerData(pPlayer)->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        D2GAME_PACKETS_SendPacket0x8C_6FC3F8B0(pOther, nUnitGUID, pPlayerList->nUnitGUID, (unsigned short)pPlayerList->dwFlags);
    }
}

// 0x0055B650
void __fastcall sub_0055B650_RefreshPendingRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        if (pPlayerList->field_C == 2)
        {
            D2UnitStrc* pOther = SUNIT_GetServerUnit(pGame, 0, pPlayerList->nUnitGUID);
            if (pOther)
            {
                pPlayerList->field_C = PARTY_GetPartyIdForUnitOwner(pGame, pOther) != -1;
                sub_6FCBAA20(pPlayer, pOther);
            }
        }
    }
}
