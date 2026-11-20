#include "D2Glide.h"
#include "D2CelContext.h"


struct D2GlideTexInfoStrc
{
	D2CelContextStrc* pData;
	int nWidth;
	int nHeight;
	int nOffsetX;
	int nOffsetY;
	int nTexWidth;
	int nTexHeight;
	int nTexArea;
	float fS0;
	float fS1;
	float fT0;
	float fT1;
	int nLod;
	int nAspect;
};

struct D2GlideVtxStrc
{
	float fX;
	float fY;
	unsigned int dwColor;
	float fOow;
	float fSow;
	float fTow;
	int unk0x18;
};

struct D2GlideAspectScaleStrc
{
	int nScaleS;
	int nScaleT;
};
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

int __stdcall sub_006001F0(D2CelContextStrc* pData, int nArg2, int nArg3);                                  // 0x006001F0
int __stdcall sub_00601B10_GetCelPixels(D2CelStrc* pCel);                                                  // 0x00601B10
void __fastcall sub_005094B0_GlideSetState(int nState);                                                     // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nCombine);                                                 // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nDepth);                                                     // 0x005095D0
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideVtxStrc* pVertex, unsigned int dwColor);         // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective();                                                              // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);         // 0x0050DD60

extern D2GlideAspectScaleStrc gGlideAspectScale_0072F290[];                                                 // 0x0072F290
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfnGrGlideState_0087EAB4)(int nState);                                             // 0x0087EAB4
extern D2GlideVtxStrc gGlideVertices_0087EFF8[4];                                                        // 0x0087EFF8

static int __declspec(noinline) sub_0050A260_GlideTexInfoInit(D2CelContextStrc* pData, D2GlideTexInfoStrc* pInfo);
static void __declspec(noinline) sub_0050A2D0_GlideTexInfoSetupSize(D2GlideTexInfoStrc* pInfo);             // 0x0050A2D0
static int __declspec(noinline) __stdcall sub_0050A450_UploadSprite(D2GlideTexInfoStrc* pInfo, unsigned char* pPalette, int nArg2, int nArg3); // 0x0050A450
static void __declspec(noinline) sub_0050ABF0_GlideSetBlendMode(int nDrawMode);                             // 0x0050ABF0

// 0x0050A260
static int sub_0050A260_GlideTexInfoInit(D2CelContextStrc* pData, D2GlideTexInfoStrc* pInfo)
{
	if (!sub_006001F0(pData, 0, 1))
	{
		return 0;
	}

	D2_ASSERT(pData->pCel, 206);

	pInfo->pData = pData;
	pInfo->nWidth = sub_006018C0(pData->pCel);
	pInfo->nOffsetX = sub_00601920(pData->pCel);
	pInfo->nHeight = sub_006018F0(pData->pCel);
	pInfo->nOffsetY = sub_00601950(pData->pCel);
	return 1;
}

// build: context sub_0050A2D0_GlideTexInfoSetupSize
// calling-convention shim (not game code)
static void sub_0050A2D0_GlideTexInfoSetupSize(D2GlideTexInfoStrc* pInfo)
{
	D2CelContextStrc* pData = pInfo->pData;
	sub_006018C0(pData->pCel);
	sub_006018F0(pData->pCel);
	sub_00601920(pData->pCel);
	pInfo->nTexArea = sub_00601950(pData->pCel);
}

// build: context sub_0050A450_UploadSprite
// calling-convention shim (not game code)
static int __stdcall sub_0050A450_UploadSprite(D2GlideTexInfoStrc* pInfo, unsigned char* pPalette, int nArg2, int nArg3)
{
	int nResult = sub_00601B10_GetCelPixels(pInfo->pData->pCel);
	pInfo->nTexArea = nResult;
	return nResult + (int)pPalette + nArg2 + nArg3 + pInfo->nWidth;
}

// build: context sub_0050ABF0_GlideSetBlendMode
// calling-convention shim (not game code)
static void sub_0050ABF0_GlideSetBlendMode(int nDrawMode)
{
	sub_00509500_GlideSetCombine(4);
	if (nDrawMode == 0)
	{
		sub_00509500_GlideSetCombine(1);
	}
	else if (nDrawMode == 1)
	{
		sub_00509500_GlideSetCombine(2);
	}
	else if (nDrawMode == 2)
	{
		sub_00509500_GlideSetCombine(3);
	}
}

