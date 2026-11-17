struct D2GameStrc;
struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall sub_00570850_Forward(void* pUnused, D2UnitStrc* pUnit, int nArg);                           // 0x00570850

// 0x00570870
static __forceinline void sub_00570870_ForwardToLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_IterateLivingPlayers(pGame, (SUNIT_IterateFn)sub_00570850_Forward, pUnit);
}

void __stdcall sub_M113_Emit_00570870(D2GameStrc* pGame, D2UnitStrc* pFirst, D2UnitStrc* pSecond)
{
    sub_00570870_ForwardToLivingPlayers(pGame, pFirst);
    sub_00570870_ForwardToLivingPlayers(pGame, pSecond);
}

// 0x00570E10
int __cdecl sub_00570E10_GetStateMaskCount()
{
    return (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
}
