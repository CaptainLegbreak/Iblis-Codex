struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xE8 - 0x14];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomUnitsStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2Act5Quest2Strc
{
    char unk0x000[0x84];
    unsigned char bCyclerActive;
    char unk0x085[0xA8 - 0x85];
    int nOtherKills;
    int nWussieCount;
    int nWussieGUIDs[3][5];
    char unk0x0EC[0x108 - 0xEC];
    unsigned char bGroupDone[0x0C];
    int nGroupKills[3];
    int nWussieGuids[0x0F];
    int nWussieGuidCount;
};

struct D2QuestDataStrc
{
    char unk0x00[0x04];
    D2GameStrc* pGame;
    char unk0x08;
    unsigned char bNotIntro;
    char unk0x0A;
    unsigned char fState;
    char unk0x0C[0x08];
    unsigned char bStatusCycle;
    char unk0x15[0x03];
    D2Act5Quest2Strc* pQuestDataEx;
};

struct D2QuestArgStrc
{
    char unk0x00[0x08];
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

typedef int (__fastcall* QUESTUNITITERATEFN)(D2GameStrc*, D2UnitStrc*, void*);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuestData, int nStatus, D2UnitStrc* pUnit, QUESTUNITITERATEFN pfIterate, int bValue); // 0x00544300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, D2UnitStrc* pUnit, QUESTUNITITERATEFN pfIterate); // 0x005537D0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x005879D0
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);   // 0x00587F60
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset);                            // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall sub_006416D0_GetDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x006416D0

// 0x00587FC0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    const int nGUID = !pUnit ? -1 : pUnit->dwUnitId;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (nGUID == pQuestDataEx->nWussieGUIDs[i][j])
            {
                return i;
            }
        }
    }

    return -1;
}

// 0x00588040
void __fastcall ACT5Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2UnitStrc* pTarget = pQuestArg->pTarget;
    if (pTarget && pTarget->dwClassId == 0x1B2)
    {
        DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pTarget), 0);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
        if (pRoom)
        {
            D2ActiveRoomStrc** ppRooms;
            int nRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                for (D2UnitStrc* pUnit = ((D2ActiveRoomUnitsStrc*)ppRooms[i])->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
                {
                    if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pUnit->dwClassId == 0x216 && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0
                        && sub_006416D0_GetDistance(pUnit, pQuestArg->pTarget) < 15)
                    {
                        pQuestDataEx->nWussieGuids[pQuestDataEx->nWussieGuidCount] = !pUnit ? -1 : pUnit->dwUnitId;
                        ++pQuestDataEx->nWussieGuidCount;
                        ++pQuestDataEx->nWussieCount;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < pQuestDataEx->nWussieGuidCount; ++i)
        {
            if ((!pTarget ? -1 : pTarget->dwUnitId) == pQuestDataEx->nWussieGuids[i])
            {
                const int nGroup = sub_00587FC0_GetWussieGroupIndex(pQuestData, pTarget);
                if (nGroup >= 0)
                {
                    D2Act5Quest2Strc* pGroupData = pQuestData->pQuestDataEx;
                    ++pGroupData->nGroupKills[nGroup];
                    if (pGroupData->nGroupKills[nGroup] >= 5)
                    {
                        pGroupData->bGroupDone[nGroup] = 1;
                    }
                }
                return;
            }
        }

        ++pQuestDataEx->nOtherKills;
    }

    if (pQuestDataEx->nOtherKills >= 5 && pQuestData->fState != 12)
    {
        pQuestData->bStatusCycle = 0;
        QUESTS_UnitIterate(pQuestData, 12, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bCyclerActive = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, pQuestArg->pPlayer, ACT5Q2_UnitIterate_SetCompletionFlag);
    }

    const int nGroup = sub_00587FC0_GetWussieGroupIndex(pQuestData, pQuestArg->pTarget);
    if (nGroup >= 0)
    {
        D2Act5Quest2Strc* pGroupData = pQuestData->pQuestDataEx;
        ++pGroupData->nGroupKills[nGroup];
        if (pGroupData->nGroupKills[nGroup] >= 5)
        {
            pGroupData->bGroupDone[nGroup] = 1;
        }
    }
}
