struct D2CmpTileNodeStrc
{
    unsigned short nX;
    unsigned short nY;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short nFormat;
    unsigned short nSize;
    short unk0x0A;
    unsigned char* pData;
    D2CmpTileNodeStrc* pNext;
};

struct D2CmpTileSubStrc
{
    unsigned short nX;
    unsigned short nY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    short nFormat;
    unsigned short nSize;
    int unk0x0C;
    unsigned char* pData;
};

// 0x00609BF0
static __declspec(noinline) void sub_00609BF0_CopyTileNode(D2CmpTileSubStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    pSub->nX = pNode->nX;
    pSub->nY = pNode->nY;
    pSub->nGridX = pNode->nGridX;
    pSub->nGridY = pNode->nGridY;
    pSub->nFormat = pNode->nFormat;
    pSub->nSize = pNode->nSize;
    pSub->pData = pNode->pData;
    pNode->pData = 0;
}

void __fastcall sub_M289_Emit_00609BF0(D2CmpTileSubStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    sub_00609BF0_CopyTileNode(pSub, pNode);
}
