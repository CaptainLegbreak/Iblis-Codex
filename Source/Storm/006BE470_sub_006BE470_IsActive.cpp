struct sub_006BE470_Strc
{
    char unk_000[0x86C];
    int nState;
};

// 0x006BE470
int __stdcall sub_006BE470_IsActive(sub_006BE470_Strc* pThis)
{
    if (!pThis)
        return 0;
    return pThis->nState == 1 || pThis->nState == 2;
}
