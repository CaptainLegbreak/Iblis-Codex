#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
struct D2CelFileStrc;
struct D2CelStrc;
struct D2WinControlStrc;


struct D2WinImageClickRectStrc;

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2AnimatedImageDescriptor;

struct D2CompPairStrc
{
    int nKey;
    int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __fastcall IMAGE2_Draw(D2WinControlStrc* pControl);                                                     // 0x004FD1F0
int __fastcall IMAGE_Draw(D2WinControlStrc* pControl);                                                      // 0x004FD470
int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x004FD5D0
int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl);                             // 0x005003A0
int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl);                                                  // 0x005005B0
void __fastcall D2SOUND_10039(const char* szFile);                                                          // 0x00514EC0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8
extern D2CompPairStrc gaCompPairs_0072EF68[];                                                               // 0x0072EF68
extern unsigned int gnCompPairs_0072EFD0;                                                                   // 0x0072EFD0
extern int gnWinCallbackDepth_007D55C4;                                                                     // 0x007D55C4
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
Unicode gwszFramedText_00841EC8[1024];                                                                      // 0x00841EC8
int gnFramedTextX_008426C8;                                                                                 // 0x008426C8
int gnFramedTextY_008426CC;                                                                                 // 0x008426CC
int gnFramedTextColor_008426D0;                                                                             // 0x008426D0
int gnFramedTextAlign_008426D4;                                                                             // 0x008426D4
int gnFramedTextRectColor_008426D8;                                                                         // 0x008426D8
extern D2CelFileStrc* ghSquelchCelFile_0087E844;                                                            // 0x0087E844
extern int gnSquelchCelFileFrameCount_0087E848;                                                             // 0x0087E848
extern D2CelFileStrc* ghSelectedCelFile_0087E850;                                                           // 0x0087E850
extern int gnSelectedCelFileFrameCount_0087E854;                                                            // 0x0087E854

// 0x004FBC80
void __fastcall D2Win_10059(D2WinTextBoxStrc* pTextBox, int nColumn, int a3)
{
    D2_ASSERT(pTextBox, 0x2EF);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x2F0);
    D2_ASSERT((nColumn >= 0) && (nColumn < pTextBox->nNumColumns), 0x2F2);
    pTextBox->unk0x68[nColumn] = a3;
}

// 0x004FBCD0
void __fastcall D2Win_10060(D2WinTextBoxStrc* ptTextData, int nColumn, int a3)
{
    D2_ASSERT(ptTextData, 0x2FC);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x2FD);
    D2_ASSERT(nColumn >= 0, 0x2FF);
    ptTextData->unk0x7C[nColumn] = a3;
}







// 0x004FD970
int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinControlStrc* pTimer = (D2WinControlStrc*)pMsg->hWnd;
    D2_ASSERT(pTimer->eType == 8, 0x82);
    if (pMsg->uMessage == 0x102 || pMsg->wParam != 0x20)
        return 0;
    if (pTimer->field_34)
        pTimer->field_34(pMsg);
    return 1;
}















// 0x00504270
void __stdcall D2Win_10154(D2CompositeUnitStrc* hCompositeUnit, const Unicode* a2, const Unicode* a3, const Unicode* a4, const Unicode* a5, int a6, int a7)
{
    D2_ASSERT(hCompositeUnit, 0x8A8);
    sub_005267E0((Unicode*)hCompositeUnit->wszAccountName, a2);
    sub_005267E0((Unicode*)hCompositeUnit->wszCharName, a3);
    sub_005267E0((Unicode*)hCompositeUnit->wszGuildTag, a4);
    sub_005267E0((Unicode*)hCompositeUnit->wszRealmName, a5);
    hCompositeUnit->nCharLevel = a6;
    hCompositeUnit->dwProductCode = a7;
}

// 0x00504370
int __stdcall sub_00504370_LookupPairValue(int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs_0072EFD0; ++i)
    {
        if (nKey == gaCompPairs_0072EF68[i].nKey)
            return gaCompPairs_0072EF68[i].nValue;
    }
    return 0;
}

// 0x005043B0
void __stdcall sub_005043B0_ReleaseToPool(void* pMemory)
{
    FOG_FreePool(0, pMemory, ".\\Src\\D2Comp.cpp", 0x939, 0);
}

// 0x00504D30
void __stdcall D2Win_10159(D2CelFileStrc* pSquelchCelFile, D2CelFileStrc* pSelectedCelFile)
{
    ghSquelchCelFile_0087E844 = pSquelchCelFile;
    gnSquelchCelFileFrameCount_0087E848 = CelFileGetCelsPerDirection(pSquelchCelFile);
    ghSelectedCelFile_0087E850 = pSelectedCelFile;
    gnSelectedCelFileFrameCount_0087E854 = CelFileGetCelsPerDirection(pSelectedCelFile);
}

// 0x00505160
D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD4C);
    return ptUnit->pNext;
}

// 0x005051A0
void __stdcall D2Win_10149(D2CompositeUnitStrc* ptUnit, unsigned char nValue)
{
    D2_ASSERT(ptUnit, 0xD57);
    const int nLow = nValue > 0 ? nValue : 0;
    ptUnit->nDirection = nLow < ptUnit->nDirections ? (nValue > 0 ? nValue : 0) : ptUnit->nDirections;
}

// 0x00505200
unsigned char __stdcall D2Win_10150(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD61);
    return ptUnit->nDirections;
}

// 0x005052B0
void __stdcall D2Win_10152(D2CompositeUnitStrc* ptUnit, int nX)
{
    D2_ASSERT(ptUnit, 0xD81);
    ptUnit->nX = nX;
}

// 0x005052F0
void __stdcall D2Win_10153(D2CompositeUnitStrc* ptUnit, int nY)
{
    D2_ASSERT(ptUnit, 0xD8C);
    ptUnit->nY = nY;
}

// 0x00505330
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* hCompositeUnit)
{
    D2_ASSERT(hCompositeUnit, 0xD95);
    return hCompositeUnit->dwFlags;
}

#include "gen/data/Source/D2Win/Src/D2WinTextBox_004FBC80.inc"
