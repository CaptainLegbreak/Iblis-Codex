struct D2UnitStrc;
struct D2CofDataStrc;
struct SMSGHANDLER_PARAMS;

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int unk0x10;
    int (__stdcall* pCallback)(SMSGHANDLER_PARAMS* pMsg);
};

struct D2CofNodeStrc
{
    int nRefCount;
    unsigned int nMode;
    unsigned int nClass;
    unsigned int dwWeaponClass;
    unsigned int dwCofSize;
    D2CofDataStrc* pCofData;
    D2CofNodeStrc* pNext;
    D2CofNodeStrc* pPrev;
};

extern D2CofNodeStrc* gpCofNodeList_0087E83C;                                                               // 0x0087E83C

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);        // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);               // 0x00627260

// 0x005C33D0
int __fastcall sub_005C33D0_GetSkillValue(int nSkillId)
{
    switch (nSkillId)
    {
    case 0x17:
        return 0xA;
    case 0x1B:
        return 0xC;
    case 0x38:
        return 0xB;
    }
    return 0;
}

// 0x004FD5A0
static __forceinline int sub_004FD5A0_IsInClickRect(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    const int nTop = pClickRect->nY;
    if (nX >= pClickRect->nX && nY >= nTop - pClickRect->nHeight && nX < pClickRect->nX + pClickRect->nWidth && nY < nTop)
    {
        return 1;
    }
    return 0;
}

// 0x00503310
static __forceinline D2CofNodeStrc* sub_00503310_FindCofNode(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList_0087E83C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }
    return 0;
}

// 0x0057B7A0
static __forceinline void sub_0057B7A0_AddDefenseFromStat(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 0x78, 0);
    if (nValue)
    {
        int nNew = STATLIST_UnitGetStatValue(pDefender, 0x1F, 0) + nValue;
        if (nNew < 0)
        {
            nNew = 0;
        }
        STATLIST_SetUnitStat(pDefender, 0x1F, nNew, 0);
    }
}

int __stdcall sub_M118_Emit_004FD5A0(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    while (pClickRect && pClickRect->pCallback)
    {
        if (sub_004FD5A0_IsInClickRect(pClickRect, nX, nY))
        {
            return 1;
        }
        ++pClickRect;
    }
    return 0;
}

D2CofNodeStrc* __stdcall sub_M118_Emit_00503310(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    return sub_00503310_FindCofNode(nClass, nMode, dwWeaponClass);
}

void __stdcall sub_M118_Emit_0057B7A0(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    sub_0057B7A0_AddDefenseFromStat(pAttacker, pDefender);
}
