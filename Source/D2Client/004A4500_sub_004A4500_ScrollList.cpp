int __cdecl sub_004A44C0_GetMaxFirstEntry();                                                                // 0x004A44C0

extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gnThumbScale_007C0278;                                                                           // 0x007C0278
extern int gnFirstVisible_007C02AC;                                                                         // 0x007C02AC
extern int gnThumbY_007C02CC;                                                                               // 0x007C02CC

static __forceinline int sub_I18_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static __forceinline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static __forceinline int sub_I18_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

// 0x004A4500
void __fastcall sub_004A4500_ScrollList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A4500_ScrollList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A4500_ScrollList(1);
        return;
    }

    const int nMax = sub_004A44C0_GetMaxFirstEntry();
    int nFirst = gnFirstVisible_007C02AC;
    if (nStep < 0)
    {
        const int nPrev = nFirst <= 0 ? nFirst : nFirst - 1;
        if (nPrev < 0)
            goto done;
        nFirst = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNext > nMax)
            goto done;
        nFirst = nNext;
    }
    else
        goto done;
    gnFirstVisible_007C02AC = nFirst;
done:
    gnThumbY_007C02CC = sub_I18_TrackSpan() * nFirst / nMax + sub_I18_TrackTop();
}
