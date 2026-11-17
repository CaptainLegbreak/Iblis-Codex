struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x08];
    int dwSeqFrame;
    char unk0x3C[0x08];
    int nSeqCurrentFramePrecise;
    char unk0x48[0x7C];
    unsigned int dwFlags;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    char unk0x0F0[0x14C];
};

struct D2MonStats2Txt
{
    unsigned int dwId;
    unsigned char nFlags[4];
};

struct D2MissilesTxt;

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268

int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
int __fastcall sub_004CA060(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x004CA060
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                      // 0x004648F0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
void __fastcall sub_00471EC0(D2UnitStrc* pUnit, int nArg, int nX, int nY, int bPlayer, int nFlags); // 0x00471EC0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder); // 0x004F67C0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780
int __stdcall sub_00621F60(D2UnitStrc* pUnit);                                                              // 0x00621F60
D2UnitStrc* __stdcall sub_00623990_GetWeapon(D2UnitStrc* pUnit, int nArg);                                  // 0x00623990
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall sub_006288A0_GetItemMissile(D2UnitStrc* pItem);                                               // 0x006288A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062BA80(D2UnitStrc* pItem);                                                              // 0x0062BA80
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C5620
void __stdcall sub_004C5620_SetSpeedToTarget(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    int nTargetX;
    int nTargetY;
    if (sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
        if (nDistance < 1)
        {
            nDistance = 1;
        }
        UNITS_SetAnimationSpeed(pMissile, 0xA00 / nDistance);
        MISSILE_SetCurrentFrame(pMissile, nDistance + 2);
        pMissile->nSeqCurrentFramePrecise = 0x200;
    }
}

// 0x004C7E10
int __fastcall sub_004C7E10_FireWeaponMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pItem = sub_00623990_GetWeapon(pUnit, 1);
    if (!pItem)
    {
        return 0;
    }

    sub_0062BA80(pItem);
    if ((pUnit->dwSeqFrame & ~0xFF) >= 0x900)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!sub_0062BA80(pItem) && STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0))
    {
        return 0;
    }

    const int nMissile = sub_006288A0_GetItemMissile(pItem);
    if (nMissile <= 0)
    {
        return 0;
    }

    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x26))
    {
        if (!sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0))
        {
            return 0;
        }
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004C7F50
int __fastcall sub_004C7F50_SpawnPairAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!sub_00621F60(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2CoordStrc tCoord;
    tCoord.nX = UNITS_GetXPosition(pTarget);
    tCoord.nY = CLIENTS_GetUnitY(pTarget);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = D2GAME_GetRoom_6FC52070(pRoom, tCoord.nX, tCoord.nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!COLLISION_GetFreeCoordinates(pRoom, &tCoord, 2, 0x1000, 1))
    {
        return 0;
    }

    if (pTarget->dwUnitType != 1)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[3])
    {
        nMissile = pSkillsTxtRecord->wCltMissileC;
    }
    else if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[2])
    {
        nMissile = pSkillsTxtRecord->wCltMissileB;
    }

    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x2001;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        tMissileParams.nX = tCoord.nX;
        tMissileParams.nY = tCoord.nY;
        sub_004CD540_CreateMissile(&tMissileParams);
        tMissileParams.nMissile = 0x73;
        sub_004CD540_CreateMissile(&tMissileParams);
        return 1;
    }

    return 0;
}

// 0x004C9060
void __fastcall sub_004C9060_DrawRotated(D2UnitStrc* pUnit, int nArg, int bForward)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    const int nDirection = PATH_GetDirection(pPath);
    sub_006488A0_SetDirection(pPath, (bForward ? nDirection + 0x15 : nDirection + 0x2A) % 64);

    int nX;
    int nY;
    if (sub_004F51D0_IsPerspective())
    {
        SCALE_ScalePerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0x60, &nX, &nY, 0);
        nX += sub_0045AFC0();
        nY += sub_0045AFD0_GetMouseYOffset();
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit);
        nY = UNITS_GetClientCoordY(pUnit);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    sub_00471EC0(pUnit, nArg, nX, nY, nUnitType == 0, 0);
    sub_006488A0_SetDirection(pPath, nDirection);
}

// 0x004CA200
int __fastcall sub_004CA200_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5)
{
    if (pArg1 && nArg4)
    {
        return sub_004CA060(pArg1, nArg2, nArg3, nArg4, 0, 0, nArg5);
    }
    return 0;
}

// 0x004CA230
int __fastcall sub_004CA230_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (pArg1 && nArg4 && nArg5)
    {
        return sub_004CA060(pArg1, nArg2, nArg3, 0, nArg4, nArg5, nArg6);
    }
    return 0;
}
