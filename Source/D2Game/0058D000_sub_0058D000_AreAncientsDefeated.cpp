struct D2GameStrc;
struct D2UnitStrc;

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
};

struct D2Act5Quest5Strc
{
    char unk0x00[0x44];
    int nAncientsAlive;
    unsigned char bAncientsActivated;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT5Q5_UnitIterate_ClosePortals(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);          // 0x0058D2C0

// 0x0058D000
int __fastcall sub_0058D000_AreAncientsDefeated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive)
        {
            return 1;
        }
    }
    return 0;
}

// 0x0058D1D0
static __forceinline void sub_0058D1D0_PlayStatueSound(D2ObjOperateFnStrc* pOp)
{
    SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
}

void __stdcall sub_M114_Emit_0058D1D0(D2ObjOperateFnStrc* pOp)
{
    sub_0058D1D0_PlayStatueSound(pOp);
}

// 0x0058D300
void __fastcall sub_0058D300_ClosePortals(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
}
