#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientMenus.h"
#include "D2Win32Types.h"
#include "D2UnitData.h"
#include "D2Path.h"
#include "D2CelContext.h"
#include "D2Drlg.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    NUM_HOTKEYS = 114,
};

struct D2MsgRecordStrc
{
    int nTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2MsgRecordStrc tRecords[500];
    int nCount;
    int nIndex;
    D2MsgRecordChunkStrc* pNext;
};

struct D2PalShiftDataStrc
{
    int unk0x00;
    unsigned char aShift[8][0x100];
    unsigned char aShiftBlood[8][0x100];
};

struct T0044A980
{
    int nId;
    D2PalShiftDataStrc* pData;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

int __cdecl GAME_GetColorFlag();                                                                                 // 0x0044DC60

int __cdecl sub_0044DA90();                                                                                 // 0x0044DA90

int __fastcall RECORD_DispatchRecordedMessage(D2MsgRecordStrc* pRecord);                                          // 0x00451880

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit);                                               // 0x00463EB0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int gnReplayEndTick_007A2774;                                                                               // 0x007A2774

int gdwGlobal_007A2788;                                                                                     // 0x007A2788

extern int gdwGlobal_007A5208;                                                                              // 0x007A5208

extern int gdwGlobal_007A520C;                                                                              // 0x007A520C

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90

extern D2WheelCallbackFn gpfnWheelUp_007A7404;                                                              // 0x007A7404

extern D2WheelCallbackFn gpfnWheelDown_007A7408;                                                            // 0x007A7408

extern T0044A980* gpPalShiftEntries_007B9578;                                                     // 0x007B9578

extern unsigned char gaGlobalPalShifts_007B9580[0x1E][0x100];                                               // 0x007B9580

extern int gbGlobalPalShifts_007BB380;                                                                      // 0x007BB380

extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                    // 0x007A5E70

extern D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                    // 0x007A5270

extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70

extern D2DrlgActStrc* gpGlobal_007A0634;                                                                             // 0x007A0634

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

struct D2UnitStrc;

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);                                                   // 0x00643260

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall GFXUTIL_UnitSupportsMode(D2UnitStrc* pUnit, int nMode);                                 // 0x004DAE60

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

int __stdcall ITEM_GetGfxClientY(D2UnitStrc* pUnit);                                          // 0x004DA0D0

int __stdcall ITEM_GetGfxClientZ(D2UnitStrc* pUnit);                                          // 0x004DA0F0

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[];                                                      // 0x00711F34

int __stdcall sub_O05_EmitArg_SkillId(D2UnitStrc* pUnit);

struct D2GfxLightStrc;

struct D2UnitSpawnExtraStrc
{
    int nArg10;
    int nArg14;
};

struct D2UnitSpawnStrc
{
    unsigned int nUnitId;
    int nClassId;
    int nX;
    int nY;
    D2UnitSpawnExtraStrc tExtra;
    int nMode;
};

extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634

void __fastcall DLIGHTMAP_ReleaseLight(D2GfxLightStrc* pLight);                                   // 0x004743D0

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                         // 0x00643A00

void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit);                                               // 0x004DA080

void __fastcall sub_004CA9C0_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce);                               // 0x004CA9C0

void __fastcall MONSTER_FreeClientUnit(D2UnitStrc* pUnit);                                             // 0x004AED30

void __fastcall OBJECT_ReleaseItemUnit(D2UnitStrc* pUnit);                                            // 0x004C1A70

void __fastcall OBJECT_ReleaseObjectUnit(D2UnitStrc* pUnit);                                                // 0x004BCA50

void __fastcall MISSILE_FreeMissileUnit(D2UnitStrc* pMissile);                                         // 0x004CD170

void __fastcall CUNITEVENT_FreeCltUnitEvents(D2UnitStrc* pUnit);                                          // 0x004DC0C0

void __fastcall SCMD_FreePacketBuffer(void* pArg);                                                  // 0x0045F9F0

void __cdecl UI_FreePlayerUI();                                                                                // 0x00453DE0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0

