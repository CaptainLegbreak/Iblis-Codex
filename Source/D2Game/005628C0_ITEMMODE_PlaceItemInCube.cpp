struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char szItemModeCpp[]; // 0x006E1164

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, int a6, int a7, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

// 0x005628C0
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 5287);
    D2_ASSERT(pUnit, 5288);

    sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 5291);

    *pItemStatus = 0;
    D2UnitStrc* pCube = SUNIT_GetServerUnit(pGame, 4, nCubeGUID);
    if (!pCube)
    {
        *pItemStatus = 1;
        return 0;
    }
    if ((!pCube ? 0 : pCube->dwAnimMode) || ITEMS_GetBaseCode(pCube) != 0x20786F62)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1) && ITEMS_GetInvPage(pCube))
    {
        SUNIT_AttachSound(pUnit, 19, pUnit);
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 3 && pItem->dwAnimMode != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    if ((!pCube ? 6 : pCube->dwUnitType) == 4)
    {
        if (!pCube ? 0 : pCube->dwAnimMode)
        {
            *pItemStatus = 1;
            return 0;
        }

        ITEMS_SetInvPage(pItem, 3);
        D2GAME_PlaceItem_6FC44410(szItemModeCpp, 5356, pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, 0, 0, 1, 1, 0);
        return 1;
    }

    return 0;
}
