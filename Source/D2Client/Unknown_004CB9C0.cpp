#include "D2Structs.h"

struct D2UnitSndPlayerStrc
{
    int f_0;
    int nDeathSound;
    int nRequestSound[6];
    int nBaseSound;
    int nHintSound;
    int nFootstep;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __cdecl sub_0044DB00(); // 0x0044DB00
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00463DF0(); // 0x00463DF0
void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId); // 0x004A0200
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nFlags, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004B9CA0_GetHintIdByKey(int nKey); // 0x004B9CA0
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit); // 0x004B9E90
void __fastcall sub_004DCD40_ShowTimedHint(int nStringId, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
unsigned int gnLastRequestTick_007C88C4;        // 0x007C88C4
int gnLastRequestSound_007C88C8;        // 0x007C88C8
extern D2UnitSndPlayerStrc* gpUnitSndPlayer_0072A008[]; // 0x0072A008

static __forceinline D2UnitSndPlayerStrc* sub_004CA3E0_GetPlayerSoundRecord(unsigned int nClass)
{
    D2_ASSERT(nClass < 7, 0xB22);
    return gpUnitSndPlayer_0072A008[nClass];
}

// 0x004CB9C0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId)
{
    D2UnitSndPlayerStrc* pRecord = sub_004CA3E0_GetPlayerSoundRecord(pUnit ? pUnit->dwClassId : -1);
    if (!pRecord)
    {
        return;
    }

    int nId = nStringId;
    int nSoundId = 0;
    D2UnitStrc* pSoundUnit = pUnit;
    if (pUnit == sub_00463DD0_GetPlayerUnit() && sub_00463DF0())
    {
        return;
    }

    if (nId >= 0x19 && nId <= 0x20 && !sub_004B9E90_HasUnitSound(pUnit))
    {
        nSoundId = pRecord->nBaseSound + 2 * (nId - 0x19);
    }

    if (nId >= 0x21 && nId <= 0x53)
    {
        int nHintSound = pRecord->nHintSound + nId - 0x21;
        if (nId == 0x23)
        {
            sub_004DCD40_ShowTimedHint(0x1250, 0x0, 0x12C, 1, nHintSound, 0xFA, 1);
            return;
        }

        if (nId == 0x22)
        {
            sub_004DCD40_ShowTimedHint(0x124E, 0x1DB, 0x320, 1, nHintSound, 0x20D, 1);
            return;
        }

        if (nId == 0x25)
        {
            sub_004DCD40_ShowTimedHint(0x0, 0x0, 0x5DC, 0, nHintSound, 0x0, 0);
            return;
        }

        if (nId == 0x21)
        {
            sub_004DCD40_ShowTimedHint(0x124D, 0x0, 0x1DB, 0, nHintSound, 0x1A9, 1);
            return;
        }

        if (nId == 0x32)
        {
            sub_004DCD40_ShowTimedHint(0x1255, 0x1DB, 0x44C, 1, nHintSound, 0x20D, 1);
            return;
        }

        if (nId == 0x34)
        {
            sub_004DCD40_ShowTimedHint(0x1256, 0x0, 0x1A9, 1, nHintSound, 0x177, 1);
            return;
        }

        if (nId == 0x42)
        {
            sub_004DCD40_ShowTimedHint(0x1254, 0x0, 0x1A9, 0, nHintSound, 0x177, 1);
            return;
        }

        if (nId == 0x4B)
        {
            sub_004DCD40_ShowTimedHint(0x1257, 0x0, 0x1DB, 0, nHintSound, 0x145, 1);
            return;
        }

        if (nId == 0x50)
        {
            sub_004DCD40_ShowTimedHint(0x125A, 0x0, 0x1F4, 1, nHintSound, 0x1DB, 1);
            return;
        }

        if (nId == 0x52)
        {
            sub_004DCD40_ShowTimedHint(0x1259, 0x0, 0x226, 1, nHintSound, 0x190, 1);
            return;
        }

        if (nId == 0x53)
        {
            sub_004DCD40_ShowTimedHint(0x1258, 0x0, 0x20D, 1, nHintSound, 0x1A9, 1);
            return;
        }

        int nFlags;
        switch (nId)
        {
        case 0x26:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2E:
        case 0x2F:
        case 0x37:
        case 0x38:
            nFlags = 0;
            break;

        default:
            nFlags = 0xC;
            break;
        }

        sub_004A0200_SetSpeechHoverText(pUnit, sub_004B9CA0_GetHintIdByKey(sub_004B9A00(nHintSound, pUnit, nFlags, 0, 0)));
        return;
    }

    int bCheckRepeat = 0;
    switch (nId)
    {
    case 0x13:
        nSoundId = pRecord->nRequestSound[0];
        bCheckRepeat = 1;
        break;

    case 0x15:
        nSoundId = pRecord->nRequestSound[1];
        bCheckRepeat = 1;
        break;

    case 0x16:
        nSoundId = pRecord->nRequestSound[2];
        bCheckRepeat = 1;
        break;

    case 0x17:
        nSoundId = pRecord->nRequestSound[3];
        bCheckRepeat = 1;
        break;

    case 0x14:
        nSoundId = pRecord->nRequestSound[4];
        bCheckRepeat = 1;
        break;

    case 0x18:
        nSoundId = pRecord->nRequestSound[5];
        bCheckRepeat = 1;
        break;

    case 1:
        nSoundId = 0xEB;
        break;

    case 2:
        nSoundId = 7;
        pSoundUnit = 0;
        break;

    case 3:
        nSoundId = 0xA;
        pSoundUnit = 0;
        break;

    case 4:
        nSoundId = 0xB;
        pSoundUnit = 0;
        break;

    case 5:
        nSoundId = 0xC;
        pSoundUnit = 0;
        break;

    case 6:
        nSoundId = 0xD;
        pSoundUnit = 0;
        break;

    case 7:
        nSoundId = 0x8B6;
        break;

    case 8:
        nSoundId = 0x8B7;
        break;

    case 9:
        nSoundId = 9;
        break;

    case 11:
        nSoundId = 0xE4;
        break;
    }

    if (bCheckRepeat && sub_004B9E90_HasUnitSound(pUnit))
    {
        return;
    }

    if (!nSoundId)
    {
        return;
    }

    if (bCheckRepeat)
    {
        unsigned int nTick = sub_0044DB00();
        if (nSoundId == gnLastRequestSound_007C88C8 && nTick - gnLastRequestTick_007C88C4 < 0x4B)
        {
            return;
        }

        gnLastRequestTick_007C88C4 = nTick;
        gnLastRequestSound_007C88C8 = nSoundId;
    }

    sub_004A0200_SetSpeechHoverText(pUnit, sub_004B9CA0_GetHintIdByKey(sub_004B9A00(nSoundId, pSoundUnit, 0, 0, 0)));
}
