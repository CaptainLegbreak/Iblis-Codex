struct D2InventoryStrc;
struct D2ClientStrc;
struct D2HoverTextStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x40];
    D2HoverTextStrc* pHoverText;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x50];
    int bExpansion;
    char f_74[0x34];
    unsigned int dwGameFrame;

    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x00549150
};

#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned int dwParam;
    unsigned char nParam;
    char szText[32];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame);  // 0x00548B00
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit);                                             // 0x00549A60
void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                  // 0x0054AA40
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);                     // 0x00535610
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);                                             // 0x005A01E0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);              // 0x00621050
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell);                               // 0x00628320
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot);     // 0x0063C4F0
int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId);  // 0x0063C600
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
D2HoverTextStrc* __stdcall CHAT_AllocHoverMsg(void* pMemoryPool, const char* szText, int nGameFrame);       // 0x00661110
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg);                             // 0x006611D0
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId);                 // 0x00661230

inline int UNITS_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    return nType;
}

// 0x00548ED0
int __stdcall sub_00548ED0_SelectBelowSix(unsigned int nValue)
{
    return nValue < 6 ? 0 : 2;
}

// 0x0054A290
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x14_HandleOverheadChat_6FC84690(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize < 4 || nSize > 275)
    {
        return 3;
    }

    const int nStringLength = SStrLen((char*)pPacket + 3);
    if (nStringLength <= 0)
    {
        return 0;
    }

    char szText[256];
    SStrCopy(szText, (char*)pPacket + 3, sizeof(szText));
    if (nStringLength >= 256)
    {
        return 2;
    }

    char szName[16];
    SStrCopy(szName, (char*)pPacket + nStringLength + 4, sizeof(szName));

    if (SStrChr(szText, -1))
    {
        return 0;
    }

    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(pGame->pMemoryPool, szText, pGame->dwGameFrame);
    if (!pHoverText)
    {
        return 0;
    }

    CHAT_SetLangIdInHoverMsg(pHoverText, *((unsigned char*)pPacket + 2));

    if (pUnit)
    {
        pUnit->pHoverText = pHoverText;
    }

    UNITROOM_RefreshUnit(pUnit);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x100;
    }

    EVENT_SetEvent(pGame, pUnit, 6, D2_MAX(pGame->dwGameFrame + 1, CHAT_GetTimeoutFromHoverMsg(pHoverText)), 0, 0);
    return 0;
}

// 0x0054AAD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x16_PickItemOnGround_6FC84DB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    const int nArg = *(int*)((char*)pPacket + 9);
    if (nUnitType >= 6)
    {
        return 2;
    }

    if ((!pUnit ? -1 : pUnit->dwUnitId) != nUnitGUID || nUnitType != 0)
    {
        return sub_6FC828D0(pUnit, nUnitType, nUnitGUID, nArg, pGame);
    }

    return 3;
}

// 0x0054D520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x63_ShiftLeftClickItemToBelt_6FC88F80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);

    const int nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        sub_00549A60_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 2;
    }

    if (!ITEMS_CheckIfBeltable(pItem))
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pItem))
    {
        return 3;
    }

    unsigned char nPage;
    int nFreeSlotId = 0;
    if (INVENTORY_GetFreeBeltSlot(pUnit->pInventory, pItem, &nFreeSlotId) && nFreeSlotId >= 0 && sub_6FC7C3A0(pGame, pUnit, pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2_ASSERT(pInventory, 0x1821);

        if (ITEMS_GetInvPage(pItem) || pItem->dwAnimMode != 0)
        {
            return 2;
        }

        D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
        D2_ASSERT(pRemove, 0x182A);
        D2_ASSERT(pItem == pRemove, 0x182B);

        nPage = ITEMS_GetInvPage(pItem);
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion);
        INVENTORY_Return(".\\PLAYER\\PlrMsg.cpp", 0x1830, pInventory, UNITS_GetXPosition(pItem), CLIENTS_GetUnitY(pItem), nInventoryRecordId, 0, nPage);
        ITEMS_SetItemCell(pItem, nPage);
        ITEMS_SetInvPage(pItem, 0xFF);

        D2GAME_UpdateClientItem_6FC3E9D0(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1834), pUnit, pItem, 0);

        UNITS_ChangeAnimMode(pItem, 4);

        pItem->dwFlags &= ~2u;

        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\PLAYER\\PlrMsg.cpp", 0x183B);

        if (INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nFreeSlotId))
        {
            ITEMS_SetInvPage(pItem, 0xFF);

            if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
            {
                UNITS_ChangeAnimMode(pItem, 2);
                D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1842), pUnit, pItem, 0);
            }
        }

        UNITS_RefreshInventory(pUnit, 1);
    }

    return 0;
}

// 0x0054D8A0
void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const bool bDefenderIsPlayer = pDefender && pDefender->dwUnitType == 0;
    D2_ASSERT(bDefenderIsPlayer, 0x19B4);

    if (pAttacker && pAttacker->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == 0)
        {
            pAttacker = pOwner;
        }
    }

    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = 6;
    packet5A.nColor = 4;
    const int nClassId = !pAttacker ? -1 : pAttacker->dwClassId;
    packet5A.dwParam = nClassId;
    packet5A.nParam = UNITS_GetUnitTypeOrInvalid(pAttacker);
    packet5A.szText[16] = 0;

    const char* szDefenderName = CLIENTS_GetName(SUNIT_GetClientFromPlayer(pDefender, ".\\PLAYER\\PlrMsg.cpp", 0x19C9));
    if (SStrLen(szDefenderName))
    {
        SStrCopy(packet5A.szText, szDefenderName, 16);
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    switch (UNITS_GetUnitTypeOrInvalid(pAttacker))
    {
    case 0:
    {
        char szName[16];
        SStrCopy(szName, CLIENTS_GetName(SUNIT_GetClientFromPlayer(pAttacker, ".\\PLAYER\\PlrMsg.cpp", 0x19DB)), 16);
        if (SStrLen(szName))
        {
            SStrCopy(&packet5A.szText[16], szName, 16);
        }
        break;
    }
    case 1:
        if (MONSTERUNIQUE_CheckMonTypeFlag(pAttacker, 2))
        {
            *(unsigned short*)&packet5A.szText[16] = MONSTERUNIQUE_GetBossHcIdx(pAttacker);
        }
        break;
    }

    sub_6FC84D40(pGame, &packet5A);
}
