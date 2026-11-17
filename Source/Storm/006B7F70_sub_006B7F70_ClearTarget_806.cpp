struct D2D3DRect006B7F70Strc
{
    long x1;
    long y1;
    long x2;
    long y2;
};
struct D2Direct3DDevice006B7F70Strc;
struct D2Direct3DDeviceVtbl006B7F70Strc
{
    void* unk_00[20];
    long (__stdcall* Clear)(D2Direct3DDevice006B7F70Strc* pDevice, unsigned long nCount, const D2D3DRect006B7F70Strc* pRects, unsigned long nFlags, unsigned long nColor, float fZ, unsigned long nStencil);
};
struct D2Direct3DDevice006B7F70Strc
{
    D2Direct3DDeviceVtbl006B7F70Strc* lpVtbl;
};
extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern D2Direct3DDevice006B7F70Strc* gpDevice_00970E7C; // 0x00970E7C
void __cdecl sub_006B3800_Flush(); // 0x006B3800

// 0x006B7F70
void __cdecl sub_006B7F70_ClearTarget()
{
    if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
    {
        sub_006B3800_Flush();
        return;
    }
    D2D3DRect006B7F70Strc tRect;
    tRect.x1 = 0;
    tRect.y1 = 0;
    tRect.x2 = gnWidth_007C9138;
    tRect.y2 = gnHeight_007C913C;
    gpDevice_00970E7C->lpVtbl->Clear(gpDevice_00970E7C, 1, &tRect, 1, 0xFF000000, 0.0f, 0);
}
