struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define BODYLOC_SWRARM 11
#define BODYLOC_SWLARM 12

// 0x0062ED50
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 == nBodyLoc || nBodyLoc2 == nBodyLoc
            || (nBodyLoc == BODYLOC_SWRARM || nBodyLoc == BODYLOC_SWLARM) && (nBodyLoc1 == BODYLOC_RARM || nBodyLoc2 == BODYLOC_RARM || nBodyLoc1 == BODYLOC_LARM || nBodyLoc2 == BODYLOC_LARM))
        {
            return 1;
        }
    }

    return 0;
}
