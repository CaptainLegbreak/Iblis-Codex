struct T00481720;

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

struct D2ClientCacheNodeStrc
{
    int nId;
    D2ClientCacheNodeStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);

int __cdecl sub_00513B50();                                                                                 // 0x00513B50
void __cdecl sub_00481950();                                                                 // 0x00481950
void __fastcall sub_004E0050(int nArg);                                                                     // 0x004E0050
void __cdecl sub_004B9D00();                                                                                // 0x004B9D00
void __cdecl sub_004DCA30();                                                                                // 0x004DCA30
void __cdecl sub_004CA280();                                                                                // 0x004CA280
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0
int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0
void __fastcall sub_00516980_RemoveNode(D2ClientCacheNodeStrc** ppList, int nId);                           // 0x00516980
void __fastcall sub_00516A70_AppendNode(D2ClientCacheNodeStrc** ppList, int nId);                           // 0x00516A70
void __fastcall sub_0040AB00_FreeAsyncData(T00481720* pAsync);                                        // 0x0040AB00
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0

D2ClientCacheEntryStrc* gpCacheEntries_007BC9A0;                                                            // 0x007BC9A0
int gnCacheEntries_007BC9A4;                                                                                // 0x007BC9A4
D2ClientCacheNodeStrc* gpCacheList_007BC9B8;                                                                // 0x007BC9B8
extern int gdwGlobal_007BC9BC;                                                                              // 0x007BC9BC
extern unsigned int gnCacheLastTick_007BC9C0;                                                               // 0x007BC9C0
extern unsigned int gnCacheLastLoadTick_007BC9C4;                                                           // 0x007BC9C4
extern unsigned int gnCacheLoading_007BC9C8;                                                                // 0x007BC9C8
unsigned int gnCacheMax_007BC9CC;                                                                           // 0x007BC9CC
extern unsigned int gdwCacheUsed_007BC9D0;                                                                  // 0x007BC9D0

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
    sub_00481950();
    sub_004E0050(nArg);
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
