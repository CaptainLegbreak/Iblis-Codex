struct D2DrlgRouteNodeStrc
{
    int unk0x00[5];
    int nTries;
    unsigned char* pTurn;
    unsigned char nDirection;
    unsigned char unk0x1D[3];
    D2DrlgRouteNodeStrc* pParent;
};

static __declspec(noinline) D2DrlgRouteNodeStrc* __stdcall sub_00681560(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart);

// 0x00681560
static D2DrlgRouteNodeStrc* __stdcall sub_00681560(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart)
{
    if (pNode->nTries < 4)
    {
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
    }
    ++pNode->nTries;

    while (pNode->nTries == 3)
    {
        if (pNode == *ppStart)
        {
            return 0;
        }

        pNode = pNode->pParent;
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
        ++pNode->nTries;
    }

    return pNode;
}

// build: context sub_00681560_Shim
// calling-convention shim (not game code)
D2DrlgRouteNodeStrc* __stdcall sub_00681560_Shim(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart)
{
    return sub_00681560(pNode, ppStart);
}
