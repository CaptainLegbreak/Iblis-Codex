extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);         // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2ClientStrc;
struct D2QuestDataStrc;

struct D2UnitStrc
{
    char unk0x00[0xE8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
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

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;

    void sub_0053E2C0_WriteBool(int bValue);
};

struct D2ObjectControlStrc
{
    char unk0x0000[0x1048];
    unsigned short wGroupCount[0x61];
    unsigned short wRoomsTried;
    unsigned short wRoomsNoGroup;
};

struct D2GameStrc
{
    char unk0x0000[0x10F0];
    D2ObjectControlStrc* pObjectControl;

    void sub_00546FF0_SendQuestText(const char* szText);                                                    // 0x00546FF0
};

struct D2ObjectsTxt
{
    char unk0x000[0x1B2];
    unsigned char nPopulateFn;
};

struct D2W11RoomTileRecordStrc
{
    char unk0x00[0x18];
    int nTileX;
    int nTileY;
    int nArg1;
    int nArg2;
};

struct D2W11RoomTileOwnerStrc
{
    char unk0x00[0x14];
    D2W11RoomTileRecordStrc* pRecord;
};

struct D2MapAIStrc
{
    int nPathNodes;
    void* pPosition;
};

struct D2QuestDataStrc
{
    int unk0x00;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2W11QuestEx5B7230Strc
{
    unsigned char unk0x00;
    unsigned char bNpcSpawned;
    unsigned char unk0x02[0x0A];
    int nNpcGUID;
    unsigned char bMapAIChanged;
    unsigned char unk0x11[0x07];
    D2MapAIStrc* pMapAI;
};

struct D2W11QuestEx5BD040Strc
{
    unsigned char unk0x00[0x20];
    unsigned char bNpcSpawned;
    unsigned char unk0x21[0x03];
    D2MapAIStrc* pMapAI;
    int unk0x28;
    int nNpcGUID;
    unsigned char bMapAIChanged;
};

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

extern OBJECTPOPULATEFN gpfObjectPopulateTable_00731D00[10];                                                 // 0x00731D00
extern unsigned char gnObjectPopulateDensity_00731BBD;                                                      // 0x00731BBD

void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A1F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall sub_0063E510_InventoryGridQuery(D2UnitStrc* pUnit, unsigned char* pFirst, unsigned char* pSecond); // 0x0063E510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                       // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);               // 0x00666120
void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient);                    // 0x005531E0
void __fastcall sub_0053AAA0_UpdateRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget); // 0x0053AAA0

// 0x005379D0
int __fastcall sub_005379D0_QueryGridFirst(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3D4);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, pGrid, abOther);
}

// 0x00537A40
int __fastcall sub_00537A40_QueryGridSecond(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3DF);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, abOther, pGrid);
}

inline void W11_InlineFixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        sub_005531E0_FixRoomIfInvalid(pUnit, pClient);
}

// 0x0053A6F0
void __fastcall sub_0053A6F0_FixAdjacentRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x75);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        W11_InlineFixRoomUnits(ppRoomList[i], pClient);
}

// 0x0053AB10
void __fastcall sub_0053AB10_UpdateAdjacentRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x141);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        sub_0053AAA0_UpdateRoomUnits(pGame, ppRoomList[i], pTarget);
}

// 0x0053E2C0
void D2BitBufferStrc::sub_0053E2C0_WriteBool(int bValue)
{
    BITMANIP_Write(this, bValue != 0, 1);
}

// 0x00547080
void __fastcall sub_00547080_PrintObjectPlacementStats(D2GameStrc* pGame)
{
    char szText[0x80];
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    for (int i = 1; i < 0x61; ++i)
    {
        if (pObjectControl->wGroupCount[i])
        {
            wsprintfA(szText, "Attempted to place group %d %d times\n", i, pObjectControl->wGroupCount[i]);
            pGame->sub_00546FF0_SendQuestText(szText);
        }
    }
    wsprintfA(szText, "%d Rooms where we wanted to place - no group beat the odds\n", pObjectControl->wRoomsNoGroup);
    pGame->sub_00546FF0_SendQuestText(szText);
    wsprintfA(szText, "%d rooms tried to place 1+ group(s); %d rooms w/no objs\n", pObjectControl->wRoomsTried, pObjectControl->wGroupCount[0]);
    pGame->sub_00546FF0_SendQuestText(szText);
}

// 0x00552840
void __fastcall sub_00552840_PopulateObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nObjectId)
{
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
        return;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC7D);
    if (gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn]), 0xC80);
        gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, gnObjectPopulateDensity_00731BBD, nObjectId, 100);
    }
}

// 0x005536E0
void __fastcall sub_005536E0_StoreRoomTile(D2W11RoomTileOwnerStrc* pOwner, D2ActiveRoomStrc* pRoom, int nArg1, int nArg2)
{
    pOwner->pRecord->nArg1 = nArg1;
    pOwner->pRecord->nArg2 = nArg2;
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    pOwner->pRecord->nTileX = tCoords.nTileXPos;
    pOwner->pRecord->nTileY = tCoords.nTileYPos;
}

// 0x005B7230
void __fastcall sub_005B7230_ChangeQuestMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x0E);
    if (!pQuestData)
        return;
    D2W11QuestEx5B7230Strc* pQuestDataEx = (D2W11QuestEx5B7230Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pMapAI = pMapAI;
    if (!pQuestDataEx->bNpcSpawned)
        return;
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nNpcGUID);
    if (pNpc && pQuestDataEx->pMapAI && pQuestDataEx->pMapAI->pPosition && !pQuestDataEx->bMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pMapAI, AIGENERAL_GetMapAiFromUnit(pNpc));
        pQuestDataEx->bMapAIChanged = 1;
    }
}

// 0x005BD040
void __fastcall sub_005BD040_ChangeQuestMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x14);
    if (!pQuestData)
        return;
    D2W11QuestEx5BD040Strc* pQuestDataEx = (D2W11QuestEx5BD040Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pMapAI = pMapAI;
    if (!pQuestDataEx->bNpcSpawned)
        return;
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nNpcGUID);
    if (pNpc && pQuestDataEx->pMapAI && pQuestDataEx->pMapAI->pPosition && !pQuestDataEx->bMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pMapAI, AIGENERAL_GetMapAiFromUnit(pNpc));
        pQuestDataEx->bMapAIChanged = 1;
    }
}
