struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

#define UNITFLAG_DOUPDATE 0x00000001

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

void __fastcall sub_6FC42050(D2UnitStrc* pItem, D2ClientStrc* pClient);                                     // 0x0055BED0

// 0x0055BF30
void __fastcall sub_6FC420B0(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (pItem && UNIT_HasFlag(pItem, UNITFLAG_DOUPDATE))
    {
        sub_6FC42050(pItem, pClient);
    }
}