// 0x0050ACC0
int __fastcall sub_0050ACC0_DrawFlatSprite(D2CelContextStrc* pData, int nX, int nY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
	D2GlideTexInfoStrc tInfo;
	int nScreenX;
	int nScreenY;

	if (!sub_0050A260_GlideTexInfoInit(pData, &tInfo))
	{
		return 0;
	}

	sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);

	const int nScaleS = gGlideAspectScale_0072F290[tInfo.nAspect].nScaleS;
	const int nScaleT = gGlideAspectScale_0072F290[tInfo.nAspect].nScaleT;
	const float fS0 = nScaleS * tInfo.fS0;
	const float fS1 = nScaleS * tInfo.fS1;
	const float fT0 = nScaleT * tInfo.fT0;
	const float fT1 = nScaleT * tInfo.fT1;

	int nWidth;
	int nHeight;
	if (!sub_0050DD30_GlideIsPerspective())
	{
		nWidth = tInfo.nWidth << 11;
		nHeight = tInfo.nHeight << 12;
	}
	else
	{
		nWidth = tInfo.nTexWidth << 11;
		nHeight = tInfo.nTexHeight << 12;
	}

	const int nOffsetX = tInfo.nOffsetX << 11;
	const int nOffsetY = tInfo.nOffsetY << 12;
	nX += nOffsetY + nOffsetX;
	nY += nOffsetY - nOffsetX;

	sub_0050DD60_ProjectToScreen(nX - nHeight, nY - nHeight, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[0].fX = (float)nScreenX;
	gGlideVertices_0087EFF8[0].fY = (float)nScreenY;
	gGlideVertices_0087EFF8[0].fOow = 1.0f;
	gGlideVertices_0087EFF8[0].fSow = fS0;
	gGlideVertices_0087EFF8[0].fTow = fT0;

	sub_0050DD60_ProjectToScreen(nX, nY, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[1].fX = (float)nScreenX;
	gGlideVertices_0087EFF8[1].fY = (float)nScreenY;
	gGlideVertices_0087EFF8[1].fOow = 1.0f;
	gGlideVertices_0087EFF8[1].fSow = fS0;
	gGlideVertices_0087EFF8[1].fTow = fT1;

	sub_0050DD60_ProjectToScreen(nX + nWidth, nY - nWidth, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[2].fX = (float)nScreenX;
	gGlideVertices_0087EFF8[2].fY = (float)nScreenY;
	gGlideVertices_0087EFF8[2].fOow = 1.0f;
	gGlideVertices_0087EFF8[2].fSow = fS1;
	gGlideVertices_0087EFF8[2].fTow = fT1;

	sub_0050DD60_ProjectToScreen(nX + nWidth - nHeight, nY - nHeight - nWidth, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[3].fX = (float)nScreenX;
	gGlideVertices_0087EFF8[3].fY = (float)nScreenY;
	gGlideVertices_0087EFF8[3].fOow = 1.0f;
	gGlideVertices_0087EFF8[3].fSow = fS1;
	gGlideVertices_0087EFF8[3].fTow = fT0;

	const int nShift = gnScreenWidth_007C9138 / 4;
	if (nScreenMode == 1)
	{
		const float fShift = (float)nShift;
		gGlideVertices_0087EFF8[0].fX -= fShift;
		gGlideVertices_0087EFF8[1].fX -= fShift;
		gGlideVertices_0087EFF8[2].fX -= fShift;
		gGlideVertices_0087EFF8[3].fX -= fShift;
	}
	else if (nScreenMode == 2)
	{
		const float fShift = (float)nShift;
		gGlideVertices_0087EFF8[0].fX += fShift;
		gGlideVertices_0087EFF8[1].fX += fShift;
		gGlideVertices_0087EFF8[2].fX += fShift;
		gGlideVertices_0087EFF8[3].fX += fShift;
	}

	const int nScreenWidth = gnScreenWidth_007C9138;
	const int nScreenHeight = gnScreenHeight_007C913C - 47;
	if ((gGlideVertices_0087EFF8[0].fX >= 0.0f && gGlideVertices_0087EFF8[0].fX < nScreenWidth && gGlideVertices_0087EFF8[0].fY >= 0.0f && gGlideVertices_0087EFF8[0].fY < nScreenHeight)
		|| (gGlideVertices_0087EFF8[1].fX >= 0.0f && gGlideVertices_0087EFF8[1].fX < nScreenWidth && gGlideVertices_0087EFF8[1].fY >= 0.0f && gGlideVertices_0087EFF8[1].fY < nScreenHeight)
		|| (gGlideVertices_0087EFF8[2].fX >= 0.0f && gGlideVertices_0087EFF8[2].fX < nScreenWidth && gGlideVertices_0087EFF8[2].fY >= 0.0f && gGlideVertices_0087EFF8[2].fY < nScreenHeight)
		|| (gGlideVertices_0087EFF8[3].fX >= 0.0f && gGlideVertices_0087EFF8[3].fX < nScreenWidth && gGlideVertices_0087EFF8[3].fY >= 0.0f && gGlideVertices_0087EFF8[3].fY < nScreenHeight))
	{
		if (!sub_0050A450_UploadSprite(&tInfo, pPalette, 0, 1))
		{
			return 1;
		}

		sub_0050ABF0_GlideSetBlendMode(eDrawMode);
		sub_005094B0_GlideSetState(1);
		sub_005095D0_GlideSetDepth(1);
		sub_0050DC30_GlideSetVertexColor(gGlideVertices_0087EFF8, dwGamma);
		gGlideVertices_0087EFF8[1].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gGlideVertices_0087EFF8[2].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gGlideVertices_0087EFF8[3].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gpfnGrDrawVertexArrayContiguous_0087EAC4(5, 4, gGlideVertices_0087EFF8, sizeof(D2GlideVtxStrc));
		gpfnGrGlideState_0087EAB4(2);
		return 1;
	}

	return 1;
}
