struct D2ClientStrc;
struct D2TextHeaderStrc;
struct D2BitBufferStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

struct D2PackedGuidStrc
{
    unsigned short f_0;
    unsigned short f_2;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2MessageListStrc
{
    unsigned char nCount;
    unsigned char pad0x01;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    D2MessageListStrc messageList;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x00681CE0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket);   // 0x0053C8D0
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00543520
void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl); // 0x00543D10
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient);                          // 0x00544520
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);      // 0x00554120
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00554D00
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo); // 0x00576770
int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame);                                      // 0x00594610
D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool);                                           // 0x00661240
void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader);                                          // 0x006612A0
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList); // 0x00661480

static int __stdcall sub_00572C10_StartNpcInteraction(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract, char nQuestFlags, D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;

    if (SUNIT_GetInteractUnit(pGame, pUnit))
    {
        return 0;
    }

    if (!pTarget || !pTarget->dwAnimMode || pTarget->dwAnimMode == 0xC || PLAYER_IsBusy(pUnit) == 1)
    {
        return 0;
    }

    if (!sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, 9))
    {
        return 1;
    }

    if (pTarget->dwClassId == 0x92 && ACT1Q4_IsCainInTristramDeactivated(pGame))
    {
        return 0;
    }

    for (; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            return 1;
        }
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\MONSTER\\MonsterAI.cpp", 0x1C4);
    D2InteractInfoStrc* pNewInteractInfo = (D2InteractInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2InteractInfoStrc), ".\\MONSTER\\MonsterAI.cpp", 0x1C7, 0);
    pNewInteractInfo->pUnit = pUnit;

    int bNoInteractInfo;
    if (!pMonInteract->pInteractInfo)
    {
        bNoInteractInfo = 1;
    }
    else
    {
        bNoInteractInfo = 0;
    }

    pNewInteractInfo->pNext = pMonInteract->pInteractInfo;
    pMonInteract->pInteractInfo = pNewInteractInfo;

    D2GAME_NPC_BuildHirelingList_6FCC6FF0(CLIENTS_GetGame(pClient), pClient, pTarget, bNoInteractInfo);
    SUNIT_SetInteractInfo(pUnit, 1, pTarget->dwUnitId);
    pNewInteractInfo->nInteract = 0;

    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame->pMemoryPool);
    QUESTS_NPCActivate(pClient, pUnit, pTarget, pTextHeader);

    D2GSPacketSrv27 packet27;
    memcpy(&packet27.dwUnitGUID, &pTarget->dwUnitId, sizeof(pTarget->dwUnitId));
    packet27.nHeader = 0x27;
    packet27.nUnitType = pTarget->dwUnitType;
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &packet27.messageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
    TEXT_FreeTextHeader(pTextHeader);

    QUESTS_SendCurrentFlags(pGame, pClient);
    const int nTargetGUID = pTarget->dwUnitId;
    D2GAME_SendPacket0x28_6FC3F2F0(pClient, 0x28, 1, nTargetGUID, sub_00543520(pGame, pUnit), nQuestFlags);
    return 0;
}

// 0x00573020
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags)
{
    sub_00572C10_StartNpcInteraction(pGame, pMonInteract, nQuestFlags, pTarget, pUnit);
}
