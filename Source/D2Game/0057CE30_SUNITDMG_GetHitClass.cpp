struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x9C];
    unsigned int dwLastHitClass;
    char unk0xB4[0x10];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2SkillStrc;

struct D2StatListStrc;

struct D2ActiveRoomStrc;

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
};

struct D2SkillsTxt
{
    char unk0x000[0x0FC];
    short wStSound;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    char unk0x08[0x44];
    int dwDmgTotal;
    char unk0x50[0x10];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit   ;
    int nX                        ;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2DamageHitClassMappingStrc
{
    int nDamageStrcOffset;
    unsigned int nHitClass;
};

extern "C" const D2DamageHitClassMappingStrc gsDamageHitClassMapping_006E16D8[8];                                    // 0x006E16D8
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A54F0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __fastcall MONSTER_SetAiState(D2UnitStrc* pMonster, int nAiState);                                     // 0x005734C0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall sub_0057CB00(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nHitClass);                        // 0x0057CB00
void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A43A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned char __fastcall sub_6FC62F50(D2UnitStrc* pUnit);                                                   // 0x005A5650
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

static unsigned char s_nHitClassCounter_0088CAD0;                                                                    // 0x0088CAD0

// 0x0057CE30
static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass)
{
    unsigned int nHitClass = 0;
    int nIndex = s_nHitClassCounter_0088CAD0 % 0x04;
    ++s_nHitClassCounter_0088CAD0;

    const int nEnd = nIndex + 0x04;

    while (nIndex < nEnd)
    {
        if (*(int*)((char*)pDamage + gsDamageHitClassMapping_006E16D8[nIndex].nDamageStrcOffset) > 0)
        {
            nHitClass = gsDamageHitClassMapping_006E16D8[nIndex].nHitClass;
            break;
        }

        ++nIndex;
    }

    if (!nHitClass)
    {
        if (pDamage->wResultFlags & 0x2000)
        {
            nHitClass = 0x10;
        }
    }

    if (!nBaseHitClass)
    {
        nBaseHitClass = 0x0D;
    }

    return nBaseHitClass | nHitClass;
}

// 0x0057CEC0
static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF0))
    {
        pDamage->dwHitClass = SUNITDMG_GetHitClass(pDamage, pDamage->dwHitClass);
    }
}

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (UNITS_GetRoom(pUnit) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!pAttacker || pAttacker->dwUnitType != 1)
        {
            return;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[0x0A >> 3] & gdwBitMasks[0x0A & 7]))
        {
            return;
        }
    }

    if (pDamage->wResultFlags & 1)
    {
        sub_0057CEC0_SetHitClassIfUnset(pDamage);
        pUnit->dwLastHitClass = pDamage->dwHitClass;
    }

    if (STATES_CheckState(pUnit, 0x36))
    {
        if (pDamage->wResultFlags & 0x02)
        {
            STATES_ToggleState(pUnit, 0x5C, 1);
        }
        return;
    }

    int nType = 0x06;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
    {
        if (pDamage->wResultFlags & 0x80)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x41);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x100)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x42);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x200)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x44);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);

                if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wStSound > 0)
                    {
                        SUNIT_AttachSound(pUnit, 0x0C, pUnit);
                    }
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & (0x10 | 0x8000))
        {
            if (pDamage->wResultFlags & 0x4000)
            {
                return;
            }

            const int nLastBlockFrame = STATLIST_UnitGetStatValue(pUnit, 0x5F, 0);
            const int nBlockRate = STATLIST_UnitGetStatValue(pUnit, 0x66, 0);
            if ((int)(pGame->dwGameFrame - nLastBlockFrame) > nBlockRate / 0x08 + 0x0F)
            {
                sub_6FC817D0(pGame, pUnit, 0, 0x09, 0, 0, 0);
                STATLIST_SetUnitStat(pUnit, 0x5F, pGame->dwGameFrame, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x02)
        {
            if (pUnit && pUnit->dwAnimMode != 0 && pUnit->dwAnimMode != 0x11)
            {
                D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 0, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x08)
        {
            D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 0x13, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            return;
        }
        else
        {
            if (pDamage->wResultFlags & 0x04)
            {
                if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
                {
                    sub_6FC817D0(pGame, pUnit, 0, 0x04, pDamage->dwDmgTotal, 0, 0);
                    return;
                }
            }
            else
            {
                if (!(pDamage->wResultFlags & 0x4000))
                {
                    return;
                }
            }

            UNITROOM_RefreshUnit(pUnit);
            if (pUnit)
            {
                pUnit->dwFlags |= 0x8000;
            }
            return;
        }
    }
    case 1:
    {
        if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 0x0C)
        {
            return;
        }

        const unsigned short wResultFlags = pDamage->wResultFlags;
        if (wResultFlags & 0x08)
        {
            if (!sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, 0x0D))
            {
                pDamage->wResultFlags = wResultFlags & (unsigned short)(~0x08) | 0x04;
            }
        }

        sub_6FC62DF0(pGame, pAttacker, pUnit, pDamage);

        if (pDamage->wResultFlags & 0x02)
        {
            SUNITDMG_KillMonster(pGame, pUnit, pAttacker, 1);
            return;
        }

        D2ModeChangeStrc modeChange;
        if (pDamage->wResultFlags & 0x08)
        {
            MONSTERMODE_GetModeChangeInfo(pUnit, 0x0D, &modeChange);
            modeChange.pTargetUnit = pAttacker;
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x10)
        {
            if (pDamage->wResultFlags & 0x4000 || pUnit->dwClassId == 0xF3 || pUnit->dwClassId == 0x14D || pUnit->dwClassId == 0x2C1
                || !sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, 0x06))
            {
                MONSTER_SetAiState(pUnit, 0x13);
                return;
            }

            MONSTERMODE_GetModeChangeInfo(pUnit, 0x06, &modeChange);
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x04)
        {
            if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
            {
                MONSTERMODE_GetModeChangeInfo(pUnit, 0x03, &modeChange);
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                sub_6FC6E8A0(pGame, pUnit);
                return;
            }

            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 0x4000)
        {
            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 1 && pDamage->dwDmgTotal > 0)
        {
            const unsigned char nLastHpPct = (unsigned char)STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
            int nHpDiff = nLastHpPct - sub_6FC62F50(pUnit);
            if (nHpDiff < 0)
            {
                nHpDiff = -nHpDiff;
            }

            if (nHpDiff > 0x04)
            {
                UNITROOM_RefreshUnit(pUnit);
                pUnit->dwFlags |= 0x8000;
            }
        }
        return;
    }
    }
}

#include "gen/data/Source/D2Game/0057CE30_SUNITDMG_GetHitClass.inc"
