#include "D2Game.h"
#include "D2Structs.h"

#define MONSTER_QUALKEHK 515
struct Unit0058F000;
struct D2ObjInitFnStrc;
struct D2Act5Quest1Strc;
struct D2Act5Quest2Strc;

struct D2CoordStrc
{
    int nX;
    int nY;
};


struct D2MapAIStrc
{
    int nPathNodes;
    void* pPosition;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    char pad0x0C[0x8];
    int nX;
    int nY;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

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
    char pad0x1C[0x84];
    QUESTCALLBACK pfCallback[15];
};

struct D2Act5Quest1Strc
{
    D2MapAIStrc* pLarzukMapAI;
    D2ActiveRoomStrc* pRoom;
    char pad0x08[0x8];
    int nLarzukGUID;
    char pad0x14[0x1];
    unsigned char bLarzukSpawned;
    char pad0x16[0x1];
    unsigned char bLarzukMapAIChanged;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
extern "C" unsigned int* __stdcall sub_0058F000(Unit0058F000* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act5Quest2Strc
{
    char tPlayerGUIDs[0x84];
    unsigned char bQualKehkActivated;
    char unk0x85[0xA8 - 0x85];
    int nKilledWussies;
};

int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl sub_0063A800_Nop()
{
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl sub_00587830_Nop()
{
}

// 0x00587840
void __fastcall OBJECTS_InitFunction71_LarzukStandard(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x1F);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;
    QUESTS_GetFreePosition(pOp->pRoom, &pCoord, 2, 0x100, &pRoom, 16, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pLarzuk = D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pRoom, pCoord.nX, pCoord.nY, 0x1FF, 1, 5, 0);
    if (!pLarzuk)
    {
        return;
    }

    pQuestDataEx->bLarzukSpawned = 1;
    pQuestDataEx->nLarzukGUID = !pLarzuk ? -1 : pLarzuk->dwUnitId;
    pLarzuk->dwFlags |= 0x3000000;

    if (pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, (D2MapAIStrc*)sub_0058F000((Unit0058F000*)pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}

// 0x00587A30
void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_QUALKEHK)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bQualKehkActivated == 1 && pQuestDataEx->nKilledWussies < 5)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bQualKehkActivated = 0;
        pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}
