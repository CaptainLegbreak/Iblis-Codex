struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

D2InvRectStrc gInvRect_007BCB30;                                                                            // 0x007BCB30
#define gnGlobal_007BCB30 (gInvRect_007BCB30.nLeft)
#define gnGlobal_007BCB34 (gInvRect_007BCB30.nRight)
#define gnGlobal_007BCB3C (gInvRect_007BCB30.nBottom)

// 0x00483C20
static __declspec(noinline) int sub_00483C20_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_M133_Emit_00483C20(int nX, int nY)
{
    return sub_00483C20_IsInRect(nX, nY);
}
