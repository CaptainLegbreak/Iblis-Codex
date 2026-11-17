#include "D2Client.h"

struct D2LightStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char nInteractType;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    unsigned char nAct;
    char unk0x19[3];
    D2DrlgActStrc* pDrlgAct;
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x60 - 0x30];
    D2InventoryStrc* pInventory;
    D2LightStrc* pLight;
    char unk0x68[0x94 - 0x68];
    int dwOwnerType;
    unsigned int dwOwnerGUID;
    char unk0x9C[0xA4 - 0x9C];
    void* pHoverText;
    char unk0xA8[0xC4 - 0xA8];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
    char unk0xCC[0xD4 - 0xCC];
    unsigned int dwLastSoundTick;
    char unk0xD8[0xE4 - 0xD8];
    D2UnitStrc* pListNext;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                    // 0x007A5270
extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                    // 0x007A5E70
extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70
extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634

void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight);                                   // 0x004743D0
D2LightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                         // 0x00643A00
void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit);                                               // 0x004DA080
void __fastcall sub_004CA9C0_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce);                               // 0x004CA9C0
void __fastcall sub_004AED30_FreeClientUnit(D2UnitStrc* pUnit);                                             // 0x004AED30
void __fastcall sub_004C1A70_ReleaseItemUnit(D2UnitStrc* pUnit);                                            // 0x004C1A70
void __fastcall sub_004BCA50_ReleaseUnit(D2UnitStrc* pUnit);                                                // 0x004BCA50
void __fastcall sub_004CD170_FreeMissileUnit(D2UnitStrc* pMissile);                                         // 0x004CD170
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __fastcall sub_004DC0C0_FreeCltUnitEvents(D2UnitStrc* pUnit);                                          // 0x004DC0C0
void __fastcall sub_0045F9F0_FreePacketBuffer(void* pArg);                                                  // 0x0045F9F0
void __cdecl sub_00453DE0();                                                                                // 0x00453DE0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0
void __fastcall sub_0044BEA0_SetValue(int nValue);                                                          // 0x0044BEA0
void __cdecl sub_00453D90_RunSequenceA();                                                                   // 0x00453D90
void __fastcall sub_004879D0(D2UnitStrc* pUnit);                                                            // 0x004879D0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp);  // 0x004C0EC0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomBySubtile(int nX, int nY);                                // 0x00465420
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall sub_004CD0A0(D2UnitStrc* pMissile, D2ActiveRoomStrc* pRoom, int nTargetX, int nTargetY, int nUnused); // 0x004CD0A0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350
void __fastcall sub_004DC510_InitGfxData(D2UnitStrc* pUnit);                                                // 0x004DC510
void __fastcall sub_004BC8D0_UpdateObjectOverlay(D2UnitStrc* pUnit);                                        // 0x004BC8D0

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

static __forceinline int CUNIT_GetUnitClassId(D2UnitStrc* pUnit)
{
    return pUnit->dwClassId;
}

static D2UnitStrc* __stdcall sub_00463940_FindUnitInTable(int nHash, unsigned int nUnitId, D2UnitStrc** ppTable, int nUnitType)
{
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
    }
    return 0;
}

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType)
{
    return sub_00463940_FindUnitInTable(nUnitId & 0x7F, nUnitId, &gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitType);
}

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    return sub_00463940_FindUnitInTable(nUnitId & 0x7F, nUnitId, &gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitType);
}

// build: context sub_004639D0_GetOwnerUnit
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x83);
    if (UNIT_HasFlagEx(pUnit, 0x400))
    {
        const int nOwnerType = pUnit->dwOwnerType;
        const unsigned int nOwnerGUID = pUnit->dwOwnerGUID;
        if (nOwnerType == 3)
        {
            return sub_004639B0_FindServerSideUnit(nOwnerGUID, nOwnerType);
        }
        return sub_00463990(nOwnerGUID, nOwnerType);
    }
    return 0;
}

