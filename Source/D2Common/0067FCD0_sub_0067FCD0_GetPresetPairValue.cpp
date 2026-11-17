struct D2PresetPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2DrlgOutRectStrc
{
    int nX;
    int nY;
    int unk0x08;
    unsigned char nFlags;
    char pad0x0D[3];
    D2DrlgOutRectStrc* pBounds;
};

extern D2PresetPairStrc gaPresetPairs_006F2680[];                                                           // 0x006F2680

void __stdcall sub_M127_EmitSink(int nValue);

// 0x0067FCD0
static __forceinline int __stdcall sub_0067FCD0_GetPresetPairValue(int bFirst, int nIndex, unsigned int nFlags)
{
    if (nIndex)
    {
        if (nIndex == 7 && (nFlags & 0xF0000) == 0x30000)
        {
            return nIndex - 4;
        }
        if (bFirst)
        {
            return gaPresetPairs_006F2680[nIndex].nFirst;
        }
        return gaPresetPairs_006F2680[nIndex].nSecond;
    }
    return (nFlags & 0x100) ? 0 : 3;
}

// 0x0067FFB0
static __forceinline int sub_0067FFB0_IsRectAdjacent(D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther)
{
    D2DrlgOutRectStrc* pBounds = pRect->pBounds;
    if (pRect->nX < pBounds->nX && pOther->nY > pRect->nY && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    if (pRect->nY > pBounds->nY && pOther->nX > pRect->nX && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    return 0;
}

void __fastcall sub_M127_Emit_0067FCD0(int nValue, D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther, unsigned int nFlags)
{
    sub_M127_EmitSink(sub_0067FCD0_GetPresetPairValue(nValue & 1, nValue, nFlags));
    for (D2DrlgOutRectStrc* p = pOther; p; p = p->pBounds)
    {
        sub_M127_EmitSink(sub_0067FFB0_IsRectAdjacent(pRect, p));
    }
}

#include "gen/data/Source/D2Common/0067FCD0_sub_0067FCD0_GetPresetPairValue.inc"
