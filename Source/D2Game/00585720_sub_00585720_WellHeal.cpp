struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2ObjectsTxt
{
    char unk0x00[0x178];
    int dwParm[8];
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STATE_FREEZE 1
#define STATE_POISON 2
#define EVENTTYPE_AITHINK 2

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord);                    // 0x00552AA0
unsigned char __fastcall sub_00552AB0();                                                    // 0x00552AB0
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit);                                         // 0x00578C20
void __fastcall OBJMODE_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pUnit2, void* pUnitHealed); // 0x005856A0
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B30
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0

// 0x00585720
static int __stdcall sub_00585720_WellHeal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ObjectsTxt* pObjectsTxtRecord)
{
    int bUsed = 0;

    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
    const int nFlags = pObjectsTxtRecord->dwParm[3];
    if (nLife < nMaxLife && (nFlags & 2))
    {
        unsigned int nNewLife = nLife + (nMaxLife * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewLife > nMaxLife)
        {
            nNewLife = nMaxLife;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nNewLife, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_HITPOINTS, nNewLife, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);
    if (nMana < nMaxMana && (nFlags & 1))
    {
        unsigned int nNewMana = nMana + (nMaxMana * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewMana > nMaxMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_MANA, nNewMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_MANA, nNewMana, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    const unsigned int nStamina = STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0);
    if (nStamina < nMaxStamina)
    {
        unsigned int nNewStamina = nStamina + (nMaxStamina * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewStamina > nMaxStamina)
        {
            nNewStamina = nMaxStamina;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nNewStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_STAMINA, nNewStamina, pPlayer);
        bUsed = 1;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_POISON);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_FREEZE);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pPlayer))
    {
        bUsed = 1;
    }

    PLAYERPETS_IteratePets(pGame, pPlayer, OBJMODE_PetIterate_Heal, &bUsed);
    return bUsed;
}

// 0x005858A0
int __fastcall OBJECTS_OperateFunction22_Well(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pOp->pObject);
    unsigned char nType = pOp->pObject->pObjectData->InteractType;
    if (nType)
    {
        if (sub_00585720_WellHeal(pOp->pGame, pOp->pPlayer, pObjectsTxtRecord))
        {
            nType -= 1;
            const unsigned char nMax = sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord);
            if (nType <= nMax && !(nType % (unsigned char)(nMax / sub_00552AB0())))
            {
                UNITS_ChangeAnimMode(pOp->pObject, sub_00552AB0() - nType / pObjectsTxtRecord->dwParm[2]);
            }

            pOp->pObject->pObjectData->InteractType = nType;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_AITHINK, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[0] + 1, 0, 0);
        }
    }
    return 0;
}
