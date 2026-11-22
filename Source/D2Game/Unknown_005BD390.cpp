#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2QuestData.h"


typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern D2CoordStrc gaSpawnOffsets[8];                                                              // 0x00741538
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __fastcall ACT3Q7_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x005BD260
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BD390
bool __fastcall sub_005BD390(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bVileDogsSpawned)
    {
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT3Q7_UnitIterate_SetRewardGranted);
        pQuestDataEx->bVileDogsSpawned = 1;
        pQuestDataEx->bVileDogSpawnTimerCreated = 0;

        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 1, pQuestDataEx->nUnitGUID);
        if (pUnit)
        {
            const unsigned int nRand = SEED_RollRandomNumber(QUESTS_GetGlobalSeed(pGame));
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            D2CoordStrc tCoords;
            UNITS_GetCoords(pUnit, &tCoords);
            for (unsigned int i = nRand & 1; i < 8; ++i)
            {
                D2CoordStrc tPos = tCoords;
                tPos.nX += gaSpawnOffsets[i].nX;
                tPos.nY += gaSpawnOffsets[i].nY;
                D2ActiveRoomStrc* pFoundRoom;
                QUESTS_GetFreePosition(pRoom, &tPos, 3, 0x3F11, &pFoundRoom, 11, 100);
                if (pFoundRoom)
                {
                    SUNIT_AllocUnitData(2, 0x83, tPos.nX, tPos.nY, pGame, pFoundRoom, 1, 0, 0);
                }
            }
        }
    }

    return true;
}

#include "gen/data/Source/D2Game/Unknown_005BD390.inc"
