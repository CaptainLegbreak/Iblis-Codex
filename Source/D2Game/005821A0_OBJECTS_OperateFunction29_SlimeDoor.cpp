struct D2ObjectControlStrc;
struct D2MonStatsTxt;

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

struct D2MonStats2Txt
{
    char unk0x00[0x0B];
    unsigned char nHeight;
};

#define UNITFLAG_TARGETABLE 0x00000002

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x00650D70
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                       // 0x00451FE0
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit);                           // 0x0055B7E0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster);                                                   // 0x0063EDC0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180

// 0x005821A0
int __fastcall OBJECTS_OperateFunction29_SlimeDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        UNITS_FreeCollisionPath(pOp->pObject);

        const int nMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;
        const int bSelectable = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nSelectable[nMode];
        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            if (bSelectable)
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
        }

        if (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nMode[2])
        {
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }

    return 1;
}

// 0x00582750
int __fastcall sub_6FC76F60(D2UnitStrc* pMonster, D2UnitStrc* pUnit1)
{
    if (pMonster == pUnit1)
    {
        return 0;
    }
    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (!pMonster || nUnitType != 1)
    {
        return 0;
    }
    if (STATLIST_AreUnitsAligned(pUnit1, pMonster) == 1)
    {
        return 0;
    }
    if (STATLIST_GetUnitAlignment(pMonster) != 0)
    {
        return 0;
    }
    if (MONSTERS_IsDead(pMonster))
    {
        return 0;
    }
    const int nAnimMode = pMonster->dwAnimMode;
    if (nAnimMode != 1 && nAnimMode != 2)
    {
        return 0;
    }
    const int nClassId = pMonster->dwClassId;
    if (!sub_0046C140_CheckMonStats2ModeFlag(nClassId, 2))
    {
        return 0;
    }
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord || !pMonStats2TxtRecord->nHeight)
    {
        return 0;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pMonster);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    if (MONSTERS_IsBoss(pMonStatsTxtRecord, pMonster))
    {
        return 0;
    }
    if (MONSTERS_IsPrimeEvil(pMonster))
    {
        return 0;
    }
    return MONSTERUNIQUE_CheckMonTypeFlag(pMonster, 31) == 0;
}
