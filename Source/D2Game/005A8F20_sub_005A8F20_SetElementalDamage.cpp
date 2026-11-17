struct D2GameStrc;
struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
};
struct D2DamageStrc
{
    unsigned char unk_00[0x18];
    int n18;
    unsigned char unk_1C[0x10];
    int n2C;
    int n30;
    int n34;
    unsigned char unk_38[0xC];
    int n44;
};
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

// 0x005A8F20
void __fastcall sub_005A8F20_SetElementalDamage(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, D2DamageStrc* pDamage, int nValue)
{
    if (pMissile)
    {
        switch (MISSILE_GetElemTypeFromMissileId(!pMissile ? -1 : pMissile->dwClassId))
        {
        case 4:
            pDamage->n30 = nValue;
            break;
        case 5:
            pDamage->n2C = nValue;
            break;
        case 9:
            pDamage->n44 = nValue;
            break;
        case 11:
            pDamage->n18 = nValue;
            break;
        case 12:
            pDamage->n34 = nValue;
            break;
        }
    }
}
