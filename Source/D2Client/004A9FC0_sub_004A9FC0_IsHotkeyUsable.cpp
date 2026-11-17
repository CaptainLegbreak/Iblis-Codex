struct D2UnitStrc;
struct D2SkillStrc;

extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
int gnSelectedHotkey_007C0708;                                                                              // 0x007C0708
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
int __stdcall sub_00643B00(D2SkillStrc* pSkill, int a2, int a3, int a4, int* pCharges);          // 0x00643B00
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

// 0x004A9FC0
static int sub_004A9FC0_IsHotkeyUsable(int nSlot)
{
    if (gnHotkeySkill_007C06C8[nSlot] == -1)
        return 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return 0;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
    if (!pSkill)
        return 0;
    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        int nCharges;
        if (sub_00643B00(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
            return 0;
    }
    return 1;
}

// 0x004AA030
void __fastcall sub_004AA030_SelectHotkey(int nSlot)
{
    if (gnHotkeySkill_007C06C8[nSlot] == -1)
        return;
    if (!sub_004A9FC0_IsHotkeyUsable(nSlot))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0();
    gnSelectedHotkey_007C0708 = nSlot;
    sub_004786A0_SendIntInt(0x3C, (gbHotkeyLeft_007C07B8[nSlot] ? 0x80000000 : 0) + gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
    if (gbHotkeyLeft_007C07B8[nSlot])
        SKILLS_SetLeftActiveSkill(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
    else
        SKILLS_SetRightActiveSkill(pPlayer, gnHotkeySkill_007C06C8[nSlot], gnHotkeyOwner_007C0768[nSlot]);
}

// 0x004AA740
void __fastcall sub_004AA740_CycleHotkey(int nDelta)
{
    if (sub_00463DF0())
        return;
    const int nStep = (nDelta > 0) * 2 - 1;
    if (nDelta < 0)
        nDelta = -nDelta;
    if (!nDelta)
        return;
    int nFound = -1;
    int nSlot = gnSelectedHotkey_007C0708 + nStep;
    for (int i = 0; i < 16; ++i, nSlot += nStep)
    {
        if (nSlot < 0)
            nSlot = 15;
        else if (nSlot >= 16)
            nSlot = 0;
        if (gnHotkeySkill_007C06C8[nSlot] != -1 && !gbHotkeyLeft_007C07B8[nSlot] && sub_004A9FC0_IsHotkeyUsable(nSlot))
        {
            nFound = nSlot;
            if (!--nDelta)
                break;
        }
    }
    if (nFound != -1)
        sub_004AA030_SelectHotkey(nFound);
}
