#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define OFFSET(T, M) ((unsigned int)&(((T*)0)->M))
struct D2ClientCacheEntryStrc;
struct D2ClientCacheNodeStrc;
struct PlayerNode;
struct PlayerListHead;

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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
void __cdecl sub_00481950_LoadSoundTables(); // 0x00481950
void __fastcall sub_004E0050_RestartSound(int nArg); // 0x004E0050
void __cdecl sub_004B9D00(); // 0x004B9D00
void __cdecl sub_004CA280(); // 0x004CA280
int __fastcall sub_004DF9D0_CheckCacheEntry(int nId); // 0x004DF9D0
void __fastcall sub_00516980_RemoveNode(D2ClientCacheNodeStrc** ppList, int nId); // 0x00516980
void __fastcall sub_00516A70_AppendNode(D2ClientCacheNodeStrc** ppList, int nId); // 0x00516A70
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall sub_004E40A0(int nRange); // 0x004E40A0
extern int gdwGlobal_007BC9BC; // 0x007BC9BC
extern unsigned int gnCacheLastTick_007BC9C0; // 0x007BC9C0
extern unsigned int gnCacheLastLoadTick_007BC9C4; // 0x007BC9C4
extern unsigned int gnCacheLoading_007BC9C8; // 0x007BC9C8
extern unsigned int gdwCacheUsed_007BC9D0; // 0x007BC9D0

typedef char NodeFlags[(OFFSET(PlayerNode, flags) == 4) ? 1 : -1];

typedef char NodeNext[(OFFSET(PlayerNode, next) == 8) ? 1 : -1];

extern const char gPlayerListFile[];
extern void* gAuxSoundRows; // 0x007BC9A8
extern int gAuxSoundCount; // 0x007BC9AC
extern void* gCacheRows; // 0x007BC9A0
extern int gnCacheEntries_007BC9A4; // 0x007BC9A4
extern int gTextY;
extern int gTextRight;
PlayerListHead* __fastcall sub_0047A310(int playerId);
void* __fastcall Allocate(U32 bytes, const char* file, int line, U32 flags);
int __fastcall Release(void* allocation, const char* file, int line, U32 flags); // 0x0040B3C0
void __fastcall sub_004823E0(int index); // 0x004823E0
void* __cdecl sub_004646A0();
int __stdcall DUNGEON_GetLevelIdFromRoom(void* room);
const U16* __fastcall sub_00453E70(int levelId);
int __fastcall sub_00501820(const U16* text);
void __fastcall sub_00502320(const U16* text, int x, int y, int color, int mode);

D2ClientCacheEntryStrc* gpCacheEntries_007BC9A0; // 0x007BC9A0

int gnCacheEntries_007BC9A4; // 0x007BC9A4

D2ClientCacheNodeStrc* gpCacheList_007BC9B8; // 0x007BC9B8

unsigned int gnCacheMax_007BC9CC; // 0x007BC9CC

// 0x00481840
void __fastcall sub_00481840_SetCacheMax(unsigned int nMax)
{
    gnCacheMax_007BC9CC = nMax;
}

// 0x00481850
void __cdecl sub_00481850()
{
}

// 0x00481860
D2ClientCacheEntryStrc* __fastcall sub_00481860_GetCacheEntry(int nIndex)
{
    if (gpCacheEntries_007BC9A0 && nIndex >= 0 && nIndex < gnCacheEntries_007BC9A4)
        return &gpCacheEntries_007BC9A0[nIndex];
    return 0;
}

// 0x00481890
int __fastcall sub_00481890_GetCacheFirst(int nIndex)
{
    if (!gpCacheEntries_007BC9A0)
        return 0;
    return sub_00481860_GetCacheEntry(nIndex)->nFirstVariant;
}

// 0x004818C0
unsigned char __fastcall sub_004818C0_GetCacheCount(int nIndex)
{
    if (!gpCacheEntries_007BC9A0)
        return 0;
    return sub_00481860_GetCacheEntry(nIndex)->nVariants;
}

// 0x004818F0
int __fastcall sub_004818F0_GetCacheKind(int nIndex)
{
    if (!gpCacheEntries_007BC9A0)
        return 0;
    return sub_00481860_GetCacheEntry(nIndex)->nKindByte;
}

// 0x00482260
void __fastcall sub_00482260_UpdateSoundSystem(int nArg)
{
    if (!sub_00513B50())
        return;
    sub_00481950_LoadSoundTables();
    sub_004E0050_RestartSound(nArg);
    sub_004B9D00();
    sub_004DCA30();
    sub_004CA280();
    sub_00515CE0_SetMasterVolume(0xFF);
    gdwGlobal_007BC9BC = 0;
    gnCacheLastTick_007BC9C0 = 0;
    gnCacheLastLoadTick_007BC9C4 = 0;
    gnCacheLoading_007BC9C8 = 0;
}

