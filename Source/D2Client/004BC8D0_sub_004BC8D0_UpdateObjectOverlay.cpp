struct D2InventoryStrc;
struct D2ActiveRoomStrc;

struct D2ObjectsTxt
{
    char unk0x000[0x1B4];
    unsigned char nClientFn;
    unsigned char nOverlay;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    char unk0x04[0x24];
    char szOwner[0x10];
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
    union
    {
        D2ObjectDataStrc* pObjectData;
        void* pData;
    };
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

typedef char (__fastcall* D2ObjectClientFn)(D2UnitStrc* pUnit);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                       // 0x0040B3C0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax);                                      // 0x004135D0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg);                             // 0x00466CB0
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit);                            // 0x0064C260
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit);                                                        // 0x00621310
int __fastcall sub_0046E100(D2UnitStrc* pUnit, int nOverlay);                                               // 0x0046E100

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
extern D2ObjectClientFn gapfnObjectClientFn_007277F0[];                                                     // 0x007277F0

// 0x004BC8D0
void __fastcall sub_004BC8D0_UpdateObjectOverlay(D2UnitStrc* pUnit)
{
    if (!pUnit->pObjectData->pObjectTxt->nOverlay)
    {
        return;
    }

    switch (pUnit->dwClassId)
    {
    case 0x98:
        sub_00470390(pUnit, 0xB6, 3, 0, 0, 0, 0, 0);
        return;

    case 0x95:
        if (pUnit->dwAnimMode == 1)
        {
            sub_00470390(pUnit, 0xB6, 3, 0, 0, 0, 0, 0);
        }
        return;

    case 0x162:
    case 0x163:
    case 0x164:
    case 0x18D:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x1C7:
        if (pUnit->dwAnimMode == 0)
        {
            sub_00470390(pUnit, 0x47, 3, 0, 0, 0, 0, 0);
        }
        return;
    }
}

// 0x004BCA50
void __fastcall sub_004BCA50_ReleaseUnit(D2UnitStrc* pUnit)
{
    sub_0046EC10_FreeGfxData(pUnit);
    if (gpGlobal_007A0634)
    {
        UNITS_FreeCollisionPath(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
        sub_00464930_FreeLight(pUnit);
    }

    sub_0040B3C0(pUnit->pData, ".\\UNIT\\Object.cpp", 0xFE, 0);
}

// 0x004BDEE0
char __fastcall sub_004BDEE0(D2UnitStrc* pUnit)
{
    D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    unsigned char nClientFn = pTxt->nClientFn;
    D2_ASSERT(nClientFn < 0x13, 0x546);
    if (nClientFn)
    {
        return gapfnObjectClientFn_007277F0[nClientFn](pUnit);
    }

    return 1;
}

// 0x004BDFE0
void __fastcall sub_004BDFE0_SetObjectName(D2UnitStrc* pUnit, const char* szName)
{
    SStrCopy(pUnit->pObjectData->szOwner, szName, 0x10);
}

// 0x004C1A70
void __fastcall sub_004C1A70_ReleaseItemUnit(D2UnitStrc* pUnit)
{
    sub_0046EC10_FreeGfxData(pUnit);
    if (ITEMS_CheckIfSocketable(pUnit))
    {
        sub_00466CB0_RemoveInventoryUnits(pUnit, 0);
        INVENTORY_FreeInventory(pUnit->pInventory);
        pUnit->pInventory = 0;
    }

    if (gpGlobal_007A0634)
    {
        UNITS_FreeCollisionPath(pUnit);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (UNITROOM_IsUnitInRoom(pRoom, pUnit))
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
    }
}

// 0x004C1AD0
void __fastcall sub_004C1AD0_UpdateAnim(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x348);
    switch (pUnit->dwAnimMode)
    {
    case 5:
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            pUnit->dwAnimMode = 3;
            break;
        }

        UNITS_UpdateFrame(pUnit);
        return;

    case 3:
        pUnit->dwFlags |= 2;
        if (sub_0046E100(pUnit, 0x46))
        {
            return;
        }
        break;

    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        pUnit->dwFlags &= ~2;
        return;

    default:
        D2_ASSERT(0, 0x362);
    }

    sub_00470390(pUnit, 0x46, 6, 8, 0, 0, 8, 0);
}

#include "gen/data/Source/D2Client/004BC8D0_sub_004BC8D0_UpdateObjectOverlay.inc"
