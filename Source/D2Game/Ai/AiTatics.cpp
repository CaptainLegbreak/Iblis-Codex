#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"
#include "D2PlayerModes.h"

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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __stdcall sub_0062E880(D2UnitStrc* pItem); // 0x0062E880

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

enum D2C_F41AiTacticsConstants
{
    STATE_DECREPIFY = 60,
    EVENTTYPE_AITHINK = 2,
    EVENTTYPE_FREEHOVER = 6,
    UNITFLAG_HASTXTMSG = 0x100,
    MONSTATSFLAGINDEX_INTERACT = 9,
    COLLIDE_MISSILE = 0x40,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

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
    int unk0x08[8];
};

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0

int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0

int __fastcall sub_00544590_QuestsActiveFilter(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC); // 0x00544590

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

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

int __fastcall AITACTICS_MoveInRadiusToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nMaxDistance, int a6); // 0x005DE4E0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit); // 0x005A61F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int nParam18, int nParam1C, unsigned char nParam20); // 0x005A6260

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0

D2UnitStrc* __fastcall sub_6FCCFDE0(D2GameStrc* pGame, D2UnitStrc* pNPC, D2UnitStrc* pPlayer, void* pCallbackArg); // 0x005DDE80

D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60

#define UNIT_INVALID 6

#define UNIT_MONSTER 1

#define MONMODE_WALK 2

#define MONMODE_RUN 15

#define STATE_DECREPIFY 60

#define EVENTTYPE_AITHINK 2

union D2SeedStrc;

enum D2C_Y10UseSkillConstants
{
    UNITFLAG_SKSRVDOFUNC = 0x40,
};

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

// build: context CLIENTS_GetUnitX
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

// build: context CLIENTS_GetUnitY
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

    if (sub_00544590_QuestsActiveFilter(pGame, pPlayer, pNPC) && nDistance < pArg->nDistance)
    {
        pArg->nDistance = nDistance;
        pArg->pTarget = pPlayer;
        return pPlayer;
    }

    return 0;
}

// 0x005DDF20
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget)
{
    if (!UNITS_GetRoom(pUnit))
    {
        return 0;
    }

    UnkAiStrc1 tCallbackArg;
    tCallbackArg.pTarget = 0;
    tCallbackArg.nDistance = 0x7FFFFFFF;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &tCallbackArg, sub_6FCCFDE0, 2);

    if (!tCallbackArg.pTarget)
    {
        return pUnit;
    }

    if (tCallbackArg.nDistance < 4)
    {
        *bCloseToTarget = 1;
    }

    return tCallbackArg.pTarget;
}

// 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.pTargetUnit = pTargetUnit;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
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

// 0x005DE080
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }

    if (!pUnit || pUnit->dwAnimMode != MONMODE_NEUTRAL)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        modeChange.pTargetUnit = pUnit;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

// 0x005DE0F0
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
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

	D2AiParamStrc* pAiParams = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParam : 0;
	sub_005A6260_SetAiParamFields(pAiParams, nParam, nValue, nArg);
}

inline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

__forceinline int AI_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int AI_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DE200
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance)
{
    const int nTargetX = AI_GetUnitX(pUnit);
    const int nTargetY = AI_GetUnitY(pUnit);
    int nOffsetX;
    int nOffsetY;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetX = nMaxDistance;
        nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
    }
    else
    {
        nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
        nOffsetY = nMaxDistance;
    }

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, 0, MONMODE_WALK, nOffsetX + nTargetX, nOffsetY + nTargetY, 1, 0);
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
        D2ClientStrc* pClient = UnitGetClient(pScrollTarget, ".\\Ai\\AiTatics.cpp", 715);
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