// build: context sub_00463A50_AddUnitToTable
static __declspec(noinline) int sub_00463A50_AddUnitToTable(D2UnitStrc* pUnit)
{
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        if (sub_004639B0_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!sub_004639B0_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0x9C);
    }
    else
    {
        if (sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType), 0xA5);
    }

    sub_004CC160(pUnit, 1);

    const unsigned int nUnitId = pUnit->dwUnitId;
    const int nHash = nUnitId & 0x7F;
    D2UnitStrc** ppTable;
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        ppTable = &gpUnitHashTable_007A5270[pUnit->dwUnitType * 0x80];
    }
    else
    {
        ppTable = &gpUnitHashTable_007A5E70[pUnit->dwUnitType * 0x80];
    }

    D2UnitStrc* pPrev = 0;
    D2UnitStrc* pNext = ppTable[nHash];
    while (pNext && pNext->dwUnitId > nUnitId)
    {
        pPrev = pNext;
        pNext = pNext->pListNext;
    }

    pUnit->pListNext = pNext;
    if (pPrev)
    {
        pPrev->pListNext = pUnit;
        return 1;
    }

    ppTable[nHash] = pUnit;
    return 1;
}

void __fastcall sub_00463D90_SetPlayerUnit(D2UnitStrc* pUnit)
{
    if (gpPlayerUnit_007A6A70)
    {
        sub_00453DE0();
    }

    if (pUnit)
    {
        sub_006488A0_SetDirection(pUnit->pDynamicPath, 0);
        gnCharClass_007A0522 = (unsigned char)CUNIT_GetUnitClassId(pUnit);
        sub_0044BEA0_SetValue(0);
        sub_00453D90_RunSequenceA();
    }

    gpPlayerUnit_007A6A70 = pUnit;
}

void __fastcall sub_004643F0_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, sub_00463990(nUnitId, nUnitType));
}

// 0x00464D20
static int __stdcall sub_00464D20_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (pOwner == pUnit)
    {
        return 0;
    }

    if (pUnit->pInventory)
    {
        for (D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pUnit->pInventory); pEntry; pEntry = INVENTORY_GetNextItem(pEntry))
        {
            D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pEntry);
            D2_ASSERT(pInvItem, 0xA5B);
            if (pInvItem == pItem)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00464D90
static int __stdcall sub_00464D90_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem)
{
    D2UnitStrc** ppTable = gpUnitHashTable_007A5E70;
    for (int nTable = 0; nTable < 2; ++nTable)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
            {
                if (sub_00464D20_IsItemInInventory(pOwner, pItem, pUnit))
                {
                    return 1;
                }
            }
        }
        ppTable = &gpUnitHashTable_007A5E70[0x80];
    }
    return 0;
}

// 0x00465870
static void sub_00465870_FreeUnit(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }

    D2LightStrc* pRoomLight = D2Common_10958(pUnit, 0);
    if (pRoomLight)
    {
        sub_004743D0_ReleaseOverlayResource(pRoomLight);
    }

    sub_004DA080_FreeGfxMotion(pUnit);
    sub_004CA9C0_ReleaseUnitHints(pUnit, 0);
    sub_004CC160(pUnit, -1);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_00460D50_FreePlayerUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MONSTER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_004AED30_FreeClientUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_ITEM:
        sub_004C1A70_ReleaseItemUnit(pUnit);
        ITEMS_FreeItemData(0, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_OBJECT:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_004BCA50_ReleaseUnit(pUnit);
        UNITS_FreeStaticPath(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MISSILE:
        sub_004CD170_FreeMissileUnit(pUnit);
        break;

    case UNIT_TILE:
        if (gpAct_007A0634)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    sub_004DC0C0_FreeCltUnitEvents(pUnit);
    sub_0045F9F0_FreePacketBuffer(pUnit);

    if (pUnit == gpPlayerUnit_007A6A70)
    {
        sub_00463D90_SetPlayerUnit(0);
    }

    UNITS_FreeUnit(pUnit);
}

// 0x004659C0
void __cdecl sub_004659C0_FreeAllUnits()
{
    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                sub_00465870_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }

    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                sub_00465870_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }
}

// 0x00465E80
static void sub_00465E80_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash)
{
    D2UnitStrc* pPrev = 0;
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId && pUnit->dwUnitType == nUnitType)
        {
            if (!pPrev)
            {
                ppTable[nHash] = pUnit->pListNext;
            }
            else
            {
                pPrev->pListNext = pUnit->pListNext;
            }

            if (pUnit->dwUnitType == 4)
            {
                sub_004879D0(pUnit);
            }

            sub_00465870_FreeUnit(pUnit);
            return;
        }
        pPrev = pUnit;
    }
}

// 0x00465EE0
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId & 0x7F);
}

// 0x00465F00
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId & 0x7F);
}

