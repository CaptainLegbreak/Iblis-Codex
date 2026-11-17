struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;
};

#define STAT_STATPTS 4
#define STAT_NEWSKILLS 5

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
void* gpGlobal_007C02DC;                                                                                    // 0x007C02DC
void* gpGlobal_007C02E0;                                                                                    // 0x007C02E0
extern "C" int gnFlag_007C02EC;                                                                             // 0x007C02EC

// 0x004A6460
void __cdecl sub_004A6460_LoadLevelCels()
{
    gpGlobal_007C02DC = sub_004520C0_LoadUiCelFile("Panel\\Level");
    gpGlobal_007C02E0 = sub_004520C0_LoadUiCelFile("Panel\\Levelsocket");
}

// 0x004A6480
void __cdecl sub_004A6480_FreeLevelCels()
{
    if (gpGlobal_007C02DC)
    {
        sub_00478A00(gpGlobal_007C02DC);
        gpGlobal_007C02DC = 0;
    }
    if (gpGlobal_007C02E0)
    {
        sub_00478A00(gpGlobal_007C02E0);
        gpGlobal_007C02E0 = 0;
    }
}

// 0x004A64C0
void __cdecl sub_004A64C0_UpdateStatButtons()
{
    if (sub_004538D0(0xB))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (sub_004538D0(6))
    {
        if (!STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
            sub_00455F20(6, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0) && !sub_004538D0(2))
            sub_00455F20(6, 0, 0);
    }
    if (sub_004538D0(7))
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) <= 0)
            sub_00455F20(7, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) > 0 && !sub_004538D0(4))
            sub_00455F20(7, 0, 0);
    }
}

// 0x004A65E0
int __cdecl sub_004A65E0_IsMouseOnLeftButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 - 0xC2 && nX < gnGlobal_0071146C / 2 - 0xA0 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A6690
int __cdecl sub_004A6690_IsMouseOnRightButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 + 0xA3 && nX < gnGlobal_0071146C / 2 + 0xC5 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A7660
int __fastcall sub_004A7660_SplitAtNewline(Unicode* wszText, Unicode** ppNext)
{
    Unicode* pChar = wszText;
    *ppNext = 0;
    int nLen = sub_00526800(wszText);
    int i = 0;
    while (pChar->wChar)
    {
        if (pChar->wChar == '\n')
        {
            wszText[i].wChar = 0;
            if (i >= nLen)
                return 0;
            *ppNext = pChar + 1;
            return 1;
        }
        ++pChar;
        ++i;
    }
    return 0;
}

// 0x004A7A90
void __cdecl sub_004A7A90_SetFlag()
{
    gnFlag_007C02EC = 1;
}

// 0x004A7AD0
void __cdecl sub_004A7AD0()
{
}
