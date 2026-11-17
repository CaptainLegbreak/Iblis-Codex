struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillListStrc;
struct D2GfxLightStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc tSeed;
    unsigned int dwInitSeed;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    D2GfxLightStrc* pLight;
    char unk0x68[0x40];
    D2SkillListStrc* pSkills;
    char unk0xAC[0x18];
    unsigned int dwFlags;
};

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

extern int gnInTown_007A5260;                                                                               // 0x007A5260

void __fastcall sub_004609F0_OnStatChanged(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x004609F0
void __cdecl sub_004608C0();                                                                                // 0x004608C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00464CF0(D2UnitStrc* pUnit, int nRadius);                                // 0x00464CF0
void __fastcall sub_0046C6E0_AddToUnitSlots(D2UnitStrc* pUnit);                                             // 0x0046C6E0
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight);                                           // 0x00474350
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall sub_0061AB30(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AB30
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit);                                                   // 0x00621F90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool);                                          // 0x006438B0
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit);                                                    // 0x00647EE0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);               // 0x006488A0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);        // 0x00648C30
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                     // 0x00649190
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                         // 0x00649560
void __stdcall sub_00649D00(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00

// 0x00460BF0
void __fastcall sub_00460BF0_InitClientPlayer(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    sub_0046C6E0_AddToUnitSlots(pUnit);
    sub_00649D00(0, pRoom, nX, nY, pUnit, 1);
    if (!pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    pUnit->pSkills = SKILLS_AllocSkillList(0);
    SKILLS_InitSkillList(pUnit);
    STATLIST_AllocStatListEx(pUnit, 0, sub_004609F0_OnStatChanged, 0);
    STATLIST_SetUnitStat(pUnit, 0x44, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x43, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x45, 100, 0);
    gnInTown_007A5260 = DUNGEON_IsRoomInTown(pRoom);
    UNITS_ChangeAnimMode(pUnit, 5);
    pUnit->dwFlags &= ~0x20;
    pUnit->dwFlags |= 0xE;
    if (pUnit->dwAnimMode == 0x11 || pUnit->dwAnimMode == 0)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x8000);
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!sub_0061AB30(pRoom))
    {
        D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, pPlayer && pUnit != pPlayer, 0xD, 0xFF, 0xFF, 0xFF, 0xFF);
        if (pLight)
        {
            pUnit->pLight = pLight;
            sub_00464CF0(pUnit, sub_00474350_GetLightSize(pLight));
        }
    }

    UNITS_AllocPlayerData(pUnit);
    if (pUnit != pPlayer)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2SeedStrc* pSeed = &pUnit->tSeed;
        unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nLowSeed = (unsigned int)lSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        PATH_SetDirection(pPath, (unsigned int)lSeed & 0x3F);
    }

    sub_004608C0();
}