// build: context sub_004823E0_ReleaseCacheEntry
void __fastcall sub_004823E0_ReleaseCacheEntry(int nIndex)
{
    D2ClientCacheEntryStrc* pEntry = sub_00481860_GetCacheEntry(nIndex);
    if (!pEntry->nState)
        return;
    D2_ASSERT(!sub_004DF9D0_CheckCacheEntry(nIndex), 0x259);
    gdwCacheUsed_007BC9D0 -= pEntry->nSize;
    sub_00516980_RemoveNode(&gpCacheList_007BC9B8, nIndex);
    pEntry->dwLastUse = 0;
    if (pEntry->pAsync)
    {
        sub_0040AB00_FreeAsyncData(pEntry->pAsync);
        pEntry->pAsync = 0;
        pEntry->pData = 0;
        pEntry->nState = 0;
        return;
    }
    FOG_Free(pEntry->pData, ".\\Sound\\SoundHdr.cpp", 0x272, 0);
    pEntry->pData = 0;
    pEntry->nState = 0;
}

// 0x004825B0
float __fastcall sub_004825B0_GetCacheVolume(int nIndex)
{
    switch (sub_00481860_GetCacheEntry(nIndex)->nKind)
    {
    case 0:
        return 60.0f;
    case 1:
        return 60.0f;
    case 2:
        return 200.0f;
    case 3:
        return 400.0f;
    case 4:
        return 2000.0f;
    }
    return 60.0f;
}

// 0x00482610
float __fastcall sub_00482610_GetCacheRange(int nIndex)
{
    switch (sub_00481860_GetCacheEntry(nIndex)->nKind)
    {
    case 0:
        return 400.0f;
    case 2:
        return 1000.0f;
    case 3:
        return 1500.0f;
    case 4:
        return 2000.0f;
    default:
        return 700.0f;
    }
}

// 0x00482680
int __fastcall sub_00482680_PickVariant(int nIndex)
{
    if (!gpCacheEntries_007BC9A0)
        return nIndex;
    D2ClientCacheEntryStrc* pEntry = sub_00481860_GetCacheEntry(nIndex);
    const unsigned char nVariants = pEntry->nVariants;
    if (nVariants <= 1)
        return nIndex;

    int nRecent = nVariants - 1 < 2 ? nVariants - 1 : 2;
    if (nVariants <= 3 && !sub_004E40A0(nVariants + 1))
        --nRecent;

    for (;;)
    {
        const int nResult = sub_004E40A0(pEntry->nVariants) + nIndex;
        bool bFound = false;
        for (int i = 0; i < nRecent; i++)
        {
            if (nResult == pEntry->anRecent[i])
            {
                bFound = true;
                break;
            }
        }
        if (!bFound)
            return nResult;
    }
}

// 0x00482710
void __fastcall sub_00482710_GetCachePath(int nIndex, char* szPath)
{
    D2ClientCacheEntryStrc* pEntry = sub_00481860_GetCacheEntry(nIndex);
    if (nIndex >= 0xB76 && nIndex <= 0xB76 + 0x6BA)
        strcpy(szPath, "DATA\\LOCAL");
    else
        strcpy(szPath, "DATA\\GLOBAL");

    if (nIndex >= 0x1231 && nIndex <= 0x1231 + 0x29)
        strcat(szPath, "\\MUSIC\\");
    else
        strcat(szPath, "\\SFX\\");

    D2_ASSERT(strlen(szPath) + strlen(pEntry->szName) < 0x50, 0x3AB);
    strcat(szPath, pEntry->szName);
}

// 0x00482860
void __fastcall sub_00482860_TouchCacheEntry(int nIndex)
{
    sub_00481860_GetCacheEntry(nIndex)->dwLastUse = gdwGlobal_007BC9BC;
    sub_00516980_RemoveNode(&gpCacheList_007BC9B8, nIndex);
    sub_00516A70_AppendNode(&gpCacheList_007BC9B8, nIndex);
}

int gSoundMaxId; // 0x007BC9B4

int gSoundMinId; // 0x007BC9B0

// 0x004828B0
void __cdecl sub_004828B0_ReleaseSoundTables()
{
    if (gAuxSoundRows)
    {
        Release(gAuxSoundRows, ".\\Sound\\SoundHdr.cpp", 385, 0);
        gAuxSoundRows = 0;
        gAuxSoundCount = 0;
    }
    if (gCacheRows)
    {
        for (int index = 1; index < gnCacheEntries_007BC9A4; index += 1)
            sub_004823E0(index);
        Release(gCacheRows, ".\\Sound\\SoundHdr.cpp", 398, 0);
        gCacheRows = 0;
        gnCacheEntries_007BC9A4 = 0;
    }
    gSoundMinId = 0;
    gSoundMaxId = 0;
}
