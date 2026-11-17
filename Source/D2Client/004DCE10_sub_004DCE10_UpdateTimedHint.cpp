struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    unsigned int nEndTickA;
    int bActive2;
    int nArgE;
    unsigned int nEndTickF;
    int nArgG;
    unsigned int nEndTickC;
};

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00

extern D2TimedHintStrc gTimedHint_007C89E4;                                                                 // 0x007C89E4

// 0x004DCE10
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg)
{
    if (gTimedHint_007C89E4.bActive)
    {
        if (nArg)
        {
            gTimedHint_007C89E4.nEndTickF = sub_0044DB00() + nDelay;
        }

        gTimedHint_007C89E4.nArgG = nArg;
        gTimedHint_007C89E4.nEndTickC = gTimedHint_007C89E4.nEndTickF + 0x32;
    }
}
