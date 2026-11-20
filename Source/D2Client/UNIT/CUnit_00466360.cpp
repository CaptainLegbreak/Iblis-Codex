#include "D2Client.h"
#include "D2Constants.h"

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
    union
    {
        D2ObjectDataStrc* pObjectData;
        struct D2MonsterDataLocalStrc* pMonsterData;
    };
    unsigned char nAct;
    char unk0x19[3];
    D2DrlgActStrc* pDrlgAct;
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x54 - 0x30];
    struct D2GfxDataStrc* pGfxData;
    char unk0x58[0x60 - 0x58];
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

struct D2UnitSpawnExtraStrc
{
    int nArg10;
    int nArg14;
};

struct D2UnitSpawnStrc
{
    unsigned int nUnitId;
    int nClassId;
    int nX;
    int nY;
    D2UnitSpawnExtraStrc tExtra;
    int nMode;
};


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
D2UnitStrc* __fastcall sub_00466360_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6); // 0x00466360

struct Unicode;

struct D2MonsterInfo16Strc
{
    unsigned int aValues[4];
};

struct D2MonsterDataLocalStrc
{
    char unk0x00[0x04];
    D2MonsterInfo16Strc tInfo;
};

struct D2MonStatsTxt
{
    char unk0x000[0x06];
    unsigned short wNameStr;
    char unk0x008[0x10];
    short wMonStatsEx;
    char unk0x01A[0x33];
    unsigned char nMode4D;
    char unk0x04E[0x15A];
};

struct D2MonStats2Txt
{
    char unk0x000[0x0E];
    unsigned char nSteps;
    char unk0x00F[0x113];
    unsigned char nModes[3];
    char unk0x125[0x0F];
};

struct D2SuperUniquesTxt
{
    char unk0x00[0x28];
    unsigned char nModes[3];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x04];
    int nMonStats2TxtRecordCount;
};

struct D2ClientEntryStrc
{
    unsigned int dwValue;
    unsigned short wValue;
};

struct D2HirelingInfoStrc
{
    unsigned short wValue;
    char unk0x02[2];
    unsigned int dwValue;
    int unk0x08;
    int unk0x0C;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10
int __fastcall sub_00477620(D2UnitStrc* pUnit, int nArg);                                                   // 0x00477620
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20
int __fastcall sub_00479180_GetPetType(int nUnitId);                                                        // 0x00479180
int __fastcall sub_004791B0_IsOwnedByPlayer(D2UnitStrc* pUnit);                                             // 0x004791B0
unsigned char* __fastcall sub_004AC740_GetMonsterBytes(D2UnitStrc* pUnit);                                  // 0x004AC740
void __fastcall sub_004AC7A0(D2UnitStrc* pUnit, unsigned short wValue);                                     // 0x004AC7A0
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit);                                          // 0x004AC7C0
void __fastcall sub_004AE0A0_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags);                      // 0x004AE0A0
void __fastcall sub_004AE150(D2UnitStrc* pUnit, unsigned int dwValue);                                      // 0x004AE150
int __fastcall sub_004AE360_IsMonsterFlag8(D2UnitStrc* pUnit);                                              // 0x004AE360
void __fastcall sub_004AE8D0(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nMode); // 0x004AE8D0
void __fastcall sub_004B1090_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo);                    // 0x004B1090
void __fastcall sub_004CC380_PlayInitSound(D2UnitStrc* pUnit);                                              // 0x004CC380
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                               // 0x0063ABD0
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);         // 0x0063E810
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0
static D2UnitStrc* __stdcall sub_00463940_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType); // 0x00463940
static void sub_004656C0_ClassEffects(D2UnitStrc* pUnit, int nClassId); // 0x004656C0

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0

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

