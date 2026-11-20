#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2ModeChangeStrc;
struct D2PackedGuidStrc;
struct D2MessageStrc;
struct D2GSPacketSrv27;
struct UnkAiStrc1;
struct D2AiParamStrc;
struct D2DataTablesStrc;
struct D2QuestDataStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2CoordStrc;
struct D2MonsterDataStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x11C];
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x4];
    int nHighestClassSkillCount;
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
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    unsigned int dwGameFrame;
};


int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __stdcall sub_0062E880(D2UnitStrc* pItem); // 0x0062E880
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

enum D2C_F41AiTacticsConstants
{
    MONMODE_WALK = 2,
    MONMODE_SEQUENCE = 14,
    MONMODE_RUN = 15,
    STATE_DECREPIFY = 60,
    EVENTTYPE_AITHINK = 2,
    EVENTTYPE_FREEHOVER = 6,
    UNITFLAG_HASTXTMSG = 0x100,
    MONSTATSFLAGINDEX_INTERACT = 9,
    COLLIDE_MISSILE = 0x40,
};



struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x198];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

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

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};

struct UnkAiStrc1
{
    D2UnitStrc* pTarget;
    int nDistance;
};

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall QUESTS_ActiveCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC); // 0x00544590
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __fastcall sub_005DE4E0_MoveAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nMaxDistance, int a6); // 0x005DE4E0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit); // 0x005A61F0

struct D2MonsterDataStrc
{
	char unk_00[0x2C];
	D2AiParamStrc* pAiParams;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParams, int nParam, int nValue, int nArg); // 0x005A6260

// 0x00530F30
void __fastcall sub_00530F30_SetGlobal(int nValue)
{
    gnGlobal_007310CC = nValue;
}

// 0x00568D70
int __cdecl sub_00568D70_GetHighestClassSkillCount()
{
    return sgptDataTables->nHighestClassSkillCount;
}

// 0x00576320
static __forceinline int sub_00576320_CheckItem(D2UnitStrc* pItem)
{
    return sub_0062E880(pItem);
}

int __stdcall sub_M114_Emit_00576320(D2UnitStrc* pItem)
{
    return sub_00576320_CheckItem(pItem) + 1;
}

// 0x005875D0
void __fastcall sub_005875D0_SetQuestStateIfIntroDone(D2QuestDataStrc* pQuest)
{
    if (!pQuest->fState && pQuest->bNotIntro)
    {
        pQuest->fState = 1;
    }
}

// 0x005B0BC0
int __fastcall MISSMODE_SrvDo01_BasicMissile(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

#include "gen/data/Source/D2Game/Ai/AiTatics.inc"

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005DDE50
D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance)
{
    D2UnitStrc* pResult = sub_6FCF2110(pGame, pUnit, pAiControl, pDistance, pCombat);
    if (pResult && *pDistance <= nMaxDistance)
    {
        return pResult;
    }

    return 0;
}

// 0x005DDE80
D2UnitStrc* __fastcall sub_6FCCFDE0(D2GameStrc* pGame, D2UnitStrc* pNPC, D2UnitStrc* pPlayer, void* pCallbackArg)
{
    UnkAiStrc1* pArg = (UnkAiStrc1*)pCallbackArg;
    const int nType = pPlayer ? pPlayer->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pNPC, pPlayer);
    if (nDistance > 15)
    {
        return 0;
    }

    int nInteract = 0;
    if (pNPC)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline(pNPC->dwClassId);
        nInteract = pMonStatsTxtRecord ? (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7]) : 0;
    }

    if (!nInteract)
    {
        pArg->nDistance = nDistance;
        pArg->pTarget = pPlayer;
        return pPlayer;
    }

    if (QUESTS_ActiveCycler(pGame, pPlayer, pNPC) && nDistance < pArg->nDistance)
    {
        pArg->nDistance = nDistance;
        pArg->pTarget = pPlayer;
        return pPlayer;
    }

    return 0;
}

