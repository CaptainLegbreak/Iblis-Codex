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

// build: symbol ??3UIWidget@@SAXPAX@Z 0x004053F0

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

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

struct D2MouseMessageStrc
{
    char unk_00[0xC];
    unsigned short nX;
    unsigned short nY;
};

struct D2ButtonPairStrc
{
    char unk_00[0x10];
    int nFirstX;
    int nFirstY;
    int nSecondX;
    int nSecondY;
    int unk_20;
    int nHeight;
    int nWidth;
    int unk_2C;
    int f_30;
    int bFirst;
    int bSecond;
    void (__cdecl* pCallback)();
    int unk_40;
    unsigned long nTick;
    int unk_48;
    int bInvoking;
};

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                   // 0x00478A00

struct SMSGHANDLER_PARAMS;

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonWrapper@@6B@ 0x006DA72C
// build: symbol ??_7EditBoxImplementation@@6B@ 0x006DA77C
// build: symbol ??_7EditBoxWrapper@@6B@ 0x006DA7CC
// build: symbol ??_7SpinnerImplementation@@6B@ 0x006DA83C
// build: symbol ??_7SpinnerWrapper@@6B@ 0x006DA874
// 0x004BADD0
ButtonWrapper::~ButtonWrapper()
{
    delete pImpl;
}

// build: symbol ?MsgSlot02@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE60
// 0x004BAE60
int ButtonWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}

// build: symbol ?MsgSlot03@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE70
// 0x004BAE70
int ButtonWrapper::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot03(pMsg);
}

// build: symbol ?MsgSlot04@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE80
// 0x004BAE80
int ButtonWrapper::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot04(pMsg);
}

// build: symbol ?MsgSlot05@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE90
// 0x004BAE90
int ButtonWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// build: symbol ?Slot01@ButtonWrapper@@UAEXXZ 0x004BAEA0
// 0x004BAEA0
void ButtonWrapper::Slot01()
{
    pImpl->Slot01();
}

// build: symbol ?MsgSlot06@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEB0
// 0x004BAEB0
int ButtonWrapper::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot06(pMsg);
}

// build: symbol ?MsgSlot08@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEC0
// 0x004BAEC0
int ButtonWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAED0
// 0x004BAED0
int ButtonWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?MsgSlot09@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEE0
// 0x004BAEE0
int ButtonWrapper::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot09(pMsg);
}

// build: symbol ?MsgSlot10@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEF0
// 0x004BAEF0
int ButtonWrapper::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot10(pMsg);
}

// build: symbol ?Slot11@ButtonWrapper@@UAEHXZ 0x004BAF00
// 0x004BAF00
int ButtonWrapper::Slot11()
{
    return pImpl->Slot11();
}

// 0x004BAF10
void ButtonWrapper::sub_004BAF10_SetUnk24(int nValue)
{
    pImpl->sub_004BAC60_SetUnk24(nValue);
}

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonImplementation@@6B@ 0x006DA6F4
// build: symbol ??_7ButtonWrapper@@6B@ 0x006DA72C
// build: symbol ??_7EditBoxImplementation@@6B@ 0x006DA77C
// build: symbol ??_7EditBoxWrapper@@6B@ 0x006DA7CC
// build: symbol ??_7SpinnerWrapper@@6B@ 0x006DA874
// 0x004BAF20
ButtonImplementation::ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    nBaseFrame = gaButtonStrings[nStringSlot].nCelFrame;
    this->nStringSlot = nStringSlot;
    this->pfnCallback = pfnCallback;
    f_20 = 0;
    unk0x2C = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nDirection = 0;
    tContext.nFrame = nBaseFrame;
    D2CelStrc* pCel = CelGetHandle(&tContext);
    this->nX = nX;
    this->nY = nY;
    unk0x24 = 0;
    nHeight = CelGetHeight(pCel);
    nWidth = CelGetWidth(pCel);
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

// 0x004BB0F0
ButtonWrapper::ButtonWrapper(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    pImpl = new ButtonImplementation(nX, nY, nStringSlot, pfnCallback);
}

// 0x004BB170
EditBoxImplementation::~EditBoxImplementation()
{
    if (pText)
    {
        FOG_Free(pText, ".\\UI\\editbox.cpp", 0x8E, 0);
        pText = 0;
    }
    if (pTextCopy)
    {
        FOG_Free(pTextCopy, ".\\UI\\editbox.cpp", 0x93, 0);
        pTextCopy = 0;
    }
    ARCHIVE_FreeClientCellFile(pCellFile);
}

