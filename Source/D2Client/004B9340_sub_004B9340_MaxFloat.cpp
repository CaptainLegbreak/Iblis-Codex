struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2UnkFieldsStrc
{
    char unk0x00[0x1C];
    int nUnk0x1C;
    char unk0x20[0x25];
    unsigned char nUnk0x45[4];
    unsigned char nUnk0x49[4];
    unsigned char nUnk0x4D[4];
    unsigned char nUnk0x51[4];
    unsigned char nUnk0x55[4];
};

struct D2UnkSortItemStrc
{
    char unk0x00[0x18];
    float fUnk0x18;
    char unk0x1C[0x18];
    unsigned int nUnk0x34;
    char unk0x38[4];
    unsigned char nUnk0x3C;
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

class ButtonImplementation : public UIWidget
{
public:
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual void sub_004BAC60_SetUnk24(int nValue);

    char unk0x08[0x1C];
    int unk0x24;
    int (__cdecl* pfnCallback)();
};

class SpinnerImplementation;

class SpinnerWrapper : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);

    SpinnerImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
};

// 0x004B9340
float __fastcall sub_004B9340_MaxFloat(float fA, float fB)
{
    return fA > fB ? fA : fB;
}

// 0x004B9370
float __fastcall sub_004B9370_MinFloat(float fA, float fB)
{
    return fA < fB ? fA : fB;
}

// 0x004B93A0
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax)
{
    return sub_004B9370_MinFloat(sub_004B9340_MaxFloat(fValue, fMin), fMax);
}

// 0x004B9B80
void __fastcall sub_004B9B80_SetFields(D2UnkFieldsStrc* pRecord, int nValue, int nBase, int nOffset)
{
    *(int*)pRecord->nUnk0x49 = pRecord->nUnk0x1C;
    *(int*)pRecord->nUnk0x4D = nValue;
    *(int*)pRecord->nUnk0x51 = nBase;
    *(int*)pRecord->nUnk0x55 = nBase + nOffset;
    *(int*)pRecord->nUnk0x45 = 1;
}

// 0x004B9DA0
int __fastcall sub_004B9DA0_CompareItems(D2UnkSortItemStrc* pA, D2UnkSortItemStrc* pB, int bCompareFloat,
                                         int bCompareValue)
{
    if (pA->nUnk0x3C > pB->nUnk0x3C)
    {
        return 1;
    }

    if (pA->nUnk0x3C < pB->nUnk0x3C)
    {
        return 0;
    }

    if (bCompareFloat)
    {
        if (pA->fUnk0x18 < pB->fUnk0x18)
        {
            return 1;
        }

        if (pA->fUnk0x18 > pB->fUnk0x18)
        {
            return 0;
        }
    }

    if (bCompareValue)
    {
        if (pA->nUnk0x34 > pB->nUnk0x34)
        {
            return 1;
        }

        if (pA->nUnk0x34 < pB->nUnk0x34)
        {
            return 0;
        }
    }

    return pA > pB;
}

// 0x004BAC60
void ButtonImplementation::sub_004BAC60_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// 0x004BAD40
int ButtonImplementation::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x24 && !(pMsg->lParam & 0x40000000) && pMsg->wParam == 0x0D)
    {
        return pfnCallback();
    }

    return 0;
}

// 0x004BC280
int SpinnerWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}
