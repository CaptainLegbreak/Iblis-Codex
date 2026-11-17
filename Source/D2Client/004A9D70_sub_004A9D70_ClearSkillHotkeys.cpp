struct D2SkillsTxt
{
    short nSkillId;
};

extern int gnTable_007C04E0[60];                                                                            // 0x007C04E0
extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0

// 0x004A9D70
void __stdcall sub_004A9D70_ClearSkillHotkeys(D2SkillsTxt* pSkillsTxt, int nQuantity)
{
    int i = 0;
    while (i < 60)
    {
        if (gnTable_007C04E0[i] != pSkillsTxt->nSkillId)
        {
            ++i;
            continue;
        }

        for (int nSlot = 0; nSlot < 16; ++nSlot)
        {
            if (gnHotkeySkill_007C06C8[nSlot] == gnTable_007C04E0[i] && nQuantity <= 0)
            {
                gnHotkeySkill_007C06C8[nSlot] = -1;
                gbHotkeyLeft_007C07B8[nSlot] = -1;
                gnHotkeyOwner_007C0768[nSlot] = -1;
                sub_004786A0_SendIntInt(0x51, (nSlot << 16) + 0xFFFF, -1);
            }
        }

        ++i;
    }
}
