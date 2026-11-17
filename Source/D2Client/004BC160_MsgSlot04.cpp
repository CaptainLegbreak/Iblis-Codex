struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
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
    virtual int sub_004BBFB0() = 0;

    int unk0x04;
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);

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
};

struct SpinnerWrapper
{
    virtual void Slot00();
    int unk0x04;
    UIWidget* pImpl;

    int sub_004BC330_ForwardSlot30(int nArg);
};

#pragma pack(1)
struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};
#pragma pack()

inline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x004BC160
int SpinnerImplementation::MsgSlot04(SMSGHANDLER_PARAMS* pMsg)
{
    if (!unk0x30)
    {
        return 0;
    }

    unk0x40 = 0;
    unk0x30 = 0;
    if (unk0x34 == 1)
    {
        unk0x34 = 0;
        return 1;
    }

    if (unk0x38 == 1)
    {
        unk0x38 = 0;
        return 1;
    }

    return 0;
}

// 0x004BC330
int SpinnerWrapper::sub_004BC330_ForwardSlot30(int nArg)
{
    return pImpl->sub_004BBFB0();
}

// 0x004BC500
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMax <= nMin)
    {
        return nMin;
    }

    const int nRange = nMax - nMin;
    if ((nRange - 1) & nRange)
    {
        return (unsigned int)SEED_RollRandomNumber(pSeed) % nRange + nMin;
    }

    return (SEED_RollRandomNumber(pSeed) & (nRange - 1)) + nMin;
}