// 0x005DE490
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesNoStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 0);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE4E0
int __fastcall AITACTICS_MoveInRadiusToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int a5, int a6)
{
    int nSign = 1;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance < a6)
    {
        nSign = -1;
    }

    const int nDelta = nDistance - a6;
    int nDiff = nDelta < 0 ? -nDelta : nDelta;
    if (nDiff > a5)
    {
        nDiff = a5;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    int nXOffset = 0;
    int nYOffset = 0;

    int nXDiff = nTargetX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    const int nYDelta = nTargetY - nY;
    const int nYDiff = nYDelta < 0 ? -nYDelta : nYDelta;

    int nSum = nYDiff + nXDiff;
    if (nSum < nDiff)
    {
        nSum = nDiff;
    }

    if (nSum > 0)
    {
        nXOffset = nDiff * nXDiff / nSum;
        nYOffset = nDiff * nYDiff / nSum;
        while (nXOffset + nYOffset < nDiff)
        {
            nXOffset += 1;
            nYOffset += 1;
        }
    }

    int nSignX = 0;
    int nSignY = 0;
    if (nTargetX > nX)
    {
        nSignX = 1;
    }
    if (nTargetX < nX)
    {
        nSignX = -1;
    }
    if (nTargetY > nY)
    {
        nSignY = 1;
    }
    if (nTargetY < nY)
    {
        nSignY = -1;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.nX = nX + nSign * nXOffset * nSignX;
    modeChange.nY = nY + nSign * nYOffset * nSignY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE6D0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback)
{
    return AITACTICS_MoveInRadiusToTarget(pGame, pUnit, pTarget, MONMODE_WALK, nMaxDistance, bDeleteAiEventCallback);
}

// 0x005DE830
D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pTarget->dwAnimMode == PLRMODE_DEATH || pTarget->dwAnimMode == PLRMODE_DEAD)
        {
            return 0;
        }
        return pTarget;

    case UNIT_MONSTER:
        if (pTarget->dwAnimMode == MONMODE_DEATH || pTarget->dwAnimMode == MONMODE_DEAD)
        {
            return 0;
        }
        return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) ? pTarget : 0;

    default:
        return 0;
    }
}

// 0x005DE890
D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2UnitStrc* pResult = sub_6FCF2110(pGame, pUnit, pAiControl, pDistance, pCombat);
    if (pResult)
    {
        return pResult;
    }

    if (sub_6FCF2E70(pUnit) && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_WALK))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), nX, nY, nCollisionPattern, COLLIDE_MISSILE) && sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_WALK))
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

static __forceinline void AITACTICS_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    EVENT_SetEvent(pGame, pUnit, 2, nFrames + pGame->dwGameFrame, 0, 0);
}

// 0x005DE9D0
D2UnitStrc* __fastcall sub_005DE9D0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiControl, pDistance, pCombat);
    if (pTarget)
        return pTarget;
    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), nX, nY, nCollisionPattern, 0x40) && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return 0;
    }
    AITACTICS_IdleInline(pGame, pUnit, 20);
    return 0;
}

// 0x005DEAD0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY)
{
    if (nMode >= 16)
    {
        return 0;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    UNITS_SetUsedSkill(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1));

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, 1);

    modeChange.pTargetUnit = pTarget;
    modeChange.nX = nX;
    modeChange.nY = nY;

    if (D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0))
    {
        return 1;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    return 0;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005DEB60
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags)
{
    int nNewMode = nMode;

    if (nMode == MONMODE_RUN && STATES_CheckState(pUnit, STATE_DECREPIFY))
    {
        D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(pUnit);
        nNewMode = MONMODE_WALK;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, bStep);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nNewMode, &modeChange);

    if (pTarget)
    {
        modeChange.pTargetUnit = pTarget;
    }
    else
    {
        modeChange.nX = nX;
        modeChange.nY = nY;
    }

    int nResult = D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    if (!nResult)
    {
        if (nFlags & 4)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
        }

        if (nFlags & 1)
        {
            D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
            if (pAiControl)
            {
                AIUTIL_ToggleAiControlFlag(pAiControl, 0x40, 1);
            }
        }

        if (nFlags & 2)
        {
            nResult = 1;
            if (AI_RollPercentage(pUnit) < 70)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
    }

    return nResult;
}

// 0x005DECA0
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);

    if (pTarget)
    {
        modeChange.pTargetUnit = pTarget;
    }
    else
    {
        modeChange.nX = 0;
        modeChange.nY = 0;
    }

    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DED00
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags)
{
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, 1, nFlags);
}

// 0x005DED20
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, 1, 0);
}

// 0x005DED40
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags)
{
    sub_005A6260_SetAiParamFields((pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParam : 0, 13, 0, 0);
    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_WALK, 0, 0, 1, nFlags);
}

// 0x005DED90
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
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

// 0x005DEF80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep)
{
    if (!bStep)
    {
        bStep = 1;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_WALK, 0, 0, bStep, 0);
}

// 0x005DEFB0
int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep)
{
    if (!bStep)
    {
        bStep = 1;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, pTarget, MONMODE_RUN, 0, 0, bStep, 0);
}

#include "gen/data/Source/D2Game/Ai/AiTatics.inc"
