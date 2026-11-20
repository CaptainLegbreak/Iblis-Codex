#include "D2Client.h"

struct T00481920
{
    int f_0;
    char unk0x04[0x20];
    int nEAXEnviron;
};

struct D2HintCursorStrc
{
    char unk0x00[0x50];
    int aValues[4];
};

struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    unsigned int nEndTickA;
    int bActive2;
    int nArgE;
    unsigned int nEndTickF;
    int nArgG;
    unsigned int nEndTickC;
};

unsigned int gnGlobal_007C89D0;                                                                             // 0x007C89D0
unsigned int gnGlobal_007C89D4;                                                                             // 0x007C89D4
int gnGlobal_007C89D8;                                                                                      // 0x007C89D8
int gnGlobal_007C89DC;                                                                                      // 0x007C89DC
unsigned int gnGlobal_007C89E0;                                                                             // 0x007C89E0
D2TimedHintStrc gTimedHint_007C89E4;                                                                        // 0x007C89E4
int gnGlobal_007C8A04;                                                                                      // 0x007C8A04

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl sub_00481780_GetPlayerLevelId();                                                                // 0x00481780
int __cdecl sub_004817F0();                                                                                 // 0x004817F0
int __cdecl sub_00481800();                                                                                 // 0x00481800
int __cdecl sub_00481810();                                                                                 // 0x00481810
D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
int __fastcall sub_004B9590(void* pEntry);                                                                  // 0x004B9590
void* __fastcall sub_004B9610(int nId);                                                                     // 0x004B9610
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __cdecl sub_004B9C60_IsSongPlaying();                                                                   // 0x004B9C60
int __fastcall sub_004B9D50_GetPosition(void* pEntry);                                                      // 0x004B9D50
void __fastcall sub_004BA890_RefreshHintsById(int nHintId);                                                 // 0x004BA890
void __cdecl sub_004CC270_CheckLevelSpeech();                                                               // 0x004CC270
int __cdecl sub_00514CC0();                                                                                 // 0x00514CC0
int __cdecl sub_00514CF0();                                                                                 // 0x00514CF0

// 0x004DCAA0
void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int dwTick)
{
    int nLevelId = sub_00481780_GetPlayerLevelId();
    if (!nLevelId)
    {
        return;
    }

    if (nLevelId != gnGlobal_007C89DC)
    {
        gnGlobal_007C89DC = nLevelId;
        gnGlobal_007C89D0 = dwTick;
    }

    int nSong = 0;
    T00481920* pSoundEnvironTxtRecord = sub_00481920_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
    if (pSoundEnvironTxtRecord)
    {
        nSong = pSoundEnvironTxtRecord->f_0;
        if (nSong && (nSong < sub_004817F0() || nSong > sub_00481800()))
        {
            nSong = 0;
        }
    }

    int bEnabled = sub_00514CC0() && sub_00514CF0() ? 1 : 0;
    int bChange = 0;
    if (!gnGlobal_007C89D8)
    {
        bChange = 1;
    }

    if (!bEnabled)
    {
        bChange = 1;
    }

    if (dwTick - gnGlobal_007C89D0 >= 0x4B)
    {
        bChange = 1;
    }

    if (gnGlobal_007C89D8 != nSong && bChange)
    {
        gnGlobal_007C89D8 = nSong;
        gnGlobal_007C89E0 = dwTick;
    }

    if (!bEnabled)
    {
        sub_004BA8F0();
    }

    if (!gnGlobal_007C89D8)
    {
        sub_004BA8F0();
    }

    if (gTimedHint_007C89E4.bActive)
    {
        if (gTimedHint_007C89E4.bActive2 && sub_0044DB00() >= gTimedHint_007C89E4.nEndTickA)
        {
            sub_004B9A00((int)gTimedHint_007C89E4.pOwner, 0, 0, 0, 0);
            gTimedHint_007C89E4.bActive2 = 0;
        }

        if (gTimedHint_007C89E4.nArgG && sub_0044DB00() >= gTimedHint_007C89E4.nEndTickF)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            if (!sub_00464820_IsDeadOrDying(pPlayer))
            {
                sub_004B9A00(gTimedHint_007C89E4.nArgE, pPlayer, 0, 0, 0);
            }

            gTimedHint_007C89E4.nArgG = 0;
        }

        if (sub_0044DB00() < gTimedHint_007C89E4.nEndTickC)
        {
            return;
        }

        gTimedHint_007C89E4.bActive = 0;
        if (bEnabled)
        {
            sub_004BA890_RefreshHintsById((int)gTimedHint_007C89E4.pOwner);
        }
    }

    if (gnGlobal_007C89D8 && bEnabled && !sub_004B9610(gnGlobal_007C89D8))
    {
        const int nOffset = 4 * (gnGlobal_007C89D8 - sub_004817F0());
        int nValue = *(int*)(sub_00481810() + nOffset);
        int nMode = !sub_004B9C60_IsSongPlaying() && !nValue ? 2 : 0;
        sub_004BA8F0();
        sub_004B9A00(gnGlobal_007C89D8, 0, 0, nMode, nValue);
        gnGlobal_007C89D4 = dwTick;
    }

    if (gnGlobal_007C89DC != gnGlobal_007C8A04 && dwTick - gnGlobal_007C89D0 >= 0x3E)
    {
        sub_004CC270_CheckLevelSpeech();
        gnGlobal_007C8A04 = gnGlobal_007C89DC;
    }

    if (!gnGlobal_007C89D8 || dwTick <= gnGlobal_007C89E0 + 0x7D)
    {
        return;
    }

    D2HintCursorStrc* pCursor = sub_00481860(gnGlobal_007C89D8);
    void* pEntry = sub_004B9610(gnGlobal_007C89D8);
    if (!pEntry || !sub_004B9590(pEntry))
    {
        return;
    }

    int nPosition = sub_004B9D50_GetPosition(pEntry);
    int nValue = 0;
    if (nPosition >= 0 && nPosition < pCursor->aValues[1])
    {
        nValue = pCursor->aValues[1];
    }

    if (nPosition >= pCursor->aValues[1] && nPosition < pCursor->aValues[2])
    {
        nValue = pCursor->aValues[2];
    }

    if (nPosition >= pCursor->aValues[2] && nPosition < pCursor->aValues[3])
    {
        nValue = pCursor->aValues[3];
    }

    const int nOffset = 4 * (gnGlobal_007C89D8 - sub_004817F0());
    *(int*)(sub_00481810() + nOffset) = nValue;
    gnGlobal_007C89E0 = dwTick;
}
