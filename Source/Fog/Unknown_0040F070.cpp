#include "Fog.h"
#include "D2StormLink.h"

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2LogMessageStrc;
struct D2LogDumpStrc;
struct D2StormLinkStrc;
struct D2StormListStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2LogMessageStrc
{
    void* pLinkPrev;
    char* pLinkNext;
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc f_14;
    char szName[1];
};

struct D2LogDumpStrc
{
    const unsigned char* pAddress;
    unsigned int nSize;
    int bShortAddress;
    int bIndirect;
    int bShowAscii;
    char szLabel[1];
};

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize); // 0x0040EBD0
void __fastcall sub_0040ECC0_LogWriteHeader(_iobuf* pFile, const D2SystemTimeStrc* pTime); // 0x0040ECC0
void __fastcall sub_0040ED40_LogWriteStartup(_iobuf* pFile); // 0x0040ED40
extern int ganLogNewFile_0075D298[20]; // 0x0075D298
extern char gaszLogFilePaths_0075D340[20][0x104]; // 0x0075D340
extern unsigned long gadwLogOpenTick_0075E7E0[20]; // 0x0075E7E0
extern "C" const char gszLogTimeStampFormat_006CE1DC[]; // 0x006CE1DC
extern "C" const char gszLogBlankStamp_006CE1CC[]; // 0x006CE1CC
extern "C" const char gszLogDumpAddress16_006CE1C0[]; // 0x006CE1C0
extern "C" const char gszLogDumpAddress32_006CE1B4[]; // 0x006CE1B4
extern "C" const char gszLogUnreadable_006CD880[]; // 0x006CD880
extern "C" const char gszLogDumpByte_006CE1AC[]; // 0x006CE1AC
extern "C" const char gszLogDumpByteSpaced_006CE1A4[]; // 0x006CE1A4
extern "C" const char gszLogLineFormat_006CD90C[]; // 0x006CD90C


struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

// 0x0040EDE0
_iobuf* __fastcall sub_0040EDE0_GetLogFile(const char* szName, int* pnSlot)
{
    const unsigned long dwTick = GetTickCount();
    int nEmpty = -1;
    int nFree = -1;
    int nOldest;
    int nSlot = -1;
    _iobuf* pFile;

    int i = szName[0] != 0;
    nOldest = 1;
    for (; i < 20; ++i)
    {
        if (!strcmp(gaszLogNames_0075D148[i], szName))
        {
            nSlot = i;
            pFile = gapLogFiles_0075E790[i];
            if (pFile)
            {
                goto done;
            }
            break;
        }

        if (!gaszLogNames_0075D148[i][0])
        {
            if (nEmpty < 0)
            {
                nEmpty = i;
            }
        }
        else if (!gapLogFiles_0075E790[i])
        {
            if (nFree < 0)
            {
                nFree = i;
            }
            else if (dwTick - gadwLogWriteTick_0075D2F0[i] > gadwLogWriteTick_0075D2F0[nFree])
            {
                nFree = i;
            }
        }
        else if (dwTick - gadwLogWriteTick_0075D2F0[i] > dwTick - gadwLogWriteTick_0075D2F0[nOldest])
        {
            nOldest = i;
        }
    }

    if (nSlot < 0)
    {
        if (nEmpty >= 0)
        {
            nSlot = nEmpty;
        }
        else
        {
            if (nFree >= 0)
            {
                nOldest = nFree;
            }

            if (gapLogFiles_0075E790[nOldest])
            {
                fclose(gapLogFiles_0075E790[nOldest]);
                gapLogFiles_0075E790[nOldest] = 0;
            }

            nSlot = nOldest;
        }
    }

    {
        D2_ASSERT(SStrLen(szName) < 16, 0x34C);
        strcpy(gaszLogNames_0075D148[nSlot], szName);

        D2SystemTimeStrc tTime;
        int bNew;
        _iobuf* pNewFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "a", &bNew, gaszLogFilePaths_0075D340[nSlot], 0x104);
        gapLogFiles_0075E790[nSlot] = pNewFile;
        gadwLogOpenTick_0075E7E0[nSlot] = dwTick;
        gadwLogWriteTick_0075D2F0[nSlot] = dwTick;
        if (ganLogNewFile_0075D298[nSlot] && pNewFile)
        {
            sub_0040ED40_LogWriteStartup(pNewFile);
            ganLogNewFile_0075D298[nSlot] = 0;
        }
        else if (bNew)
        {
            sub_0040ECC0_LogWriteHeader(pNewFile, &tTime);
        }
    }

    pFile = gapLogFiles_0075E790[nSlot];

