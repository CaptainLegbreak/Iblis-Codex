#include "D2MonsterIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"


enum
{
    ANIMSEQ_EVENT_MELEE_ATTACK = 1,
    ANIMSEQ_EVENT_MISSILE_ATTACK = 2,
};

enum
{
    ACT_II = 1,
};




struct D2UnkMonCompStrc
{
    unsigned char nComposit[12];
};



extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnMonStatsMissileOffsets_006EA938[];                                                             // 0x006EA938
extern const unsigned int* gpSkeletonComponentCodes_007489A8[16];                                           // 0x007489A8
extern const unsigned int* gpArcherComponentCodes_00748A18[16];                                             // 0x00748A18

void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount);                    // 0x00621870
int __stdcall UNITS_GetEventFrameInfo(D2UnitStrc* pUnit, int nFrame);                                       // 0x00621920
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode);                                      // 0x006117D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return pUnit->dwAnimMode;
}

inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }
    return 0;
}

// 0x0063E6B0
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int a2)
{
    if (a2)
    {
        if (!pUnit->nActionFrame)
        {
            return -1;
        }

        int nFrame;
        int nFrameCount;
        UNITS_GetFrameMetrics(pUnit, &nFrame, &nFrameCount);

        int nStart = nFrame - pUnit->wAnimSpeed;
        nFrame >>= 8;
        nStart >>= 8;

        if (nStart >= nFrame)
        {
            return -1;
        }

        int nCounter = nStart;
        while (nCounter <= nFrame)
        {
            if (UNITS_GetEventFrameInfo(pUnit, nCounter) == ANIMSEQ_EVENT_MISSILE_ATTACK || UNITS_GetEventFrameInfo(pUnit, nCounter) == ANIMSEQ_EVENT_MELEE_ATTACK)
            {
                break;
            }

            ++nCounter;
        }

        if (nCounter > nFrame)
        {
            return -1;
        }

        if (nCounter <= nStart)
        {
            return -1;
        }
    }

    const int nOffset = gnMonStatsMissileOffsets_006EA938[UNITS_GetAnimModeInline(pUnit)];
    if (!nOffset)
    {
        return -1;
    }

    return *(short*)((char*)MONSTERS_GetMonStatsTxtRecordFromUnit(pUnit) + nOffset);
}

// 0x00664860
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent)
{
    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        if (nIndex >= 16)
        {
            return 0;
        }

        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pMonster->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return 0;
        }

        if (pMonStats2TxtRecord->nComponentChoiceCounts[nIndex] <= nComponent)
        {
            return 0;
        }

        unsigned int dwCode = DATATBLS_GetCodeFromCompCodeTxt(pMonStats2TxtRecord->pComponents[nIndex].nComposit[nComponent]);

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMonster);
        if (pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == ACT_II)
        {
            switch (MONSTERS_GetBaseIdFromMonsterId(sub_00463860(pMonster)))
            {
            case MONSTER_SK_ARCHER1:
            {
                const unsigned int* pCode = gpArcherComponentCodes_00748A18[nIndex];
                if (pCode)
                {
                    dwCode = pCode[nComponent];
                }
                break;
            }

            case MONSTER_SKELETON1:
            {
                const unsigned int* pCode = gpSkeletonComponentCodes_007489A8[nIndex];
                if (pCode)
                {
                    dwCode = pCode[nComponent];
                }
                break;
            }
            }
        }

        return dwCode;
    }

    return 0;
}

#include "gen/data/Source/D2Common/Unknown_0063E6B0.inc"
