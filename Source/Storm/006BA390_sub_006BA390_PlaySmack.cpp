struct D2SmackStrc
{
    unsigned int Version;
    unsigned int Width;
    unsigned int Height;
    unsigned int Frames;
    unsigned char unknown_0010[0x364];
    unsigned int FrameNum;
};
struct D2VideoHandleStrc
{
    D2SmackStrc* handle;
    char type;
    unsigned char pad_0005[3];
    int x;
    int y;
};
extern "C" __declspec(dllimport) unsigned int __stdcall SmackWait(D2SmackStrc* smack); // 0x006CC5F8
extern "C" __declspec(dllimport) unsigned int __stdcall SmackDoFrame(D2SmackStrc* smack); // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* smack); // 0x006CC600
void __fastcall sub_006B9BB0_CloseSmack(D2VideoHandleStrc* video); // 0x006B9BB0
void __cdecl sub_006B9BD0_Apply(); // 0x006B9BD0
void __stdcall sub_006B9F00_PresentFrame(); // 0x006B9F00
extern void* ghDDrawWindow_007C9140; // 0x007C9140
extern int gbRenderPaused_007C9144; // 0x007C9144

struct D2VideoBlitVertex
{
    float x, y, z, rhw;
    unsigned int color, specular;
    float u, v;
};
struct D2VideoBlitDevice;
struct D2VideoBlitDeviceVtbl
{
    void* slots_0000[28];
    long (__stdcall* DrawPrimitive)(D2VideoBlitDevice*, unsigned int,
        unsigned int, void*, unsigned int, unsigned int);
    void* slots_0074[9];
    long (__stdcall* SetTexture)(D2VideoBlitDevice*, unsigned int, void*);
};
struct D2VideoBlitDevice { D2VideoBlitDeviceVtbl* lpVtbl; };
extern D2VideoBlitDevice* gpDevice_00970E78; // 0x00970E78
D2VideoBlitVertex gVideoVertices_00989750[4];        // 0x00989750
extern void* gpArray_009897EC[2]; // 0x009897EC
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int nState); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030

// 0x006B9C40
static void __stdcall sub_006B9C40_BlitVideo(D2VideoHandleStrc* video, int width, int height)
{
    const int top = video->y - height;
    const int bottom = video->y;
    sub_006B1EA0_SetState(1);
    sub_006B1F40_SetBlendMode(1);
    sub_006B2030_SetFilterMode(1);

    int x = video->x;
    int right = x + 256;
    gVideoVertices_00989750[0].x = (float)x;
    gVideoVertices_00989750[0].y = (float)top;
    gVideoVertices_00989750[0].z = 0.5f;
    gVideoVertices_00989750[0].rhw = 1.0f;
    gVideoVertices_00989750[0].u = 0.0f;
    gVideoVertices_00989750[0].v = 0.0f;
    gVideoVertices_00989750[1].x = (float)x;
    gVideoVertices_00989750[1].y = (float)bottom;
    gVideoVertices_00989750[1].z = 0.5f;
    gVideoVertices_00989750[1].rhw = 1.0f;
    gVideoVertices_00989750[1].u = 0.0f;
    gVideoVertices_00989750[1].v = 1.0f;
    gVideoVertices_00989750[2].x = (float)right;
    gVideoVertices_00989750[2].y = (float)bottom;
    gVideoVertices_00989750[2].z = 0.5f;
    gVideoVertices_00989750[2].rhw = 1.0f;
    gVideoVertices_00989750[2].u = 1.0f;
    gVideoVertices_00989750[2].v = 1.0f;
    gVideoVertices_00989750[3].x = (float)right;
    gVideoVertices_00989750[3].y = (float)top;
    gVideoVertices_00989750[3].z = 0.5f;
    gVideoVertices_00989750[3].rhw = 1.0f;
    gVideoVertices_00989750[3].u = 1.0f;
    gVideoVertices_00989750[3].v = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[0]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);

    x += 256;
    right = x + width - 256;
    const float u = (float)((width - 256) * (1.0 / 256.0));
    gVideoVertices_00989750[0].x = (float)x;
    gVideoVertices_00989750[0].y = (float)top;
    gVideoVertices_00989750[0].z = 0.5f;
    gVideoVertices_00989750[0].rhw = 1.0f;
    gVideoVertices_00989750[0].u = 0.0f;
    gVideoVertices_00989750[0].v = 0.0f;
    gVideoVertices_00989750[1].x = (float)x;
    gVideoVertices_00989750[1].y = (float)bottom;
    gVideoVertices_00989750[1].z = 0.5f;
    gVideoVertices_00989750[1].rhw = 1.0f;
    gVideoVertices_00989750[1].u = 0.0f;
    gVideoVertices_00989750[1].v = 1.0f;
    gVideoVertices_00989750[2].x = (float)right;
    gVideoVertices_00989750[2].y = (float)bottom;
    gVideoVertices_00989750[2].z = 0.5f;
    gVideoVertices_00989750[2].rhw = 1.0f;
    gVideoVertices_00989750[2].u = u;
    gVideoVertices_00989750[2].v = 1.0f;
    gVideoVertices_00989750[3].x = (float)right;
    gVideoVertices_00989750[3].y = (float)top;
    gVideoVertices_00989750[3].z = 0.5f;
    gVideoVertices_00989750[3].rhw = 1.0f;
    gVideoVertices_00989750[3].u = u;
    gVideoVertices_00989750[3].v = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[1]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);
}

// 0x006BA390
void __fastcall sub_006BA390_PlaySmack(D2VideoHandleStrc* pVideo)
{
    switch (pVideo->type)
    {
    case 's':
    {
        D2SmackStrc* pSmack = pVideo->handle;
        if (!pSmack)
        {
            return;
        }

        if (!SmackWait(pSmack))
        {
            if (!ghDDrawWindow_007C9140)
            {
                return;
            }

            SmackDoFrame(pSmack);
            sub_006B9F00_PresentFrame();
            if (pSmack->FrameNum == pSmack->Frames)
            {
                sub_006B9BB0_CloseSmack(pVideo);
            }
            else
            {
                SmackNextFrame(pSmack);
            }

            if (gbRenderPaused_007C9144)
            {
                return;
            }
            sub_006B9BD0_Apply();
        }

        if (!gbRenderPaused_007C9144)
        {
            sub_006B9C40_BlitVideo(pVideo, pSmack->Width, pSmack->Height);
        }
        break;
    }

    case 'p':
        if (!gbRenderPaused_007C9144)
        {
            sub_006B9C40_BlitVideo(pVideo, 468, 60);
        }
        break;
    }
}