// 0x004BB200
void EditBoxImplementation::sub_004BB200_SetUnk20(int nValue)
{
    unk0x20 = nValue;
}

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

// build: symbol ?Slot01@EditBoxImplementation@@UAEXXZ 0x004BB210
// 0x004BB210
void EditBoxImplementation::Slot01()
{
    ++unk0x46;
    if (unk0x56)
    {
        sub_0046EFD0_DrawFramedBox(nTextX - 10, nTextY - 0x10, nTextWidth, 0x12, 0, 2);
    }
    sub_00502EF0(nFont);

    Unicode wszBuffer[200];
    Unicode wszCursor[2];
    char szCursor[2];
    szCursor[1] = 0;
    szCursor[0] = '_';
    Unicode::win2Unicode(wszCursor, szCursor, 2);

    if ((unk0x4A && unk0x46 % 20 == 0) || (!unk0x4A && unk0x46 % 10 == 0))
    {
        unk0x4A = !unk0x4A;
    }

    if (nHeight == 1)
    {
        int nStart = 0;
        if (D2Win_10121_GetTextWidth(pText) > nTextWidth)
        {
            const int nLength = sub_00526800(pText);
            for (nStart = 0; nStart < nLength; ++nStart)
            {
                if (D2Win_10121_GetTextWidth(&pText[nStart]) <= nTextWidth)
                {
                    break;
                }
            }
        }

        D2Win_10117_DrawText(&pText[nStart], nTextX, nTextY, 0, 0);
        if (unk0x36 < nMaxLength && unk0x4A && unk0x36 <= unk0x3A)
        {
            if (sub_00526800(&pText[nStart]))
            {
                sub_005267E0(pTextCopy, pText);
                pTextCopy[unk0x36] = 0;
                D2Win_10117_DrawText(wszCursor, D2Win_10121_GetTextWidth(pTextCopy) + nTextX, nTextY, 0, 0);
            }
            else
            {
                D2Win_10117_DrawText(wszCursor, nTextX, nTextY, 0, 0);
            }
        }
        return;
    }

    int nLines;
    T0044CB60* pLine = sub_00502970_SplitText(pText, &nLines, nTextWidth);
    int nLine = 0;
    int nChars = 0;
    int bDone = 0;
    while (pLine)
    {
        D2Win_10117_DrawText(pLine->pText, nTextX, nTextY + 20 * nLine, 0, 0);
        const int nLength = sub_00526800(pLine->pText);
        T0044CB60* pNext = pLine->pNext;
        nChars += nLength;
        ++nLine;
        if (unk0x36 < nMaxLength && unk0x4A && nChars >= unk0x36 && !bDone)
        {
            bDone = 1;
            int nColumn = unk0x36 - nChars + nLength;
            if (nColumn < 0)
            {
                nColumn = 0;
            }
            if (sub_00526800(pLine->pText))
            {
                if (sub_00526800(pLine->pText) > 199)
                {
                    return;
                }
                sub_005267E0(wszBuffer, pLine->pText);
                wszBuffer[nColumn] = 0;
                D2Win_10117_DrawText(wszCursor, D2Win_10121_GetTextWidth(wszBuffer) + nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
            else
            {
                D2Win_10117_DrawText(wszCursor, nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
        }
        FOG_Free(pLine->pText, ".\\UI\\editbox.cpp", 0x103, 0);
        FOG_Free(pLine, ".\\UI\\editbox.cpp", 0x104, 0);
        pLine = pNext;
    }
    if (!nLine && unk0x4A)
    {
        D2Win_10117_DrawText(wszCursor, nTextX, nTextY, 0, 0);
    }
}

// 0x004BB4D0
void EditBoxImplementation::sub_004BB4D0_Slot15(int nValue)
{
    char szBuffer[0x14];
    sprintf(szBuffer, szIntFormat_006D57BC, nValue);
    if (strlen(szBuffer) > nMaxLength)
    {
        szBuffer[nMaxLength - 1] = 0;
    }
    sub_00526F20_ToUnicode(pText, szBuffer, nMaxLength);
    const int nLength = sub_00526800(pText);
    unk0x36 = nLength;
    unk0x3A = nLength;
}

// 0x004BB530
void EditBoxImplementation::sub_004BB530_Slot14(const char* szText)
{
    sub_00526F20_ToUnicode(pText, szText, nMaxLength);
    const int nLength = sub_00526800(pText);
    unk0x36 = nLength;
    unk0x3A = nLength;
}

// build: symbol ?Slot11@EditBoxImplementation@@UAEHXZ 0x004BB560
// 0x004BB560
int EditBoxImplementation::Slot11()
{
    if (!sub_00526800(pText))
    {
        return 0;
    }
    char szBuffer[100];
    sub_005263E0(szBuffer, pText, nMaxLength);
    const int nValue = atoi(szBuffer);
    if (nValue > nMaxValue)
    {
        return 0;
    }
    return nValue;
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

// build: symbol ?MsgSlot05@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB950
// 0x004BB950
int EditBoxImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot07@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB960
// 0x004BB960
int EditBoxImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot08@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB970
// 0x004BB970
int EditBoxImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BB980
void EditBoxImplementation::sub_004BB980_SetUnk04(int nValue)
{
    unk0x04 = nValue;
}

// 0x004BB990
void EditBoxImplementation::sub_004BB990_SetUnk18(int nValue)
{
    nTextWidth = nValue;
}

// 0x004BB9A0
void EditBoxImplementation::sub_004BB9A0_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// build: symbol ?MsgSlot09@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB9B0
// 0x004BB9B0
int EditBoxImplementation::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 < unk0x3A)
        unk0x36 += 1;
    return 1;
}

// build: symbol ?MsgSlot10@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB9D0
// 0x004BB9D0
int EditBoxImplementation::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 > 0)
        unk0x36 -= 1;
    return 1;
}

// 0x004BB9F0
EditBoxWrapper::~EditBoxWrapper()
{
    delete pImpl;
}

// build: symbol ?MsgSlot02@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBA80
// 0x004BBA80
int EditBoxWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}

