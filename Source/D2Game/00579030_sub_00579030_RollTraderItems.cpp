struct D2GameStrc;
struct D2UnitStrc;

int __fastcall sub_00536B40(D2GameStrc* pGame); // 0x00536B40
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg); // 0x00576890
int __fastcall sub_00576C90_RollTraderItemCode(D2GameStrc* pGame, D2UnitStrc* pNpc, int nValue, int nStockLevel, int* pItemCode, int* pArg); // 0x00576C90

// 0x00579030
int __fastcall sub_00579030_RollTraderItems(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg, int nArg2)
{
    const int nValue = sub_00536B40(pGame);
    int i = 0;
    const int nStockLevel = sub_00576890(pGame, pNpc, nArg);
    int nItemCode;
    while ((i < 5 ? sub_00576C90_RollTraderItemCode(pGame, pNpc, nValue, nStockLevel, &nItemCode, &nArg2) : 0) != 0)
        ++i;
    return 0;
}
