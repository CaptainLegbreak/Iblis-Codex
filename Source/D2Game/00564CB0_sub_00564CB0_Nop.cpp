struct D2UnitStrc;
struct D2GameStrc;

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
void __fastcall sub_6FC4B830(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FA40
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer);                 // 0x00568640

// 0x00564CB0
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit)
{
}

// 0x00567330
void __fastcall sub_6FC92EF0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_ResetInteractInfo(pUnit);
    sub_6FC4B830(pGame, pUnit);
}

// 0x00568760
void __fastcall sub_00568760_ResetPlayerInteract(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PLRTRADE_StopAllPlayerInteractions(pGame, pUnit);
}

// 0x00568D80
int __fastcall sub_00568D80_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}
