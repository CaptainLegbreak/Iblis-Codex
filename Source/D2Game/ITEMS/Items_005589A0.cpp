#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_ABS(a) ((a) < 0 ? -(a) : (a))
#define D2_SEED_ROLL(pUnit, nOut) \
    { \
        const unsigned __int64 lSeedRoll = (pUnit)->pSeed.nHighSeed + 0x6AC690C5i64 * (pUnit)->pSeed.nLowSeed; \
        (pUnit)->pSeed.nHighSeed = (unsigned int)(lSeedRoll >> 32); \
        (pUnit)->pSeed.nLowSeed = (unsigned int)lSeedRoll; \
        nOut = (unsigned int)lSeedRoll; \
    }
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
union D2SeedStrc;
struct D2QualityModsStrc;
struct D2TCModsStrc;
struct D2TCExInfoStrc;
struct D2TCArrayStrc;
struct D2ItemsTxt;
struct D2ItemTypesTxt;
struct D2ItemRatioTxt;

struct D2QualityModsStrc
{
    unsigned short f_0;
    unsigned short wRare;
    unsigned short wSet;
    unsigned short wUnique;
    unsigned short wSuperior;
    unsigned short wNormal;
};

struct D2TCModsStrc
{
    unsigned short nMods[6];
};

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    unsigned short nItemId;
    unsigned short nTxtRow;
    unsigned char nFlags;
    char unk0x0D[1];
    D2TCModsStrc tMods;
    unsigned short unk0x1A;
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    short unk0x18;
    D2TCModsStrc tMods;
    short unk0x26;
    D2TCExInfoStrc* pInfo;
};

struct D2TCArrayStrc
{
    D2TCExShortStrc* pTC;
    int nPicks;
    D2TCModsStrc tMods;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue); // 0x00530EA0
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame); // 0x00535790
int __fastcall PARTY_GetLivingPartyMemberCountInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005408E0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType); // 0x00628860
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int nItemId, unsigned char nDifficulty, unsigned short nVersion); // 0x00637910
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall sub_00558610_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2); // 0x00558610
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

enum D2C_ItemQualities
{
    ITEMQUAL_MAGIC = 4,
    ITEMQUAL_TEMPERED = 9,
};

enum
{
    ITEMTYPE_GOLD = 4,
    STAT_GOLD = 14,
};

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
int __fastcall EVENT_GetEventFrame(D2GameStrc*, D2UnitStrc*, int); // 0x005415A0
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc*, D2ActiveRoomStrc*, unsigned char*, unsigned int, int, D2ItemSaveStrc*, unsigned int*, unsigned int); // 0x00558CB0
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc*, D2UnitStrc*, int, int, int*, int, int, int, int); // 0x00562660
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc*, D2UnitStrc*); // 0x005979B0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc*, int, int); // 0x00628170
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc*, unsigned char*, int, int, int, int); // 0x006313E0

static __forceinline D2ItemTypesTxt* sub_C03_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

static int sub_005585D0_GetMagicFindBonus(D2UnitStrc* pPlayer)
{
    if (pPlayer && (unsigned int)pPlayer->dwUnitType <= 1)
    {
        int nMagicBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 0x50, 0);
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nMagicBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x50, 0);
        }
        return nMagicBonus;
    }
    return 0;
}

