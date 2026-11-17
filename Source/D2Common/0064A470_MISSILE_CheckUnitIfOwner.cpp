struct D2MissileDataStrc
{
    unsigned int unk0x00;
    short nStreamMissile;
    short nStreamRange;
    short nActivateFrame;
    short nSkill;
    short nLevel;
    short nTotalFrames;
    short nCurrentFrame;
    unsigned short unk0x12;
    unsigned int fFlags;
    int nOwnerType;
    int dwOwnerGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    int dwAnimMode;
    D2MissileDataStrc* pMissileData;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x19C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit) return 6;
    return pUnit->dwUnitType;
}

static __forceinline unsigned int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0xFFFFFFFFu;
    return pUnit->dwUnitId;
}

// 0x0064A470
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pMissile && pUnit && pMissile->dwUnitType == 3)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pData = pMissile->pMissileData;
            if (pData && pData->nOwnerType == GetUnitType(pUnit) && pData->dwOwnerGUID == GetUnitId(pUnit))
            {
                return 1;
            }
        }
    }

    return 0;
}
