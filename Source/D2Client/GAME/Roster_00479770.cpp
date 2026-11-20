#include "D2ClientGame.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct D2StoredUnitRecordStrc;

static D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                          // 0x007BB5C8
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

static __forceinline D2RosterGroupStrc* ROSTER_FindGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wPartyId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

static __declspec(noinline) D2RosterGroupStrc* sub_00479770_GetOrAddGroup(unsigned short wId);

// 0x00479770
static D2RosterGroupStrc* sub_00479770_GetOrAddGroup(unsigned short wId)
{
    D2RosterGroupStrc* pGroup = ROSTER_FindGroup(wId);
    if (pGroup)
    {
        return pGroup;
    }
    pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), ".\\GAME\\Roster.cpp", 0x1FC, 0);
    memset(pGroup, 0, 8);
    pGroup->wPartyId = wId;
    pGroup->pNext = gpRosterGroups_007BB5C8;
    gpRosterGroups_007BB5C8 = pGroup;
    return pGroup;
}

// calling-convention shim (not game code)
void __fastcall sub_00479770_Shim(unsigned short* pIds, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        sub_00479770_GetOrAddGroup(pIds[i])->unk0x02 = 1;
    }
}
