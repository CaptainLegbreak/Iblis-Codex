struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0x84];
    int unk0x84;
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char unk0x01[0x0B];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x86];
    unsigned char bWorldStoneChamberOpen;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);                 // 0x00589FF0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00588EB0
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058AEA0
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058D770
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

// 0x0058A0A0
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nValue = 0;
    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[0], 0x25, 7))
    {
        nValue = 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[1], 0x25, 7))
    {
        nValue += 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[2], 0x25, 7))
    {
        nValue += 10;
    }

    if (nValue)
    {
        ACT5Q3_UpdateResistances(pGame, pUnit, nValue);
    }
}

// 0x0058A9F0
int __fastcall sub_0058A9F0_ACT5Q3_IsDrehyaStateZero(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return 0;
    }

    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->unk0x84 == 0;
}

// 0x0058AA10
void __fastcall sub_0058AA10_ACT5Q3_UpdateStatusOnActivate(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058BC00
void __fastcall ACT5Q4_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 0x26, 1);

    QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0x0F);
}

// 0x0058BC40
void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x22);
    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 3)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
}

// 0x0058CF50
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    --((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    if (!((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->unk0x10)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 1;
    }
}

// 0x0058CF90
int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, 0x23)->pQuestDataEx)->bActivatable == 0;
}

// 0x0058D090
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData->bNotIntro)
    {
        return 0;
    }

    return ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated == 0;
}

// 0x0058E600
void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (!pQuestData)
    {
        return;
    }

    ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen = 1;

    if (pQuestData->bNotIntro && pQuestData->fLastState < 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058E640
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (pQuestData && ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen == 1)
    {
        return 0;
    }

    return 1;
}

// 0x0058FD20
void __fastcall sub_0058FD20_ACT1Q1_SetRespecRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 0x0D);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 1);
}

// 0x0058FD50
void __fastcall sub_0058FD50_ACT1Q1_SetRespecRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 0x29, 1);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x29, 0x0F))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x1E);
        D2_ASSERT(pQuestData, 0xE1);

        pQuestData->bActive = 0;

        QUESTS_DebugOutput(pGame, "deactivated respec quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0xE5);
    }
}

// 0x00591790
void __fastcall ACT1Q3_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 3, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 3, 1);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 3, 0x0F))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 3);
        D2_ASSERT(pQuestData, 0x160);

        pQuestData->bActive = 0;

        QUESTS_DebugOutput(pGame, "deactivated tools of trade", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x164);
    }
}
