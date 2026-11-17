struct D2UnitStrc;
struct D2QuestStrc;
struct D2QuestArgStrc
{
    D2UnitStrc* pUnit;
    int nEvent;
    int pTarget;
    D2QuestStrc* pQuest;
    int unk_10;
    int nClassId;
    unsigned short nIndex;
};
void __fastcall sub_00572360_Update(D2QuestStrc* pQuest, D2UnitStrc* pUnit, int nClassId); // 0x00572360

// 0x005B6C60
void __fastcall sub_005B6C60_UpdateQuest(void* pUnused, D2QuestArgStrc* pArgs)
{
    const int nClassId = pArgs->nClassId;
    const unsigned short nIndex = pArgs->nIndex;
    switch (nClassId)
    {
    case 254:
        if (nIndex == 502 || nIndex == 501)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    case 264:
        if (nIndex == 479 || nIndex == 478)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    case 252:
        if (nIndex == 491 || nIndex == 490)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    case 255:
        if (nIndex == 515 || nIndex == 514)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    case 297:
        if (nIndex == 453)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    case 245:
        if (nIndex == 458)
            sub_00572360_Update(pArgs->pQuest, pArgs->pUnit, nClassId);
        break;
    }
}
