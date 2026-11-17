struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
    unsigned short wNameSeed;
    unsigned short nTypeFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xD0];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GfxEntryStrc
{
    unsigned char nValue;
    unsigned char unk0x01;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    char unk0x08[0x8];
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[20];
    D2GfxListNodeStrc* pNodeList;
};

struct D2MotionVectorStrc
{
    int nX;
    int nY;
    int nZ;
};

struct D2GfxMotionStrc
{
    int unk0x00;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    char unk0x1C[0xC];
    D2MotionVectorStrc tC;
};

struct D2CellBlockStrc
{
    unsigned char nCount;
    unsigned char nWidth;
    char unk0x02[0x1A];
    unsigned char pData[1];
};

struct D2OffsetTableStrc
{
    char unk0x00[0x10];
    int nOffsetsOffset;
    unsigned int nCount;
    int nFirstId;
};

struct D2OffsetTableRefStrc
{
    D2OffsetTableStrc* f_0;

    void* sub_004E0700_GetEntry(int nId);
};

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

typedef int (__fastcall* UNITCALLBACKFN)(D2UnitStrc* pUnit, D2UnitStrc* pOther, void* pArg1, void* pArg2);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
int __fastcall sub_0046DA60_GetUnitMode(D2UnitStrc* pUnit);                                                 // 0x0046DA60
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest);                                         // 0x004CD540

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x004AC810
void __fastcall sub_004AC810_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
            {
                pMonsterData->nTypeFlag |= nFlag;
            }
            else
            {
                pMonsterData->nTypeFlag &= ~nFlag;
            }
        }
    }
}

// 0x004DB110
unsigned char* __fastcall sub_004DB110_GetCellPtr(D2CellBlockStrc* pBlock, int nX, int nY)
{
    if (!pBlock)
    {
        return 0;
    }

    return &pBlock->pData[(pBlock->nWidth * nX + nY + 9) * pBlock->nCount + pBlock->nWidth];
}

// 0x004DB1C0
void __fastcall sub_004DB1C0_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        pGfxData->tEntries[nIndex].nValue = nValue;
    }
}

// 0x004E0700
void* D2OffsetTableRefStrc::sub_004E0700_GetEntry(int nId)
{
    D2OffsetTableStrc* pTable = this->f_0;
    if (!pTable)
    {
        return 0;
    }

    unsigned int nIndex = nId - pTable->nFirstId;
    if (nIndex >= pTable->nCount)
    {
        return 0;
    }

    return (char*)pTable + *(int*)((char*)pTable + pTable->nOffsetsOffset + nIndex * 4);
}

// 0x004DA1D0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->tA.nX = nX << 11;
        pMotion->tA.nY = nY << 11;
        pMotion->tA.nZ = nZ << 11;
    }
}

// 0x004DA200
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tB.nX = nX << 11;
            pMotion->tB.nY = nY << 11;
            pMotion->tB.nZ = nZ << 11;
        }
        else
        {
            pMotion->tB.nX = nX;
            pMotion->tB.nY = nY;
            pMotion->tB.nZ = nZ;
        }
    }
}

// 0x004DA2A0
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tC.nX = nX << 11;
            pMotion->tC.nY = nY << 11;
            pMotion->tC.nZ = nZ << 11;
        }
        else
        {
            pMotion->tC.nX = nX;
            pMotion->tC.nY = nY;
            pMotion->tC.nZ = nZ;
        }
    }
}

// 0x0046E5A0
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 940);

    if (nMode == -1)
    {
        nMode = sub_0046DA60_GetUnitMode(pUnit);
    }

    for (D2GfxListNodeStrc* pNode = pGfxData->pNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nId == nId)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x0046C570
int __fastcall sub_0046C570_ForEachUnitInAdjacentRooms(D2UnitStrc* pUnit, void* pArg1, void* pArg2, UNITCALLBACKFN pfnCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pOther = ppRoomList[i]->pUnitFirst; pOther; pOther = pOther->pRoomNext)
        {
            int nResult = pfnCallback(pUnit, pOther, pArg1, pArg2);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    return 0;
}

// 0x0046C600
int __fastcall sub_0046C600_NearestUnitCallback(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppNearest, int* pnDistance)
{
    if (pUnit != pOther && pOther)
    {
        if (pOther->dwUnitType == 0
            || pOther->dwUnitType == 1 && pOther->dwClassId != 149 && pOther->dwClassId != 556)
        {
            if (!sub_00464820_IsDeadOrDying(pUnit))
            {
                int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pOther);
                if (nDistance < *pnDistance)
                {
                    *ppNearest = pOther;
                    *pnDistance = nDistance;
                }
            }
        }
    }

    return 0;
}

// 0x004CDB40
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 1;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = nArg1;
    tRequest.nArg2 = nArg2;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}
