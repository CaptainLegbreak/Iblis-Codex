struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x34];
    int nCainGibbetGUID;
    char unk0x38[0x10];
    unsigned char bCageModeChanged;
    char unk0x49[0x0B];
    int nCainGibbetObjectMode;
};

struct D2Act1Quest5Strc
{
    char unk0x00[0x64];
    unsigned short nUnitCount2;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
};

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594BB0
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594F10
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x00594060
void __fastcall sub_00594060_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nCainGibbetObjectMode);
        pQuestDataEx->bCageModeChanged = 1;
        pQuestDataEx->nCainGibbetGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    }
}

// 0x00594DB0
void __fastcall sub_00594DB0_InitTowerTome(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData->bNotIntro)
        UNITS_ChangeAnimMode(pOp->pObject, 3);
}

// 0x00594FD0
static __forceinline void sub_00594FD0_FinishCountessQuest(D2QuestDataStrc* pQuestData)
{
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 5, 13);
    if (!((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->nUnitCount2)
        pQuestData->bActive = 0;
    else
        pQuestData->pfCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
}

void __fastcall sub_M129_Emit_00594FD0(D2QuestDataStrc* pQuestData)
{
    sub_00594FD0_FinishCountessQuest(pQuestData);
}
