#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_SetIronGolemItemGUID(D2ClientStrc* pClient, int nIronGolemItemGUID);                // 0x00538700
int __fastcall PLRSAVE2_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc** ppItem, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion); // 0x0056ACE0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

#define PLRSAVE2ERROR_BAD_IRONGOLEM 23
#define SKILL_IRONGOLEM 90

// 0x0056AE50
int __fastcall PLRSAVE2_ReadIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion)
{
    unsigned char* pSection = *ppSection;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    unsigned char* pData = pSection + 2;
    if (pData > pEnd)
    {
        return 0;
    }

    if (*(unsigned short*)pSection != 'fk')
    {
        return PLRSAVE2ERROR_BAD_IRONGOLEM;
    }

    const unsigned char bHasGolem = *pData;
    unsigned char* pSectionEnd = pData + 1;
    unsigned char* pNext = pData + 1;
    if (bHasGolem)
    {
        D2UnitStrc* pItem = 0;
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_IRONGOLEM);
        if (!pSkill)
        {
            return PLRSAVE2ERROR_BAD_IRONGOLEM;
        }

        UNITS_SetUsedSkill(pPlayer, pSkill);

        if (!PLRSAVE2_CreateItem(pGame, pPlayer, &pItem, &pSectionEnd, pEnd, dwVersion))
        {
            return PLRSAVE2ERROR_BAD_IRONGOLEM;
        }

        D2UnitStrc* pGolemItem = pItem;
        UNITS_ChangeAnimMode(pGolemItem, IMODE_ONGROUND);
        CLIENTS_SetIronGolemItemGUID(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 2185), !pGolemItem ? -1 : pGolemItem->dwUnitId);
        pNext = pSectionEnd;
    }

    *ppSection = pNext;
    return 0;
}
