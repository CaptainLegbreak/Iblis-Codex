typedef unsigned short Unicode;

struct D2CelFileStrc;
struct SMSGHANDLER_PARAMS;

struct D2WinButtonStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    void* pfDraw;
    void* pfInitialize;
    void* pfHandleMouseDown;
    void* pfHandleMouseUp;
    void* pfHandleCharInput;
    void* pfHandleVirtualKeyInput;
    void* pfCallback;
    void* pfShouldMouseInputBeHandled;
    D2WinButtonStrc* pNext;
    unsigned int dwButtonFlags;
    int bIsPressed;
    int bIsCallbackPending;
    int nActivationCounter;
    int nVirtualKey;
    int nIsPressedFrameOffset;
    int nDisabledFrameOffset;
    int nBaseFrame;
    int eFont;
    Unicode wszText[256];
    int nTextColor;
    void* pfUpdateHoverState;
    int isButtonHovered;
    int nStringId;
};

#define D2WIN_BUTTON 6
#define BUTTONFLAG_HAS_DISABLED_FRAMES 0x20

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __stdcall CONTROL_AppendToList(D2WinButtonStrc* pControl);                                              // 0x004F9210
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton);                                                       // 0x00500DB0
int __stdcall BUTTON_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00501090
int __stdcall BUTTON_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                               // 0x00501150
int __stdcall BUTTON_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                       // 0x005011F0

// 0x00501290
D2WinButtonStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, void* pCallback, int nVirtualKey, int nBaseFrame, unsigned int dwButtonFlags, int nStringId, void* pUpdateHoverState)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)FOG_Alloc(sizeof(D2WinButtonStrc), ".\\Src\\D2WinButton.cpp", 36, 0);
    memset(pButton, 0, sizeof(D2WinButtonStrc));

    pButton->nType = D2WIN_BUTTON;
    pButton->dwFlags |= gdwBitMasks[0];
    pButton->dwFlags |= gdwBitMasks[2];
    pButton->pCellFile = pCellFile;
    pButton->nImageX = nX;
    pButton->nImageY = nY;
    pButton->nWidth = nWidth;
    pButton->nHeight = nHeight;
    pButton->pfDraw = (void*)BUTTON_Draw;
    pButton->pfHandleMouseDown = (void*)BUTTON_HandleMouseDown;
    pButton->pfHandleMouseUp = (void*)BUTTON_HandleMouseUp;
    pButton->pfHandleCharInput = 0;
    pButton->pfHandleVirtualKeyInput = nVirtualKey ? (void*)BUTTON_HandleVirtualKeyInput : 0;
    pButton->pfCallback = pCallback;
    pButton->pNext = 0;
    pButton->dwButtonFlags = dwButtonFlags;
    pButton->bIsPressed = 0;
    pButton->bIsCallbackPending = 0;
    pButton->nVirtualKey = nVirtualKey;
    pButton->nBaseFrame = nBaseFrame;

    if (nStringId)
    {
        sub_005267E0(pButton->wszText, D2LANG_GetStringFromTblIndex(nStringId));
    }

    struct { int nColumns; int nRows; } tCels;
    tCels.nColumns = (nWidth + 0xFF) >> 8;
    tCels.nRows = (nHeight + 0xFF) >> 8;
    pButton->nIsPressedFrameOffset = tCels.nRows * tCels.nColumns;
    pButton->nDisabledFrameOffset = (pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES) ? 2 * pButton->nIsPressedFrameOffset : 0;

    pButton->pfUpdateHoverState = pUpdateHoverState;
    pButton->isButtonHovered = 0;
    pButton->nStringId = 0;
    CONTROL_AppendToList(pButton);
    return pButton;
}
