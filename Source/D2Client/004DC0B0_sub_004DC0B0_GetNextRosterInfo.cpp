struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned int dwPartyFlags;
    D2RosterInfoStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x004DC0B0
D2RosterInfoStrc* __fastcall sub_004DC0B0_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo)
{
    if (!pRosterInfo)
    {
        return 0;
    }
    return pRosterInfo->pNext;
}

// 0x004DC2B0
void __fastcall sub_004DC2B0_FreeRosterInfoList(D2RosterInfoStrc** ppRosterInfo)
{
    if (ppRosterInfo)
    {
        D2RosterInfoStrc* pRosterInfo = *ppRosterInfo;
        while (pRosterInfo)
        {
            D2RosterInfoStrc* pNext = pRosterInfo->pNext;
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x3C, 0);
            pRosterInfo = pNext;
        }
        FOG_Free(ppRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x40, 0);
    }
}
