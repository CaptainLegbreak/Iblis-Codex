extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2InventoryStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

#define UNIT_PLAYER 0
#define STATE_PLAYERBODY 7
#define STAT_EXPERIENCE 13

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory);                                           // 0x0063D450
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags);       // 0x0055B300
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nExperience);            // 0x0057EAB0
int __fastcall sub_00562F30(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody);                 // 0x00562F30
void __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, int nUnitId, int bFree);                   // 0x0063D4E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380

static int __stdcall sub_0057FAF0_CanPickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    D2_ASSERT(pPlayer, 909);
    D2_ASSERT(pDeadBody, 910);
    D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 911);
    const int nOwnerGUID = INVENTORY_GetOwnerId(pDeadBody->pInventory);
    if (pPlayer->dwUnitId == nOwnerGUID)
    {
        return 1;
    }
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
    if (pOwner)
    {
        return PLAYERLIST_CheckFlag(pOwner, pPlayer, 1);
    }
    return 0;
}

// 0x0057FB70
void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    if (!STATES_CheckState(pDeadBody, STATE_PLAYERBODY))
    {
        return;
    }
    if (!sub_0057FAF0_CanPickUpCorpse(pGame, pPlayer, pDeadBody))
    {
        return;
    }
    D2InventoryStrc* const pBodyInventory = pDeadBody->pInventory;
    const int nOwnerGUID = INVENTORY_GetOwnerId(pBodyInventory);
    if ((!pPlayer ? -1 : pPlayer->dwUnitId) == nOwnerGUID)
    {
        const int nExperience = STATLIST_UnitGetStatValue(pDeadBody, STAT_EXPERIENCE, 0);
        if (nExperience)
        {
            STATLIST_SetUnitStat(pDeadBody, STAT_EXPERIENCE, 0, 0);
            SUNITDMG_AddExperience(pGame, pPlayer, nExperience);
        }
    }
    if (sub_00562F30(pGame, pPlayer, pDeadBody))
    {
        const int nCorpseGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2InventoryStrc* const pInventory = pPlayer->pInventory;
        INVENTORY_FreeCorpse(pInventory, nCorpseGUID, 1);
        const int nBodyGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        const int nBodyType = !pDeadBody ? 6 : pDeadBody->dwUnitType;
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pDeadBody), nBodyType, nBodyGUID);
        const int nDeadGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, pPlayer->dwUnitId, nDeadGUID, 0);
        UNITS_FreeCollisionPath(pDeadBody);
        SUNIT_RemoveUnit(pGame, pDeadBody);
        SUNIT_AttachSound(pPlayer, 0x5D, pPlayer);
    }
    else
    {
        SUNIT_AttachSound(pPlayer, 0x17, pPlayer);
    }
}
