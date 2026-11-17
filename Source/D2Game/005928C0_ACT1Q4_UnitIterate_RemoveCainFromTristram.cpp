struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2MonsterInteractStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x3C];
    int nPlayerGUID;
    char unk0x40[0x10];
    unsigned char unk0x50;
    unsigned char bCainInTownSpawned;
    unsigned char unk0x52;
    char unk0x53[0x01];
    int nCainGibbetObjectMode;
    char unk0x58[0x09];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    char unk0x63[0x03];
    unsigned char bPortalFromTristramToTownSpawned;
    char unk0x67[0x0D];
    D2UnitStrc* pPlayerInTristram;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    char unk0x0A[0x0A];
    unsigned int dwFlags;
    D2Act1Quest4Strc* pQuestDataEx;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract);                              // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pUnit, void(__fastcall* pfCallback)(D2UnitStrc*), int a4); // 0x00573180
void __fastcall ACT1Q4_SendPacket0x5DToClient(D2UnitStrc* pUnit);                                           // 0x00592880
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT1Q4_UnitIterate_FindPlayersInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00593220
int __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00593130
int __fastcall ACT1Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x005931C0
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0

inline D2MonsterInteractStrc* MONSTERS_GetMonInteractInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

// 0x005928C0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!pUnit || pUnit->dwClassId != 0x92)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (MONSTERAI_HasInteractUnit(nType == 1 ? MONSTERS_GetMonInteractInline(pUnit) : 0))
    {
        sub_00573180(pGame, pUnit, ACT1Q4_SendPacket0x5DToClient, 0);
        return 1;
    }

    D2ModeChangeStrc tModeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &tModeChange);
    D2GAME_ModeChange_6FC65220(pGame, &tModeChange, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        pQuestData->pQuestDataEx->bCainRemovedFromTristram = 1;
    }

    return 1;
}

// 0x00593290
void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = pQuestData->pQuestDataEx;
        if (!pQuestData->bNotIntro || pQuestDataEx->unk0x50 == 1)
        {
            return;
        }

        pQuestDataEx->nCainGibbetObjectMode = 3;
        UNITS_ChangeAnimMode(pUnit, 3);

        const int nX = UNITS_GetXPosition(pUnit) + 3;
        const int nY = CLIENTS_GetUnitY(pUnit) + 3;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2UnitStrc* pCain = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 0x92, 1, -1, 0);
        if (!pCain)
        {
            D2CoordStrc pCoord;
            pCoord.nX = nX;
            pCoord.nY = nY;

            D2ActiveRoomStrc* pFreeRoom;
            QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pFreeRoom, 3, 0x64);
            if (pFreeRoom)
            {
                pCain = D2GAME_SpawnMonster_6FC69F10(pGame, pFreeRoom, pCoord.nX, pCoord.nY, 0x92, 1, -1, 0);
            }
        }

        if (pCain)
        {
            pCain->dwFlags |= 0x3000000;
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pQuestDataEx->nPlayerGUID);
            if (pPlayer)
            {
                SUNIT_AttachSound(pPlayer, 0x30, 0);
            }
        }
        else
        {
            QUESTS_DebugOutput(pGame, "Cain not created, look in town, dammit\n", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x6B6);
            pQuestDataEx->pPlayerInTristram = 0;
            SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_FindPlayersInTristram);

            if (pQuestDataEx->pPlayerInTristram && !pQuestDataEx->bPortalFromTristramToTownSpawned)
            {
                if (D2GAME_CreatePortalObject_6FD13DF0(pGame, pQuestDataEx->pPlayerInTristram, pRoom, nX + 3, nY + 3, 1, 0, 0x3B, 0))
                {
                    pQuestDataEx->bPortalFromTristramToTownSpawned = 1;
                }
            }

            if (!pQuestDataEx->bCainInTownSpawned)
            {
                pQuestDataEx->unk0x52 = 1;
            }

            pQuestDataEx->bCainNotCreated = 1;
        }

        SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_SetCompletionFlag);
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 6, 0, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
    }
    else
    {
        D2_ASSERT(pQuestData, 0x68E);
    }
}
