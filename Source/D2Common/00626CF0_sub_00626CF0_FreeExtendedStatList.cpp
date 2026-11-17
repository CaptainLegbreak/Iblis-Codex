struct D2StatListStrc
{
    char unk0x00[16];
    unsigned int dwFlags;
};

void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList);                     // 0x00626C00

#define STATLIST_EXTENDED 0x80000000
inline int STATLIST_IsExtended(D2StatListStrc* pStatList)
{
    return pStatList->dwFlags & STATLIST_EXTENDED;
}

// 0x00626CF0
void __fastcall sub_00626CF0_FreeExtendedStatList(D2StatListStrc* pStatList)
{
    if (pStatList && STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
    }
}
