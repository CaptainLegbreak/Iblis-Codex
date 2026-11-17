struct D2PosStrc
{
    int nX;
    int nY;
};

struct D2OffsetPosStrc
{
    int nX;
    int nY;
    int nA;
    int nB;
    int nDir;
};

// 0x006777D0
static __declspec(noinline) void __stdcall sub_006777D0_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    int nDx = 0;
    int nDy = 0;
    switch (nDir)
    {
    case 0:
        nDx = 0;
        nDy = -nB;
        break;

    case 1:
        nDx = -nA;
        nDy = nB / -3;
        break;

    case 2:
        nDx = nA;
        nDy = nB / -3;
        break;

    case 3:
        nDx = -nA;
        nDy = -nB * 2 / 3;
        break;

    case 4:
        nDx = nA;
        nDy = -nB * 2 / 3;
        break;
    }

    pOut->nX = pBase->nX + nDx;
    pOut->nY = pBase->nY + nDy;
    pOut->nA = nA;
    pOut->nB = nB;
    pOut->nDir = nDir;
}

void __stdcall sub_W04_Emit_006777D0(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    sub_006777D0_OffsetByDirection(pBase, nDir, nA, nB, pOut);
}
