#include "D2Sound.h"
#include "D2SoundTypes.h"

#define DSBSTATUS_BUFFERLOST 0x00000002

#define DSERR_BUFFERLOST ((long)0x88780096)

struct D2DirectSoundStrc;

struct D2ComObjectStrc;

struct D2DSoundBufferStrc;

struct D2SoundStrc;

struct D2SoundNodeStrc;

struct D2WaveStrc;

struct D2SoundChannelEntryStrc;

struct D2WaveFormatStrc;

struct D2SoundSampleStrc;

struct D2SoundViewStrc;

struct D2StoredUnitRecordStrc;

struct D2PanelCtrlStrc_004B8370;

struct D2SoundObjStrc_00515A30;

struct D2ClientStrc;

struct D2LinkStrc_004CA990;

struct D2OwnerStrc_004CA990;

struct D2SoundFadeStrc;

struct D2CriticalSectionStrc;

struct D2KsPropertySetStrc;

struct D2DSound3DBufferStrc;

struct D2GuidStrc;

struct D2EaxEnvironmentStrc;

struct D2DSBufferDescStrc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __cdecl sub_00419F30(); // 0x00419F30

int __stdcall sub_0041A990(void* hStream); // 0x0041A990

D2DirectSoundStrc* __cdecl sub_00513B50(); // 0x00513B50

void __fastcall D2SOUND_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0

void __fastcall D2SOUND_StopSound(D2SoundStrc* pSound); // 0x00515EE0

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __stdcall SFileDdaBeginEx(void* hFile, int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2DSoundBufferStrc* pBuffer); // 0x0041B280

int __fastcall D2SOUND_FillSoundBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size); // 0x00515180

void* __fastcall sub_00516760_ParseWave(const void* pFile, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760

void __fastcall D2SOUND_DestroySound(D2SoundStrc* pSound); // 0x005160D0

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern D2SoundChannelEntryStrc gaChannelTableA_0072F878[8]; // 0x0072F878

extern D2SoundChannelEntryStrc gaChannelTableB_0072F8B8[8]; // 0x0072F8B8

extern D2ComObjectStrc* gpSoundObject_008816D8; // 0x008816D8

extern D2ComObjectStrc* gpSoundObject_00881740; // 0x00881740

extern D2ComObjectStrc* gpSoundObject_00881744; // 0x00881744

extern D2SoundStrc* gpSoundChannel_00881794; // 0x00881794

int gnSoundMode_008817AC; // 0x008817AC

int gnMusicVolume_008817B4; // 0x008817B4

int gnOptionsMusic_008817C0; // 0x008817C0

extern D2CriticalSectionStrc gWaveLock_008817C4; // 0x008817C4

extern D2SoundStrc* gapWaveSlots_008817DC[8]; // 0x008817DC

extern int gbWaveSlotsInit_008817FC; // 0x008817FC

D2SoundNodeStrc* gpSoundList_00881808; // 0x00881808

struct D2SoundSampleStrc
{
    char unk0x00[0x48];
    void* hSample;
};

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

D2CriticalSectionStrc gSoundLock_0088174C; // 0x0088174C

struct D2SoundViewStrc
{
    char unk0x00[0x38];
    int nField38;
};

struct D2StoredUnitRecordStrc
{
    char unk0x00[0x66];
    char szName[1];
};

struct D2PanelCtrlStrc_004B8370
{
    char unk0x00[0x5C];
    int nState;
};

struct D2SoundObjStrc_00515A30
{
    char unk0x00[0x40];
    int nValue40;
    int nValue44;
};

struct D2ClientStrc
{
    char unk0x00[0x3D4];
    unsigned int dwFlags;
};

struct D2LinkStrc_004CA990
{
    void* pFirst;
};

struct D2OwnerStrc_004CA990
{
    char unk0x00[0x78];
    D2LinkStrc_004CA990* pLink;
};

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

typedef char check_size_entry[(sizeof(D2StoredUnitRecordStrc) == 0x67) ? 1 : -1];

typedef char check_size_ctrl[(sizeof(D2PanelCtrlStrc_004B8370) == 0x60) ? 1 : -1];

typedef char check_size_sound[(sizeof(D2SoundObjStrc_00515A30) == 0x48) ? 1 : -1];

typedef char check_size_client[(sizeof(D2ClientStrc) == 0x3D8) ? 1 : -1];

typedef char check_size_owner[(sizeof(D2OwnerStrc_004CA990) == 0x7C) ? 1 : -1];

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" double __cdecl log10(double x); // 0x00687EA0

struct D2SoundFadeStrc
{
    char unk0x00[0x38];
    int nCurrent;
    char unk0x3C[0x10];
    int f_4C;
    int nFadeStart;
    int f_54;
    unsigned int dwFadeStartTick;
    unsigned int dwFadeEndTick;
};

unsigned long __stdcall sub_00516250_SoundThread(void* pParameter); // 0x00516250

void* ghSoundEvent_0088180C; // 0x0088180C

void* ghSoundThread_00881810; // 0x00881810

void __fastcall D2SOUND_CloseSoundStream(D2SoundStrc* pSound); // 0x00515E40

struct D2EaxEnvironmentStrc
{
    unsigned int dwEnvironment;
    float fEnvironmentSize;
    float fEnvironmentDiffusion;
    int nRoom;
    int f_10;
    float f_14;
    float f_18;
    int f_1C;
    float f_20;
    int f_24;
    float f_28;
    float fRoomRolloffFactor;
    float f_30;
};

int __cdecl sub_00513BA0(); // 0x00513BA0

float __stdcall sub_00516670_RoomToVolume(float fRoom); // 0x00516670

extern const D2GuidStrc gEaxListener20PropertySet_006DE460; // 0x006DE460

extern const D2GuidStrc gEaxBuffer20PropertySet_006DE470; // 0x006DE470

extern const D2GuidStrc gEax10PropertySet_006DE480; // 0x006DE480

extern const D2GuidStrc gEaxBuffer10PropertySet_006DE490; // 0x006DE490

extern int gbEaxEnabled_00881770; // 0x00881770

extern int gnEaxVersion_00881774; // 0x00881774

extern int gbEaxRoomOff_00881778; // 0x00881778

void __fastcall D2SOUND_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950

void __fastcall D2SOUND_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90

void __fastcall D2SOUND_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels); // 0x00516720

