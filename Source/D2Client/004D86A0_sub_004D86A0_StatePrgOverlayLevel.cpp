struct D2UnitStrc;
struct D2StatListStrc;

struct D2StatesTxt
{
    unsigned short wState;
    unsigned short wOverlay[4];
    unsigned short wCastOverlay;
    unsigned short wRemoveOverlay;
    short wPrgOverlay;
    unsigned char nStateFlags[8];
    short wStat;
    char unk0x1A[0x3C - 0x1A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xBC0 - 0xC8];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0xBD4 - 0xBC4];
    int nItemStatCostTxtRecordCount;
};

void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId);              // 0x00621CC0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                    // 0x00621CE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);            // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);       // 0x00625D00

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x004D86A0
void __fastcall sub_004D86A0_StatePrgOverlayLevel(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_0046F0C0(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, pStatesTxt->wStat, 0);
    if (nLevel >= 1 && nLevel <= 3)
    {
        sub_00470390(pUnit, pStatesTxt->wPrgOverlay + nLevel - 1, 3, 0, 0, 0, 0, 0);
    }
}

// 0x004D8760
void __fastcall sub_004D8760_StatePrgOverlays(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_0046F0C0(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }
}

// 0x004D8960
void __fastcall sub_004D8960_StateStoreOwner(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        unsigned int nOwnerType = STATLIST_GetStatValue(pStatList, 0x161, 0);
        if (nOwnerType < 6)
        {
            UNITS_StoreOwnerTypeAndGUID(pUnit, nOwnerType, STATLIST_GetStatValue(pStatList, 0x162, 0));
        }
    }
}

// 0x004D89A0
void __fastcall sub_004D89A0_StateClearOwner(D2UnitStrc* pUnit, int nState)
{
    UNITS_StoreOwner(pUnit, 0);
}
