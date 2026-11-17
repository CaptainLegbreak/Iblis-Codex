struct D2DrlgActStrc;
struct D2UnitStrc;
struct D2QuestArgStrc;
struct D2ObjInitFnStrc;

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short unk0x0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00;
    unsigned char bDarkenTimerCreated;
    unsigned char bRewarded;
    unsigned char bBlackened;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A170
void __stdcall ENVIRONMENT_TaintedSunBegin(D2DrlgActStrc* pAct);                                            // 0x0061C450
void __stdcall ENVIRONMENT_TaintedSunEnd(D2DrlgActStrc* pAct);                                              // 0x0061C4D0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760

// 0x005994F0
bool __fastcall sub_005994F0_ACT2Q1_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState == 5 ? true : false;
}

// 0x00599A20
void __fastcall sub_00599A20_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}

// 0x00599BD0
void __fastcall sub_00599BD0_ACT2Q2_AddAmulets(D2QuestDataStrc* pQuestData, int nCount)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuest)
    {
        ((D2Act2Quest2Strc*)pQuest->pQuestDataEx)->nAmulets += nCount;
    }
}

// 0x00599BF0
int __fastcall sub_00599BF0_HasNoHoradricStaff(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return !ITEMS_FindQuestItem(pGame, pUnit, ' tsh');
}

// 0x00599EE0
void __fastcall sub_00599EE0_OBJECTS_InitFunction31(D2ObjInitFnStrc* pOp)
{
}

// 0x00599EF0
void __fastcall sub_00599EF0_OBJECTS_InitFunction33(D2ObjInitFnStrc* pOp)
{
}

// 0x00599F00
void __fastcall sub_00599F00_OBJECTS_InitFunction32(D2ObjInitFnStrc* pOp)
{
}

// 0x0059A3C0
static __forceinline void sub_0059A3C0_ACT2Q3_EndTaintedSun(D2QuestDataStrc* pQuestData, D2GameStrc* pGame)
{
    if (pGame->pAct[1])
    {
        ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bRewarded = 0;
        ENVIRONMENT_TaintedSunEnd(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_SendPacket0x53ToClient);
    }
}

// 0x0059AC20
bool __fastcall sub_0059AC20_ACT2Q3_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState >= 4 ? true : false;
}

// 0x0059AC40
void __fastcall sub_0059AC40(D2GameStrc* pGame, unsigned char nActNo)
{
    if (nActNo != 1)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBlackened != 1)
    {
        return;
    }

    ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
    pQuestDataEx->bBlackened = 0;
    pQuestDataEx->bRewarded = 1;
}

void __fastcall sub_M118_Emit_0059A3C0(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->bNotIntro)
    {
        sub_0059A3C0_ACT2Q3_EndTaintedSun(pQuestData, pQuestData->pGame);
        QUESTS_TriggerFX(pQuestData->pGame, 6);
    }
}
