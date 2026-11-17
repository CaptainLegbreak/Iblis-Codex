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
    int nHomeType;
    int dwHomeGUID;
    int nTargetX;
    int nTargetY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MissileDataStrc* pMissileData;
    char unk0x18[0x34];
    short wAnimSpeed;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x8C];
    unsigned char nHitClass;
    char unk0x95[0x10F];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0064A1C0
void __stdcall MISSILE_SetFlags(D2UnitStrc* pMissile, unsigned int dwFlags)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        pMissile->pMissileData->fFlags = dwFlags;
    }
}

// 0x0064A240
void __stdcall MISSILE_SetSkill(D2UnitStrc* pMissile, int nSkill)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        nSkill = nSkill > 0 ? nSkill : 0;
        if (nSkill >= 32767)
        {
            nSkill = 32767;
        }
        pMissile->pMissileData->nSkill = nSkill;
    }
}

// build: context MISSILE_SetTotalFrames
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        if (nTotalFrames > -32768)
        {
            if (nTotalFrames >= 32767)
            {
                nTotalFrames = 32767;
            }
        }
        else
        {
            nTotalFrames = -32768;
        }
        pMissile->pMissileData->nTotalFrames = nTotalFrames;
    }
}

// build: context MISSILE_SetCurrentFrame
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        if (nCurrentFrame > -32768)
        {
            if (nCurrentFrame >= 32767)
            {
                nCurrentFrame = 32767;
            }
        }
        else
        {
            nCurrentFrame = -32768;
        }
        pMissile->pMissileData->nCurrentFrame = nCurrentFrame;
    }
}

// 0x0064A5A0
int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == 3)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            return pMissilesTxtRecord->nHitClass;
        }
    }
    return 0;
}

// build: context MISSILE_SetActivateFrame
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        if (nActivateFrame > -32768)
        {
            if (nActivateFrame >= 32767)
            {
                nActivateFrame = 32767;
            }
        }
        else
        {
            nActivateFrame = -32768;
        }
        pMissile->pMissileData->nActivateFrame = nActivateFrame;
    }
}

// 0x0064A670
int __stdcall MISSILE_GetAnimSpeed(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == 3)
    {
        return pMissile->wAnimSpeed;
    }
    return 0;
}

// build: context MISSILE_SetAnimSpeed
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed)
{
    if (pMissile && pMissile->dwUnitType == 3)
    {
        if (nAnimSpeed > -32768)
        {
            if (nAnimSpeed >= 32767)
            {
                nAnimSpeed = 32767;
            }
        }
        else
        {
            nAnimSpeed = -32768;
        }
        pMissile->wAnimSpeed = nAnimSpeed;
    }
}

// 0x0064A710
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        pMissile->pMissileData->nTargetX = nTargetX;
    }
}

// 0x0064A760
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        pMissile->pMissileData->nTargetY = nTargetY;
    }
}

// 0x0064A7B0
void __stdcall MISSILE_SetHomeType(D2UnitStrc* pMissile, D2UnitStrc* pTarget)
{
    if (pMissile && pMissile->dwUnitType == 3)
    {
        D2MissileDataStrc* pMissileData = pMissile->pMissileData;
        if (pMissileData)
        {
            if (pTarget)
            {
                pMissileData->nHomeType = pTarget->dwUnitType;
                pMissileData->dwHomeGUID = pTarget->dwUnitId;
            }
            else
            {
                pMissileData->nHomeType = 0;
                pMissileData->dwHomeGUID = -1;
            }
        }
    }
}
