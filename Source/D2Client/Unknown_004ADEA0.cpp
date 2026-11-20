#include "D2Unicode.h"
struct D2MonsterDataStrc
{
    char unk0[0x1C];
    unsigned char nUniqueMods[10];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0[0xC];
    D2MonsterDataStrc* pMonsterData;
};

extern "C" const unsigned short gwUniqueModNameIds[];                                                       // 0x00725188
extern "C" { Unicode gwszNameSeparator[1]; }                                                                // 0x007C0C58
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0
extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

// 0x004ADEA0
void __fastcall sub_004ADEA0_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId)
{
    wszName->wChar = 0;

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUniqueMods = pMonsterData->nUniqueMods;
    if (!pUniqueMods)
    {
        return;
    }

    if (sub_004AE380_IsMinionMonster(pUnit))
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

    const int nOldFont = sub_00502EF0(6);
    int nWidth = 0;
    int nCount = 0;
    int nTextLength = 0;
    if (nNameId)
    {
        nCount = 1;
        Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(nNameId));
        nTextLength = sub_00526800((const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
        nWidth = sub_00501820(D2LANG_GetStringFromTblIndex(nNameId));
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
            nWidth += sub_00501820(gwszNameSeparator);
        }

        if (nTextLength < nLength - 1)
        {
            const Unicode* wszMod = D2LANG_GetStringFromTblIndex(gwUniqueModNameIds[nMod]);
            if (sub_00526800((const unsigned short*)wszMod) + nTextLength < nLength - 1)
            {
                nTextLength += sub_00526800((const unsigned short*)wszMod);
                nWidth += sub_00501820(wszMod);
                Unicode::strcat(wszName, wszMod);
                ++nCount;
            }
        }

        if (nWidth > 480)
        {
            sub_00502EF0(nOldFont);
            return;
        }
    }

    sub_00502EF0(nOldFont);
}

#include "gen/data/Source/D2Client/Unknown_004ADEA0.inc"
