extern "C" double __cdecl sqrt(double x);                                                                   // 0x006879C0
extern "C" double __cdecl log(double x);                                                                    // 0x00687AC0
extern "C" double __cdecl pow(double x, double y);                                                          // 0x00687C10

extern const float gfMaxSoundDistance_006DEB10;                                                             // 0x006DEB10

static float SOUND_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}

static float SOUND_LogF(float fValue)
{
    return (float)log(fValue);
}

static float SOUND_Log2F(float fValue)
{
    return SOUND_LogF(fValue) / 0.6931472f;
}

static float SOUND_PowF(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

static float SOUND_GetDistance(float fX, float fY, float fZ)
{
    return SOUND_SqrtF(fX * fX + fY * fY + fZ * fZ);
}

static __forceinline float SOUND_GetAttenuation(float fDistance)
{
    if (fDistance > 100.0)
        fDistance = gfMaxSoundDistance_006DEB10;

    if (fDistance < 2.0f)
        return 0.0f;

    return SOUND_Log2F(fDistance * 0.5f) * 6.0f;
}

// 0x00516830
void __fastcall sub_00516830_GetPositionalVolumePan(int* pVolume, int* pPan, float fX, float fY, float fZ)
{
    *(volatile float*)&fY = SOUND_GetDistance(fX, fY, fZ);
    const float fAttenuation = SOUND_GetAttenuation(*(volatile float*)&fY);

    int nVolume = (int)(255.0f / SOUND_PowF(10.0f, fAttenuation / 20.0f));
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 255)
        nVolume = 255;

    *(volatile float*)&fX = fX * 127.0f / 1.25f + 128.0f;
    int nPan = (int)*(volatile float*)&fX;
    nPan = nPan > 0 ? nPan : 0;
    if (nPan >= 255)
        nPan = 255;

    *pVolume = nVolume;
    *pPan = nPan;
}
