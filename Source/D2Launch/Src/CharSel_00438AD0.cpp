struct Unicode
{
    unsigned short wChar;

    static int __fastcall strcmp(const Unicode* str1, const Unicode* str2);                 // 0x005264F0
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);     // 0x00526F20
    static char* __fastcall unicode2Win(char* dest, const Unicode* src, int count);        // 0x00526F70
};

extern char gbRealmNamesInit_00779DA8;                                                      // 0x00779DA8
extern Unicode gwszRealmNames_00779DF0[7][0x100];                                           // 0x00779DF0
extern "C" char* __cdecl strcpy(char* dst, const char* src);
#pragma intrinsic(strcpy)

static __declspec(noinline) int sub_00437D20_IsTestRealm(const Unicode* pName);

// 0x00437D20
static int sub_00437D20_IsTestRealm(const Unicode* pName)
{
    if (!gbRealmNamesInit_00779DA8)
    {
        char szBuffer[0x100];
        gbRealmNamesInit_00779DA8 = 1;
        strcpy(szBuffer, "Testv104");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[0], szBuffer, 255);
        strcpy(szBuffer, "FatRealm");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[1], szBuffer, 255);
        strcpy(szBuffer, "BetaWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[2], szBuffer, 255);
        strcpy(szBuffer, "BetaEurope");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[3], szBuffer, 255);
        strcpy(szBuffer, "BetaUSWest");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[4], szBuffer, 255);
        strcpy(szBuffer, "BetaUSEast");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[5], szBuffer, 255);
        strcpy(szBuffer, "BetaAsia");
        Unicode::win2Unicode(gwszRealmNames_00779DF0[6], szBuffer, 255);
    }

    for (int i = 0; i < 7; ++i)
    {
        if (!Unicode::strcmp(pName, gwszRealmNames_00779DF0[i]))
        {
            return 1;
        }
    }
    return 0;
}

struct D2CompositeUnitStrc;

struct D2LaunchCharEntryStrc
{
    char szTitle[0x100];
    Unicode f_100[0x100];
    unsigned char aFlags[16];
    unsigned char aColors[16];
    unsigned char nSel;
    char unk0x321;
    short nWord322;
    short nWord324;
    short nWord326;
    short nWord328;
    char szCode32A[4];
    unsigned char nByte32E;
    unsigned char nByte32F;
    unsigned char nByte330;
    char unk0x331[3];
    int bShared;
    D2CompositeUnitStrc* pCompositeUnit;
    char unk0x33C[4];
    unsigned int nKeyLow;
    unsigned int nKeyHigh;
    int nFlag348;
    D2LaunchCharEntryStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

extern int gnGlobal_00779DC4;                                                                               // 0x00779DC4
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
extern "C" const char gszCharSelFile_006D4DBC[];                                                            // 0x006D4DBC
extern D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                          // 0x00779DBC
extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __fastcall sub_0043C750_JoinEntry(D2LaunchCharEntryStrc* pEntry, const char* szName);                  // 0x0043C750
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0
void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0
void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260
D2CompositeUnitStrc* __stdcall sub_005066C0_CreateComposite(int nSel, int nMode, unsigned char* pFlags, unsigned char* pColors); // 0x005066C0
unsigned short __stdcall sub_006BBF20_ReadPackedWord(const unsigned char* pData);                           // 0x006BBF20

static __forceinline int sub_F4B0_IsMaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_00438AD0_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm);

