#include "D2Client.h"
#include "D2Structs.h"

#define gnGlobal_007BCA34 (gGrid_007BCA30.nGridLeft)
#define gnGlobal_007BCA38 (gGrid_007BCA30.nGridRight)
#define gnGlobal_007BCA3C (gGrid_007BCA30.nGridTop)
#define gnGlobal_007BCA40 (gGrid_007BCA30.nGridBottom)
#define gnGlobal_007BCA68 (gInvRect_007BCA68.nLeft)
#define gnGlobal_007BCA6C (gInvRect_007BCA68.nRight)
#define gnGlobal_007BCA74 (gInvRect_007BCA68.nBottom)
#define gnGlobal_007BCA7C (gGrid_007BCA78.nGridLeft)
#define gnGlobal_007BCA80 (gGrid_007BCA78.nGridRight)
#define gnGlobal_007BCA84 (gGrid_007BCA78.nGridTop)
#define gnGlobal_007BCA88 (gGrid_007BCA78.nGridBottom)
#define gnGlobal_007BCAF4 (gInvRect_007BCAF4.nLeft)
#define gnGlobal_007BCAF8 (gInvRect_007BCAF4.nRight)
#define gnGlobal_007BCB00 (gInvRect_007BCAF4.nBottom)
#define gnGlobal_007BCB44 (gGrid_007BCB40.nGridLeft)
#define gnGlobal_007BCB48 (gGrid_007BCB40.nGridRight)
#define gnGlobal_007BCB4C (gGrid_007BCB40.nGridTop)
#define gnGlobal_007BCB50 (gGrid_007BCB40.nGridBottom)
#define gnGlobal_007BCB74 (gGrid_007BCB70.nGridLeft)
#define gnGlobal_007BCB78 (gGrid_007BCB70.nGridRight)
#define gnGlobal_007BCB7C (gGrid_007BCB70.nGridTop)
#define gnGlobal_007BCB80 (gGrid_007BCB70.nGridBottom)

struct Unicode;
struct D2InvRectStrc;
struct D2InventoryGridInfoStrc;

struct Unicode
{
    unsigned short wChar;
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
void __fastcall sub_00482B40(unsigned int nTick); // 0x00482B40
void __fastcall sub_004BA020(unsigned int nTick); // 0x004BA020
void __fastcall sub_004DCAA0(unsigned int nTick); // 0x004DCAA0
int __cdecl sub_004DF870(); // 0x004DF870
void __cdecl sub_004DF890(); // 0x004DF890
void __fastcall sub_004E42E0(unsigned int nTick); // 0x004E42E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern char gbCinematicStop_007BC9D4; // 0x007BC9D4
extern char gbCinematicWide_007BC9D6; // 0x007BC9D6
extern char gbCinematicBusy_007BC9D7; // 0x007BC9D7
extern char gbCinematicChain_007BC9D8; // 0x007BC9D8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
static __declspec(noinline) unsigned char sub_00482C70_GetFlagIndex(unsigned char nFlags);
int __cdecl sub_0044DCC0(); // 0x0044DCC0

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};


extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
extern D2InvRectStrc gInvRect_007BCA68; // 0x007BCA68
extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InvRectStrc gInvRect_007BCAF4; // 0x007BCAF4
extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70

unsigned int gdwGlobal_007BC9BC; // 0x007BC9BC

// 0x00482C20
void __cdecl sub_00482C20_Tick()
{
    if (sub_004DF870())
    {
        sub_004E42E0(gdwGlobal_007BC9BC);
        sub_004DCAA0(gdwGlobal_007BC9BC);
        sub_00482B40(gdwGlobal_007BC9BC);
        sub_004BA020(gdwGlobal_007BC9BC);
        sub_004DF890();
        ++gdwGlobal_007BC9BC;
        Sleep(0);
    }
}

// 0x00483310
void __cdecl sub_00483310_ResetCinematicFlags()
{
    gbCinematicStop_007BC9D4 = 0;
    gbCinematicWide_007BC9D6 = !sub_0040EB10();
    gbCinematicChain_007BC9D8 = 0;
    gbCinematicBusy_007BC9D7 = 0;
}

// 0x00483350
unsigned char __cdecl sub_00483350_IsCinematicBusy()
{
    return gbCinematicBusy_007BC9D7;
}

// 0x004834A0
const Unicode* __fastcall sub_004834A0_SkipBracketTag(const Unicode* pString)
{
    int n = sub_00526800(pString);
    for (; n > 0; --n)
    {
        if (pString[n].wChar == ']')
        {
            break;
        }
    }
    if (pString[n].wChar == ']' && n >= 3 && pString[n - 3].wChar == '[')
    {
        return &pString[n + 1];
    }
    return pString;
}

// 0x00483E10
int __cdecl sub_00483E10_IsNpcStateIdle()
{
    if (gdwGlobal_007BCBF0 == 0 || gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4)
    {
        return 1;
    }
    return 0;
}

// 0x00482C70
static unsigned char sub_00482C70_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_00482C70_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += sub_00482C70_GetFlagIndex(pFlags[i]);
    return nSum;
}

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

D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30

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
