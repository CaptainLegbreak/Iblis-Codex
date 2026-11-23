#include "D2Client.h"
#include "D2Structs.h"

extern D2NpcSoundStrc gaNpcSounds[];                                                               // 0x0072AE28
extern D2DrlgActStrc* gpAct;                                                                       // 0x007A0634

int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0
int __fastcall SOUNDHDR_PickVariant(int nIndex);                                                        // 0x00482680
int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00

// 0x004E0370
static D2NpcSoundStrc* sub_004E0370_GetNpcSoundRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x94:
        return &gaNpcSounds[0];
    case 0xFE:
        return &gaNpcSounds[1];
    case 0xFC:
        return &gaNpcSounds[2];
    case 0xB0:
        return &gaNpcSounds[3];
    case 0x9A:
        return &gaNpcSounds[5];
    case 0xB1:
        return &gaNpcSounds[6];
    case 0xC7:
        return &gaNpcSounds[7];
    case 0xB2:
        return &gaNpcSounds[8];
    case 0xC8:
        return &gaNpcSounds[9];
    case 0x93:
        return &gaNpcSounds[10];
    case 0xC6:
        return &gaNpcSounds[11];
    case 0x101:
        return &gaNpcSounds[12];
    case 0xFD:
        return &gaNpcSounds[13];
    case 0xC9:
        return &gaNpcSounds[16];
    case 0x96:
        return &gaNpcSounds[17];
    case 0xCA:
        return &gaNpcSounds[18];
    case 0xD2:
        return &gaNpcSounds[19];
    case 0x129:
        return &gaNpcSounds[20];
    case 0xFF:
        return &gaNpcSounds[21];
    case 0x9B:
    case 0xAF:
        return &gaNpcSounds[23];
    case 0x195:
        return &gaNpcSounds[14];
    case 0x92:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0x109:
    case 0x208:
        return &gaNpcSounds[4];
    case 0xFB:
    case 0x209:
        return &gaNpcSounds[22];
    case 0x200:
        return &gaNpcSounds[24];
    case 0x203:
        return &gaNpcSounds[25];
    case 0x202:
        return &gaNpcSounds[28];
    case 0x1FF:
        return &gaNpcSounds[27];
    case 0x201:
        return &gaNpcSounds[26];
    }

    return 0;
}

int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType)
{
    D2NpcSoundStrc* pSound = sub_004E0370_GetNpcSoundRecord(pUnit);
    if (!pSound)
    {
        return 0;
    }

    if (nType == 2)
    {
        return pSound->nGreetSound;
    }

    int nSound;
    for (unsigned int i = 0; i < 20; ++i)
    {
        nSound = pSound->f_0;
        if (!nType && pSound->nDaySound && !sub_004E40A0(2))
        {
            nSound = pSound->nDaySound;
        }

        if (pSound->nNightSound && (!nSound || !sub_004E40A0(3)))
        {
            const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct);
            nSound = pSound->nNightSound;
            if (nCycle != 1)
            {
                if (nCycle >= 2 && nCycle <= 3)
                {
                    nSound += 1;
                }
                else
                {
                    nSound += 2;
                }
            }
        }

        nSound = SOUNDHDR_PickVariant(nSound);
        if (nSound != pSound->nLastSound)
        {
            break;
        }
    }

    pSound->nLastSound = nSound;
    pSound->nLastTick = sub_0044DB00();
    return nSound;
}

#include "gen/data/Source/D2Client/Unknown_004E0370.inc"
