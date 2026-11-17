extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2RosterInfoStrc;
struct D2RosterCorpseStrc;
struct D2StoredUnitRecordStrc;

struct D2StoredUnitRecordStrc
{
    char szName[16];
    int dwUnitId;
    int dwPartyLife;
    int dwKillCount;
    int dwClassId;
    unsigned short wLevel;
    unsigned short wPartyId;
    int dwLevelId;
    int dwPosX;
    int dwPosY;
    int dwPartyFlags;
    D2RosterInfoStrc** pRosterInfo;
    D2RosterCorpseStrc* pCorpse;
    int dwPortalA;
    int dwPortalB;
    unsigned short wGuildFlags;
    char szGuildTag[4];
    char szGuildName[28];
    char szNameEx[26];
    D2StoredUnitRecordStrc* pNext;
};

struct D2RosterGroupStrc
{
    unsigned short wPartyId;
    unsigned short unk0x02;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

extern "C" const char szRosterCpp_006D7268[];                                                               // 0x006D7268
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

static D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                      // 0x007BB5C0
static D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                          // 0x007BB5C8

static __declspec(noinline) void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup);

// 0x00479800
static void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRecord = gpStoredUnits_007BB5C0;
    while (pRecord)
    {
        if (pRecord->wPartyId == pGroup->wPartyId)
        {
            D2StoredUnitRecordStrc* pMoved = pRecord;
            pRecord = pRecord->pNext;
            if (pPrev)
                pPrev->pNext = pRecord;
            else
                gpStoredUnits_007BB5C0 = pRecord;
            pMoved->pNext = pGroup->pFirst;
            pGroup->pFirst = pMoved;
        }
        else
        {
            pPrev = pRecord;
            pRecord = pRecord->pNext;
        }
    }
}

// build: context sub_00479940_BuildRosterGroups
void __cdecl sub_00479940_BuildRosterGroups()
{
    while (gpStoredUnits_007BB5C0)
    {
        const unsigned short wPartyId = gpStoredUnits_007BB5C0->wPartyId;
        D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8;
        while (pGroup)
        {
            if (pGroup->wPartyId == wPartyId)
                break;
            pGroup = pGroup->pNext;
        }
        if (!pGroup)
        {
            pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), szRosterCpp_006D7268, 0x1FC, 0);
            memset(pGroup, 0, 8);
            pGroup->wPartyId = wPartyId;
            pGroup->pNext = gpRosterGroups_007BB5C8;
            gpRosterGroups_007BB5C8 = pGroup;
        }
        sub_00479800_MoveGroupMembers(pGroup);
    }
}
