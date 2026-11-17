struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2ItemDropStrc;
struct D2CombatStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x7C];
    D2CombatStrc* pCombat;
    char unk0xB0[0x8];
    unsigned int dwDropItemCode;
    char unk0xBC[0x8];
    unsigned int dwFlags;
};

struct D2DamageStrc;

struct D2CombatStrc
{
    D2GameStrc* pGame;
    unsigned int dwAttackerType;
    int dwAttackerId;
    unsigned int dwDefenderType;
    int dwDefenderId;
    char tDamage[0x70];
    D2CombatStrc* pNext;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2ObjectControlStrc;

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2ShrinesTxt;

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0xF8[0x75];
    unsigned char nMonsterOK;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                        // 0x0062B400
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID);                                         // 0x00629ED0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
void __fastcall sub_6FCBC4D0(D2UnitStrc* pUnit);                                                            // 0x005533D0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);           // 0x00553990
void __fastcall sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005539B0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __fastcall sub_6FD12FD0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0056FAF0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest);                // 0x005540A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __fastcall sub_0056E970(D2CurseStrc* pCurse);                                                          // 0x0056E970
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit);                                                            // 0x0056DE40
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                          // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x005594C0
D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x00559630
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define ITEMTYPE_GOLD 4
#define ITEMQUAL_NORMAL 2
#define STAT_STAMINA 10
#define OBJECT_TOWN_PORTAL 59
#define OBJECT_FIRE_SMALL 160
#define OBJECT_FIRE_LARGE 162
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_QUESTFN 7
#define UNITFLAG_TARGETABLE 0x00000002
#define UNITFLAG_SKSRVDOFUNC 0x00000040
#define GOLD_PILE_COUNT 32

// 0x0057C980
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1897, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057C9F0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1951, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057E240
void __fastcall SUNITDMG_RollDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage)
{
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, pDamage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
}

// 0x0057E350
int __fastcall sub_0057E350_ApplyExpRatio(int nValue, int nRatio, int nShift)
{
    if (nShift > 0 && nShift < 32)
    {
        if (nValue > (0x7FFFFFFF >> (nShift + (nRatio >> nShift))))
        {
            return (nValue >> nShift) * nRatio;
        }

        return nValue * nRatio >> nShift;
    }

    return nValue;
}

// 0x0057F390
void __fastcall sub_0057F390_DropCorpseGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody, int nGold, int nUnused)
{
    if (nGold > 0)
    {
        D2UnitStrc* pGoldPiles[GOLD_PILE_COUNT];
        int nCount = 0;
        sub_0055A090_DropGoldPiles(pGame, pDeadBody, nGold, pGoldPiles, &nCount, GOLD_PILE_COUNT);

        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pGold = pGoldPiles[i];
            D2_ASSERT(ITEMS_GetItemType(pGold) == ITEMTYPE_GOLD, 588);
            ITEMS_SetOwnerId(pGold, sub_00451F50_GetUnitGUID(pPlayer));
        }
    }
}

// 0x0057FDC0
void __fastcall PLRMODE_StartXY_Block(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pPlayer, 1095);

    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    sub_6FCBC4D0(pPlayer);
    UNITS_SetUsedSkill(pPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
}

// 0x0057FE30
void __fastcall PLRMODE_StartXY_GetHit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pPlayer, 1136);

    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    sub_6FCBC4D0(pPlayer);
    UNITS_SetUsedSkill(pPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
}

// 0x0057FE90
void __fastcall PLRMODE_StartXY_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
    pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    sub_6FD12FD0(pGame, pPlayer);
}

// 0x0057FEF0
void __fastcall PLRMODE_StartID_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTarget)
{
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);

    D2_ASSERT(pTarget, 1215);

    UNITS_SetTargetUnitForDynamicUnit(pPlayer, pTarget);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);

    if (pPlayer)
    {
        pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    }

    sub_6FD12FD0(pGame, pPlayer);
}

// 0x00582380
void __fastcall D2GAME_OBJECTS_TrapHandler5_7_6FC75BC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pFireLarge = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_LARGE, pCoord.nX, pCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pFireLarge)
    {
        D2GAME_SetSparkChest_6FCBD7C0(pFireLarge, 2);
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    const int nX = pCoord.nX + 1;
    if (nX >= drlgCoords.nSubtileX && nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        D2UnitStrc* pFireSmall = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_SMALL, nX, pCoord.nY, pGame, UNITS_GetRoom(pUnit), 1, 1, 0);
        D2GAME_SetSparkChest_6FCBD7C0(pFireSmall, 2);
    }
}

// 0x00582800
void __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback)
{
    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 0;
    curse.pTarget = pTarget;
    curse.nDuration = nDuration;
    curse.nStat = nStat;
    curse.nStatValue = nStatValue;
    curse.nState = nState;
    curse.pStateRemoveCallback = pStateRemoveCallback;
    sub_0056E970(&curse);
}

// 0x00582A30
void __fastcall D2GAME_SHRINES_Portal_6FC76880(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pPlayer);

    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->pPlayer, &pCoord);

    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    const int nTownId = DUNGEON_GetTownLevelIdFromActNo(nAct);

    if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pOp->pPlayer), &pCoord, 3, 0x1C09, 0))
    {
        D2GAME_CreatePortalObject_6FD13DF0(pOp->pGame, pOp->pPlayer, pRoom, pCoord.nX + 5, pCoord.nY + 5, nTownId, 0, OBJECT_TOWN_PORTAL, 0);
    }
}

// 0x00583A40
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
}

// 0x00583BD0
void __fastcall sub_6FC77C10(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    sub_6FD14C30(pUnit);
}

// 0x00583E70
int __fastcall OBJECTS_OperateFunction33_WirtsBody(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        pOp->pObject->dwDropItemCode = ' gel';

        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 10, 0, 0);
        }
    }

    return 1;
}

// 0x00584160
int __fastcall OBJECTS_OperateFunction19_ArmorStand(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);
        D2GAME_DropArmor_6FC4F830(pOp->pGame, UNITS_GetRoom(pOp->pObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005841D0
int __fastcall OBJECTS_OperateFunction20_WeaponRack(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);
        D2GAME_DropWeapon_6FC4FA50(pOp->pGame, UNITS_GetRoom(pOp->pObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x00584540
int __fastcall sub_6FC78B20(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    if (!pObject)
    {
        return 0;
    }

    const int nClassId = pObject->dwClassId;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && !DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
        {
            return 1;
        }

        if (!UNITS_IsObjectInInteractRange(pUnit, pObject))
        {
            return 1;
        }
    }

    int nResult = 1;
    OBJECTS_OperateHandler(pGame, pUnit, nObjectType, nObjectGUID, &nResult);
    return nResult;
}
