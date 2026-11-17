extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
};
#pragma pack(pop)

struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

#define UNIT_OBJECT 2
#define ITEMTYPE_GEM 20
#define OBJMODE_OPERATING 1
#define OBJMODE_SPECIAL1 3

void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket);               // 0x0053D8D0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);      // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00554D00
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x005825B0
static int sub_005825B0_HasItemOfType(D2UnitStrc* pUnit, int nItemType)
{
    D2_ASSERT(pUnit->pInventory, 1747);
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_CheckItemTypeId(pCheckedItem, nItemType))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00582610
int __fastcall OBJECTS_OperateFunction17_Obelisk(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pOp->pGame, pOp->pPlayer);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOp->pPlayer, ".\\OBJECTS\\ObjMode.cpp", 1772);
    const int nAnimMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;
    if (nAnimMode)
    {
        if (nAnimMode == OBJMODE_SPECIAL1 && pInteractUnit == pOp->pObject)
        {
            SUNIT_ResetInteractInfo(pOp->pPlayer);
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
            return 1;
        }
        return 1;
    }

    if (PLAYER_IsBusy(pOp->pPlayer) == 1)
    {
        return 1;
    }

    if (!sub_005825B0_HasItemOfType(pOp->pPlayer, ITEMTYPE_GEM))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 1;
    }

    SUNIT_SetInteractInfo(pOp->pPlayer, UNIT_OBJECT, !pOp->pObject ? -1 : pOp->pObject->dwUnitId);
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_SPECIAL1);

    D2GSPacketSrv58 packet58;
    packet58.nHeader = 0x58;
    const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    packet58.nUnitId = nUnitId;
    packet58.unk0x05 = 0;
    sub_0053D8D0_SendPacket0x58(pClient, &packet58);
    return 1;
}
