struct D2ItemCacheStrc;

struct D2UnitProxyStrc
{
    D2ItemCacheStrc* pItemCache;
    int nItems;
    unsigned int* pPermCache;
    int nPerms;
};

struct D2EventTimerStrc;

struct D2EventTimerSlabListStrc
{
    char unk0x0000[0x7084];
    D2EventTimerSlabListStrc* pNextSlab;
};

struct D2EventTimerQueueStrc
{
    char unk0x000[0xA1C];
    D2EventTimerSlabListStrc* pSlabListHead;
};

struct D2ClientStrc
{
    char unk0x000[0x4A8];
    D2ClientStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x1A];
    D2ClientStrc* pClientList;
    char unk0x8C[0x2C];
    D2EventTimerQueueStrc* pTimerQueue;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
    char unk0xC8[0x14];
    D2EventTimerStrc* pTimer;
};

struct D2RegurgitatorAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
};

enum
{
    MAX_NPC_INVENTORY = 17,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    UNIT_ALIGNMENT_EVIL = 0,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit);                                                           // 0x0063EA40
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0

extern D2UnitProxyStrc gUnitProxyItemCache_00883D78[17];                                                    // 0x00883D78
unsigned char gbUnitProxyItemCacheInitialized_00883E88[17];                                                 // 0x00883E88
extern const int gnDifficultyBonus_006E21F4[];                                                              // 0x006E21F4

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x00537120
void __fastcall SUNITPROXY_ClearGlobalItemCache()
{
    for (int i = 0; i < MAX_NPC_INVENTORY; ++i)
    {
        if (gbUnitProxyItemCacheInitialized_00883E88[i] == 1)
        {
            gbUnitProxyItemCacheInitialized_00883E88[i] = 0;

            if (gUnitProxyItemCache_00883D78[i].pItemCache)
            {
                FOG_FreeServerMemory(0, gUnitProxyItemCache_00883D78[i].pItemCache, ".\\UNIT\\sunitproxy.cpp", 0x59D, 0);
                gUnitProxyItemCache_00883D78[i].pItemCache = 0;
            }

            if (gUnitProxyItemCache_00883D78[i].pPermCache)
            {
                FOG_FreeServerMemory(0, gUnitProxyItemCache_00883D78[i].pPermCache, ".\\UNIT\\sunitproxy.cpp", 0x5A2, 0);
                gUnitProxyItemCache_00883D78[i].pPermCache = 0;
            }
        }
    }
}

// 0x00537AC0
void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pCurrent = pClient;
        pClient = pClient->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\GAME\\Clients.cpp", 0x617, 0);
    }
}

// 0x00541400
void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (!pTimerQueue)
    {
        return;
    }

    D2EventTimerSlabListStrc* pTimerArray = pTimerQueue->pSlabListHead;
    while (pTimerArray)
    {
        D2EventTimerSlabListStrc* pNext = pTimerArray->pNextSlab;
        FOG_FreeServerMemory(pGame->pMemoryPool, pTimerArray, ".\\GAME\\Event.cpp", 0x314, 0);
        pTimerArray = pNext;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pTimerQueue, ".\\GAME\\Event.cpp", 0x317, 0);
    pGame->pTimerQueue = 0;
}

// 0x00545300
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs)
{
    pGUIDs->nPlayerCount = 0;
}

// 0x00553980
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->pTimer;
}

// 0x005A4F20
int __fastcall sub_005A4F20_GetDifficultyScaledBonus(D2GameStrc* pGame, int nCount)
{
    if (pGame->nDifficulty <= 0)
    {
        return 0;
    }

    if (nCount < 2)
    {
        return 0;
    }

    if (nCount < 9)
    {
        return gnDifficultyBonus_006E21F4[nCount];
    }

    return 8 * nCount - 16;
}

// 0x005FA690
D2UnitStrc* __fastcall AITHINK_TargetCallback_Regurgitator(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2RegurgitatorAiCallbackArgStrc* pArg = (D2RegurgitatorAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || UNIT_HasFlag(pTarget, UNITFLAG_ISMERC) || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE))
    {
        return 0;
    }

    if (!MONSTERS_IsDead(pTarget) || STATES_CheckStateMaskUdeadOnUnit(pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, MONSTATS2FLAGINDEX_SOFT))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

#include "gen/data/Source/D2Game/00537120_SUNITPROXY_ClearGlobalItemCache.inc"
