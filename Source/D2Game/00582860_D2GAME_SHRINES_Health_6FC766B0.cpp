struct D2UnitStrc;
struct D2ShrinesTxt;

struct D2ObjOperateFnStrc
{
    char unk0x00[0x08];
    D2UnitStrc* pPlayer;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
};

#define STAT_HITPOINTS 6
#define STAT_MANA 8

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" char* __cdecl _strrev(char* szString);                                                           // 0x00687860

// 0x00582860
void __fastcall D2GAME_SHRINES_Health_6FC766B0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxLifeFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nDiff, 0);
    }
}

// 0x005828A0
void __fastcall D2GAME_SHRINES_FillMana_6FC766F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxManaFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nDiff, 0);
    }
}

// 0x00582A00
void __fastcall D2GAME_SHRINES_Enirhs_6FC76850(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    char* szName = UNITS_GetPlayerData(pOp->pPlayer)->szName;
    if (szName)
    {
        strncpy(szName, _strrev(szName), 16);
    }
}
