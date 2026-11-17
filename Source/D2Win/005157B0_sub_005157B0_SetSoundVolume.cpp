struct D2DSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pdwPlay, unsigned long* pdwWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long dwSize, unsigned long* pdwWritten) = 0;
    virtual long __stdcall GetVolume(long* plVolume) = 0;
    virtual long __stdcall GetPan(long* plPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pdwFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pdwStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long dwOffset, unsigned long dwBytes, void** ppv1, unsigned long* pdw1, void** ppv2, unsigned long* pdw2, unsigned long dwFlags) = 0;
    virtual long __stdcall Play(unsigned long dwReserved, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long dwPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long lVolume) = 0;
    virtual long __stdcall SetPan(long lPan) = 0;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    int unk0x04[2];
    void* p3DBuffer;
    void* pPropertySet;
    int unk0x14[8];
    unsigned int dwFlags;
    int f_38;
    float f_3C;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_00513B90();                                                                                  // 0x00513B90
float __stdcall sub_005165F0_ToDecibels(float fMin, float fMax, float fValue);                              // 0x005165F0

extern int gnSoundMasterVolume_0072F9B0;                                                                    // 0x0072F9B0

// 0x005157B0
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2CB);
    int nScaled = nVolume * gnSoundMasterVolume_0072F9B0;
    pSound->f_38 = nVolume;
    nScaled /= 255;
    if (!(pSound->dwFlags & 4) || sub_00513B90() != 2)
        nScaled = (int)((1.0f - pSound->f_3C) * nScaled);
    const int nDecibels = (int)sub_005165F0_ToDecibels(0.0f, 255.0f, (float)nScaled);
    pSound->pBuffer->SetVolume(nDecibels);
}
