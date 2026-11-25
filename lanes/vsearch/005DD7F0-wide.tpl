int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom); // 0x0061AA40

static inline int AIUTIL_TestAiFlag_5DD7F0(D2AiControlStrc* pAiControl, int nBit)
{
    if (!pAiControl)
        return 0;
    return (pAiControl->nAiFlags >> nBit) & 1;
}
//==FUNC==
D2UnitStrc* __fastcall FNAME(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
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
    else if (DUNGEON_CheckLOSDraw(pRoom))
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
    else if (DUNGEON_CheckLOSDraw(pRoom))
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
    else if (DUNGEON_CheckLOSDraw(pRoom))
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
        if (STATLIST_GetUnitAlignment(pUnit) == 0)
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
            const int nX = CLIENTS_GetUnitX(pUnit);
            const int nY = CLIENTS_GetUnitY(pUnit);
<<{            for (int i = 0; i < 8; ++i)
<<ALT>>            for (int i = 8; i; --i)
<<ALT>>            for (int i = 0; i != 8; i++)
}>>            {
                if (pNode)
                {
                    D2UnitStrc* pCurrent = pNode->hUnit;
                    D2_ASSERT(pCurrent && pCurrent->dwUnitType == 0, 0x5F6);
                    if (nAct == pCurrent->nAct && UNITS_GetRoom(pCurrent) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pCurrent)))
                    {
                        unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
<<{                        if (nCurrentDistance < nMinDistance)
                            nMinDistance = nCurrentDistance;
<<ALT>>                        nMinDistance = nCurrentDistance < nMinDistance ? nCurrentDistance : nMinDistance;
}>>                        if (nCurrentDistance < 55)
                        {
<<{                            if (SUNIT_IsDead(pCurrent))
                                nCurrentDistance = 0x7FFFFFFF;
<<ALT>>                            nCurrentDistance = SUNIT_IsDead(pCurrent) ? 0x7FFFFFFF : nCurrentDistance;
}>>                            for (;;)
                            {
<<{                                if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
                                {
                                    nDistance = nCurrentDistance;
                                    pTarget = pCurrent;
                                }
<<ALT>>                                if (nCurrentDistance < (unsigned int)nDistance)
                                {
                                    if (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4))
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
                                nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
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
                    const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                    if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
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
                    const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                    if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
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
                        const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                        if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
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
                    const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                    if (nCurrentDistance < nAlternativeDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
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
            const int nCollision = D2Common_10095(pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
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
}>>    if (STATLIST_GetUnitAlignment(pUnit) != 2)
    {
        pAiControl->nAiFlags |= 8;
        if (pSpecialAi)
            pSpecialAi[9] = nOldToggle == 0;
    }
    *pCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    *pDistance = nDistance;
    return pTarget;
}

