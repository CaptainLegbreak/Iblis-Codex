#include "D2Game.h"

#define nullptr 0
struct Obj005452C0;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act5Quest2Strc;
struct D2GSPacketSrv5D;

typedef int (__stdcall* FARPROC)();

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x4];
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
};

struct D2Act5Quest2Strc
{
    char pad0x00[0x84];
    unsigned char bQualKehkActivated;
    unsigned char unk_85[0x83];
    unsigned char unk0x108[3];
    char unk0x10B[9];
    int unk0x114[3];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    char pad0x0E[0x2];
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char pad0xE4[0x4];
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
    };
    unsigned short nMessageIndex;
    unsigned char unk_1A[0x2];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern const unsigned int gdwAct5Q2RuneCodes_00732FEC[3]; // 0x00732FEC
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestFlags, int nQuestId); // 0x0065C3E0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587A90
extern "C" int __fastcall sub_005452C0(Obj005452C0* pObj, unsigned int dwValue); // 0x005452C0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00587B00
void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x203)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);

    if (nMessageIndex == 20096)
    {
        pQuestDataEx->bQualKehkActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x100);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20110)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
        {
            {
                bool bRewardGranted = false;

                if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13))
                {
                    if (pQuestData->fState != 5)
                    {
                        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x128);
                        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
                        {
                            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x129);
                            exit(-1);
                        }
                        pQuestData->pfSeqFilter(pQuestData);

                        pQuestData->dwFlags &= 0xFFFFFF00;
                        QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 0);
                    }
                    pQuestData->pfCallback[2] = nullptr;
                }

                int nRewards = 3;
                if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 6))
                {
                    nRewards = 2;
                }
                else if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 7))
                {
                    nRewards = 1;
                }

                if (nRewards > 0)
                {
                    for (int i = 0; i < nRewards; ++i)
                    {
                        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, gdwAct5Q2RuneCodes_00732FEC[i], 0, 2, 1))
                        {
                            bRewardGranted = true;
                        }
                    }

                    if (bRewardGranted)
                    {
                        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
                        QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->nQuestFilter, 1);
                        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->nQuestFilter);

                        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

                        D2GSPacketSrv5D packet5D = {};
                        packet5D.nHeader = 0x5D;
                        packet5D.nQuestId = 0x20;
                        packet5D.nFlags = 2;
                        sub_6FC3F380(SUNIT_GetClientFromPlayer(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x14E), &packet5D);
                    }
                }
            }

            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

#include "gen/data/Source/D2Game/Quests/a5q2.inc"

// 0x00587D30
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (sub_005452C0((Obj005452C0*)pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (nRewardGranted == 1)
    {
        return;
    }

    const unsigned char nState = pQuestData->fState;
    if ((nState >= 4 && !nPrimaryGoalDone) || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q2NpcActivateIndices[nState];
    if (gnA5Q2NpcActivateIndices[nState] == 2 && nNpcId == 0x203)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 0x203, 5);
            return;
        }
        goto send;
    }

    if (nIndex != -1 && nIndex < 12)
    {
send:
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00588010
static __forceinline void sub_00588010_CountWussie(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pUnit);
    if (nIndex >= 0)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x114[nIndex] += 1;
        if (pQuestDataEx->unk0x114[nIndex] >= 5)
        {
            pQuestDataEx->unk0x108[nIndex] = 1;
        }
    }
}

void __fastcall sub_M117_Emit_00588010(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    sub_00588010_CountWussie(pQuestData, pUnit);
}
