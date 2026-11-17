extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

enum D2C_W10Constants
{
    UNIT_MONSTER = 1,
    UNIT_TILE = 5,
    STAT_HITPOINTS = 6,
    PET_TYPE_LIFE = 7,
    WEAPON_CLASS_7 = 7,
    DRAW_MODE_5 = 5,
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2InventoryStrc;
struct D2ClientUnitPointStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x14];
    int nSeqCurrentFramePrecise;
    char unk0x48[0x0C];
    D2ClientUnitPointStrc* pPoints;
    char unk0x58[0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0x28];
    unsigned short nLastClickX;
    unsigned short nLastClickY;
    char unk0x90[0x58];
    D2UnitStrc* pRoomNext;
};

struct D2ClientUnitPointStrc
{
    int nX;
    int nY;
    char unk0x08[0x18];
    D2ClientUnitPointStrc* pNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2MapAIStrc;

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    unsigned int bSpawned;
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

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2ClientViewStrc
{
    unsigned int dwFlags;
    tagRECT tViewRect;
    tagRECT tClipRect;
    int nPosX;
    int nPosY;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int nArg10;
    int unk0x14[2];
    int nLifePercent;
    int unk0x20[4];
    D2RosterPetStrc* pNext;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x24];
    int nState;
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

struct D2HintCursorStrc
{
    char unk0x00[0x60];
    int nOwnerId;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern int gdwGlobal_007A520C;                                                                              // 0x007A520C
extern int gdwGlobal_007A5208;                                                                              // 0x007A5208
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                       // 0x007C5458
static D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC

extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
void __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);         // 0x00466730
D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom);                       // 0x00619FD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260
void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY);              // 0x00643400
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

// 0x0045B0B0
void __fastcall sub_0045B0B0_DrawRoomUnitBoxes(D2ActiveRoomStrc* pRoom)
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nX = UNITS_GetClientCoordX(pUnit) - gdwGlobal_007A520C;
            const int nY = UNITS_GetClientCoordY(pUnit) - gdwGlobal_007A5208;
            D2GFX_DrawBox(nX, nY, nX + 4, nY + 4, 0xFF, DRAW_MODE_5);
            if (pUnit && pUnit->dwUnitType == UNIT_TILE)
            {
                for (D2ClientUnitPointStrc* pPoint = pUnit->pPoints; pPoint; pPoint = pPoint->pNext)
                {
                    D2GFX_DrawLine(UNITS_GetClientCoordX(pUnit) - gdwGlobal_007A520C, UNITS_GetClientCoordY(pUnit) - gdwGlobal_007A5208, pPoint->nX - gdwGlobal_007A520C, pPoint->nY - gdwGlobal_007A5208, 0xFF, 0xFF);
                }
            }
        }
    }
}

// 0x00466820
void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
            sub_00466730_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
        }
    }
}

// 0x0046B680
void __fastcall sub_0046B680_SpawnMissileTrio(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x11C;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
        MISSILE_SetTargetX(pMissile, 0x32);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x128;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
    tMissileParams.nMissile = 0x125;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046B9A0
void __fastcall sub_0046B9A0_SpawnMissileTrio2(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x12B;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x4B);
        MISSILE_SetTargetY(pMissile, 0x4B);
    }

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkillLevel = 1;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nMissile = 0x166;
    sub_004CD540_CreateMissile(&tMissileParams);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x132;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046BA50
void __fastcall sub_0046BA50_SpawnMissile(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x133;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046BC10
void __fastcall sub_0046BC10_HintAndMissile(D2UnitStrc* pUnit)
{
    sub_004DCD40_ShowTimedHint((void*)0x1253, 0, 0xFA, 0, 0, 0, 0);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x17B;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x00476000
void __fastcall sub_00476000_SetViewRects(D2ClientViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom)
{
    if (!pView)
        return;

    SetRect(&pView->tViewRect, nLeft, nTop, nRight, nBottom);
    nBottom = sub_004F51D0_IsPerspective();
    SetRect(&pView->tClipRect, -0x50, -0x50, gnGlobal_0071146C + 0x50, gnGlobal_00711470 - 0x2F);
    if (nBottom)
    {
        pView->tClipRect.top -= 30;
        pView->tClipRect.left -= 45;
        pView->tClipRect.right += 30;
    }
    pView->dwFlags |= 1;
}

// 0x004760E0
void __fastcall sub_004760E0_ViewToGameCoords(D2ClientViewStrc* pView, int nX, int nY, int* pX, int* pY)
{
    D2_ASSERT(pView, 0x1CD);
    D2_ASSERT(pX, 0x1CE);
    D2_ASSERT(pY, 0x1CF);
    DUNGEON_ClientSubileDrawPositionToGameCoords(pView->nPosX + nX, pView->nPosY + nY, pX, pY);
}

// 0x00479010
void __fastcall sub_00479010_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            pPet->nLifePercent = nLifePercent;
            pPet->nArg10 = nArg;
            if (pPet->nType == PET_TYPE_LIFE)
            {
                D2UnitStrc* pUnit = sub_00463990(nUnitId, UNIT_MONSTER);
                if (pUnit)
                    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pUnit) * nLifePercent / 100, 0);
            }
            return;
        }
    }
}

// 0x004B9640
int __fastcall sub_004B9640_CountHintsForOwner(int nOwnerId)
{
    int nCount = 0;
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (sub_00481860(pEntry->nHintId)->nOwnerId == nOwnerId && pEntry->nState == 1)
            nCount += 1;
    }
    return nCount;
}

// 0x004C76A0
int __fastcall sub_004C76A0_GetWeaponClassMask(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == WEAPON_CLASS_7 ? 0x1F : 0;
}

// 0x004D1640
D2UnitStrc* __fastcall sub_004D1640_SpawnDirectionalMissile(D2UnitStrc* pUnit, int nFrame)
{
    D2UnitStrc* pMissile = 0;
    if (pUnit->pDynamicPath)
    {
        unsigned char nDirection = PATH_GetDirection(pUnit->pDynamicPath);
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nMissile = 0x54;
        tMissileParams.nSkillLevel = 1;
        pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            pMissile->nSeqCurrentFramePrecise = nFrame << 8;
            if (pMissile->pDynamicPath)
                D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, nDirection);
            sub_00464810(pMissile);
        }
    }
    return pMissile;
}

// 0x004DC580
void __fastcall sub_004DC580_DrawUnitClickCross(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x61);
    int nX = pUnit->nLastClickX;
    int nY = pUnit->nLastClickY;
    sub_00643260(&nX, &nY);
    D2GFX_DrawLine(nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset(), nX - sub_0045AFC0() + 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset(), nX - sub_0045AFC0() - 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0() - 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset() + 0x10, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0() + 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset() + 0x10, 0xFF, 0xFF);
    const int nBoxX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
    const int nBoxY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    D2GFX_DrawBox(nBoxX, nBoxY, nBoxX + 4, nBoxY + 4, 0xFF, DRAW_MODE_5);
}
