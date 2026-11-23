#include "D2Client.h"
#include "D2Unicode.h"

struct D2CandidateListStrc
{
    unsigned int dwSize;
    unsigned int dwStyle;
    unsigned int dwCount;
    unsigned int dwSelection;
    unsigned int dwPageStart;
    unsigned int dwPageSize;
    unsigned int dwOffset[1];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
extern int gnScreenHeight;                                                                               // 0x00711470

// 0x0047B5C0
void __cdecl sub_0047B5C0_DrawImeCandidates()
{
    if (gpChatBuffer_007BB5F4)
    {
        D2CandidateListStrc* const pList = (D2CandidateListStrc*)gpChatBuffer_007BB5F4;
        int nFirst;
        int nLast;
        if (pList->dwPageSize)
        {
            nFirst = pList->dwPageStart;
            if (pList->dwCount < pList->dwPageStart + pList->dwPageSize)
                nLast = pList->dwCount;
            else
                nLast = pList->dwPageStart + pList->dwPageSize;
        }
        else
        {
            nFirst = 0;
            nLast = pList->dwCount;
            if (pList->dwCount >= 20)
                nLast = 20;
        }

        int nIndex = 0;
        const int nLineHeight = D2Win_10125();
        for (int i = nFirst; i < nLast; i++)
        {
            const char* szCandidate = (const char*)pList + pList->dwOffset[i];
            ++nIndex;
            const int nY = nIndex * nLineHeight;

            Unicode wszIndex[20];
            memset(wszIndex, 0, sizeof(wszIndex));
            char szIndex[20];
            sprintf(szIndex, "%d: ", nIndex);
            Unicode::win2Unicode(wszIndex, szIndex, 20);
            D2Win_10117_DrawText(wszIndex, 20, nY + gnScreenHeight - 0x170, 0, 0);

            Unicode wszText[256];
            for (int j = 0; j < 256; j++)
                wszText[j].wChar = 0;
            if (MultiByteToWideChar(0, 1, szCandidate, -1, (wchar_t*)wszText, 0x101))
                D2Win_10117_DrawText(wszText, 0x1E, nY + gnScreenHeight - 0x170, 0, 0);

            if (nY > 0x118)
                break;
        }
    }
}