static D2UnitStrc* __stdcall sub_00463940_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType)
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
    return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x83);
    if (UNIT_HasFlagEx(pUnit, 0x400))
    {
        const int nOwnerType = pUnit->dwOwnerType;
        const unsigned int nOwnerGUID = pUnit->dwOwnerGUID;
        const int nHash = nOwnerGUID & 0x7F;
        if (nOwnerType == 3)
        {
            return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5270[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
        }
        return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5E70[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
    }
    return 0;
}

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

    D2UnitStrc* pNext = ppTable[nHash];
    D2UnitStrc* pPrev = 0;
    while (pNext && pNext->dwUnitId > nUnitId)
    {
        pPrev = pNext;
        pNext = pNext->pListNext;
    }

    pUnit->pListNext = pNext;
    if (pPrev)
    {
        pPrev->pListNext = pUnit;
    }
    else
    {
        ppTable[nHash] = pUnit;
    }

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

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId & 0x7F);
}

void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId & 0x7F);
}

static D2UnitStrc* sub_00465F20_InsertUnit(D2UnitStrc* pUnit); // 0x00465F20

static __declspec(noinline) D2UnitStrc* sub_00465F20_InsertUnit(D2UnitStrc* pUnit)
{
    if (!sub_00463A50_AddUnitToTable(pUnit))
    {
        D2UnitStrc* pOld = sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType);
        D2_ASSERT(pOld != pUnit, 0x1C6);
        if (pOld)
        {
            if (UNIT_HasFlag(pOld, 0x200000))
            {
                sub_00465F00_RemoveServerSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }
            else
            {
                sub_00465EE0_RemoveClientSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }

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

D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    return sub_00465FD0_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, 0, pUnit, nX);
}

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

