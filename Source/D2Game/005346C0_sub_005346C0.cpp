struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x1120];
    D2UnitStrc* pUnitList[5][128];
};

struct D2Game5347F0Strc
{
    char unk0x00[0x0C];
    int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2GameStrc* __cdecl sub_0052F6E0_LockFirstGame();                                                          // 0x0052F6E0
void __cdecl sub_0052DF40_UnlockFirstGame();                                                               // 0x0052DF40
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __cdecl sub_005449D0_ClearByte();                                                                      // 0x005449D0

// 0x005346C0
int __stdcall sub_005346C0()
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();

    D2_ASSERT(pGame, 0x7B);

    int nIndex = 0;
    for (int i = 0; i < 128; ++i)
    {
        for (D2UnitStrc* pUnit = pGame->pUnitList[1][i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
        {
            ++nIndex;
        }
    }

    sub_0052DF40_UnlockFirstGame();
    return nIndex;
}

// 0x00534790
void __cdecl sub_00534790_ClearByte()
{
    sub_005449D0_ClearByte();
}

// 0x005347A0
char* __fastcall sub_005347A0_ClearText(int nUnused, char* szText)
{
    *szText = 0;
    return szText;
}

// 0x005347F0
void __fastcall sub_005347F0_SetField0C(D2Game5347F0Strc* pRecord, int nValue)
{
    if (pRecord)
    {
        pRecord->nValue = nValue;
    }
}
