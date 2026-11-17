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
    CLTDO_SLOW_FRAME = 8,
    CLTDO_FAST_FRAME = 0x23,
    CLTDO_SLOW_FLAG = 0x100,
};

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg);                                  // 0x00621780
void __stdcall sub_004DA250(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA250

// 0x004CD290
static __forceinline void sub_004CD290_CltAnimSpeedSteps(D2UnitStrc* pMissile, int nFrame)
{
    switch (nFrame)
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }
}

void __fastcall sub_M130_Emit_004CD290(D2UnitStrc* pMissile)
{
    sub_004CD290_CltAnimSpeedSteps(pMissile, sub_0064A3B0_GetElapsedFrames(pMissile));
}
