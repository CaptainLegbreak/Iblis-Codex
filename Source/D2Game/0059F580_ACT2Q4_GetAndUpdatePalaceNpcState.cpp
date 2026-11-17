struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
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

struct D2Act2Quest4Strc
{
    unsigned char unused0x00[4];
    unsigned char bDrognanActivated;
    unsigned char pad0x05[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bJerhynStartInitialized;
    unsigned char bJerhynPalaceInitialized;
    unsigned char bPalaceOpen;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char bHaremBlockerInitialized;
    unsigned char unk0x12;
    unsigned char unk0x13;
    unsigned char unk0x14;
    unsigned char bJerhynCoordinatesStored;
    unsigned char bPortalToCanyonOpen;
    unsigned char unused0x17;
    unsigned char unk0x18;
    unsigned char unk0x19;
    unsigned char bPlayerCloseToHaremBlocker;
    unsigned char pad0x1B;
    int nPlayerCloseToHaremBlockerGUID;
    D2CoordStrc pHaremBlockerCoords;
    D2CoordStrc pJerhynCoords;
    D2CoordStrc pGuardCoords;
    int nHaremBlockerGUID;
};

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
bool __fastcall sub_0059D7C0_ACT2Q6_IsStateBelow2Inactive(D2GameStrc* pGame);                               // 0x0059D7C0
unsigned char __fastcall sub_0059D7E0_ACT2Q6_IsStateOne(D2GameStrc* pGame);                                 // 0x0059D7E0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                          // 0x005DC5C0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);     // 0x005DED90
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms); // 0x0064E7B0
int __fastcall ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059B820

// 0x0059F580
void __fastcall ACT2Q4_GetAndUpdatePalaceNpcState(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3, int* pIdle)
{
    D2QuestDataStrc* pQuestData11 = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData11 || !pQuestData11->bNotIntro)
    {
        *a3 = 1;
        *pIdle = 0;
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData11->pQuestDataEx;
    if (!pQuestDataEx->bJerhynPalaceInitialized)
    {
        *a3 = 1;
        *pIdle = 0;
        return;
    }

    if (QUESTS_GetGlobalState(pGame, 12, 13) || QUESTS_GetGlobalState(pGame, 14, 13) || sub_0059D7C0_ACT2Q6_IsStateBelow2Inactive(pGame))
    {
        *a3 = 1;
        *pIdle = 0;
        return;
    }

    if (pQuestDataEx->unk0x14)
    {
        *a3 = 1;
        *pIdle = 0;
        return;
    }

    {
        if (sub_0059D7E0_ACT2Q6_IsStateOne(pGame))
        {
            pQuestDataEx->unk0x12 = 1;
        }

        if (pQuestDataEx->unk0x12 == 1)
        {
            if (!pQuestDataEx->unk0x13 || pQuestDataEx->unk0x0F)
            {
                pQuestDataEx->bPlayerCloseToHaremBlocker = 0;
                pQuestDataEx->nPlayerCloseToHaremBlockerGUID = 0;
                SUNIT_IterateUnitsOfType(pQuestData11->pGame, 0, 0, ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker);

                if (pQuestDataEx->bPlayerCloseToHaremBlocker)
                {
                    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY);
                    pQuestDataEx->unk0x13 = 1;
                    pQuestDataEx->unk0x12 = 0;
                    *a3 = 0;
                    *pIdle = 0;
                    return;
                }

                *a3 = 0;
                *pIdle = 1;
                return;
            }

            *a3 = 0;
            *pIdle = 1;

            if (pQuestDataEx->bHaremBlockerInitialized != 1)
            {
                return;
            }

            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY) <= 2)
            {
                D2UnitStrc* pHaremBlocker = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nHaremBlockerGUID);
                if (!pHaremBlocker)
                {
                    *a3 = 0;
                    *pIdle = 1;
                    return;
                }

                D2CoordStrc pCoord;
                UNITS_GetCoords(pHaremBlocker, &pCoord);
                pCoord.nX += 4;
                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pHaremBlocker);
                if (!COLLISION_GetFreeCoordinates(pRoom, &pCoord, 1, 0x3C01, 0) && !COLLISION_GetFreeCoordinates(pRoom, &pCoord, 2, 0x3C01, 0) && !COLLISION_GetFreeCoordinates(pRoom, &pCoord, 3, 0x3C01, 0))
                {
                    *a3 = 0;
                    *pIdle = 1;
                    return;
                }

                if (!sub_6FCBDFE0(pGame, pUnit, pRoom, pCoord.nX, pCoord.nY, 0, 0))
                {
                    *a3 = 0;
                    *pIdle = 1;
                    return;
                }

                pQuestDataEx->unk0x0F = 1;
                pQuestDataEx->unk0x14 = 1;
                return;
            }

            pQuestDataEx->unk0x19 = 1;
            pQuestDataEx->unk0x18 = 0;
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY);
            *pIdle = 0;
            return;
        }
    }

    *a3 = 1;
    *pIdle = 0;
}