void __fastcall D2SOUND_ListAddHead(D2SoundNodeStrc** ppList, void* pData); // 0x00516950

void __fastcall D2SOUND_ListRemove(D2SoundNodeStrc** ppList, void* pData); // 0x00516980

extern const D2GuidStrc gIidDirectSound3DBuffer_006DE3D0; // 0x006DE3D0

extern const D2GuidStrc gIidKsPropertySet_006DE410; // 0x006DE410

D2KsPropertySetStrc* gpEaxListenerPropertySet_008816D8; // 0x008816D8

int gnChannelTableSel_008817A4; // 0x008817A4

int gbChannelTableInit_008817A8; // 0x008817A8

D2WaveStrc* gpWaveList_00881800; // 0x00881800

int gdwGlobal_008817B0; // 0x008817B0

int gdwGlobal_008817B8; // 0x008817B8

int gdwGlobal_008817BC; // 0x008817BC

int gbSoundGlobalFocus_00881804; // 0x00881804

extern "C" { int gdwGlobal_008817A0; } // 0x008817A0

extern "C" int __stdcall SFileDdaInitialize(int nValue); // 0x00415EE0

D2SoundStrc* __fastcall D2SOUND_CreateSound(unsigned int nFlags, int nValue); // 0x00515530


extern const char gszEmptyAssert[]; // 0x006CC837

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int); // 0x006829C0

void __cdecl sub_0042B9D0_Nop()
{
}

void __cdecl sub_0043CBF0_Nop()
{
}

extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szName;
}

extern "C" void __fastcall sub_004B8370_SetCtrlState(D2PanelCtrlStrc_004B8370* pCtrl, int nState)
{
    D2_ASSERT(pCtrl, 1310);
    pCtrl->nState = nState;
}

extern "C" void* __fastcall sub_004CA990_GetLinkFirst(D2OwnerStrc_004CA990* pOwner)
{
    D2_ASSERT(pOwner, 3171);
    D2LinkStrc_004CA990* pLink = pOwner->pLink;
    if (pLink)
    {
        return pLink->pFirst;
    }

    return 0;
}

// 0x00513AF0
void __cdecl D2SOUND_ReleaseSoundObjects()
{
    if (gpSoundObject_008816D8)
    {
        gpSoundObject_008816D8->Release();
        gpSoundObject_008816D8 = 0;
    }
    if (gpSoundObject_00881740)
    {
        gpSoundObject_00881740->Release();
        gpSoundObject_00881740 = 0;
    }
    if (gpSoundObject_00881744)
    {
        gpSoundObject_00881744->Release();
        gpSoundObject_00881744 = 0;
    }
}

