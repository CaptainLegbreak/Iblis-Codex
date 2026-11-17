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
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

float __stdcall sub_005165F0_ToDecibels(float fMin, float fMax, float fValue);                              // 0x005165F0

// 0x00515890
void __fastcall sub_00515890_SetSoundPan(D2SoundStrc* pSound, int nPan)
{
    long lPan;

    D2_ASSERT(pSound, 0x2EF);
    if (nPan > 0x80)
        lPan = (long)-sub_005165F0_ToDecibels(0.0f, 127.0f, (float)(0xFF - nPan));
    else if (nPan < 0x80)
        lPan = (long)sub_005165F0_ToDecibels(0.0f, 127.0f, (float)nPan);
    else
        lPan = 0;
    pSound->pBuffer->SetPan(lPan);
}
