struct D2SoundStrc;

struct D2SoundPosStrc
{
    float fX;
    float fY;
    float fZ;
};

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

struct D2SoundRecordStrc
{
    char unk0x00[0x3C];
    unsigned char nVolume;
    char unk0x3D[0x15];
    unsigned char bNoEnvVolume;
    unsigned char bMusic;
};

struct D2SlotStrc
{
    D2SoundStrc* pSound;
    int nType;
    D2SlotObjectStrc* pObject;
    D2SoundPosStrc tPos;
    int nVolume;
    float fAttenuation;
};

extern "C" int __cdecl memcmp(const void* pA, const void* pB, unsigned int nSize);
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

D2SoundRecordStrc* __fastcall sub_00481860(int nId);                                                        // 0x00481860
float __fastcall sub_004825B0_GetCacheVolume(int nIndex);                                                   // 0x004825B0
float __fastcall sub_00482610_GetCacheRange(int nIndex);                                                    // 0x00482610
float __stdcall sub_004E4130_Length2D(float fX, float fY);                                                  // 0x004E4130
int __cdecl sub_00514C90();                                                                                 // 0x00514C90
int __cdecl sub_00514CC0();                                                                                 // 0x00514CC0
int __cdecl sub_00514CF0();                                                                                 // 0x00514CF0
int __cdecl sub_00514D20();                                                                                 // 0x00514D20
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
void __fastcall sub_00515890_SetSoundPan(D2SoundStrc* pSound, int nPan);                                    // 0x00515890
void __fastcall sub_00515950_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z);              // 0x00515950
void __fastcall sub_00515A90_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation);                  // 0x00515A90
void __fastcall sub_00516830_GetVolumePan(int* pVolume, int* pPan, float x, float y, float z);              // 0x00516830

extern int gnSfxVolume_00727564;                                                                            // 0x00727564
extern int gnEnvVolume_00727568;                                                                            // 0x00727568
extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78

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
    D2SoundRecordStrc* pRecord = sub_00481860(pObject->nSoundId);
    float fMin = sub_004825B0_GetCacheVolume(pObject->nSoundId);
    float fMax = sub_00482610_GetCacheRange(pObject->nSoundId);

    int nVolume = pObject->nVolume;
    if (pRecord->bMusic)
        nVolume = sub_00514CF0() * nVolume / 100;
    nVolume = sub_00514CC0() * nVolume / 100;

    if (gnSfxVolume_00727564 != 100)
    {
        if (!(pObject->nSoundId >= 0x1231 && pObject->nSoundId <= 0x125A) && !(pObject->nSoundId >= 0x34 && pObject->nSoundId <= 0x47)
            && !(pObject->nSoundId >= 1 && pObject->nSoundId <= 0x0F))
            nVolume = gnSfxVolume_00727564 * nVolume / 100;
    }

    if (gnEnvVolume_00727568 != 100 && !pRecord->bNoEnvVolume)
        nVolume = gnEnvVolume_00727568 * nVolume / 100;

    if (gdwGlobal_007C8C78)
    {
        const int nMode = sub_00514C90();
        if ((nMode == 1 || nMode == 2) && sub_00514D20() != 50)
        {
            const int nLevel = (sub_00514D20() * 2 - 100) / 3;
            if (pSlot->pSound && nLevel > 0)
                nVolume = (255 - nLevel * 255 / 50) * nVolume / 255;
            if ((pSlot->nType & 2) && nLevel < 0)
                nVolume = (nLevel * 255 / 50 + 255) * nVolume / 255;
        }
    }

    if (nVolume == pSlot->nVolume && pObject->fAttenuation == pSlot->fAttenuation && !memcmp(pPos, &pSlot->tPos, sizeof(D2SoundPosStrc)))
        return;

    int nFinal = nVolume;
    float fDist = sub_004E4130_Length2D(pPos->fX, pPos->fY);
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
        sub_00516830_GetVolumePan(&nPanVolume, &nPan, fX, fY, fZ);
        sub_00515890_SetSoundPan(pSlot->pSound, nPan);
        nFinal = nPanVolume * nFinal / 255;
    }

    if (pSlot->nType & 2)
        sub_00515950_SetSoundPosition(pSlot->pSound, fX, fY, fZ);

    sub_00515A90_SetSoundAttenuation(pSlot->pSound, pObject->fAttenuation);
    sub_005157B0_SetSoundVolume(pSlot->pSound, nFinal);
    pSlot->tPos = *pPos;
    pSlot->nVolume = nVolume;
    pSlot->fAttenuation = pObject->fAttenuation;
}