// 0x00513C50
void __fastcall D2SOUND_SetEaxEnvironment(D2EaxEnvironmentStrc* pEnvironment)
{
    if (!gbEaxEnabled_00881770 || !gpEaxListenerPropertySet_008816D8)
        return;
    if (gnEaxVersion_00881774 == 1)
    {
        float fVolume = sub_00516670_RoomToVolume((float)pEnvironment->nRoom);
        gpEaxListenerPropertySet_008816D8->Set(gEax10PropertySet_006DE480, 1, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEax10PropertySet_006DE480, 2, 0, 0, &fVolume, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEax10PropertySet_006DE480, 3, 0, 0, &pEnvironment->f_14, 4);
    }
    if (gnEaxVersion_00881774 == 2)
    {
        int nFlags = 0x20;
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xF, 0, 0, &nFlags, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xC, 0, 0, &pEnvironment->fEnvironmentSize, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xD, 0, 0, &pEnvironment->fEnvironmentDiffusion, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 2, 0, 0, &pEnvironment->nRoom, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 3, 0, 0, &pEnvironment->f_10, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 5, 0, 0, &pEnvironment->f_14, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 6, 0, 0, &pEnvironment->f_18, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 7, 0, 0, &pEnvironment->f_1C, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 8, 0, 0, &pEnvironment->f_20, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 9, 0, 0, &pEnvironment->f_24, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xA, 0, 0, &pEnvironment->f_28, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 4, 0, 0, &pEnvironment->fRoomRolloffFactor, 4);
        gpEaxListenerPropertySet_008816D8->Set(gEaxListener20PropertySet_006DE460, 0xE, 0, 0, &pEnvironment->f_30, 4);
    }
    gbEaxRoomOff_00881778 = pEnvironment->nRoom == -10000;
}

// 0x00513ED0
const char* __fastcall D2SOUND_GetDirectSoundErrorString(long hResult)
{
    switch (hResult)
    {
    case 0x80004005:
        return "DSERR_GENERIC";
    case 0x80004002:
        return "DSERR_NOINTERFACE";
    case 0x80004001:
        return "DSERR_UNSUPPORTED";
    case 0x80040110:
        return "DSERR_NOAGGREGATION";
    case 0x80070057:
        return "DSERR_INVALIDPARAM";
    case 0x8007000E:
        return "DSERR_OUTOFMEMORY";
    case 0x8878000A:
        return "DSERR_ALLOCATED";
    case 0x88780064:
        return "DSERR_BADFORMAT";
    case 0x8878001E:
        return "DSERR_CONTROLUNAVAIL";
    case 0x88780032:
        return "DSERR_INVALIDCALL";
    case 0x88780078:
        return "DSERR_NODRIVER";
    case 0x88780046:
        return "DSERR_PRIOLEVELNEEDED";
    case 0x88780082:
        return "DSERR_ALREADYINITIALIZED";
    case 0x887800A0:
        return "DSERR_OTHERAPPHASPRIO";
    case 0x88780096:
        return "DSERR_BUFFERLOST";
    case 0x887800AA:
        return "DSERR_UNINITIALIZED";
    case 0:
        return "DS_OK";
    }
    return 0;
}

// 0x00514780
extern "C" void __fastcall D2SOUND_CreateStreamChannel(int nArg)
{
    gdwGlobal_008817A0 = nArg;
    SFileDdaInitialize((int)sub_00513B50());
    gpSoundChannel_00881794 = D2SOUND_CreateSound(1, gdwGlobal_008817A0);
}

// build: symbol ?sub_N19_GetChannelEntry@@YAPAUD2SoundChannelEntryStrc@@H@Z 0x00514710
static D2SoundChannelEntryStrc* sub_N19_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit_008817A8)
    {
        gbChannelTableInit_008817A8 = 1;
        gnChannelTableSel_008817A4 = sub_00513AE0();
    }
    D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA_0072F874, 0x53);
    if (gnChannelTableSel_008817A4)
        return &gaChannelTableB_0072F8B8[nIndex];
    return &gaChannelTableA_0072F878[nIndex];
}

// 0x005147B0
void __cdecl D2SOUND_DestroyStreamChannel()
{
    if (gpSoundChannel_00881794)
    {
        D2SOUND_DestroySound(gpSoundChannel_00881794);
        gpSoundChannel_00881794 = 0;
    }
    sub_00419F30();
}

// 0x00514860
void __cdecl D2SOUND_ClearChannelTable()
{
    for (int i = 0; i < gnChannelCountA_0072F874; ++i)
        sub_N19_GetChannelEntry(i)->bBusy = 0;
}

