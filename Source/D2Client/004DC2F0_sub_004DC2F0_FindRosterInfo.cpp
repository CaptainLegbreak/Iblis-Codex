struct D2UnitStrc;

struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned short wPartyFlags;
    unsigned short wPartyFlagsHigh;
    D2RosterInfoStrc* pNext;
};

D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId);                                  // 0x0047A310
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_00471450(D2UnitStrc* pUnit);                                                             // 0x00471450

// 0x004DC2F0
static __forceinline D2RosterInfoStrc* sub_004DC2F0_FindRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo;
        }
    }
    return 0;
}

D2RosterInfoStrc* __stdcall sub_M121_Emit_004DC2F0(int nUnitId1, int nUnitId2) { return sub_004DC2F0_FindRosterInfo(nUnitId1, nUnitId2); }

// 0x004DC380
void __fastcall sub_004DC380_RemoveRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    D2RosterInfoStrc* pPrevious = 0;
    if (!ppRosterInfo)
    {
        return;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pRosterInfo->pNext;
            }
            else
            {
                *ppRosterInfo = pRosterInfo->pNext;
            }
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x97, 0);
            return;
        }
        pPrevious = pRosterInfo;
    }
}

// 0x004DC480
unsigned short __fastcall sub_004DC480_GetRosterFlags16(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->wPartyFlags;
        }
    }
    return 0;
}

// 0x004DCA20
int __fastcall sub_004DCA20_Forward(D2UnitStrc* pUnit)
{
    return sub_00471450(pUnit);
}
