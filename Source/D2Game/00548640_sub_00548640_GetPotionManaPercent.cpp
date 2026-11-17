struct D2ClientStrc;
struct D2StatListStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2CharStatsTxt
{
    char unk0x00[0x3A];
    unsigned char nManaRegen;
    char unk0x3B[0x89];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2ClientPlayerDataStrc
{
    int dwInactivityTime;
    unsigned short nHitPoints;
    unsigned short nManaPoints;
    unsigned short nStaminaPoints;
    unsigned char nPotionLifePercent;
    unsigned char nPotionManaPercent;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned short nTargetOffsetX;
    unsigned short nTargetOffsetY;
    int dwBeltGold;
    int dwExperience;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList);                                                    // 0x00626090
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);     // 0x00625D00
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void* __fastcall CLIENTS_GetClientPlayerData(D2ClientStrc* pClient);                                        // 0x00539330
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C230
void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C320
void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C3F0
void __fastcall D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(D2ClientStrc* pClient, int nValue, int a3);          // 0x0053E9B0
void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(D2ClientStrc* pClient, int nExperience, int a3); // 0x0053BDD0

#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_EXPERIENCE 13
#define STAT_GOLD 14
#define STAT_MANARECOVERY 26
#define STAT_MANARECOVERYBONUS 27
#define STAT_HPREGEN 74
#define STATE_HEALTHPOT 100
#define STATE_MANAPOT 106

static unsigned char sub_005485B0_GetPotionLifePercent(D2UnitStrc* pUnit)
{
    D2StatListStrc* pHealthPotStatList;
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
    if (pHealthPotStatList && nShiftedMaxHp)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        const int nFrameDiff = D2COMMON_10473(pHealthPotStatList) - pGame->dwGameFrame;
        const unsigned char nPotionLifePercent = 100 * ((nHitpoints + nFrameDiff * STATLIST_GetStatValue(pHealthPotStatList, STAT_HPREGEN, 0)) >> 8) / nShiftedMaxHp;
        return nPotionLifePercent > 100 ? 100 : nPotionLifePercent;
    }

    return 0;
}

static D2CharStatsTxt* sub_00548640_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00548640
static unsigned char sub_00548640_GetPotionManaPercent(D2UnitStrc* pUnit)
{
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_MANAPOT);
    if (!pManaPotStatList || !nMaxMana)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = sub_00548640_GetCharStatsTxtRecord(pUnit ? pUnit->dwClassId : -1);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
    if (!nManaRegen)
    {
        nManaRegen = 7500;
    }

    const int nQuotient = nMaxMana / nManaRegen;
    const int nManaMultiplier = nQuotient < 1 ? 1 : nQuotient;
    const int nRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERYBONUS, 0);
    const int nRecovery = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERY, 0);
    const int nFrameMultiplier = nManaMultiplier * (nRecoveryBonus + 100) / 100 + nRecovery;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const unsigned char nPotionManaPercent = 100 * (nMana + nFrameMultiplier * (D2COMMON_10473(pManaPotStatList) - pGame->dwGameFrame)) / nMaxMana;
    return nPotionManaPercent > 100 ? 100 : nPotionManaPercent;
}

// 0x00548760
int __fastcall sub_6FC82360(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int bSkipHpCheck)
{
    if (!pPlayer || !pUnit)
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 0x1B0);
    if (!pClient)
    {
        return 0;
    }

    D2ClientPlayerDataStrc* pClientPlayerData = (D2ClientPlayerDataStrc*)CLIENTS_GetClientPlayerData(pClient);
    if (!pClientPlayerData)
    {
        return 0;
    }

    const int nShiftedHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nShiftedMaxHp <= 0)
    {
        return 0;
    }

    int nHpDiff = (unsigned short)pClientPlayerData->nHitPoints - nShiftedHitpoints;
    if (nHpDiff < 0)
    {
        nHpDiff = -nHpDiff;
    }

    if (!bSkipHpCheck && (100 * nHpDiff / nShiftedMaxHp < 10 || !nShiftedHitpoints && pClientPlayerData->nHitPoints))
    {
        return 0;
    }

    const int nUnitX = (unsigned short)CLIENTS_GetUnitX(pUnit);
    const int nUnitY = (unsigned short)CLIENTS_GetUnitY(pUnit);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    unsigned char nX = 0;
    unsigned char nY = 0;
    if (pPath)
    {
        nX = nUnitX - D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = nUnitY - D2COMMON_10176_PathGetFirstPointY(pPath);
    }

    const int nShiftedMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >> 8;
    const int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) >> 8;
    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nExperience = STATLIST_UnitGetStatValue(pUnit, STAT_EXPERIENCE, 0);
    const unsigned char nPotionLifePercent = sub_005485B0_GetPotionLifePercent(pUnit);
    const unsigned char nPotionManaPercent = sub_00548640_GetPotionManaPercent(pUnit);

    int bSent = 1;
    if (pClientPlayerData->nPotionLifePercent == nPotionLifePercent && pClientPlayerData->nPotionManaPercent == nPotionManaPercent)
    {
        if (pClientPlayerData->nHitPoints == (unsigned short)nShiftedHitpoints && pClientPlayerData->nManaPoints == (unsigned short)nShiftedMana)
        {
            if (pClientPlayerData->nStaminaPoints == (unsigned short)nStamina)
            {
                if (pClientPlayerData->dwInactivityTime <= 3)
                {
                    bSent = 0;
                }
                else
                {
                    int nXDiff = pClientPlayerData->nPosX - (unsigned short)nUnitX;
                    if (nXDiff < 0)
                    {
                        nXDiff = -nXDiff;
                    }

                    if (nXDiff < 2)
                    {
                        int nYDiff = pClientPlayerData->nPosY - (unsigned short)nUnitY;
                        if (nYDiff < 0)
                        {
                            nYDiff = -nYDiff;
                        }

                        if (nYDiff < 2)
                        {
                            bSent = 0;
                        }
                    }
                }
            }

            if (bSent)
            {
                D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(pClient, nStamina, nUnitX, nUnitY, nX, nY);
            }
        }
        else
        {
            SCMD_SendVitals(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nUnitX, nUnitY, nX, nY);
        }
    }
    else
    {
        SCMD_SendVitalsAndPotionPrediction(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nPotionLifePercent, nPotionManaPercent, nUnitX, nUnitY, nX, nY);
    }

    if (bSent)
    {
        pClientPlayerData->nPosX = nUnitX;
        pClientPlayerData->nPosY = nUnitY;
        pClientPlayerData->nTargetOffsetX = nX;
        pClientPlayerData->nTargetOffsetY = nY;
        pClientPlayerData->dwInactivityTime = 0;
    }
    else
    {
        ++pClientPlayerData->dwInactivityTime;
    }

    if (nGold != pClientPlayerData->dwBeltGold)
    {
        D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(pClient, nGold, pClientPlayerData->dwBeltGold);
        pClientPlayerData->dwBeltGold = nGold;
    }

    if (nExperience != pClientPlayerData->dwExperience)
    {
        D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(pClient, nExperience, pClientPlayerData->dwExperience);
        pClientPlayerData->dwExperience = nExperience;
    }

    pClientPlayerData->nHitPoints = nShiftedHitpoints;
    pClientPlayerData->nStaminaPoints = nStamina;
    pClientPlayerData->nManaPoints = nShiftedMana;
    pClientPlayerData->nPotionLifePercent = nPotionLifePercent;
    pClientPlayerData->nPotionManaPercent = nPotionManaPercent;
    return 1;
}
