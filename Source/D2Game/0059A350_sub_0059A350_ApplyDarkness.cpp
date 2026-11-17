struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2SeedStrc;
struct D2DrlgActStrc;
struct D2BitBufferStrc;

#pragma pack(push, 1)
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};
#pragma pack(pop)

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x4E];
    D2DrlgActStrc* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

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
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00;
    unsigned char bDarkenTimerCreated;
    unsigned char bDarknessApplied;
    unsigned char bDarknessPending;
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    unsigned char unk0x06;
    unsigned char pad0x07;
    int nAltarMode;
    int nAltarGUID;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
void __stdcall ENVIRONMENT_TaintedSunBegin(D2DrlgActStrc* pAct);                                            // 0x0061C450
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00599F50
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);          // 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A4F0

// 0x0059A350
static bool sub_0059A350_ApplyDarkness(D2QuestDataStrc* pQuestData)
{
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x211);
    }

    D2GameStrc* pGame = pQuestData->pGame;
    if (pGame->pAct[1])
    {
        ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_UpdateClient);
        return true;
    }

    ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessPending = 1;
    return false;
}

// 0x0059A3F0
void __fastcall sub_0059A3F0(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestData->bNotIntro == 1)
    {
        if (pQuestData->fState <= 1)
        {
            if (!sub_0059A350_ApplyDarkness(pQuestData))
            {
                pQuestDataEx->bDarknessPending = 1;
            }
            else
            {
                pQuestDataEx->bDarknessApplied = 1;
            }

            pQuestData->fState = 3;
            pQuestData->dwFlags &= 0xFFFFFF00;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
        }
    }

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nAltarMode);
}

// build: context sub_0059A570_StartDarknessForPlayer
static void __stdcall sub_0059A570_StartDarknessForPlayer(D2UnitStrc* pPlayer, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!sub_0059A350_ApplyDarkness(pQuestData))
    {
        D2GSPacketSrv5D packet5D = {};
        pQuestDataEx->bDarknessPending = 1;
        packet5D.nFlags = 1;
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 10;
        sub_6FC3F380(SUNIT_GetClientFromPlayer(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x2E0), &packet5D);
    }
    else
    {
        pQuestDataEx->bDarknessApplied = 1;
    }
}

// build: context ACT2Q3_Callback13_PlayerStartedGame
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 11, 13);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 2) == 1)
    {
        sub_0059A570_StartDarknessForPlayer(pQuestArg->pPlayer, pQuestData);

        if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 4))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 3;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 3))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 2;
        }
        else
        {
            pQuestData->fLastState = 1;
            pQuestData->fState = 1;
        }
    }
}

// 0x0059ED80
bool __fastcall ACT2Q3_DarkenEnvironment(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bDarkenTimerCreated = 0;
    if (pQuestDataEx->bDarknessApplied)
    {
        return true;
    }

    if (!sub_0059A350_ApplyDarkness(pQuestData))
    {
        pQuestDataEx->bDarknessPending = 1;
        return true;
    }

    pQuestDataEx->bDarknessApplied = 1;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
    return true;
}

// 0x0059EDC0
static void sub_0059EDC0_CreateDarkenTimer(D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->fState && !pQuestDataEx->bDarkenTimerCreated)
    {
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
        QUESTS_CreateTimer(pQuestData, ACT2Q3_DarkenEnvironment, OBJECTS_RollRandomNumber(pSeed, 15, 17));
        pQuestDataEx->bDarkenTimerCreated = 1;
    }
}

// 0x0059EE00
void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;

    if ((nNewLevel == 0x2C || nNewLevel == 0x2D) && !pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        sub_0059EDC0_CreateDarkenTimer(pQuestData);
    }

    if (nNewLevel == 0x28 && pQuestDataEx->bDarknessPending == 1 && sub_0059A350_ApplyDarkness(pQuestData))
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestDataEx->bDarknessPending = 0;
    }

    if (nOldLevel == 0x28)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x270);
        }
    }
}