// 0x00514B60
void __cdecl D2SOUND_LoadRegistrySettings()
{
    unsigned long nValue;
    gnSoundMode_008817AC = 0;
    gdwGlobal_008817B0 = 100;
    gnMusicVolume_008817B4 = 50;
    gdwGlobal_008817B8 = 50;
    gdwGlobal_008817BC = 2;
    gnOptionsMusic_008817C0 = 1;
    if (SRegLoadValue("Diablo II", "Sound Mixer", 0, &nValue) && nValue < 3)
        gnSoundMode_008817AC = nValue;
    if (SRegLoadValue("Diablo II", "Master Volume", 0, &nValue) && nValue <= 100)
        gdwGlobal_008817B0 = nValue;
    if (SRegLoadValue("Diablo II", "Music Volume", 0, &nValue) && nValue <= 100)
        gnMusicVolume_008817B4 = nValue;
    if (SRegLoadValue("Diablo II", "Positional Bias", 0, &nValue) && nValue <= 100)
        gdwGlobal_008817B8 = nValue;
    if (SRegLoadValue("Diablo II", "NPC Speech", 0, &nValue) && nValue < 3)
        gdwGlobal_008817BC = nValue;
    if (SRegLoadValue("Diablo II", "Options Music", 0, &nValue) && nValue <= 1)
        gnOptionsMusic_008817C0 = nValue;
}

// 0x00514CA0
int __fastcall D2SOUND_SetSoundMixerOption(int nValue)
{
    SRegSaveValue("Diablo II", "Sound Mixer", 0, nValue);
    gnSoundMode_008817AC = nValue;
    return nValue;
}

// 0x00514D00
int __fastcall D2SOUND_SetMusicVolumeOption(int nValue)
{
    SRegSaveValue("Diablo II", "Music Volume", 0, nValue);
    gnMusicVolume_008817B4 = nValue;
    return nValue;
}

// 0x00514D90
int __fastcall D2SOUND_SetOptionsMusicOption(int nValue)
{
    SRegSaveValue("Diablo II", "Options Music", 0, nValue);
    gnOptionsMusic_008817C0 = nValue;
    return nValue;
}


// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515120
void __cdecl D2SOUND_StopSoundThread()
{
    if (ghSoundThread_00881810 && ghSoundEvent_0088180C)
    {
        SetEvent(ghSoundEvent_0088180C);
        WaitForSingleObject(ghSoundThread_00881810, -1);
        CloseHandle(ghSoundEvent_0088180C);
        CloseHandle(ghSoundThread_00881810);
        ghSoundEvent_0088180C = 0;
        ghSoundThread_00881810 = 0;
    }
}

// 0x00515180
int __fastcall D2SOUND_FillSoundBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size)
{
 void* locked=0;
 if(sound && sound->pBuffer && sound->pData && size) {
  EnterCriticalSection(&gSoundLock_0088174C);
  unsigned long lockedSize=size;
  if(sound->pBuffer->Lock(destinationPosition,size,&locked,&lockedSize,0,0,0)<0) {
   LeaveCriticalSection(&gSoundLock_0088174C);
   return 0;
  }
  unsigned char* destination=(unsigned char*)locked;
  do {
   unsigned int end=sound->nDataSize;
   if(sourcePosition>=end)
    sourcePosition=sound->nMinDataSize+(sourcePosition-sound->nMinDataSize)%(end-sound->nMinDataSize);
   unsigned int count=size<end-sourcePosition?size:end-sourcePosition;
   memcpy(destination,(unsigned char*)sound->pData+sourcePosition,count);
   sound->nFillPosition+=count;
   destination+=count;
   destinationPosition+=count;
   size-=count;
   sourcePosition+=count;
  } while(sound->bNoLoop && size);
  if(size) {
   if(sound->nLoopStart!=(unsigned int)-1) {
    if(destinationPosition>=sound->nLoopStart) goto unlock;
    size=sound->nLoopStart-destinationPosition;
   }
   if(size) memset(destination,0,size);
  }
 unlock:
  sound->pBuffer->Unlock(locked,lockedSize,0,0);
  if(!sound->bNoLoop && sound->nFillPosition>=sound->nDataSize) sound->bStreamed=1;
  LeaveCriticalSection(&gSoundLock_0088174C);
  return 1;
 }
 sub_00408A60(gszEmptyAssert,sub_00408090(),221);
 exit(-1);
}

