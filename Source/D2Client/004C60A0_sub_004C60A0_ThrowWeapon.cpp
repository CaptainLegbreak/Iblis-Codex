struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
D2UnitStrc* __stdcall sub_00623990_GetWeapon(D2UnitStrc* pUnit, int nArg);                                  // 0x00623990
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem);                                                      // 0x006288A0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

// 0x004C60A0
int __fastcall sub_004C60A0_ThrowWeapon(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    int nX;
    int nY;
    D2UnitStrc* pItem;
    int nMissile;

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    pItem = sub_00623990_GetWeapon(pUnit, 0);
    if (!pItem)
    {
        return 0;
    }

    nMissile = ITEMS_GetMissileType(pItem);
    if (ITEMS_GetItemType(pItem) == 0x26)
    {
        sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY);
        sub_004CDC30(pUnit, nMissile, 0, 0, nX, nY, nSkillId, 1, 0);
        return 1;
    }

    sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, 1);
    return 1;
}
