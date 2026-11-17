struct D2UnitStrc
{
    char unk0x00[0xE4];
    D2UnitStrc* pListNext;
};

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_00463CC0_FreeUnitTable(D2UnitStrc** ppTable);                                            // 0x00463CC0
void __fastcall sub_00480810_OnUnitA(D2UnitStrc* pUnit);                                                    // 0x00480810
void __fastcall sub_00463D80_OnUnitB(D2UnitStrc* pUnit);                                                    // 0x00463D80
void __fastcall sub_00465070_OnUnitC(D2UnitStrc* pUnit);                                                    // 0x00465070

D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                             // 0x007A5270
D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                             // 0x007A5E70

#define gpUnitTable_007A5470 (gpUnitHashTable_007A5270 + 1 * 0x80)
#define gpUnitTable_007A5670 (gpUnitHashTable_007A5270 + 2 * 0x80)
#define gpUnitTable_007A5870 (gpUnitHashTable_007A5270 + 3 * 0x80)
#define gpUnitTable_007A5E70 (gpUnitHashTable_007A5E70 + 0 * 0x80)
#define gpUnitTable_007A6070 (gpUnitHashTable_007A5E70 + 1 * 0x80)
#define gpUnitTable_007A6270 (gpUnitHashTable_007A5E70 + 2 * 0x80)
#define gpUnitTable_007A6470 (gpUnitHashTable_007A5E70 + 3 * 0x80)
#define gpUnitTable_007A6670 (gpUnitHashTable_007A5E70 + 4 * 0x80)
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610

// 0x00463C90
static void __stdcall sub_00463C90_ForEachUnitInTable(D2UnitStrc** ppTable, UNITFN pfnCallback)
{
    for (int i = 0; i < 0x80; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            pfnCallback(pUnit);
            pUnit = pNext;
        }
    }
}

// 0x00464950
void __fastcall sub_00464950(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x961);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, pfnCallback);
}

// 0x00464990
void __fastcall sub_00464990(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x96C);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, pfnCallback);
}

// 0x004649D0
void __fastcall sub_004649D0(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x977);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6270, pfnCallback);
}

static __forceinline void WalkUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < 0x80; ++i)
    {
        for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
        {
        }
    }
}

// 0x00465AA0
void __cdecl sub_00465AA0_ResetUnitTables()
{
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6470, sub_00480810_OnUnitA);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5870);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5670);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6270, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6670, sub_00480810_OnUnitA);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A6670);
    WalkUnitTable(gpUnitTable_007A5E70);
    WalkUnitTable(gpUnitTable_007A6070);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5470, sub_00463D80_OnUnitB);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6670, sub_00463D80_OnUnitB);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00463D80_OnUnitB);
    if (!gdwGlobal_007A0610)
    {
        sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00465070_OnUnitC);
        sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, sub_00465070_OnUnitC);
    }
}