// 0x00515300
int __fastcall D2SOUND_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes)
{
    void* pAudio = 0;
    D2_ASSERT(pBuffer, 0x14B);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pBuffer->Lock(nOffset, nBytes, &pAudio, &nBytes, 0, 0, 0) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    memset(pAudio, 0, nBytes);
    pBuffer->Unlock(pAudio, nBytes, 0, 0);
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

static int __stdcall sub_005153C0_CreateSoundBuffer(unsigned int nFlags, D2SoundStrc* pSound)
{
    D2WaveFormatStrc tFormat;
    D2SOUND_InitWaveFormat(&tFormat, (nFlags & 1) ? 2 : 1);

    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    const unsigned int nBytes = (nFlags & 1) ? 0x40000 : 0x20000;
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = gbSoundGlobalFocus_00881804 ? 0x80A0 : 0xA0;
    if (nFlags & 2)
        tDesc.dwFlags |= 0x14;
    else
        tDesc.dwFlags |= 0x40;
    tDesc.dwBufferBytes = nBytes;
    tDesc.lpwfxFormat = &tFormat;

    D2DirectSoundStrc* pDirectSound = sub_00513B50();
    if (pDirectSound->CreateSoundBuffer(&tDesc, &pSound->pBuffer, 0) < 0)
        return 0;

    if (nFlags & 2)
    {
        if (pSound->pBuffer->QueryInterface(gIidDirectSound3DBuffer_006DE3D0, (void**)&pSound->p3DBuffer) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }
    }

    if ((nFlags & 2) && sub_00513B70())
    {
        if (pSound->p3DBuffer->QueryInterface(gIidKsPropertySet_006DE410, (void**)&pSound->pPropertySet) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }

        unsigned long dwSupport = 0;
        long hr;
        if (sub_00513B90() == 1)
            hr = pSound->pPropertySet->QuerySupport(gEaxBuffer10PropertySet_006DE490, 1, &dwSupport);
        else
            hr = pSound->pPropertySet->QuerySupport(gEaxBuffer20PropertySet_006DE470, 1, &dwSupport);
        if (hr < 0 || (dwSupport & 3) != 3)
        {
            pSound->pPropertySet->Release();
            pSound->pBuffer->Release();
            return 0;
        }
    }

    pSound->nBufferSize = nBytes;
    pSound->nHalfBufferBytes = nBytes >> 1;
    pSound->dwFlags = nFlags;
    pSound->nLoopStart = -1;
    return 1;
}

// 0x00515530
D2SoundStrc* __fastcall D2SOUND_CreateSound(unsigned int nFlags, int nValue)
{
    gbSoundGlobalFocus_00881804 = nValue;
    if ((nFlags & 2) && !sub_00513B60())
        return 0;
    if ((nFlags & 2) && (nFlags & 1))
        return 0;

    D2SoundStrc* pSound = (D2SoundStrc*)FOG_Alloc(0x60, ".\\Src\\D2SoundSmp.cpp", 0x1D9, 0);
    memset(pSound, 0, 0x60);
    if (!sub_005153C0_CreateSoundBuffer(nFlags, pSound))
    {
        FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x1E0, 0);
        return 0;
    }

    EnterCriticalSection(&gSoundLock_0088174C);
    D2SOUND_ListAddHead(&gpSoundList_00881808, pSound);
    LeaveCriticalSection(&gSoundLock_0088174C);
    return pSound;
}

// 0x005155D0
int __fastcall D2SOUND_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize)
{
    D2_ASSERT(pSound && pSound->pBuffer && pFile && nSize, 0x257);
    EnterCriticalSection(&gSoundLock_0088174C);
    unsigned int nDataSize = nSize;
    D2WaveFormatStrc tFormat;
    void* pData = sub_00516760_ParseWave(pFile, &nDataSize, &tFormat);
    D2_ASSERT(pSound->nMinDataSize < nDataSize, 0x25F);
    pSound->nDataSize = nDataSize;
    pSound->pData = pData;
    D2SOUND_FillSoundBuffer(pSound, 0, 0, pSound->nBufferSize);
    pSound->bSecondHalf = 1;
    if (!pSound->bNoLoop && pSound->nDataSize < pSound->nBufferSize)
        pSound->nLoopStart = pSound->nDataSize;
    else
        pSound->nLoopStart = -1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x005156A0
int __fastcall D2SOUND_PlaySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x279);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->pBuffer->Play(0, 0, 1) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    pSound->bStreaming = 1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x00515710
int __fastcall D2SOUND_GetSoundPlayingFlag(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2A5);
    return pSound->bStreaming;
}

// 0x00515740
int __fastcall D2SOUND_IsSoundBufferPlaying(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2B0);
    EnterCriticalSection(&gSoundLock_0088174C);
    unsigned long dwStatus;
    if (pSound->pBuffer->GetStatus(&dwStatus) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
    const unsigned char bPlaying = dwStatus & 1;
    return bPlaying;
}

