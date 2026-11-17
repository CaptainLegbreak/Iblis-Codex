struct D2GameStrc;
struct D2ClientStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                           // 0x006289F0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260
int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                          // 0x0056C3F0
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                      // 0x0055F850
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0

static __forceinline unsigned int sub_M401_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005DAA40
static void __stdcall sub_005DAA40_ImpaleWearItem(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemTypeId(pItem, 0x2D))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0 && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
        {
            sub_6FD118C0(pGame, pUnit);
        }
    }
    else if (ITEMS_HasDurability(pItem) && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
    {
        int nNewDurability = STATLIST_UnitGetStatValue(pItem, 0x48, 0) - nAmount;
        if (nNewDurability < 0)
        {
            nNewDurability = 0;
        }

        if (nNewDurability)
        {
            STATLIST_SetUnitStat(pItem, 0x48, nNewDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillAma.cpp", 0x9B), pItem, 1, 0x48, nNewDurability, 0);
        }
        else
        {
            sub_6FC4B580(pGame, pUnit, pItem);
        }
    }
}

int __fastcall sub_M401_Emit_005DAB40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nChance, int nAmount)
{
    D2UnitStrc* pItem = sub_6FC7C7B0(pUnit);
    if (!pItem)
    {
        return 0;
    }

    sub_005DAA40_ImpaleWearItem(pGame, nChance, nAmount + 7, pItem, pUnit);
    return 9;
}
