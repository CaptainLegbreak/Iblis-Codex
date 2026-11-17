#define UNIT_MONSTER 1
#define STAT_HITPOINTS 6

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                            // 0x00463990
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __fastcall sub_0047A690(int nUnitGUID, unsigned char nLifePct);                                        // 0x0047A690

// 0x0045F120
void __fastcall sub_0045F120_HandleLifePacket(unsigned char* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(*(int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    if (pUnit == sub_00463DE0_GetStoredUnit())
        return;
    const int bFlag = (pUnit->dwFlags >> 9) & 1;
    if (bFlag)
        return;
    if (pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pPacket[6] << 8, bFlag);
    else
        sub_0047A690(*(int*)(pPacket + 2), pPacket[6] * 100 / 128);
}
