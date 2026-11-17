#ifdef MOVED_TEST
#define UNIT_FLAG 0x20
#else
#define UNIT_FLAG 0x40
#endif
struct D2DynamicPathStrc;
struct D2GameStrc;
struct D2MissilesTxt;
struct D2MonsterDataStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;
struct D2UnitStrc
{
#ifdef MOVED_TEST
    int movedPrefix;
#endif
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x04];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x0C];
    unsigned int dwSeqSpeed;
    char unk0x40[0x0E];
    unsigned char nActionFrame;
    char unk0x4F[0x75];
    unsigned int dwFlags;
};
struct D2SkillsTxt
{
#ifdef MOVED_TEST
    int movedPrefix[2];
#endif
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x3C];
    short wSrvMissileA;
    short wSrvMissileB;
    char unk0x04C[0x02];
    short wSrvOverlay;
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    short wAuraTargetState;
    short wAuraEvent[3];
    short wAuraEventFunc[3];
    char unk0x090[0x08];
    short nPassiveStat[5];
    char unk0x0A2[0x02];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x2E];
    short wSumOverlay;
    char unk0x0E8[0x28];
    short wCltOverlayA;
    char unk0x112[0x1C];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    int dwParam[4];
    char unk0x158[0x4D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};
struct D2DataTablesStrc
{
#ifdef MOVED_TEST
    int movedPrefix;
#endif
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0x10];
    int nItemStatCostTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);                          // 0x0056E450
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}
// 0x005CA3E0
int __fastcall sub_005CA3E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    if (!sub_6FD15340(pGame, pUnit, nMissileId))
        return 0;
    return D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0) != 0;
}
