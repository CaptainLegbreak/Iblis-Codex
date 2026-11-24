#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Client.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"

extern "C" const unsigned short gwUniqueModNameIds[];                                                       // 0x00725188

extern "C" { Unicode gwszNameSeparator[1]; }                                                                // 0x007C0C58

int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

typedef void (__fastcall* UMODCALLBACK)(void* pTarget, int nUMod, int bUnique);

struct D2UModCallbacksStrc
{
    UMODCALLBACK pCallbacks[5];
};

extern D2UModCallbacksStrc gaUModCallbacks[]; // 0x00724E28

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

// build: context MONSTERS_CheckMonTypeFlag
static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

// build: context MONSTERUNIQUE_GetUMods
static unsigned char* MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
        return pMonsterData->nMonUmod;
    return 0;
}

// 0x004ADD90
void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, void* pArgument, int nMode)
{
    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);
    if (nMode != 4)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pUnit, nUMod, bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pArgument, nUMod, bUnique);
            }
        }
    }
}

// 0x004ADE40
void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 0);
}

// 0x004ADE50
void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 1);
}

// 0x004ADE60
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 2);
}

// 0x004ADE70
void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 3);
}

// 0x004ADE80
void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pArg && pUnit->dwUnitType == UNIT_MONSTER)
    {
        MONSTER_RunUModCallbacks(pUnit, pArg, 4);
    }
}

// 0x004ADEA0
void __fastcall MONSTER_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId)
{
    wszName->wChar = 0;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUniqueMods = pMonsterData->nMonUmod;
    if (!pUniqueMods)
    {
        return;
    }

    if (MONSTER_IsMinionMonster(pUnit))
    {
        if (nNameId)
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3995));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3221));
        }
        else
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(3221));
        }
        return;
    }

    const int nOldFont = D2Win_10127_SetFont(6);
    int nWidth = 0;
    int nCount = 0;
    int nTextLength = 0;
    if (nNameId)
    {
        nCount = 1;
        Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(nNameId));
        nTextLength = sub_00526800((const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
        nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(nNameId));
    }

    switch (pUnit->dwClassId)
    {
    case 704:
    case 704 + 1:
    case 704 + 2:
    case 704 + 3:
    case 704 + 4:
    case 704 + 5:
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        const int nMod = pUniqueMods[i];
        if (!gwUniqueModNameIds[nMod])
        {
            continue;
        }

        if (nCount && nTextLength + 1 < nLength - 1)
        {
            Unicode::strcat(wszName, gwszNameSeparator);
            ++nTextLength;
            nWidth += D2Win_10121_GetTextWidth(gwszNameSeparator);
        }

        if (nTextLength < nLength - 1)
        {
            const Unicode* wszMod = D2LANG_GetStringFromTblIndex(gwUniqueModNameIds[nMod]);
            if (sub_00526800((const unsigned short*)wszMod) + nTextLength < nLength - 1)
            {
                nTextLength += sub_00526800((const unsigned short*)wszMod);
                nWidth += D2Win_10121_GetTextWidth(wszMod);
                Unicode::strcat(wszName, wszMod);
                ++nCount;
            }
        }

        if (nWidth > 480)
        {
            D2Win_10127_SetFont(nOldFont);
            return;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

#include "gen/data/Source/D2Client/Unknown_004ADD90.inc"
