struct D2DrlgActStrc;

struct T00481920
{
    char unk0x00[0x4];
    int nDaySound;
    int nNightSound;
    int nDayAmbient;
    int nNightAmbient;
    unsigned int nAmbientDelay;
    char unk0x18[0x4];
    int nEntryA;
    int nEntryB;
};

extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634
int gnGlobal_007C8C7C;                                                                                      // 0x007C8C7C
int gnGlobal_007C8C80;                                                                                      // 0x007C8C80
int gnGlobal_007C8C84;                                                                                      // 0x007C8C84
int gnGlobal_007C8C88;                                                                                      // 0x007C8C88
int gnGlobal_007C8C8C;                                                                                      // 0x007C8C8C
int gnGlobal_007C8C90;                                                                                      // 0x007C8C90
unsigned int gnGlobal_007C8C94;                                                                             // 0x007C8C94
unsigned int gnGlobal_007C8C98;                                                                             // 0x007C8C98
void __fastcall sub_004822B0(int nId, int nValue);                                                          // 0x004822B0
void __fastcall sub_00482370(int nId);                                                                      // 0x00482370
int __cdecl sub_004DF870();                                                                                 // 0x004DF870
int __cdecl sub_00481780_GetPlayerLevelId();                                                                // 0x00481780
int __stdcall ENVIRONMENT_GetCycleIndexFromAct(D2DrlgActStrc* pAct);                                        // 0x0061C220
int __cdecl sub_004817A0_GetPlayerSoundEnviron();                                                           // 0x004817A0
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
int __cdecl sub_00473C40();                                                                                 // 0x00473C40
float __cdecl sub_00473C80();                                                                               // 0x00473C80
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
void __fastcall sub_004BA950_RefreshHintsInRangeA(int nGroupA, int nGroupB);                                // 0x004BA950
void __fastcall sub_004BA9D0_RefreshHintsInRangeB(int nGroupA, int nGroupB);                                // 0x004BA9D0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue);                                            // 0x004B9B50
int __fastcall sub_004B9B20(int nHandle);                                                                   // 0x004B9B20
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __fastcall sub_004DF6C0(int nArg);                                                                     // 0x004DF6C0
int __fastcall sub_004E4120(int nRange);                                                                    // 0x004E4120
int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0
int __fastcall sub_004E4100(int nMin, int nMax);                                                            // 0x004E4100
void __fastcall sub_004B99A0(int nHandle, int nPan, int nVolume, int nArg);                                 // 0x004B99A0

static void sub_004E4240_ResetEntryPairs(int nIndex); // 0x004E4240

static void sub_004E4240_ResetEntryPairs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        sub_004822B0(nId, 1);
        sub_004822B0(nId + 0x18, 1);
        nId += 0x30;
    }
}

static __forceinline float GetEnvironVolume_Inline()
{
    return sub_00473C40() ? sub_00473C80() : 0.0f;
}

// 0x004E42E0
void __fastcall sub_004E42E0_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870())
        return;
    const int nLevelId = sub_00481780_GetPlayerLevelId();
    if (!nLevelId)
        return;
    int nSound = 0;
    int nAmbient = 0;
    int nVolume = 0;
    int bNight;
    switch (ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634))
    {
    case 1:
    case 2:
    case 3:
        bNight = 0;
        break;
    default:
        bNight = 1;
        break;
    }
    const int nEnviron = sub_004817A0_GetPlayerSoundEnviron();
    T00481920* pEnv = sub_00481920_GetSoundEnvironTxtRecord(nEnviron);
    if (pEnv)
    {
        if (bNight)
        {
            nAmbient = pEnv->nNightAmbient;
            nSound = pEnv->nNightSound;
        }
        else
        {
            nAmbient = pEnv->nDayAmbient;
            nSound = pEnv->nDaySound;
        }
    }
    int nSecond = sub_00473C40() ? 0x40 : 0;
    if (GetEnvironVolume_Inline() != 0.0f)
    {
        const float fVolume = !sub_00473C40() ? 0.0f : sub_00473C80();
        nVolume = (int)(fVolume * 255.0);
    }
    if (nSound != gnGlobal_007C8C88)
    {
        int bCross = 0;
        if (nSound == pEnv->nDaySound && gnGlobal_007C8C88 == pEnv->nNightSound)
            bCross = 1;
        if (nSound == pEnv->nNightSound && gnGlobal_007C8C88 == pEnv->nDaySound)
            bCross = 1;
        if (bCross)
        {
            sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0, 0, 0xFA);
        }
        else
        {
            sub_004BA950_RefreshHintsInRangeA(nSound, nSecond);
            sub_004BA9D0_RefreshHintsInRangeB(nAmbient, 0);
        }
        if (nSound != gnGlobal_007C8C88)
        {
            if (nSound)
            {
                gnGlobal_007C8C80 = sub_004B9A00(nSound, 0, 0, 0, 0);
                if (bCross)
                {
                    sub_004B9B50_SetHintValue(gnGlobal_007C8C80, 0);
                    sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0xFF, 0, 0xFA);
                }
                gnGlobal_007C8C88 = nSound;
            }
            else
            {
                gnGlobal_007C8C80 = 0;
                gnGlobal_007C8C88 = 0;
            }
        }
    }
    if (nSecond)
    {
        if (nVolume && !gnGlobal_007C8C84)
        {
            gnGlobal_007C8C84 = sub_004B9A00(gnGlobal_007C8C8C, 0, 0, 0, 0);
            if (gnGlobal_007C8C84)
                sub_004B9B50_SetHintValue(gnGlobal_007C8C84, nVolume);
        }
        if (gnGlobal_007C8C84)
        {
            const int nCurrent = sub_004B9B20(gnGlobal_007C8C84);
            int nNext;
            if (nVolume > nCurrent)
                nNext = nVolume < nCurrent + 6 ? nVolume : nCurrent + 6;
            else
                nNext = nVolume > nCurrent - 6 ? nVolume : nCurrent - 6;
            if (nNext)
            {
                sub_004B9B50_SetHintValue(gnGlobal_007C8C84, nNext);
            }
            else
            {
                sub_004BA840(gnGlobal_007C8C84);
                gnGlobal_007C8C84 = 0;
            }
        }
        gnGlobal_007C8C8C = nSecond;
    }
    else
    {
        sub_004BA840(gnGlobal_007C8C84);
        gnGlobal_007C8C84 = 0;
        gnGlobal_007C8C8C = 0;
    }
    sub_004DF6C0(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnGlobal_007C8C90)
        {
            gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            gnGlobal_007C8C98 = dwTick - sub_004E40A0(gnGlobal_007C8C94);
            gnGlobal_007C8C90 = nAmbient;
        }
        if (dwTick - gnGlobal_007C8C98 >= gnGlobal_007C8C94)
        {
            const int nHandle = sub_004B9A00(gnGlobal_007C8C90, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0(2) ? 1 : -1;
                const int nPan = sub_004E4100(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
                sub_004B99A0(nHandle, nPan, nPanVolume, 0);
                gnGlobal_007C8C98 = dwTick;
                gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            }
        }
    }
    if (nLevelId != gnGlobal_007C8C7C)
    {
        const int nEntryA = pEnv->nEntryA;
        const int nEntryB = pEnv->nEntryB;
        for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
            sub_00482370(nId);
        if (nEntryA)
            sub_004E4240_ResetEntryPairs(nEntryA);
        if (nEntryB)
            sub_004E4240_ResetEntryPairs(nEntryB);
        gnGlobal_007C8C7C = nLevelId;
    }
}
