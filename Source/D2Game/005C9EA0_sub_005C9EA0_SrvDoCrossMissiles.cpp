struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
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
    int unk0x38[7];
    void (__fastcall* pInitFunc)(D2UnitStrc* pMissile, int nInitArg);
    int nInitArg;
};

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};

struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissileA;
    short wSrvMissileB;
    char unk0x04C[0x23C - 0x4C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);                          // 0x0056E450
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    return pRecord;
}

// 0x005C9EA0
int __fastcall sub_005C9EA0_SrvDoCrossMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !sub_6FD15340(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nX = 0;
    int nY = 0;
    if (pTarget)
    {
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
        nX = nTargetX;
    }
    else
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    }

    if (!nX || !nY)
    {
        return 0;
    }

    D2ActiveRoomStrc* const tArg1 = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(tArg1, nX, nY);
    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    const int nDiffX = CLIENTS_GetUnitX(pUnit) - nX;
    const int nDiffY = CLIENTS_GetUnitY(pUnit) - nY;

    missileParams.nTargetX = nX - nDiffY;
    missileParams.nTargetY = nY + nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    missileParams.nTargetX = nX + nDiffY;
    missileParams.nTargetY = nY - nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    const int nMissileB = pSkillsTxtRecord->wSrvMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        missileParams.nTargetX = 0;
        missileParams.nTargetY = 0;
        missileParams.nMissile = nMissileB;
        missileParams.dwFlags = 1;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}
