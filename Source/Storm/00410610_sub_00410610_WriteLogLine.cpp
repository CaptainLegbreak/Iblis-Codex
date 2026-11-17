typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

struct T00410610
{
    int nFirst;
    int nSecond;
    char unk0x08[0x10];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268
extern int gnBitClearMasks_006CE2E8[8];                                                                     // 0x006CE2E8
extern int gnByteTable_006CE398[256];                                                                       // 0x006CE398
extern int gnLowBitTable_006CE798[256];                                                                     // 0x006CE798
extern char gszLowerTable_006CEB98[256];                                                                    // 0x006CEB98
extern T00410610 gaRecords_0075E8A8[];                                                                // 0x0075E8A8
extern unsigned int gnRecordCount_007768A4;                                                                 // 0x007768A4
extern int gnTickAtReset_007768A0;                                                                          // 0x007768A0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00410610
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 299);
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(&gszEmptyAssertText, 1, 1, szFormat, args);
}

// 0x00410660
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 316);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 1, 1, szFormat, args);
}

// 0x004106B0
void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 335);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 1, 0, szFormat, args);
}

// 0x00410B10
void __stdcall sub_00410B10(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] |= gnBitMasks_006CE268[nBit & 7];
}

// 0x00410B30
int __stdcall sub_00410B30(unsigned char* pBits, int nBit)
{
    return pBits[nBit >> 3] & gnBitMasks_006CE268[nBit & 7];
}

// 0x00410B50
void __stdcall sub_00410B50(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] &= gnBitClearMasks_006CE2E8[nBit & 7];
}

// 0x00411130
int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize)
{
    int nChecksum = 0;
    for (int i = 0; i < nSize; ++i)
    {
        nChecksum = pData[i] + (nChecksum < 0) + 2 * nChecksum;
    }
    return nChecksum;
}

// 0x00411170
int __stdcall sub_00411170_SumByteTable(unsigned char* pData, int nSize)
{
    int nTotal = 0;
    for (unsigned char* pEnd = pData + nSize; pData < pEnd; ++pData)
    {
        nTotal += gnByteTable_006CE398[*pData];
    }
    return nTotal;
}

// 0x004111A0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue)
{
    if (nValue)
    {
        unsigned char* pBytes = (unsigned char*)&nValue;
        if (pBytes[0] > 0) return gnLowBitTable_006CE798[pBytes[0]];
        if (pBytes[1] > 0) return gnLowBitTable_006CE798[pBytes[1]] + 8;
        if (pBytes[2] > 0) return gnLowBitTable_006CE798[pBytes[2]] + 16;
        if (pBytes[3] > 0) return gnLowBitTable_006CE798[pBytes[3]] + 24;
    }
    return -1;
}

// build: context sub_00411280_ResetRecords
void __cdecl sub_00411280_ResetRecords()
{
    for (unsigned int i = 0; i < gnRecordCount_007768A4; ++i)
    {
        gaRecords_0075E8A8[i].nFirst = 0;
        gaRecords_0075E8A8[i].nSecond = 0;
    }
    gnTickAtReset_007768A0 = GetTickCount();
}

// 0x004113C0
void __fastcall sub_004113C0(char* szString, int nLength)
{
    for (char* pEnd = szString + nLength; *szString && szString < pEnd; ++szString)
    {
        *szString = gszLowerTable_006CEB98[*szString];
    }
}

#include "gen/data/Source/Storm/00410610_sub_00410610_WriteLogLine.inc"
