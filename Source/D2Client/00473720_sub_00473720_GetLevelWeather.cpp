struct D2UnitStrc;
struct D2ActiveRoomStrc;

D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId);                                        // 0x0061DBA0
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId);                                         // 0x0061DC20

// 0x00473720
static __forceinline void sub_00473720_GetLevelWeather(int* pRain, int* pMud)
{
    D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
    *pRain = 0;
    *pMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        *pRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        *pMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
}

// build: context sub_M112_Emit_00473720
int __cdecl sub_M112_Emit_00473720()
{
    int nRain;
    int nMud;
    sub_00473720_GetLevelWeather(&nRain, &nMud);
    return nRain + nMud;
}

// 0x00473CA0
void __cdecl sub_00473CA0_Empty()
{
}

// 0x00473CB0
void __cdecl sub_00473CB0_Nop()
{
}

// 0x00473CC0
void __cdecl sub_00473CC0_Nop()
{
}

// 0x00473CD0
void __cdecl sub_00473CD0_Nop()
{
}
