int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom); // 0x0061AA40

static inline int AIUTIL_TestAiFlag_5DD7F0(D2AiControlStrc* pAiControl, int nBit)
{
    if (!pAiControl)
        return 0;
    return (pAiControl->nAiFlags >> nBit) & 1;
}
int __stdcall DUNGEON_CheckLOSDraw_int(D2ActiveRoomStrc* pRoom);
bool __stdcall DUNGEON_CheckLOSDraw_bool(D2ActiveRoomStrc* pRoom);
unsigned char __stdcall DUNGEON_CheckLOSDraw_uchar(D2ActiveRoomStrc* pRoom);
unsigned int __stdcall DUNGEON_CheckLOSDraw_uint(D2ActiveRoomStrc* pRoom);
int __fastcall SUNIT_IsDead_int(D2UnitStrc* pUnit);
bool __fastcall SUNIT_IsDead_bool(D2UnitStrc* pUnit);
int __stdcall DUNGEON_IsRoomInTown_int(D2ActiveRoomStrc* pRoom);
bool __stdcall DUNGEON_IsRoomInTown_bool(D2ActiveRoomStrc* pRoom);
int __stdcall UNITS_TestCollisionWithUnit_int(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);
bool __stdcall UNITS_TestCollisionWithUnit_bool(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);
int __stdcall STATLIST_GetUnitAlignment_int(D2UnitStrc* pUnit);
unsigned int __stdcall STATLIST_GetUnitAlignment_uint(D2UnitStrc* pUnit);
unsigned char __stdcall STATLIST_GetUnitAlignment_uchar(D2UnitStrc* pUnit);
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize_int(D2UnitStrc* pUnit, int nX, int nY);
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize_uint(D2UnitStrc* pUnit, int nX, int nY);
int __stdcall AIUTIL_ResolveTargetOverride_int(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit);
bool __stdcall AIUTIL_ResolveTargetOverride_bool(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit);
int __stdcall AIUTIL_ShouldUseAlternativeTarget_int(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit);
bool __stdcall AIUTIL_ShouldUseAlternativeTarget_bool(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit);
int __stdcall UNITS_IsInMeleeRange_int(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);
bool __stdcall UNITS_IsInMeleeRange_bool(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);
int __fastcall CLIENTS_GetUnitX_int(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY_int(D2UnitStrc* pUnit);
unsigned int __fastcall CLIENTS_GetUnitX_uint(D2UnitStrc* pUnit);
unsigned int __fastcall CLIENTS_GetUnitY_uint(D2UnitStrc* pUnit);
//==FUNC==
D2UnitStrc* __fastcall FNAME(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
<<{#undef LOS
#define LOS DUNGEON_CheckLOSDraw_int
<<ALT>>#undef LOS
#define LOS DUNGEON_CheckLOSDraw_bool
<<ALT>>#undef LOS
#define LOS DUNGEON_CheckLOSDraw_uchar
<<ALT>>#undef LOS
#define LOS DUNGEON_CheckLOSDraw_uint
}>><<{#undef ISDEAD
#define ISDEAD SUNIT_IsDead_int
<<ALT>>#undef ISDEAD
#define ISDEAD SUNIT_IsDead_bool
}>><<{#undef INTOWN
#define INTOWN DUNGEON_IsRoomInTown_int
<<ALT>>#undef INTOWN
#define INTOWN DUNGEON_IsRoomInTown_bool
}>><<{#undef TESTCOLL
#define TESTCOLL UNITS_TestCollisionWithUnit_int
<<ALT>>#undef TESTCOLL
#define TESTCOLL UNITS_TestCollisionWithUnit_bool
}>><<{#undef ALIGN
#define ALIGN STATLIST_GetUnitAlignment_int
<<ALT>>#undef ALIGN
#define ALIGN STATLIST_GetUnitAlignment_uint
<<ALT>>#undef ALIGN
#define ALIGN STATLIST_GetUnitAlignment_uchar
}>><<{#undef DIST
#define DIST AIUTIL_GetDistanceToCoordinates_NoUnitSize_int
<<ALT>>#undef DIST
#define DIST AIUTIL_GetDistanceToCoordinates_NoUnitSize_uint
}>><<{#undef MELEE
#define MELEE UNITS_IsInMeleeRange_int
<<ALT>>#undef MELEE
#define MELEE UNITS_IsInMeleeRange_bool
}>><<{#undef GETX
#undef GETY
#define GETX CLIENTS_GetUnitX_int
#define GETY CLIENTS_GetUnitY_int
<<ALT>>#undef GETX
#undef GETY
#define GETX CLIENTS_GetUnitX_uint
#define GETY CLIENTS_GetUnitY_uint
}>>    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int* pSpecialAi = 0;
    int nOldToggle = 0;
    int bCheckCollision;
<<{    if (pAiControl->nAiFlags & 0x40)
    {
        bCheckCollision = 1;
        pAiControl->nAiFlags &= ~0x40;
    }
    else if (LOS(pRoom))
        bCheckCollision = 0;
    else
    {
        bCheckCollision = (pAiControl->nAiFlags & 8) == 0;
        if (pUnit && pUnit->dwUnitType == 1)
        {
            pSpecialAi = pUnit->pMonsterData ? (int*)pUnit->pMonsterData->pVision : 0;
            if (bCheckCollision && pSpecialAi)
            {
                nOldToggle = pSpecialAi[9];
                bCheckCollision = nOldToggle == 0;
            }
        }
    }

<<ALT>>    bCheckCollision = 1;
    if (pAiControl->nAiFlags & 0x40)
        pAiControl->nAiFlags &= ~0x40;
    else if (LOS(pRoom))
        bCheckCollision = 0;
    else
    {
        bCheckCollision = (pAiControl->nAiFlags & 8) == 0;
        if (pUnit && pUnit->dwUnitType == 1)
        {
            pSpecialAi = pUnit->pMonsterData ? (int*)pUnit->pMonsterData->pVision : 0;
            if (bCheckCollision && pSpecialAi)
            {
                nOldToggle = pSpecialAi[9];
                bCheckCollision = nOldToggle == 0;
            }
        }
    }
<<ALT>>    if (pAiControl->nAiFlags & 0x40)
    {
        bCheckCollision = 1;
        pAiControl->nAiFlags &= ~0x40;
    }
    else if (LOS(pRoom))
        bCheckCollision = 0;
    else
    {
        bCheckCollision = AIUTIL_TestAiFlag_5DD7F0(pAiControl, 3) == 0;
        if (pUnit && pUnit->dwUnitType == 1)
        {
            pSpecialAi = pUnit->pMonsterData ? (int*)pUnit->pMonsterData->pVision : 0;
            if (bCheckCollision && pSpecialAi)
            {
                nOldToggle = pSpecialAi[9];
                bCheckCollision = nOldToggle == 0;
            }
        }
    }

}>>    D2UnitStrc* pTarget = 0;
    int nDistance;
    unsigned int nMinDistance = 0x7FFFFFFF;
    if (!AIUTIL_ResolveTargetOverride(bCheckCollision, 0, &pTarget, &nDistance, pGame, pUnit))
    {
        if (ALIGN(pUnit) == 0)
        {
            D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
            D2TargetNodeStrc* pNode = *ppNode;
            pTarget = 0;
            nDistance = 35;
            D2MonStatsTxt* pMonStats = 0;
<<{            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pMonStats = (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStats)
            {
                unsigned char nThreat = pMonStats->nAiDist[pGame->nDifficulty];
                if (nThreat)
                    nDistance = nThreat;
            }
<<ALT>>            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pMonStats = (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStats && pMonStats->nAiDist[pGame->nDifficulty])
                nDistance = pMonStats->nAiDist[pGame->nDifficulty];
}>>            const unsigned char nAct = pUnit->nAct;
            const int nX = GETX(pUnit);
            const int nY = GETY(pUnit);
<<{            for (int i = 0; i < 8; ++i)
<<ALT>>            for (int i = 8; i; --i)
<<ALT>>            for (int i = 0; i != 8; i++)
}>>            {
                if (pNode)
                {
                    D2UnitStrc* pCurrent = pNode->hUnit;
                    D2_ASSERT(pCurrent && pCurrent->dwUnitType == 0, 0x5F6);
                    if (nAct == pCurrent->nAct && UNITS_GetRoom(pCurrent) && !INTOWN(UNITS_GetRoom(pCurrent)))
                    {
                        unsigned int nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
<<{                        if (nCurrentDistance < nMinDistance)
                            nMinDistance = nCurrentDistance;
<<ALT>>                        nMinDistance = nCurrentDistance < nMinDistance ? nCurrentDistance : nMinDistance;
}>>                        if (nCurrentDistance < 55)
                        {
<<{                            if (ISDEAD(pCurrent))
                                nCurrentDistance = 0x7FFFFFFF;
<<ALT>>                            nCurrentDistance = ISDEAD(pCurrent) ? 0x7FFFFFFF : nCurrentDistance;
}>>                            for (;;)
                            {
<<{                                if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4)))
                                {
                                    nDistance = nCurrentDistance;
                                    pTarget = pCurrent;
                                }
<<ALT>>                                if (nCurrentDistance < (unsigned int)nDistance)
                                {
                                    if (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4))
                                    {
                                        nDistance = nCurrentDistance;
                                        pTarget = pCurrent;
                                    }
                                }
}>><<{                                pNode = pNode->pNext;
                                if (!pNode)
                                    break;
<<ALT>>                                if (!(pNode = pNode->pNext))
                                    break;
}>>                                pCurrent = pNode->hUnit;
                                nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
                            }
                        }
                    }
                }
                pNode = *++ppNode;
            }
