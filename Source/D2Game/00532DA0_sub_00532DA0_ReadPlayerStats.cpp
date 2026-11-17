struct D2GameStrc;
struct D2UnitStrc;
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc*); // 0x0053FCE0
// 0x00532DA0
int __fastcall sub_00532DA0_ReadPlayerStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pData, int nStatCount, int nUnused, int* pSize)
{
    *pSize = 0;
    if (*(unsigned short*)pData != 0x6667) return 4;
    pData += 2;
    struct { int i; int nPresent; } tLoop;
    tLoop.nPresent = 0;
    tLoop.i = 0;
    if (nStatCount > 0) do
    {
        if (pData[(unsigned int)tLoop.i >> 3] & (1 << (tLoop.i & 7)))
        {
            const int nValue = *(int*)&pData[4 * tLoop.nPresent + 3];
            ++tLoop.nPresent;
            STATLIST_SetUnitStat(pUnit, tLoop.i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, tLoop.i, 0, 0);
        }
        ++tLoop.i;
    } while (tLoop.i < nStatCount);
    const int nSize = tLoop.nPresent * 4 + 5;
    if (ARENA_IsInArenaMode(pGame))
    {
        const int nLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
        const int nMana = STATLIST_GetMaxManaFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 8, nMana, 0);
    }
    const int nStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, 10, nStamina, 0);
    *pSize = nSize;
    return 0;
}
