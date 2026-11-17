extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2RoomCoordListStrc;
struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2AiParamStrc;
struct D2WaypointDataStrc;
struct D2MonStatsTxt;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x2];
    int bExpansion;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    D2AiParamStrc* pAiParam;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2DamageStrc
{
    char unk0x00[0x30];
    int dwColdLen;
    int dwFrzLen;
};

struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[3];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    unsigned int nTargetDistance;
};

struct D2DoorObjectAiCallbackArgStrc
{
    D2UnitStrc* pDoor;
    int nDistance;
};

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
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

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x0C];
    unsigned char bOrbSmashed;
};

struct D2Act4Quest1Strc
{
    char unk0x00[0x14];
    D2UnitStrc* pTargetUnit;
    unsigned char bCloseToIzualGhost;
};

struct D2Act4Quest3Strc
{
    char unk0x00[0x1C];
    unsigned char bSoulstoneAcquired;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x74];
    short nAuraState;
    char unk0x082[0x1BA];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x9B8];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xE0];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszAct3Q2SourceFile[];                                                                // 0x006E2E84

int __fastcall SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll); // 0x005D0C40
D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster_6FC68E30(D2UnkMonCreateStrc* pMonCreate);                 // 0x005B2A00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);          // 0x0065C360
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId);               // 0x005723C0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin);                    // 0x00553380
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);                // 0x00660E00
void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField);               // 0x00660EC0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                               // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                    // 0x0063E9F0
int __fastcall AIUTIL_CheckAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag);               // 0x005DD220
void __fastcall AIUTIL_ToggleAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag, int bSet);   // 0x005DD230
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
int __fastcall SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C50B0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall sub_005D5E10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005D5E10
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);       // 0x006439F0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_005D7CE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7CE0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __stdcall UNITS_IsDoor(D2UnitStrc* pUnit);                                                              // 0x00621A70
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005AD2B0
void __fastcall MISSMODE_SrvDmg10_BladesOfIceCubes(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pMissile && DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId))
    {
        pDamage->dwFrzLen = pDamage->dwColdLen;
    }
}

// 0x005AD8F0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused)
{
    return SKILLS_ApplyRedemptionEffect(pGame, pUnit, pCorpse, 124, nSkillLevel, 0);
}

// 0x005AD910
int __fastcall MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused)
{
    return SKILLS_ApplyRedemptionEffect(pGame, pUnit, pCorpse, 124, nSkillLevel, 1);
}

// 0x005B0D70
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2)
{
    if (!pAiControl)
    {
        return;
    }
    if (nParam0 != -666)
    {
        pAiControl->dwAiParam[0] = nParam0;
    }
    if (nParam1 != -666)
    {
        pAiControl->dwAiParam[1] = nParam1;
    }
    if (nParam2 != -666)
    {
        pAiControl->dwAiParam[2] = nParam2;
    }
}

// 0x005B1140
int __fastcall sub_005B1140_BossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bBoss = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 8) || MONSTERS_IsBoss(0, pUnit);
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount && pUnit->dwClassId == 250 || bBoss)
    {
        if (pAiTickParam->nTargetDistance < 20u && pAiTickParam->pTarget && pAiTickParam->pTarget->dwUnitType == 0 && !AIUTIL_CheckAiControlFlag(pAiTickParam->pAiControl, 0x10))
        {
            SUNIT_AttachSound(pUnit, 16, 0);
            AIUTIL_ToggleAiControlFlag(pAiTickParam->pAiControl, 0x10, 1);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return 1;
        }
    }
    return 0;
}

// 0x005B23C0
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = UNITS_GetRoom(pUnit);
    monCreate.field_20 = a5;
    monCreate.nFlags = nFlags;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nX = CLIENTS_GetUnitX(pUnit);
    monCreate.nY = CLIENTS_GetUnitY(pUnit);
    return D2GAME_SpawnNormalMonster_6FC68E30(&monCreate);
}

// 0x005B2F70
D2UnitStrc* __fastcall sub_6FC69F70(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = UNITS_GetRoom(pUnit);
    monCreate.field_20 = a6;
    monCreate.nFlags = nFlags;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pRoomCoordList;
    monCreate.nX = CLIENTS_GetUnitX(pUnit);
    monCreate.nY = CLIENTS_GetUnitY(pUnit);
    return D2GAME_SpawnNormalMonster_6FC68E30(&monCreate);
}

// 0x005B3750
bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 367 && !QUESTRECORD_GetQuestState(pQuestFlags, 24, 0))
    {
        return true;
    }
    return false;
}

// 0x005B3F20
int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    D2_ASSERT(pQuestData, 452);

    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pQuestDataEx->pTargetUnit);
    if (!pRoom)
    {
        return 0;
    }

    int bFound = 0;
    if (pRoom == pTargetRoom)
    {
        bFound = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 473);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pTargetRoom)
            {
                bFound = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 1) && bFound)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
    }
    return 0;
}

