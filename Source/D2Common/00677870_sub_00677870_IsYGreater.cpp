struct D2PosStrc
{
    int nX;
    int nY;
};

static __declspec(noinline) int sub_00677870_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2);

// 0x00677870
static int sub_00677870_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return pPos1->nY > pPos2->nY;
}

int __fastcall sub_00677870_Emit(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return sub_00677870_IsYGreater(pPos1, pPos2);
}
