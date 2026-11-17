struct D2DDBltFxStrc
{
    unsigned int dwSize;
    unsigned int unk0x04[19];
    unsigned int dwFillColor;
    unsigned int unk0x54[4];
};

struct D2DDrawSurfaceStrc;

struct D2DDrawSurfaceVtblStrc
{
    void* unk0x00[5];
    long (__stdcall* Blt)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDrawSurfaceStrc* pSrcSurface, void* pSrcRect, unsigned long dwFlags, D2DDBltFxStrc* pBltFx);
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __fastcall sub_005103B0(const char* szText, long nResult); // 0x005103B0
extern int gnScreenHeight_007C913C; // 0x007C913C
extern int gnScreenWidth_007C9138; // 0x007C9138
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881280; // 0x00881280

// 0x00512ED0
void __fastcall sub_00512ED0_ClearScreen(int bPartial)
{
    D2DDBltFxStrc tBltFx = { sizeof(D2DDBltFxStrc) };
    tBltFx.dwFillColor = 0;

    if (gpDDrawSurface_00881280)
    {
        long nResult = gpDDrawSurface_00881280->lpVtbl->Blt(gpDDrawSurface_00881280, 0, 0, 0, 0x400, &tBltFx);
        if (nResult)
        {
            if (nResult == 0x887601AE)
            {
                if (bPartial)
                {
                    memset(gpScreenBuffer_007C9154, 0, gnScreenWidth_007C9138 * (gnScreenHeight_007C913C - 47));
                }
                else
                {
                    memset(gpScreenBuffer_007C9154, 0, gnScreenWidth_007C9138 * gnScreenHeight_007C913C);
                }
            }
            else
            {
                sub_005103B0("Blit (screen clear) failed!", nResult);
            }
        }
    }
}
