#include "D2Txt.h"
struct D2TxtLinkStrc;



extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(strlen, memset)

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130

D2TxtLinkStrc* gpCompCodeLinker_0096BCB0;                                                                   // 0x0096BCB0

static void DATATBLS_MakeCompCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// 0x00657010
void __fastcall DATATBLS_MonStats2CompositLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    D2MonStats2Txt* pMonStats2TxtRecord = (D2MonStats2Txt*)pRecord;
    char szCode[4];

    if (!pMonStats2TxtRecord || (unsigned int)nOffset > 15)
    {
        return;
    }

    pMonStats2TxtRecord->nComponentChoiceCounts[nOffset] = 0;
    memset(pMonStats2TxtRecord->pComponents[nOffset].nComposit, -1, sizeof(pMonStats2TxtRecord->pComponents[nOffset].nComposit));

    if (!pSrc)
    {
        return;
    }

    char* pNext = pSrc;
    if (*pSrc == '"')
    {
        pNext = pSrc + 1;
    }

    for (char* pTmp = pNext; *pTmp; ++pTmp)
    {
        if (*pTmp == '"')
        {
            *pTmp = 0;
        }
    }

    int nCounter = 0;
    do
    {
        char* szToken = pNext;
        pNext = strchr(pNext, ',');
        if (pNext)
        {
            *pNext = 0;
            ++pNext;
        }

        if (!szToken || !*szToken || strlen(szToken) > 4)
        {
            break;
        }

        DATATBLS_MakeCompCode(szToken, szCode);
        pMonStats2TxtRecord->pComponents[nOffset].nComposit[nCounter] = (unsigned char)FOG_GetLinkIndex(gpCompCodeLinker_0096BCB0, *(unsigned int*)szCode, 1);
        ++nCounter;
    }
    while (pNext && nCounter < 12);

    pMonStats2TxtRecord->nComponentChoiceCounts[nOffset] = (unsigned char)nCounter;

    if (nOffset == 15)
    {
        int nTotal = 0;
        for (int i = 0; i < 16; ++i)
        {
            if (pMonStats2TxtRecord->nComponentChoiceCounts[i] > 1)
            {
                nTotal += pMonStats2TxtRecord->nComponentChoiceCounts[i] - 1;
            }
        }

        if (nTotal > 254)
        {
            nTotal = 254;
        }

        pMonStats2TxtRecord->nTotalPieces = (unsigned char)nTotal;
    }
}
