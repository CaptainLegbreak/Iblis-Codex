#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;
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
    virtual int Slot11();
    virtual void sub_004BB5B0_Slot12(Unicode* pBuffer);
    virtual int sub_004BB5D0_Slot13();
    virtual void sub_004BB530_Slot14(const char* szText);
    virtual void sub_004BB4D0_Slot15(int nValue);
    virtual void sub_004BB990_SetUnk18(int nValue);
    virtual void sub_004BB9A0_SetUnk24(int nValue);
    virtual void sub_004BB200_SetUnk20(int nValue);

    char unk0x08[0x10];
    int unk0x18;
    char unk0x1C[4];
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    char unk0x2C[4];
    int nMaxValue;
    unsigned short nMaxLength;
    unsigned char unk0x36[4];
    unsigned char unk0x3A[4];
};

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

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
    *(int*)unk0x36 = nLength;
    *(int*)unk0x3A = nLength;
}

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
