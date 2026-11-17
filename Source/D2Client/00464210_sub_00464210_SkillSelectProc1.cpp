struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x64];
    int nUnk0x68;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall D2COMMON_11018(D2UnitStrc* pUnit);                                                            // 0x00645590
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit);                                                            // 0x006455E0
int __stdcall sub_00645630(D2UnitStrc* pUnit);                                                            // 0x00645630
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit);                                      // 0x00645680
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

// 0x00464210
int __fastcall sub_00464210_SkillSelectProc1(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return sub_00645680_CanUnitCorpseBeSelected(pTarget);
}

// 0x00464280
int __fastcall sub_00464280_SkillSelectProc4(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11018(pTarget);
}

// 0x00464290
int __fastcall sub_00464290_SkillSelectProc6(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return sub_00645630(pTarget);
}

// 0x004642A0
int __fastcall sub_004642A0_SkillSelectProc5(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11019(pTarget);
}

// 0x004643B0
int __fastcall sub_004643B0_IsPlayerOrMonster(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x793);
    const int nType = pUnit->dwUnitType;
    return nType == 0 || nType == 1;
}

// 0x00464CC0
int __fastcall sub_00464CC0_GetField68(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA3F);
    return pUnit->nUnk0x68;
}

// 0x00464E20
static __forceinline void sub_00464E20_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay)
{
    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

void __fastcall sub_M109_Emit_00464E20(D2UnitStrc* pUnit, int nOverlay)
{
    if (pUnit)
        sub_00464E20_PlayOverlaySound(pUnit, nOverlay);
}
