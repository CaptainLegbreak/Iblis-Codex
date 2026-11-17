struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x8];
    int dwMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
    unsigned int dwFlagExBits0 : 7;
    unsigned int bOutOfSight : 1;
    unsigned int dwFlagExBits8 : 10;
    unsigned int bNoDraw : 1;
    unsigned int dwFlagExBits19 : 13;
};

struct D2ObjectsTxt
{
    char unk0x00[0x131];
    unsigned char nDrawMode[8];
};

struct D2MissilesTxt
{
    char unk0x00[0xA2];
    short nOffsetX;
    short wYoffset;
    short nOffsetY;
};

D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DRLG_GetLOSDrawFromLevelId(int nLevelId);                                                     // 0x00642840
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __stdcall sub_004F66E0_IsPrecisionOnScreen(int nPrecisionX, int nPrecisionY);                           // 0x004F66E0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder); // 0x004F67C0
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
int __fastcall sub_00471EC0(D2UnitStrc* pUnit, int nArg, int nX, int nY, int bPlayer, int nFlags); // 0x00471EC0
int __fastcall sub_004AE340(D2UnitStrc* pUnit);                                                             // 0x004AE340
void __fastcall sub_004D85B0_SkillSeqDo1Thunk(D2UnitStrc* pUnit, int nArg);                                 // 0x004D85B0
void __fastcall sub_004D8650(D2UnitStrc* pUnit, int nArg);                                                  // 0x004D8650
void __fastcall sub_004D8520_SkillSeqDo1(D2UnitStrc* pUnit, int nArg);                                      // 0x004D8520
void __fastcall sub_004D85C0_SkillSeqDo0(D2UnitStrc* pUnit, int nArg);                                      // 0x004D85C0
void __cdecl sub_004F6830();                                                                                // 0x004F6830

// 0x004DC710
static int sub_004DC710_UpdateUnitSightFlag(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2UnitStrc* pPlayer;
        switch (pUnit->dwUnitType)
        {
        case 0:
            pPlayer = sub_00463DE0_GetStoredUnit();
            if (pPlayer == pUnit || !pUnit->dwMode || pUnit->dwMode == 0x11)
                goto set_flag;
            break;
        case 1:
            if (!pUnit->dwMode || pUnit->dwMode == 0xC)
                goto set_flag;
            pPlayer = sub_00463DE0_GetStoredUnit();
            break;
        case 3:
        case 4:
            pPlayer = sub_00463DE0_GetStoredUnit();
            break;
        default:
            goto set_flag;
        }
        if (pPlayer)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if ((!pRoom || DRLG_GetLOSDrawFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))) && UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
            {
                pUnit->bOutOfSight = 0;
                return 0;
            }
        }
set_flag:
        pUnit->bOutOfSight = 1;
    }
    return 1;
}

void __fastcall sub_004DC7B0_DrawUnitByType(D2UnitStrc* pUnit, int nColor, int bForce)
{
    if (!bForce && pUnit && pUnit->bNoDraw)
        return;
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwMode == 0x11 && !STATES_CheckState(pUnit, 7))
        return;
    if (!bForce && pUnit && pUnit->dwUnitType > 0 && pUnit->dwUnitType <= 2)
    {
        if (STATES_CheckState(pUnit, 0x8F))
            return;
        if (STATES_CheckState(pUnit, 0x92))
            return;
    }
    const int bPerspective = sub_004F51D0_IsPerspective();
    const int nPrecisionX = UNITS_GetPrecisionX(pUnit);
    const int nPrecisionY = UNITS_GetPrecisionY(pUnit);
    if (bPerspective && !sub_004F66E0_IsPrecisionOnScreen(nPrecisionX, nPrecisionY))
        return;
    if (!sub_004DC710_UpdateUnitSightFlag(pUnit))
        return;
    const int nType = !pUnit ? 6 : pUnit->dwUnitType;
    int nX;
    int nY;
    if (bPerspective)
    {
        int bOrder = 0;
        if (pUnit && pUnit->dwUnitType == 2)
        {
            D2ObjectsTxt* pObjectsRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
            if (pObjectsRecord->nDrawMode[UNITS_GetAnimOrSeqMode(pUnit)] == 2)
                bOrder = 1;
        }
        int nTempY;
        SCALE_ScalePerspectivePosition(nPrecisionX, nPrecisionY, 0x60, &nX, &nTempY, bOrder);
        nX += sub_0045AFC0();
        nY = nTempY + sub_0045AFD0_GetMouseYOffset();
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit);
        nY = UNITS_GetClientCoordY(pUnit);
    }
    int bSpecial = 0;
    switch (nType)
    {
    case 0:
        sub_004D8520_SkillSeqDo1(pUnit, nColor);
        if (sub_00471EC0(pUnit, nColor, nX, nY, 0, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        sub_004D85C0_SkillSeqDo0(pUnit, nColor);
        break;
    case 1:
        if (sub_004AE340(pUnit))
            bSpecial = 1;
        sub_004D85B0_SkillSeqDo1Thunk(pUnit, nColor);
        if (sub_00471EC0(pUnit, nColor, nX, nY, bSpecial, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        sub_004D8650(pUnit, nColor);
        break;
    case 3:
    {
        D2MissilesTxt* pMisTxt = DATATBLS_GetMissilesTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMisTxt)
            break;
        if (sub_00471EC0(pUnit, nColor, nX + pMisTxt->nOffsetX, nY + pMisTxt->nOffsetY + pMisTxt->wYoffset, 0, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        break;
    }
    default:
        if (sub_00471EC0(pUnit, nColor, nX, nY, bSpecial, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        break;
    }
    if (bPerspective)
        sub_004F6830();
}
