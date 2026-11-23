#include "D2Client.h"
#include "D2StormTypes.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class UIWidget;
class SpinnerImplementation;

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

#pragma pack(push, 2)

class SpinnerImplementation : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);

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
