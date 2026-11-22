#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameClient.h"
struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_INVALID 6

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue); // 0x0053B400
void __fastcall D2GAME_PACKETS_SendPacket0x7B_6FC3F720(D2ClientStrc* pClient, unsigned char nIndex, int nSkill, int nHand, int nItemGUID); // 0x0053DB20
void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6); // 0x0053C590
int __fastcall D2GAME_SAVE_GetUnitDataFromFile_6FC8CB40(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int a4, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005345A0
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, void(__fastcall* pfCallback)(D2UnitStrc*, unsigned short, unsigned int, D2UnitStrc*)); // 0x006258D0
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask);                         // 0x00463720
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __fastcall PLRMSG_SendPlayerStatUpdates(D2UnitStrc* pUnit, D2UnitStrc* pUnit2, int bSkipHpCheck);                       // 0x00548760
void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00597B00
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x0058A0A0

// 0x00537930
static void __stdcall sub_00537930_SendPlayerAssign(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    D2GAME_PACKETS_SendPacketSize06_6FC3C850(pClient, 0x0B, nUnitType, nUnitGUID);
}

int __fastcall ClientAddPlayerToGame(D2ClientStrc* pClient, D2GameStrc* pGame, int bLoadFromSave, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2UnitStrc* pPlayer = 0;
    D2_ASSERT(pGame, 0x23F);
    D2_ASSERT(pClient, 0x242);
    pClient->dwFlags |= 1;
    if (!pGame->bExpansion && pClient->nClassId >= 5)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "[PLAYER CREATE]  ClientAddPlayerToGame()  Error Creating:%s  Error:%d=%s", CLIENTS_GetName(pClient), 0x18, "nError");
        pClient->pPlayer = 0;
        return 0x18;
    }
    const int nError = D2GAME_SAVE_GetUnitDataFromFile_6FC8CB40(pGame, pClient, pClient->szName, bLoadFromSave, &pPlayer, pRoom, nX, nY);
    if (nError)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "[PLAYER LOAD]  ClientAddPlayerToGame()  Error Loading:%s  Error:%d=%s", CLIENTS_GetName(pClient), nError, "nError");
        pClient->pPlayer = 0;
        return nError;
    }
    if (pClient->nSaveFlags & 0x20)
    {
        if (!pGame->bExpansion)
        {
            pClient->pPlayer = 0;
            return 0x18;
        }
    }
    else if (pGame->bExpansion)
    {
        pClient->pPlayer = 0;
        return 0x17;
    }
    if (pClient->nSaveFlags & 4)
    {
        if (pClient->nSaveFlags & 8)
        {
            pClient->pPlayer = 0;
            return 0x15;
        }
        if (!(ARENA_GetFlags(pGame) & 0x800))
        {
            pClient->pPlayer = 0;
            return 0x14;
        }
    }
    else if (ARENA_GetFlags(pGame) & 0x800)
    {
        pClient->pPlayer = 0;
        return 0x13;
    }
    sub_00537930_SendPlayerAssign(pClient, pPlayer);
    D2GAME_SendPacketSize05_6FC3C880(pClient, 0x5F, UNITS_GetPlayerPortalFlags(pPlayer));
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute_6FC822D0);
    D2UnitStrc* pUnit = pPlayer;
    if (sub_00463720_TestUnitFlagEx(pUnit, 1))
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= 0x200000;
        }
    }
    for (int i = 0; i < 16; ++i)
    {
        if (pClient->HotkeySkills[i].nSkill >= 0 && pClient->HotkeySkills[i].nSkill < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2GAME_PACKETS_SendPacket0x7B_6FC3F720(pClient, i, pClient->HotkeySkills[i].nSkill, pClient->HotkeySkills[i].nHand, pClient->HotkeySkills[i].nItemGUID);
        }
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2GAME_PACKETS_SendPacket0x23_6FC3DC60(pClient, !pPlayer ? UNIT_INVALID : pPlayer->dwUnitType, !pPlayer ? -1 : pPlayer->dwUnitId, 1, (unsigned short)pPlayerData->nLeftSkillId, pPlayerData->nLeftSkillFlags);
        D2GAME_PACKETS_SendPacket0x23_6FC3DC60(pClient, !pPlayer ? UNIT_INVALID : pPlayer->dwUnitType, !pPlayer ? -1 : pPlayer->dwUnitId, 0, (unsigned short)pPlayerData->nRightSkillId, pPlayerData->nRightSkillFlags);
    }
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute_6FC822D0);
    PLRMSG_SendPlayerStatUpdates(pPlayer, pPlayer, 1);
    D2GAME_INVMODE_Last_6FC416D0(pGame, pPlayer);
    if (pGame->bExpansion)
    {
        ACT5Q3_ApplyResistanceReward(pGame, pPlayer);
    }
    return 0;
}
