// 0x0055A6D0
void __fastcall D2GAME_DropTC_6FC51360(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, D2TCExShortStrc* pTCTxtRecord, int nQuality, int nLvl, int bIgnoreNoDrop, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems)
{
    const int bExpansion = pGame->bExpansion;
    int nThrowableCounter = 0;

    D2_ASSERT(pTCTxtRecord, 0xF3A);

    int nItemsDropped;
    if (!pnItemsDropped)
    {
        pnItemsDropped = &nItemsDropped;
    }
    *pnItemsDropped = 0;

    if (!ppItems)
    {
        if (nMaxItems <= 0)
        {
            nMaxItems = 6;
        }
    }
    else
    {
        D2_ASSERT(nMaxItems, 0xF44);
    }

    D2TCArrayStrc tcArray[64];
    tcArray[0].pTC = pTCTxtRecord;
    tcArray[0].nPicks = D2_ABS(pTCTxtRecord->nPicks);
    tcArray[0].nPicks = D2_MAX(tcArray[0].nPicks, 1);
    tcArray[0].tMods = pTCTxtRecord->tMods;

    int nCounter = 1;
    while (nCounter)
    {
        --nCounter;

        if (!tcArray[nCounter].pTC)
        {
            continue;
        }

        if (!(bExpansion ? tcArray[nCounter].pTC->nProb : tcArray[nCounter].pTC->nClassic))
        {
            continue;
        }

        while (tcArray[nCounter].nPicks)
        {
            D2TCExShortStrc* pTC = tcArray[nCounter].pTC;
            const int nChance = bExpansion ? pTC->nProb : pTC->nClassic;
            if (!nChance)
            {
                break;
            }

            int nRand;
            if (pTC->nPicks >= 0)
            {
                nRand = nChance;
                int nNoDrop = pTC->nNoDrop;
                if (nNoDrop)
                {
                    int nPlayerCount = 1;
                    if (pPlayer)
                    {
                        D2UnitStrc* pOwner = pPlayer;
                        if (pPlayer->dwUnitType != UNIT_PLAYER)
                        {
                            pOwner = AIGENERAL_GetMinionOwner(pPlayer);
                        }

                        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
                        {
                            const int nLiving = PARTY_GetLivingPartyMemberCountInSameLevel(pGame, pOwner);
                            nPlayerCount = D2_MIN(D2_MAX(nLiving, 1), 8);
                        }
                    }

                    nPlayerCount += (PLAYER_GetPlayerCount(pGame) - nPlayerCount) / 2;
                    if (pMonster && GAME_GetUnitTypeOrInvalid(pMonster) == 1)
                    {
                        int nMonsterPlayers = STATLIST_UnitGetStatValue(pMonster, STAT_MONSTER_PLAYERCOUNT, 0);
                        nMonsterPlayers = D2_MAX(1, nMonsterPlayers);
                        nPlayerCount = D2_MIN(nPlayerCount, nMonsterPlayers);
                    }

                    if (nPlayerCount > 1)
                    {
                        const double dBaseRatio = (double)nNoDrop / (double)(nNoDrop + nChance);
                        double dNoDropRatio = dBaseRatio;
                        for (int i = 1; i < nPlayerCount; ++i)
                        {
                            dNoDropRatio *= dBaseRatio;
                        }

                        const double dInverseRatio = 1.0 - dNoDropRatio;
                        if (dInverseRatio != 0.0)
                        {
                            nNoDrop = (int)((1.0 - dInverseRatio) * nChance / dInverseRatio);
                        }
                        else
                        {
                            nNoDrop = 0;
                        }
                    }
                }

                if (!bIgnoreNoDrop)
                {
                    nRand = nNoDrop + nChance;
                }

                if (nRand <= 0)
                {
                    nRand = 0;
                }
                else if ((nRand - 1) & (unsigned int)nRand)
                {
                    unsigned int nRoll;
                    D2_SEED_ROLL(pMonster, nRoll);
                    nRand = nRoll % nRand;
                }
                else
                {
                    unsigned int nRoll;
                    D2_SEED_ROLL(pMonster, nRoll);
                    nRand = nRoll & (nRand - 1);
                }

                if (!bIgnoreNoDrop)
                {
                    if (nRand < nNoDrop)
                    {
                        --tcArray[nCounter].nPicks;
                        continue;
                    }

                    nRand -= nNoDrop;
                }
            }
            else
            {
                nRand = D2_ABS(pTC->nPicks) - tcArray[nCounter].nPicks;
                if (nRand >= nChance)
                {
                    break;
                }
            }

            --tcArray[nCounter].nPicks;

            int nIndex;
            if (bExpansion)
            {
                int nLowerBound = 0;
                int nUpperBound = pTC->nTypes;
                while (nLowerBound < nUpperBound)
                {
                    nIndex = nLowerBound + (nUpperBound - nLowerBound) / 2;
                    if (nRand > pTC->pInfo[nIndex].nProb)
                    {
                        nLowerBound = nIndex + 1;
                    }
                    else if (nRand < pTC->pInfo[nIndex].nProb)
                    {
                        nUpperBound = nIndex;
                    }
                    else
                    {
                        break;
                    }
                }

                if (nLowerBound >= nUpperBound)
                {
                    nIndex = D2_MAX(0, nLowerBound - 1);
                }
            }
            else
            {
                nIndex = 0;
                while (nIndex < pTC->nTypes)
                {
                    if (!(pTC->pInfo[nIndex].nFlags & 0x10) && (nIndex >= pTC->nTypes - 1 || pTC->pInfo[nIndex + 1].nClassic > nRand))
                    {
                        break;
                    }

                    ++nIndex;
                }
            }

            if (nIndex >= pTC->nTypes)
            {
                continue;
            }

            if (pTC->pInfo[nIndex].nFlags & 4)
            {
                D2TCExShortStrc* pSubTC = DATATBLS_GetTreasureClassExRecordFromIdAndLevel(pTC->pInfo[nIndex].nItemId, 0);
                const int nOldCounter = nCounter;
                if (tcArray[nCounter].nPicks > 0)
                {
                    ++nCounter;
                }

                D2_ASSERT(nCounter < 0x40, 0xFEA);

                tcArray[nCounter].pTC = pSubTC;
                tcArray[nCounter].nPicks = D2_ABS(pSubTC->nPicks);
                tcArray[nCounter].nPicks = D2_MAX(tcArray[nCounter].nPicks, 1);

                for (int i = 0; i < 6; ++i)
                {
                    if (!tcArray[nOldCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pSubTC->tMods.nMods[i];
                    }
                    else if (pSubTC->tMods.nMods[i] > tcArray[nOldCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pSubTC->tMods.nMods[i];
                    }
                    else
                    {
                        tcArray[nCounter].tMods.nMods[i] = tcArray[nOldCounter].tMods.nMods[i];
                    }
                }
                continue;
            }

            unsigned short nItemId = pTC->pInfo[nIndex].nItemId;
            if (nItemId == 0xFFFF)
            {
                continue;
            }

            if (!bExpansion)
            {
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
                if (!pItemsTxtRecord || pItemsTxtRecord->wVersion >= 100)
                {
                    continue;
                }

                for (int i = 0; i < 6; ++i)
                {
                    if (pTC->pInfo[nIndex].tMods.nMods[i] > tcArray[nCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pTC->pInfo[nIndex].tMods.nMods[i];
                    }
                }
            }

            int nItemQuality;
            int nItemIndex = 0;
            if (pTC->pInfo[nIndex].nFlags & 1)
            {
                nItemQuality = 7;
                nItemIndex = pTC->pInfo[nIndex].nTxtRow + 1;
            }
            else if (pTC->pInfo[nIndex].nFlags & 2)
            {
                nItemQuality = 5;
                nItemIndex = pTC->pInfo[nIndex].nTxtRow + 1;
            }
            else
            {
                nItemQuality = nQuality;
                if (!nItemQuality)
                {
                    nItemQuality = ITEMS_RollDropQuality(pGame, pMonster, pPlayer, (D2QualityModsStrc*)&tcArray[nCounter].tMods, nLvl, nItemId);
                }
            }

            int nFlags = 0;
            if (tcArray[nCounter].tMods.nMods[4] > 0)
            {
                unsigned int nRoll;
                D2_SEED_ROLL(pMonster, nRoll);
                if ((nRoll & 0x3FF) < tcArray[nCounter].tMods.nMods[4])
                {
                    nFlags = 4;
                }
            }

            const unsigned short wNormal = tcArray[nCounter].tMods.nMods[5];
            if (wNormal > 0)
            {
                unsigned int nRoll;
                D2_SEED_ROLL(pMonster, nRoll);
                if ((nRoll & 0x3FF) < wNormal)
                {
                    nFlags |= 0x10;
                }
            }

            if (!pGame->bExpansion && ITEMS_CheckItemTypeIfThrowable(ITEMS_GetItemTypeFromItemId(nItemId)))
            {
                if (nThrowableCounter++ < 0xA)
                {
                    ++tcArray[nCounter].nPicks;
                    continue;
                }

                nItemId = DATATBLS_GetItemIdFromItemCode(0x2064736C);
            }

            D2UnitStrc* pItem = ITEMS_CreateDropAtUnit(pGame, nItemQuality, nItemIndex, nFlags, nItemId, pMonster);
            if (!pItem)
            {
                continue;
            }

            if (ITEMSIsA(pItem, 4) && pTC->pInfo[nIndex].nTxtRow)
            {
                D2GAME_SetStatOrResetGold(pItem, 0xE, STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0) * pTC->pInfo[nIndex].nTxtRow >> 8);
            }

            if (ppItems)
            {
                ppItems[*pnItemsDropped] = pItem;
            }

            ++*pnItemsDropped;
            if (*pnItemsDropped >= nMaxItems)
            {
                return;
            }

            ITEMS_ApplyGoldFind(pPlayer, pItem);
        }
    }
}
