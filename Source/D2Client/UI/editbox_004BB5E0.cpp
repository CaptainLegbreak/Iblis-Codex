#include "D2Client.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

class UIWidget;
class EditBoxImplementation;
class EditBoxWrapper;
class SpinnerImplementation;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

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
class EditBoxImplementation : public UIWidget
{
public:
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

    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int unk0x20;
    int unk0x24;
    void* pText;
    void* pTextCopy;
    int unk0x30;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    int unk0x46;
};

class EditBoxWrapper : public UIWidget
{
public:
    virtual ~EditBoxWrapper();
    virtual void Slot01();
    virtual int Slot11();
    virtual void sub_004BBB30_Slot12(int nValue);

    EditBoxImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual ~SpinnerImplementation();
    virtual int Slot11();
    virtual int sub_004BBFB0();

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
    int unk0x3C;
    unsigned int unk0x40;
    unsigned int unk0x44;
    unsigned int unk0x48;
    int unk0x4C;
    void* pCellFile;
};

#pragma pack(pop)

// 0x004BB5E0
int EditBoxImplementation::MsgSlot03(SMSGHANDLER_PARAMS* pMsg)
{
    unk0x3E = 1;
    return 0;
}

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
        return (dwElapsed >> 11) * unk0x40;
    if (dwElapsed > 0xBB8)
        return unk0x40 >> 2;
    if (dwElapsed > 0x7D0)
        return unk0x40 >> 4;
    if (dwElapsed > 0x3E8)
        return unk0x40 >> 5;
    return 1;
}

// 0x004BB970
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
