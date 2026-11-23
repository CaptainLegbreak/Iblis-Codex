#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

struct Unicode;
struct D2ButtonStringStrc;
class UIWidget;
class ButtonImplementation;
class EditBoxImplementation;
class ButtonWrapper;
class EditBoxWrapper;
class SpinnerImplementation;
class D2InterfaceStrc;
class D2WrapperStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int Slot11() = 0;

    void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }

    int unk0x04;
};

// build: symbol ??1ButtonWrapper@@UAE@XZ 0x004BADD0
// build: symbol ??1EditBoxImplementation@@UAE@XZ 0x004BB170
// build: symbol ??1EditBoxWrapper@@UAE@XZ 0x004BB9F0
// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonImplementation@@6B@ 0x006DA6F4
// build: symbol ??_GButtonImplementation@@UAEPAXI@Z 0x004BAFD0
// build: symbol ??_GButtonWrapper@@UAEPAXI@Z 0x004BAE30
// build: symbol ??_GEditBoxImplementation@@UAEPAXI@Z 0x004BBD50
// build: symbol ??_GEditBoxWrapper@@UAEPAXI@Z 0x004BBA50
// 0x004BAFD0
class ButtonImplementation : public UIWidget
{
public:
    virtual ~ButtonImplementation();
    virtual void Slot01();
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot11();
    virtual void sub_004BAC60_SetUnk24(int nValue);

    int HitTestButton(SMSGHANDLER_PARAMS* pMsg);

    int nX;
    int nY;
    char unk0x10[0x08];
    int nHeight;
    int nWidth;
    int f_20;
    int unk0x24;
    int (__cdecl* pfnCallback)();
    int unk0x2C;
    unsigned short nBaseFrame;
    unsigned char nStringSlot[4];
};

// 0x004BBD50
class EditBoxImplementation : public UIWidget
{
public:
    EditBoxImplementation();
    virtual ~EditBoxImplementation();
    virtual void sub_004BB5B0_Slot12(char* szBuffer);

    char unk0x08[0x20];
    Unicode* pText;
    char unk0x2C[8];
    unsigned short nMaxLength;
};

// 0x004BAE30
class ButtonWrapper : public UIWidget
{
public:
    ButtonWrapper();
    virtual ~ButtonWrapper();

    ButtonImplementation* pImpl;
};

// 0x004BBA50
class EditBoxWrapper : public UIWidget
{
public:
    EditBoxWrapper();
    virtual ~EditBoxWrapper();

    EditBoxImplementation* pImpl;
};

#pragma pack(push, 2)

class SpinnerImplementation : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);

    int HitTestUpArrow(SMSGHANDLER_PARAMS* pMsg);
    int HitTestDownArrow(SMSGHANDLER_PARAMS* pMsg);

    int nX;
    int nY;
    int nUpX;
    int nUpY;
    int nDownX;
    int nDownY;
    int unk0x20;
    int nArrowHeight;
    int nArrowWidth;
    int f_2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
extern D2ButtonStringStrc gaButtonStrings[]; // 0x007275A8

class D2InterfaceStrc
{
public:
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16(int nArg) = 0;
};

class D2WrapperStrc
{
public:
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void sub_004BBB80_Forward(int nArg);
    int unk0x04;
    D2InterfaceStrc* pImplementation;
};

// 0x004BAC00
int ButtonImplementation::HitTestButton(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX < nX || nMouseX > nX + nWidth || nMouseY < nY - nHeight || nMouseY > nY)
    {
        return 0;
    }
    return 1;
}

// 0x004BAC70
int ButtonImplementation::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    if (HitTestButton(pMsg))
    {
        f_20 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

// 0x004BACD0
int ButtonImplementation::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    if (!f_20)
    {
        return 0;
    }
    if (HitTestButton(pMsg))
    {
        f_20 = 0;
        return pfnCallback();
    }
    unk0x2C = 0;
    f_20 = 0;
    return 0;
}

ButtonImplementation::~ButtonImplementation()
{
}

// 0x004BB000
void ButtonImplementation::Slot01()
{
    D2CelContextStrc tCelContext;
    memset(&tCelContext, 0, sizeof(tCelContext));
    tCelContext.pCellFile = sub_00454600();
    tCelContext.nFrame = f_20 + nBaseFrame;
    tCelContext.nDirection = 0;
    sub_004F6480(&tCelContext, nX, nY, -1, 5, 0);

    const int nMouseX = sub_00468730();
    const unsigned int dwMousePos = ((unsigned short)sub_00468740() << 16) | (unsigned short)nMouseX;
    const int nPosX = (unsigned short)dwMousePos;
    const int nPosY = dwMousePos >> 16;
    if (nPosX >= nX && nPosX <= nX + nWidth && nPosY >= nY - nHeight && nPosY <= nY)
    {
        const int nOldFont = sub_00502EF0(1);
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaButtonStrings[*(int*)nStringSlot].nStringIndex);
        const int nTextWidth = D2Win_10121_GetTextWidth(wszText);
        D2Win_10117_DrawText(wszText, nX + (nWidth - nTextWidth) / 2, nY - nHeight - 5, 0, 0);
        sub_00502EF0(nOldFont);
    }
}

// 0x004BB5B0
void EditBoxImplementation::sub_004BB5B0_Slot12(char* szBuffer)
{
    sub_005263E0(szBuffer, pText, nMaxLength);
}

// 0x004BBEF0
int SpinnerImplementation::HitTestUpArrow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX <= nUpX || nMouseX >= nUpX + nArrowWidth || nMouseY <= nUpY - nArrowHeight || nMouseY > nUpY)
    {
        return 0;
    }
    return 1;
}

// 0x004BBF40
int SpinnerImplementation::HitTestDownArrow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX <= nDownX || nMouseX >= nDownX + nArrowWidth || nMouseY <= nDownY - nArrowHeight || nMouseY >= nDownY)
    {
        return 0;
    }
    return 1;
}

ButtonWrapper::ButtonWrapper()
{
    pImpl = 0;
}

EditBoxWrapper::EditBoxWrapper()
{
    pImpl = 0;
}

EditBoxImplementation::EditBoxImplementation()
{
    pText = 0;
}

// 0x004BB5F0
int __stdcall SKILLS_Return0(int nUnused)
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

// 0x004BBB80
void D2WrapperStrc::sub_004BBB80_Forward(int nArg)
{
    pImplementation->slot16(nArg);
}
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

// 0x004BC050
int SpinnerImplementation::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    if ((short)pMsg->wParamHigh > 0)
    {
        unk0x34 = 1;
        unk0x38 = 0;
        unk0x20 = 1;
    }
    else if ((short)pMsg->wParamHigh < 0)
    {
        unk0x34 = 0;
        unk0x38 = 1;
        unk0x20 = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    return 1;
}
// 0x004BC190
int SpinnerImplementation::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}


