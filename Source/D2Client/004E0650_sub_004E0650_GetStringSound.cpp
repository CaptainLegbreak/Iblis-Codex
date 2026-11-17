struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char unk0x000[0x178];
    unsigned char nAnimLen;
    char unk0x179[0x2B];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

struct D2StringSoundStrc
{
    int f_0;
    unsigned short nStringId;
    char unk0x06[0x02];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gdwGlobal_0072AE24;                                                                              // 0x0072AE24
extern D2StringSoundStrc gaStringSounds_0072B0E0[];                                                         // 0x0072B0E0
extern int gnGlobal_007C8C7C;                                                                               // 0x007C8C7C
extern int gnGlobal_007C8C80;                                                                               // 0x007C8C80
extern int gnGlobal_007C8C84;                                                                               // 0x007C8C84
extern int gnGlobal_007C8C88;                                                                               // 0x007C8C88
extern int gnGlobal_007C8C8C;                                                                               // 0x007C8C8C
extern int gnGlobal_007C8C90;                                                                               // 0x007C8C90
extern int gnGlobal_007C8C94;                                                                               // 0x007C8C94
extern int gnGlobal_007C8C98;                                                                               // 0x007C8C98

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E0650
int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId)
{
    if (gdwGlobal_0072AE24)
    {
        for (D2StringSoundStrc* pEntry = gaStringSounds_0072B0E0; pEntry; ++pEntry)
        {
            if (!pEntry->f_0)
            {
                break;
            }

            if (pEntry->nStringId == nStringId)
            {
                return pEntry->f_0;
            }
        }
    }

    return 0;
}

// 0x004E3170
void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor)
{
    if (pMissile && pMissile->dwUnitType == 3 && nDivisor)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord_Inline(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            UNITS_SetAnimationSpeed(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nDivisor);
        }
    }
}

// 0x004E4020
void __fastcall sub_004E4020(D2UnitStrc* pUnit)
{
}

// 0x004E4050
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
}

// 0x004E4280
extern "C" void __cdecl sub_004E4280()
{
    gnGlobal_007C8C7C = 0;
    gnGlobal_007C8C90 = 0;
    gnGlobal_007C8C94 = 0;
    gnGlobal_007C8C98 = 0;
    if (gnGlobal_007C8C80)
    {
        sub_004BA840(gnGlobal_007C8C80);
        gnGlobal_007C8C80 = 0;
    }

    gnGlobal_007C8C88 = 0;
    if (gnGlobal_007C8C84)
    {
        sub_004BA840(gnGlobal_007C8C84);
        gnGlobal_007C8C84 = 0;
    }

    gnGlobal_007C8C8C = 0;
}

#include "gen/data/Source/D2Client/004E0650_sub_004E0650_GetStringSound.inc"