D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg)
{
    if (++gnPresetUnitId_00711F30 == -1)
    {
        gnPresetUnitId_00711F30 = 0;
    }

    if (nUnitType == 1)
    {
        D2UnitSpawnStrc tSpawn = {};
        tSpawn.nUnitId = gnPresetUnitId_00711F30;
        tSpawn.nClassId = nClassId;
        tSpawn.nX = nX;
        tSpawn.nY = nY;
        tSpawn.nMode = nUnitType;
        return sub_00466360_AddClientMonster(&tSpawn, 0, 0, 0, 0, nUnitType);
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x600000;
    return sub_00465FD0_InitUnit(gnPresetUnitId_00711F30, nClassId, nY, nUnitType, nArg, 0, pUnit, nX);
}

static __declspec(noinline) void sub_004656C0_ClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        sub_00470390(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        sub_00470390(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        sub_00470390(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, -0x37);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            sub_00470390(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        sub_00470390(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

static __forceinline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_A3_GetMonStats2TxtRecord(int nMonStatsEx)
{
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* sub_A3_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

static __forceinline D2MonsterInfo16Strc* sub_F4B0_GetMonsterInfo(D2UnitStrc* pUnit)
{
    D2MonsterDataLocalStrc* pMonsterData = pUnit->dwUnitType == UNIT_MONSTER ? pUnit->pMonsterData : 0;
    return pMonsterData ? &pMonsterData->tInfo : 0;
}

static __forceinline unsigned int sub_F4B0_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00466360
D2UnitStrc* __fastcall sub_00466360_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6)
{
    const unsigned int nUnitId = pSpawn->nUnitId;
    if (nUnitId == sub_00478F20_FindPetIdByOwner(gpPlayerUnit_007A6A70, 7, 1))
    {
        D2UnitStrc* pPet = sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5E70[UNIT_MONSTER * 0x80], nUnitId, nUnitId & 0x7F, UNIT_MONSTER);
        if (pPet)
        {
            sub_0046EC10_FreeGfxData(pPet);
            sub_004DC510_InitGfxData(pPet);
            UNITS_ChangeAnimMode(pPet, pSpawn->nMode);
            return pPet;
        }
    }

    const int nClassId = pSpawn->nClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    D2MonStats2Txt* pMonStats2TxtRecord = 0;
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        pMonStats2TxtRecord = sub_A3_GetMonStats2TxtRecord(sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx);
    }

    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, UNIT_MONSTER);
    D2UnitStrc* pMonster = pUnit;
    if (nArg6 && pUnit)
    {
        pUnit->dwFlags |= 0x600000;
    }

    const int nX = pSpawn->nX;
    const int nY = pSpawn->nY;
    pUnit->dwUnitType = UNIT_MONSTER;
    pUnit->dwClassId = pSpawn->nClassId;
    pUnit->dwUnitId = pSpawn->nUnitId;
    pUnit->pMemoryPool = 0;
    pUnit->dwLastSoundTick = 0;
    D2ActiveRoomStrc* pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
    SEED_InitSeed(&pUnit->pSeed);
    if (pRoom)
    {
        pUnit->dwInitSeed = sub_F4B0_SeedStep(&pRoom->pSeed);
    }

    SEED_InitLowSeed(&pUnit->pSeed, pUnit->dwInitSeed);
    sub_004AE0A0_SetClientFlags(pUnit, 0);
    sub_004AC810_ToggleMonsterFlag(pUnit, (unsigned short)pSpawn->tExtra.nArg10, 1);
    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        sub_004AC7A0(pUnit, nArg5);
    }

    sub_004AE150(pUnit, pSpawn->tExtra.nArg14);
    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr));
    if (pArg3)
    {
        sub_004AC780_SetMonsterWord(pUnit, nArg4);
        unsigned char* pBytes = sub_004AC740_GetMonsterBytes(pUnit);
        pBytes[0] = pArg3[0];
        pBytes[1] = pArg3[1];
        pBytes[2] = pArg3[2];
        pBytes[3] = pArg3[3];
        pBytes[4] = pArg3[4];
        pBytes[5] = pArg3[5];
        pBytes[6] = pArg3[6];
        pBytes[7] = pArg3[7];
        pBytes[8] = pArg3[8];
    }

    if (pArg2)
    {
        D2MonsterInfo16Strc* pInfo = sub_F4B0_GetMonsterInfo(pUnit);
        if (pInfo)
        {
            *pInfo = *(D2MonsterInfo16Strc*)pArg2;
        }
    }

    sub_004AE8D0(pUnit, pRoom, nX, nY, nClassId, pSpawn->nMode);
    PATH_SetStepNum(pUnit->pDynamicPath, pMonStats2TxtRecord->nSteps);
    sub_004DC510_InitGfxData(pUnit);
    sub_004656C0_ClassEffects(pUnit, nClassId);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    if (sub_004AE360_IsMonsterFlag8(pUnit) && !sub_004638A0_CheckMonStats2Flag(nClassId, 15))
    {
        nMode = sub_00477620(pUnit, nArg4);
    }

    D2MonStats2Txt* pModeTxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (pModeTxtRecord && pModeTxtRecord->nModes[sub_0044DCD0_GetDifficulty()])
    {
        nMode = pModeTxtRecord->nModes[sub_0044DCD0_GetDifficulty()];
        if (nMode == 0xFF)
        {
            nMode = !sub_004791B0_IsOwnedByPlayer(pUnit);
        }
    }

    if (sub_004AC7E0_CheckMonTypeFlag(pUnit, 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (pSuperUniquesTxtRecord->nModes[sub_0044DCD0_GetDifficulty()])
        {
            nMode = pSuperUniquesTxtRecord->nModes[sub_0044DCD0_GetDifficulty()];
        }
    }

    if (nMode >= 30)
    {
        nMode = 2;
    }

    sub_0046F1C0(pUnit->pGfxData, nMode);
    sub_0046F220(pUnit->pGfxData, nMode);
    pUnit = sub_00465F20_InsertUnit(pUnit);
    if (sub_00479180_GetPetType(pUnit->dwUnitId) == 7)
    {
        D2ClientEntryStrc* pEntry = sub_00478E40_FindEntry(pUnit->dwUnitId);
        if (pEntry)
        {
            D2HirelingInfoStrc tInfo;
            tInfo.dwValue = pEntry->dwValue;
            tInfo.wValue = pEntry->wValue;
            sub_004B1090_InitHireling(pMonster, &tInfo);
        }
    }

    if (MONSTERS_GetHirelingTypeId(pMonster))
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    sub_004CC380_PlayInitSound(pMonster);
    return pMonster;
}
