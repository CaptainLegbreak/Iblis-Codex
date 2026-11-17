enum D2ControlTypes
{
    D2WIN_LIST = 7,
};

enum D2FontTypes
{
    D2FONT_FONT16 = 1,
};

struct Unicode
{
    unsigned short wChar;
};

struct SMSGHANDLER_PARAMS;
struct D2CelFileStrc;
struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    int field_21C;
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int eFont;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int nWidestEntry;
    D2WinListDataStrc* pDataList;
    D2WinListDataStrc* pSelectedDataEntry;
};

struct D2WinListInitStrc
{
    int nStringId;
    char nFlag;
    char pad0x05[3];
    int nValue;
    D2WinMsgHandler f_C;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall LIST_Draw(D2WinControlStrc* pControl);                                                       // 0x00507160
int __stdcall LIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                               // 0x005072F0
int __stdcall LIST_HandleCharInput(SMSGHANDLER_PARAMS* pMsg);                                               // 0x005073B0
int __stdcall LIST_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00507420
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern int gnListFontHeight_006DD024[];                                                                     // 0x006DD024

// 0x005075E0
D2WinListStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, D2WinListInitStrc* pInit, int* pFont)
{
    D2WinListStrc* pList = (D2WinListStrc*)FOG_Alloc(sizeof(D2WinListStrc), ".\\Src\\D2WinList.cpp", 0x2E, 0);
    memset(pList, 0, sizeof(D2WinListStrc));
    pList->controlHeader.nType = D2WIN_LIST;
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pList->controlHeader.nImageX = nX;
    pList->controlHeader.nImageY = nY;
    pList->controlHeader.nWidth = nWidth;
    pList->controlHeader.nHeight = nHeight;
    pList->controlHeader.pCellFile = 0;
    pList->controlHeader.pfDraw = LIST_Draw;
    pList->controlHeader.pfHandleMouseDown = LIST_HandleMouseDown;
    pList->controlHeader.pfHandleMouseUp = 0;
    pList->controlHeader.pfHandleCharInput = LIST_HandleCharInput;
    pList->controlHeader.pfHandleVirtualKeyInput = LIST_HandleVirtualKeyInput;
    pList->controlHeader.field_34 = 0;
    pList->controlHeader.pNext = 0;
    pList->field_5C = 0;
    pList->pDataList = 0;
    pList->eFont = *pFont;
    pList->field_44 = gnListFontHeight_006DD024[pList->eFont];
    pList->field_48 = gnListFontHeight_006DD024[pList->eFont] >> 2;
    pList->nWidestEntry = 0;
    pList->field_4C = 0;
    pList->field_50 = 0;
    pList->field_54 = -1;
    pList->field_58 = nHeight / (pList->field_44 + 2 * pList->field_48) - 1;

    sub_00502EF0(*pFont);

    for (D2WinListInitStrc* pEntry = pInit; pEntry->nStringId; ++pEntry)
    {
        D2WinListDataStrc* pData = (D2WinListDataStrc*)FOG_Alloc(sizeof(D2WinListDataStrc), ".\\Src\\D2WinList.cpp", 0x56, 0);
        const Unicode* pText = D2LANG_GetStringFromTblIndex((unsigned short)pEntry->nStringId);
        D2_ASSERT(sub_00526800(pText) < 256, 0x58);
        sub_005267E0(pData->wszText, pText);

        int nTextWidth;
        int nTextHeight;
        D2Win_10131_GetTextDimensions(pText, &nTextWidth, &nTextHeight);
        nTextWidth += 8;
        if (nTextWidth > pList->nWidestEntry)
        {
            pList->nWidestEntry = nTextWidth;
        }

        pData->field_200 = nTextWidth;
        pData->field_204 = pEntry->f_C;
        pData->field_208 = 0;
        pData->field_20C = 0;
        pData->field_210 = 0;
        pData->field_214 = 0;
        pData->field_218 = pEntry->nFlag;
        pData->field_21C = pEntry->nValue;
        pData->pNext = 0;

        if (pList->pDataList)
        {
            D2WinListDataStrc* pLast = pList->pDataList;
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pData;
        }
        else
        {
            pList->pDataList = pData;
        }

        ++pList->field_50;
    }

    sub_00502EF0(D2FONT_FONT16);
    pList->pSelectedDataEntry = pList->pDataList;
    CONTROL_AppendToList(&pList->controlHeader);
    return pList;
}

#include "gen/data/Source/D2Win/005075E0_LIST_Create.inc"
