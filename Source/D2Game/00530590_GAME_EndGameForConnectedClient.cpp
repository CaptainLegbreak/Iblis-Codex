struct D2GameStrc;
struct D2ClientStrc;
typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);
void __fastcall sub_0052CBB0_FindOwnerClient(D2ClientStrc* client, void* context); // 0x0052CBB0
void __fastcall sub_0052CBD0_FindFirstClient(D2ClientStrc* client, void* context); // 0x0052CBD0
void __fastcall GAME_ForEachIngameClient(D2GameStrc* game, GAME_ForEachIngameClientCallbackPtr callback, void* context); // 0x0052DED0
int __fastcall CLIENTS_GetClientId(D2ClientStrc* client); // 0x00538590
void __fastcall GAME_EndGame(int clientId, int flag); // 0x005303D0

// 0x00530590
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* game, D2ClientStrc* client)
{
    D2ClientStrc* owner = 0;
    GAME_ForEachIngameClient(game, sub_0052CBB0_FindOwnerClient, &owner);
    if (!owner)
    {
        if (!client)
        {
            D2ClientStrc* first = 0;
            GAME_ForEachIngameClient(game, sub_0052CBD0_FindFirstClient, &first);
            if (first)
            {
                GAME_EndGame(CLIENTS_GetClientId(first), 0);
            }
            return;
        }
        GAME_EndGame(CLIENTS_GetClientId(client), 0);
        return;
    }
    GAME_EndGame(CLIENTS_GetClientId(owner), 0);
}
