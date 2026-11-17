struct D2GameStrc;
struct D2UnitStrc;
#pragma pack(push, 1)
struct D2BuyItemPacketStrc
{
    unsigned char nHeader;
    int nNpcUnitId;
    int nItemId;
    unsigned int nTransactionType;
    int nCost;
};
#pragma pack(pop)

int __fastcall D2GAME_NPC_BuyItemHandler_6FCC92A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy); // 0x00577F30

// 0x0054BAC0
int __fastcall sub_0054BAC0_BuyItemFromNpcBuffer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2BuyItemPacketStrc* pPacket, int nSize)
{
    if (nSize != sizeof(D2BuyItemPacketStrc))
        return 3;

    unsigned int nTransactionType = pPacket->nTransactionType;
    const int nNpcUnitId = pPacket->nNpcUnitId;
    const int nItemId = pPacket->nItemId;
    const int nCost = pPacket->nCost;
    const int bMultibuy = nTransactionType & 0x80000000;
    nTransactionType &= 0x7FFFFFFF;
    return D2GAME_NPC_BuyItemHandler_6FCC92A0(pGame, pPlayer, nNpcUnitId, nItemId,
        nTransactionType >> 16, nTransactionType, nCost, bMultibuy);
}
