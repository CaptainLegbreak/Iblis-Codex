struct D2UnitStrc;

extern "C" D2UnitStrc* __fastcall sub_00463990_FindClientUnit(int nUnitId, int nUnitType);                // 0x00463990
extern "C" void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit);                     // 0x004B3790
extern "C" void __fastcall sub_004BA840(int nHandle);                                                      // 0x004BA840
extern "C" int gnNpcSoundActive_007C0DB4;                                                                  // 0x007C0DB4
extern "C" int gnNpcSoundHandle_007C0DB8;                                                                  // 0x007C0DB8

// 0x004B3830
extern "C" void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId)
{
    D2UnitStrc* pUnit = sub_00463990_FindClientUnit(nUnitId, 1);
    if (pUnit)
    {
        sub_004B3790_RemoveInventoryClientUnits(pUnit);
    }
    if (gnNpcSoundActive_007C0DB4)
    {
        sub_004BA840(gnNpcSoundHandle_007C0DB8);
    }
    gnNpcSoundActive_007C0DB4 = 0;
    gnNpcSoundHandle_007C0DB8 = 0;
}
