#include "D2Constants.h"
#include "D2Structs.h"

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x30];
    int dwParam[5];
    char unk0x4C[0x137];
    unsigned char nCollideType;
    unsigned char nCollision;
    char unk0x185[0x05];
    unsigned char nSize;
    char unk0x18B[0x19];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x005A8890
int __fastcall MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pUnit->dwClassId);
    if (!pMissilesTxtRecord || !(pMissilesTxtRecord->nMissileFlags[4 >> 3] & gdwBitMasks[4 & 7]))
    {
        return 0;
    }

    return 1;
}
