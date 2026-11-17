struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2UnitStrc { char unk_00[0x60]; D2InventoryStrc* pInventory; };
struct D2ClientStrc { char unk_00[0x4A8]; D2ClientStrc* pNext; };
struct D2GameStrc { char unk_00[0x88]; D2ClientStrc* pClientList; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc*, D2UnitStrc*, D2ClientStrc*); // 0x0053C940
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc*); // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc*); // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc*); // 0x0063D630
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc*, int, int, unsigned char); // 0x0053DFB0
void __fastcall ARENA_SendScoresToClient(D2GameStrc*, D2ClientStrc*); // 0x0053FC70

// 0x0052C410
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x5A1);
        exit(-1);
    }
    for (D2ClientStrc* pOtherClient = pGame->pClientList; pOtherClient; pOtherClient = pOtherClient->pNext)
    {
        if (pOtherClient != pClient)
        {
            D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pOtherClient, 0);
            if (pOtherPlayer)
            {
                SCMD_SendPlayerJoinAndPets(pClient, pOtherPlayer, pOtherClient);
                SCMD_SendPlayerJoinAndPets(pOtherClient, pPlayer, pClient);
                if (pOtherPlayer->pInventory)
                {
                    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pOtherPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
                    {
                        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
                        if (nCorpseGUID != -1)
                            D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(pClient, sub_00451F50_GetUnitGUID(pOtherPlayer), nCorpseGUID, 1);
                    }
                }
            }
        }
    }
    SCMD_SendPlayerJoinAndPets(pClient, pPlayer, pClient);
    ARENA_SendScoresToClient(pGame, pClient);
}
