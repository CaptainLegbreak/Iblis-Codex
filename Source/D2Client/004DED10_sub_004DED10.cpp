struct D2SoundStrc;

#pragma pack(push, 1)
struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x24];
    int nField0x2C;
    int nField0x30;
    unsigned int nKey;
    char unk0x38[0x09];
    unsigned int f_41;
};
#pragma pack(pop)

struct D2SlotStrc
{
    D2SoundStrc* f_0;
    int nType;
    D2SlotObjectStrc* pObject;
    char unk0x0C[0x14];
};

struct D2HintCursorStrc
{
    char unk0x00[0x3E];
    char bField0x3E;
};

struct D2Obj007C8A28Strc
{
    void sub_004DE730(void* pArg);                                                                          // 0x004DE730
};

D2Obj007C8A28Strc gObj_007C8A28;                                                                            // 0x007C8A28
D2SlotStrc gaSlots_007C8A78[16];                                                                            // 0x007C8A78
extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78

D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
int __cdecl sub_00513B50();                                                                                 // 0x00513B50
int __fastcall sub_00515710(D2SoundStrc* pSound);                                                           // 0x00515710
int __fastcall sub_00515740_IsSoundPlaying(D2SoundStrc* pSound);                                            // 0x00515740
unsigned int __fastcall sub_005159B0_GetSoundSampleCount(D2SoundStrc* pSound);                              // 0x005159B0
int __fastcall sub_00515C30(D2SoundStrc* pSound);                                                           // 0x00515C30
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0
void __fastcall sub_005160D0_ReleaseSound(D2SoundStrc* pSound);                                             // 0x005160D0

// 0x004DED10
void __fastcall sub_004DED10(void* pArg)
{
    gObj_007C8A28.sub_004DE730(pArg);
}

// 0x004DF7B0
void __fastcall sub_004DF7B0_StopSlot(D2SlotStrc* pSlot)
{
    if (pSlot->f_0)
    {
        if (pSlot->pObject)
        {
            pSlot->pObject->f_41 = sub_005159B0_GetSoundSampleCount(pSlot->f_0);
        }

        sub_00515EE0_StopSound(pSlot->f_0);
    }

    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF800
void __cdecl sub_004DF800()
{
    if (!sub_00513B50())
    {
        return;
    }

    sub_00515CE0_SetMasterVolume(0);
    for (int i = 0; i < 16; ++i)
    {
        sub_004DF7B0_StopSlot(&gaSlots_007C8A78[i]);
    }

    sub_00515CE0_SetMasterVolume(0xFF);
}

// 0x004DF890
void __cdecl sub_004DF890()
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (pSlot->pObject && !sub_00481860(pSlot->pObject->f_4)->bField0x3E && !sub_00515710(pSlot->f_0))
        {
            if (sub_00515C30(pSlot->f_0))
            {
                sub_004DF7B0_StopSlot(pSlot);
            }

            if (pSlot->pObject)
            {
                pSlot->pObject->nField0x30 = 2;
                pSlot->pObject->nField0x2C = 0;
                pSlot->pObject = 0;
            }
        }
    }
}

// 0x004DFA40
int __fastcall sub_004DFA40_IsSlotPlaying(D2SlotStrc* pSlot)
{
    if (pSlot && pSlot->f_0)
    {
        return sub_00515740_IsSoundPlaying(pSlot->f_0);
    }

    return 0;
}

// 0x004DFA60
void __cdecl sub_004DFA60()
{
    if (gdwGlobal_007C8C78)
    {
        sub_004DF800();
        for (int i = 0; i < 16; ++i)
        {
            sub_005160D0_ReleaseSound(gaSlots_007C8A78[i].f_0);
            gaSlots_007C8A78[i].f_0 = 0;
        }

        gdwGlobal_007C8C78 = 0;
    }
}
