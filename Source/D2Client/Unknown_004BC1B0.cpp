#include "D2Client.h"

struct D2ListBoxEntryStrc;
class UIWidget;
class SpinnerImplementation;
class SpinnerWrapper;
class ListBoxImplementation;
class ListBoxWrapper;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2ListBoxEntryStrc
{
    char unk0x0000[0x3006];
    char nData[4];
    char unk0x300A[4];
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class UIWidget
{
public:
    virtual ~UIWidget()
    {
    }

    static void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }
};

// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// build: symbol ??_GListBoxImplementation@@UAEPAXI@Z 0x004BF8C0
// build: symbol ??_GListBoxWrapper@@UAEPAXI@Z 0x004BED10
// build: symbol ??_GSpinnerImplementation@@UAEPAXI@Z 0x004BC450
// build: symbol ??_GSpinnerWrapper@@UAEPAXI@Z 0x004BC250
// 0x004BC450
class SpinnerImplementation : public UIWidget
{
public:
    SpinnerImplementation();
    virtual ~SpinnerImplementation();                                       // 0x004BBE10
};

// 0x004BC250
class SpinnerWrapper : public UIWidget
{
public:
    SpinnerWrapper();
    virtual ~SpinnerWrapper();                                              // 0x004BC1F0

    int unk0x04;
    UIWidget* pImpl;
};

// 0x004BF8C0
class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation();

    int sub_004BE770_HitTestBottomRow(SMSGHANDLER_PARAMS* pMsg);                                            // 0x004BE770
    int sub_004BE7C0_HitTestRows(SMSGHANDLER_PARAMS* pMsg);                                                 // 0x004BE7C0
    int sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg);                                                // 0x004BEA50
    int sub_004BEB70_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEC40_GetEntryData(int nIndex);                                                              // 0x004BEC40
    int sub_004BF430_MouseDownMsg(SMSGHANDLER_PARAMS* pMsg);

    int HitTestTopRowInline(SMSGHANDLER_PARAMS* pMsg)
    {
        const int nMouseX = pMsg->nXpos;
        const int nMouseY = pMsg->nYpos;
        if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10 && nMouseY > *(int*)nY - 12 && nMouseY < *(int*)nY)
        {
            return 1;
        }
        return 0;
    }

    D2ListBoxEntryStrc aEntries[0x80];
    char unk0x180704[4];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    char unk0x180718[4];
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    char unk0x18073C[0xC];
    unsigned short nEntryCount;
    char pfnCallback[4];
    char f_18074E[4];
    char unk0x180752[8];
    char nX[4];
    char nY[4];
    char f_180762[4];
    char unk0x180766[8];
    char nRepeatTicks[4];
    char nState[4];
};

// 0x004BED10
class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper();
    virtual ~ListBoxWrapper();                                              // 0x004BECC0

    int sub_004BEDF0_ForwardGetEntryData(int nIndex);

    int unk0x04;
    ListBoxImplementation* pImpl;
};

// 0x004BC1B0
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x004BE810
int ListBoxImplementation::sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > f_180708 && nMouseX < f_180708 + nRectWidth && nMouseY > f_18070C && nMouseY < f_18070C + nRectHeight)
    {
        return 1;
    }
    return 0;
}

// 0x004BEB70
int ListBoxImplementation::sub_004BEB70_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_004BE810_HitTestRect(pMsg))
    {
        sub_004BEA50_HitTestEntry(pMsg);
    }
    return 0;
}

// 0x004BEDF0
int ListBoxWrapper::sub_004BEDF0_ForwardGetEntryData(int nIndex)
{
    return pImpl->sub_004BEC40_GetEntryData(nIndex);
}

// 0x004BF430
int ListBoxImplementation::sub_004BF430_MouseDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_004BE810_HitTestRect(pMsg))
    {
        return 0;
    }

    f_18071C = 1;
    if (HitTestTopRowInline(pMsg) == 1)
    {
        bTopPressed = 1;
        *(int*)nRepeatTicks = 0;
        return 1;
    }

    if (sub_004BE770_HitTestBottomRow(pMsg) == 1)
    {
        bBottomPressed = 1;
        *(int*)nRepeatTicks = 0;
        return 1;
    }

    if (sub_004BE7C0_HitTestRows(pMsg) == 1)
    {
        nPressY = pMsg->nYpos;
        bRowsPressed = 1;
        return 1;
    }

    if (*(int*)pfnCallback)
    {
        nCallbackRow = sub_004BEA50_HitTestEntry(pMsg);
    }
    return 1;
}

SpinnerImplementation::SpinnerImplementation()
{
}

SpinnerWrapper::SpinnerWrapper()
{
    pImpl = 0;
}

ListBoxImplementation::ListBoxImplementation()
{
    nEntryCount = 0;
}

ListBoxWrapper::ListBoxWrapper()
{
    pImpl = 0;
}
