struct SMSGHANDLER_PARAMS
{
    char pad_00[12];
    unsigned short nX;
    unsigned short nY;
    char pad_10[8];
    int bReturn;
    int lResult;
};

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007BEFA4; // 0x007BEFA4
int gnGlobal_007BEF84;        // 0x007BEF84
int gnGlobal_007BEF88;        // 0x007BEF88
int gnGlobal_007BEFDC;        // 0x007BEFDC
int gnGlobal_007BEFE0;        // 0x007BEFE0
extern int gnGlobal_007BEFD0; // 0x007BEFD0
extern int gnGlobal_007BEFD8; // 0x007BEFD8
extern int gnGlobal_00722358; // 0x00722358
extern int __cdecl sub_0044DA30_InputBlocked(); // 0x0044DA30
extern int __cdecl sub_00463DF0_StateBlocked(); // 0x00463DF0
extern int __fastcall sub_00498DC0_OverlayHit(SMSGHANDLER_PARAMS*); // 0x00498DC0
extern int __stdcall sub_004150E0_SaveValue(const char*,const char*,int,int); // 0x004150E0
extern int __fastcall sub_004B9A00_Sound(int,void*,int,int,int); // 0x004B9A00
extern int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290

static __declspec(noinline) int __cdecl sub_00497440_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -145 && nX <= nHalf + -128
        && nY >= gnGlobal_00711470 + -28 && nY <= gnGlobal_00711470 + -8)
        return 1;
    return 0;
}

static __declspec(noinline) int __cdecl sub_00497780_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -8 && nX <= nHalf + 5
        && nY >= gnGlobal_00711470 + -39 && nY <= gnGlobal_00711470 + -13)
        return 1;
    return 0;
}

// 0x00499500
void __stdcall sub_00499500_Click(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30_InputBlocked() || sub_00463DF0_StateBlocked())
    {
        pMsg->bReturn=0;
        return;
    }
    int nY=pMsg->nY;
    int nX=pMsg->nX;
    if (sub_00498DC0_OverlayHit(pMsg))
    {
        gnGlobal_007BEFA4=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    int nHeight=gnGlobal_00711470;
    if (nY>nHeight + -48)
    {
        int nWidth;
        if ((unsigned int)(nX + -117)<=48 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF84=1;
        }
        else if (nX>=(nWidth=gnGlobal_0071146C) + -165 && nX<=nWidth + -117 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF88=1;
        }
        else if ((unsigned int)(nX + -30)<=80 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFDC=!gnGlobal_007BEFDC;
            sub_004150E0_SaveValue("Diablo II","Show HP Text",0,gnGlobal_007BEFDC);
        }
        else if (nX>=nWidth + -111 && nX<=nWidth + -31 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFE0=!gnGlobal_007BEFE0;
            sub_004150E0_SaveValue("Diablo II","Show MP Text",0,gnGlobal_007BEFE0);
        }
        else if (sub_00497780_Bounds(nX,nY))
        {
            gnGlobal_007BEFD0=1;
            gnGlobal_007BEFA4=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        else if (sub_00497440_Bounds(nX,nY))
        {
            gnGlobal_007BEFD8=1;
            gnGlobal_007BEFA4=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        gnGlobal_00722358=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn=0;
}

#include "gen/data/Source/D2Client/00499500_sub_00499500_Click.inc"