static int __stdcall sub_00558640_RollItemQuality(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, int nItemId)
{
    int bMagicFind = 0;
    int nChance;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_C03_GetItemTypesTxtRecord(ITEMS_GetItemTypeFromItemId(nItemId));
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    if (pItemTypesTxtRecord->nNormal)
    {
        return 2;
    }

    if (pItemsTxtRecord->nUnique)
    {
        return 7;
    }

    if (pItemTypesTxtRecord->nMagic && pItemsTxtRecord->nQuest)
    {
        return 7;
    }

    D2ItemRatioTxt* pItemRatioTxtRecord = DATATBLS_GetItemRatioTxtRecord(nItemId, pGame->nDifficulty, 100);
    D2_ASSERT(pItemRatioTxtRecord, 0xE8D);

    const int nLevel = nItemLevel - pItemsTxtRecord->nLevel;
    int nMagicFind = sub_005585D0_GetMagicFindBonus(pPlayer);
    if (nMagicFind)
    {
        if (nMagicFind <= -100)
        {
            goto LABEL_SUPERIOR;
        }

        bMagicFind = 1;
    }

    nMagicFind += 100;

    nChance = (pItemRatioTxtRecord->dwUnique - nLevel / pItemRatioTxtRecord->dwUniqueDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 250, 250);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwUniqueMin)
    {
        nChance = pItemRatioTxtRecord->dwUniqueMin;
    }

    nChance -= nChance * pMods->wUnique / 1024;
    if (nChance <= 0)
    {
        return 7;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 7;
    }

    nChance = (pItemRatioTxtRecord->dwSet - nLevel / pItemRatioTxtRecord->dwSetDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 500, 500);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwSetMin)
    {
        nChance = pItemRatioTxtRecord->dwSetMin;
    }

    nChance -= nChance * pMods->wSet / 1024;
    if (nChance <= 0)
    {
        return 5;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 5;
    }

    if (pItemTypesTxtRecord->nRare)
    {
        nChance = (pItemRatioTxtRecord->dwRare - nLevel / pItemRatioTxtRecord->dwRareDivisor) * 128;
        if (bMagicFind)
        {
            const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 600, 600);
            if (nDiminished)
            {
                nChance = nChance * 100 / nDiminished;
            }
        }

        if (nChance <= pItemRatioTxtRecord->dwRareMin)
        {
            nChance = pItemRatioTxtRecord->dwRareMin;
        }

        nChance -= nChance * pMods->wRare / 1024;
        if (nChance <= 0)
        {
            return 6;
        }

        if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
        {
            return 6;
        }
    }

    if (pItemTypesTxtRecord->nMagic)
    {
        return 4;
    }

    nChance = (pItemRatioTxtRecord->dwMagic - nLevel / pItemRatioTxtRecord->dwMagicDivisor) * 128;
    if (bMagicFind)
    {
        nChance = nChance * 100 / nMagicFind;
    }

    if (nChance <= pItemRatioTxtRecord->dwMagicMin)
    {
        nChance = pItemRatioTxtRecord->dwMagicMin;
    }

    nChance -= nChance * pMods->f_0 / 1024;
    if (nChance <= 0)
    {
        return 4;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 4;
    }

LABEL_SUPERIOR:
    nChance = (pItemRatioTxtRecord->dwHiQuality - nLevel / pItemRatioTxtRecord->dwHiQualityDivisor) * 128;
    if (nChance <= 0)
    {
        return 3;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 3;
    }

    nChance = (pItemRatioTxtRecord->dwNormal - nLevel / pItemRatioTxtRecord->dwNormalDivisor) * 128;
    if (nChance <= 0)
    {
        return 2;
    }

    return ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128 ? 2 : 1;
}

// 0x005589A0
static void sub_005589A0_ApplyGoldFind(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    if (pPlayer && pItem && ITEMS_GetItemType(pItem) == 4)
    {
        int nGoldBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 0x4F, 0) + 100;
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nGoldBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x4F, 0);
        }

        const int nGold = STATLIST_UnitGetStatValue(pItem, 0xE, 0);
        D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 0xE, nGold * nGoldBonus / 100);
    }
}

// 0x0055A550
static D2UnitStrc* __stdcall sub_0055A550_CreateDropAtUnit(D2GameStrc* pGame, int nQuality, int nItemIndex, int nFlags, int nItemId, D2UnitStrc* pUnit)
{
    if (nItemId < 0)
    {
        return 0;
    }

    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);

    D2CoordStrc tItemCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &tCoords, &tItemCoords, 1, 1);
    if (!pRoom)
    {
        return 0;
    }

    D2ItemDropStrc tItemDrop;
    memset(&tItemDrop, 0, sizeof(tItemDrop));
    tItemDrop.pGame = pGame;
    tItemDrop.wItemFormat = pGame->wItemFormat;
    tItemDrop.nId = nItemId;
    tItemDrop.pUnit = pUnit;
    tItemDrop.pSeed = 0;
    tItemDrop.nSpawnType = 3;
    tItemDrop.nX = tItemCoords.nX;
    tItemDrop.nY = tItemCoords.nY;
    tItemDrop.pRoom = pRoom;
    tItemDrop.wUnitInitFlags = 1;
    tItemDrop.nQuality = nQuality;

    int nItemLevel = 0;
    if (pUnit)
    {
        if (pUnit->dwUnitType == 1)
        {
            nItemLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
        }
        else if (pUnit->dwUnitType == 0)
        {
            nItemLevel = STATLIST_GetUnitBaseStat(pUnit, 0xC, 0);
        }
        else
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            D2GameStrc* pUnitGame = SUNIT_GetGameFromUnit(pUnit);
            nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pUnitGame->nDifficulty, pUnitGame->bExpansion);
        }
    }
    nItemLevel = D2_MAX(nItemLevel, 1);
    tItemDrop.nItemLvl = nItemLevel;
    tItemDrop.nItemIndex = nItemIndex;

    if (pUnit && pUnit->dwUnitType == 1 && pUnit->dwClassId == 0x187)
    {
        tItemDrop.dwFlags2 = 1;
    }
    tItemDrop.dwFlags2 |= nFlags;

    return D2GAME_CreateItemEx_6FC4ED80(pGame, &tItemDrop, 0);
}

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
                        if (pPlayer->dwUnitType != 0)
                        {
                            pOwner = AIGENERAL_GetMinionOwner(pPlayer);
                        }

                        if (pOwner && pOwner->dwUnitType == 0)
                        {
                            const int nLiving = PARTY_GetLivingPartyMemberCountInSameLevel(pGame, pOwner);
                            nPlayerCount = D2_MIN(D2_MAX(nLiving, 1), 8);
                        }
                    }

                    nPlayerCount += (PLAYER_GetPlayerCount(pGame) - nPlayerCount) / 2;
                    if (pMonster && sub_0044BE50_GetUnitTypeOrInvalid(pMonster) == 1)
                    {
                        int nMonsterPlayers = STATLIST_UnitGetStatValue(pMonster, 100, 0);
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
                else if ((nRand - 1) & nRand)
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
                    nItemQuality = sub_00558640_RollItemQuality(pGame, pMonster, pPlayer, (D2QualityModsStrc*)&tcArray[nCounter].tMods, nLvl, nItemId);
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

            D2UnitStrc* pItem = sub_0055A550_CreateDropAtUnit(pGame, nItemQuality, nItemIndex, nFlags, nItemId, pMonster);
            if (!pItem)
            {
                continue;
            }

            if (ITEMSIsA(pItem, 4) && pTC->pInfo[nIndex].nTxtRow)
            {
                D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 0xE, STATLIST_UnitGetStatValue(pItem, 0xE, 0) * pTC->pInfo[nIndex].nTxtRow >> 8);
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

            sub_005589A0_ApplyGoldFind(pPlayer, pItem);
        }
    }
}

