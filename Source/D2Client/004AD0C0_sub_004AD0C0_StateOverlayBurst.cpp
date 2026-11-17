struct D2DynamicPathStrc;
struct D2InventoryStrc;

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x46];
    short nStateOverlayLevel[3];
    char unk0x5C[0x14C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2ClientItemSlotStrc
{
    char unk0x00[0x08];
    int nUnitId;
    char unk0x0C[0x04];
};

unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                             // 0x00465EE0
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB);   // 0x004CDB40
int __fastcall sub_004CDBA0_AddOverlay(D2UnitStrc* pUnit, int nOverlay, int nX, int nY, int nA, int nB);      // 0x004CDBA0
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
void __stdcall sub_0063BD00(D2InventoryStrc* pInventory);                                                   // 0x0063BD00
void __stdcall sub_0063CB70(D2InventoryStrc* pInventory);                                                   // 0x0063CB70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel);                       // 0x00663270

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2ClientItemSlotStrc gaItemSlots_007C0C85[10];                                                       // 0x007C0C85

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004AD0C0
void __fastcall sub_004AD0C0_StateOverlayBurst(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    const int nX = UNITS_GetXPosition(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX + 1, nY + 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX + 1, nY - 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX - 1, nY + 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX - 1, nY - 1, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD1A0
void __fastcall sub_004AD1A0_StateOverlayCross(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    const int nX = UNITS_GetXPosition(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nX, nY, 0, 1);
    const int nYPlus = nY + 1;
    const int nXPlus = nX + 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXPlus, nYPlus, 0, 1);
    bFlag = nY - 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXPlus, bFlag, 0, 1);
    const int nXMinus = nX - 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXMinus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXMinus, bFlag, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXPlus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXPlus, bFlag, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXMinus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXMinus, bFlag, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD510
void __fastcall sub_004AD510_StateEffect(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag && nState == 0x12)
    {
        return;
    }

    if (nState == 0x2A)
    {
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_004C70D0_StartUnitEffect(pUnit, pUnit, 0x5A, -1, 0, STATLIST_UnitGetStatValue(pUnit, 0x0C, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(0x5A, 0));
        }
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    if (nState == 0x0A)
    {
        sub_004CDBA0_AddOverlay(pUnit, 0x9B, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), 0, STATLIST_UnitGetStatValue(pUnit, 0x0C, 0));
        return;
    }
    if (nState == 0x12)
    {
        sub_004C70D0_StartUnitEffect(pUnit, pUnit, 0xC2, -1, 0, STATLIST_UnitGetStatValue(pUnit, 0x0C, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(0x77, 0));
    }
}

// 0x004ADB20
void __fastcall sub_004ADB20_StateOverlayAtPath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }
    sub_004CDBA0_AddOverlay(pUnit, 0x2A, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADBC0
void __fastcall sub_004ADBC0_StateMonOverlay(D2UnitStrc* pUnit, int nState, int bFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? GetMonStatsTxtRecord(pUnit->dwClassId) : 0;
    const int nLevel = pMonStatsTxtRecord->nStateOverlayLevel[sub_0044DCD0_GetDifficulty()];

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    if (nLevel == 1)
    {
        sub_004CDBA0_AddOverlay(pUnit, 0x1AB, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    else if (nLevel >= 2)
    {
        sub_004CDBA0_AddOverlay(pUnit, 0x1AC, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    sub_004CDBA0_AddOverlay(pUnit, 0x1AA, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004B2390
void __fastcall sub_004B2390_CheckMonStatsFlag(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
    int bFlag = 0;
    if (pMonStatsTxtRecord)
    {
        bFlag = pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }
    if (bFlag)
    {
        sub_0046F0C0(pUnit, 0, 0x48);
    }
}

// 0x004B3790
void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 10; ++i)
    {
        gaItemSlots_007C0C85[i].nUnitId = 0;
    }

    if (!pUnit)
    {
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pItemUnit = INVENTORY_UnitIsItem(pItem);
        if (pItemUnit)
        {
            const int nUnitType = pItemUnit ? pItemUnit->dwUnitType : 6;
            const int nUnitId = pItemUnit ? pItemUnit->dwUnitId : -1;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
    }
    sub_0063CB70(pInventory);
    sub_0063BD00(pInventory);
}
