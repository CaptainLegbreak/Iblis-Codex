struct D2GameStrc;
struct D2UnitStrc
{
    unsigned char unk_00[0x0C];
    unsigned int dwUnitId;
};
struct D2SpawnRequest005B3130Strc
{
    D2GameStrc* pGame;
    void* pRoom;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    unsigned short n24;
};
D2UnitStrc* __fastcall sub_005B2A00_Spawn(D2SpawnRequest005B3130Strc* pRequest); // 0x005B2A00
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

// 0x005B3130
D2UnitStrc* __fastcall sub_005B3130_SpawnOwned(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7)
{
    D2SpawnRequest005B3130Strc tRequest;
    tRequest.n14 = 0;
    tRequest.n0C = a3;
    tRequest.n10 = a4;
    tRequest.pGame = pGame;
    tRequest.pRoom = pRoom;
    tRequest.n08 = 0;
    tRequest.n20 = a5;
    tRequest.n24 = a7;
    tRequest.n18 = a1;
    tRequest.n1C = a2;
    D2UnitStrc* pUnit = sub_005B2A00_Spawn(&tRequest);
    if (pUnit)
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, a6);
    }
    return pUnit;
}
