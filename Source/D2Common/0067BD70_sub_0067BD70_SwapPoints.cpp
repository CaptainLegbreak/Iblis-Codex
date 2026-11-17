struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

// 0x0067BD70
static __forceinline void sub_0067BD70_SwapPoints(D2PathPointStrc* pA, D2PathPointStrc* pB)
{
    const D2PathPointStrc tPoint = *pA;
    *pA = *pB;
    *pB = tPoint;
}

void __fastcall sub_M110_Emit_0067BD70(D2PathPointStrc* pPoints, int nCount)
{
    sub_0067BD70_SwapPoints(pPoints, pPoints + nCount);
}