void __fastcall GAME_SetStandStillHeld(int nValue);                                                          // 0x0044BEA0

void __cdecl UI_LoadPlayerUI();                                                                   // 0x00453D90

void __fastcall VIEW_ResetSelectionForUnit(D2UnitStrc* pUnit);                                                            // 0x004879D0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp);  // 0x004C0EC0

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

D2ActiveRoomStrc* __fastcall CUNIT_FindRoomBySubtile(int nX, int nY);                                // 0x00465420

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __fastcall SKILLS_InitMissileUnit(D2UnitStrc* pMissile, D2ActiveRoomStrc* pRoom, int nTargetX, int nTargetY, int nUnused); // 0x004CD0A0

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

void __fastcall PLAYERLIST_InitGfxData(D2UnitStrc* pUnit);                                                // 0x004DC510

void __fastcall OBJECT_UpdateObjectOverlay(D2UnitStrc* pUnit);                                        // 0x004BC8D0

D2UnitStrc* __fastcall CUNIT_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6); // 0x00466360

int CUNIT_AddUnitToTable(D2UnitStrc* pUnit); // 0x00463A50

struct D2InventoryStrc;

struct Unicode;

struct D2MonsterInfo16Strc
{
    unsigned int aValues[4];
};

struct D2MonsterDataLocalStrc
{
    char unk0x00[0x04];
    D2MonsterInfo16Strc tInfo;
};

struct D2HirelingInfoStrc
{
    unsigned short wValue;
    char unk0x02[2];
    unsigned int dwValue;
    int unk0x08;
    int unk0x0C;
};

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10

int __fastcall sub_00477620_RollUnitValue(D2UnitStrc* pUnit, unsigned short nOffset); // 0x00477620

D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20

int __fastcall ROSTER_GetPetType(int nUnitId);                                                        // 0x00479180

int __fastcall sub_004791B0_IsOwnedByPlayer(D2UnitStrc* pUnit);                                             // 0x004791B0

unsigned char* __fastcall MONSTER_GetMonUmods(D2UnitStrc* pUnit);                                  // 0x004AC740

void __fastcall sub_004AC7A0(D2UnitStrc* pUnit, unsigned short wValue);                                     // 0x004AC7A0

short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit);                                          // 0x004AC7C0

void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags);                      // 0x004AE0A0

void __fastcall MONSTER_SetOwnerGUID(D2UnitStrc* pUnit, unsigned int dwValue);                                      // 0x004AE150

int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit);                                              // 0x004AE360

void __fastcall sub_004AE8D0(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nMode); // 0x004AE8D0

void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo);                    // 0x004B1090

void __fastcall UNITSND_PlayInitSound(D2UnitStrc* pUnit);                                              // 0x004CC380

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);         // 0x0063E810

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0

static D2UnitStrc* __stdcall CUNIT_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType); // 0x00463940

static void CUNIT_ApplyClassEffects(D2UnitStrc* pUnit, int nClassId); // 0x004656C0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200

void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0

void __fastcall MISSILE_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0


static D2UnitStrc* CUNIT_InsertUnit(D2UnitStrc* pUnit); // 0x00465F20

// 0x004519C0
void __cdecl CUNIT_ReplayRecords()
{
    if (!gdwGlobal_007A2788)
        return;
    if (!gpMsgRecordChunk_0070F7A0)
        return;
    const int nNow = sub_0044DA90();
    if (nNow >= gnReplayEndTick_007A2774)
    {
        gdwGlobal_007A2788 = 0;
        return;
    }
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunk_0070F7A0;
    D2_ASSERT(pChunk->nIndex < 500, 0x189);
    if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
        return;
    D2MsgRecordStrc* pRecord = &pChunk->tRecords[pChunk->nIndex];
    while (pRecord->nTick <= nNow)
    {
        RECORD_DispatchRecordedMessage(pRecord);
        pChunk = gpMsgRecordChunk_0070F7A0;
        pChunk->nIndex++;
        if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
            return;
        if (pChunk->nIndex >= 500)
        {
            pChunk = pChunk->pNext;
            gpMsgRecordChunk_0070F7A0 = pChunk;
        }
        if (!pChunk)
            return;
        pRecord = &pChunk->tRecords[pChunk->nIndex];
    }
}