// 0x005157B0
void __fastcall D2SOUND_SetSoundVolume(D2SoundStrc* pSound, int nVolume)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2CB);
    int nScaled = nVolume * gnSoundMasterVolume_0072F9B0;
    pSound->nVolume = nVolume;
    nScaled /= 255;
    if (!(pSound->dwFlags & 4) || sub_00513B90() != 2)
        nScaled = (int)((1.0f - pSound->fAttenuation) * nScaled);
    const int nDecibels = (int)sub_005165F0_ToDecibels(0.0f, 255.0f, (float)nScaled);
    pSound->pBuffer->SetVolume(nDecibels);
}

// 0x00515860
int __fastcall D2SOUND_GetSoundVolume(D2SoundViewStrc* pSound)
{
    D2_ASSERT(pSound, 0x2E4);
    return pSound->nField38;
}

// 0x00515890
void __fastcall D2SOUND_SetSoundPan(D2SoundStrc* pSound, int nPan)
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

// 0x00515950
void __fastcall D2SOUND_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x302);
    if (pSound->dwFlags & 2)
        pSound->p3DBuffer->SetPosition(x, y, z, 0);
}

// 0x005159B0
unsigned int __fastcall D2SOUND_GetStreamPosition(D2SoundSampleStrc* pSound)
{
    D2_ASSERT(pSound, 784);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hSample)
    {
        unsigned int nValueA;
        unsigned int nValueB;
        if (sub_00418140(pSound->hSample, &nValueA, &nValueB))
        {
            LeaveCriticalSection(&gSoundLock_0088174C);
            return nValueA >> 2;
        }
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 0;
}

// 0x00515A30
extern "C" void __fastcall D2SOUND_SetSoundNoLoop(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 815);
    pSound->nValue40 = nValue;
}

// 0x00515A60
extern "C" void __fastcall D2SOUND_SetSoundLoopStart(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 826);
    pSound->nValue44 = nValue;
}

// 0x00515A90
void __fastcall D2SOUND_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation)
{
    D2_ASSERT(pSound, 0x345);
    pSound->fAttenuation = fAttenuation;
    if (pSound->pPropertySet && sub_00513B90() == 2)
    {
        if ((pSound->dwFlags & 4) || fAttenuation == 0.0f)
        {
            fAttenuation = 1.0f - fAttenuation;
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fAttenuation);
            pSound->pPropertySet->Set(gEaxBuffer20PropertySet_006DE470, 7, 0, 0, &nValue, 4);
        }
    }
}

// 0x00515B40
void __fastcall D2SOUND_SetSoundReverbMix(D2SoundStrc* pSound, float fReverbMix)
{
    D2_ASSERT(pSound, 0x359);
    if (sub_00513BA0())
        fReverbMix = 0.0f;
    if (pSound->pPropertySet)
    {
        if (sub_00513B90() == 1)
        {
            if (fReverbMix != 0.0f)
                fReverbMix = -1.0f;
            pSound->pPropertySet->Set(gEaxBuffer10PropertySet_006DE490, 1, 0, 0, &fReverbMix, 4);
        }
        else
        {
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fReverbMix);
            pSound->pPropertySet->Set(gEaxBuffer20PropertySet_006DE470, 5, 0, 0, &nValue, 4);
            pSound->pPropertySet->Set(gEaxBuffer20PropertySet_006DE470, 4, 0, 0, &nValue, 4);
        }
    }
}

// 0x00515C30
int __fastcall D2SOUND_IsSoundStreaming(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x37A);
    return pSound->hStream != 0;
}

// 0x00515C60
void __fastcall D2SOUND_StartSoundFade(D2SoundFadeStrc* pFade, int nTarget, int nDuration)
{
    D2_ASSERT(pFade, 0x39E);
    if (sub_00513B50())
    {
        EnterCriticalSection(&gSoundLock_0088174C);
        pFade->f_4C = 1;
        pFade->nFadeStart = pFade->nCurrent;
        pFade->f_54 = nTarget;
        const unsigned int dwTick = GetTickCount();
        pFade->dwFadeStartTick = dwTick;
        pFade->dwFadeEndTick = dwTick + nDuration;
        LeaveCriticalSection(&gSoundLock_0088174C);
    }
}

