struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissile;
    short wCltMissileA;
    short wCltMissileB;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xBA0 - 0xB70];
    int nSkillsTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0

// 0x004E3AB0
void __fastcall sub_004E3AB0_CreateStateSkillMissile(D2UnitStrc* pUnit)
{
    if (!pUnit->pDynamicPath || !sub_006505C0_TestPathFlag8(pUnit->pDynamicPath))
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 13);
    if (!pStatList)
    {
        return;
    }

    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nCltMissile = pSkillsTxt->wCltMissile;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = pSkillsTxt->wCltMissile;

    if (pSkillsTxt->wCltMissileA >= 0)
    {
        if (pSkillsTxt->wCltMissileB >= 0)
        {
            switch (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3))
            {
            case 0:
                tMissile.nMissile = pSkillsTxt->wCltMissileA;
                break;

            case 1:
                tMissile.nMissile = pSkillsTxt->wCltMissileB;
                break;
            }
        }
        else if (!SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
        {
            tMissile.nMissile = pSkillsTxt->wCltMissileA;
        }
    }

    sub_004CD540_CreateMissile(&tMissile);
}
