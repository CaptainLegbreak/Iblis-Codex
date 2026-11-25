// 0x005DD7F0
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int* pSpecialAi = 0;
    int nOldToggle = 0;
    int bCheckCollision;
    if (pAiControl->nAiFlags & 0x40)
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

    D2UnitStrc* pTarget = 0;
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
            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pMonStats = (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStats)
            {
                unsigned char nThreat = pMonStats->nAiDist[pGame->nDifficulty];
                if (nThreat)
                    nDistance = nThreat;
            }
            const unsigned char nAct = pUnit->nAct;
            const int nX = CLIENTS_GetUnitX(pUnit);
            const int nY = CLIENTS_GetUnitY(pUnit);
            for (int i = 0; i < 8; ++i)
            {
                if (pNode)
                {
                    D2UnitStrc* pCurrent = pNode->hUnit;
                    D2_ASSERT(pCurrent && pCurrent->dwUnitType == 0, 0x5F6);
                    if (nAct == pCurrent->nAct && UNITS_GetRoom(pCurrent) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pCurrent)))
                    {
                        unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                        if (nCurrentDistance < nMinDistance)
                            nMinDistance = nCurrentDistance;
                        if (nCurrentDistance < 55)
                        {
                            if (SUNIT_IsDead(pCurrent))
                                nCurrentDistance = 0x7FFFFFFF;
                            for (;;)
                            {
                                if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
                                {
                                    nDistance = nCurrentDistance;
                                    pTarget = pCurrent;
                                }
                                pNode = pNode->pNext;
                                if (!pNode)
                                    break;
                                pCurrent = pNode->hUnit;
                                nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                            }
                        }
                    }
                }
                pNode = *++ppNode;
            }
            while (pNode)
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
            pNode = ppNode[1];
            D2UnitStrc* pAlternative = 0;
            unsigned int nAlternativeDistance = 0x7FFFFFFF;
            while (pNode)
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
            if (pAlternative && AIUTIL_ShouldUseAlternativeTarget(&pTarget, &nDistance, pAlternative, nAlternativeDistance, pUnit))
            {
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
            arg.tSearch.nAreaTile = nCollision;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 5);
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
    if (!pTarget)
    {
        *pCombat = 0;
        *pDistance = nMinDistance;
        return 0;
    }
    if (STATLIST_GetUnitAlignment(pUnit) != 2)
    {
        pAiControl->nAiFlags |= 8;
        if (pSpecialAi)
            pSpecialAi[9] = nOldToggle == 0;
    }
    *pCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    *pDistance = nDistance;
    return pTarget;
}