// 0x005B43D0
void __fastcall ACT4Q1_UnitIterate_CheckDistanceToIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pData;
    if (sub_006416D0_UnitEdgeDistance(pUnit, pQuestDataEx->pTargetUnit) < 5)
    {
        pQuestDataEx->bCloseToIzualGhost = 1;
    }
}

// 0x005B4450
bool __fastcall ACT4Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 367)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 15) && pQuest->fState == 1
            || !pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && QUESTRECORD_GetQuestState(pQuestFlags, 26, 7))
        {
            return true;
        }

        if (pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 9))
        {
            return true;
        }
    }
    else if (nNpcId == 246)
    {
        if (!pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && QUESTRECORD_GetQuestState(pQuestFlags, 26, 6))
        {
            return true;
        }

        if (!pQuest->pGame->bExpansion || !QUESTRECORD_GetQuestState(pQuestFlags, 26, 0))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 8))
        {
            return true;
        }
    }

    return false;
}

// 0x005B49C0
int __fastcall ACT4Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 420);
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nQuestId = 23;
    packet5D.nFlags = 2;
    sub_6FC3F380(pClient, &packet5D);
    SUNIT_AttachSound(pUnit, 75, pUnit);
    return 0;
}

// 0x005B4FF0
void __stdcall sub_005B4FF0_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    unsigned short nWpNo;
    if (WAYPOINTS_GetWaypointNoFromLevelId(109, &nWpNo))
    {
        D2WaypointDataStrc* pWaypointData = UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
        WAYPOINTS_ActivateWaypoint(pWaypointData, nWpNo);
    }
}

// 0x005B69F0
bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 408)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pFlags, 27, 0) && !QUESTRECORD_GetQuestState(pFlags, 27, 1) && !QUESTRECORD_GetQuestState(pFlags, 27, 13))
        {
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pFlags, 26, 13) && !QUESTRECORD_GetQuestState(pFlags, 26, 0))
        {
            return true;
        }
    }

    return false;
}

// 0x005B6E20
bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x005B6E30
bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 245 && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, 245))
    {
        return true;
    }
    return false;
}

// 0x005B6FA0
bool __fastcall ACT3Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 253 && !QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return true;
    }
    return false;
}

// 0x005BAD60
bool __fastcall ACT3Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0))
    {
        return false;
    }

    if (nNpcId == 255)
    {
        if (pQuest->fState == 1)
        {
            return true;
        }
    }
    else if (nNpcId == 245)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !((D2Act3Quest5Strc*)pQuest->pQuestDataEx)->bOrbSmashed)
        {
            return true;
        }
    }

    return false;
}

// 0x005BBFE0
bool __fastcall ACT3Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 0) || nNpcId != 255 || pQuest->fState != 1)
    {
        return QUESTRECORD_GetQuestState(pQuestFlags, 22, 11);
    }

    return true;
}

// 0x005D2420
int __fastcall SKILLS_SrvSt62_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nSpawnMode;
    int nX;
    int nY;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, &nX, &nY);
    SKILLS_SetParam1(pSkill, nSummonId);
    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    SKILLS_SetParam4(pSkill, nSpawnMode);
    return 1;
}

// 0x005D2E50
int __fastcall SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nUnused)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    return SKILLS_SrvDo055_CorpseExplosion(pGame, pUnit, 285, nSkillLevel);
}

// 0x005D6170
int __fastcall SKILLS_SrvDo045_Sentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    return sub_005D5E10(pGame, pUnit, nX, nY, pSkillsTxtRecord, nSkillId, nSkillLevel) != 0;
}

// 0x005D7E10
int __fastcall SKILLS_SrvDo054_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || !SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
    {
        return 0;
    }

    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        sub_005D7CE0(pGame, pUnit, nSkillId, nSkillLevel);
    }

    return 1;
}

// 0x005DA8F0
int __fastcall SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}

// 0x005DC530
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY)
{
    int nXDiff = CLIENTS_GetUnitX(pUnit) - nX;
    int nYDiff = CLIENTS_GetUnitY(pUnit) - nY;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }
    else
    {
        return (nXDiff + 2 * nYDiff) / 2;
    }
}

// 0x005DCD50
D2UnitStrc* __fastcall sub_6FCF1CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2DoorObjectAiCallbackArgStrc* pArg = (D2DoorObjectAiCallbackArgStrc*)pCallbackArg;

    if (!pTarget || pTarget->dwUnitType != 2 || !UNITS_IsDoor(pTarget) || pTarget->dwAnimMode != 0)
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pTarget, pUnit);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pDoor = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag)
{
    return AITACTICS_MoveToTarget(pGame, pUnit, pTargetUnit, 2, 0, 0, 1, nFlag);
}
