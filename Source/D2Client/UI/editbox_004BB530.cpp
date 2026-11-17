#include "D2Client.h"

struct Unicode;
class UIWidget;
class EditBoxImplementation;
class SpinnerImplementation;

struct Unicode
{
    unsigned short wChar;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

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

// 0x004BB530
void EditBoxImplementation::sub_004BB530_Slot14(const char* szText)
{
    sub_00526F20_ToUnicode(pText, szText, nMaxLength);
    const int nLength = sub_00526800(pText);
    *(int*)unk0x36 = nLength;
    *(int*)unk0x3A = nLength;
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
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, nUpX, nUpY, -1, 5, 0);
    tContext.nFrame = 2 * unk0x38 + 1;
    sub_004F6480(&tContext, nDownX, nDownY, -1, 5, 0);
}

// 0x004BB960
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
