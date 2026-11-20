#include "D2Game.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_TRAP 4
#define UNITFLAG_TARGETABLE 2
#define MONSTER_FLYINGSCIMITAR 234
#define MONMODE_WALK 2
typedef int (__stdcall* FARPROC)();


struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectsTxt
{
    char unk0x000[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0x0F8[0x28];
    unsigned char nHasCollision[8];
    char unk0x128[0x17]; unsigned char nMode[8]; char unk0x147[0x31];
    unsigned int dwParm[8];
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
};


struct D2MonRegDataStrc
{
    short nMonHcIdx;
    char unk0x002[0x32];
};

struct D2MonsterRegionStrc
{
    char unk0x000[0x10];
    unsigned char nMonCount;
    char unk0x011[0x3];
    D2MonRegDataStrc pMonData[1];
};

struct D2GameStrc
{
    char unk0x000[0xA8];
    int dwGameFrame;
    char unk0x0AC[0x44];
    D2MonsterRegionStrc* pMonReg[1];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

typedef void (__fastcall* ObjTrapHandlerFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

extern ObjTrapHandlerFunction gpObjectTrapHandlerTable_00732CEC[];                                          // 0x00732CEC
extern D2MonStatsCountStrc* sgptDataTables;                                                                 // 0x00744304

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp);                                            // 0x005474C0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pUnit, int nUnitId);                                // 0x00552AF0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);      // 0x00585B90
D2UnitStrc* __fastcall sub_005A43E0_QUESTS_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nMonsterId, int a5, int a6, int a7, int a8); // 0x005A43E0
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill);                                                     // 0x00644360

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

// 0x00582250
static int __stdcall sub_00582250(D2ActiveRoomStrc* pRoom, int nMonsterId)
{
    if (nMonsterId == MONSTER_FLYINGSCIMITAR && pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == ACT_I)
    {
        return 0;
    }

    return 1;
}

// 0x00582280
static void D2GAME_SpawnTrapMonster_6FC75B40(D2ObjOperateFnStrc* pOp, int nMonsterId, int nAnimMode)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
        if (nMonsterId != MONSTER_FLYINGSCIMITAR || !pRoom || DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != ACT_I)
        {
            if (!sub_6FC6A150(pOp->pGame, pOp->pObject, nMonsterId, nAnimMode, (-1), 0)
                && !sub_6FC6A150(pOp->pGame, pOp->pObject, nMonsterId, nAnimMode, 1, 0))
            {
                sub_6FC6A150(pOp->pGame, pOp->pObject, nMonsterId, nAnimMode, 3, 0);
            }
        }
    }
}

// 0x005822F0
void __fastcall D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ObjOperateFnStrc op;
    op.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pUnit));
    op.pObject = pUnit;
    op.pGame = pGame;

    const int nMonsters = (SEED_RollRandomNumber_Inline(&op.pObjectregion->pSeed) & 1) + 1;

    const int nMonsterId = OBJRGN_GetTrapMonsterId(&op);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        for (int i = 0; i < nMonsters; ++i)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(&op, nMonsterId, 8);
        }
    }
}

// 0x00582510
static void __stdcall D2GAME_SetTrapCallback_6FC764B0(unsigned char nTrapType, D2ObjOperateFnStrc* pOp)
{
    if (nTrapType < gnObjectTrapHandlerCount_00732D14 && gpObjectTrapHandlerTable_00732CEC[nTrapType])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[nTrapType]), 0x56C);

        if (gpObjectTrapHandlerTable_00732CEC[nTrapType] == D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0
            && !sub_00582250(UNITS_GetRoom(pOp->pObject), OBJRGN_GetTrapMonsterId(pOp)))
        {
            return;
        }

        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_TRAP, pOp->pGame->dwGameFrame + 35, 0, 0);
        SUNIT_AttachSound(pOp->pObject, 13, 0);
    }
}

// 0x00583F10
int __fastcall OBJECTS_OperateFunction51_JungleStash(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_AIRESET, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[1] + 1, 0, 0);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->pObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->pObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
        OBJECTS_SetUnitIdInTimerArg(pOp->pObject, !pOp->pPlayer ? -1 : pOp->pPlayer->dwUnitId);
    }

    return 1;
}