// 0x00558A10
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (ITEMS_IsQuestItem(pUnit))
    {
        return 0;
    }

    const int nItemQuality = ITEMS_GetItemQuality(pUnit);
    if (nItemQuality != ITEMQUAL_MAGIC)
    {
        if (nItemQuality > ITEMQUAL_MAGIC && nItemQuality <= ITEMQUAL_TEMPERED)
        {
            return pGame->dwGameFrame + 45000;
        }

        if (ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
        {
            if (STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) > 10000)
            {
                return pGame->dwGameFrame + 45000;
            }

            return pGame->dwGameFrame + 15000;
        }

        if (ITEMS_IsSocketFiller(pUnit))
        {
            return pGame->dwGameFrame + 30000;
        }

        return pGame->dwGameFrame + 15000;
    }

    return pGame->dwGameFrame + 30000;
}

// 0x0055A2A0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame)
{
    unsigned char aBuffer[1024];
    D2ItemSaveStrc itemSave;
    unsigned int nRead;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    unsigned int nSize = ITEMS_SerializeItemToBitstream(pItem, aBuffer, 1024, 1, 1, 0);
    sub_0062E410(aBuffer, nSize, 1, &itemSave);
    D2UnitStrc* pNewItem = ITEMS_CreateItemFromBitstream(pGame, pRoom, aBuffer, nSize, 1, &itemSave, &nRead, 96);
    if (!pNewItem)
        return 0;
    unsigned char* pBitstream = aBuffer + nRead;
    nSize -= nRead;
    ITEMS_SetItemFlag(pNewItem, 0x80000, 1);
    ITEMS_SetItemFlag(pNewItem, 0x2000, 0);
    if (bAddToGame && itemSave.nItemFileIndex)
    {
        const int nSocketCount = itemSave.nItemFileIndex;
        for (int i = 0; i < nSocketCount; ++i)
        {
            sub_0062E410(pBitstream, nSize, 1, &itemSave);

            D2UnitStrc* __restrict pFiller = ITEMS_CreateItemFromBitstream(pGame, 0, pBitstream, nSize, 1, &itemSave, &nRead, 96);
            if (!pFiller)
                return 0;
            pBitstream += nRead;
            nSize -= nRead;
            UNITS_ChangeAnimMode(pFiller, 4);
            int bPlaced;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pNewItem, !pFiller ? -1 : pFiller->dwUnitId, sub_00451F50_GetUnitGUID(pNewItem), &bPlaced, 0, 1, 0, 0))
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDD4);
                exit(-1);
            }
            ITEMS_SetItemFlag(pFiller, 0x80000, 1);
            ITEMS_SetItemFlag(pFiller, 0x2000, 0);
            ITEMS_SetItemCMDFlag(pFiller, 1, 0);
        }
    }
    ITEMS_SetItemFlag(pItem, 0x8000000, 1);
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pNewItem, 252, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishDurability + 1, 0, 0);
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pNewItem, 253, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishQuantity + 1, 0, 0);
    D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pNewItem);
    ITEMS_SetItemCMDFlag(pNewItem, 1, 0);
    return pNewItem;
}
