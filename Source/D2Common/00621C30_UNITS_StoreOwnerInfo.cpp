struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x04];
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x4C];
    void* pStatListEx;
    char unk0x60[0x34];
    int dwOwnerType;
    int dwOwnerGUID;
    char unk0x9C[0x2C];
    unsigned int dwFlagEx;
};

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwState);                  // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);

static __forceinline int sub_T03_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitType;
}

static __forceinline int sub_T03_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

static __forceinline void* sub_M442_GetMemPool(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->pMemoryPool;
}

// 0x00621C30
static void __stdcall UNITS_StoreOwnerInfo(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    D2StatListStrc* pStatList = 0;

    if (pUnit)
    {
        pUnit->dwOwnerType = nOwnerType;
        pUnit->dwOwnerGUID = nOwnerId;

        if (pUnit->pStatListEx)
        {
            STATES_ToggleState(pUnit, 0x62, 1);
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(sub_M442_GetMemPool(pUnit), 0, 0, sub_T03_GetUnitType(pUnit), sub_T03_GetUnitId(pUnit));
                if (!pStatList)
                    return;

                sub_006252D0(pStatList, 0x62);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, 0x161, nOwnerType, 0);
            STATLIST_SetStatIfListIsValid(pStatList, 0x162, nOwnerId, 0);
        }

        pUnit->dwFlagEx |= 0x400;
    }
}

void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    UNITS_StoreOwnerInfo(pUnit, nOwnerType, nOwnerId);
}

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    D2StatListStrc* pStatList = 0;

    if (pOwner)
    {
        UNITS_StoreOwnerInfo(pUnit, sub_T03_GetUnitType(pOwner), sub_T03_GetUnitId(pOwner));
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwOwnerType = 0;
            pUnit->dwOwnerGUID = 0;

            if (pUnit->pStatListEx)
            {
                STATES_ToggleState(pUnit, 0x62, 0);

                pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }

            pUnit->dwFlagEx &= ~0x400;
        }
    }
}
