#include "D2Structs.h"


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __fastcall sub_004B9B20(int nHandle);                                                                   // 0x004B9B20
void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue);                                            // 0x004B9B50
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

static int gnGlobal_007B8D10;                                                                               // 0x007B8D10
static int gnGlobal_007B8D14;                                                                               // 0x007B8D14
static int gnGlobal_007B8D18;                                                                               // 0x007B8D18
static int gnGlobal_007B8D1C;                                                                               // 0x007B8D1C
static int gnGlobal_007B8D20;                                                                               // 0x007B8D20
extern int gnGlobal_007B8D2C;                                                                               // 0x007B8D2C
static int gnGlobal_007B9534;                                                                               // 0x007B9534
static int gnGlobal_007B9538;                                                                               // 0x007B9538

// 0x004769D0
static void sub_004769D0_UpdateShakeSound(int nIntensity)
{
    int nVolume = nIntensity * 0xFF / 20;
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 0xFF)
    {
        nVolume = 0xFF;
    }

    if (nVolume && !gnGlobal_007B8D2C)
    {
        gnGlobal_007B8D2C = sub_004B9A00(0x1C4, 0, 0, 0, 0);
        if (!gnGlobal_007B8D2C)
        {
            return;
        }
        sub_004B9B50_SetHintValue(gnGlobal_007B8D2C, 0);
    }

    if (!gnGlobal_007B8D2C)
    {
        return;
    }

    const int nCurrent = sub_004B9B20(gnGlobal_007B8D2C);
    if (nVolume == nCurrent)
    {
        return;
    }

    int nNew;
    if (nVolume > nCurrent)
    {
        nNew = nCurrent + 6;
        if (nVolume < nNew)
        {
            nNew = nVolume;
        }
    }
    else
    {
        nNew = nCurrent - 6;
        if (nVolume > nNew)
        {
            nNew = nVolume;
        }
    }

    if (nNew)
    {
        sub_004B9B50_SetHintValue(gnGlobal_007B8D2C, nNew);
        return;
    }

    sub_004BA840(gnGlobal_007B8D2C);
    gnGlobal_007B8D2C = 0;
}

// 0x00476D40
void __fastcall sub_00476D40_AdjustViewPos(int* pX, int* pY)
{
    const unsigned int nTick = GetTickCount();
    const unsigned int nElapsed = nTick - gnGlobal_007B8D10;
    const unsigned int nFadeIn = gnGlobal_007B8D14;
    const unsigned int nHold = gnGlobal_007B8D18;
    const unsigned int nFadeOut = gnGlobal_007B8D1C;
    int nMagnitude = 0;
    if (nElapsed > nFadeOut + nHold + nFadeIn)
    {
        sub_004769D0_UpdateShakeSound(nMagnitude);
        gnGlobal_007B9534 = 0;
        gnGlobal_007B9538 = 0;
        gnGlobal_007B8D20 = 0;
        return;
    }

    if (nElapsed < nFadeIn)
    {
        if (nFadeIn)
        {
            nMagnitude = gnGlobal_007B9534 * nElapsed / nFadeIn;
        }
    }
    else if (nElapsed < nHold + nFadeIn)
    {
        nMagnitude = gnGlobal_007B9534;
    }
    else if (nFadeOut)
    {
        nMagnitude = (nFadeOut - nElapsed + nHold + nFadeIn) * gnGlobal_007B9534 / nFadeOut;
    }

    if (nMagnitude)
    {
        D2SeedStrc* pSeed = &sub_00463DD0()->pSeed;
        gnGlobal_007B9538 = sub_00472280(pSeed, -nMagnitude, 2 * nMagnitude);
        const int nOffsetY = sub_00472280(pSeed, -nMagnitude, 2 * nMagnitude);
        *pX += gnGlobal_007B9538;
        *pY += nOffsetY;
        gnGlobal_007B8D20 = nOffsetY;
    }
    sub_004769D0_UpdateShakeSound(nMagnitude);
}
