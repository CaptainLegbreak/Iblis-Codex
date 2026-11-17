struct D2ClientStrc;
struct D2MonsterInteractStrc;
struct D2BitBufferStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short unk0x02;
    int dwSeed;
    int bHired;
    int unk0x0C;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2MercDataStrc* pMercData;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel);                         // 0x00576890
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C310
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass); // 0x00575FF0
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId);        // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost);                  // 0x00576D90
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit);                           // 0x00535E80
int __fastcall MONSTERAI_GetInteractUnitCount(D2MonsterInteractStrc* pMonInteract);                         // 0x00572DA0
void __fastcall sub_00576770_VendorUpdate(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bSingle); // 0x00576770
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord);  // 0x00577010

// 0x005770E0
void __fastcall SUNITNPC_HireMercenaryFromRoster(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, unsigned short wName)
{
    int nLevel = STATLIST_UnitGetStatValue(pPlayer, 0x0C, 0);
    nLevel = sub_00576890(pGame, pNpc, nLevel);
    UNITS_GetPlayerData(pPlayer);

    if (pNpc)
    {
        if (pNpc->dwClassId == 0x203)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x24, 0))
            {
                sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x654), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
                return;
            }
        }

        if (pNpc->dwClassId == 0x96 && nLevel < 8)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 2, 0))
            {
                sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x65F), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
                return;
            }
        }
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x66C), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    int nVendorId;
    if (!pNpc)
    {
        nVendorId = -1;
    }
    else
    {
        nVendorId = pNpc->dwClassId;
    }

    int nNameFirst;
    int nNameLast;
    int nClass;
    sub_00575FF0(pGame, nVendorId, &nNameFirst, &nNameLast, &nClass);

    if (wName < nNameFirst || wName > nNameLast)
    {
        sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x685), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2MercDataStrc* pMercData = &pNpcRecord->pMercData[wName - nNameFirst];
    if (pMercData->nMercName != wName)
    {
        sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x693), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    if (pMercData->bHired)
    {
        sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x69A), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2HirelingInitStrc hirelingInit;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    if (!sub_00576D90_SpendGold(pGame, pPlayer, hirelingInit.nGold))
    {
        sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x6AE), 0x2A, 0x0C, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
        return;
    }

    D2UnitStrc* pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pNpc, nClass, 1, 4, 0);
    if (!pMerc)
    {
        pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 4, 0);
        if (!pMerc)
        {
            sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x6BA), 0x2A, 0x0F, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), -1, 0);
            return;
        }
    }

    pMercData->bHired = 1;
    MONSTERAI_AssignHireling(pGame, pPlayer, pMerc, -1, pMercData, 0);
    sub_00576770_VendorUpdate(pGame, SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x6C5), pNpc, MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)) <= 1);
    sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 0x6C6), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, 0x0E, 0), !pMerc ? -1 : pMerc->dwUnitId, 0);
    sub_00577010_VendorRefresh(pGame, nVendorId, pNpcRecord);
}
