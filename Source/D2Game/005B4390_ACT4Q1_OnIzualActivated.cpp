struct D2ActiveRoomStrc;
struct D2BitBufferStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
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

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2Act4Quest1Strc
{
    char unk0x00[0x12];
    unsigned char bIzualGhostActivated;
    unsigned char unk0x13;
    D2UnitStrc* pTargetUnit;
    unsigned char bCloseToIzualGhost;
};

struct D2Act4Quest2Strc
{
    char unk0x00[0x11];
    unsigned char bDiabloSpawned;
    unsigned char unused0x12;
    unsigned char unk0x13;
    unsigned char bDiabloKilled;
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
    int nItemDropCount;
    int nEyesDropped;
    int nBrainsDropped;
    int nHeartsDropped;
    int nFlailsDropped;
    int nCubedFlails;
};

struct D2Act3Quest3Strc
{
    char unk0x00[0x06];
    unsigned char bAltarCanBeActivated;
    char unk0x07[0x09];
    int nAltarX;
    int nAltarY;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x0C];
    unsigned char bOrbSmashed;
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted;
    unsigned char bHellGatePortalInitialized;
    unsigned char bMephistoBridgeInitialized;
    unsigned char bOrmusActivated;
    int nHellGatePortalGUID;
    int nMephistoBridgeGUID;
    int nHellGatePortalObjectMode;
    int nMephistoBridgeObjectMode;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData);       // 0x005B3940
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall ACT4Q1_UnitIterate_CheckDistanceToIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B43D0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x005B3D30
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x005B4390
void __fastcall ACT4Q1_OnIzualActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);

    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005B43F0
int __fastcall ACT4Q1_IsAnyPlayerInRangeOfIzualGhost(D2GameStrc* pGame, D2UnitStrc* pTargetUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (pQuestData)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bIzualGhostActivated)
        {
            pQuestDataEx->bCloseToIzualGhost = 0;
            pQuestDataEx->pTargetUnit = pTargetUnit;
            SUNIT_IterateLivingPlayers(pGame, ACT4Q1_UnitIterate_CheckDistanceToIzualGhost, pQuestDataEx);

            return !pQuestDataEx->bCloseToIzualGhost;
        }
    }

    return 0;
}

// 0x005B4440
void __fastcall ACT4Q1_AttachCompletionSoundToPlayers(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT4Q1_UnitIterate_AttachCompletionSound);
}

// 0x005B4B60
D2UnitStrc* __fastcall sub_005B4B60_SpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx)
{
    D2UnitStrc* pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, -1, 0);
    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, 5, 0);
    }

    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, 10, 0);
        if (!pDiablo)
        {
            return 0;
        }
    }

    pDiablo->dwFlags |= 0x3000000;
    pQuestDataEx->bDiabloSpawned = 1;
    return pDiablo;
}

// 0x005B5810
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame)
{
    if (pGame->bExpansion)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData && !((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bDiabloKilled)
    {
        return 0;
    }

    return 1;
}

// 0x005B6930
void __fastcall sub_005B6930_Return(D2GameStrc* pGame, int nSoulStonesDropped)
{
}

// 0x005B86E0
void __fastcall ACT3Q2_UpdateKhalimItemCounts(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
    {
        QUESTRECORD_GetQuestState(pQuestFlags, 18, 1);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nEyesDropped;
    --pQuestDataEx->nHeartsDropped;
    --pQuestDataEx->nBrainsDropped;
    --pQuestDataEx->nFlailsDropped;
    ++pQuestDataEx->nCubedFlails;
}

// 0x005B9CA0
int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAltarCanBeActivated)
        {
            pCoord->nX = pQuestDataEx->nAltarX;
            pCoord->nY = pQuestDataEx->nAltarY;
            return 1;
        }
    }

    return 0;
}

// 0x005BAD20
int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);
    if (pQuestData && ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor)
    {
        return 1;
    }

    return 0;
}

// 0x005BAD40
void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);

    if (pQuestData)
    {
        ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor = 0;
    }
}

// 0x005BBF80
bool __fastcall sub_005BBF80_IsOrbNotSmashed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return true;
}

// 0x005BBFA0
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == 101)
    {
        return 0;
    }

    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return 0;
}

// 0x005BCFD0
void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;

    pQuestDataEx->nHellGatePortalObjectMode = 2;
    pQuestDataEx->nMephistoBridgeObjectMode = 2;

    if (pQuestDataEx->bHellGatePortalInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nHellGatePortalGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 1);
        }
    }

    if (pQuestDataEx->bMephistoBridgeInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nMephistoBridgeGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 2);
        }
    }
}
