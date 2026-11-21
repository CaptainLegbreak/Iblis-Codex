#include "D2Client.h"
#include "D2Unicode.h"
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
    virtual void Slot01();
    virtual int Slot11();

    ButtonImplementation* pImpl;
};

struct Unicode;

class UIWidget;

class EditBoxImplementation;

class EditBoxWrapper;

class EditBoxImplementation : public UIWidget
{
public:
    virtual void sub_004BB5B0_Slot12(Unicode* pBuffer);
    virtual int sub_004BB5D0_Slot13();
    virtual void sub_004BB530_Slot14(const Unicode* pText);
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
};

class EditBoxWrapper : public UIWidget
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
    virtual void sub_004BBB30_Slot12(int nValue);
    virtual void sub_004BBB50_Slot13(const Unicode* pText);
    virtual void sub_004BBB40_Slot14(const char* szText);
    virtual void sub_004BBB60_Slot15(Unicode* pBuffer);
    virtual void sub_004BBB80_SetUnk18(int nValue);
    virtual void sub_004BBB90_SetUnk24(int nValue);
    virtual void sub_004BBBA0_SetUnk20(int nValue);

    void sub_004BBB70_SetUnk04(int nValue);

    EditBoxImplementation* pImpl;
};

// 0x004BAEA0
void ButtonWrapper::Slot01()
{
    pImpl->Slot01();
}

// 0x004BAF00
int ButtonWrapper::Slot11()
{
    return pImpl->Slot11();
}

// 0x004BB200
void EditBoxImplementation::sub_004BB200_SetUnk20(int nValue)
{
    unk0x20 = nValue;
}

// 0x004BB950
int __stdcall sub_00646000_AlwaysZero(int nUnused)
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
    unk0x18 = nValue;
}

// 0x004BB9A0
void EditBoxImplementation::sub_004BB9A0_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// 0x004BBA80
int EditBoxWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}

// 0x004BBA90
int EditBoxWrapper::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot03(pMsg);
}

// 0x004BBAA0
int EditBoxWrapper::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot04(pMsg);
}

// 0x004BBAB0
int EditBoxWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// 0x004BBAD0
int EditBoxWrapper::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot06(pMsg);
}

// 0x004BBAE0
int EditBoxWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// 0x004BBAF0
int EditBoxWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// 0x004BBB00
int EditBoxWrapper::MsgSlot09(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot09(pMsg);
}

// 0x004BBB10
int EditBoxWrapper::MsgSlot10(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot10(pMsg);
}

// 0x004BBB40
void EditBoxWrapper::sub_004BBB40_Slot14(const char* szText)
{
    pImpl->sub_004BB4D0_Slot15(szText);
}

// 0x004BBB50
void EditBoxWrapper::sub_004BBB50_Slot13(const Unicode* pText)
{
    pImpl->sub_004BB530_Slot14(pText);
}

// 0x004BBB60
void EditBoxWrapper::sub_004BBB60_Slot15(Unicode* pBuffer)
{
    pImpl->sub_004BB5B0_Slot12(pBuffer);
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
