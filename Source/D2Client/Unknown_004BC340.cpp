#include "D2Client.h"

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

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
extern "C" D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
extern "C" int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
extern "C" int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
extern "C" const char gszEditBoxCpp_006DA760[];                                                             // 0x006DA760
extern "C" const char gszTextSlidPath_006DA824[];                                                           // 0x006DA824
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

class SpinnerImplementation : public UIWidget
{
public:
    SpinnerImplementation(int nX, int nY, int bHorizontal, int nArg0C);
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

#pragma pack(pop)

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7SpinnerImplementation@@6B@ 0x006DA83C
// 0x004BC340
SpinnerImplementation::SpinnerImplementation(int nX, int nY, int bHorizontal, int nArg0C)
{
    char szPath[260];
    sprintf(szPath, "%s\\ui\\menu\\spinner", szDataGlobal_006D4118);
    void* pFile = sub_004788B0(szPath, 0);
    pCellFile = pFile;
    this->nX = nX;
    this->nY = nY;
    unk0x3C = nArg0C;
    this->f_2C = bHorizontal;
    unk0x34 = 0;
    unk0x38 = 0;
    unk0x30 = 0;
    unk0x4C = 0;
    unk0x40 = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    D2CelStrc* pCel = CelGetHandle(&tContext);
    nArrowHeight = sub_006018F0(pCel);
    nArrowWidth = sub_006018C0(pCel);
    nUpY = nY;
    if (this->f_2C)
    {
        nUpX = nX + 1;
        nDownX = nX + nArrowWidth;
        nDownY = nY;
    }
    else
    {
        nUpX = nX + 1;
        nDownX = nX + 1;
        nDownY = nY + nArrowHeight + 1;
    }
}
