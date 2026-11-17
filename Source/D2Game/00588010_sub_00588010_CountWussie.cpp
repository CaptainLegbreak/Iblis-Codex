struct D2UnitStrc;

struct D2Act5Quest2Strc
{
    char unk0x00[0x108];
    unsigned char unk0x108[3];
    char unk0x10B[9];
    int unk0x114[3];
};

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
};

int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);           // 0x00587FC0

// 0x00588010
static __forceinline void sub_00588010_CountWussie(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pUnit);
    if (nIndex >= 0)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x114[nIndex] += 1;
        if (pQuestDataEx->unk0x114[nIndex] >= 5)
        {
            pQuestDataEx->unk0x108[nIndex] = 1;
        }
    }
}

void __fastcall sub_M117_Emit_00588010(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    sub_00588010_CountWussie(pQuestData, pUnit);
}
