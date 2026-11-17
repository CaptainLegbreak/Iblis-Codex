struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x008[0x18];
    D2SeedStrc tSeed;
};

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex);                               // 0x00628420
unsigned char __stdcall sub_0062E8D0_HasAltInvGfx(D2UnitStrc* pItem);                                       // 0x0062E8D0

// 0x00557A70
static void sub_00557A70_RollVarInvGfx(D2UnitStrc* pItem)
{
    if (sub_0062E8D0_HasAltInvGfx(pItem))
    {
        const unsigned char nIndex = sub_00472280(&pItem->tSeed, 0, sub_0062E8D0_HasAltInvGfx(pItem));
        ITEMS_SetVarGfxIndex(pItem, nIndex);
    }
}

void sub_G07_Emit_00557A70(D2UnitStrc** ppItem)
{
    sub_00557A70_RollVarInvGfx(*ppItem);
}
