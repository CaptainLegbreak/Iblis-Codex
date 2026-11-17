struct D2ActiveRoomStrc;
struct D2InventoryStrc;

struct D2AnimDataRecordStrc
{
    char szAnimDataName[8];
    unsigned int dwFrames;
    int dwAnimSpeed;
    unsigned char pFrameFlags[144];
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0x38];
    short wAnimSpeed;
    unsigned char nActionFrame;
    unsigned char unk0x4F;
    D2AnimDataRecordStrc* pAnimData;
    char unk0x54[8];
    void* pStatListEx;
    D2InventoryStrc* pInventory;
};

struct D2MonStatsTxt
{
    char unk0x00[0x36];
    short nWalkAnimSpeed;
    short nRunAnimSpeed;
    char unk0x3A[0x16E];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit);                                                   // 0x006209D0
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064DE30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory);                            // 0x0063BF90
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem);                                              // 0x00628660

// 0x00620A70
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pUnit, 2129);
    const int nSizeX = UNITS_GetUnitSizeX(pUnit);
    const int nSizeY = UNITS_GetUnitSizeY(pUnit);
    if (nSizeX && nSizeY)
    {
        COLLISION_SetMaskWithSizeXY(pRoom, nX, nY, nSizeX, nSizeY, UNITS_GetCollisionMask(pUnit));
    }
}

// 0x00620D80
void __stdcall sub_00620D80_SetMonsterAnimSpeed(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    switch (pUnit->dwUnitType)
    {
    case 1:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
        }
        if (!pMonStatsTxtRecord)
        {
            pUnit->wAnimSpeed = 0;
            return;
        }
        if (!pUnit->pStatListEx)
        {
            pUnit->wAnimSpeed = pMonStatsTxtRecord->nWalkAnimSpeed;
            return;
        }
        const int nVelocityPercent = STATLIST_UnitGetStatValue(pUnit, 67, 0);
        const short nBaseAnimSpeed = (pUnit->dwAnimMode == 15) ? pMonStatsTxtRecord->nRunAnimSpeed : pMonStatsTxtRecord->nWalkAnimSpeed;
        int nAnimSpeed = nBaseAnimSpeed * nVelocityPercent / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }
        pUnit->wAnimSpeed = nAnimSpeed;
        break;
    }
    }
}

// 0x006218D0
void __stdcall UNITS_SetAnimActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    if (pUnit && pUnit->pAnimData && nFrame < 144)
    {
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// 0x00623C80
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int a2)
{
    if (!UNITS_CanDualWield(pUnit))
    {
        return;
    }
    D2UnitStrc* pWeapon = D2Common_10434(pUnit, a2);
    D2UnitStrc* pPrimaryWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    if (!pWeapon)
    {
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
    }
    else if (pWeapon == pPrimaryWeapon)
    {
        D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pUnit->pInventory);
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
        if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
        }
    }
    else
    {
        if (STATLIST_GetOwner(pWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 1);
        }
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 0);
        }
    }
}

// 0x00623D60
unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 5 || nBodyLoc == 4)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!sub_0062A4E0_TestItem(pRightHandItem))
        {
            pRightHandItem = 0;
        }
        D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (!sub_0062A4E0_TestItem(pLeftHandItem))
        {
            pLeftHandItem = 0;
        }
        if (pRightHandItem && pLeftHandItem && !ITEMS_CheckWeaponIfTwoHanded(pRightHandItem) && !ITEMS_CheckWeaponIfTwoHanded(pLeftHandItem)
            && UNITS_CanDualWield(pUnit) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}
