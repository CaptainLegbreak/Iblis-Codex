struct D2UnitStrc;

struct D2SlotStrc
{
    int unk0x00;
    int nClass;
    int unk0x08;
};

struct D2SlotOwnerStrc
{
    char unk0x00[0x20];
    D2SlotStrc* pSlots;
};

int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
void __fastcall sub_00464950(void (__fastcall* pfnCallback)(D2UnitStrc*));                                  // 0x00464950
void __fastcall sub_00453330_DrawPartyMemberText(D2UnitStrc* pUnit);                                        // 0x00453330
int __cdecl sub_004B85E0();                                                                                 // 0x004B85E0
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0

// 0x004535D0
void __cdecl sub_004535D0_DrawPartyTexts()
{
    if (sub_0044DB30())
    {
        sub_00464950(sub_00453330_DrawPartyMemberText);
    }
}

// 0x004535F0
static __forceinline void __stdcall sub_004535F0_SetSlotClass(D2SlotOwnerStrc* pOwner, unsigned short wDefault, int nIndex, int nA, int nB)
{
    if (nIndex == -1)
    {
        return;
    }

    int nValue;
    unsigned short wClass;
    if (sub_00469D90(nA, nB) && (wClass = sub_00469AA0(nA, nB)) != 0xFFFF && wClass <= 0xDF)
    {
        nValue = wClass;
    }
    else
    {
        nValue = wDefault;
    }

    pOwner->pSlots[nIndex].nClass = nValue;
}

void __fastcall sub_M117_Emit_004535F0(D2SlotOwnerStrc* pOwner, int nIndex, int nA, int nB)
{
    sub_004535F0_SetSlotClass(pOwner, 0x1234, nIndex, nA, nB);
}

// 0x00453900
int __cdecl sub_00453900_IsActive()
{
    return sub_004B85E0() != 0;
}
