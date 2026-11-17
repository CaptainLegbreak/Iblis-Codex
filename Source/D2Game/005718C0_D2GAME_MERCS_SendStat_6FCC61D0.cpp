struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2NpcRecordStrc;

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
};

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

struct D2PlrIntroStrc
{
    D2BitBufferStrc* pQuestIntroFlags;
    D2BitBufferStrc* pNpcIntroFlags;
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    D2PetInfoStrc petInfo;
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
    char unk0x48[0x18];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2InteractInfoStrc;

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
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
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xBC];
    D2UnitPacketListStrc* pMsgFirst;
    D2UnitPacketListStrc* pMsgLast;
};

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2NpcIndexMapStrc
{
    int nNpcClassId;
    int nIndex;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x22];
    unsigned char nAct;
    char unk0x23[0x11];
    int* pPermStoreItems;
    int nPermStoreItems;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBF0];
    int nPetTypeTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern int gnPlrIntroNpcIndexMapCount;                                                                      // 0x00732734
extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[];                                                           // 0x00732738
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall sub_00410B10(unsigned char* pBits, int nBit);                                                // 0x00410B10
int __stdcall sub_00410B30(unsigned char* pBits, int nBit);                                                 // 0x00410B30
void __stdcall sub_00410B50(unsigned char* pBits, int nBit);                                              // 0x00410B50
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall sub_006272B0_UnitStatListCall(D2UnitStrc* pUnit, int nType, int nValue, int n0);             // 0x006272B0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define DIFFMODE_NORMAL 0
#define NPC_LEVEL_COUNT 5

// 0x005718C0
void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short nStatId, int nValue)
{
    D2_ASSERT(nStatId < ((unsigned char)-1), 685);

    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 687, 0);
    pMsg->nHeader = 0x9E;
    pMsg->pNext = 0;
    *((int*)pMsg + 2) = !pUnit ? -1 : pUnit->dwUnitId;
    *((unsigned char*)pMsg + 12) = (unsigned char)nStatId;
    *((int*)pMsg + 4) = nValue;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

static int PLRINTRO_GetNpcIndex(int nNpcId)
{
    for (int i = 0; i < gnPlrIntroNpcIndexMapCount; ++i)
    {
        if (gaPlrIntroNpcIndexMap[i].nNpcClassId == nNpcId)
        {
            return gaPlrIntroNpcIndexMap[i].nIndex;
        }
    }

    return 0;
}

// 0x00572360
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B10(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005723C0
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    return sub_00410B30(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005724C0
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B50(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572E00
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract)
{
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pMonster)
        {
            if (pInteractInfo == pMonInteract->pInteractInfo)
            {
                pMonInteract->pInteractInfo = pInteractInfo->pNext;
            }
            else
            {
                pPrevious->pNext = pInteractInfo->pNext;
            }
            FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 553, 0);
            return;
        }

        pPrevious = pInteractInfo;
    }
}

// 0x00573750
void __fastcall sub_00573750_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        PATH_SetTargetUnit(pUnit->pDynamicPath, 0);
    }
}

// 0x005749B0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc* pUnit, int nPetType, int nUnitGUID, D2PetInfoStrc* pPetInfo)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pUnit)->pPlayerPets;
    if (!pPlayerPets || nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetListStrc* pPetList = &pPlayerPets->pPetList[nPetType];
    if (!pPetList)
    {
        return;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nUnitGUID)
        {
            pPetData->petInfo = *pPetInfo;
        }
    }
}

// 0x00576890
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel)
{
    if (pGame->nDifficulty == DIFFMODE_NORMAL)
    {
        int nUnused;
        D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
        if (pNpcRecord)
        {
            const int npcLevels[NPC_LEVEL_COUNT] = { 12, 20, 28, 36, 45 };
            if (pNpcRecord->nAct < NPC_LEVEL_COUNT)
            {
                const int nCap = npcLevels[pNpcRecord->nAct];
                return nCap < nLevel ? nCap : nLevel;
            }
        }
    }

    return nLevel;
}

// 0x00576ED0
bool __fastcall sub_00576ED0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return false;
    }

    const int nCode = ITEMS_GetBaseCode(pItem);
    if (pGame->nDifficulty > DIFFMODE_NORMAL)
    {

        if (nCode == 0x20347068 || nCode == 0x20357068 || nCode == 0x2034706D || nCode == 0x2035706D)
        {
            return true;
        }
    }

    for (int i = 0; i < pNpcRecord->nPermStoreItems; ++i)
    {
        if (nCode == pNpcRecord->pPermStoreItems[i])
        {
            return true;
        }
    }

    return false;
}

// 0x00579130
void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    SUNIT_ResetInteractInfo(pPlayer);
    MONSTERAI_RemoveInteractInfoFor(pGame, pPlayer, (pNpc && pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData) ? pNpc->pMonsterData->pMonInteract : 0);
}

// 0x00585160
int __fastcall sub_00585160_StatCallback1(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 1, nValue, 0);
    return 1;
}

// 0x00585180
int __fastcall sub_00585180_StatCallback2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 2, nValue, 0);
    return 1;
}

// 0x005851A0
int __fastcall sub_005851A0_StatCallback3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 3, nValue, 0);
    return 1;
}

// 0x005851C0
int __fastcall sub_005851C0_StatCallback0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 0, nValue, 0);
    return 1;
}

// 0x00585220
int __fastcall sub_00585220_StatCallback5(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 5, nValue, 0);
    return 1;
}

#include "gen/data/Source/D2Game/005718C0_D2GAME_MERCS_SendStat_6FCC61D0.inc"
