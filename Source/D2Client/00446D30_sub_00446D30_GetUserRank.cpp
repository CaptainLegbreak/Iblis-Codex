struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
    char unk0x36[0x5A];
    unsigned int dwFlags;
    char unk0x94[0x1C];
    T0043E860* pNext;
};

static __declspec(noinline) int sub_00446D30_GetUserRank(T0043E860* pUser);

// 0x00446D30
static int sub_00446D30_GetUserRank(T0043E860* pUser)
{
    const unsigned int dwFlags = pUser->dwFlags;
    if (dwFlags & 2)
        return 4;
    if (dwFlags & 8)
        return 3;
    if (dwFlags & 1)
        return 2;
    if (dwFlags & 4)
        return 1;
    return 0;
}

// build: context sub_00446D30_Shim

// calling-convention shim (not game code)
int __fastcall sub_00446D30_Shim(T0043E860* pLeft, T0043E860* pRight)
{
    return sub_00446D30_GetUserRank(pRight) - sub_00446D30_GetUserRank(pLeft);
}
