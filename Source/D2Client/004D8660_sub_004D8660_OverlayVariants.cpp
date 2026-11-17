struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc tSeed;
    char unk0x28[0x1C];
    int n44;
    char unk0x48[0x7C];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2StatesTxt
{
    unsigned short wState;
    short wOverlay[4];
    short wCastOverlay;
    short wRemoveOverlay;
    short wPrgOverlay;
    unsigned char nStateFlags[8];
    unsigned short wStat;
    short wSetFunc;
    short wRemFunc;
    unsigned short wGroup;
    unsigned char nColorPri;
    unsigned char nColorShift;
    unsigned char nLightRGB[3];
    unsigned char pad0x25;
    short wOnSound;
    short wOffSound;
    char unk0x2A[0x12];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
};

struct D2StatListStrc;
struct D2SkillStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

void __fastcall sub_0046F000_ResetGfx(D2UnitStrc* pUnit);                                                   // 0x0046F000
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode);                                     // 0x00480E70
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __stdcall sub_004D97F0_UpdateStateColor(D2UnitStrc* pUnit);                                            // 0x004D97F0
void __fastcall sub_004D9920(D2UnitStrc* pUnit, int nState);                                                // 0x004D9920
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);                                                    // 0x00624390
int __stdcall STATLIST_GetState(D2StatListStrc* pStatList);                                                 // 0x006252F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList);                                          // 0x00627340
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                           // 0x0063A320
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId);                                      // 0x00664740

static __forceinline D2StatesTxt* GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }
    return 0;
}

static __forceinline int GetOverlay(short nOverlay)
{
    return nOverlay >= 0 ? nOverlay : -1;
}

static __forceinline int GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8660
static __declspec(noinline) void __stdcall sub_004D8660_OverlayVariants(D2UnitStrc* pUnit, int nOverlay)
{
    if (nOverlay == -1)
        return;

    const int nCount = DATATBLS_Get1OfNFromOverlayTxt(nOverlay);
    for (int i = 0; i < nCount; ++i)
    {
        sub_0046F0C0(pUnit, 0, nOverlay + i);
    }
}

// 0x004D8A60
void __fastcall sub_004D8A60_StateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nCast = GetOverlay(pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    if (nCast != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nCast);
        sub_004D8660_OverlayVariants(pUnit, nCast);
        sub_004D8660_OverlayVariants(pUnit, nCast);
    }
    if (nOverlay1 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
    }
    if (nOverlay2 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
    }
    if (nOverlay3 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay3);
    }
    if (nOverlay4 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay4);
    }
}

// 0x004D8B90
void __fastcall sub_004D8B90_StateTier4(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, 0x84, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, 0x85, 0);
    const int nCast = GetOverlay(pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, 0x163, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, 0x163, nTier, 0);
    if (nTier > nOldTier)
    {
        sub_004D8A60_StateOverlays(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            sub_00470390(pUnit, nOverlay3, 7, 0, 0, 0, 0, 0);
        }
        if (nOverlay4 != -1 && nTier >= 2)
        {
            sub_00470390(pUnit, nOverlay4, 7, 0, 0, 0, 0, 0);
        }
        if (nCast != -1 && nOverlay1 != -1 && nOverlay2 != -1)
        {
            sub_00470390(pUnit, nCast, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
    }
    else if (nTier < nOldTier)
    {
        for (int i = nTier; i < nOldTier; ++i)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay1);
            sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        }
    }
}

// 0x004D8D90
void __fastcall sub_004D8D90_StateOverlayPairs(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    if (nOverlay1 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1 + 1);
    }
    if (nOverlay2 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2 + 1);
    }
    if (nOverlay3 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay3);
        sub_004D8660_OverlayVariants(pUnit, nOverlay3 + 1);
    }
}

