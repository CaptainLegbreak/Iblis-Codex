struct D2StatListStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[4];
    D2SeedStrc tSeed;
    int unk0x28[39];
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
    char unk0x18[0x24];
};

struct D2SkillsTxt
{
    char unk0x00[0x10E];
    short wPrgSound;
    char unk0x110[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC];
    D2StatesTxt* pStatesTxt;
    char f_C0[0x04];
    int nStatesTxtRecordCount;
    char unk0xC8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __fastcall sub_004DA620(D2UnitStrc* pUnit, int nArg);                                                  // 0x004DA620
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall sub_0063A210_StateMaskTest(int nState);                                                       // 0x0063A210
int __stdcall sub_0063A250(D2UnitStrc* pUnit);                                                              // 0x0063A250
void __stdcall D2Common_10214(D2UnitStrc* pUnit);                                                           // 0x00649CA0
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId);                                      // 0x00664740

#define STAT_MODIFIERLIST_SKILL 350

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004D9090
void __fastcall sub_004D9090_StatePlaySkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wPrgSound, pUnit, 0, 0, 0);
    }
}

// 0x004D90F0
void __fastcall sub_004D90F0_StateStopSkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pUnit, pSkillsTxtRecord->wPrgSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
        }
    }
}

// 0x004D9310
void __fastcall sub_004D9310_SetStateFlagEx(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
    }
}

// 0x004D9320
void __fastcall sub_004D9320_SetStateFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D9340
void __fastcall sub_004D9340_ClearStateFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= ~0x40000;
        pUnit->dwFlags &= ~0x20;
    }
}

// 0x004D9360
void __fastcall sub_004D9360_ResetGfxMotion(D2UnitStrc* pUnit, int nState)
{
    sub_004DA000_ResetGfxMotion(pUnit);
    sub_004DA620(pUnit, 1);
}

// 0x004D9380
void __fastcall sub_004D9380_ClearMotion(D2UnitStrc* pUnit, int nState)
{
    sub_004DA620(pUnit, 0);
    sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, 0);
}

// 0x004D9450
void __fastcall sub_004D9450_StateSetMode(D2UnitStrc* pUnit, int nState)
{
    sub_00480E70_SetState(pUnit, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 0x80000000;
    }
    D2Common_10214(pUnit);
}

// 0x004D9920
void __fastcall sub_004D9920_StartStateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || (pStatesTxtRecord->nStateFlags[4] & gdwBitMasks[3]))
    {
        return;
    }

    int nCastOverlay = pStatesTxtRecord->wCastOverlay >= 0 ? pStatesTxtRecord->wCastOverlay : -1;
    int nOverlay1 = pStatesTxtRecord->wOverlay[0] >= 0 ? pStatesTxtRecord->wOverlay[0] : -1;
    int nOverlay2 = pStatesTxtRecord->wOverlay[1] >= 0 ? pStatesTxtRecord->wOverlay[1] : -1;
    const int bMask = sub_0063A210_StateMaskTest(nState);

    if (nCastOverlay != -1)
    {
        nCastOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->tSeed, DATATBLS_Get1OfNFromOverlayTxt(nCastOverlay));
    }

    if (nOverlay1 != -1)
    {
        nOverlay1 += ITEMS_RollLimitedRandomNumber(&pUnit->tSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay1));
    }

    if (nOverlay2 != -1)
    {
        nOverlay2 += ITEMS_RollLimitedRandomNumber(&pUnit->tSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay2));
    }

    if (bMask)
    {
        STATES_ToggleState(pUnit, nState, 0);
        if (sub_0063A250(pUnit))
        {
            nCastOverlay = -1;
        }
        STATES_ToggleState(pUnit, nState, 1);
    }

    if (nCastOverlay != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nCastOverlay, 9, 0, nOverlay1, nOverlay2, nState, 0);
        }
        else
        {
            sub_00470390(pUnit, nCastOverlay, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
        return;
    }

    if (nOverlay1 != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nOverlay1, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            sub_00470390(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
        }
    }

    if (nOverlay2 != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nOverlay2, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            sub_00470390(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
        }
    }
}
