struct T00481720;

#pragma pack(push, 2)
struct D2ClientCacheEntryStrc
{
    char unk0x00[0x4C];
    char bLocked;
    char unk0x4D[0x1F];
    void* pData;
    unsigned int nSize;
    char f_74[0x0D];
    char f_81;
    T00481720* pAsync;
    int nState;
    int nRefCount;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall sub_0040A9E0(T00481720* pAsync);                                                     // 0x0040A9E0
unsigned int __fastcall sub_0040AA40(T00481720* pAsync);                                              // 0x0040AA40
int __fastcall sub_004DF630_QueryAddress(D2ClientCacheEntryStrc* pEntry);                                   // 0x004DF630
void __fastcall sub_00482710(int nIndex, char* szPath);                                                     // 0x00482710
void __fastcall sub_00482860(int nIndex);                                                                   // 0x00482860
int __stdcall sub_004824A0_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge);             // 0x004824A0
int __fastcall sub_004068E0(const char* szFileName, void** phFile);                                          // 0x004068E0
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh);                                       // 0x00406930
void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
void* __cdecl sub_004FAC80();                                                                               // 0x004FAC80
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
T00481720* __fastcall sub_0040A620(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
int __fastcall sub_0040A7F0_AsyncDataCheck(T00481720* pAsyncData);                                    // 0x0040A7F0
int __cdecl sub_00513B50();                                                                                 // 0x00513B50
void __cdecl sub_004DF800();                                                                                // 0x004DF800
void __cdecl sub_004BAAB0();                                                                                // 0x004BAAB0
void __cdecl sub_004B9D20();                                                                                // 0x004B9D20
void __cdecl sub_004E00C0();                                                                                // 0x004E00C0
void __cdecl sub_004828B0();                                                                                // 0x004828B0

extern D2ClientCacheEntryStrc* gpCacheEntries_007BC9A0;                                                     // 0x007BC9A0
extern int gdwGlobal_007BC9A4;                                                                              // 0x007BC9A4
extern int gdwGlobal_007BC9BC;                                                                              // 0x007BC9BC
unsigned int gnCacheLastTick_007BC9C0;                                                                      // 0x007BC9C0
unsigned int gnCacheLastLoadTick_007BC9C4;                                                                  // 0x007BC9C4
unsigned int gnCacheLoading_007BC9C8;                                                                       // 0x007BC9C8
extern unsigned int gnCacheMax_007BC9CC;                                                                    // 0x007BC9CC
extern unsigned int gdwCacheUsed_007BC9D0;                                                                  // 0x007BC9D0

// 0x00481720
static void sub_00481720_FinishCacheLoad(D2ClientCacheEntryStrc* pEntry)
{
    D2_ASSERT(pEntry->nState == 1, 0x40);
    pEntry->pData = sub_0040A9E0(pEntry->pAsync);
    pEntry->nSize = sub_0040AA40(pEntry->pAsync);
    pEntry->nState = 2;
    sub_004DF630_QueryAddress(pEntry);
    gnCacheLoading_007BC9C8 -= 1;
}

// 0x00482940
void __cdecl sub_00482940_UpdateSound()
{
    if (!sub_00513B50())
        return;
    sub_004DF800();
    sub_004BAAB0();
    sub_004B9D20();
    sub_004E00C0();
    sub_004828B0();
}

void __fastcall sub_00482970_LoadCacheEntry(int nIndex, int bDirect, int nArg)
{
    D2ClientCacheEntryStrc* pEntry;
    if (gpCacheEntries_007BC9A0 && nIndex >= 0 && nIndex < gdwGlobal_007BC9A4)
        pEntry = &gpCacheEntries_007BC9A0[nIndex];
    else
        pEntry = 0;

    const int nSaved = gdwGlobal_007BC9BC;
    if (pEntry->f_81)
        return;

    if (pEntry->nState == 2)
        return;
    if (pEntry->nState == 1 && !bDirect)
        return;
    if (pEntry->nState == 1 && bDirect)
    {
        sub_00481720_FinishCacheLoad(pEntry);
        return;
    }
    if (pEntry->nState)
        return;

    char szPath[0x50];
    void* hFile;
    sub_00482710(nIndex, szPath);
    if (!sub_004068E0(szPath, &hFile))
    {
        pEntry->f_81 = 1;
        return;
    }

    const unsigned int nSize = sub_00406930(hFile, 0);
    sub_004068F0(hFile);
    if (gdwCacheUsed_007BC9D0 + nSize > gnCacheMax_007BC9CC && !sub_004824A0_FreeCacheEntries(nSize + (gdwCacheUsed_007BC9D0 - gnCacheMax_007BC9CC), bDirect, nArg))
    {
        gnCacheLastLoadTick_007BC9C4 = nSaved;
        return;
    }

    if (bDirect)
    {
        pEntry->pData = sub_00517079_LoadFile(sub_004FAC80(), szPath, &pEntry->nSize, ".\\Sound\\SoundHdr.cpp", 0x301);
        D2_ASSERT(pEntry->pData && pEntry->nSize, 0x302);
        gdwCacheUsed_007BC9D0 += pEntry->nSize;
        sub_00482860(nIndex);
        pEntry->nState = 2;
        sub_004DF630_QueryAddress(pEntry);
        return;
    }

    pEntry->pAsync = sub_0040A620(0, szPath, 1, 0, -1, 0, 0, -2, ".\\Sound\\SoundHdr.cpp", 0x31B);
    if (pEntry->pAsync)
    {
        const unsigned int nAsyncSize = sub_0040AA40(pEntry->pAsync);
        gdwCacheUsed_007BC9D0 += nAsyncSize;
        pEntry->nSize = nAsyncSize;
        sub_00482860(nIndex);
        gnCacheLoading_007BC9C8 += 1;
        pEntry->nState = 1;
    }
}

// 0x00482B40
void __fastcall sub_00482B40_UpdateCache(unsigned int nTick)
{
    if (!gpCacheEntries_007BC9A0)
        return;

    const int bForce = nTick == 0;
    if (nTick && nTick - gnCacheLastTick_007BC9C0 < 0x19)
        return;

    for (int i = 1; i <= 0xB75; i++)
    {
        D2ClientCacheEntryStrc* pEntry = &gpCacheEntries_007BC9A0[i];
        if (!pEntry->nState && (pEntry->nRefCount || pEntry->bLocked))
        {
            if (!bForce)
            {
                if (gnCacheLoading_007BC9C8 >= 0xF)
                    continue;
                if (nTick - gnCacheLastLoadTick_007BC9C4 < 0xFA)
                    continue;
            }
            sub_00482970_LoadCacheEntry(i, bForce, 1);
        }
        if (pEntry->nState == 1 && sub_0040A7F0_AsyncDataCheck(pEntry->pAsync))
            sub_00481720_FinishCacheLoad(pEntry);
    }
    gnCacheLastTick_007BC9C0 = nTick;
}
