struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

#pragma pack(push, 1)
struct D2PacketUnitRecordStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitId;
};
#pragma pack(pop)

struct D2AreaScanContextStrc
{
    D2UnitStrc* pSource;
    int nHits;
    void* pArg;
    int nRangeSquared;
};

struct D2AreaScanFindStrc
{
    D2UnitStrc* pFirst;
    unsigned int nBest;
    D2UnitStrc* pSecond;
    unsigned int nArgA;
    unsigned int nArgB;
    int nOut;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                            // 0x00463990
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem);                                           // 0x004C2180
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit);                                                // 0x0064F460
int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit);                                                    // 0x004C54F0
D2UnitStrc* __stdcall sub_00623990_GetWeapon(D2UnitStrc* pUnit, int nArg);                                  // 0x00623990
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

// 0x004C51B0
void __fastcall sub_004C51B0_UpdateUnitFromPacket(D2PacketUnitRecordStrc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        sub_004C2180_UpdateCursorItem(pUnit);
    }
}

// 0x004C5E20
int __fastcall sub_004C5E20_CountCallback(void* pArg, D2UnitStrc* pUnit)
{
    *(int*)((D2AreaScanContextStrc*)pArg)->pArg += 1;
    return 1;
}

// 0x004C5E70
int __fastcall sub_004C5E70_FindCallback(void* pArg, D2UnitStrc* pUnit)
{
    D2AreaScanFindStrc* pFind = (D2AreaScanFindStrc*)((D2AreaScanContextStrc*)pArg)->pArg;
    const unsigned int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    if (nUnitId > pFind->nArgB && nUnitId < pFind->nBest)
    {
        pFind->nOut += 1;
        pFind->nBest = nUnitId;
        pFind->pFirst = pUnit;
        return 1;
    }
    if (nUnitId <= pFind->nArgA)
    {
        pFind->nArgA = nUnitId;
        pFind->pSecond = pUnit;
    }
    pFind->nOut += 1;
    return 1;
}

// 0x004C5F30
int __fastcall sub_004C5F30_CheckWeaponStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        if (!sub_004C54F0_CanThrow(pUnit))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
        if (pWeapon && ITEMS_CheckItemTypeId(pWeapon, 0x26))
        {
            return 0;
        }
    }
    return 1;
}

// 0x004C5F70
int __fastcall sub_004C5F70_CheckThrowStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_004C54F0_CanThrow(pUnit))
    {
        return 0;
    }
    return sub_00623990_GetWeapon(pUnit, 0) != 0;
}