// 0x0045B1A0
void __fastcall sub_0045B1A0_DrawDiamond(int nX, int nY, unsigned char nColor)
{
    tagRECT tRect;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, nColor);
}

// 0x004637F0
unsigned char* __fastcall CUNIT_GetMonsterComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

static inline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

// 0x00463860
int __fastcall sub_00463860(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

// 0x00463920
static inline D2UnitStrc** CUNIT_GetClientHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5E70[nUnitType * 0x80];
}

// 0x00463930
static inline D2UnitStrc** CUNIT_GetServerHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5270[nUnitType * 0x80];
}

// build: context UNIT_HasFlag
inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// build: context UNIT_HasFlagEx
inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// build: context CUNIT_GetUnitClassId
static inline int CUNIT_GetUnitClassId(D2UnitStrc* pUnit)
{
    return pUnit->dwClassId;
}

static D2UnitStrc* __stdcall CUNIT_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType)
{
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
    }
    return 0;
}

// build: symbol ?CUNIT_FindClientUnit@* 0x00463990
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType)
{
    return CUNIT_FindUnitInTable(&gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

// build: symbol ?CUNIT_FindServerSideUnit@* 0x004639B0
D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    return CUNIT_FindUnitInTable(&gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x83);
    if (UNIT_HasFlagEx(pUnit, 0x400))
    {
        const int nOwnerType = pUnit->dwOwnerType;
        const unsigned int nOwnerGUID = pUnit->dwOwnerGUID;
        const int nHash = nOwnerGUID & 0x7F;
        if (nOwnerType == 3)
        {
            return CUNIT_FindUnitInTable(&gpUnitHashTable_007A5270[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
        }
        return CUNIT_FindUnitInTable(&gpUnitHashTable_007A5E70[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
    }
    return 0;
}

// 0x00463A50
static int CUNIT_AddUnitToTable(D2UnitStrc* pUnit)
{
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        if (CUNIT_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!CUNIT_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0x9C);
    }
    else
    {
        if (CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0xA5);
    }

    sub_004CC160(pUnit, 1);

    const unsigned int nUnitId = pUnit->dwUnitId;
    const int nType = pUnit->dwUnitType;
    D2UnitStrc** ppTable;
    int nHash;
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        nHash = nUnitId & 0x7F;
        ppTable = &gpUnitHashTable_007A5270[nType * 0x80];
    }
    else
    {
        nHash = nUnitId & 0x7F;
        ppTable = &gpUnitHashTable_007A5E70[nType * 0x80];
    }

    D2UnitStrc* pNext = ppTable[nHash];
    D2UnitStrc* pPrev = 0;
    for (;;)
    {
        if (!pNext)
        {
            pUnit->pListNext = pNext;
            break;
        }
        if (pNext->dwUnitId <= nUnitId)
        {
            pUnit->pListNext = pNext;
            break;
        }
        pPrev = pNext;
        pNext = pNext->pListNext;
    }
    if (pPrev)
    {
        pPrev->pListNext = pUnit;
    }
    else
    {
        ppTable[nHash] = pUnit;
    }

    return 1;
}

// 0x00463C60
static inline void CUNIT_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    if (gpGlobal_007A0634)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
}

// 0x00463D70
void __cdecl sub_00463D70_Empty()
{
}

// 0x00463DD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit()
{
    return gpPlayerUnit_007A6A70;
}

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00463FE0
static int __stdcall CUNIT_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, int nX, D2UnitStrc* pUnit)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    DUNGEON_GameSubtileToClientCoords(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

static inline int OBJECTS_IsDeadInline(int nClassId, int nMode)
{
    const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord(nClassId)->nFlags1B7;
    return (nFlags & 2) || (nMode == 2 && (nFlags & 1));
}

// 0x00464860
int __fastcall CUNIT_IsUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMode = pUnit->dwAnimMode;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
            if (OBJECTS_IsDeadInline(pUnit->dwClassId, nMode))
            {
                return 1;
            }
            break;
        case UNIT_ITEM:
            return nMode == 3;
        case UNIT_MONSTER:
            if (!MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 0x14) && nMode == 12)
            {
                return 1;
            }
            break;
        case UNIT_PLAYER:
            if (nMode == 17)
            {
                return 1;
            }
            break;
        case UNIT_MISSILE:
            if (pUnit->dwFlags & 0x10000)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}

