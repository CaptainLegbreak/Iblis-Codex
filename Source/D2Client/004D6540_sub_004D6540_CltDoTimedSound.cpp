struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    char unk0x20[0x08];
    char unk0x28[0x1C];
    int dwGFXcurrentFrame;
    char unk0x48[0x04];
    short wAnimSpeed;
};

enum
{
    CLTDO_TIMING_FRAME = 150,
    CLTDO_TIMING_ARG = 25,
    CLTDO_TIMING_LENGTH = 4000,
    CLTDO_SOUND_FRAME = 50,
    CLTDO_SOUND_ID = 0x121E,
    CLTDO_SLOW_FRAME = 8,
    CLTDO_SLOW_FLAG = 0x100,
    CLTDO_FAST_FRAME = 35,
};

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                        // 0x00476A80
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg);                                  // 0x00621780
void __stdcall sub_004DA250(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA250

// 0x004D6540
void __fastcall sub_004D6540_CltDoTimedSound(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    if (nFrames == CLTDO_TIMING_FRAME)
    {
        sub_00476A80_StartTiming(CLTDO_TIMING_ARG, 0, CLTDO_TIMING_LENGTH, 0);
    }
    else if (nFrames == CLTDO_SOUND_FRAME)
    {
        sub_004B9A00(CLTDO_SOUND_ID, 0, 0, 0, 0);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6590
void __fastcall sub_004D6590_CltDoAnimSpeedSteps(D2UnitStrc* pMissile)
{
    switch (sub_0064A3B0_GetElapsedFrames(pMissile))
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6660
void __fastcall sub_004D6660_CltDoClearFrameWithOwner(D2UnitStrc* pMissile)
{
    if (sub_004639D0_GetOwnerUnit(pMissile))
    {
        pMissile->dwGFXcurrentFrame = 0;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
