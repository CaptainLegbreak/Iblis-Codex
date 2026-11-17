#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WinControlStrc;
struct Unicode;
struct D2WinAnimImageStrc;
struct D2WinButtonStrc;

typedef int (__stdcall* D2WinMsgHandler)(struct SMSGHANDLER_PARAMS* pMsg);

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

struct D2WinAnimImageStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    union
    {
        int field_48;
        unsigned long dwStartTickCount;
    };
    union
    {
        int field_4C;
        unsigned int nFrame;
    };
    int field_50;
};

struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
};

struct D2WinButtonStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
};

typedef char check_control_header_size[(sizeof(D2WinControlStrc) == 0x40) ? 1 : -1];

typedef char check_animimage_field_50[(sizeof(D2WinAnimImageStrc) == 0x54) ? 1 : -1];

typedef char check_scrollbar_field_50[(sizeof(D2WinScrollBarStrc) == 0x54) ? 1 : -1];

typedef char check_button_field_5C[(sizeof(D2WinButtonStrc) == 0x60) ? 1 : -1];

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
    D2WIN_TYPE_5 = 5,
    D2WIN_TYPE_6 = 6,
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

// 0x00500310
extern "C" int __fastcall sub_00500310_GetAnimImageField50(D2WinAnimImageStrc* pAnimImage)
{
    D2_ASSERT(pAnimImage->controlHeader.nType == D2WIN_IMAGE, 0x50);
    return pAnimImage->field_50;
}

// 0x00507EF0
extern "C" int __fastcall sub_00507EF0_GetScrollBarField48(D2WinScrollBarStrc* pScrollBar)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_TYPE_5, 0x4B);
    return pScrollBar->field_48;
}

// 0x00507FA0
extern "C" int __fastcall sub_00507FA0_GetScrollBarField4C(D2WinScrollBarStrc* pScrollBar)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_TYPE_5, 0x74);
    return pScrollBar->field_4C;
}

// 0x005009A0
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* pButton, int bIsPressed)
{
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_TYPE_6, 0x72);
    pButton->field_44 = bIsPressed;
    pButton->field_48 = bIsPressed;
}

// 0x00500B20
extern "C" void __fastcall sub_00500B20_SetButtonField5C(D2WinButtonStrc* pButton, int nValue)
{
    D2_ASSERT(pButton->controlHeader.nType == D2WIN_TYPE_6, 0xD6);
    pButton->field_5C = nValue;
}

// 0x005080C0
extern "C" void __fastcall sub_005080C0_SetScrollBarField50(D2WinScrollBarStrc* pScrollBar, int nValue)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_TYPE_5, 0xCA);
    pScrollBar->field_50 = nValue;
}

// 0x00500340
int __fastcall D2Win_10104(D2WinAnimImageStrc* pAnimImage)
{
    D2_ASSERT(pAnimImage->controlHeader.nType == 2, 92);

    if (pAnimImage->field_50 == 3)
    {
        pAnimImage->field_50 = 4;
        pAnimImage->nFrame = 0;
        pAnimImage->dwStartTickCount = GetTickCount();
    }
    else if (pAnimImage->field_50 == 2 || pAnimImage->field_50 == 4)
    {
        return 0;
    }

    return 1;
}