void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90

// build: symbol ?CUNIT_SetTargetByGUID@* 0x004643F0
void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, CUNIT_FindClientUnit(nUnitId, nUnitType));
}

// build: symbol ?CUNIT_IsItemInInventory@* 0x00464D20
static int __stdcall CUNIT_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (pOwner == pUnit)
    {
        return 0;
    }

    if (pUnit->pInventory)
    {
        for (D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pUnit->pInventory); pEntry; pEntry = INVENTORY_GetNextItem(pEntry))
        {
            D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pEntry);
            D2_ASSERT(pInvItem, 0xA5B);
            if (pInvItem == pItem)
            {
                return 1;
            }
        }
    }

    return 0;
}

// build: symbol ?CUNIT_IsItemOwnedByOther@* 0x00464D90
static int __stdcall CUNIT_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem)
{
    D2UnitStrc** ppTable = gpUnitHashTable_007A5E70;
    for (int nTable = 0; nTable < 2; ++nTable)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
            {
                if (CUNIT_IsItemInInventory(pOwner, pItem, pUnit))
                {
                    return 1;
                }
            }
        }
        ppTable = &gpUnitHashTable_007A5E70[0x80];
    }
    return 0;
}

// build: symbol ?CUNIT_FreeUnit@* 0x00465870
static void CUNIT_FreeUnit(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        DLIGHTMAP_ReleaseLight(pUnit->pLight);
        pUnit->pLight = 0;
    }

    D2GfxLightStrc* pRoomLight = D2Common_10958(pUnit, 0);
    if (pRoomLight)
    {
        DLIGHTMAP_ReleaseLight(pRoomLight);
    }

    PARTICLE_FreeGfxMotion(pUnit);
    sub_004CA9C0_ReleaseUnitHints(pUnit, 0);
    sub_004CC160(pUnit, -1);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_00460D50_FreePlayerUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MONSTER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        MONSTER_FreeClientUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_ITEM:
        OBJECT_ReleaseItemUnit(pUnit);
        ITEMS_FreeItemData(0, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_OBJECT:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        OBJECT_ReleaseObjectUnit(pUnit);
        UNITS_FreeStaticPath(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MISSILE:
        MISSILE_FreeMissileUnit(pUnit);
        break;

    case UNIT_TILE:
        if (gpAct_007A0634)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    CUNITEVENT_FreeCltUnitEvents(pUnit);
    SCMD_FreePacketBuffer(pUnit);

    if (pUnit == gpPlayerUnit_007A6A70)
    {
        CUNIT_SetPlayerUnit(0);
    }

    UNITS_FreeUnit(pUnit);
}

// build: symbol ?CUNIT_FreeAllUnits@* 0x004659C0
void __cdecl CUNIT_FreeAllUnits()
{
    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                CUNIT_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }

    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                CUNIT_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }
}

// build: symbol ?CUNIT_RemoveUnitFromTable@* 0x00465E80
static void CUNIT_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash)
{
    D2UnitStrc* pPrev = 0;
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId && pUnit->dwUnitType == nUnitType)
        {
            if (!pPrev)
            {
                ppTable[nHash] = pUnit->pListNext;
            }
            else
            {
                pPrev->pListNext = pUnit->pListNext;
            }

            if (pUnit->dwUnitType == UNIT_ITEM)
            {
                VIEW_ResetSelectionForUnit(pUnit);
            }

            CUNIT_FreeUnit(pUnit);
            return;
        }
        pPrev = pUnit;
    }
}

