#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
int __stdcall D2Win_10125();                                                                                // 0x00501A40
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00507B30
int __fastcall ACCOUNTLIST_Draw(D2WinControlStrc* pControl)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)pControl;

    D2_ASSERT(pAccountList->controlHeader.eType == 0x0C, 0xD0);

    if (!(pAccountList->controlHeader.dwFlags & gdwBitMasks[2]) || !(pAccountList->controlHeader.dwFlags & gdwBitMasks[0]) || !pAccountList->pDataList)
    {
        return 0;
    }

    sub_00502EF0(pAccountList->eFont);

    Unicode wszText[256];

    int nCounter = 0;
    const int nBaseX = pAccountList->controlHeader.nImageX;
    D2WinAccountListDataStrc* pData = pAccountList->pDataList;
    const int nBaseY = pAccountList->controlHeader.nImageY - pAccountList->controlHeader.nHeight + D2Win_10125();

    for (; pData; pData = pData->pNext)
    {
        if (nCounter >= pAccountList->unk0x48 && nCounter < pAccountList->unk0x48 + 24)
        {
            const int nX = nBaseX + 120 * (nCounter % 6);
            const int nY = nBaseY + 20 * (nCounter / 6);
            D2GFX_DrawBox(nX, nY - 14, nX + 28, nY, 0x55, 5);

            sub_00526F20_ToUnicode(wszText, pData->szText, 256);
            sub_00502320(wszText, nX + 32, nY, 0, 0);

            if (pData == pAccountList->pSelectedDataEntry)
            {
                D2GFX_DrawBox(nX - 1, nY - 16, nX + 118, nY + 1, 0xFF, 1);
            }
        }

        ++nCounter;
    }

    return 1;
}
