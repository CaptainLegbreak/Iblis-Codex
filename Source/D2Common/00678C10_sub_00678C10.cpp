struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

// 0x00678C10
int __stdcall sub_00678C10(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nAbsDiffX = pPoint2.X - pPoint1.X;
    int nAbsDiffY = pPoint2.Y - pPoint1.Y;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
    }

    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
    }

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
        {
            nDiffY = -1;
        }
        else
        {
            nDiffY &= 1;
        }
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
        {
            nDiffX = -1;
        }
        else
        {
            nDiffX &= 1;
        }
    }

    if (nDiffX < -1)
    {
        nDiffX = -2;
    }
    else if (nDiffX > 1)
    {
        nDiffX = 2;
    }

    if (nDiffY < -1)
    {
        nDiffY = -2;
    }
    else if (nDiffY > 1)
    {
        nDiffY = 2;
    }

    return nDiffY + 5 * nDiffX + 12;
}