<<{            while (pNode)
            {
                D2UnitStrc* pCurrent = pNode->hUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
                    if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4)))
                    {
                        nDistance = nCurrentDistance;
                        pTarget = pCurrent;
                    }
                }
                pNode = pNode->pNext;
            }
<<ALT>>            for (; pNode; pNode = pNode->pNext)
            {
                D2UnitStrc* pCurrent = pNode->hUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
                    if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4)))
                    {
                        nDistance = nCurrentDistance;
                        pTarget = pCurrent;
                    }
                }
            }
<<ALT>>            if (pNode)
            {
                do
                {
                    D2UnitStrc* pCurrent = pNode->hUnit;
                    if (nAct == pCurrent->nAct)
                    {
                        const unsigned int nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
                        if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4)))
                        {
                            nDistance = nCurrentDistance;
                            pTarget = pCurrent;
                        }
                    }
                    pNode = pNode->pNext;
                }
                while (pNode);
            }
}>>            pNode = ppNode[1];
<<{            D2UnitStrc* pAlternative = 0;
            unsigned int nAlternativeDistance = 0x7FFFFFFF;
<<ALT>>            unsigned int nAlternativeDistance = 0x7FFFFFFF;
            D2UnitStrc* pAlternative = 0;
}>>            while (pNode)
            {
                D2UnitStrc* pCurrent = pNode->hUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = (unsigned int)DIST(pCurrent, nX, nY);
                    if (nCurrentDistance < nAlternativeDistance && (!bCheckCollision || !TESTCOLL(pUnit, pCurrent, 4)))
                    {
                        nAlternativeDistance = nCurrentDistance;
                        pAlternative = pCurrent;
                    }
                }
                pNode = pNode->pNext;
            }
