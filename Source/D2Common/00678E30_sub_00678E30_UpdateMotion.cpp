struct D2PathPointStrc { unsigned short nX, nY; };
struct D2CoordStrc { int nX, nY; };
struct D2MotionPathStrc
{
    D2PathPointStrc tStart;
    D2PathPointStrc tTarget;
    D2CoordStrc tDirectionVector;
    D2CoordStrc tVelocity;
    int nSpeed;
    unsigned char nDirection;
    char unk_1D[3];
    unsigned int nFlags;
};
void __fastcall sub_0064FD70_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70

// 0x00678E30
int __fastcall sub_00678E30_UpdateMotion(D2MotionPathStrc* pPath)
{
    if (pPath->tStart.nX == pPath->tTarget.nX && pPath->tStart.nY == pPath->tTarget.nY)
    {
        pPath->tDirectionVector.nX = 0;
        pPath->tDirectionVector.nY = 0;
        pPath->tVelocity.nX = 0;
        pPath->tVelocity.nY = 0;
        pPath->nSpeed = 0;
        return 1;
    }
    int nDirection;
    sub_0064FD70_GetDirectionVectorFromPoints(&pPath->tDirectionVector, &nDirection, pPath->tStart, pPath->tTarget);
    pPath->nDirection = nDirection;
    if (pPath->nFlags & 0x200)
        pPath->nDirection = (pPath->nDirection - 32) & 63;
    pPath->tVelocity.nX = (pPath->tDirectionVector.nX * pPath->nSpeed) >> 8;
    pPath->tVelocity.nY = (pPath->tDirectionVector.nY * pPath->nSpeed) >> 8;
    const int nVelocityX = pPath->tVelocity.nX < 0 ? -pPath->tVelocity.nX : pPath->tVelocity.nX;
    unsigned short nTargetCoordinate = pPath->tTarget.nX;
    const int nDiffX = (int)pPath->tStart.nX - nTargetCoordinate;
    const int nDeltaX = (nDiffX < 0 ? -nDiffX : nDiffX) << 16;
    const int nVelocityY = pPath->tVelocity.nY < 0 ? -pPath->tVelocity.nY : pPath->tVelocity.nY;
    nTargetCoordinate = pPath->tTarget.nY;
    const int nDiffY = (int)pPath->tStart.nY - nTargetCoordinate;
    const int nDeltaY = nDiffY < 0 ? -nDiffY : nDiffY;
    return (nVelocityX <= nDeltaX || nVelocityY <= (nDeltaY << 16)) ? 1 : 0;
}
