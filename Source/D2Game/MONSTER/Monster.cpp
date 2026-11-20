#include "D2Game.h"
#include "D2Structs.h"

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    char unk0x78[0x04];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nFlags[4];
    char unk0x010[0x22];
    short nVelocity;
    char unk0x034[0x174];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);       // 0x005A7C20
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                            // 0x006427F0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                         // 0x0061A1B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster);                                     // 0x005736A0
void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                         // 0x00624690

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005735A0
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5)
{
    int nAnimMode;
    D2MonStatsTxt* pMonStatsTxtRecord;
    if (!pMonster)
    {
        nAnimMode = 0;
        pMonStatsTxtRecord = 0;
    }
    else
    {
        nAnimMode = pMonster->dwAnimMode;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pMonster->dwClassId);
    }

    PATH_SetVelocity(pMonster->pDynamicPath, pMonStatsTxtRecord->nVelocity << 8, ".\\MONSTER\\Monster.cpp", 383);
    UNITS_UpdateAnimRateAndVelocity(pMonster, ".\\MONSTER\\Monster.cpp", 384);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pMonster, nAnimMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x00573C00
void __fastcall sub_00573C00_ResetMonsterModesInLevel(D2GameStrc* pGame, int nClassId1, int nClassId2, int nLevelId)
{
    D2DrlgActStrc* pAct = pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)];
    if (!pAct)
    {
        return;
    }

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nLevelId && DUNGEON_GetLevelIdFromRoom(pRoom) != nLevelId)
        {
            continue;
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
        {
            pNext = pUnit->pRoomNext;
            if (pUnit->dwUnitType == 1 && (pUnit->dwClassId == nClassId1 || pUnit->dwClassId == nClassId2) && !SUNIT_IsDead(pUnit) && !STATLIST_GetUnitAlignment(pUnit))
            {
                D2ModeChangeStrc modeChange;
                MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            }
        }
    }
}

// 0x00574370
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClassId, int nMode)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (!(pMonStatsTxtRecord->nFlags[25 >> 3] & gdwBitMasks[25 & 7]))
        {
            return 0;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nUnitGUID = pUnit->dwUnitId;
        MONSTER_Free(pGame, pUnit);

        pUnit->dwClassId = nClassId;
        MONSTER_Initialize(pGame, pRoom, pUnit, nUnitGUID);
        UNITS_ChangeAnimMode(pUnit, nMode);
        return 1;
    }

    return 0;
}