// 0x00515CE0
void __fastcall D2SOUND_SetMasterVolume(int nVolume)
{
    if (!sub_00513B50())
        return;
    if (nVolume == gnSoundMasterVolume_0072F9B0)
        return;
    D2_ASSERT(nVolume >= 0 && nVolume <= 0xFF, 0x3B9);
    EnterCriticalSection(&gSoundLock_0088174C);
    gnSoundMasterVolume_0072F9B0 = nVolume;
    for (D2SoundNodeStrc* pNode = gpSoundList_00881808; pNode; pNode = pNode->pNext)
    {
        D2_ASSERT(pNode->pSound, 0x2E4);
        D2SOUND_SetSoundVolume(pNode->pSound, pNode->pSound->nVolume);
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00515D60
int __cdecl D2SOUND_GetMasterVolume()
{
    return sub_00513B50() ? gnSoundMasterVolume_0072F9B0 : 0;
}

// 0x00515D70
int __fastcall D2SOUND_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop)
{
    D2_ASSERT(pSound, 0x3DB);
    void* hFile;
    if (!FOG_FOpenFile(szFileName, &hFile))
        return 0;
    EnterCriticalSection(&gSoundLock_0088174C);
    if (!SFileDdaBeginEx(hFile, pSound->nBufferSize, bLoop ? 0x40000 : 0, nPosition * 4, 0x7FFFFFFF, 0x7FFFFFFF, pSound->pBuffer))
    {
// build: symbol ?FOG_FCloseFile@* 0x004068F0
        FOG_FCloseFile(hFile);
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    pSound->hStream = hFile;
    pSound->bStreaming = 1;
    pSound->nLoopStart = -1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x00515E40
void __fastcall D2SOUND_CloseSoundStream(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x400);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_0041A990(pSound->hStream);
        pSound->pBuffer->Stop();
        FOG_FCloseFile(pSound->hStream);
        pSound->hStream = 0;
        pSound->bStreaming = 0;
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x00515EE0
void __fastcall D2SOUND_StopSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 658);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        D2SOUND_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bStreaming = 0;
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00515F50
void __fastcall D2SOUND_FadeOutMasterVolume(int nTime)
{
    if (!sub_00513B50())
        return;
    D2_ASSERT(nTime > 0, 0x387);
    unsigned int nVolume = D2SOUND_GetMasterVolume();
    const unsigned int nStep = nVolume / (nTime / 20u);
    while (nVolume)
    {
        Sleep(20);
        if (nVolume > nStep)
            nVolume -= nStep;
        else
            nVolume = 0;
        D2SOUND_SetMasterVolume(nVolume);
    }
}

// 0x00515FD0
int __fastcall D2SOUND_RestoreLostBuffer(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 290);
    EnterCriticalSection(&gSoundLock_0088174C);
    unsigned long dwStatus;
    if (pSound->pBuffer->GetStatus(&dwStatus) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }

    if (dwStatus & DSBSTATUS_BUFFERLOST)
    {
        for (;;)
        {
            const long hResult = pSound->pBuffer->Restore();
            if (hResult == DSERR_BUFFERLOST)
            {
                Sleep(10);
                continue;
            }
            if (hResult >= 0)
            {
                break;
            }
        }
        D2SOUND_StopSound(pSound);
    }

    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x00516070
static void D2SOUND_ReleaseSoundBuffers(D2SoundStrc* pSound)
{
    D2SOUND_StopSound(pSound);
    if (pSound->pPropertySet)
    {
        pSound->pPropertySet->Release();
        pSound->pPropertySet = 0;
    }
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->Release();
        pSound->p3DBuffer = 0;
    }
    if (pSound->pBuffer)
    {
        pSound->pBuffer->Release();
        pSound->pBuffer = 0;
    }
    memset(pSound, 0, 0x60);
}

// 0x005160D0
void __fastcall D2SOUND_DestroySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x211);
    EnterCriticalSection(&gSoundLock_0088174C);
    D2SOUND_ReleaseSoundBuffers(pSound);
    D2SOUND_ListRemove(&gpSoundList_00881808, pSound);
    LeaveCriticalSection(&gSoundLock_0088174C);
    FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x21D, 0);
}

// 0x00516140
void __fastcall D2SOUND_ResetSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x226);
    D2_ASSERT(!pSound->hStream, 0x227);

    EnterCriticalSection(&gSoundLock_0088174C);
    if (sub_00513BB0())
    {
        pSound->pData = 0;
        pSound->nDataSize = 0;
        pSound->nPosition = 0;
        pSound->nFillPosition = 0;
        pSound->bStreamed = 0;
        pSound->bNoLoop = 0;
        pSound->nMinDataSize = 0;
    }
    else
    {
        const unsigned int nFlags = pSound->dwFlags;
        D2SOUND_ReleaseSoundBuffers(pSound);
        sub_005153C0_CreateSoundBuffer(nFlags, pSound);
    }

    pSound->pBuffer->SetCurrentPosition(0);
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->SetMaxDistance(100.0f, 0);
        pSound->p3DBuffer->SetMinDistance(2.0f, 0);
    }
    if (pSound->dwFlags & 2)
        D2SOUND_SetSoundPosition(pSound, 0.0f, 0.0f, 0.0f);
    else
        pSound->pBuffer->SetPan(0);
    D2SOUND_SetSoundAttenuation(pSound, 0.0f);
    D2SOUND_SetSoundVolume(pSound, 0xFF);
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00516510
void __cdecl D2SOUND_StartSoundThread()
{
    unsigned long dwThreadId;
    D2_ASSERT(!ghSoundThread_00881810, 0xBC);
    ghSoundEvent_0088180C = CreateEventA(0, 1, 0, 0);
    ghSoundThread_00881810 = CreateThread(0, 0, sub_00516250_SoundThread, 0, 0, &dwThreadId);
}

