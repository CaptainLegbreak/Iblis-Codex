struct D2SkillStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_INTOWN = 8,
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    char unk0x0C[0x58];
    unsigned int dwAuraRangeCalc;
    char unk0x68[0x23C - 0x68];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __fastcall sub_004C7950(D2UnitStrc* pUnit);                                                            // 0x004C7950
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

__forceinline int UNITS_GetXInline(D2UnitStrc* pUnit)
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

__forceinline int UNITS_GetYInline(D2UnitStrc* pUnit)
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

static int __stdcall sub_004C8350_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY);           // 0x004C8350
static int __stdcall sub_004C80D0_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY); // 0x004C80D0

static int __stdcall sub_004C8350_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    D2ActiveRoomStrc* pTarget = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pTarget)
        return 0;
    if (!(pSkillsTxt->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pTarget))
        return 0;
    return 1;
}

static int __stdcall sub_004C80D0_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    if (!sub_004C52E0_GetTargetPosition((D2UnitStrc*)&pUnit, &nSkillLevel, (int*)&pX))
        return 0;
    return sub_004C52E0_GetTargetPosition((D2UnitStrc*)pSkillsTxt, (int*)&pY, (int*)&pUnit);
}

// 0x004C83C0
int __fastcall sub_004C83C0_SkillCltStartPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (STATES_CheckState(pUnit, 0x36))
            return 0;
        if (SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillsBar.cpp", 442) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
            return 0;
    }

    const int bMonster = (!pUnit ? 6 : pUnit->dwUnitType) == 1;
    int nX;
    int nY;
    if (bMonster)
    {
        D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
        if (!pTarget)
        {
            if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
                return 0;
            SKILLS_SetParam4(pSkill, -1);
        }
        else
        {
            nX = CLIENTS_GetUnitX(pTarget);
            nY = CLIENTS_GetUnitY(pTarget);
            nX = 2 * nX - CLIENTS_GetUnitX(pUnit);
            nY = 2 * nY - CLIENTS_GetUnitY(pUnit);
        }

        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
            return 0;
        nX = tCoord.nX;
        nY = tCoord.nY;
    }
    else
    {
        if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
            return 0;
        if (!sub_004C8350_CanTargetRoom(nSkillId, pUnit, nX, nY))
            return 0;
        if (!sub_004C80D0_AdjustTargetPosition(nSkillId, pUnit, nSkillLevel, &nX, &nY))
            return 0;
    }

    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    if (bMonster)
    {
        D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }
    SKILLS_SetFlags(pSkill, 0x1080);
    sub_004C7950(pUnit);
    return 1;
}
