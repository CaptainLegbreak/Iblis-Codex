struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                    // 0x007A5E70
extern D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                    // 0x007A5270
extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70
extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

// 0x004637F0
unsigned char* __fastcall sub_004637F0_GetMonsterComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

// 0x00463920
static __forceinline D2UnitStrc** sub_00463920_GetClientHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5E70[nUnitType * 0x80];
}

// 0x00463930
static __forceinline D2UnitStrc** sub_00463930_GetServerHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5270[nUnitType * 0x80];
}

// 0x00463C60
static __forceinline void sub_00463C60_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    if (gpGlobal_007A0634)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
}

// 0x00463D70
void __cdecl sub_00463D70_Empty()
{
}

// 0x00463DD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit()
{
    return gpPlayerUnit_007A6A70;
}

D2UnitStrc* __fastcall sub_M109_Emit_00463920(int nUnitType, int nHash)
{
    return sub_00463920_GetClientHashTable(nUnitType)[nHash] ? sub_00463930_GetServerHashTable(nUnitType)[nHash] : 0;
}

void __fastcall sub_M109_Emit_00463C60(D2UnitStrc* pUnit)
{
    sub_00463C60_RemoveUnitFromRoom(pUnit);
}
