struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2DrlgActStrc;

struct D2MonStatsTxt
{
    char unk0x000[0x1A8];
};

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
    char unk0x04[0x18];
    unsigned char nMonUmod[10];
    char unk0x26[0x2];
    unsigned short wClientFlags;
    char unk0x2A[0x2];
    void* wszMonName;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634
extern "C" const char gszMonsterSourceFile_006DA5C8[];                                                       // 0x006DA5C8

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                               // 0x0040B3C0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_00466CB0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00466CB0
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
void __stdcall sub_004ADD90(D2UnitStrc* pUnit, void* pArg, int nMode);                                      // 0x004ADD90
void __fastcall sub_004D2D70_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg);            // 0x004D2D70
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                                // 0x00643A00
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                      // 0x00648460
void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

static D2MonsterDataStrc* CLIENT_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x004AC740
unsigned char* __fastcall sub_004AC740_GetMonsterBytes(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterData(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x004ADE40
void __fastcall sub_004ADE40(D2UnitStrc* pUnit)
{
    sub_004ADD90(pUnit, 0, 0);
}

// 0x004ADE50
void __fastcall sub_004ADE50(D2UnitStrc* pUnit)
{
    sub_004ADD90(pUnit, 0, 1);
}

// 0x004ADE60
void __fastcall sub_004ADE60(D2UnitStrc* pUnit)
{
    sub_004ADD90(pUnit, 0, 2);
}

// 0x004ADE70
void __fastcall sub_004ADE70(D2UnitStrc* pUnit)
{
    sub_004ADD90(pUnit, 0, 3);
}

// 0x004ADE80
void __fastcall sub_004ADE80(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pArg && pUnit->dwUnitType == 1)
    {
        sub_004ADD90(pUnit, pArg, 4);
    }
}

static inline D2MonStatsTxt* CLIENT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004AE0A0
void __fastcall sub_004AE0A0_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wClientFlags = wFlags;
            pMonsterData->pMonstatsTxt = CLIENT_GetMonStatsTxtRecord(pUnit->dwClassId);
        }
    }
}

// 0x004AE3C0
void __fastcall sub_004AE3C0_OwnerMissileHit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (pOwner)
    {
        D2_ASSERT(pOwner->dwUnitType == 3, 353);
        sub_004D2D70_CltMissileHit(pOwner, 0, 0);
    }
}

// 0x004AED30
void __fastcall sub_004AED30_FreeClientUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    sub_0046EC10_FreeGfxData(pUnit);
    sub_00466CB0(pUnit, 1);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;

    if (gpAct_007A0634)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
        sub_00464930_FreeLight(pUnit);
    }

    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;

    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
    {
        sub_004743D0_ReleaseOverlayResource(pResource);
    }

    if (pUnit->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->wszMonName)
        {
            FOG_Free(pMonsterData->wszMonName, gszMonsterSourceFile_006DA5C8, 102, 0);
            pMonsterData->wszMonName = 0;
        }
    }
}
