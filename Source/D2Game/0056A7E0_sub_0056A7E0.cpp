struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0xAD];
    unsigned char bChangeToSpecialObjectModeOutsideTown;
    unsigned char bChangeToSpecialObjectModeInTown;
    char unk0xAF[0x2D];
    int nObjectUpdateInvocations;
};

#define UNITFLAG_SKSRVDOFUNC 0x00000040
#define UNITFLAG_HASEVENTSOUND 0x00000400
#define UNITFLAG_HASTXTMSG 0x00000100
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAGEX_HASINV 0x00000001
#define UNITFLAGEX_ITEMINIT 0x00000010
#define PLRMODE_NEUTRAL 1
#define PLRMODE_TOWNNEUTRAL 5
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define OBJMODE_SPECIAL1 3
#define OBJMODE_SPECIAL2 4
#define LEVEL_HARROGATH 109

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);           // 0x00553990
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553490
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);                                       // 0x00554CA0
void __fastcall sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0056FC50
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __fastcall sub_6FC752A0(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00581A20
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient);                       // 0x00571740
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571620
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00597890
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571CD0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x0056A7E0
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError)
{
    unsigned char* pSection = *ppSection;
    int nSize = 0;
    const int nError = sub_005337F0_ReadItems(pGame, pUnit, pSection, nVersion, pEnd - pSection, 0, &nSize);
    if (nError)
    {
        if (pError)
        {
            *pError = nError;
        }
        return 0x14;
    }

    *ppSection = pSection + nSize;
    return 0;
}

// 0x00577670
D2UnitStrc* __fastcall sub_00577670_FindInventoryItemByClassId(D2UnitStrc* pUnit, int nClassId)
{
    if (pUnit->pInventory)
    {
        D2UnitStrc* pNext;
        for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
        {
            D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
            pNext = INVENTORY_GetNextItem(pItem);
            if ((!pCheck ? -1 : pCheck->dwClassId) == nClassId && !UNIT_HasFlagEx(pCheck, UNITFLAGEX_ITEMINIT))
            {
                return pCheck;
            }
        }
    }

    return 0;
}

// 0x0057F020
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        nMode = DUNGEON_IsRoomInTown(pRoom) != 0 ? PLRMODE_TOWNNEUTRAL : PLRMODE_NEUTRAL;
    }

    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetUsedSkill(pPlayer, 0);
}

// 0x00580460
int __fastcall sub_6FC80EE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 2;
    }

    UNITS_SetAnimationFrame(pPlayer, nSkillLevel);

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 1 && (sub_6FCBC7E0(pGame, pPlayer), sub_6FCBC930(pGame, pPlayer) == 2))
    {
        SKILLS_SetFlags(pSkill, nSkillFlags | 2);
    }
    else
    {
        if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_SKSRVDOFUNC) || nSkillId != 1 && nSkillId != 2)
        {
            return (SUNIT_IsDead(pPlayer) != 0) + 1;
        }
    }

    sub_6FD13410(pGame, pPlayer);
    return (SUNIT_IsDead(pPlayer) != 0) + 1;
}

// 0x00581AD0
void __fastcall sub_6FC75350(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (pUnit)
    {
        if (UNIT_HasFlag(pUnit, UNITFLAG_DOUPDATE))
        {
            sub_6FC752A0(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASEVENTSOUND))
        {
            D2GAME_UpdateUnit_6FCC6080(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASTXTMSG))
        {
            sub_00571620(pUnit, pClient);
        }

        if (UNIT_HasFlagEx(pUnit, UNITFLAGEX_HASINV))
        {
            D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
        }
    }

    sub_6FCC6540(pUnit, pClient);
}

// 0x0058A730
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    switch (nAnimMode)
    {
    case OBJMODE_OPERATING:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
        if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_HARROGATH)
        {
            if (++pQuestDataEx->nObjectUpdateInvocations > 5)
            {
                pQuestDataEx->bChangeToSpecialObjectModeInTown = 1;
            }

            if (pQuestDataEx->bChangeToSpecialObjectModeInTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        else
        {
            if (pQuestDataEx->bChangeToSpecialObjectModeOutsideTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        break;
    }

    case OBJMODE_SPECIAL1:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL2);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}