// 0x00586410
int __fastcall OBJECTS_OperateFunction01_Casket(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->pObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->pObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x00586520
int __fastcall OBJECTS_OperateFunction68_EvilUrn(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 255 <= pObjectsTxtRecord->dwParm[7])
        {
            D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
            const int nMonCount = pMonsterRegion->nMonCount;
            for (int i = 0; i < nMonCount; ++i)
            {
                const int nMonsterId = pMonsterRegion->pMonData[i].nMonHcIdx;
                if (sub_0046C140_CheckMonStats2ModeFlag(nMonsterId, MONMODE_WALK))
                {
                    sub_005A43E0_QUESTS_SpawnMonster(pOp->pGame, UNITS_GetRoom(pOp->pObject), 0, nMonsterId, 1, 0, 0, 1);
                    break;
                }
            }
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->pObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->pObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005866C0
int __fastcall OBJECTS_OperateFunction03_Urn_Basket_Jar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->pObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->pObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005867A0
int __fastcall OBJECTS_OperateFunction14_Corpse(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->pObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->pObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005868A0
int __fastcall OBJECTS_OperateFunction05_Barrel(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));

        if (pOp->pPlayer && pOp->pPlayer->dwUnitType == UNIT_PLAYER)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pOp->pPlayer, 1, -1);
            if (pSkill)
            {
                UNITS_SetTargetUnitForDynamicUnit(pOp->pPlayer, pOp->pObject);
                D2GAME_PLAYERMODE_Change_6FC81A00(pOp->pGame, pOp->pPlayer, pSkill, SKILLS_GetSkillMode(pSkill), UNIT_OBJECT, !pOp->pObject ? -1 : pOp->pObject->dwUnitId, 0);
            }
        }

        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);
        UNITS_FreeCollisionPath(pOp->pObject);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    return 0;
}
struct D2CoordStrc { int nX; int nY; };
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit);                                      // 0x005540D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pPlayer);                          // 0x0055F140
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient);                       // 0x00571740
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
extern const char gszObjModeSourceFile_006E1970[]; // 0x006E1970

// 0x00585F60
int __fastcall sub_00585F60_OperateChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) != 0) return 1;
    DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));
    D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    unsigned int nDropCount = 0;
    const unsigned char nInteractType = pOp->pObject->pObjectData->InteractType;
    if (nInteractType & 0x80) {
        int bOpen = 1;
        if (!pOp->pPlayer || pOp->pPlayer->dwClassId != 6) bOpen = D2GAME_DoKeyCheck_6FC4A4B0(pOp->pGame, pOp->pPlayer);
        if (!bOpen) {
            SUNIT_AttachSound(pOp->pPlayer, 22, pOp->pPlayer);
            return 1;
        }
        SUNIT_AttachSound(pOp->pPlayer, 11, pOp->pPlayer);
        D2GAME_UpdateUnit_6FCC6080(pOp->pPlayer, SUNIT_GetClientFromPlayer(pOp->pPlayer, gszObjModeSourceFile_006E1970, 0x5D4));
        nDropCount = 1;
    }
    ++nDropCount;
    D2CoordStrc coords;
    UNITS_GetCoords(pOp->pObject, &coords);
    int nItemCount = 0;
    int nQuality;
    if (D2GAME_CheckIfSparklyChest_6FCBD7F0(pOp->pObject) & 1) {
        nQuality = (int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) < 5 ? 6 : 4;
        nItemCount = 1;
    } else nQuality = 0;
    if (pOp->pObject && pOp->pObject->dwClassId == 397) {
        nQuality = 0;
        nItemCount = 0;
        const int nRoll = SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000;
        if (nRoll < 200) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 7);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 7);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 600) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 5);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 5);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 1200) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 6);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 6);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 3200) {
            for (int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
                if (pItem) {
                    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nQuality;
                    ++nItemCount;
                }
                if (nQuality >= 3) break;
            }
            if (!nItemCount) goto Default;
            goto Finish;
        } else if (nRoll < 6200) {
            for (int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
                if (pItem) {
                    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nQuality;
                    else ++nItemCount;
                }
                if (nQuality >= 2) break;
            }
            if (!nItemCount) {
                if (OBJMODE_DropFromChestTCWithQuality(pOp, 0)) nItemCount = 1;
            } else if (nItemCount >= 7) goto Finish;
            for (int i = 0; i < 7 - nItemCount; ++i)
                OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, 0x20646C67, 0);
            goto Finish;
        }
    Default:
        for (int i = 0; i < 10; ++i) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
            if (pItem) {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) break;
                ++nItemCount;
            }
        }
        if (nItemCount < 4) {
            for (int i = 0; i < 4 - nItemCount; ++i) OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }
        for (int i = 0; i < 5; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, 0x20646C67, 0);
        for (int i = 0; i < 2; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, 0x20337068, 0);
        for (int i = 0; i < 2; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, 0x2033706D, 0);
    } else if ((int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) >= 25 || nItemCount || nInteractType & 0x80) {
        unsigned int nSuccess = 0;
        for (unsigned int i = 0; i < nDropCount; ++i) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, nQuality);
            if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nSuccess;
        }
        if (nItemCount && !nSuccess) {
            for (unsigned int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, nQuality);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) break;
            }
        }
    }
Finish:
    if (pRecord->nMode[1]) {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    } else UNITS_ChangeAnimMode(pOp->pObject, 2);
    UNIT_ClearFlag(pOp->pObject, 2);
    if (pOp->pObject->dwDropItemCode) {
        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 2, &nItemLevel, 0, -1, 1);
    }
    D2GAME_SetTrapCallback_6FC764B0(nInteractType & ~0x80, pOp);
    return 1;
}
