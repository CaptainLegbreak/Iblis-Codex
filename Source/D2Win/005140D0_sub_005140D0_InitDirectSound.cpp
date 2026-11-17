extern "C" const char gszEmptyAssertText;                                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DSCritSect { void* a; long b; long c; void* d; void* e; unsigned long f; };
struct D2DSGuid { unsigned long a; unsigned short b; unsigned short c; unsigned char d[8]; };
#pragma pack(push, 1)
struct D2DSWaveFormat
{
    unsigned short wFormatTag; unsigned short nChannels; unsigned long nSamplesPerSec; unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign; unsigned short wBitsPerSample; unsigned short cbSize;
};
#pragma pack(pop)
struct D2DSBufferDesc { unsigned long dwSize; unsigned long dwFlags; unsigned long dwBufferBytes; unsigned long dwReserved; D2DSWaveFormat* lpwfxFormat; };
struct D2DSBufferCaps { unsigned long dwSize; unsigned long dwFlags; unsigned long dwBufferBytes; unsigned long dwUnlockTransferRate; unsigned long dwPlayCpuOverhead; };
struct D2DSCaps { unsigned long dwSize; unsigned long a[10]; unsigned long dwMaxHw3DAllBuffers; unsigned long b[13]; };

struct D2DSUnknown
{
    virtual long __stdcall QueryInterface(const D2DSGuid& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct D2DSBuffer : D2DSUnknown
{
    virtual long __stdcall GetCaps(D2DSBufferCaps* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* a, unsigned long* b) = 0;
    virtual long __stdcall GetFormat(D2DSWaveFormat* a, unsigned long b, unsigned long* c) = 0;
    virtual long __stdcall GetVolume(long* a) = 0;
    virtual long __stdcall GetPan(long* a) = 0;
    virtual long __stdcall GetFrequency(unsigned long* a) = 0;
    virtual long __stdcall GetStatus(unsigned long* a) = 0;
    virtual long __stdcall Initialize(void* a, const D2DSBufferDesc* b) = 0;
    virtual long __stdcall Lock(unsigned long a, unsigned long b, void** c, unsigned long* d, void** e, unsigned long* f, unsigned long g) = 0;
    virtual long __stdcall Play(unsigned long dwReserved1, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long a) = 0;
    virtual long __stdcall SetFormat(const D2DSWaveFormat* pFormat) = 0;
};
struct D2DSDirectSound : D2DSUnknown
{
    virtual long __stdcall CreateSoundBuffer(const D2DSBufferDesc* pDesc, D2DSBuffer** ppBuffer, D2DSUnknown* pOuter) = 0;
    virtual long __stdcall GetCaps(D2DSCaps* pCaps) = 0;
    virtual long __stdcall DuplicateSoundBuffer(D2DSBuffer* a, D2DSBuffer** b) = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwLevel) = 0;
};
struct D2DSPropertySet : D2DSUnknown
{
    virtual long __stdcall Get(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f, unsigned long* g) = 0;
    virtual long __stdcall Set(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f) = 0;
    virtual long __stdcall QuerySupport(const D2DSGuid& rguid, unsigned long nId, unsigned long* pSupport) = 0;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2DSCritSect* pLock);              // 0x006CC210
extern "C" long __stdcall DirectSoundCreate(const D2DSGuid* pGuid, D2DSDirectSound** ppDS, D2DSUnknown* pOuter); // 0x006B1344
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                            // 0x00410610
void* __cdecl sub_004F59A0();                                                                               // 0x004F59A0
void __cdecl sub_00513AF0_ReleaseSoundObjects();                                                             // 0x00513AF0
int __fastcall sub_00513BC0_SetEaxRoomOff(int nEaxVersion);                                                  // 0x00513BC0
const char* __fastcall sub_00513ED0_GetDSoundErrorString(long hResult);                                      // 0x00513ED0
void __cdecl sub_00514060_ShutdownSound();                                                                   // 0x00514060
extern "C" void __fastcall sub_00514780_CreateSoundChannel(int nArg);                                        // 0x00514780
void __cdecl sub_00514B60_LoadSoundSettings();                                                               // 0x00514B60
int __fastcall sub_00515300_ClearSoundBuffer(D2DSBuffer* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                   // 0x00515CE0
void __cdecl sub_00516510_StartSoundThread();                                                                // 0x00516510
void __fastcall sub_00516720_InitWaveFormat(D2DSWaveFormat* pFormat, int nChannels);                         // 0x00516720

extern D2DSPropertySet* gpPropertySet_008816D8;                                                              // 0x008816D8
int gnChannelArg_008816DC;                                                                                   // 0x008816DC
extern D2DSCaps gDSCaps_008816E0;                                                                          // 0x008816E0
D2DSUnknown* gp3DBuffer_00881740;                                                                            // 0x00881740
D2DSBuffer* gpEaxBuffer_00881744;                                                                          // 0x00881744
D2DSBuffer* gpSoundObject_00881748;                                                                        // 0x00881748
extern D2DSCritSect gSoundLock_0088174C;                                                                     // 0x0088174C
extern int gnSoundState_00881764;                                                                            // 0x00881764
D2DSDirectSound* gpDirectSound_00881768;                                                                     // 0x00881768
int gb3DSound_0088176C;                                                                                      // 0x0088176C
extern int gbUseEax_00881770;                                                                                // 0x00881770
int gnEaxVersion_00881774;                                                                                   // 0x00881774
int gbSoundLockInit_0088177C;                                                                                // 0x0088177C
extern int gbSoundInit_00881784;                                                                             // 0x00881784
extern const D2DSGuid gIID_IDirectSound3DBuffer_006DE3D0;                                                    // 0x006DE3D0
extern const D2DSGuid gIID_IKsPropertySet_006DE410;                                                          // 0x006DE410
extern const D2DSGuid gDSPROPSETID_EAX20_ListenerProperties_006DE460;                                        // 0x006DE460
extern const D2DSGuid gDSPROPSETID_EAX_ReverbProperties_006DE480;                                            // 0x006DE480

// 0x005140D0
void __cdecl sub_005140D0_InitDirectSound()
{
    if (gb3DSound_0088176C && gbSoundInit_00881784)
    {
        return;
    }

    D2_ASSERT(!gbSoundLockInit_0088177C, 0x53);
    InitializeCriticalSection(&gSoundLock_0088174C);
    gbSoundLockInit_0088177C = 1;

    long hResult = DirectSoundCreate(0, &gpDirectSound_00881768, 0);
    if (hResult < 0)
    {
        sub_00410610_WriteLogLine("DirectSound error: %s returned on DirectSoundCreate", sub_00513ED0_GetDSoundErrorString(hResult));
        sub_00514060_ShutdownSound();
        return;
    }

    hResult = gpDirectSound_00881768->SetCooperativeLevel(sub_004F59A0(), 2);
    if (hResult < 0)
    {
        sub_00410610_WriteLogLine("DirectSound error: %s returned on SetCooperativeLevel", sub_00513ED0_GetDSoundErrorString(hResult));
        sub_00514060_ShutdownSound();
        return;
    }

    D2DSBufferDesc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = 1;
    if (gb3DSound_0088176C)
    {
        tDesc.dwFlags = 0x11;
    }
    tDesc.dwBufferBytes = 0;
    tDesc.lpwfxFormat = 0;
    hResult = gpDirectSound_00881768->CreateSoundBuffer(&tDesc, &gpSoundObject_00881748, 0);
    if (hResult < 0)
    {
        sub_00410610_WriteLogLine("........DirectSound progress: %s returned on failed CreateSoundBuffer", sub_00513ED0_GetDSoundErrorString(hResult));
        sub_00514060_ShutdownSound();
        return;
    }

    gDSCaps_008816E0.dwSize = 0x60;
    hResult = gpDirectSound_00881768->GetCaps(&gDSCaps_008816E0);
    if (hResult < 0)
    {
        sub_00410610_WriteLogLine("........DirectSound progress: %s returned on failed GetCaps", sub_00513ED0_GetDSoundErrorString(hResult));
        sub_00514060_ShutdownSound();
        return;
    }

    if (gb3DSound_0088176C && gDSCaps_008816E0.dwMaxHw3DAllBuffers < 0x10)
    {
        sub_00410610_WriteLogLine("........DirectSound progress: %d buffers available is less than min needed %d buffers for 3d sound", gDSCaps_008816E0.dwMaxHw3DAllBuffers, 0x10);
        sub_00514060_ShutdownSound();
        return;
    }

    D2DSWaveFormat tFormat;
    memset(&tFormat, 0, sizeof(tFormat));
    tFormat.wFormatTag = 1;
    tFormat.nChannels = 2;
    tFormat.nSamplesPerSec = 0x5622;
    tFormat.wBitsPerSample = 0x10;
    tFormat.nBlockAlign = 4;
    tFormat.nAvgBytesPerSec = 0x15888;
    hResult = gpSoundObject_00881748->SetFormat(&tFormat);
    if (hResult < 0)
    {
        sub_00410610_WriteLogLine("........DirectSound progress: %s returned on failed SetFormat", sub_00513ED0_GetDSoundErrorString(hResult));
        gpSoundObject_00881748->Release();
        sub_00514060_ShutdownSound();
        return;
    }

    gnEaxVersion_00881774 = 0;
    if (gbUseEax_00881770)
    {
        D2DSWaveFormat tEaxFormat;
        sub_00516720_InitWaveFormat(&tEaxFormat, 1);
        D2DSBufferDesc tEaxDesc;
    memset(&tEaxDesc, 0, sizeof(tEaxDesc));
        tEaxDesc.dwSize = 0x14;
        tEaxDesc.dwBufferBytes = 0x400;
        tEaxDesc.dwFlags = 0x12;
        tEaxDesc.lpwfxFormat = &tEaxFormat;
        unsigned long nSupport;
        if (!gnEaxVersion_00881774)
        {
            if (gpDirectSound_00881768->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer_00881744, 0) >= 0
                && gpEaxBuffer_00881744->QueryInterface(gIID_IDirectSound3DBuffer_006DE3D0, (void**)&gp3DBuffer_00881740) >= 0
                && gp3DBuffer_00881740->QueryInterface(gIID_IKsPropertySet_006DE410, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX20_ListenerProperties_006DE460, 1, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(2))
            {
                gnEaxVersion_00881774 = 2;
            }
            else
            {
                sub_00513AF0_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion_00881774)
        {
            if (gpDirectSound_00881768->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer_00881744, 0) >= 0
                && gpEaxBuffer_00881744->QueryInterface(gIID_IDirectSound3DBuffer_006DE3D0, (void**)&gp3DBuffer_00881740) >= 0
                && gp3DBuffer_00881740->QueryInterface(gIID_IKsPropertySet_006DE410, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX_ReverbProperties_006DE480, 0, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(1))
            {
                gnEaxVersion_00881774 = 1;
            }
            else
            {
                sub_00513AF0_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion_00881774)
        {
            sub_00410610_WriteLogLine("........DirectSound progress: Unsupported EAX or EAX emulation");
            sub_00514060_ShutdownSound();
            return;
        }
    }

    D2DSBufferCaps tCaps;
    memset(&tCaps, 0, sizeof(tCaps));
    tCaps.dwSize = 0x14;
    gpSoundObject_00881748->GetCaps(&tCaps);
    sub_00515300_ClearSoundBuffer(gpSoundObject_00881748, 0, tCaps.dwBufferBytes);
    gpSoundObject_00881748->Play(0, 0, 1);
    sub_00516510_StartSoundThread();
    sub_00514780_CreateSoundChannel(gnChannelArg_008816DC);
    sub_00514B60_LoadSoundSettings();
    sub_00515CE0_SetMasterVolume(0xFF);
    gnSoundState_00881764 = 1;
}

#include "gen/data/Source/D2Win/005140D0_sub_005140D0_InitDirectSound.inc"
