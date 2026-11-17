extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00462EE0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
void __fastcall sub_0046F280(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                      // 0x00649190
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);                       // 0x006488A0

void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);               // 0x00627260
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10

void __fastcall sub_004AC780_SetMonsterWord(D2UnitStrc* pUnit, unsigned short nValue);                      // 0x004AC780
unsigned char* __fastcall sub_004AC740_GetMonsterBytes(D2UnitStrc* pUnit);                                  // 0x004AC740
void __fastcall sub_004AC810_ToggleMonsterFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet);          // 0x004AC810
void __fastcall sub_004AD020_RefreshMonster(D2UnitStrc* pUnit);                                             // 0x004AD020

// 0x0045D010
void __fastcall sub_0045D010_UnitPacket6D(D2UnitStrc* pUnit, const unsigned char* p)
{
    if (!pUnit)
        return;
    if (!p)
        return;

    const unsigned short nX = *(const unsigned short*)(p + 5);
    const unsigned short nY = *(const unsigned short*)(p + 7);
    int args[7] = { nX, nY, p[9], 2, 0, 4, 0 };
    sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_00480C10_UnitEvent(7, pUnit, args, 1);
}

// 0x0045E400
void __fastcall sub_0045E400_Packet57(const unsigned char* p)
{
    const int nId = *(const int*)(p + 1);
    const unsigned short n6 = *(const unsigned short*)(p + 6);
    const unsigned short n8 = *(const unsigned short*)(p + 8);
    const unsigned short nA = *(const unsigned short*)(p + 0xA);
    const unsigned short nC = *(const unsigned short*)(p + 0xC);
    if (p[5] == 1)
    {
        D2UnitStrc* pUnit = sub_00463990(nId, 1);
        if (pUnit)
        {
            sub_004AC780_SetMonsterWord(pUnit, n6);
            unsigned char* pBytes = sub_004AC740_GetMonsterBytes(pUnit);
            pBytes[0] = (unsigned char)n8;
            pBytes[1] = (unsigned char)(n8 >> 8);
            pBytes[2] = (unsigned char)nA;
            if (nC)
            {
                sub_004AC810_ToggleMonsterFlag(pUnit, 4, 1);
            }
            sub_004AC810_ToggleMonsterFlag(pUnit, 8, 1);
            sub_004AD020_RefreshMonster(pUnit);
        }
    }
}

// 0x00462F60
void __fastcall sub_00462F60_UnitDropItems(D2UnitDropItemsPacketStrc* pPacket)
{
    if (!pPacket->bActive)
        return;
    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->nUnitId, 0);
    if (!pUnit)
        return;
    if (!sub_00464820_IsDeadOrDying(pUnit))
        sub_00480E70_SetState(pUnit, 0);
    if (pUnit == sub_00463DD0())
    {
        D2UnitStrc* pOther = sub_00463990(*(int*)pPacket->nOtherUnitId, 0);
        if (!pOther)
            return;
        D2DynamicPathStrc* pPath = pOther->pDynamicPath;
        PATH_SetMoveTestCollisionMask(pPath, 0);
        sub_00649190_SetPathMode(pOther, 5);
        D2_ASSERT(sub_00650BE0_PlaceUnit(pPath, pOther, UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit)), 0xABA);
        PATH_SetDirection(pOther->pDynamicPath, PATH_GetDirection(pUnit->pDynamicPath));
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            pItem = INVENTORY_UnitIsItem(pItem);
            sub_0063D2B0_DetachItem(pInventory, pItem);
            sub_0046F280(pUnit, sub_00462EE0_GetItemComponent(pUnit, pItem));
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xAC8);
            D2_ASSERT(pRemoved == pItem, 0xAC9);
            sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
            sub_0063BE30(pInventory, ITEMS_GetBodyLocation(pItem));
            sub_00470610_Refresh(pUnit, 0);
            const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
            const int nUnitId = !pItem ? -1 : pItem->dwUnitId;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
        pItem = pNext;
    }
}
