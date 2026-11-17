#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId[18];
    short wAnimSpeed;
};

// 0x0064A690
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed)
{
    if (pMissile && pMissile->dwUnitType == 3)
    {
        pMissile->wAnimSpeed = D2_MIN(D2_MAX(nAnimSpeed, -32768), 32767);
    }
}
