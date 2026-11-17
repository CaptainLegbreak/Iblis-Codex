struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x004C1B80
void __fastcall sub_004C1B80_ItemCommand(int nEvent, D2UnitStrc* pUnit, int bSet, int nMode)
{
    switch (nEvent)
    {
    case 2:
        UNITS_ChangeAnimMode(pUnit, nMode);
        if (pUnit)
        {
            if (bSet)
            {
                pUnit->dwFlags |= 2;
            }
            else
            {
                pUnit->dwFlags &= ~2;
            }
        }
        break;
    }
}
