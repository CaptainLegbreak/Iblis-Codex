struct D2CelFileStrc;
struct D2WinControlStrc;
struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};
typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS*);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc*);
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
struct D2WinTextBoxStrc;
struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader;
    int bIsUpperArrowPressed;
    int bIsLowerArrowPressed;
    int nMaxSteps;
    int nCurrentStep;
    int field_50;
    D2WinTextBoxStrc* pTextBox;
    int bIsStepIndicatorDragged;
    D2WinMsgHandler field_5C;
};
struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size); // 0x00681EF0
int __cdecl sub_004FA460(); // 0x004FA460
int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00508120
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern unsigned int gdwBitMasks[]; // 0x006CE268
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00508370
int __fastcall SCROLLBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pControl;
    D2_ASSERT(pScrollBar, 0xE7);
    D2_ASSERT(pScrollBar->controlHeader.nType == 5, 0xE8);
    if (!(pScrollBar->controlHeader.dwFlags & gdwBitMasks[2]) ||
        !(pScrollBar->controlHeader.dwFlags & gdwBitMasks[0]))
        return 0;

    D2CelFileStrc* pCellFile = pScrollBar->controlHeader.pCellFile;
    int nX = pScrollBar->controlHeader.nImageX;
    int nY = pScrollBar->controlHeader.nImageY - 1;
    if (pScrollBar->nMaxSteps)
    {
        if (!sub_004FA460())
            pScrollBar->bIsStepIndicatorDragged = 0;
        if (pScrollBar->bIsStepIndicatorDragged)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pScrollBar;
            msg.uMessage = 0x201;
            SCROLLBAR_HandleMouseDown(&msg);
        }

        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.pCellFile = pCellFile;
        context.unk0x40 = 0;
        context.nFrame = pScrollBar->bIsLowerArrowPressed ? 3 : 1;
        sub_004F6480(&context, nX, nY, -1, 5, 0);
        context.nFrame = 5;
        if (pScrollBar->controlHeader.nHeight - 10 > 10)
        {
            int nOffset = 10;
            do
            {
                nOffset += 10;
                nY -= 10;
                sub_004F6480(&context, nX, nY, -1, 5, 0);
            } while (nOffset < pScrollBar->controlHeader.nHeight - 10);
        }
        context.nFrame = pScrollBar->bIsUpperArrowPressed != 0 ? 2 : 0;
        sub_004F6480(&context, nX,
            pScrollBar->controlHeader.nImageY - pScrollBar->controlHeader.nHeight + 9,
            -1, 5, 0);
        context.nFrame = 4;
        sub_004F6480(&context, nX,
            (pScrollBar->controlHeader.nHeight - 30) * pScrollBar->nCurrentStep / pScrollBar->nMaxSteps
                - pScrollBar->controlHeader.nHeight + pScrollBar->controlHeader.nImageY + 19,
            -1, 5, 0);
    }
    return 1;
}
