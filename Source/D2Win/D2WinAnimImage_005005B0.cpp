#include "D2Win.h"

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

struct D2AnimatedImageDescriptor
{
    D2CelFileStrc** ppCellFile1;
    D2CelFileStrc** ppCellFile2;
    int eDrawMode;
    int nAnimSpeed;
};

struct D2WinAnimImageStrc
{
    D2WinControlStrc controlHeader;
    D2AnimatedImageDescriptor* pAnimatedImageDescriptor;
    int nAnimSpeed;
    unsigned long dwStartTickCount;
    int nFrame;
    int nAnimType;
    int eDrawMode;
    D2WinMsgHandler field_58;
    int bIsRunning;
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
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __fastcall ANIMIMAGE_ShouldMouseInputBeHandled(D2WinControlStrc* pControl);                             // 0x005003A0
int __stdcall sub_006019F0(D2CelFileStrc* pCelFile);                                                // 0x006019F0
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

static int sub_00500480_AnimImageUpdateState(D2WinAnimImageStrc* pAnimImage)
{
    D2_ASSERT(pAnimImage->controlHeader.nType == 2, 0x9A);

    if (!pAnimImage->pAnimatedImageDescriptor)
        return 0;

    int nAnimType = pAnimImage->nAnimType;
    if (nAnimType == 0 || nAnimType == 1)
    {
        const int nNewAnimType = ANIMIMAGE_ShouldMouseInputBeHandled(&pAnimImage->controlHeader) != 0;
        pAnimImage->nAnimType = nNewAnimType;
        if (nAnimType != nNewAnimType)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pAnimImage;
            msg.lParam = nNewAnimType == 1;
            if (pAnimImage->field_58)
                pAnimImage->field_58(&msg);
        }
    }

    int nMaxFrames = 1;
    D2CelFileStrc** ppCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
    if (ppCellFile && *ppCellFile)
        nMaxFrames = sub_006019F0(*ppCellFile);

    nAnimType = pAnimImage->nAnimType;
    switch (nAnimType)
    {
    case 4:
        if (pAnimImage->nFrame >= nMaxFrames - 2)
        {
            pAnimImage->nAnimType = 1;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        break;
    case 2:
        if (pAnimImage->nFrame >= nMaxFrames - 2)
        {
            pAnimImage->nAnimType = 3;
            pAnimImage->nFrame = 0;
            pAnimImage->dwStartTickCount = GetTickCount();
        }
        break;
    }

    if (nAnimType != pAnimImage->nAnimType)
    {
        D2CelFileStrc** ppNewCellFile = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
        if (ppNewCellFile && *ppNewCellFile)
            sub_006019F0(*ppNewCellFile);
    }

    if (pAnimImage->nFrame > nMaxFrames)
    {
        pAnimImage->nFrame = 0;
        pAnimImage->dwStartTickCount = GetTickCount();
    }

    return 1;
}

// 0x005005B0
int __fastcall ANIMIMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinAnimImageStrc* pAnimImage = (D2WinAnimImageStrc*)pControl;
    D2_ASSERT(pAnimImage->controlHeader.nType == 2, 0xF9);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;

    if (!pAnimImage->controlHeader.pCellFile && !pAnimImage->pAnimatedImageDescriptor)
        return 1;

    int nX = pAnimImage->controlHeader.nImageX;
    int nY = pAnimImage->controlHeader.nImageY;
    sub_00500480_AnimImageUpdateState(pAnimImage);

    D2CelFileStrc* pCellFile1 = 0;
    D2CelFileStrc* pCellFile2 = 0;
    int nAnimDrawMode;
    int nDrawMode;
    int nFrameCount;
    int nAnimSpeed;
    if (pAnimImage->pAnimatedImageDescriptor)
    {
        D2CelFileStrc** ppCellFile1 = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile1;
        D2CelFileStrc** ppCellFile2 = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].ppCellFile2;
        if (ppCellFile1)
            pCellFile1 = *ppCellFile1;
        if (ppCellFile2)
            pCellFile2 = *ppCellFile2;
        nDrawMode = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].eDrawMode;
        nAnimDrawMode = pAnimImage->eDrawMode;
        nFrameCount = sub_006019F0(pCellFile1);
        nAnimSpeed = pAnimImage->pAnimatedImageDescriptor[pAnimImage->nAnimType].nAnimSpeed;
    }
    else
    {
        pCellFile1 = pAnimImage->controlHeader.pCellFile;
        pCellFile2 = 0;
        nAnimDrawMode = pAnimImage->eDrawMode;
        nDrawMode = nAnimDrawMode;
        nFrameCount = sub_006019F0(pCellFile1);
        nAnimSpeed = pAnimImage->nAnimSpeed;
        tContext.pCellFile = pCellFile1;
        tContext.unk0x40 = 0;
        tContext.nFrame = 0;
        D2CelStrc* pCel = D2CMP_CelGetHandle(&tContext);
        nY -= sub_00601950(pCel);
        nX -= sub_00601920(pCel);
    }

    if (pCellFile1)
    {
        tContext.pCellFile = pCellFile1;
        tContext.nFrame = pAnimImage->nFrame;
        sub_004F6480(&tContext, nX, nY, -1, nAnimDrawMode, 0);
    }

    if (pCellFile2)
    {
        tContext.pCellFile = pCellFile2;
        tContext.nFrame = pAnimImage->nFrame;
        sub_004F6480(&tContext, nX, nY, -1, nDrawMode, 0);
    }

    if (nAnimSpeed && nFrameCount > 1 && pAnimImage->bIsRunning)
    {
        const int nFrameDivisor = 1000 * nAnimSpeed / 25;
        switch (pAnimImage->nAnimType)
        {
        case 2:
        case 4:
            pAnimImage->nFrame = (GetTickCount() - pAnimImage->dwStartTickCount) / nFrameDivisor;
            pAnimImage->nFrame = pAnimImage->nFrame < nFrameCount - 1 ? pAnimImage->nFrame : nFrameCount - 1;
            break;
        default:
            pAnimImage->nFrame = (GetTickCount() - pAnimImage->dwStartTickCount) / nFrameDivisor % (nFrameCount - 1);
            break;
        }
    }

    return 1;
}