// build: symbol ?CUNIT_RemoveClientSideUnit@* 0x00465EE0
void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType)
{
    CUNIT_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId & 0x7F);
}

// build: symbol ?CUNIT_RemoveServerSideUnit@* 0x00465F00
void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    CUNIT_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId & 0x7F);
}

static D2UnitStrc* CUNIT_InsertUnit(D2UnitStrc* pUnit)
{
    if (!CUNIT_AddUnitToTable(pUnit))
    {
        D2UnitStrc* pOld = CUNIT_FindClientUnit(pUnit->dwUnitId, pUnit->dwUnitType);
        D2_ASSERT(pOld != pUnit, 0x1C6);
        if (pOld)
        {
            if (UNIT_HasFlag(pOld, 0x200000))
            {
                CUNIT_RemoveServerSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }
            else
            {
                CUNIT_RemoveClientSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }

            if (CUNIT_AddUnitToTable(pUnit))
            {
                return pUnit;
            }
        }

        CUNIT_FreeUnit(pUnit);
        pUnit = 0;
    }

    return pUnit;
}

// build: symbol ?CUNIT_RemoveInventoryUnits@* 0x00466CB0
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner)
{
    D2_ASSERT(pUnit, 0xA80);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pInventory);
    while (pEntry)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pEntry);
        D2UnitStrc* pItem = CUNIT_FindClientUnit(INVENTORY_GetItemGUID(pEntry), 4);
        if (pItem)
        {
            int bRemove = 1;
            if (bCheckOwner)
            {
                bRemove = !CUNIT_IsItemOwnedByOther(pUnit, pItem);
            }

            if (bRemove)
            {
                ITEM_UpdateItemLink(pItem, pUnit, 0, 0);
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA92);
                CUNIT_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }
            else
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA96);
            }
        }
        pEntry = pNext;
    }
}

// build: symbol ?CUNIT_InitUnit@* 0x00465FD0
static D2UnitStrc* __stdcall CUNIT_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX)
{
    const int bFlag = GAME_IsExpansion();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom = 0;
    if (nX || nY)
    {
        pRoom = CUNIT_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (nUnitType == 4)
    {
        ITEMS_AllocItemData(0, pUnit);
        ITEMS_InitItemSeed(pUnit);
    }

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    switch (nUnitType)
    {
    case 0:
        sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
        break;

    case 1:
        D2_ASSERT(0, 0x202);
        break;

    case 2:
        UNITS_AllocStaticPath(pUnit);
        sub_004BC720_InitObjectUnit(pUnit, pRoom, nX, nY, nClassId, nArg6);
        break;

    case 4:
        UNITS_AllocStaticPath(pUnit);
        sub_004C1910_InitItemUnit(pUnit, pRoom, nX, nY, nArg5, 1);
        break;

    case 3:
        SKILLS_InitMissileUnit(pUnit, pRoom, nX, nY, nClassId);
        break;

    case 5:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= 0x22;
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }

    if (nUnitType != 5)
    {
        PLAYERLIST_InitGfxData(pUnit);
        if (nUnitType == 0 || nUnitType == 1)
        {
            UnitUpdateAnimRateAndVel(pUnit, gszCUnitFile_006D6A48, 0x21D);
        }
    }

    pUnit = CUNIT_InsertUnit(pUnit);
    if (pUnit && nUnitType == 2)
    {
        OBJECT_UpdateObjectOverlay(pUnit);
    }

    return pUnit;
}

// build: symbol ?CUNIT_CreatePlayerUnit@* 0x00466200
D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, 0);
    if (!pUnit)
    {
        return 0;
    }

    const int bFlag = GAME_IsExpansion();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwClassId = nClassId;
    pUnit->dwUnitType = 0;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom;
    if (nX || nY)
    {
        pRoom = CUNIT_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }
    else
    {
        pRoom = 0;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
    PLAYERLIST_InitGfxData(pUnit);
    UnitUpdateAnimRateAndVel(pUnit, gszCUnitFile_006D6A48, 0x21D);

    pUnit = CUNIT_InsertUnit(pUnit);
    if (pUnit)
    {
        UNITS_SetNameInPlayerData(pUnit, szName);
    }

    return pUnit;
}

