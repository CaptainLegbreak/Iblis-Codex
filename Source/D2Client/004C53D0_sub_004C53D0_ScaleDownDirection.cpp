// 0x004C53D0
void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY)
{
    int nY = *pY;
    int nX = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nY /= 2;
        nX /= 2;
    }

    *pX = nY;
    *pY = nX;
}
