struct D2GameStrc;
struct D2UnitStrc;

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

// 0x0056BC70
int __fastcall sub_0056BC70_CountAuraTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    ++*(int*)pAuraCallback->pArgs;
    return 1;
}
