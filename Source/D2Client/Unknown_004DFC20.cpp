#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2ClientUi.h"
#include "D2Txt.h"
#include "D2ClientSound.h"

struct D2SoundPosStrc;
struct D2SlotObjectStrc;
struct D2SlotStrc;
struct D2SkillsTxt;
struct D2MissilesTxt;
struct D2MissileStrc;

struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int nSoundId;
    char unk0x08[0x04];
    D2SoundPosStrc tPos;
    char unk0x18[0x04];
    int nVolume;
    float fAttenuation;
};

extern "C" int __cdecl memcmp(const void* pA, const void* pB, unsigned int nSize);
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
float __fastcall SOUNDHDR_GetFalloffVolume(int nIndex); // 0x004825B0
float __fastcall SOUNDHDR_GetFalloffRange(int nIndex); // 0x00482610
float __stdcall GFXUTIL_VectorLength(float fX, float fY); // 0x004E4130
int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0
int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20
void __fastcall D2SOUND_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall D2SOUND_SetSoundPan(D2SoundStrc* pSound, int nPan); // 0x00515890
void __fastcall D2SOUND_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950
void __fastcall D2SOUND_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90
void __fastcall sub_00516830_GetPositionalVolumePan(int* pVolume, int* pPan, float x, float y, float z); // 0x00516830
extern int gnSfxVolume_00727564; // 0x00727564
extern int gnEnvVolume_00727568; // 0x00727568
extern int gbSoundSystemInit; // 0x007C8C78

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gaSkillRingOffsetX[16]; // 0x006DBAF8
extern const int gaSkillRingOffsetY[16]; // 0x006DBAB8
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

// 0x004DFC20
void __fastcall sub_004DFC20_UpdateSoundSlot(D2SlotStrc* pSlot)
{
    if (!pSlot->pObject)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1E7);
        exit(-1);
    }

    D2SlotObjectStrc* const pObject = pSlot->pObject;

    const D2SoundPosStrc* pPos = &pObject->tPos;
    D2SoundsTxt* pRecord = SOUNDHDR_GetSoundRecord(pObject->nSoundId);
    float fMin = SOUNDHDR_GetFalloffVolume(pObject->nSoundId);
    float fMax = SOUNDHDR_GetFalloffRange(pObject->nSoundId);

    int nVolume = pObject->nVolume;
    if (pRecord->bMusicVol)
        nVolume = D2SOUND_GetMusicVolumeOption() * nVolume / 100;
    nVolume = D2SOUND_GetMasterVolumeOption() * nVolume / 100;

    if (gnSfxVolume_00727564 != 100)
    {
        if (!(pObject->nSoundId >= 0x1231 && pObject->nSoundId <= 0x125A) && !(pObject->nSoundId >= 0x34 && pObject->nSoundId <= 0x47)
            && !(pObject->nSoundId >= 1 && pObject->nSoundId <= 0x0F))
            nVolume = gnSfxVolume_00727564 * nVolume / 100;
    }

    if (gnEnvVolume_00727568 != 100 && !pRecord->bSolo)
        nVolume = gnEnvVolume_00727568 * nVolume / 100;

    if (gbSoundSystemInit)
    {
// build: symbol ?D2SOUND_GetSoundMixerOption@* 0x00514C90
        const int nMode = D2SOUND_GetSoundMixerOption();
        if ((nMode == 1 || nMode == 2) && D2SOUND_GetPositionalBiasOption() != 50)
        {
            const int nLevel = (D2SOUND_GetPositionalBiasOption() * 2 - 100) / 3;
            if (pSlot->pSound && nLevel > 0)
                nVolume = (255 - nLevel * 255 / 50) * nVolume / 255;
            if ((pSlot->nType & 2) && nLevel < 0)
                nVolume = (nLevel * 255 / 50 + 255) * nVolume / 255;
        }
    }

    if (nVolume == pSlot->nVolume && pObject->fAttenuation == pSlot->fAttenuation && !memcmp(pPos, &pSlot->tPos, sizeof(D2SoundPosStrc)))
        return;

    int nFinal = nVolume;
    float fDist = GFXUTIL_VectorLength(pPos->fX, pPos->fY);
    if (fDist > fMin)
    {
        float fNum = fMax - fDist;
        float fDen = fMax - fMin;
        nFinal = (int)(fNum * nVolume / fDen);
    }

    nFinal = pRecord->nVolume * nFinal / 255;

    float fX = pPos->fX * 0.0031250000465661287;
    float fY = pPos->fY * 0.0031250000465661287;
    float fZ = pPos->fZ * 0.0031250000465661287;
    if (!pSlot->nType)
    {
        int nPanVolume;
        int nPan;
        sub_00516830_GetPositionalVolumePan(&nPanVolume, &nPan, fX, fY, fZ);
        D2SOUND_SetSoundPan(pSlot->pSound, nPan);
        nFinal = nPanVolume * nFinal / 255;
    }

    if (pSlot->nType & 2)
        D2SOUND_SetSoundPosition(pSlot->pSound, fX, fY, fZ);

    D2SOUND_SetSoundAttenuation(pSlot->pSound, pObject->fAttenuation);
    D2SOUND_SetSoundVolume(pSlot->pSound, nFinal);
    pSlot->tPos = *pPos;
    pSlot->nVolume = nVolume;
    pSlot->fAttenuation = pObject->fAttenuation;
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline D2MissilesTxt* GetMissilesRecord(int nMissile)
{
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissile];
    return 0;
}

// 0x004E1770
int __fastcall sub_004E1770_SpawnSkillMissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    int nMissile = pSkillsTxt->wCltMissileA;
    D2MissilesTxt* pMissilesTxt = 0;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
        pMissilesTxt = &sgptDataTables->pMissilesTxt[nMissile];
    if (pMissilesTxt)
    {
    if (pUnit)
        pUnit->dwFlags |= 0x40;

    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = nMissile;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    missileParams.nVelocity = pMissilesTxt->dwParam[0] << 6;
    int nStep = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nStep < 1)
        nStep = 1;
    for (int i = 0; i < 16; i += 2)
    {
        missileParams.nTargetX = gaSkillRingOffsetX[i];
        missileParams.nTargetY = gaSkillRingOffsetY[i];
        sub_004CD540_CreateMissile(&missileParams);
    }
    missileParams.nVelocity = pMissilesTxt->dwParam[1] << 6;
    if (nStep > 1)
    {
        for (int i = 0; i < 15; i += nStep)
        {
            missileParams.nTargetX = gaSkillRingOffsetX[i + 1];
            missileParams.nTargetY = gaSkillRingOffsetY[i + 1];
            sub_004CD540_CreateMissile(&missileParams);
        }
    }
    return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_004DFC20.inc"
