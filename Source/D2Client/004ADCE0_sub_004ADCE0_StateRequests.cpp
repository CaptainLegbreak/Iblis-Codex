struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB);   // 0x004CDB40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x004ADCE0
void __fastcall sub_004ADCE0_StateRequests(D2UnitStrc* pUnit)
{
    int nX = GetUnitPathX(pUnit);
    int nY = GetUnitPathY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x221, nX, nY, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004ADD80
void __fastcall sub_004ADD80_StateRequestsCallback(D2UnitStrc* pUnit, int nState, int bFlag)
{
    sub_004ADCE0_StateRequests(pUnit);
}
