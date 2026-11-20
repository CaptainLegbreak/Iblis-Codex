#include "D2Direct3D.h"

void __fastcall sub_006B9BB0_CloseSmack(D2SmackRecordStrc* video); // 0x006B9BB0
void __cdecl sub_006B9BD0_Apply(); // 0x006B9BD0
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
D2TLVertexStrc gVideoVertices_00989750[4];        // 0x00989750
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int nState); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030

// 0x006B9C40
static void __stdcall sub_006B9C40_BlitVideo(D2SmackRecordStrc* video, int width, int height)
{
    const int top = video->nY - height;
    const int bottom = video->nY;
    sub_006B1EA0_SetState(1);
    sub_006B1F40_SetBlendMode(1);
    sub_006B2030_SetFilterMode(1);

    int x = video->nX;
    int right = x + 256;
    gVideoVertices_00989750[0].fX = (float)x;
    gVideoVertices_00989750[0].fY = (float)top;
    gVideoVertices_00989750[0].fZ = 0.5f;
    gVideoVertices_00989750[0].fRhw = 1.0f;
    gVideoVertices_00989750[0].fU = 0.0f;
    gVideoVertices_00989750[0].fV = 0.0f;
    gVideoVertices_00989750[1].fX = (float)x;
    gVideoVertices_00989750[1].fY = (float)bottom;
    gVideoVertices_00989750[1].fZ = 0.5f;
    gVideoVertices_00989750[1].fRhw = 1.0f;
    gVideoVertices_00989750[1].fU = 0.0f;
    gVideoVertices_00989750[1].fV = 1.0f;
    gVideoVertices_00989750[2].fX = (float)right;
    gVideoVertices_00989750[2].fY = (float)bottom;
    gVideoVertices_00989750[2].fZ = 0.5f;
    gVideoVertices_00989750[2].fRhw = 1.0f;
    gVideoVertices_00989750[2].fU = 1.0f;
    gVideoVertices_00989750[2].fV = 1.0f;
    gVideoVertices_00989750[3].fX = (float)right;
    gVideoVertices_00989750[3].fY = (float)top;
    gVideoVertices_00989750[3].fZ = 0.5f;
    gVideoVertices_00989750[3].fRhw = 1.0f;
    gVideoVertices_00989750[3].fU = 1.0f;
    gVideoVertices_00989750[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[0]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);

    x += 256;
    right = x + width - 256;
    const float u = (float)((width - 256) * (1.0 / 256.0));
    gVideoVertices_00989750[0].fX = (float)x;
    gVideoVertices_00989750[0].fY = (float)top;
    gVideoVertices_00989750[0].fZ = 0.5f;
    gVideoVertices_00989750[0].fRhw = 1.0f;
    gVideoVertices_00989750[0].fU = 0.0f;
    gVideoVertices_00989750[0].fV = 0.0f;
    gVideoVertices_00989750[1].fX = (float)x;
    gVideoVertices_00989750[1].fY = (float)bottom;
    gVideoVertices_00989750[1].fZ = 0.5f;
    gVideoVertices_00989750[1].fRhw = 1.0f;
    gVideoVertices_00989750[1].fU = 0.0f;
    gVideoVertices_00989750[1].fV = 1.0f;
    gVideoVertices_00989750[2].fX = (float)right;
    gVideoVertices_00989750[2].fY = (float)bottom;
    gVideoVertices_00989750[2].fZ = 0.5f;
    gVideoVertices_00989750[2].fRhw = 1.0f;
    gVideoVertices_00989750[2].fU = u;
    gVideoVertices_00989750[2].fV = 1.0f;
    gVideoVertices_00989750[3].fX = (float)right;
    gVideoVertices_00989750[3].fY = (float)top;
    gVideoVertices_00989750[3].fZ = 0.5f;
    gVideoVertices_00989750[3].fRhw = 1.0f;
    gVideoVertices_00989750[3].fU = u;
    gVideoVertices_00989750[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[1]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);
}

// 0x006BA390
void __fastcall sub_006BA390_PlaySmack(D2SmackRecordStrc* pVideo)
{
    switch (pVideo->nType)
    {
    case 's':
    {
        D2SmackStrc* pSmack = (D2SmackStrc*)pVideo->hSmack;
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
            if (pSmack->nFrameNum == pSmack->nFrames)
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
            sub_006B9C40_BlitVideo(pVideo, pSmack->nWidth, pSmack->nHeight);
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
