#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
struct D2SkillStrc;
struct D2UnitStrc;

struct D2GameStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem);                                           // 0x004C2180
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern short gwGlobal_007C78A8;                                                                             // 0x007C78A8
extern short gwGlobal_007C78AC;                                                                             // 0x007C78AC
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0
void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4);          // 0x004B9A00
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue);                                            // 0x004B9B50
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame);  // 0x00626D40
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450

static __declspec(noinline) D2UnitStrc* __stdcall sub_004C0F20_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9CStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 8;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pData, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->dwUnitId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pData, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->dwUnitId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xD8, ".\\UNIT\\Item.cpp"))
            sub_00478680_SendPacket5(0x37, pPacket->dwUnitId);
    }
    return pItem;
}

static __declspec(noinline) D2UnitStrc* __stdcall sub_004C0FF0_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2ItemPacket9DStrc* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nSize - 0x0D;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pData, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_AllocClientUnit(pPacket->dwUnitId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pData, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->dwUnitId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xFE, ".\\UNIT\\Item.cpp"))
            sub_00478680_SendPacket5(0x37, pPacket->dwUnitId);
    }
    return pItem;
}

// 0x004C1160
static void sub_004C1160_SaveSkillState(D2SkillStateStrc* pState, D2UnitStrc* pUnit)
{
    pState->nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pState->nStamina = STATLIST_UnitGetStatValue(pUnit, 0x0A, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pState->nLeftOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\Item.cpp", 0x155);
    }
    else
    {
        pState->nLeftOwnerGUID = -1;
        pState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pState->nRightOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\UNIT\\Item.cpp", 0x161);
    }
    else
    {
        pState->nRightOwnerGUID = -1;
        pState->nRightSkillId = 0;
    }
}

// 0x004C1200
static void sub_004C1200_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
{
    if (pState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (sub_004D9FC0(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetLeftActiveSkill(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
                break;
            }
        }
    }

    if (pState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (sub_004D9FC0(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetRightActiveSkill(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
                break;
            }
        }
    }
}

static __declspec(noinline) void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem || !pUnit->pInventory)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
    sub_0046F280_ClearGfxBytes(pUnit, nComponent);
}

static __forceinline D2UniqueItemsTxt* ITEM_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    return 0;
}

static __forceinline D2SetItemsTxt* ITEM_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nIndex];
    return 0;
}

static int sub_004C16D0_GetItemDropSound(D2UnitStrc* pItem, int* pDelay)
{
    int nSound = 0;
    if (pDelay)
        *pDelay = 0x0C;

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > nSound)
    {
        if (pDelay && pItemsTxt->nDropSfxFrame > 0)
            *pDelay = pItemsTxt->nDropSfxFrame;
        nSound = pItemsTxt->wDropSound;
    }

    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEM_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
            {
                if (pDelay && pUniqueItemsTxt->nDropSfxFrame > 0)
                    *pDelay = pUniqueItemsTxt->nDropSfxFrame;
                nSound = pUniqueItemsTxt->wDropSound;
            }
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEM_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
        {
            if (pDelay && pSetItemsTxt->nDropSfxFrame > 0)
                *pDelay = pSetItemsTxt->nDropSfxFrame;
            nSound = pSetItemsTxt->wDropSound;
        }
    }
    return nSound;
}

static __declspec(noinline) void sub_004C18B0_PlayDropSound(D2UnitStrc* pItem)
{
    int nDelay = 0x0C;
    const int nSound = sub_004C16D0_GetItemDropSound(pItem, &nDelay);
    sub_004B9A00(0xD8, pItem, 0, 0, 0);
    if (nSound > 0)
    {
        const int nHandle = sub_004B9A00(nSound, pItem, nDelay, 0, 0);
        if (nHandle)
            sub_004B9B50_SetValue(nHandle, 0xB4);
    }
}

void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bInit)
{
    if (nMode >= 7)
        return;

    const int nCurrentMode = pItem->dwAnimMode;
    if ((nCurrentMode == 5 || nCurrentMode == 3) && nMode != 5 && nMode != 3)
        UNITS_FreeCollisionPath(pItem);

    pItem->dwAnimMode = nMode;
    UNITROOM_UpdatePath(pItem);
    switch (pItem->dwAnimMode)
    {
    case 5:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags &= ~2;
        sub_00624390_AnimInit(pItem);
        sub_004C18B0_PlayDropSound(pItem);
        break;

    case 3:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags |= 2;
        sub_00624390_AnimInit(pItem);
        break;

    case 4:
        sub_004B9A00(0xEB, 0, 0, 0, 0);
    case 0:
    case 1:
    case 2:
    case 6:
        pItem->dwFlags &= ~2;
        break;

    default:
        return;
    }

    pItem->dwFlags &= ~4;
    pItem->dwFlags &= ~0x08;
    pItem->dwFlags |= 0x20;
    if (!bInit)
        return;

    ITEMS_SetItemFlag(pItem, 0x10, 1);
    STATLIST_AllocStatListEx(pItem, 0, 0, 0);
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 0x40, 0, 4, pItem->dwUnitId);
    D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
    if (ITEMS_CheckIfSocketable(pItem) && !pItem->pInventory)
        INVENTORY_AllocInventory(0, pItem);
}

static __declspec(noinline) void sub_004C1C20_SetWeaponClass(D2UnitStrc* pItem, unsigned char nType)
{
    const int nWeaponClass = ITEMS_GetWeaponClassId(pItem);
    if (nType == 4)
        gwGlobal_007C78A8 = nWeaponClass;
    else if (nType == 5)
        gwGlobal_007C78AC = nWeaponClass;
}

// 0x004C25B0
void __fastcall sub_004C25B0_ItemDropToGround9C(D2ItemPacket9CStrc* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pData, pPacket->nSize - 8, 0, &tItemSave);

    D2UnitStrc* pItem = sub_004C0F20_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0x384);

    sub_004C2180_UpdateCursorItem(pItem);
    if (pItem->dwAnimMode == 3 && ITEMS_CheckItemFlag(pItem, 0x2000, 0x388, ".\\UNIT\\Item.cpp"))
    {
        UNITS_ChangeAnimMode(pItem, 5);
        sub_004C18B0_PlayDropSound(pItem);
    }
}

D2UnitStrc* __fastcall sub_E08_Emit_ItemCreate(D2ItemPacket9CStrc* pPacket, D2ItemPacket9DStrc* pOwned, unsigned short nX, unsigned short nY, D2ItemSaveStrc* pSave)
{
    D2UnitStrc* pItem = sub_004C0F20_CreateWorldItem(nX, nY, 0, pPacket, 0);
    if (!pItem)
        pItem = sub_004C0FF0_CreateOwnedItem(nX, nY, 0, pOwned, pSave);
    sub_004C1C20_SetWeaponClass(pItem, pOwned->nAction);
    return pItem;
}

void __fastcall sub_E08_Emit_SkillState(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2SkillStateStrc tState;
    sub_004C1160_SaveSkillState(&tState, pUnit);
    sub_004C1290_AttachItem(pItem->dwClassId, pUnit, pItem);
    sub_004C1200_RestoreSkillState(pUnit, &tState);
}
