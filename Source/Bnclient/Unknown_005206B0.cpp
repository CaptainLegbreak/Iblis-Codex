#include "Bnclient.h"

#define HASH_ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

struct D2BnetHashContextStrc;
struct D2VersionReplyStrc;
struct D2BnReplyStrc;

struct D2BnetHashContextStrc
{
    unsigned int state[5];
    union
    {
        unsigned int block[16];
        unsigned char f_14[64];
    };
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_005206B0_HashTransform(D2BnetHashContextStrc* pContext); // 0x005206B0

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2VersionReplyStrc
{
    unsigned int nResult;
    char szText[1];
};
void __cdecl sub_00518D40_Log(const char* szFormat, ...); // 0x00518D40
int __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
extern int gnUpdateState_008822C4; // 0x008822C4

struct D2BnReplyStrc
{
    unsigned int nResult;
    char szText[0x100];
};

extern char gszReplyText_00882428[0x100]; // 0x00882428
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

// 0x005206B0
void __fastcall sub_005206B0_HashTransform(D2BnetHashContextStrc* context)
{
    unsigned int words[80];
    int i;
    for (i = 0; i < 16; ++i)
        words[i] = context->block[i];
    i = 16;
    do
    {
        const int nShift = (words[i - 3] ^ words[i - 8] ^ words[i - 16] ^ words[i - 14]) & 31;
        words[i] = HASH_ROL(1, nShift);
        ++i;
    } while (i < 80);
    unsigned int a = context->state[0];
    unsigned int b = context->state[1];
    unsigned int c = context->state[2];
    unsigned int d = context->state[3];
    unsigned int e = context->state[4];
    unsigned int t;
    unsigned int n = 0;
    for (; n < 20; ++n)
    {
        t = HASH_ROL(a, 5) + ((~b & d) | (c & b)) + words[n] + e + 0x5A827999;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 40; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0x6ED9EBA1;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 60; ++n)
    {
        t = HASH_ROL(a, 5) + (((c | b) & d) | (c & b)) + words[n] + e + 0x8F1BBCDC;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 80; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0xCA62C1D6;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    context->state[4] += e;
}

// 0x005209D0
void __fastcall sub_005209D0_HashBuffer(unsigned int* pOut, const void* pData, unsigned int nSize)
{
    D2BnetHashContextStrc tContext;
    tContext.state[0] = 0x67452301;
    tContext.state[1] = 0xEFCDAB89;
    tContext.state[2] = 0x98BADCFE;
    tContext.state[3] = 0x10325476;
    tContext.state[4] = 0xC3D2E1F0;
    for (unsigned int i = 0; i < nSize; i += 64)
    {
        unsigned int nLength = nSize - i;
        if (nLength > 64)
            nLength = 64;
        memcpy(tContext.f_14, pData, nLength);
        if (nLength < 64)
            memset(&tContext.f_14[nLength], 0, 64 - nLength);
        sub_005206B0_HashTransform(&tContext);
    }
    pOut[0] = tContext.state[0];
    pOut[1] = tContext.state[1];
    pOut[2] = tContext.state[2];
    pOut[3] = tContext.state[3];
    pOut[4] = tContext.state[4];
}

// 0x00520E50
int __fastcall sub_00520E50_HandleVersionReply(D2VersionReplyStrc* pReply, int nSize)
{
    const unsigned int nResult = pReply->nResult;
    switch (nResult)
    {
    case 1:
    case 2:
    case 3:
        sub_0051BCF0_SendBuffer();
        break;
    }

    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    if (nResult == 1)
    {
        const char* szText = pReply->szText;
        const int nLength = nSize - 4;
        sub_0051E370_SetText(szText, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szText, nLength);
        D2FileTimeStrc tFileTime = { 0 };
        sub_0051F910_Report(0x80000002, 2, 0, 0, &tFileTime, szText, 0);
        gnUpdateState_008822C4 = 0;
        sub_00518D40_Log("downloading upgrade");
        return 1;
    }

    if (nResult == 2)
    {
        gnUpdateState_008822C4 = 1;
        sub_00518D40_Log("user has latest version");
        return 1;
    }

    sub_005204A0_SetError(1);
    if (nResult == 3)
    {
        gnUpdateState_008822C4 = 0;
        sub_00518D40_Log("User must reinstall and patch");
        return 1;
    }

    gnUpdateState_008822C4 = 0;
    sub_00518D40_Log("user has unknown version");
    return 1;
}

int gnReplyReady_008823B0; // 0x008823B0

unsigned int gnReplyResult_00882420; // 0x00882420

// 0x00520FE0
int __fastcall sub_00520FE0_HandleReply(D2BnReplyStrc* pReply)
{
    const unsigned int nResult = pReply->nResult;
    gnReplyResult_00882420 = nResult;
    gszReplyText_00882428[0] = 0;
    gnReplyReady_008823B0 = 0;
    switch (nResult)
    {
    case 0:
        gnReplyReady_008823B0 = 1;
        break;
    case 3:
        sub_00520520_SetState(3);
        break;
    case 6:
        sub_00520520_SetState(5);
        break;
    case 5:
        sub_00520520_SetState(4);
        break;
    case 4:
        sub_00520520_SetState(6);
        SStrCopy(gszReplyText_00882428, pReply->szText, 0x100);
        sub_00520550_SetStateArg(gszReplyText_00882428);
        break;
    }
    return 1;
}

// 0x00522570
unsigned int __fastcall sub_00522570_GetBit(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = nIndex & 0x1F;
    return (pKey[3 - (nIndex >> 5)] & (1 << nShift)) >> nShift;
}

// 0x005225A0
void __fastcall sub_005225A0_SetBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const unsigned int nShift = nIndex & 0x1F;
    const unsigned int nWord = 3 - (nIndex >> 5);
    pKey[nWord] = (pKey[nWord] & ~(1 << nShift)) | ((nValue & 1) << nShift);
}

// 0x005226D0
void __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey)
{
    unsigned int aCopy[4];
    aCopy[0] = pKey[0];
    aCopy[1] = pKey[1];
    aCopy[2] = pKey[2];
    aCopy[3] = pKey[3];

    unsigned int nPos = 0;
    for (unsigned int i = 0; i < 120; ++i)
    {
        sub_005225A0_SetBit(pKey, i, (unsigned char)sub_00522570_GetBit(aCopy, nPos));
        nPos += 11;
        if (nPos >= 120)
        {
            nPos -= 120;
            if ((int)nPos < 0)
            {
                nPos += 11;
            }
        }
    }
}
