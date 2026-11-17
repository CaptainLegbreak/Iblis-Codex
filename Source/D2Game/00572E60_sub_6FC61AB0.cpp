struct D2ClientStrc;
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

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
void __fastcall sub_6FC3F340(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                      // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc);           // 0x00578E70

// 0x00572E60
void __fastcall sub_6FC61AB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            if (!pInteractInfo->nInteract)
            {
                pInteractInfo->nInteract = 1;
                D2GAME_NPC_Heal_6FCCB220(pGame, pUnit, pNpc);
            }
            return;
        }
    }
}

// 0x00573180
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide)
{
    if (!pMonster)
    {
        return;
    }

    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (!pMonster->pMonsterData)
    {
        return;
    }

    D2MonsterInteractStrc* pMonInteract = pMonster->pMonsterData->pMonInteract;
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        sub_6FC3F340(SUNIT_GetClientFromPlayer(pInteractInfo->pUnit, ".\\MONSTER\\MonsterAI.cpp", 860), 0x62, UNIT_MONSTER, sub_00451F50_GetUnitGUID(pMonster), 0);

        int nInteractType;
        int nInteractGUID;
        if (!bClientSide || (SUNIT_GetInteractInfo(pInteractInfo->pUnit, &nInteractType, &nInteractGUID) && nInteractType == UNIT_MONSTER && nInteractGUID == sub_00451F50_GetUnitGUID(pMonster)))
        {
            SUNIT_ResetInteractInfo(pInteractInfo->pUnit);
        }

        if (pCallback)
        {
            pCallback(pInteractInfo->pUnit);
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 875, 0);
        pInteractInfo = pNext;
    }

    pMonInteract->pInteractInfo = 0;
}
