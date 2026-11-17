struct D2InventoryStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2DrlgActStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x34];
    int dwSeqFrame;
    char unk0x3C[0x24];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x00[0x168];
    unsigned char nWeapSel;
};

struct D2PartyNodeStrc
{
    int nUnitGUID;
    D2PartyNodeStrc* pNext;
};

struct D2PartyStrc
{
    unsigned short nPartyId;
    short field_2;
    D2PartyNodeStrc* pPartyNodes;
    D2PartyStrc* pNext;
};

struct D2PartyControlStrc
{
    short field_0;
    short field_2;
    D2PartyStrc* pParties;
};

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1C5C];
    D2PartyControlStrc* pPartyControl;
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x005317B0
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId); // 0x00537340
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                          // 0x005382B0
void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* pClient, int nDestinationLevelId, int nTileCalc); // 0x0053ACC0
void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053EAE0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
int __fastcall PLRTRADE_CopyTradeSaveDataToBuffer(D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize); // 0x005675E0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                              // 0x00620250
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                   // 0x00623460
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063C050
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                            // 0x006427F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                           // 0x00644140
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

#define UNIT_PLAYER 0
#define STAT_GOLD 14
#define STAT_GOLDBANK 15
#define ITEMTYPE_WEAPON 45
#define ITEMACTION_DROPTOGROUND 2
#define ITEMACTION_ONGROUND 3

// 0x00531BB0
int __fastcall sub_00531BB0_WriteItemList(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7)
{
    if (nArg5 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nResult = PLRTRADE_CopyTradeSaveDataToBuffer(pUnit, pBuffer, nBufferSize);
        if (nResult != 0)
        {
            return nResult;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    return sub_005317B0_WriteItems(pGame, pUnit, pInventory, pBuffer, nBufferSize, nArg5, nArg6, nArg7);
}

// 0x00535BC0
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pEquippedWeapon;
    int nBodyLoc;
    int bIsLeftHandItem;
    INVENTORY_GetEquippedWeapon(pInventory, &pEquippedWeapon, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
        if (pSkill)
        {
            D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pWeapon = 0;
                switch (pSkillsTxtRecord->nWeapSel)
                {
                case 2:
                {
                    const int nFlag = SKILLS_GetFlags(pSkill) & 0x2000;
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    D2UnitStrc* pTemp = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    if (!pWeapon || !ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_WEAPON) || pTemp && ITEMS_CheckItemTypeId(pTemp, ITEMTYPE_WEAPON) && nFlag)
                    {
                        pWeapon = pTemp;
                    }
                    break;
                }
                case 3:
                {
                    if (((pUnit->dwSeqFrame >> 8) % 2) != 0)
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    }
                    else
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    }
                    break;
                }
                case 4:
                {
                    pEquippedWeapon = 0;
                    break;
                }
                case 1:
                {
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    break;
                }
                default:
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    if (!pWeapon || !ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_WEAPON))
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    }
                    break;
                }

                if (ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_WEAPON) && ITEMS_CanBeEquipped(pWeapon))
                {
                    return pWeapon;
                }
            }
        }
        return pEquippedWeapon;
    }
    return pEquippedWeapon;
}

// 0x0053AEC0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc)
{
    const unsigned char nDestinationAct = DRLG_GetActNoFromLevelId(nDestinationLevelId);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\Level.cpp", 506);
    D2_ASSERT(pClient, 507);

    int nSourceLevelId = 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        nSourceLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    if (nDestinationAct != CLIENTS_GetActNo(pClient))
    {
        SUNITPROXY_UpdateNpcsOnActChange(pGame, pPlayer, nSourceLevelId, nDestinationLevelId);
        LEVEL_ChangeAct(pGame, pClient, nDestinationLevelId, nTileCalc);
        return;
    }

    int nX;
    int nY;
    D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nDestinationAct], nDestinationLevelId, nTileCalc, &nX, &nY, UNITS_GetUnitSizeX(pPlayer));
    if (pSpawnRoom)
    {
        sub_6FCBDFE0(pGame, pPlayer, pSpawnRoom, nX, nY, 0, 0);
    }
}

// 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2013) == pClient, 2013);
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_DROPTOGROUND, a4, 0);
}

// 0x0053ECF0
void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2022) == pClient, 2022);
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ONGROUND, a4, 0);
}

// 0x0053FF00
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    const int nNewValue = nValue + STATLIST_UnitGetStatValue(pUnit, nStat, 0);
    if (nNewValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nNewValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nNewValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00540510
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs)
{
    D2_ASSERT(pGame->pPartyControl, 210);

    for (D2PartyStrc* pParty = pGame->pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            if (nPartyId != 0xFFFF)
            {
                for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
                {
                    D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
                    if (pPartyMember)
                    {
                        pCallback(pGame, pPartyMember, pArgs);
                    }
                }
            }
            return;
        }
    }
}
