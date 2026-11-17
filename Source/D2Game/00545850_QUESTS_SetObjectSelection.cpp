struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2ObjectControlStrc;

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk0x00[0xC4];
    unsigned char nSelectable[8];
    char unk0xCC[0x0C];
    unsigned int dwFrameCnt[8];
    char unk0xF8[0x47];
    unsigned char nMode[8];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

#define UNITFLAG_TARGETABLE 0x00000002

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);

// 0x00545850
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp)
{
    int bCanOperate = 1;
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        bCanOperate = 0;
    }

    if (bCanOperate)
    {
        D2CoordStrc tCoords;
        UNITS_GetCoords(pOp->pObject, &tCoords);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        if (pObjectsTxtRecord->nMode[1])
        {
            UNITS_ChangeAnimMode(pOp->pObject, 1);
            sub_005417D0_DirectDated(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
        return 1;
    }

    return 0;
}
