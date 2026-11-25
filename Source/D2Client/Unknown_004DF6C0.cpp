#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0072ADA8

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2SoundEnvironTxt.h"

struct D2SoundEnvironStrc
{
    int nEnviron;
    float f_4;
    float fEnvDiff;
    int nRoomVol;
    int f_10;
    float f_14;
    float fDecayHF;
    int nReflect;
    float fReflectDelay;
    int f_24;
    float fRevDelay;
    float fRoomRoll;
    float fAirAbsorb;
};

extern int gnSoundEnvironId; // 0x0072ADE4


void __fastcall D2SOUND_SetEaxEnvironment(D2SoundEnvironStrc* pEnviron); // 0x00513C50

// 0x004DF6C0
void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId)
{
    if (nEnvironId == gnSoundEnvironId)
    {
        return;
    }

    D2SoundEnvironTxtStrc* pTxt = SOUNDHDR_GetSoundEnvironTxtRecord(nEnvironId);
// build: symbol ?D2SOUND_IsEaxEnabled@* 0x00513B70
    if ((sub_00514C90_GetSoundMode() == 2 || !nEnvironId) && D2SOUND_IsEaxEnabled())
    {
        D2SoundEnvironStrc tEnviron;
        tEnviron.nEnviron = pTxt->nEAXEnviron;
        tEnviron.f_4 = pTxt->nEAXEnvSize / 1000.0;
        tEnviron.fEnvDiff = pTxt->nEAXEnvDiff / 1000.0;
        tEnviron.nRoomVol = pTxt->nEAXRoomVol;
        tEnviron.f_10 = pTxt->nEAXRoomHF;
        tEnviron.f_14 = pTxt->nEAXDecayTime / 1000.0;
        tEnviron.fDecayHF = pTxt->nEAXDecayHF / 1000.0;
        tEnviron.nReflect = pTxt->nEAXReflect;
        tEnviron.fReflectDelay = pTxt->nEAXReflectDelay / 1000.0;
        tEnviron.f_24 = pTxt->nEAXReverb;
        tEnviron.fRevDelay = pTxt->nEAXRevDelay / 1000.0;
        tEnviron.fRoomRoll = pTxt->nEAXRoomRoll / 1000.0;
        tEnviron.fAirAbsorb = pTxt->nEAXAirAbsorb / 1000.0;
        D2SOUND_SetEaxEnvironment(&tEnviron);
    }

    gnSoundEnvironId = nEnvironId;
}

#include "gen/data/Source/D2Client/Unknown_004DF6C0.inc"
