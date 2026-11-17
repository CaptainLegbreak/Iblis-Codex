struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc);            // 0x00543D50
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID);     // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer);         // 0x00537190

// 0x00572F20
void __fastcall sub_6FC61B70(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    QUESTS_NPCDeactivate(pGame, pPlayer, pNpc);

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            if (pInteractInfo->nInteract >= 1)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 651, 0);
                if (!pMonInteract->pInteractInfo)
                {
                    SUNITPROXY_FreeNpcGamble(pGame, pNpc, pPlayer);
                }
                return;
            }

            if (pInteractInfo->nInteract == 0)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 686, 0);
                return;
            }
        }

        pPrevious = pInteractInfo;
    }
}
