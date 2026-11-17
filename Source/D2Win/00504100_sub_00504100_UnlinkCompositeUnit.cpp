struct D2CompositeUnitStrc
{
    char unk0x00[0xC4];
    D2CompositeUnitStrc* pNext;
    D2CompositeUnitStrc* pPrev;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern D2CompositeUnitStrc* gpCompositeUnitList_0087E838;                                                   // 0x0087E838

// 0x00504100
void __fastcall sub_00504100_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit)
{
    D2CompositeUnitStrc* pPrev = pCompositeUnit->pPrev;
    D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
    if (!pPrev)
    {
        gpCompositeUnitList_0087E838 = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }
    FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0x85A, 0);
}
