struct D2DynamicPathStrc;

struct D2UnitStrc
{
    char unk0x00[0x2C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xC4 - 0x30];
    unsigned int dwFlags;
};

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970

inline int UNITS_GetFlag21Inl(D2UnitStrc* pUnit)
{
    return (pUnit->dwFlags >> 21) & 1;
}

// 0x004804A0
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    return D2Common_10142(pPath, pUnit, UNITS_GetFlag21Inl(pUnit));
}
