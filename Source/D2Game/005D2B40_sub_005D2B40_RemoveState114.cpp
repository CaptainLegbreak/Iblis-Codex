struct D2UnitStrc;
struct D2StatListStrc;

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0

// 0x005D2B40
static __forceinline void sub_005D2B40_RemoveState114(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x72);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

void __stdcall sub_M121_Emit_005D2B40(D2UnitStrc* pUnit) { sub_005D2B40_RemoveState114(pUnit); }
