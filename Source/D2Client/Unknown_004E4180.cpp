extern "C" int __cdecl abs(int);
#pragma intrinsic(abs)
#define MINIMUM(a,b) (((a) < (b)) ? (a) : (b))
#ifdef MOVED_TEST
#define MASK_DECREMENT 3
#else
#define MASK_DECREMENT 1
#endif
static __forceinline int Absolute(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}
// 0x004E4180
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength)
{
    int nFrameMod;
    int nOffsetMod;
    const int nMask = nStepLength - MASK_DECREMENT;
    if (!(nStepLength & nMask))
    {
        nFrameMod = nFrame & nMask;
        nOffsetMod = nOffset & nMask;
    }
    else
    {
        nFrameMod = nFrame % nStepLength;
        nOffsetMod = nOffset % nStepLength;
    }
    const int nDirect = Absolute(nOffsetMod - nFrameMod);
    const int nForward = Absolute(nOffsetMod - nFrameMod - nStepLength);
    const int nBackward = Absolute(nFrameMod - nOffsetMod - nStepLength);
    return MINIMUM(MINIMUM(nDirect, nForward), nBackward);
}
