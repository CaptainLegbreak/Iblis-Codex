struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0

static D2MonStatsTxt* FACING_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int FACING_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = FACING_GetMonStatsTxtRecordInline(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x004AE7B0
int __fastcall sub_004AE7B0_CheckMonsterFacing(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nArg3, int nArg4)
{
    const int nUnitType = pTarget ? pTarget->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nBaseId = FACING_GetBaseIdInline(pTarget->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != 298)
    {
        return 0;
    }

    if (sub_006416D0_UnitEdgeDistance(pUnit, pTarget) > 1)
    {
        return 0;
    }

    const unsigned char nDirection = PATH_GetDirection(pTarget->pDynamicPath);
    unsigned char aDirections[8] = { 6, 7, 0, 1, 2, 3, 4, 5 };
    const unsigned char nNewDirection = aDirections[sub_0063E7A0_GetByteTableEntry(nDirection)];
    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(nNewDirection, &nOffsetX, &nOffsetY);
    const int nX = UNITS_GetXPosition(pTarget) + 3 * nOffsetX;
    const int nY = CLIENTS_GetUnitY(pTarget) + 3 * nOffsetY;
    if (nX == UNITS_GetXPosition(pUnit) && nY == CLIENTS_GetUnitY(pUnit))
    {
        return nDirection;
    }

    return 0;
}
