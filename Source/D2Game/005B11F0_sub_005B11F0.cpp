struct D2ActiveRoomStrc;
struct D2AiControlStrc;
struct D2RoomCoordListStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2GameStrc;

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    unsigned int nTargetDistance;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall AIUTIL_CheckAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag);               // 0x005DD220
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                  // 0x00457490
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY);                    // 0x0061AD30
int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B11F0
int __fastcall sub_005B11F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!AIUTIL_CheckAiControlFlag(pAiTickParam->pAiControl, 0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumberInline(&pUnit->pSeed) % 100) >= 40)
    {
        return 0;
    }

    const int nId = sub_00463860(pUnit);
    const int nBaseId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    int bNoHeal = sub_00457490_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1);
    if (nBaseId == 10 || nBaseId == 345 || nBaseId == 557)
    {
        bNoHeal = 1;
    }

    const int nLifePct = UNITS_GetCurrentLifePercentage(pUnit);
    if (nLifePct >= 30)
    {
        if (bNoHeal)
        {
            return 0;
        }

        if (pAiTickParam->nTargetDistance >= 10)
        {
            return 0;
        }
    }

    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 15)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2RoomCoordListStrc* pCoordList = D2Common_10096(pRoom, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit));
        int nX;
        int nY;
        if (sub_0054DC40_FindSpawnPosition(pGame, pRoom, pCoordList, nBaseId, &nX, &nY, 0))
        {
            D2ActiveRoomStrc* pTargetRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
            if (pTargetRoom && !DUNGEON_IsRoomInTown(pTargetRoom))
            {
                if (nLifePct < 30 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 25 && !STATES_CheckState(pUnit, 52))
                {
                    int nHeal = STATLIST_UnitGetStatValue(pUnit, 12, 0) << 8;
                    const int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
                    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
                    if (nLife + nHeal > nMaxLife)
                    {
                        nHeal = nMaxLife - nLife;
                    }
                    STATLIST_AddUnitStat(pUnit, 6, nHeal, 0);
                }

                AITACTICS_UseSkill(pGame, pUnit, 4, 184, 0, nX, nY);
                return 1;
            }
        }
    }

    return 0;
}
