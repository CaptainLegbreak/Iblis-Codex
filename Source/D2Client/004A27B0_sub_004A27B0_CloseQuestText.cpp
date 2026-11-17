struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
};

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0

extern char gbGlobal_007BF2B3;                                                                              // 0x007BF2B3

// 0x004A27B0
int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue)
{
    gbGlobal_007BF2B3 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    return 0;
}

// 0x004A2C70
void __fastcall sub_004A2C70_ClearUnitFlag92(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x92)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2C90
void __fastcall sub_004A2C90_ClearUnitFlag20F(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x20F)
        pUnit->dwFlags &= ~2u;
}