// build: symbol ?CUNIT_AllocClientUnit@* 0x004661C0
D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    return CUNIT_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, 0, pUnit, nX);
}

// build: symbol ?CUNIT_CreateObjectUnit@* 0x00466300
D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit = CUNIT_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, nArg6, pUnit, nX);
    if (pUnit)
    {
        pUnit->pObjectData->InteractType = nInteractType;
        if (UNITS_IsShrine(pUnit))
        {
            sub_004BD6B0_InitShrine(pUnit);
        }
    }

    return pUnit;
}

// build: symbol ?CUNIT_SpawnPresetUnit@* 0x00466730
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg)
{
    if (++gnPresetUnitId_00711F30 == -1)
    {
        gnPresetUnitId_00711F30 = 0;
    }

    if (nUnitType == 1)
    {
        D2UnitSpawnStrc tSpawn = {};
        tSpawn.nUnitId = gnPresetUnitId_00711F30;
        tSpawn.nClassId = nClassId;
        tSpawn.nX = nX;
        tSpawn.nY = nY;
        tSpawn.nMode = nUnitType;
        return CUNIT_AddClientMonster(&tSpawn, 0, 0, 0, 0, nUnitType);
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x600000;
    return CUNIT_InitUnit(gnPresetUnitId_00711F30, nClassId, nY, nUnitType, nArg, 0, pUnit, nX);
}

static void CUNIT_ApplyClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        GFX_AddUnitOverlay(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        GFX_AddUnitOverlay(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        GFX_AddUnitOverlay(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_SetMotionVectorA(pUnit, 0, 0, -0x37);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        MISSILE_SetMotionFlagMask(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            GFX_AddUnitOverlay(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        GFX_AddUnitOverlay(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

static inline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static inline D2MonStats2Txt* sub_A3_GetMonStats2TxtRecord(int nMonStatsEx)
{
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }

    return 0;
}

static inline D2MonStatsTxt* sub_A3_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

static inline D2MonsterInfo16Strc* sub_F4B0_GetMonsterInfo(D2UnitStrc* pUnit)
{
    D2MonsterDataLocalStrc* pMonsterData = pUnit->dwUnitType == UNIT_MONSTER ? (D2MonsterDataLocalStrc*)pUnit->pMonsterData : 0;
    return pMonsterData ? &pMonsterData->tInfo : 0;
}

static inline unsigned int sub_F4B0_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00466360
D2UnitStrc* __fastcall CUNIT_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6)
{
    const unsigned int nUnitId = pSpawn->nUnitId;
    if (nUnitId == sub_00478F20_FindPetIdByOwner(gpPlayerUnit_007A6A70, 7, 1))
    {
        D2UnitStrc* pPet = CUNIT_FindUnitInTable(&gpUnitHashTable_007A5E70[UNIT_MONSTER * 0x80], nUnitId, nUnitId & 0x7F, UNIT_MONSTER);
        if (pPet)
        {
            GFX_FreeGfxData(pPet);
            PLAYERLIST_InitGfxData(pPet);
            UNITS_ChangeAnimMode(pPet, pSpawn->nMode);
            return pPet;
        }
    }

    const int nClassId = pSpawn->nClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    D2MonStats2Txt* pMonStats2TxtRecord = 0;
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        pMonStats2TxtRecord = sub_A3_GetMonStats2TxtRecord(sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx);
    }

    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, UNIT_MONSTER);
    D2UnitStrc* pMonster = pUnit;
    if (nArg6 && pUnit)
    {
        pUnit->dwFlags |= 0x600000;
    }

    const int nX = pSpawn->nX;
    const int nY = pSpawn->nY;
    pUnit->dwUnitType = UNIT_MONSTER;
    pUnit->dwClassId = pSpawn->nClassId;
    pUnit->dwUnitId = pSpawn->nUnitId;
    pUnit->pMemoryPool = 0;
    pUnit->dwTickCount = 0;
    D2ActiveRoomStrc* pRoom = CUNIT_FindRoomBySubtile(nX, nY);
    SEED_InitSeed(&pUnit->pSeed);
    if (pRoom)
    {
        pUnit->dwInitSeed = sub_F4B0_SeedStep(&pRoom->pSeed);
    }

    SEED_InitLowSeed(&pUnit->pSeed, pUnit->dwInitSeed);
    MONSTER_SetClientFlags(pUnit, 0);
    sub_004AC810_ToggleMonsterFlag(pUnit, (unsigned short)pSpawn->tExtra.nArg10, 1);
    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        sub_004AC7A0(pUnit, nArg5);
    }

    MONSTER_SetOwnerGUID(pUnit, pSpawn->tExtra.nArg14);
    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr));
    if (pArg3)
    {
        sub_004AC780_SetMonsterWord(pUnit, nArg4);
        unsigned char* pBytes = MONSTER_GetMonUmods(pUnit);
        pBytes[0] = pArg3[0];
        pBytes[1] = pArg3[1];
        pBytes[2] = pArg3[2];
        pBytes[3] = pArg3[3];
        pBytes[4] = pArg3[4];
        pBytes[5] = pArg3[5];
        pBytes[6] = pArg3[6];
        pBytes[7] = pArg3[7];
        pBytes[8] = pArg3[8];
    }

    if (pArg2)
    {
        D2MonsterInfo16Strc* pInfo = sub_F4B0_GetMonsterInfo(pUnit);
        if (pInfo)
        {
            *pInfo = *(D2MonsterInfo16Strc*)pArg2;
        }
    }

    sub_004AE8D0(pUnit, pRoom, nX, nY, nClassId, pSpawn->nMode);
    PATH_SetStepNum(pUnit->pDynamicPath, pMonStats2TxtRecord->nSteps);
    PLAYERLIST_InitGfxData(pUnit);
    CUNIT_ApplyClassEffects(pUnit, nClassId);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    if (MONSTER_IsUniqueMonster(pUnit) && !MONSTERREGION_CheckMonStats2Flag(nClassId, 15))
    {
        nMode = sub_00477620_RollUnitValue(pUnit, nArg4);
    }

    D2MonStats2Txt* pModeTxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (pModeTxtRecord && pModeTxtRecord->nModes[GAME_GetDifficulty()])
    {
        nMode = pModeTxtRecord->nModes[GAME_GetDifficulty()];
        if (nMode == 0xFF)
        {
            nMode = !sub_004791B0_IsOwnedByPlayer(pUnit);
        }
    }

    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (pSuperUniquesTxtRecord->nModes[GAME_GetDifficulty()])
        {
            nMode = pSuperUniquesTxtRecord->nModes[GAME_GetDifficulty()];
        }
    }

    if (nMode >= 30)
    {
        nMode = 2;
    }

    sub_0046F1C0(pUnit->pGfxData, nMode);
    sub_0046F220(pUnit->pGfxData, nMode);
    pUnit = CUNIT_InsertUnit(pUnit);
    if (ROSTER_GetPetType(pUnit->dwUnitId) == 7)
    {
        D2ClientEntryStrc* pEntry = sub_00478E40_FindEntry(pUnit->dwUnitId);
        if (pEntry)
        {
            D2HirelingInfoStrc tInfo;
            tInfo.dwValue = pEntry->dwValue;
            tInfo.wValue = pEntry->wValue;
            MONSTER_InitHireling(pMonster, &tInfo);
        }
    }

    if (MONSTERS_GetHirelingTypeId(pMonster))
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    UNITSND_PlayInitSound(pMonster);
    return pMonster;
}

