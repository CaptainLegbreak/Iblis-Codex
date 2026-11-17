int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

extern D2InventoryGridInfoStrc gGrid_007BCA30;                                                              // 0x007BCA30
#define gnGlobal_007BCA34 (gGrid_007BCA30.nGridLeft)
#define gnGlobal_007BCA38 (gGrid_007BCA30.nGridRight)
#define gnGlobal_007BCA3C (gGrid_007BCA30.nGridTop)
#define gnGlobal_007BCA40 (gGrid_007BCA30.nGridBottom)
extern D2InvRectStrc gInvRect_007BCA68;                                                                     // 0x007BCA68
#define gnGlobal_007BCA68 (gInvRect_007BCA68.nLeft)
#define gnGlobal_007BCA6C (gInvRect_007BCA68.nRight)
#define gnGlobal_007BCA74 (gInvRect_007BCA68.nBottom)
extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78
#define gnGlobal_007BCA7C (gGrid_007BCA78.nGridLeft)
#define gnGlobal_007BCA80 (gGrid_007BCA78.nGridRight)
#define gnGlobal_007BCA84 (gGrid_007BCA78.nGridTop)
#define gnGlobal_007BCA88 (gGrid_007BCA78.nGridBottom)
extern D2InvRectStrc gInvRect_007BCAF4;                                                                     // 0x007BCAF4
#define gnGlobal_007BCAF4 (gInvRect_007BCAF4.nLeft)
#define gnGlobal_007BCAF8 (gInvRect_007BCAF4.nRight)
#define gnGlobal_007BCB00 (gInvRect_007BCAF4.nBottom)
extern D2InventoryGridInfoStrc gGrid_007BCB18;                                                              // 0x007BCB18
#define gnGlobal_007BCB1C (gGrid_007BCB18.nGridLeft)
#define gnGlobal_007BCB20 (gGrid_007BCB18.nGridRight)
#define gnGlobal_007BCB24 (gGrid_007BCB18.nGridTop)
#define gnGlobal_007BCB28 (gGrid_007BCB18.nGridBottom)
extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40
#define gnGlobal_007BCB44 (gGrid_007BCB40.nGridLeft)
#define gnGlobal_007BCB48 (gGrid_007BCB40.nGridRight)
#define gnGlobal_007BCB4C (gGrid_007BCB40.nGridTop)
#define gnGlobal_007BCB50 (gGrid_007BCB40.nGridBottom)
extern D2InventoryGridInfoStrc gGrid_007BCB70;                                                              // 0x007BCB70
#define gnGlobal_007BCB74 (gGrid_007BCB70.nGridLeft)
#define gnGlobal_007BCB78 (gGrid_007BCB70.nGridRight)
#define gnGlobal_007BCB7C (gGrid_007BCB70.nGridTop)
#define gnGlobal_007BCB80 (gGrid_007BCB70.nGridBottom)

// 0x00483AE0
static __declspec(noinline) int sub_00483AE0_IsInRect(int nX, int nY)
{
    if (nX > gnGlobal_007BCB1C && nX < gnGlobal_007BCB20 && nY >= gnGlobal_007BCB24 && nY <= gnGlobal_007BCB28)
    {
        return 1;
    }
    return 0;
}

// 0x00483B10
static __declspec(noinline) int sub_00483B10_IsInRect(int nX, int nY)
{
    if (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
    {
        return 1;
    }
    return 0;
}

// 0x00483B40
static __declspec(noinline) int sub_00483B40_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

// 0x00483BA0
static __declspec(noinline) int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
    {
        return 1;
    }
    return 0;
}

// 0x00483BF0
static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_E04_Emit_00483AE0(int nX, int nY)
{
    return sub_00483AE0_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483B10(int nX, int nY)
{
    return sub_00483B10_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483B40(int nX, int nY)
{
    return sub_00483B40_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BA0(int nX, int nY)
{
    return sub_00483BA0_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BF0(int nX, int nY)
{
    return sub_00483BF0_IsInRect(nX, nY);
}
