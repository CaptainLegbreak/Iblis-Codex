#include "D2Direct3D.h"

struct D2DeviceStrc;
struct D2Point006B7F20Strc;

struct D2DeviceStrc
{
    virtual void __stdcall Unused0() = 0;
    virtual void __stdcall Unused1() = 0;
    virtual void __stdcall Unused2() = 0;
    virtual void __stdcall Unused3() = 0;
    virtual void __stdcall Unused4() = 0;
    virtual void __stdcall Unused5() = 0;
    virtual void __stdcall Unused6() = 0;
    virtual void __stdcall Unused7() = 0;
    virtual void __stdcall Unused8() = 0;
    virtual void __stdcall Unused9() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused11() = 0;
    virtual void __stdcall Unused12() = 0;
    virtual void __stdcall Unused13() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused15() = 0;
    virtual void __stdcall Unused16() = 0;
    virtual void __stdcall Unused17() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused19() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused21() = 0;
    virtual void __stdcall Unused22() = 0;
    virtual void __stdcall Unused23() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused25() = 0;
    virtual void __stdcall Unused26() = 0;
    virtual void __stdcall Unused27() = 0;
    virtual int __stdcall DrawPrimitive(unsigned int type, unsigned int format, void* vertices, unsigned int count, unsigned int flags) = 0;
};
extern D2DeviceStrc* gpDevice_00970E78; // 0x00970E78
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __fastcall D3DCORE_SetColorCombineMode(int state); // 0x006B1EA0
void __fastcall D3DCORE_SetAlphaBlendMode(int mode); // 0x006B1F40
void __fastcall D3DCORE_SetTextureFilterMode(int mode); // 0x006B2030

int __fastcall sub_006B77B0_Call(int nLeft, int nTop, int nRight, int nBottom, int nValue, int nMode); // 0x006B77B0

struct D2Point006B7F20Strc
{
    int nX;
    int nY;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);

static inline int ClampCoordinate(int value, int extent)
{
    value = value > 0 ? value : 0;
    return value < extent - 1 ? value : extent - 1;
}

// 0x006B7980
void __fastcall sub_006B7980_DrawRectangle(int left, int top, int right, int bottom, unsigned char color, unsigned char alpha)
{
    left = ClampCoordinate(left, gnWidth_007C9138);
    right = ClampCoordinate(right, gnWidth_007C9138);
    if (left == right)
        return;
    top = ClampCoordinate(top, gnHeight_007C913C);
    bottom = ClampCoordinate(bottom, gnHeight_007C913C);
    if (bottom == top)
        return;
    if (bottom <= top)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x68);
        exit(-1);
    }
    D3DCORE_SetColorCombineMode(2);
    D3DCORE_SetAlphaBlendMode(4);
    D3DCORE_SetTextureFilterMode(1);

    D2TLVertexStrc vertices[4];
    vertices[0].fX = (float)left;
    vertices[0].fY = (float)top;
    vertices[0].fZ = 0.5f;
    vertices[0].fRhw = 1.0f;
    vertices[0].fU = 0.0f;
    vertices[0].fV = 0.0f;
    vertices[1].fX = (float)left;
    vertices[1].fY = (float)bottom;
    vertices[1].fZ = 0.5f;
    vertices[1].fRhw = 1.0f;
    vertices[1].fU = 0.0f;
    vertices[1].fV = 0.0f;
    vertices[2].fX = (float)right;
    vertices[2].fY = (float)bottom;
    vertices[2].fZ = 0.5f;
    vertices[2].fRhw = 1.0f;
    vertices[2].fU = 0.0f;
    vertices[2].fV = 0.0f;
    vertices[3].fX = (float)right;
    vertices[3].fY = (float)top;
    vertices[3].fZ = 0.5f;
    vertices[3].fRhw = 1.0f;
    vertices[3].fU = 0.0f;
    vertices[3].fV = 0.0f;
// build: symbol ?D3DCORE_GetColor@* 0x006B1D50
    unsigned int diffuse = (D3DCORE_GetColor(color) & 0x00FFFFFF) | ((unsigned int)alpha << 24);
    vertices[0].dwColor = diffuse;
    vertices[1].dwColor = diffuse;
    vertices[2].dwColor = diffuse;
    vertices[3].dwColor = diffuse;
    gpDevice_00970E78->DrawPrimitive(6, 0x1C4, vertices, 4, 0x1C);
}

// 0x006B7ED0
int __fastcall sub_006B7ED0_CallRect(D2RectStrc* pRect, int nValue)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0x10C);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0x10D);
    return sub_006B77B0_Call(pRect->nLeft, pRect->nTop, pRect->nRight, pRect->nBottom, nValue, 5);
}

// 0x006B7F20
void __fastcall sub_006B7F20_CallSquare(D2Point006B7F20Strc* pPoint, unsigned char nSize, int nValue)
{
    if (nSize)
    {
        --nSize;
        D2RectStrc tRect;
        SetRect(&tRect, pPoint->nX - nSize, pPoint->nY - nSize, pPoint->nX + nSize + 1, pPoint->nY + nSize + 1);
        sub_006B77B0_Call(tRect.nLeft, tRect.nTop, tRect.nRight, tRect.nBottom, nValue, 5);
    }
}