// 0x00516570
float __stdcall sub_00516570_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x00516590
float __stdcall sub_00516590_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165B0
float __cdecl sub_005165B0_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x005165D0
float __cdecl sub_005165D0_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165F0
float __stdcall D2SOUND_ScaleToDecibels(float fMin, float fMax, float fValue)
{
    if (fValue <= fMin + 0.0001f)
        return -10000.0f;
    if (fValue >= fMax - 0.0001f)
        return 0.0f;
    return (float)(log10(fValue != 0.0f ? (fMin + fMax) / fValue : (fMin + fMax) / fMax) * -2000.0f);
}

// 0x00516670
float __stdcall D2SOUND_DecibelsToScale(float fVolume)
{
    if (fVolume + 0.0001f > 0.0)
        return 1.0f;
    if (fVolume - 0.0001f < -10000.0)
        return 0.0f;
    return (float)pow(10.0, fVolume / 2000.0);
}

// 0x005166D0
static const unsigned char* __stdcall sub_005166D0_FindRiffChunk(const unsigned char* pData, unsigned int* pnSize, unsigned int nChunkId, unsigned int* pnChunkSize)
{
    while (*pnSize >= 8)
    {
        *pnSize -= 8;
        const unsigned int nRemaining = *pnSize;
        const unsigned int* pHeader = (const unsigned int*)pData;
        pData += 8;
        const unsigned int nLength = pHeader[1];
        if (pHeader[0] == nChunkId)
        {
            *pnChunkSize = nLength;
            return pData;
        }

        if (nRemaining < nLength)
            return 0;

        *pnSize = nRemaining - nLength;
        pData += nLength;
    }

    return 0;
}

// 0x00516720
void __fastcall D2SOUND_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels)
{
    memset(pFormat, 0, sizeof(D2WaveFormatStrc));
    pFormat->wFormatTag = 1;
    pFormat->nChannels = nChannels;
    pFormat->nSamplesPerSec = 22050;
    pFormat->wBitsPerSample = 16;
    pFormat->nBlockAlign = nChannels * 2;
    pFormat->nAvgBytesPerSec = pFormat->nSamplesPerSec * pFormat->nBlockAlign;
}

extern "C" void __fastcall CLIENTS_SetPlayerUnitAlive(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}

void __cdecl sub_00650EA0_Nop()
{
}

const unsigned char* __fastcall sub_00516760_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat)
{
    if (*pnSize < 0x20)
        return 0;

    *pnSize -= 12;
    if (pRiff[0] != 0x46464952 || pRiff[2] != 0x45564157)
        return 0;

    unsigned int nChunkSize = 0;
    const unsigned char* pChunk = sub_005166D0_FindRiffChunk((const unsigned char*)pRiff + 12, pnSize, 0x20746D66, &nChunkSize);
    if (!pChunk)
        return 0;

    if (nChunkSize < 0x10)
        return 0;

    if (*pnSize < nChunkSize)
        return 0;

    *pnSize -= nChunkSize;
    const unsigned char* pNext = pChunk + nChunkSize;
    pFormat->wFormatTag = ((const D2WaveFormatStrc*)pChunk)->wFormatTag;
    pFormat->nChannels = ((const D2WaveFormatStrc*)pChunk)->nChannels;
    pFormat->nSamplesPerSec = ((const D2WaveFormatStrc*)pChunk)->nSamplesPerSec;
    pFormat->nAvgBytesPerSec = ((const D2WaveFormatStrc*)pChunk)->nAvgBytesPerSec;
    pFormat->nBlockAlign = ((const D2WaveFormatStrc*)pChunk)->nBlockAlign;
    pFormat->wBitsPerSample = ((const D2WaveFormatStrc*)pChunk)->wBitsPerSample;
    pFormat->cbSize = 0;

    pChunk = sub_005166D0_FindRiffChunk(pNext, pnSize, 0x61746164, &nChunkSize);
    if (!pChunk)
        return 0;

    if (*pnSize < nChunkSize)
        return 0;

    *pnSize = nChunkSize;
    return pChunk;
}

#include "gen/data/Source/D2Sound/Src/D2SoundSmp.inc"
