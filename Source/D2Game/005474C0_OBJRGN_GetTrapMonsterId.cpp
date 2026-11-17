struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ObjectRegionStrc
{
    char unk0x00[0x1C];
    int nTrapMonsterId;
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
};

struct D2MonRegDataStrc
{
    short nMonHcIdx;
    char unk0x02[0x32];
};

struct D2MonsterRegionStrc
{
    char unk0x00[0x10];
    unsigned char nMonCount;
    char unk0x11[3];
    D2MonRegDataStrc pMonData[13];
};

struct D2GameStrc
{
    char unk0x00[0xF0];
    D2MonsterRegionStrc* pMonReg[1024];
    D2ObjectControlStrc* pObjectControl;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

enum
{
    MONSTER_SKELETON1 = 0,
    MONSTER_ZOMBIE1 = 5,
    MONSTER_MUMMY1 = 96,
    MONSTER_SK_ARCHER1 = 170,
    MONSTER_FLYINGSCIMITAR = 234,
    MONSTER_SKMAGE_POIS1 = 274,
    MONSTER_SKMAGE_COLD1 = 379,
    MONSTER_SKMAGE_FIRE1 = 383,
    MONSTER_SKMAGE_LTNG1 = 387,
    ACT_II = 1,
};

// 0x005474C0
int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);
    D2ObjectRegionStrc* pObjectRegion = pOp->pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nTrapMonsterId < 0 || pObjectRegion->nTrapMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nTrapMonsterIds1[] = { MONSTER_ZOMBIE1 };
        int nTrapMonsterIds2[] = { MONSTER_MUMMY1 };
        int nTrapMonsterIds3[] = { MONSTER_SKELETON1, MONSTER_SK_ARCHER1, MONSTER_SKMAGE_POIS1, MONSTER_SKMAGE_COLD1, MONSTER_SKMAGE_FIRE1, MONSTER_SKMAGE_LTNG1 };

        const int* pTrapMonsterIds = nTrapMonsterIds1;
        if (nAct == ACT_II)
        {
            pTrapMonsterIds = nTrapMonsterIds2;
        }

        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
        pObjectRegion->nTrapMonsterId = MONSTER_FLYINGSCIMITAR;

        for (int j = 0; j < pMonsterRegion->nMonCount; ++j)
        {
            const int nMonsterId = pMonsterRegion->pMonData[j].nMonHcIdx;
            for (int i = 0; i < 1; ++i)
            {
                if (nMonsterId >= pTrapMonsterIds[i] && nMonsterId < pTrapMonsterIds[i] + 5)
                {
                    pObjectRegion->nTrapMonsterId = pTrapMonsterIds[i];
                    return pTrapMonsterIds[i];
                }
            }

            for (int i = 0; i < 6; ++i)
            {
                if (nMonsterId >= nTrapMonsterIds3[i] && nMonsterId < nTrapMonsterIds3[i] + 4)
                {
                    pObjectRegion->nTrapMonsterId = nTrapMonsterIds3[i];
                    return nTrapMonsterIds3[i];
                }
            }
        }
    }

    return pObjectRegion->nTrapMonsterId;
}
