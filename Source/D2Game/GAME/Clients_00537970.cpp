#include "D2GameClient.h"
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
typedef char check_size_owner[(sizeof(D2OwnerStrc_004CA990) == 0x7C) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004795C0
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szName;
}

// 0x004B8370
extern "C" void __fastcall ROSTER_SetCtrlState(D2PanelCtrlStrc_004B8370* pCtrl, int nState)
{
    D2_ASSERT(pCtrl, 1310);
    pCtrl->nState = nState;
}

// 0x004CA990
extern "C" void* __fastcall ROSTER_GetLinkFirst(D2OwnerStrc_004CA990* pOwner)
{
    D2_ASSERT(pOwner, 3171);
    D2LinkStrc_004CA990* pLink = pOwner->pLink;
    if (pLink)
    {
        return pLink->pFirst;
    }

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

// 0x00537970
extern "C" void __fastcall CLIENTS_SetPlayerUnitAlive(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}
