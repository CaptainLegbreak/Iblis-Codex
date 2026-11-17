struct D2ActRoom00619DA0Strc
{
    unsigned char unk_00[0x4C];
    int nX4C;
    int nY50;
    int nWidth54;
    int nHeight58;
    unsigned char unk_5C[0x7C - 0x5C];
    D2ActRoom00619DA0Strc* pNext7C;
};
struct D2Act00619DA0Strc
{
    unsigned char unk_00[0x10];
    D2ActRoom00619DA0Strc* pFirstRoom10;
};

// 0x00619DA0
D2ActRoom00619DA0Strc* __stdcall sub_00619DA0_ActLookup(D2Act00619DA0Strc* pAct, int nX, int nY)
{
    if (!pAct)
    {
        return 0;
    }
    for (D2ActRoom00619DA0Strc* pRoom = pAct->pFirstRoom10; pRoom; pRoom = pRoom->pNext7C)
    {
        if (pRoom && nX >= pRoom->nX4C && nX < pRoom->nX4C + pRoom->nWidth54 && nY >= pRoom->nY50 && nY < pRoom->nY50 + pRoom->nHeight58)
        {
            return pRoom;
        }
    }
    return 0;
}