// 0x00477530
unsigned char* __fastcall CUNIT_GetPalShift(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2PalShiftDataStrc* pData = gpPalShiftEntries_007B9578[pUnit->dwClassId].pData;
        if (!pData)
            return 0;
        int nMode = CUNIT_GetPalShiftIndex(pUnit);
        switch (nMode)
        {
        case 0:
        case 1:
            switch (pUnit->dwClassId)
            {
            case 0x16B:
            case 0x16C:
                return pData->aShift[nMode];
            }
            return 0;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        default:
            if (gbGlobalPalShifts_007BB380)
            {
                nMode -= 8;
                D2_ASSERT(nMode >= 0 && nMode < 0x1E, 0x160);
                return gaGlobalPalShifts_007B9580[nMode];
            }
            break;
        }
        if (GAME_GetColorFlag())
        {
            D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2TxtRecord && pMonStats2TxtRecord->nLocalBlood == 2)
                return pData->aShiftBlood[nMode];
        }
        return pData->aShift[nMode];
    }
    return 0;
}

D2UnitStrc* __fastcall sub_M109_Emit_00463920(int nUnitType, int nHash)
{
    return CUNIT_GetClientHashTable(nUnitType)[nHash] ? CUNIT_GetServerHashTable(nUnitType)[nHash] : 0;
}