static __declspec(noinline) D2UnitStrc* sub_00465F20_InsertUnit(D2UnitStrc* pUnit)
{
    if (!sub_00463A50_AddUnitToTable(pUnit))
    {
        D2UnitStrc* pOld = sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType);
        D2_ASSERT(pOld != pUnit, 0x1C6);
        if (pOld)
        {
            const int bServer = UNIT_HasFlag(pOld, 0x200000);
            const int nType = pOld->dwUnitType;
            const unsigned int nId = pOld->dwUnitId;
            D2UnitStrc** ppTable;
            if (bServer)
            {
                ppTable = &gpUnitHashTable_007A5270[nType * 0x80];
            }
            else
            {
                ppTable = &gpUnitHashTable_007A5E70[nType * 0x80];
            }
            sub_00465E80_RemoveUnitFromTable(nId, nType, ppTable, nId & 0x7F);

            if (sub_00463A50_AddUnitToTable(pUnit))
            {
                return pUnit;
            }
        }

        sub_00465870_FreeUnit(pUnit);
        pUnit = 0;
    }

    return pUnit;
}

// 0x00466CB0
void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner)
{
    D2_ASSERT(pUnit, 0xA80);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pInventory);
    while (pEntry)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pEntry);
        D2UnitStrc* pItem = sub_00463990(INVENTORY_GetItemGUID(pEntry), 4);
        if (pItem)
        {
            int bRemove = 1;
            if (bCheckOwner)
            {
                bRemove = !sub_00464D90_IsItemOwnedByOther(pUnit, pItem);
            }

            if (bRemove)
            {
                sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA92);
                sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }
            else
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA96);
            }
        }
        pEntry = pNext;
    }
}

// 0x00465FD0
static D2UnitStrc* __stdcall sub_00465FD0_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX)
{
    const int bFlag = sub_0044DCC0();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwLastSoundTick = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom = 0;
    if (nX || nY)
    {
        pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (nUnitType == 4)
    {
        ITEMS_AllocItemData(0, pUnit);
        ITEMS_InitItemSeed(pUnit);
    }

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    switch (nUnitType)
    {
    case 0:
        sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
        break;

    case 1:
        D2_ASSERT(0, 0x202);
        break;

    case 2:
        UNITS_AllocStaticPath(pUnit);
        sub_004BC720_InitObjectUnit(pUnit, pRoom, nX, nY, nClassId, nArg6);
        break;

    case 4:
        UNITS_AllocStaticPath(pUnit);
        sub_004C1910_InitItemUnit(pUnit, pRoom, nX, nY, nArg5, 1);
        break;

    case 3:
        sub_004CD0A0(pUnit, pRoom, nX, nY, nClassId);
        break;

    case 5:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= 0x22;
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }

    if (nUnitType != 5)
    {
        sub_004DC510_InitGfxData(pUnit);
        if (nUnitType == 0 || nUnitType == 1)
        {
            UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);
        }
    }

    pUnit = sub_00465F20_InsertUnit(pUnit);
    if (pUnit && nUnitType == 2)
    {
        sub_004BC8D0_UpdateObjectOverlay(pUnit);
    }

    return pUnit;
}

// 0x00466200
D2UnitStrc* __fastcall sub_00466200_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, 0);
    if (!pUnit)
    {
        return 0;
    }

    const int bFlag = sub_0044DCC0();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwClassId = nClassId;
    pUnit->dwUnitType = 0;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwLastSoundTick = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom;
    if (nX || nY)
    {
        pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }
    else
    {
        pRoom = 0;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
    sub_004DC510_InitGfxData(pUnit);
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);

    pUnit = sub_00465F20_InsertUnit(pUnit);
    if (pUnit)
    {
        UNITS_SetNameInPlayerData(pUnit, szName);
    }

    return pUnit;
}

// 0x004661C0
D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    return sub_00465FD0_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, 0, pUnit, nX);
}

// 0x00466300
D2UnitStrc* __fastcall sub_00466300_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit = sub_00465FD0_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, nArg6, pUnit, nX);
    if (pUnit)
    {
        pUnit->pObjectData->nInteractType = nInteractType;
        if (UNITS_IsShrine(pUnit))
        {
            sub_004BD6B0_InitShrine(pUnit);
        }
    }

    return pUnit;
}

#include "gen/data/Source/D2Client/UNIT/CUnit_00464D20.inc"
