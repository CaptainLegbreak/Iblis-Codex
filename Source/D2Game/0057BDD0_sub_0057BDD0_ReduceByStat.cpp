struct D2UnitStrc;

struct D2StatReduceCtx
{
    int unk0x00;
    int unk0x04;
    D2UnitStrc* pUnit;
    int unk0x0C;
    int unk0x10;
    int bCapped;
};

struct D2StatReduceRec
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nStatId;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

static __declspec(noinline) int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue);

// 0x0057BDD0
static int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int nStatId = pRec->nStatId;
    if (nStatId == -1)
    {
        return nValue;
    }

    if (nValue >= 100 && pCtx->bCapped)
    {
        return nValue;
    }

    int nStat = STATLIST_UnitGetStatValue(pCtx->pUnit, nStatId, 0);
    if (!nStat)
    {
        return nValue;
    }

    return nValue - nStat;
}

int __fastcall sub_Emit_0057BDD0(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int n = sub_0057BDD0_ReduceByStat(pCtx, pRec, nValue);
    return n + sub_0057BDD0_ReduceByStat(pCtx, pRec + 1, n);
}