void __fastcall sub_M109_Emit_00463C60(D2UnitStrc* pUnit)
{
    CUNIT_RemoveUnitFromRoom(pUnit);
}

int __fastcall sub_Q03_Emit_ObjectSelectBox(D2UnitStrc* pUnit, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    if (pObjectsTxtRecord->nIsDoor)
    {
        return CUNIT_IsInObjectSelectBox(nY, pObjectsTxtRecord, nX, pUnit);
    }

    return 0;
}

// build: symbol ?CUNIT_GetUnitSelectRect@* 0x004640A0
static int __stdcall CUNIT_GetUnitSelectRect(unsigned int nFrame, D2RectStrc* pRect, D2UnitStrc* pUnit, int nMode)
{
    if (GFXUTIL_UnitSupportsMode(pUnit, nMode))
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));

        int nOut;
        if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, nMode, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2CelStrc* pCell = tContext.pCel;
            if (pCell)
            {
                D2_ASSERT(nFrame <= tContext.nFrames, 0x5DF);

                const int nOffsetX = CelGetOffsetX(pCell) - 12;
                pRect->nLeft = nOffsetX + UNITS_GetClientCoordX(pUnit);
                pRect->nRight = CelGetWidth(pCell) + pRect->nLeft + 24;
                const int nTop = CelGetOffsetY(pCell) + UNITS_GetClientCoordY(pUnit) + 12;
                pRect->nTop = nTop;
                pRect->nBottom = nTop - CelGetHeight(pCell) - 24;

                const int nWidth = pRect->nRight - pRect->nLeft;
                if (nWidth < 32)
                {
                    const int nPad = (32 - nWidth) >> 1;
                    pRect->nRight += nPad;
                    pRect->nLeft -= nPad;
                }

                const int nHeight = nTop - pRect->nBottom;
                if (nHeight < 32)
                {
                    const int nPad = (32 - nHeight) >> 1;
                    pRect->nBottom -= nPad;
                    pRect->nTop += nPad;
                }

                const int nGfxOffsetX = sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
                const int nGfxOffsetY = ITEM_GetGfxClientY(pUnit) + ITEM_GetGfxClientZ(pUnit);
                pRect->nLeft += nGfxOffsetX;
                pRect->nRight += nGfxOffsetX;
                pRect->nTop += nGfxOffsetY;
                pRect->nBottom += nGfxOffsetY;
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall sub_Q03_Emit_UnitSelectRect(D2UnitStrc* pUnit, int nX)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);

    D2RectStrc tRect;
    for (int nMode = 0; nMode < 16; ++nMode)
    {
        if (CUNIT_GetUnitSelectRect(nFrameNo, &tRect, pUnit, nMode) && nX >= tRect.nLeft && nX <= tRect.nRight)
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_004642B0(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pPlayer)))
    {
        return 1;
    }

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pTarget)) != 0;
}

#include "gen/data/Source/D2Client/UNIT/CUnit_00466360.inc"
