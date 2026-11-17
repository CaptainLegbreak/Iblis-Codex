struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc {
    int dwUnitType;
    int dwClassId;
    int unk08;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk14[0x4C];
    D2InventoryStrc* pInventory;
};
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc*); // 0x00627D40
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc*,D2UnitStrc*); // 0x0063C180
int __fastcall sub_00560200(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200
int __fastcall sub_005606B0_EquipItem(D2GameStrc*,D2UnitStrc*,int,unsigned char,int,int*); // 0x005606B0
int __fastcall sub_0055E9B0_PlaceInBelt(D2GameStrc*,D2UnitStrc*,int,int,int,int*); // 0x0055E9B0
int __fastcall sub_0055FB10_UpdateCursorItem(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055FB10
int __fastcall sub_00562660(D2GameStrc*,D2UnitStrc*,int,int,int*,int,int,int,int); // 0x00562660
static __forceinline unsigned int GetMode(D2UnitStrc* pUnit) { if (!pUnit) return 0; return pUnit->dwAnimMode; }
static __forceinline int GetId(D2UnitStrc* pUnit) { if (!pUnit) return -1; return pUnit->dwUnitId; }
// 0x00531210
int __fastcall sub_00531210_PlaceLoadedItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem,D2UnitStrc* pSocketItem)
{
    switch (GetMode(pItem))
    {
    case 0:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            if (!sub_00560200(".\\PLAYER\\PlrSave.cpp",319,pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),CLIENTS_GetUnitY(pItem),0,1,0))
                return 12;
            break;
        }
    case 1:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!sub_005606B0_EquipItem(pGame,pPlayer,nId,ITEMS_GetBodyLocation(pItem),1,&nResult))
                return 12;
            break;
        }
    case 2:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!sub_0055E9B0_PlaceInBelt(pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),0,&nResult))
                return 12;
            break;
        }
    case 4:
        UNITS_ChangeAnimMode(pItem,4);
        INVENTORY_SetCursorItem(pPlayer->pInventory,pItem);
        if (!sub_0055FB10_UpdateCursorItem(pGame,pPlayer,pItem))
            return 12;
        break;
    case 6:
        {
            UNITS_ChangeAnimMode(pItem,4);
            if (!pSocketItem) return 12;
            const int nSocketId = pSocketItem->dwUnitId;
            int nResult;
            if (!sub_00562660(pGame,pPlayer,GetId(pItem),nSocketId,&nResult,0,0,0,0))
                return 12;
            break;
        }
    default: return 12;
    }
    return 0;
}