// 0x00438AD0
static int __stdcall sub_00438AD0_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), gszCharSelFile_006D4DBC, 0x414, 0);
    pEntry->nKeyLow = nKeyLow;
    pEntry->nKeyHigh = nKeyHigh;
    pEntry->nFlag348 = nFlag;
    SStrCopy(pEntry->szTitle, szName, 0x7FFFFFFF);

    Unicode* pText = pEntry->f_100;
    if (szRealm)
    {
        Unicode::win2Unicode(pText, szRealm, 255);
    }
    else
    {
        pText->wChar = 0;
    }

    const unsigned char* pData = (const unsigned char*)szStats;
    pEntry->nWord326 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    if (sub_00437D20_IsTestRealm(pText))
    {
        char szText[0x100];
        Unicode::unicode2Win(szText, pText, 255);
        sub_0043C750_JoinEntry(pEntry, szText);
        return 0;
    }

    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aFlags[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aFlags[i] = 0xFF;
        }
    }

    pEntry->nSel = *pData - 1;
    ++pData;
    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aColors[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aColors[i] = 0xFF;
        }
    }

    pEntry->pNext = 0;
    pEntry->nWord322 = *pData++;
    pEntry->nWord324 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    pEntry->nWord328 = sub_006BBF20_ReadPackedWord(pData);
    pData += 2;
    pEntry->nByte32E = *pData++;
    pEntry->nByte32E = pEntry->nByte32E == 0xFF ? 0 : pEntry->nByte32E;
    pEntry->nByte32F = *pData++;
    pEntry->nByte32F = pEntry->nByte32F == 0xFF ? 0 : pEntry->nByte32F;
    pEntry->nByte330 = *pData++;
    pEntry->nByte330 = pEntry->nByte330 == 0xFF ? 0 : pEntry->nByte330;
    strncpy(pEntry->szCode32A, (const char*)pData, 3);

    unsigned char nSel = pEntry->nSel;
    int nMode = 5;
    if (pEntry->nWord324 & 4)
    {
        if (pEntry->nWord324 & 8)
        {
            nSel = sub_F4B0_IsMaleClass(nSel) ? 9 : 8;
        }
        else if (sub_00408F20_HasExpansionMpq() || pEntry->nSel < 5)
        {
            nMode = 1;
        }
    }

    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(nSel, nMode, pEntry->aFlags, pEntry->aColors);
    if (!pEntry->pCompositeUnit)
    {
        for (int j = 0; j < 16; ++j)
        {
            pEntry->aFlags[j] = 0;
            pEntry->aColors[j] = 0xFF;
        }

        pEntry->aFlags[1] = 1;
        pEntry->pCompositeUnit = sub_005066C0_CreateComposite(7, 5, pEntry->aFlags, pEntry->aColors);
    }

    D2_ASSERT(pEntry->pCompositeUnit, 0x4BE);
    pEntry->bShared = 0;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);

    if (gpCharList_00779DBC)
    {
        D2LaunchCharEntryStrc* pPrev = 0;
        D2LaunchCharEntryStrc* pCur = gpCharList_00779DBC;
        if (sub_00408F20_HasExpansionMpq())
        {
            while (pCur)
            {
                if (nKeyHigh > pCur->nKeyHigh || (nKeyHigh == pCur->nKeyHigh && nKeyLow > pCur->nKeyLow))
                {
                    break;
                }

                pPrev = pCur;
                pCur = pCur->pNext;
            }

            if (pPrev)
            {
                pEntry->pNext = pPrev->pNext;
                pPrev->pNext = pEntry;
            }
            else
            {
                pEntry->pNext = gpCharList_00779DBC;
                gpCharList_00779DBC = pEntry;
            }
        }
        else
        {
            while (pCur->pNext)
            {
                pCur = pCur->pNext;
            }

            pCur->pNext = pEntry;
        }
    }
    else
    {
        gpCharList_00779DBC = pEntry;
    }

    gnGlobal_00779DC4 += 1;
    sub_00438560_Refresh();
    gdwGlobal_00779DA4 = 1;
    return 1;
}

struct D2FileTimeStrc { unsigned int dwLowDateTime; unsigned int dwHighDateTime; };

extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1D8

extern int gnGlobal_007795EC;                                                                               // 0x007795EC
extern int gnGlobal_0070CC04;                                                                               // 0x0070CC04
extern int gnGlobal_0070CC08;                                                                               // 0x0070CC08
extern int gnGlobal_00779DD8;                                                                               // 0x00779DD8

void __fastcall sub_00437AB0_CharSelCacheStore(const char* szName, unsigned char* pPacket, int nSize);      // 0x00437AB0
void __cdecl sub_00437B90_FreeCache();                                                                      // 0x00437B90
void __cdecl sub_00439210();                                                                                // 0x00439210
void __stdcall sub_0043A460_CreateNotice(const Unicode* wszTitle, const Unicode* wszText, int nArg3, int nArg4); // 0x0043A460
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

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
