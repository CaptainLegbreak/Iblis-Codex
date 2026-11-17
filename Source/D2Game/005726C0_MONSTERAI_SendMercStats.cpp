struct D2UnitStrc;
struct D2InteractInfoStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

#define PETTYPE_HIREABLE 7
#define STAT_STRENGTH 0
#define STAT_DEXTERITY 2
#define STAT_HITPOINTS 6
#define STAT_MAXHP 7
#define STAT_LEVEL 12
#define STAT_EXPERIENCE 13
#define STAT_NEXTEXP 30
#define STAT_ARMORCLASS 31
#define STAT_MINDAMAGE 21
#define STAT_MAXDAMAGE 22
#define STAT_SECONDARY_MINDAMAGE 23
#define STAT_SECONDARY_MAXDAMAGE 24
#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short nStatId, int nValue);      // 0x005718C0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);           // 0x00574EC0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

// 0x005726C0
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3)
{
    D2UnitStrc* pMerc = sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (!pMerc)
    {
        return;
    }

    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LEVEL, STATLIST_UnitGetStatValue(pMerc, STAT_LEVEL, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_STRENGTH, STATLIST_GetUnitBaseStat(pMerc, STAT_STRENGTH, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_DEXTERITY, STATLIST_GetUnitBaseStat(pMerc, STAT_DEXTERITY, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXHP, STATLIST_GetUnitBaseStat(pMerc, STAT_MAXHP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_HITPOINTS, STATLIST_UnitGetStatValue(pMerc, STAT_HITPOINTS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_ARMORCLASS, STATLIST_GetUnitBaseStat(pMerc, STAT_ARMORCLASS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_EXPERIENCE, STATLIST_UnitGetStatValue(pMerc, STAT_EXPERIENCE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_NEXTEXP, STATLIST_UnitGetStatValue(pMerc, STAT_NEXTEXP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MINDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MINDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MINDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MAXDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MAXDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_FIRERESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_FIRERESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LIGHTRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_LIGHTRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_COLDRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_COLDRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_POISONRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_POISONRESIST, 0));
}

// 0x00572BA0
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame)
{
    D2MonsterInteractStrc* pMonInteract = (D2MonsterInteractStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2MonsterInteractStrc), ".\\MONSTER\\MonsterAI.cpp", 379, 0);
    pMonInteract->pInteractInfo = 0;
    return pMonInteract;
}
