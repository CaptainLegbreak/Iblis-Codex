struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
};

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC];
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2GSPacketSrv60
{
    unsigned char nHeader;
    unsigned char nFlags;
    unsigned char nLevel;
    char dwUnitGUID[4];
};

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};

struct D2SkillsTxt
{
    char unk0x000[0x114];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2MotionVectorStrc
{
    int nX;
    int nY;
    int nZ;
};

struct D2GfxMotionStrc
{
    int unk0x00;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    char unk0x1C[0xC];
    D2MotionVectorStrc tC;
    int unk0x34;
    int nUnk0x38;
    int nUnk0x3C;
};

struct D2UnitEventArgsStrc
{
    int nX;
    int nY;
    int nArg2;
    int nArg3;
    int nArg4;
    int nArg5;
    int nArg6;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
void __fastcall sub_0046F070_SetGfxMotion(D2UnitStrc* pUnit, D2GfxMotionStrc* pMotion);                     // 0x0046F070
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __fastcall sub_00480C10_DispatchUnitEvent(int nEvent, D2UnitStrc* pUnit, D2UnitEventArgsStrc* pArgs, int nArg); // 0x00480C10
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem);                                           // 0x004C2180
void __fastcall sub_004C5420_UseBow(D2UnitStrc* pUnit, int nValue, int nArg2, int nArg3);                   // 0x004C5420
void __fastcall sub_004C7BE0_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue);                           // 0x004C7BE0
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                               // 0x004E4050
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit);                                      // 0x006222C0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag);                    // 0x00622300
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall sub_00645F00_GetBowValue(D2UnitStrc* pUnit, int* pValue);                                     // 0x00645F00
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit);                                                // 0x0064F460

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004BDF30
void __fastcall sub_004BDF30_SetPortalStateFromPacket60(D2GSPacketSrv60* pPacket)
{
    D2_ASSERT(pPacket, 0x556);

    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->dwUnitGUID, UNIT_OBJECT);
    if (pUnit)
    {
        D2_ASSERT(pUnit->dwClassId == 0x3B || pUnit->dwClassId == 0x3C, 0x560);
        D2_ASSERT(pPacket->nLevel <= 0xFF, 0x562);

        pUnit->pObjectData->InteractType = pPacket->nLevel;

        unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pUnit);
        if (pPacket->nFlags & 2)
        {
            nPortalFlags |= 2;
        }
        if (pPacket->nFlags & 1)
        {
            nPortalFlags |= 1;
        }
        UNITS_SetObjectPortalFlags(pUnit, nPortalFlags);
    }
}

// 0x004C3B30
void __fastcall sub_004C3B30_UpdateItemFromPacket9C(D2GSPacketSrv9C* pPacket)
{
    int bFail;
    const int nSize = pPacket->nPacketSize - 8;
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, UNIT_ITEM);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, UNIT_ITEM);
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x7B3);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x7B6);

    if (!sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 8))
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem)
    {
        sub_004C2180_UpdateCursorItem(pCursorItem);
    }
}

// 0x004C51E0
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    *pX = aOffsetX[nDirection] + nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    *pY = aOffsetY[nDirection] + nY;
}

// 0x004C52E0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        sub_004C51E0_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

// 0x004C6030
int __fastcall sub_004C6030_UseBowOrCallTarget(D2UnitStrc* pUnit, int nArg2, int nArg3)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nValue = sub_00645F00_GetBowValue(pUnit, &nArg3);
        if (nValue != -1)
        {
            sub_004C5420_UseBow(pUnit, nValue, nArg2, nArg3);
        }
    }
    else
    {
        sub_004E4050_Nothing(pUnit, sub_004648F0_GetTargetUnit(pUnit));
    }

    return 1;
}

// 0x004C7CF0
int __fastcall sub_004C7CF0_EvaluateClientSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_004C7BE0_ApplyClientSkillCalc(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004D93B0
void __fastcall sub_004D93B0_SendPositionEvent(D2UnitStrc* pUnit)
{
    D2UnitEventArgsStrc tArgs = {};

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    tArgs.nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    tArgs.nY = nY;

    sub_00480C10_DispatchUnitEvent(0x19, pUnit, &tArgs, 0);
    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0);
}

// 0x004DA080
void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        FOG_Free(pMotion, ".\\ENGINE\\Particle.cpp", 100, 0);
        sub_0046F070_SetGfxMotion(pUnit, 0);
    }
}

// 0x004DA0D0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nUnk0x38;
    }
    return 0;
}

// 0x004DA0F0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nUnk0x3C;
    }
    return 0;
}
