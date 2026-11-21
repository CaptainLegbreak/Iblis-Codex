#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

extern D2ButtonStringStrc gaButtonStrings_007275A8[];                                                       // 0x007275A8

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
        return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
    }

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

#pragma pack(push, 2)

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
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();

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
    int unk0x30;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    int unk0x46;
    int unk0x4A;
    int nFont;
    void* pCellFile;
    int unk0x56;
};

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
    virtual void sub_004BBFB0(char* szBuffer);
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();

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
    virtual void sub_004BBFB0();

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
    int unk0x40;
    int unk0x44[2];
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
    virtual void sub_004BBFB0();

    SpinnerImplementation* pImpl;
};

#pragma pack(pop)

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ButtonImplementation@@6B@ 0x006DA6F4
// build: symbol ??_7ButtonWrapper@@6B@ 0x006DA72C
// build: symbol ??_7EditBoxImplementation@@6B@ 0x006DA77C
// build: symbol ??_7EditBoxWrapper@@6B@ 0x006DA7CC
// build: symbol ??_7SpinnerWrapper@@6B@ 0x006DA874
// 0x004BAF20
ButtonImplementation::ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    nBaseFrame = gaButtonStrings_007275A8[nStringSlot].nCelFrame;
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

// 0x004BB0F0
ButtonWrapper::ButtonWrapper(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    pImpl = new ButtonImplementation(nX, nY, nStringSlot, pfnCallback);
}

// 0x004BBBB0
EditBoxImplementation::EditBoxImplementation(int nX, int nY, int nTextWidth, int nHeight, int nArg10,
    unsigned short nMaxLength, int nArg18, int nFont)
{
    char szPath[260];
    sprintf(szPath, "%s\\ui\\menu\\textslid", szDataGlobal_006D4118);
    pCellFile = sub_004788B0(szPath, 0);
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
    unk0x30 = nArg10;
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
        this->nTextWidth = sub_00501820(wszDigits) / 10 * (nMaxLength + 2);
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

// 0x004BC1D0
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x004BC480
SpinnerWrapper::SpinnerWrapper(int nX, int nY, int bHorizontal, int nArg0C)
{
    pImpl = new SpinnerImplementation(nX, nY, bHorizontal, nArg0C);
}

struct D2CelFileStrc;

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

#include "gen/data/Source/D2Client/UI/editbox_004BBBB0.inc"
