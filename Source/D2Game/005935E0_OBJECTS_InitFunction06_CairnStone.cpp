struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x40];
    int nCairnStoneObjectId;
    unsigned char bTimerStarted;
    unsigned char bPortalOpened;
    char unk0x46[0x06];
    unsigned char bStonesActive;
    unsigned char bRescued;
    char unk0x4E[0x02];
    unsigned char bCompleted;
    char unk0x51[0x0B];
    unsigned char bStoneActivated[5];
};

struct D2QuestDataStrc
{
    char unk0x00[0x09];
    unsigned char bNotIntro;
    char unk0x0A[0x0E];
    D2Act1Quest4Strc* pQuestDataEx;
};

typedef int(__fastcall* QUESTTIMERFN)(D2GameStrc*, D2QuestDataStrc*);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuestData, QUESTTIMERFN pfTimer, int nTicks);          // 0x00543F10
int __fastcall ACT1Q4_OpenPortalToTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                // 0x00592D50
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                          // 0x00624690

// 0x005935E0
void __fastcall OBJECTS_InitFunction06_CairnStone(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        D2UnitStrc* pObject = pOp->pObject;
        const int nClassId = !pObject ? -1 : pObject->dwClassId;
        D2Act1Quest4Strc* pQuestDataEx = pQuestData->pQuestDataEx;
        if (pQuestData->bNotIntro && !pQuestDataEx->bStonesActive)
        {
            if (pQuestDataEx->bRescued)
            {
                UNITS_ChangeAnimMode(pObject, 2);
            }
            else if (pQuestDataEx->bCompleted)
            {
                UNITS_ChangeAnimMode(pObject, 2);
            }
            else
            {
                const int const tValue = nClassId - 17;
                if (pQuestDataEx->bStoneActivated[tValue] == 1)
                {
                    pQuestDataEx->bStoneActivated[tValue] = 0;
                    UNITS_ChangeAnimMode(pOp->pObject, 0);
                }
            }
            return;
        }

        pQuestDataEx->bStonesActive = 0;
        if (!pQuestDataEx->bPortalOpened && nClassId == 17)
        {
            pQuestDataEx->nCairnStoneObjectId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
            if (!pQuestDataEx->bTimerStarted)
            {
                pQuestDataEx->bTimerStarted = 1;
                QUESTS_CreateTimer(pQuestData, ACT1Q4_OpenPortalToTristram, 1);
            }
        }

        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        if (pOp->pObject && pOp->pObject->dwAnimMode == 2)
        {
            return;
        }

        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}
