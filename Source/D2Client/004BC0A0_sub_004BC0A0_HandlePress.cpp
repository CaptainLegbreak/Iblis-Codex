struct D2MouseMessageStrc
{
    char unk_00[0xC];
    unsigned short nX;
    unsigned short nY;
};
struct D2ButtonPairStrc
{
    char unk_00[0x10];
    int nFirstX;
    int nFirstY;
    int nSecondX;
    int nSecondY;
    int unk_20;
    int nHeight;
    int nWidth;
    int unk_2C;
    int f_30;
    int bFirst;
    int bSecond;
    void (__cdecl* pCallback)();
    int unk_40;
    unsigned long nTick;
    int unk_48;
    int bInvoking;
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

static __forceinline int sub_004BC0A0_IsInFirst(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nFirstX && nX < pButtons->nFirstX + pButtons->nWidth
        && nY > pButtons->nFirstY - pButtons->nHeight && nY <= pButtons->nFirstY;
}

static __forceinline int sub_004BC0A0_IsInSecond(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nSecondX && nX < pButtons->nSecondX + pButtons->nWidth
        && nY > pButtons->nSecondY - pButtons->nHeight && nY < pButtons->nSecondY;
}

// 0x004BC0A0
int __fastcall sub_004BC0A0_HandlePress(D2ButtonPairStrc* pButtons, int nUnused, D2MouseMessageStrc* pMessage)
{
    pButtons->f_30 = 1;
    if (sub_004BC0A0_IsInFirst(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bFirst = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    _ReadWriteBarrier();
    if (sub_004BC0A0_IsInSecond(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bSecond = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    return 0;
}
