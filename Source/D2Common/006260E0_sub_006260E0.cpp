struct D2SkillStrc;
struct D2SkillListStrc;
struct D2PlayerDataStrc;
struct D2StatListStrc
{
    char unk0x00[16];
    unsigned int dwFlags;
    char unk0x14[8];
    D2SkillStrc* pSkill;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[12];
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[68];
    D2StatListStrc* pStatListEx;
    char unk0x60[72];
    D2SkillListStrc* pSkills;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList);                     // 0x00626C00
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList);                                 // 0x006269F0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627030

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STATLIST_EXTENDED 0x80000000
inline int STATLIST_IsExtended(D2StatListStrc* pStatList)
{
    return pStatList->dwFlags & STATLIST_EXTENDED;
}

// 0x006260E0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc* pStatList)
{
    return pStatList->pSkill;
}

// 0x00626CD0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList)
{
    if (pStatList && !STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
    }
}

// 0x00626D10
void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit)
{
    if (pUnit->pStatListEx)
    {
        if (STATLIST_IsExtended(pUnit->pStatListEx))
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pUnit->pStatListEx);
        }

        pUnit->pStatListEx = 0;
    }
}

// 0x006272B0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer)
{
    if (nValue)
    {
        STATLIST_AddStat(pUnit->pStatListEx, nStatId, nValue, nLayer);
    }
}

// 0x006277E0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList)
{
    D2Common_ExpireStatList_6FDB6E30(pStatList);
}

// 0x006277F0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pStatListEx)
    {
        D2Common_ExpireStatList_6FDB6E30(pUnit->pStatListEx);
    }
}
