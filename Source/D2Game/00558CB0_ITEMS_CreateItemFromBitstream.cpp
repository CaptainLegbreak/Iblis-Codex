struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ItemsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char pad0x09[3];
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit);               // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit);                 // 0x00558580
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

static int ITEMS_GetItemsTxtRecordCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
    {
        return 0;
    }

    return pItemDataTbl->nItemsTxtRecordCount;
}

// 0x00558CB0
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion)
{
    if (!pGame)
    {
        return 0;
    }

    if (pItemSave->nClassId < 0 || pItemSave->nClassId >= ITEMS_GetItemsTxtRecordCount())
    {
        *pSize = 0;
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_AllocUnitData(4, pItemSave->nClassId, pItemSave->nX, pItemSave->nY, pGame, pRoom, 1, pItemSave->nAnimMode, 0);
    if (!pItem)
    {
        return 0;
    }

    int bFail;
    *pSize = ITEMS_DecodeItemFromBitstream(pItem, pBitstream, nBufferSize, bCheckForHeader, 0, dwVersion, &bFail);
    if (!*pSize || bFail)
    {
        SUNIT_RemoveUnit(pGame, pItem);
        return 0;
    }

    ITEMS_SetItemFlag(pItem, 0x80000, 1);
    ITEMS_SetItemFlag(pItem, 0x2000, 0);
    ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
    ITEMS_ScheduleQuantityReplenishment(pGame, pItem);
    return pItem;
}

// 0x0056A370
int __fastcall sub_0056A370_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + 298;
    if (pSectionEnd > pEnd)
    {
        return 15;
    }

    const D2SaveHeaderStrc* pQuestHeader = (const D2SaveHeaderStrc*)pSection;
    if (pQuestHeader->dwHeaderMagic != 0x216F6F57)
    {
        return 15;
    }

    if (pQuestHeader->dwVersion != 6)
    {
        return 15;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], &pSection[10 + 96 * i], 96, 1);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056B6C0
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit)
{
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) > nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, 6, nMaxHp, 0);
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 8, 0) > nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, 8, nMaxMana, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, 10, 0) > nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, 10, nMaxStamina, 0);
    }

    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\Skills.cpp", 267);
}

// 0x0056C2D0
int __fastcall sub_0056C2D0_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}