// build: symbol ?MsgSlot03@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBA90
// 0x004BBA90
int EditBoxWrapper::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot03(pMsg);
}

// build: symbol ?MsgSlot04@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAA0
// 0x004BBAA0
int EditBoxWrapper::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot04(pMsg);
}

// build: symbol ?MsgSlot05@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAB0
// 0x004BBAB0
int EditBoxWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
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

// build: symbol ?MsgSlot06@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAD0
// 0x004BBAD0
int EditBoxWrapper::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot06(pMsg);
}

// build: symbol ?MsgSlot08@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAE0
// 0x004BBAE0
int EditBoxWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAF0
// 0x004BBAF0
int EditBoxWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?MsgSlot09@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBB00
// 0x004BBB00
int EditBoxWrapper::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot09(pMsg);
}

// build: symbol ?MsgSlot10@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBB10
// 0x004BBB10
int EditBoxWrapper::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot10(pMsg);
}

// 0x004BBB30
void EditBoxWrapper::sub_004BBB30_Slot12(int nValue)
{
    pImpl->Slot13();
}

// 0x004BBB40
void EditBoxWrapper::sub_004BBB40_Slot14(int nValue)
{
    pImpl->sub_004BB4D0_Slot15(nValue);
}

// 0x004BBB50
void EditBoxWrapper::sub_004BBB50_Slot13(const char* szText)
{
    pImpl->sub_004BB530_Slot14(szText);
}

// 0x004BBB60
void EditBoxWrapper::sub_004BBB60_Slot15(char* szBuffer)
{
    pImpl->sub_004BB5B0_Slot12(szBuffer);
}

// 0x004BBB70
void EditBoxWrapper::sub_004BBB70_SetUnk04(int nValue)
{
    pImpl->sub_004BB980_SetUnk04(nValue);
}

// 0x004BBB90
void EditBoxWrapper::sub_004BBB90_SetUnk24(int nValue)
{
    pImpl->sub_004BB9A0_SetUnk24(nValue);
}

// 0x004BBBA0
void EditBoxWrapper::sub_004BBBA0_SetUnk20(int nValue)
{
    pImpl->sub_004BB200_SetUnk20(nValue);
}

