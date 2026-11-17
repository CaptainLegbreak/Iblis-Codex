struct Unicode { unsigned short wChar; };
struct D2FileTimeStrc { unsigned int dwLowDateTime; unsigned int dwHighDateTime; };

extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1D8

extern int gnGlobal_007795EC;                                                                               // 0x007795EC
extern int gnGlobal_0070CC04;                                                                               // 0x0070CC04
extern int gnGlobal_0070CC08;                                                                               // 0x0070CC08
extern int gnGlobal_00779DC4;                                                                               // 0x00779DC4
extern int gnGlobal_00779DD8;                                                                               // 0x00779DD8

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall sub_00437AB0_CharSelCacheStore(const char* szName, unsigned char* pPacket, int nSize);      // 0x00437AB0
void __cdecl sub_00437B90_FreeCache();                                                                      // 0x00437B90
void __cdecl sub_00439210();                                                                                // 0x00439210
void __stdcall sub_0043A460_CreateNotice(const Unicode* wszTitle, const Unicode* wszText, int nArg3, int nArg4); // 0x0043A460
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

__declspec(noinline) static int __stdcall sub_00438AD0_AddCharEntry(const char* szCharName, const char* szStats, int nExpire, unsigned int nTimeLow, unsigned int nTimeHigh, const char* szRealm);

// calling-convention shim (not game code)
static int __stdcall sub_00438AD0_AddCharEntry(const char* szCharName, const char* szStats, int nExpire, unsigned int nTimeLow, unsigned int nTimeHigh, const char* szRealm)
{
    FindClose((void*)szRealm);
    return FindClose((void*)((int)szCharName + (int)szStats + (int)nExpire + (int)nTimeLow + (int)nTimeHigh));
}

// 0x0043AAB0
void __stdcall sub_0043AAB0(const char* szName, unsigned char* pPacket, int bFlag)
{
    const unsigned char nType = pPacket[0];
    const char* pCursor = (const char*)pPacket + 9;
    unsigned int nCount = *(unsigned short*)(pPacket + 7);

    if (!sub_00408F20_HasExpansionMpq())
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x1419);
        unsigned short nText = 0x141B;
        if (gnGlobal_007795EC != 1)
            nText = 0x141A;
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(nText);
        gnGlobal_0070CC04 = gnGlobal_00779DC4;
        sub_0043A460_CreateNotice(wszTitle, wszText, 1, 0xC);
    }

    unsigned int nEntries = *(unsigned short*)(pPacket + 3);
    if (nCount < nEntries)
        nEntries = nCount;

    for (unsigned int i = 0; i < nEntries; ++i)
    {
        int nExpire = 0;
        if (nType == 0x19)
        {
            nExpire = *(const int*)pCursor;
            pCursor += 4;
        }

        const char* szCharName = pCursor;
        pCursor += strlen(pCursor) + 1;
        const char* szStats = pCursor;
        pCursor += strlen(pCursor) + 1;
        D2FileTimeStrc tTime = {};
        if (!sub_00438AD0_AddCharEntry(szCharName, szStats, nExpire, tTime.dwLowDateTime, tTime.dwHighDateTime, szName))
        {
            --nCount;
            sub_00437B90_FreeCache();
            bFlag = 0;
        }
    }

    if (bFlag)
    {
        sub_00437AB0_CharSelCacheStore(szName, pPacket, (const unsigned char*)pCursor - pPacket);
    }

    if (nCount >= *(unsigned short*)(pPacket + 1))
    {
        gnGlobal_00779DD8 = 1;
    }

    if (*(unsigned short*)(pPacket + 3) > *(unsigned short*)(pPacket + 7))
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
        Unicode wszEmpty;
        wszEmpty.wChar = 0;
        gnGlobal_0070CC08 = gnGlobal_00779DC4;
        sub_0043A460_CreateNotice(wszTitle, &wszEmpty, 2, 0x12);
    }

    sub_00439210();
}
