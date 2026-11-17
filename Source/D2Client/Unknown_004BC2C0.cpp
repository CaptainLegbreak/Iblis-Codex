#include "D2Client.h"

class UIWidget;
class ButtonImplementation;
class ButtonWrapper;

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
    virtual void Slot01();
    virtual int Slot11();

    ButtonImplementation* pImpl;
};

// 0x004BC2C0
void ButtonWrapper::Slot01()
{
    pImpl->Slot01();
}

// 0x004BC320
int ButtonWrapper::Slot11()
{
    return pImpl->Slot11();
}