// 0x004BBBB0
EditBoxImplementation::EditBoxImplementation(int nX, int nY, int nTextWidth, int nHeight, int nArg10,
    unsigned short nMaxLength, int nArg18, int nFont)
{
    char szPath[260];
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szPath, "%s\\ui\\menu\\textslid", gszDataGlobal);
    pCellFile = ARCHIVE_LoadClientCellFile(szPath, 0);
    this->nX = nX;
    this->nY = nY;
    unk0x42 = nArg18;
    unk0x3E = 0;
    unk0x46 = 0;
    const int nSize = (nMaxLength + 1) * sizeof(Unicode);
    pText = (Unicode*)FOG_Alloc(nSize, ".\\UI\\editbox.cpp", 93, 0);
    pTextCopy = (Unicode*)FOG_Alloc(nSize, ".\\UI\\editbox.cpp", 94, 0);
    memset(pText, 0, nSize);
    memset(pTextCopy, 0, nSize);
    nMaxValue = nArg10;
    this->nMaxLength = nMaxLength;
    unk0x36 = 0;
    unk0x3A = 0;
    this->nFont = nFont;
    nTextX = nX + 1;
    nTextY = nY;
    unk0x20 = 1;
    unk0x4A = 1;
    char szDigits[11] = "0000000000";
    Unicode wszDigits[11];
    memset(wszDigits, 0, sizeof(wszDigits));
    sub_00502EF0(nFont);
    sub_00526F20_ToUnicode(wszDigits, szDigits, 11);
    if (nTextWidth <= 0)
    {
        this->nTextWidth = D2Win_10121_GetTextWidth(wszDigits) / 10 * (nMaxLength + 2);
    }
    else
    {
        this->nTextWidth = nTextWidth;
    }
    if (nHeight <= 0)
    {
        this->nHeight = 1;
        unk0x56 = 1;
    }
    else
    {
        this->nHeight = nHeight;
        unk0x56 = 0;
    }
    unk0x24 = 0;
    unk0x04 = 0;
}

// 0x004BBD80
EditBoxWrapper::EditBoxWrapper(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength,
    int nArg18, int nFont)
{
    pImpl = new EditBoxImplementation(nX, nY, nTextWidth, nHeight, nArg10, nMaxLength, nArg18, nFont);
}

// 0x004BBE10
SpinnerImplementation::~SpinnerImplementation()
{
    ARCHIVE_FreeClientCellFile(pCellFile);
}

// build: symbol ?Slot01@SpinnerImplementation@@UAEXXZ 0x004BBE70
// 0x004BBE70
void SpinnerImplementation::Slot01()
{
    if (unk0x38 || unk0x34)
    {
        ++nUnk0x3CCalls;
        pfUnk0x3C();
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = 2 * unk0x34;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nUpX, nUpY, -1, 5, 0);
    tContext.nFrame = 2 * unk0x38 + 1;
    sub_004F6480(&tContext, nDownX, nDownY, -1, 5, 0);
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




// build: symbol ?MsgSlot02@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB5F0
// 0x004BB5F0
int EditBoxImplementation::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
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
static inline int sub_004BC0A0_IsInFirst(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nFirstX && nX < pButtons->nFirstX + pButtons->nWidth
        && nY > pButtons->nFirstY - pButtons->nHeight && nY <= pButtons->nFirstY;
}

static inline int sub_004BC0A0_IsInSecond(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nSecondX && nX < pButtons->nSecondX + pButtons->nWidth
        && nY > pButtons->nSecondY - pButtons->nHeight && nY < pButtons->nSecondY;
}

// 0x004BC0A0
int __fastcall EDITBOX_HandleSpinnerPress(D2ButtonPairStrc* pButtons, int nUnused, D2MouseMessageStrc* pMessage)
{
    pButtons->f_30 = 1;
    if (sub_004BC0A0_IsInFirst(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bFirst = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    _ReadWriteBarrier();
    if (sub_004BC0A0_IsInSecond(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bSecond = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    return 0;
}

// build: symbol ?MsgSlot06@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC190
// 0x004BC190
int SpinnerImplementation::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?MsgSlot08@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1C0
// 0x004BC1C0
int SpinnerImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?MsgSlot09@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1D0
// 0x004BC1D0
int SpinnerImplementation::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BC1F0
SpinnerWrapper::~SpinnerWrapper()
{
    delete pImpl;
}
// 0x004BC480
SpinnerWrapper::SpinnerWrapper(int nX, int nY, int bHorizontal, int nArg0C)
{
    pImpl = new SpinnerImplementation(nX, nY, bHorizontal, nArg0C);
}

struct D2CelFileStrc;

#include "gen/data/Source/D2Client/UI/editbox.inc"





