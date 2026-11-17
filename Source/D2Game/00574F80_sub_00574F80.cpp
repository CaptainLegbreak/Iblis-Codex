struct D2GameStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    int nName;
    int nHirelingId;
};

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    D2PetInfoStrc petInfo;
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBF0];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, int nPetClass); // 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, int nPetClass, int nSeed, int nName); // 0x0053CB80

// 0x00574F80
void __fastcall sub_00574F80(D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (!pPlayerData || !pGame || !pPlayerData->pPlayerPets)
        return;

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = &pPlayerPets->pPetList[nPetType];
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (!(pPetData->nFlags & 1))
                {
                    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
                    if (pPet)
                    {
                        const int nClassId = pPet->dwClassId;
                        switch (nPetType)
                        {
                        case 7:
                            D2GAME_PACKETS_SendPacket0x81_6FC3E160(pClient, 1, 7, pPetData->nUnitGUID, nPlayerId, nClassId, pPetData->petInfo.nSeed, pPetData->petInfo.nName);
                            break;
                        default:
                            D2GAME_PACKETS_SendPacket0x7A_6FC3E100(pClient, 1, nPetType, pPetData->nUnitGUID, nPlayerId, nClassId);
                            break;
                        }
                    }
                }
            }
        }
    }
}