// 0x004D8E60
void __fastcall sub_004D8E60_StateTier3(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, 0x84, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, 0x85, 0);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, 0x163, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, 0x163, nTier, 0);
    if (nTier > nOldTier)
    {
        sub_004D8D90_StateOverlayPairs(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            sub_00470390(pUnit, nOverlay3, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay3 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay2 != -1 && nTier >= 2)
        {
            sub_00470390(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay2 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay1 != -1 && nTier >= 1)
        {
            sub_00470390(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay1 + 1, 3, 0, 0, 0, 0, 0);
        }
    }
    else
    {
        if (nOverlay3 && nTier <= 2)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay3);
            sub_004D8660_OverlayVariants(pUnit, nOverlay3 + 1);
        }
        if (nOverlay2 && nTier <= 1)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay2);
            sub_004D8660_OverlayVariants(pUnit, nOverlay2 + 1);
        }
        if (nOverlay1 && nOverlay1 <= 1)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay1);
            sub_004D8660_OverlayVariants(pUnit, nOverlay1 + 1);
        }
    }
}

// 0x004D9AD0
static __declspec(noinline) void sub_004D9AD0_ResetTransform(D2UnitStrc* pUnit)
{
    sub_0046F000_ResetGfx(pUnit);
    if (pUnit)
    {
        if (pUnit->dwUnitType == 0)
        {
            if (pUnit->dwAnimMode == 0x12)
                return;
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
        else if (pUnit->dwUnitType == 1)
        {
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
    }
    sub_00470610_Refresh(pUnit, 1);
    sub_00624390_AnimInit(pUnit);
    pUnit->n44 = 0;
    UNITS_SetUsedSkill(pUnit, 0);
}

// 0x004D9B20
void __fastcall sub_004D9B20_BeginState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (pTxt->nStateFlags[39 >> 3] & gdwBitMasks_006CE268[39 & 7])
    {
        if ((pUnit->dwUnitType == 1 && pUnit->dwAnimMode == 0xC) || (pUnit->dwUnitType == 0 && pUnit->dwAnimMode == 0x11))
        {
            STATES_ToggleState(pUnit, nState, 1);
            return;
        }
    }

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!(pTxt->nStateFlags[36 >> 3] & gdwBitMasks_006CE268[36 & 7]))
        {
            STATLIST_RemoveAllStats(pStatList);
        }
    }
    else if (pTxt->wOnSound >= 0)
    {
        sub_004B9A00(pTxt->wOnSound, pUnit, 0, 0, 0);
    }

    STATES_ToggleState(pUnit, nState, 1);
    if (pTxt->nColorShift)
    {
        sub_004D97F0_UpdateStateColor(pUnit);
    }
    sub_004D9920(pUnit, nState);
    if (sub_00464820_IsDeadOrDying(pUnit) && STATES_CheckStateMaskHideOnUnit(pUnit))
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        sub_004D9AD0_ResetTransform(pUnit);
    }
}

// 0x004D9C30
void __fastcall sub_004D9C30_EndState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList && nState == STATLIST_GetState(pStatList))
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (pTxt->wOffSound >= 0)
        {
            sub_004B9A00(pTxt->wOffSound, pUnit, 0, 0, 0);
        }
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (pTxt->nColorShift)
    {
        sub_004D97F0_UpdateStateColor(pUnit);
    }
    if (pTxt->wRemoveOverlay >= 0)
    {
        int nOverlay = pTxt->wRemoveOverlay;
        if (nOverlay != -1)
        {
            nOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->tSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay));
        }
        sub_00470390(pUnit, nOverlay, 4, 0, -1, -1, 0, 0);
    }
    if (pTxt->wOverlay[0] >= 0)
    {
        sub_004D8660_OverlayVariants(pUnit, pTxt->wOverlay[0]);
    }
    if (pTxt->wOverlay[1] >= 0)
    {
        sub_004D8660_OverlayVariants(pUnit, pTxt->wOverlay[1]);
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        sub_004D9AD0_ResetTransform(pUnit);
    }
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\PlrSkills.cpp", 0x59C);
}
