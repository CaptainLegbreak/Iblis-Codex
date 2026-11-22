#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2MonModes.h"

#include "D2Primitives.h"
#include "D2LevelTxt.h"
#define MONTYPEFLAG_UNIQUE 8
#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
struct D2ModeChangeStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ServerCallbacks;
struct D2StatesTxt;
struct D2GSPacketSrvAA;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall sub_00570850_Forward(void* pUnused, D2UnitStrc* pUnit, int nArg); // 0x00570850

typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks { char unk_00[44]; LevelCallback levelUp; };

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall sub_00625D60(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0
void __fastcall sub_00536850_UpdateLevel(D2GameStrc*,D2UnitStrc*,int); // 0x00536850
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc*,D2UnitStrc*); // 0x0055F500
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc*,D2UnitStrc*,int); // 0x0055FDE0
int __stdcall sub_00622150_GetLevelInfo(D2UnitStrc*,int,int); // 0x00622150
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue);
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

#pragma pack(push, 1)
struct D2GSPacketSrvAA { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nSize; unsigned char pStream[244]; };

#pragma pack(pop)

extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc*); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int); // 0x004111A0
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc*); // 0x0063A100
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc*, D2StatStrc*, int); // 0x00625C90
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc*, const void*, int); // 0x0053E8D0

// 0x00570420
void __fastcall SKILLS_StunMonster(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nDelay)
{
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && !MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) && !MONSTERS_IsBoss(0, pUnit))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nDelay);
        int nFrame = pGame->dwGameFrame;
        if (!pStatList)
        {
            const int nUnitGUID = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            nFrame += 100;
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nFrame, nUnitType, nUnitGUID);
            if (pStatList)
            {
                EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
                STATLIST_SetState(pStatList, STATE_STUNNED);
                STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                STATES_ToggleState(pUnit, STATE_STUNNED, 1);
            }
        }
        else
        {
            nFrame += nDelay;
            D2COMMON_10476(pStatList, nFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
        }

        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        pUnit->dwFlags &= ~UNITFLAG_DOUPDATE;
    }
}
