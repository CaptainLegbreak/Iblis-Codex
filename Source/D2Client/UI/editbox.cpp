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

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

// build: symbol ??1ButtonWrapper@@UAE@XZ 0x004BADD0
// build: symbol ??1EditBoxImplementation@@UAE@XZ 0x004BB170
// build: symbol ??1EditBoxWrapper@@UAE@XZ 0x004BB9F0
// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonImplementation@@6B@ 0x006DA6F4
// build: symbol ??_GButtonImplementation@@UAEPAXI@Z 0x004BAFD0
// build: symbol ??_GButtonWrapper@@UAEPAXI@Z 0x004BAE30
// build: symbol ??_GEditBoxImplementation@@UAEPAXI@Z 0x004BBD50
// build: symbol ??_GEditBoxWrapper@@UAEPAXI@Z 0x004BBA50

#pragma pack(push, 2)

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
// build: symbol ?gszNew@* 0x006CC82C
        return SMemAlloc(nSize, gszNew, -1, 0);
    }

    static void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }

    virtual ~UIWidget() = 0;
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

    int unk0x04;
};

// 0x004BAFD0
class ButtonImplementation : public UIWidget
{
public:
    ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)());
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
    int unk0x10[2];
    int nHeight;
    int nWidth;
    int f_20;
    int unk0x24;
    int (__cdecl* pfnCallback)();
    int unk0x2C;
    unsigned short nBaseFrame;
    int nStringSlot;
};

// 0x004BAE30
class ButtonWrapper : public UIWidget
{
public:
    ButtonWrapper(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)());
    ButtonWrapper();
    virtual ~ButtonWrapper();
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
    virtual void sub_004BAF10_SetUnk24(int nValue);

    ButtonImplementation* pImpl;
};

// 0x004BBD50
class EditBoxImplementation : public UIWidget
{
public:
    EditBoxImplementation(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength, int nArg18,
        int nFont);
    EditBoxImplementation();
    virtual ~EditBoxImplementation();
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
    virtual void sub_004BB5B0_Slot12(char* szBuffer);
    virtual void Slot13();
    virtual void sub_004BB530_Slot14(const char* szText);
    virtual void sub_004BB4D0_Slot15(int nValue);
    virtual void sub_004BB990_SetUnk18(int nValue);
    virtual void sub_004BB9A0_SetUnk24(int nValue);
    virtual void sub_004BB200_SetUnk20(int nValue);

    void sub_004BB980_SetUnk04(int nValue);

    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    Unicode* pTextCopy;
    int nMaxValue;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    unsigned int unk0x46;
    int unk0x4A;
    int nFont;
    void* pCellFile;
    int unk0x56;
};

// 0x004BBA50
class EditBoxWrapper : public UIWidget
{
public:
    EditBoxWrapper(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength, int nArg18,
        int nFont);
    EditBoxWrapper();
    virtual ~EditBoxWrapper();
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
    virtual void sub_004BBB30_Slot12(int nValue);
    virtual void sub_004BBB50_Slot13(const char* szText);
    virtual void sub_004BBB40_Slot14(int nValue);
    virtual void sub_004BBB60_Slot15(char* szBuffer);
    virtual void sub_004BBB80_Forward(int nArg);
    virtual void sub_004BBB90_SetUnk24(int nValue);
    virtual void sub_004BBBA0_SetUnk20(int nValue);

    void sub_004BBB70_SetUnk04(int nValue);

    EditBoxImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    SpinnerImplementation(int nX, int nY, int bHorizontal, int nArg0C);                                     // 0x004BC340
    virtual ~SpinnerImplementation();
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
    virtual int sub_004BBFB0();

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
    void (__cdecl* pfUnk0x3C)();
    unsigned int nUnk0x3CCalls;
    unsigned int unk0x44;
    unsigned int unk0x48;
    int unk0x4C;
    void* pCellFile;
};

class SpinnerWrapper : public UIWidget
{
public:
    SpinnerWrapper(int nX, int nY, int bHorizontal, int nArg0C);
    virtual ~SpinnerWrapper();
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
    virtual int sub_004BC330_ForwardSlot30(int nArg);

    SpinnerImplementation* pImpl;
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

// build: symbol ?MsgSlot03@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAC70
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

// build: symbol ?MsgSlot04@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BACD0
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

// build: symbol ?Slot01@ButtonImplementation@@UAEXXZ 0x004BB000
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
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaButtonStrings[nStringSlot].nStringIndex);
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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

// build: symbol ?MsgSlot03@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB5E0
// 0x004BB5E0
int EditBoxImplementation::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    unk0x3E = 1;
    return 0;
}

// build: symbol ?MsgSlot04@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB600
// 0x004BB600
int EditBoxImplementation::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x3E)
    {
        unk0x46 = 0;
        unk0x3E = 0;
    }
    return 0;
}

// 0x004BB970
int EditBoxImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BB9B0
int EditBoxImplementation::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 < unk0x3A)
        unk0x36 += 1;
    return 1;
}

// 0x004BB9D0
int EditBoxImplementation::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 > 0)
        unk0x36 -= 1;
    return 1;
}

// build: symbol ?Slot01@EditBoxWrapper@@UAEXXZ 0x004BBAC0
// 0x004BBAC0
void EditBoxWrapper::Slot01()
{
    pImpl->Slot01();
}

// build: symbol ?Slot11@EditBoxWrapper@@UAEHXZ 0x004BBB20
int EditBoxWrapper::Slot11()
{
    return pImpl->Slot11();
}

// 0x004BBB30
void EditBoxWrapper::sub_004BBB30_Slot12(int nValue)
{
    pImpl->Slot13();
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

// build: symbol ?MsgSlot02@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB5F0
// 0x004BB5F0
int EditBoxImplementation::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
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
void EditBoxWrapper::sub_004BBB80_Forward(int nArg)
{
    pImpl->sub_004BB990_SetUnk18(nArg);
}
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

// build: symbol ?Slot11@SpinnerImplementation@@UAEHXZ 0x004BBF90
int SpinnerImplementation::Slot11()
{
    if (unk0x34)
        return 1;
    return unk0x38 ? 2 : 0;
}

// 0x004BBFB0
int SpinnerImplementation::sub_004BBFB0()
{
    if (!unk0x34 && !unk0x38)
        return 0;

    if (unk0x20)
    {
        unk0x34 = 0;
        unk0x38 = 0;
        unk0x20 = 0;
        return 1;
    }

    unsigned long dwNow = GetTickCount();
    if (unk0x4C)
    {
        unk0x48 = dwNow;
        return 1;
    }

    unsigned long dwElapsed = dwNow - unk0x44;
    if (dwNow - unk0x48 < 0x46)
        return 0;

    unk0x48 = dwNow;
    if (dwElapsed > 0x1000)
        return (dwElapsed >> 11) * nUnk0x3CCalls;
    if (dwElapsed > 0xBB8)
        return nUnk0x3CCalls >> 2;
    if (dwElapsed > 0x7D0)
        return nUnk0x3CCalls >> 4;
    if (dwElapsed > 0x3E8)
        return nUnk0x3CCalls >> 5;
    return 1;
}

// build: symbol ?MsgSlot02@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC050
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


