#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameServer.h"

struct D2ObjectControlStrc;
struct Entry00547390;
struct Sub00547390;
struct Obj00547390;
struct D2MonRegDataStrc;
struct D2MonsterRegionStrc;
struct D2ObjOperateFnStrc;

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
};

struct Entry00547390 { unsigned int dwUnknown00[4]; int nCount10; };

struct Sub00547390 { unsigned char bUnknown00[0x48]; Entry00547390* pEntries48[1]; };

struct Obj00547390 { unsigned char bUnknown00[0x10F0]; Sub00547390* pSub10F0; };

struct D2MonRegDataStrc
{
    short nMonHcIdx;
    char unk0x02[0x32];
};

struct D2MonsterRegionStrc
{
    char unk0x00[0x10];
    unsigned char nMonCount;
    char unk0x11[3];
    D2MonRegDataStrc pMonData[13];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

enum
{
    MONSTER_SKELETON1 = 0,
    MONSTER_ZOMBIE1 = 5,
    MONSTER_MUMMY1 = 96,
    MONSTER_SK_ARCHER1 = 170,
    MONSTER_FLYINGSCIMITAR = 234,
    MONSTER_SKMAGE_POIS1 = 274,
    MONSTER_SKMAGE_COLD1 = 379,
    MONSTER_SKMAGE_FIRE1 = 383,
    MONSTER_SKMAGE_LTNG1 = 387,
    ACT_II = 1,
};

// 0x00547300
bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells == 4 || pObjectRegion->nWells > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547330
bool __fastcall OBJRGN_ShouldSpawnHealingShrineOrWell(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->unk0x04 << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines)
    {
        return true;
    }
    return false;
}

// 0x00547360
bool __fastcall OBJRGN_CanNotSpawnMoreShrines(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines == 10 || pObjectRegion->nShrines > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547390
extern "C" __declspec(dllexport) void __fastcall sub_00547390(Obj00547390* pObj, int nIndex) {
    pObj->pSub10F0->pEntries48[nIndex]->nCount10++;
}

// 0x005474C0
int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);
    D2ObjectRegionStrc* pObjectRegion = pOp->pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nTrapMonsterId < 0 || pObjectRegion->nTrapMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nTrapMonsterIds1[] = { MONSTER_ZOMBIE1 };
        int nTrapMonsterIds2[] = { MONSTER_MUMMY1 };
        int nTrapMonsterIds3[] = { MONSTER_SKELETON1, MONSTER_SK_ARCHER1, MONSTER_SKMAGE_POIS1, MONSTER_SKMAGE_COLD1, MONSTER_SKMAGE_FIRE1, MONSTER_SKMAGE_LTNG1 };

        const int* pTrapMonsterIds = nTrapMonsterIds1;
        if (nAct == ACT_II)
        {
            pTrapMonsterIds = nTrapMonsterIds2;
        }

        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
        pObjectRegion->nTrapMonsterId = MONSTER_FLYINGSCIMITAR;

        for (int j = 0; j < pMonsterRegion->nMonCount; ++j)
        {
            const int nMonsterId = pMonsterRegion->pMonData[j].nMonHcIdx;
            for (int i = 0; i < 1; ++i)
            {
                if (nMonsterId >= pTrapMonsterIds[i] && nMonsterId < pTrapMonsterIds[i] + 5)
                {
                    pObjectRegion->nTrapMonsterId = pTrapMonsterIds[i];
                    return pTrapMonsterIds[i];
                }
            }

            for (int i = 0; i < 6; ++i)
            {
                if (nMonsterId >= nTrapMonsterIds3[i] && nMonsterId < nTrapMonsterIds3[i] + 4)
                {
                    pObjectRegion->nTrapMonsterId = nTrapMonsterIds3[i];
                    return nTrapMonsterIds3[i];
                }
            }
        }
    }

    return pObjectRegion->nTrapMonsterId;
}
