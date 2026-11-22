#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"
#include "D2Unicode.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
int __stdcall D2Win_10125();                                                                                // 0x00501A40
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

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
        if (nCounter >= pAccountList->nFirstDrawnEntry && nCounter < pAccountList->nFirstDrawnEntry + 24)
        {
            const int nX = nBaseX + 120 * (nCounter % 6);
            const int nY = nBaseY + 20 * (nCounter / 6);
            D2GFX_DrawBox(nX, nY - 14, nX + 28, nY, 0x55, 5);

            sub_00526F20_ToUnicode(wszText, pData->szText, 256);
            D2Win_10117_DrawText(wszText, nX + 32, nY, 0, 0);

            if (pData == pAccountList->pSelectedDataEntry)
            {
                D2GFX_DrawBox(nX - 1, nY - 16, nX + 118, nY + 1, 0xFF, 1);
            }
        }

        ++nCounter;
    }

    return 1;
}

// 0x00507850
void __fastcall ACCOUNTLIST_FreeData(D2WinAccountListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x5D);
    D2WinAccountListDataStrc* pNext = 0;
    for (D2WinAccountListDataStrc* pData = ptListData->pDataList; pData; pData = pNext)
    {
        pNext = pData->pNext;
        FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0x63, 0);
    }
}

// 0x00507AF0
int __fastcall ACCOUNTLIST_Destroy(D2WinAccountListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x50);
    ACCOUNTLIST_FreeData(ptListData);
    return CONTROL_RemoveFromList(&ptListData->controlHeader);
}

// 0x00507900
int __fastcall ACCOUNTLIST_RemoveEntry(D2WinAccountListStrc* ptListData, const char* szText)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x90);

    D2WinAccountListDataStrc* pPrevious = 0;
    for (D2WinAccountListDataStrc* pData = ptListData->pDataList; pData; pData = pData->pNext)
    {
        if (!strcmp(pData->szText, szText))
        {
            if (ptListData->pSelectedDataEntry == pData)
            {
                ptListData->pSelectedDataEntry = 0;
            }

            if (pPrevious)
            {
                pPrevious->pNext = pData->pNext;
            }
            else
            {
                ptListData->pDataList = pData->pNext;
            }

            FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0xA7, 0);
            return 1;
        }

        pPrevious = pData;
    }

    return 0;
}

// 0x005078A0
void __fastcall ACCOUNTLIST_AllocData(D2WinAccountListStrc* ptListData, const char* szText)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x72);
    D2WinAccountListDataStrc* pData = (D2WinAccountListDataStrc*)FOG_Alloc(sizeof(D2WinAccountListDataStrc), ".\\Src\\D2WinAccountList.cpp", 0x77, 0);
    strncpy(pData->szText, szText, sizeof(pData->szText));
    pData->pNext = ptListData->pDataList;
    ptListData->pDataList = pData;
}