<<{            if (pAlternative && AIUTIL_ShouldUseAlternativeTarget(&pTarget, &nDistance, pAlternative, nAlternativeDistance, pUnit))
<<ALT>>            if (pAlternative != 0 && AIUTIL_ShouldUseAlternativeTarget(&pTarget, &nDistance, pAlternative, nAlternativeDistance, pUnit) != 0)
}>>            {
                pTarget = pAlternative;
                nDistance = nAlternativeDistance;
            }
        }
        else
        {
            const int nCollision = D2Common_10095(pRoom, GETX(pUnit), GETY(pUnit));
            D2AiTargetArgsStrc arg;
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.unk0x10 = nCollision;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 5);
            if (arg.tSearch.pAlternativeTarget && AIUTIL_ShouldUseAlternativeTarget(&arg.pTarget, &arg.nDistance, arg.tSearch.pAlternativeTarget, arg.tSearch.nAlternativeDistance, pUnit))
            {
                pTarget = arg.tSearch.pAlternativeTarget;
                nDistance = arg.tSearch.nAlternativeDistance;
            }
            else
            {
                pTarget = arg.pTarget;
                nDistance = arg.nDistance;
            }
        }
    }
<<{    if (!pTarget)
    {
        *pCombat = 0;
        *pDistance = nMinDistance;
        return 0;
    }
<<ALT>>    if (pTarget == 0)
    {
        *pDistance = nMinDistance;
        *pCombat = 0;
        return 0;
    }
}>>    if (ALIGN(pUnit) != 2)
    {
        pAiControl->nAiFlags |= 8;
        if (pSpecialAi)
            pSpecialAi[9] = nOldToggle == 0;
    }
    *pCombat = MELEE(pUnit, pTarget, 0);
    *pDistance = nDistance;
    return pTarget;
}

