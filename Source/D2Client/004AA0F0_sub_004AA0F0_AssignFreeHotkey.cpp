struct D2UnitStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
};

struct D2HotkeySlotTableStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300;                                                        // 0x007C0300
extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
extern int gbGlobal_007C07FC;                                                                               // 0x007C07FC

// 0x004AA0F0
static void sub_004AA0F0_AssignFreeHotkey(int nSlot, int nIndex)
{
    if (nSlot >= 16)
        return;
    if (gnHotkeySkill_007C06C8[nSlot] != -1)
        return;

    gnHotkeySkill_007C06C8[nSlot] = gtHotkeySlots_007C0300.nSkill[nIndex];
    if (!gbGlobal_007C07FC)
        gbHotkeyLeft_007C07B8[nSlot] = 0;
    else
        gbHotkeyLeft_007C07B8[nSlot] = 1;
    gnHotkeyOwner_007C0768[nSlot] = gtHotkeySlots_007C0300.f_2D0[nIndex];
    sub_004786A0_SendIntInt(0x51, (nSlot << 16) + (gbHotkeyLeft_007C07B8[nSlot] ? 0x8000 : 0) + gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
}

// 0x004AA160
void __cdecl sub_004AA160_FillHotkeys()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(UNITS_GetStartSkill(pPlayer), 0x524);
    int nSlot = 0;
    for (int i = 0; i < 60; ++i)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, gtHotkeySlots_007C0300.nSkill[i]);
        if (!pSkill)
            continue;
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (!pSkillsTxt)
            continue;
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
            continue;
        if (nSlot > 15)
            continue;
        sub_004AA0F0_AssignFreeHotkey(nSlot, i);
        ++nSlot;
    }
}
