#pragma once
// D2Win: the window control types built on the control header (text boxes and their lines, edit boxes, buttons,
// account lists, scroll bars, lists, images, animated images, movies).

#include "D2Check.h"
#include "D2Structs.h"
#include "D2WinTypes.h"

struct Unicode;
struct D2WinScrollBarStrc;
struct D2WinAccountListDataStrc;
struct D2WinTextBoxLineStrc;
struct D2WinTextBoxStrc;
struct D2WinEditBoxStrc;
struct D2WinButtonStrc;
struct D2WinAccountListStrc;
struct D2WinListDataStrc;
struct D2WinListStrc;
struct D2WinImageClickRectStrc;
struct D2WinImageStrc;
struct D2AnimatedImageDescriptor;
struct D2WinAnimImageStrc;
struct D2WinSmackStrc;

struct D2WinTextBoxLineStrc
{
    Unicode* pColumns[5]; // 0x00
    int unk0x14; // 0x14
    char unk0x18; // 0x18
    char unk0x19; // 0x19
    char unk0x1A; // 0x1A
    char unk0x1B; // 0x1B
    D2WinTextBoxLineStrc* pNext; // 0x1C
};

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader; // 0x00
    int unk0x40; // 0x40
    int unk0x44; // 0x44
    D2WinTextBoxLineStrc* pFirstLine; // 0x48
    D2WinTextBoxLineStrc* pLastLine; // 0x4C
    D2WinTextBoxLineStrc* pCurrentLine; // 0x50
    int nNumLines; // 0x54
    int nLine; // 0x58
    unsigned int dwTextBoxFlags; // 0x5C
    int nCurrentLine; // 0x60
    int nNumColumns; // 0x64
    int unk0x68[5]; // 0x68
    int unk0x7C[5]; // 0x7C
    D2WinScrollBarStrc* pScrollBar; // 0x90
    int eFont; // 0x94
    int unk0x98; // 0x98
    int unk0x9C; // 0x9C
    int unk0xA0; // 0xA0
    int unk0xA4; // 0xA4
    int unk0xA8; // 0xA8
};

struct D2WinEditBoxStrc
{
    D2WinControlStrc controlHeader; // 0x00
    int nTextInsetX; // 0x40
    int nTextInsetY; // 0x44
    int nMaxLength; // 0x48
    int nFirstVisibleChar; // 0x4C
    int nLastVisibleChar; // 0x50
    int nSelectionStart; // 0x54
    int nSelectionEnd; // 0x58
    unsigned short wszText[256]; // 0x5C
    int nCaretPosition; // 0x25C
    unsigned int dwEditBoxFlags; // 0x260
    void* pfOnEnter; // 0x264
    void* pfFilter; // 0x268
    void* pfOnChange; // 0x26C
    int eFont; // 0x270
    int nTextColor; // 0x274
    D2WinEditBoxStrc* pNext; // 0x278
    D2WinEditBoxStrc* pPrevious; // 0x27C
    int bMouseSelecting; // 0x280
};

struct D2WinButtonStrc
{
    D2WinControlStrc controlHeader; // 0x00
    unsigned int dwButtonFlags; // 0x40
    int bIsPressed; // 0x44
    int bIsCallbackPending; // 0x48
    int nActivationCounter; // 0x4C
    int nActivationVirtualKey; // 0x50
    int nIsPressedFrameOffset; // 0x54
    int nDisabledFrameOffset; // 0x58
    int nBaseFrame; // 0x5C
    int eFont; // 0x60
    unsigned short wszText[256]; // 0x64
    int nTextColor; // 0x264
    D2WinMsgHandler pfUpdateHoverState; // 0x268
    int isButtonHovered; // 0x26C
    int nStringId; // 0x270
};

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader; // 0x00
    D2WinAccountListDataStrc* pDataList; // 0x40
    D2WinAccountListDataStrc* pSelectedDataEntry; // 0x44
    int nFirstDrawnEntry; // 0x48
    int unk0x4C; // 0x4C
    int eFont; // 0x50
    int unk0x54; // 0x54
};

struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader; // 0x00
    int bIsUpperArrowPressed; // 0x40
    int bIsLowerArrowPressed; // 0x44
    int nMaxSteps; // 0x48
    int nCurrentStep; // 0x4C
    int nPageStep; // 0x50
    D2WinTextBoxStrc* pTextBox; // 0x54
    int bIsStepIndicatorDragged; // 0x58
    D2WinMsgHandler field_5C; // 0x5C
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader; // 0x00
    int eFont; // 0x40
    int field_44; // 0x44
    int field_48; // 0x48
    int field_4C; // 0x4C
    int field_50; // 0x50
    int field_54; // 0x54
    int field_58; // 0x58
    int field_5C; // 0x5C
    int nWidestEntry; // 0x60
    D2WinListDataStrc* pDataList; // 0x64
    D2WinListDataStrc* pSelectedDataEntry; // 0x68
};

struct D2WinImageStrc
{
    D2WinControlStrc controlHeader; // 0x00
    int nFrame; // 0x40
    int eDrawMode; // 0x44
    D2WinImageClickRectStrc* pClickRect; // 0x48
    int field_4C; // 0x4C
    int field_50; // 0x50
};

struct D2WinAnimImageStrc
{
    D2WinControlStrc controlHeader; // 0x00
    D2AnimatedImageDescriptor* pAnimatedImageDescriptor; // 0x40
    int nAnimSpeed; // 0x44
    unsigned long dwStartTickCount; // 0x48
    int nFrame; // 0x4C
    int nAnimType; // 0x50
    int eDrawMode; // 0x54
    D2WinMsgHandler field_58; // 0x58
    int bIsRunning; // 0x5C
};

struct D2WinSmackStrc
{
    D2WinControlStrc controlHeader; // 0x00
    char szFileName[256]; // 0x40
    int field_140; // 0x140
    int field_144; // 0x144
    int nMovieX; // 0x148
    int nMovieY; // 0x14C
};

D2_CHECK_SIZE(D2WinTextBoxLineStrc, 0x20);
D2_CHECK_SIZE(D2WinTextBoxStrc, 0xAC);
D2_CHECK_SIZE(D2WinEditBoxStrc, 0x284);
D2_CHECK_SIZE(D2WinButtonStrc, 0x274);
D2_CHECK_SIZE(D2WinAccountListStrc, 0x58);
D2_CHECK_SIZE(D2WinScrollBarStrc, 0x60);
D2_CHECK_SIZE(D2WinListStrc, 0x6C);
D2_CHECK_SIZE(D2WinImageStrc, 0x54);
D2_CHECK_SIZE(D2WinAnimImageStrc, 0x60);
D2_CHECK_SIZE(D2WinSmackStrc, 0x150);
