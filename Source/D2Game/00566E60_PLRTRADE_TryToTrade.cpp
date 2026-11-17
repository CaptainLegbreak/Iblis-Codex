struct D2GameStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    char unk0x10[0x40];
    unsigned int dwTradeState;
    unsigned int unk0x54;
    unsigned int dwAcceptTradeTick;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);      // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame);                                               // 0x005B5810
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId);                                                          // 0x0061AAF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

#define EVENTTYPE_PLAYERISBUSY 8
#define EVENTTYPE_PLEASEWAIT 9

// 0x00566E60
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    if (PLAYER_IsBusy(pPlayer1) || ACT4Q2_HasDiabloBeenKilled(pGame))
    {
        return;
    }

    const unsigned int nTickCount = GetTickCount();

    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pPlayer2);
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer1);
    if (PLAYER_IsBusy(pPlayer2))
    {
        if (nTickCount - pPlayerData1->unk0x54 <= 1000)
        {
            return;
        }

        PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLAYERISBUSY, pPlayerData2->szName);
        pPlayerData1->unk0x54 = nTickCount;
        return;
    }

    if (nTickCount - pPlayerData2->dwAcceptTradeTick < 5000)
    {
        if (pPlayerData1->unk0x54 + 1000 < nTickCount)
        {
            pPlayerData1->unk0x54 = nTickCount;
            PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, pPlayerData2->szName);
        }
    }
    else
    {
        if (!pPlayerData1->dwTradeState && !pPlayerData2->dwTradeState)
        {
            if (nTickCount - pPlayerData1->dwAcceptTradeTick < 5000)
            {
                if (nTickCount > pPlayerData1->unk0x54 + 1000)
                {
                    PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, 0);
                    pPlayerData1->unk0x54 = nTickCount;
                }
                return;
            }

            if (DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer1))) && DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer2))))
            {
                SUNIT_SetInteractInfo(pPlayer1, 0, !pPlayer2 ? -1 : pPlayer2->dwUnitId);
                SUNIT_SetInteractInfo(pPlayer2, 0, !pPlayer1 ? -1 : pPlayer1->dwUnitId);

                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 2375), 0);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 2376), 1);

                pPlayerData1->dwTradeState = 1;
                pPlayerData2->dwTradeState = 2;
            }
            else
            {
                SUNIT_ResetInteractInfo(pPlayer1);
                SUNIT_ResetInteractInfo(pPlayer2);
            }
        }
    }
}
