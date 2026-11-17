struct D2GameStrc;
struct D2UnitStrc;

struct D2QuestDataStrc
{
    char unk0x00[0x09];
    unsigned char bNotIntro;
    char unk0x0A[0x0E];
    void* pQuestDataEx;
};

struct D2Act3Quest0Strc
{
    unsigned char bHratliStartCreated;
    unsigned char bHratliEndCreated;
    unsigned char bHratliEndObjectInitialized;
    unsigned char bHratliStartIsPresent;
    int nHratliX;
    int nHratliY;
};

struct D2Act3Quest1Strc
{
    char unk0x00[0x18];
    int nTomeObjectMode;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x005B7120
int __fastcall sub_005B7120_GetHratliEndCoords(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 14);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bHratliEndObjectInitialized != 1 || !pQuestDataEx->bHratliStartIsPresent)
    {
        return 0;
    }
    pCoord->nX = pQuestDataEx->nHratliX;
    pCoord->nY = pQuestDataEx->nHratliY;
    return 1;
}

// 0x005B7310
void __fastcall sub_005B7310(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData)
    {
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, ((D2Act3Quest1Strc*)pQuestData->pQuestDataEx)->nTomeObjectMode);
    }
}

// 0x005B7FE0
void __cdecl sub_005B7FE0_Nop()
{
}
