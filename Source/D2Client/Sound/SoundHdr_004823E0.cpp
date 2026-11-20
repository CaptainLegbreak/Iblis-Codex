#include "D2Client.h"

#pragma pack(push, 1)
struct D2ClientCacheEntryStrc
{
    char szName[0x3D];
    unsigned char nVariants;
    unsigned char nKindByte;
    char unk0x3F[0x08];
    int nKind;
    char unk0x4B[0x15];
    int nFirstVariant;
    int anRecent[2];
    void* pData;
    unsigned int nSize;
    char f_74[0x08];
    int dwLastUse;
    char unk0x80[0x02];
    T00481720* pAsync;
    int nState;
    unsigned int nRefCount;
};
#pragma pack(pop)
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall sub_004DF9D0_CheckCacheEntry(int nId); // 0x004DF9D0
void __fastcall sub_00516980_RemoveNode(D2ClientCacheNodeStrc** ppList, int nId); // 0x00516980
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

extern D2ClientCacheEntryStrc* sgptSoundHeaderTable; // 0x007BC9A0
extern int gnCacheEntries_007BC9A4; // 0x007BC9A4
extern D2ClientCacheNodeStrc* gpCacheList_007BC9B8; // 0x007BC9B8
extern unsigned int gdwCacheUsed_007BC9D0; // 0x007BC9D0

static D2ClientCacheEntryStrc* __fastcall sub_00481860_GetCacheEntry(int nIndex)
{
    if (sgptSoundHeaderTable && nIndex >= 0 && nIndex < gnCacheEntries_007BC9A4)
        return &sgptSoundHeaderTable[nIndex];
    return 0;
}

// 0x004823E0
void __fastcall sub_004823E0_ReleaseCacheEntry(int nIndex)
{
    D2ClientCacheEntryStrc* pEntry = sub_00481860_GetCacheEntry(nIndex);
    if (!pEntry->nState)
        return;
    if (sub_004DF9D0_CheckCacheEntry(nIndex))
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x259);
        exit(-1);
    }
    gdwCacheUsed_007BC9D0 -= pEntry->nSize;
    sub_00516980_RemoveNode(&gpCacheList_007BC9B8, nIndex);
    pEntry->dwLastUse = 0;
    if (pEntry->pAsync)
    {
        sub_0040AB00_FreeAsyncData(pEntry->pAsync);
        pEntry->pAsync = 0;
        pEntry->nState = 0;
        pEntry->pData = 0;
        return;
    }
    FOG_Free(pEntry->pData, ".\\Sound\\SoundHdr.cpp", 0x272, 0);
    pEntry->nState = 0;
    pEntry->pData = 0;
}