done:
    if (pFile && pnSlot)
    {
        *pnSlot = nSlot;
    }

    return pFile;
}

// 0x0040F070
void __fastcall sub_0040F070_WriteDumpMessage(D2LogMessageStrc* pMessage)
{
    D2SystemTimeStrc* const pStamp = &pMessage->f_14;
    D2_ASSERT(pMessage->nType == 2, 0x389);
    char* szName = pMessage->szName;
    D2LogDumpStrc* pDump = (D2LogDumpStrc*)(szName + SStrLen(szName) + 1);
    const unsigned char* pData;
    char* const szLabel = pDump->szLabel;
    if (pDump->bIndirect)
    {
        pData = pDump->pAddress;
    }
    else
    {
        pData = (const unsigned char*)(szLabel + SStrLen(szLabel) + 1);
    }

    int nSlot;
    _iobuf* pFile = sub_0040EDE0_GetLogFile(szName, &nSlot);
    if (!pFile)
    {
        return;
    }

    char szTime[32];
    SStrPrintf(szTime, sizeof(szTime), gszLogTimeStampFormat_006CE1DC, pStamp->wHour, pStamp->wMinute, pStamp->wSecond, pStamp->wMilliseconds);
    char szWhite[32];
    SStrCopy(szWhite, gszLogBlankStamp_006CE1CC, sizeof(szWhite));

    const unsigned char* pCur = pData;
    unsigned int nRemain = pDump->nSize;
    int bFirst = 1;
    while (nRemain > 0)
    {
        const unsigned int nOffset = pCur - pData;
        fprintf(pFile, pDump->bShortAddress ? gszLogDumpAddress16_006CE1C0 : gszLogDumpAddress32_006CE1B4, bFirst ? szTime : szWhite, szLabel, pDump->bShortAddress ? nOffset : (unsigned int)pDump->pAddress + nOffset);
        bFirst = 0;
        unsigned int nLine = nRemain < 16 ? nRemain : 16;

        char szLine[0x100];
        szLine[0] = 0;
        if (IsBadReadPtr(pCur, nLine))
        {
            SStrCopy(szLine, gszLogUnreadable_006CD880, 0x7FFFFFFF);
        }
        else
        {
            unsigned int i;
            for (i = 0; i < nLine; ++i)
            {
                const unsigned int nLen = strlen(szLine);
                SStrPrintf(&szLine[nLen], sizeof(szLine) - nLen, (i & 3) ? gszLogDumpByte_006CE1AC : gszLogDumpByteSpaced_006CE1A4, pCur[i]);
            }

            if (pDump->bShowAscii)
            {
                for (i = (16 - nLine) * 9 / 4 + 2; i; --i)
                {
                    SStrPack(szLine, gszSpace_006FFC44, sizeof(szLine));
                }

                const int nLen = strlen(szLine);
                int j = nLen;
                for (i = 0; i < nLine; ++i)
                {
                    unsigned char c = pCur[i];
                    szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
                }
                szLine[nLen + i] = 0;
            }
        }

        fprintf(pFile, gszLogLineFormat_006CD90C, szLine);
        pCur += nLine;
        nRemain -= nLine;
    }
}

#include "gen/data/Source/Fog/Unknown_0040F070.inc"

// 0x0040F520
char* __fastcall sub_0040F520_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0040F580
void __fastcall sub_0040F580_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0040F350
void __cdecl AUTOMAP_CloseStaleLogs()
{
    char szPath[0x104];
    int bLog = 0;
    szPath[0] = 0;
    unsigned long nNow = GetTickCount();
    for (int i = 0; i < 20; ++i)
    {
        if (gapLogFiles_0075E790[i])
        {
            if (nNow - gadwLogOpenTick_0075E7E0[i] > 15000 || nNow - gadwLogWriteTick_0075D2F0[i] > 5000)
            {
                if (bLog)
                {
                    OutputDebugStringA(szPath);
                }
                fclose(gapLogFiles_0075E790[i]);
                gapLogFiles_0075E790[i] = 0;
            }
        }
    }
}
