struct D2InventoryStrc;
struct D2PlrIntroStrc;

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    unsigned int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[3][8];
    unsigned char unk0x1C[3][8];
};

#define PLRSAVE2ERROR_BAD_PLAYERINTRO 17
#define PLRSAVE2ERROR_BAD_PET 22
#define STAT_HITPOINTS 6

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                       // 0x006221A0
void __fastcall PLRINTRO_CopyBufferToQuestIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572540
void __fastcall PLRINTRO_CopyBufferToNpcIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer);   // 0x00572550
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0
void __fastcall D2GAME_ITEMS_UpdateInventoryItems_6FC45050(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                // 0x0055F4F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x0056A470
int __fastcall sub_0056A470(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    D2PlrIntroSaveStrc* pPlrIntro = (D2PlrIntroSaveStrc*)*ppSection;
    unsigned char* pSectionEnd = *ppSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    if (pPlrIntro->nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->unk0x04[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->unk0x1C[i]);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056AC10
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* a6)
{
    unsigned char* pSection = *ppSection;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    if (pSection + 2 > pEnd)
    {
        return 0;
    }

    if (*(unsigned short*)pSection != 0x666A)
    {
        if (a6)
        {
            *a6 = 101;
        }

        return PLRSAVE2ERROR_BAD_PET;
    }

    unsigned char* pData = pSection + 2;
    if (pMerc)
    {
        int nError = 0;
        if (sub_0056A7E0(pGame, pMerc, &pData, pEnd, dwVersion, 0, &nError))
        {
            if (a6)
            {
                *a6 = nError;
            }

            return PLRSAVE2ERROR_BAD_PET;
        }

        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
        sub_0055F4F0(pGame, pMerc, 0);
        if (!SUNIT_IsDead(pMerc))
        {
            STATLIST_SetUnitStat(pMerc, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
        }
    }

    *ppSection = pData;
    return 0;
}

// 0x0056AF20
int __fastcall sub_0056AF20_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex)
{
    if (!pUnit->pInventory)
    {
        return -1;
    }

    int nCounter = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (nCounter == nIndex)
        {
            if (pCheckedItem)
            {
                return pCheckedItem->dwUnitId;
            }

            break;
        }

        ++nCounter;
    }

    return -1;
}
