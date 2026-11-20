#include "D2StormTypes.h"

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
