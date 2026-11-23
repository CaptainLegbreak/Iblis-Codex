#include "D2Client.h"
#include "D2Structs.h"

struct Sub004BDFD0;
struct Obj004BDFD0;

struct Sub004BDFD0 { unsigned char bUnknown00[0x28]; unsigned int dwMember28; };
struct Obj004BDFD0 { unsigned char bUnknown00[0x14]; Sub004BDFD0* pSub14; };

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

// 0x004BDFD0
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_004BDFD0(Obj004BDFD0* pObj) {
    return &pObj->pSub14->dwMember28;
}

// 0x004BF990
D2UnitStrc* __cdecl sub_004BF990_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        return INVENTORY_GetCursorItem(pPlayer->pInventory);
    }
    return 0;
}
