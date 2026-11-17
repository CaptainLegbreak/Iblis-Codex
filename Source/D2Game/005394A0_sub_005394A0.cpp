extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgActStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2SkillStrc;
struct D2SkillListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1C];
    int unk0xEC;
};

struct D2ClientStrc
{
    char unk0x000[0x3D4];
    unsigned int dwFlags;
    char unk0x3D8[0xAC];
    int nIronGolemItemGUID;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                            // 0x005382B0
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom);                     // 0x005381F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_6FC7BFC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nPlayerGUID, D2CoordStrc* pCoord); // 0x005352C0
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x7E_6FC3F770(D2ClientStrc* pClient, int nUnused);                  // 0x0053DB70
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate); // 0x00554850
void __fastcall sub_005773D0_UpdateMercForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer);                // 0x005773D0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead); // 0x005774F0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7);
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);               // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct);                                           // 0x0061AE80
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY, int nUnitSize); // 0x0061B060
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                           // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                           // 0x006204C0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                    // 0x00620C10
int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int a3);     // 0x0063D4E0
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                              // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse);                                     // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
extern "C" unsigned short __stdcall sub_0063D650(D2CorpseStrc* pCorpse);                                   // 0x0063D650
extern "C" unsigned int __stdcall sub_0063D670(D2CorpseStrc* pCorpse);                                     // 0x0063D670
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);          // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

// 0x005394A0
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nXArg, int nYArg)
{
    if (!pGame || !pPlayer || !pClient)
    {
        return;
    }

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    int nX;
    int nY;
    if (!pRoom)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]);
        pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nX, &nY, UNITS_GetUnitSizeX(pPlayer));
        D2_ASSERT(pRoom, 0x1A1);

        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), tDrlgCoords.nTileXPos, tDrlgCoords.nTileYPos);
    }
    else
    {
        nX = nXArg;
        nY = nYArg;
    }

    CLIENTS_SetRoomInClient(pClient, pRoom);
    SUNIT_Add(pPlayer, nX, nY, pGame, pRoom, 0);
    pClient->dwFlags &= ~1;
    const int nUnitGUID = pPlayer->dwUnitId;
    const int nUnitType = (pPlayer ? pPlayer->dwUnitType : 6);
    D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, 1);
    D2GAME_PACKETS_SendPacket0x7E_6FC3F770(pClient, pGame->unk0xEC);

    D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory);
    while (pCorpse)
    {
        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
        if (!sub_0063D670(pCorpse))
        {
            const unsigned short wName = sub_0063D650(pCorpse);
            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
            INVENTORY_FreeCorpse(pPlayer->pInventory, nCorpseGUID, 0);
            if (nCorpseGUID && wName)
            {
                D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, wName, nCorpseGUID, 0xFFFF, 0, 0);
            }
        }
        else
        {
            D2UnitStrc* pCorpsePlayer = SUNIT_GetServerUnit(pGame, 0, nCorpseGUID);
            if (pCorpsePlayer)
            {
                const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
                int nCorpseX = 0;
                int nCorpseY = 0;
                D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nCorpseX, &nCorpseY, UNITS_GetUnitSizeX(pCorpsePlayer));
                D2CoordStrc tCoord;
                tCoord.nX = nCorpseX;
                tCoord.nY = nCorpseY;
                sub_6FC7BFC0(pGame, pSpawnRoom, nCorpseGUID, &tCoord);
            }

            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
        }
    }

    sub_005773D0_UpdateMercForOwnerMove(pGame, pPlayer);

    const int nIronGolemItemGUID = pClient->nIronGolemItemGUID;
    if (nIronGolemItemGUID && nIronGolemItemGUID != -1)
    {
        D2UnitStrc* pIronGolemItem = SUNIT_GetServerUnit(pGame, 4, nIronGolemItemGUID);
        if (pIronGolemItem)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, 0x5A);
            if (pSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                UNITS_SetXForStaticUnit(pIronGolemItem, CLIENTS_GetUnitX(pPlayer));
                UNITS_SetYForStaticUnit(pIronGolemItem, CLIENTS_GetUnitY(pPlayer));
                UNITS_SetTargetUnitForDynamicUnit(pPlayer, pIronGolemItem);
                sub_0056F7F0(pGame, pPlayer, 0x5A, nSkillLevel, 1, 0, 0);
            }
        }

        pClient->nIronGolemItemGUID = -1;
    }
}
