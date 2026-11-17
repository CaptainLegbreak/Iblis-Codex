#include "D2Game.h"

struct D2Act4Quest2Strc;

struct D2GameStrc
{
    char unk0x000[0x70];
    int bExpansion;
};

struct D2QuestDataStrc
{
    char unk0x000[0x4];
    D2GameStrc* pGame;
    char unk0x008[0x10];
    struct D2Act4Quest2Strc* pQuestDataEx;
};

struct D2Act4Quest2Strc
{
    char unk0x000[0x1];
    unsigned char bTimerCreated;
    unsigned char bNeedToSpawnDiablo;
    unsigned char unk0x03;
    unsigned char bNeedToEndGame;
    unsigned char bNeedToWarpPlayers;
    unsigned char bDiabloStartPointInitialized;
    char unk0x007[0x1];
    int nDiabloStartPointObjectGUID;
    unsigned char unk_0C[0x8];
    unsigned char bDiabloKilled;
    unsigned char bClientsSaved;
    char unk0x016[0x2];
    unsigned int dwTickCount;
    char unk0x01C[0x30];
};

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame); // 0x0052E2A0
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00530590
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4A80
D2UnitStrc* __fastcall sub_005B4B60_SpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640

// 0x005B4BE0
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act4Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bNeedToSpawnDiablo)
    {
        ++pQuestDataEx->dwTickCount;
        if (pQuestDataEx->dwTickCount < 10 || !pQuestDataEx->bDiabloStartPointInitialized)
            return false;

        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nDiabloStartPointObjectGUID);
        if (!pObject)
            return false;

        if (!sub_005B4B60_SpawnDiablo(pQuestData->pGame, UNITS_GetRoom(pObject), CLIENTS_GetUnitX(pObject), CLIENTS_GetUnitY(pObject), pQuestDataEx))
            return false;

        pQuestDataEx->bNeedToSpawnDiablo = 0;
        pQuestDataEx->bTimerCreated = 0;
        return true;
    }

    if (pQuestDataEx->unk0x03)
    {
        if (pQuestDataEx->bNeedToEndGame && pQuestDataEx->dwTickCount + 95000 < GetTickCount())
        {
            pQuestDataEx->bTimerCreated = 0;
            pQuestDataEx->unk0x03 = 0;
            pQuestDataEx->bNeedToEndGame = 0;
            if (pQuestData->pGame->bExpansion)
                return true;

            GAME_EndGameForConnectedClient(pGame, 0);
            return true;
        }

        if (pQuestDataEx->dwTickCount + 90000 < GetTickCount())
        {
            if (pQuestDataEx->bNeedToWarpPlayers)
            {
                if (!pQuestData->pGame->bExpansion)
                    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT4Q2_UnitIterate_WarpToTownEndGame);

                pQuestDataEx->bNeedToWarpPlayers = 0;
            }
            return false;
        }

        if (pQuestDataEx->dwTickCount + 75000 < GetTickCount() && !pQuestDataEx->bClientsSaved)
        {
            pQuestDataEx->bClientsSaved = 1;
            GAME_SaveAndSendClientSaves(pGame);
        }
        return false;
    }

    return true;
}

// 0x005B5730
unsigned char __fastcall sub_005B5730_GetDiabloKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData) return pQuestData->pQuestDataEx->bDiabloKilled;
    return 0;
}