// 0x005DE000
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_SEQUENCE, &modeChange);
    UNITS_SetUsedSkill(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1));
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.pTargetUnit = pTargetUnit;
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
}

// 0x005DE130
void __fastcall sub_6FCD0150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }

    const unsigned int dwEventFrame = EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_AITHINK);
    if (!dwEventFrame || dwEventFrame == pGame->dwGameFrame || dwEventFrame >= nFrames + pGame->dwGameFrame)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
    }
}

// 0x005DE190
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg)
{
	D2_ASSERT(nValue >= -126 && nValue <= 126, 272);

	if (nParam == 1)
	{
		nParam = 7;
	}

	D2AiParamStrc* pAiParams = (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParams : 0;
	sub_005A6260_SetAiParamFields(pAiParams, nParam, nValue, nArg);
}

// 0x005DE320
void __fastcall sub_005DE320_AttachSoundNoOrigin(D2UnitStrc* pUnit, int nUpdateType)
{
    SUNIT_AttachSound(pUnit, nUpdateType, 0);
}

// 0x005DE330
void __fastcall AITACTICS_AddMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScrollTarget, unsigned short wMessage, int bScrollMessage)
{
    if (wMessage < 1 || wMessage > 0xFFFF)
    {
        return;
    }

    if (bScrollMessage)
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pScrollTarget, ".\\Ai\\AiTatics.cpp", 715);
        D2GSPacketSrv27 packet27;
        packet27.nHeader = 0x27;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        memcpy(&packet27.dwUnitGUID, &nUnitGUID, sizeof(nUnitGUID));
        packet27.nUnitType = UNIT_MONSTER;
        packet27.nCount = 1;
        packet27.pMessages[0].nMenu = 3;
        packet27.pMessages[0].nStringId = wMessage;
        D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
    }
    else
    {
        char szText[12];
        sprintf(szText, gszFormatD_006D57BC, wMessage);
        if (pUnit && pUnit->pHoverText)
        {
            CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        }

        D2HoverTextStrc* pHoverMsg = CHAT_AllocHoverMsg(pGame->pMemoryPool, szText, pGame->dwGameFrame);
        if (pHoverMsg)
        {
            if (pUnit)
            {
                pUnit->pHoverText = pHoverMsg;
            }

            UNITROOM_RefreshUnit(pUnit);
            if (pUnit)
            {
                pUnit->dwFlags |= UNITFLAG_HASTXTMSG;
            }

            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_FREEHOVER, CHAT_GetTimeoutFromHoverMsg(pHoverMsg), 0, 0);
        }
    }
}

// 0x005DE440
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE6D0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback)
{
    return sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pTarget, MONMODE_WALK, nMaxDistance, bDeleteAiEventCallback);
}

// 0x005DE890
D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2UnitStrc* pResult = sub_6FCF2110(pGame, pUnit, pAiControl, pDistance, pCombat);
    if (pResult)
    {
        return pResult;
    }

    if (sub_6FCF2E70(pUnit) && sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_WALK))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), nX, nY, nCollisionPattern, COLLIDE_MISSILE) && sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, MONMODE_WALK))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return 0;
    }

    int nFrames = *pDistance;
    if (nFrames >= 35)
    {
        nFrames = 25;
    }
    else if (nFrames < 25)
    {
        nFrames = 10;
    }
    else
    {
        nFrames -= 10;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, nFrames);
    return 0;
}

// 0x005DEDE0
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    int nMode = MONMODE_RUN;
    if (STATES_CheckState(pUnit, STATE_DECREPIFY))
    {
        D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(pUnit);
        nMode = MONMODE_WALK;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DEE50
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    const int nResult = D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    if (!nResult)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    }

    return nResult;
}

// 0x005DEEB0
int __fastcall AITACTICS_RunToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    int nMode = MONMODE_RUN;
    if (STATES_CheckState(pUnit, STATE_DECREPIFY))
    {
        D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(pUnit);
        nMode = MONMODE_WALK;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    const int nResult = D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    if (!nResult)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    }

    return nResult;
}

// 0x005DEF30
int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 0);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}
