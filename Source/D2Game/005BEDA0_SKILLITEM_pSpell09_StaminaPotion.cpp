struct D2UnitStrc;
struct D2GameStrc;
struct D2StatListStrc;
struct D2ItemStatCostTxt;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2ItemsTxt
{
    char unk0x000[0x98];
    short wState;
    short wCurseState[2];
    short wStat[3];
    unsigned int dwCalc[3];
    unsigned int dwLen;
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xB0C];
    int nItemStatCostTxtRecordCount;
};

enum D2C_Z09ItemConstants
{
    UNIT_INVALID = 6,
    EVENTTYPE_REMOVESTATE = 0x0C,
    STAT_STAMINA = 0x0A,
    STAT_MAXSTAMINA = 0x0B,
    STAT_STAMINARECOVERYBONUS = 0x1C,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc);       // 0x00627C20
void __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nState, int a3);                                        // 0x0056C740
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList);                                                    // 0x00626090
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x005BEDA0
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nState = pItemsTxtRecord->wState;
    if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    if (nLength <= 0)
    {
        return 0;
    }

    sub_6FD11C90(pUnit, nState, 0);

    int nRemaining = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        nRemaining = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }

    const int nEndFrame = pGame->dwGameFrame + nRemaining + nLength;

    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nState);
        STATES_ToggleState(pUnit, nState, 1);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    if (nEndFrame)
    {
        D2COMMON_10476(pStatList, nEndFrame);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nEndFrame, 0, 0);
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount && sub_0045C4F0_GetItemStatCostTxtRecord(nStatId))
        {
            const int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_STAMINARECOVERYBONUS && nValue > 0)
                {
                    const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
                    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
                    {
                        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina + 0x100, 0);
                    }
                }
            }
        }
    }

    return 1;
}
