#include "D2StormTypes.h"
#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"

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

class ButtonImplementation : public UIWidget
{
public:
    virtual void sub_004BAC60_SetUnk24(int nValue);
};

class ButtonWrapper : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);
    virtual void sub_004BAF10_SetUnk24(int nValue);

    ButtonImplementation* pImpl;
};

struct Unicode;

class UIWidget;

class EditBoxImplementation;

class SpinnerImplementation;

class EditBoxImplementation : public UIWidget
{
public:
    virtual void sub_004BB5B0_Slot12(Unicode* pBuffer);
    virtual int sub_004BB5D0_Slot13();
    virtual void sub_004BB530_Slot14(const char* szText);
    virtual void sub_004BB4D0_Slot15(const char* szText);
    virtual void sub_004BB990_SetUnk18(int nValue);
    virtual void sub_004BB9A0_SetUnk24(int nValue);
    virtual void sub_004BB200_SetUnk20(int nValue);

    void sub_004BB980_SetUnk04(int nValue);

    char unk0x08[0x10];
    int unk0x18;
    char unk0x1C[4];
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    char unk0x2C[8];
    unsigned short nMaxLength;
    unsigned char unk0x36[4];
    unsigned char unk0x3A[4];
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual void Slot01();
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);

    char unk0x08[8];
    int nUpX;
    int nUpY;
    int nDownX;
    int nDownY;
    int unk0x20;
    char unk0x24[0x10];
    int unk0x34;
    int unk0x38;
    void (__cdecl* pfUnk0x3C)();
    int nUnk0x3CCalls;
    char unk0x44[0xC];
    void* pCellFile;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

// 0x004BAE60
int ButtonWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}

// 0x004BAE70
int ButtonWrapper::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot03(pMsg);
}

// 0x004BAE80
int ButtonWrapper::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot04(pMsg);
}

// 0x004BAE90
int ButtonWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// 0x004BAEB0
int ButtonWrapper::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot06(pMsg);
}

// 0x004BAEC0
int ButtonWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// 0x004BAED0
int ButtonWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// 0x004BAEE0
int ButtonWrapper::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot09(pMsg);
}

// 0x004BAEF0
int ButtonWrapper::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot10(pMsg);
}

// 0x004BAF10
void ButtonWrapper::sub_004BAF10_SetUnk24(int nValue)
{
    pImpl->sub_004BAC60_SetUnk24(nValue);
}

// 0x004BB530
void EditBoxImplementation::sub_004BB530_Slot14(const char* szText)
{
    sub_00526F20_ToUnicode(pText, szText, nMaxLength);
    const int nLength = sub_00526800(pText);
    *(int*)unk0x36 = nLength;
    *(int*)unk0x3A = nLength;
}

// 0x004BB960
int __stdcall SKILLS_Return0(int nUnused)
{
    return 0;
}

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
int __fastcall sub_004BC0A0_HandlePress(D2ButtonPairStrc* pButtons, int nUnused, D2MouseMessageStrc* pMessage)
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
