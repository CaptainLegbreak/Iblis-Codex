extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TLVertex006B77B0Strc
{
    float fX;
    float fY;
    float fZ;
    float fRhw;
    unsigned int dwColor;
    unsigned int f_14;
    float fU;
    float fV;
};

struct D2Device006B77B0Strc;
struct D2DeviceVtbl006B77B0Strc
{
    void* unk_00[28];
    long (__stdcall* DrawPrimitive)(D2Device006B77B0Strc* pDevice, int nPrimitiveType, unsigned long dwFVF, void* pVertices, unsigned long nVertices, unsigned long dwFlags);
};
struct D2Device006B77B0Strc
{
    D2DeviceVtbl006B77B0Strc* lpVtbl;
};

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern D2Device006B77B0Strc* gpDevice_00970E78; // 0x00970E78
unsigned int __fastcall sub_006B1D50_GetColor(unsigned int index); // 0x006B1D50
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlend(int nBlend); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030

static __forceinline int sub_006B77B0_Clip(int nValue, int nSize)
{
    int nClipped = nValue > 0 ? nValue : 0;
    return nClipped < nSize - 1 ? nClipped : nSize - 1;
}

// 0x006B77B0
void __fastcall sub_006B77B0_Call(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nMode)
{
    nX1 = sub_006B77B0_Clip(nX1, gnScreenWidth_007C9138);
    nX2 = sub_006B77B0_Clip(nX2, gnScreenWidth_007C9138);
    if (nX1 == nX2)
        return;

    nY1 = sub_006B77B0_Clip(nY1, gnScreenHeight_007C913C);
    nY2 = sub_006B77B0_Clip(nY2, gnScreenHeight_007C913C);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x2B);

    sub_006B1EA0_SetState(2);
    sub_006B1F40_SetBlend(4);
    sub_006B2030_SetFilterMode(1);

    D2TLVertex006B77B0Strc tVertices[4];
    tVertices[0].fX = (float)nX1;
    tVertices[0].fY = (float)nY1;
    tVertices[0].fZ = 0.5f;
    tVertices[0].fRhw = 1.0f;
    tVertices[0].fU = 0.0f;
    tVertices[0].fV = 0.0f;
    tVertices[1].fX = (float)nX1;
    tVertices[1].fY = (float)nY2;
    tVertices[1].fZ = 0.5f;
    tVertices[1].fRhw = 1.0f;
    tVertices[1].fU = 0.0f;
    tVertices[1].fV = 0.0f;
    tVertices[2].fX = (float)nX2;
    tVertices[2].fY = (float)nY2;
    tVertices[2].fZ = 0.5f;
    tVertices[2].fRhw = 1.0f;
    tVertices[2].fU = 0.0f;
    tVertices[2].fV = 0.0f;
    tVertices[3].fX = (float)nX2;
    tVertices[3].fY = (float)nY1;
    tVertices[3].fZ = 0.5f;
    tVertices[3].fRhw = 1.0f;
    tVertices[3].fU = 0.0f;
    tVertices[3].fV = 0.0f;

    unsigned int dwColor = sub_006B1D50_GetColor(nColor) & 0xFFFFFF;
    switch (nMode)
    {
    case 0:
        dwColor |= 0x40000000;
        break;
    case 1:
        dwColor |= 0x80000000;
        break;
    case 2:
        dwColor |= 0xC0000000;
        break;
    default:
        dwColor |= 0xFF000000;
        break;
    }

    tVertices[0].dwColor = dwColor;
    tVertices[1].dwColor = dwColor;
    tVertices[2].dwColor = dwColor;
    tVertices[3].dwColor = dwColor;
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, tVertices, 4, 0x1C);
}
