struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2CoordStrc;
struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[5];
    unsigned char bNotIntro;
    char unk0x0A[0xEA];
    D2QuestDataStrc* pPrev;
};
struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    char unk0x04[4];
    int bPickedSet;
    char unk0x0C[0x14];
    unsigned char unk0x20;
};
struct D2GameStrc
{
    char unk0x00[109];
    unsigned char nDifficulty;
    char unk0x6E[4230];
    D2QuestInfoStrc* pQuestControl;
};
struct D2PlayerDataStrc
{
    char unk0x00[16];
    D2BitBufferStrc* pQuestData[3];
};
struct D2UnitStrc;
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);                          // 0x005456F0
int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom);      // 0x0059DFD0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005BB550
void __fastcall sub_0058CFD0(D2GameStrc* pGame, D2UnitStrc* pUnit);                     // 0x0058CFD0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LEVEL_DURIELSLAIR 73
#define LEVEL_FIRST_COUNCIL_LIMIT 108
#define QUEST_LOG_PACKET 0x5D
#define QUEST_FLAGS_PACKET 0x28
#define QUEST_FLAGS_KIND 6
#define QUEST_LOG_FLAGS 2

// 0x005444B0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId)
{
    D2_ASSERT(pGame, 1987);
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 1989);

    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nQuestId)
        {
            return pQuestData->bNotIntro == 1;
        }
    }

    return 1;
}

// 0x005455B0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 3239), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
}

// 0x00545760
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2)
{
    pGame->pQuestControl->unk0x20 = a2;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, QUESTS_FXIterate);
}

// 0x00545830
int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom)
{
    if (nLevel == LEVEL_DURIELSLAIR)
    {
        return ACT2Q6_ActivateTomb(pGame, pCoord, ppRoom);
    }

    return 0;
}

// 0x005458E0
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, unsigned char nQuestId)
{
    D2GSPacketSrv5D packet5D = {};

    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = nQuestId;
    packet5D.nFlags = QUEST_LOG_FLAGS;

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 3433);
    sub_6FC3F380(pClient, &packet5D);
}

// 0x00545990
void __stdcall sub_00545990(int nUnused)
{
}

// 0x00545B50
void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) < LEVEL_FIRST_COUNCIL_LIMIT)
    {
        ACT3Q5_SpawnCouncil(pGame, pUnit);
    }
    else
    {
        sub_0058CFD0(pGame, pUnit);
    }
}
