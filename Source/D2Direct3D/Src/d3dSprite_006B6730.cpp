#include "D2Direct3D.h"
#include "D2D3DTypes.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"

struct D2CelStrc;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                          // 0x00410610
int __stdcall sub_006001F0(D2GfxDataStrc* pData, int nArg2, int nArg3);                                     // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                                // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                                // 0x00601950
int __stdcall sub_00601B10_GetCelPixels(D2CelStrc* pCel);                                                  // 0x00601B10

void __fastcall sub_006B1EA0_SetState(int nState);                                                          // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int nBlendMode);                                                  // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nFilterMode);                                                // 0x006B2030
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int dwColor, unsigned char nAlpha); // 0x006B9780
void __fastcall sub_006B9860_Project(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);                  // 0x006B9860
extern D2VertexBufferStrc* gpVertexBuffer_00970F3C;                                                      // 0x00970F3C
extern int gnVertexBufferPos_00970F40;                                                                      // 0x00970F40

static int __declspec(noinline) sub_006B5C80_GetSpriteInfo(D2GfxDataStrc* pData, D2SpriteInfoStrc* pInfo);
static void __declspec(noinline) sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static int __declspec(noinline) __stdcall sub_006B5D40_UploadSprite(D2SpriteInfoStrc* pInfo, int nType, unsigned char* pPalette, int nUnused); // 0x006B5D40
static unsigned char __declspec(noinline) sub_006B6680_GetAlpha(int nDrawMode);

// 0x006B5C80
static int sub_006B5C80_GetSpriteInfo(D2GfxDataStrc* pData, D2SpriteInfoStrc* pInfo)
{
	if (!sub_006001F0(pData, 0, 1))
	{
		return 0;
	}

	if (!pData->pCel)
	{
		sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", pData->nUnitType, pData->nUnitIndex, pData->nMode, pData->pOverlays);
		return 0;
	}

	pInfo->pContext = (D2CelContextStrc*)pData;
	pInfo->nWidth = sub_006018C0(pData->pCel);
	pInfo->nOffsetX = sub_00601920(pData->pCel);
	pInfo->nHeight = sub_006018F0(pData->pCel);
	pInfo->nOffsetY = sub_00601950(pData->pCel);
	return 1;
}

// 0x006B5CF0
static void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo)
{
	if (pInfo->nWidth <= 32 && pInfo->nHeight <= 32)
	{
		pInfo->nTexWidth = 32;
		pInfo->nTexHeight = 32;
	}
	else if (pInfo->nWidth <= 128 && pInfo->nHeight <= 128)
	{
		pInfo->nTexWidth = 128;
		pInfo->nTexHeight = 128;
	}
	else if (pInfo->nWidth <= 256 && pInfo->nHeight <= 256)
	{
		pInfo->nTexWidth = 256;
		pInfo->nTexHeight = 256;
	}

	pInfo->nTexSize = pInfo->nTexWidth * pInfo->nTexHeight;
	pInfo->fU0 = 0.0f;
	pInfo->fU1 = 1.0f;
	pInfo->fV0 = 0.0f;
	pInfo->fV1 = 1.0f;
}

// build: context sub_006B5D40_UploadSprite
// calling-convention shim (not game code)
static int __stdcall sub_006B5D40_UploadSprite(D2SpriteInfoStrc* pInfo, int nType, unsigned char* pPalette, int nFlags)
{
	int nResult = sub_00601B10_GetCelPixels(pInfo->pContext->pCel);
	if (nType == 4)
	{
		nType = 1;
	}
	pInfo->nWidth = nResult;
	D2SpriteInfoStrc* pNext = (D2SpriteInfoStrc*)pInfo->pContext;
	nResult = sub_00601B10_GetCelPixels(pNext->pContext->pCel);
	pNext->nWidth = nResult + nType;
	return (int)pPalette + nFlags;
}

// 0x006B6680
static unsigned char sub_006B6680_GetAlpha(int nDrawMode)
{
	unsigned char nAlpha = 0xFF;

	switch (nDrawMode)
	{
	case 5:
	case 7:
		sub_006B1F40_SetBlendMode(1);
		break;

	case 3:
		sub_006B1F40_SetBlendMode(2);
		break;

	case 4:
		sub_006B1F40_SetBlendMode(3);
		break;

	default:
		sub_006B1F40_SetBlendMode(4);
		if (nDrawMode == 0)
		{
			nAlpha = 0x40;
		}
		else if (nDrawMode == 1)
		{
			nAlpha = 0x80;
		}
		else if (nDrawMode == 2)
		{
			nAlpha = 0xC0;
		}
		break;
	}

	return nAlpha;
}

// 0x006B6730
int __fastcall sub_006B6730_DrawFlatSprite(D2GfxDataStrc* pData, int nX, int nY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
	D2SpriteInfoStrc tInfo;
	D2TLVertexStrc pVertices[4];
	int nScreenX;
	int nScreenY;

	if (!sub_006B5C80_GetSpriteInfo(pData, &tInfo))
	{
		return 0;
	}

	sub_006B5CF0_SetTextureSize(&tInfo);

	const int nOffsetX = tInfo.nOffsetX << 11;
	const int nOffsetY = tInfo.nOffsetY << 12;
	nX += nOffsetY + nOffsetX;
	nY += nOffsetY - nOffsetX;
	const int nHeight = tInfo.nTexHeight << 12;
	const int nWidth = tInfo.nTexWidth << 11;
	const int nTopY = nY - nHeight;

	sub_006B9860_Project(nX - nHeight, nTopY, 0, &nScreenX, &nScreenY);
	pVertices[0].fX = (float)nScreenX;
	pVertices[0].fY = (float)nScreenY;
	pVertices[0].fZ = 0.5f;
	pVertices[0].fRhw = 1.0f;
	pVertices[0].fU = tInfo.fU0;
	pVertices[0].fV = tInfo.fV0;

	sub_006B9860_Project(nX, nY, 0, &nScreenX, &nScreenY);
	pVertices[1].fX = (float)nScreenX;
	pVertices[1].fY = (float)nScreenY;
	pVertices[1].fZ = 0.5f;
	pVertices[1].fRhw = 1.0f;
	pVertices[1].fU = tInfo.fU0;
	pVertices[1].fV = tInfo.fV1;

	sub_006B9860_Project(nX + nWidth, nY - nWidth, 0, &nScreenX, &nScreenY);
	pVertices[2].fX = (float)nScreenX;
	pVertices[2].fY = (float)nScreenY;
	pVertices[2].fZ = 0.5f;
	pVertices[2].fRhw = 1.0f;
	pVertices[2].fU = tInfo.fU1;
	pVertices[2].fV = tInfo.fV1;

	sub_006B9860_Project(nX + nWidth - nHeight, nTopY - nWidth, 0, &nScreenX, &nScreenY);
	pVertices[3].fX = (float)nScreenX;
	pVertices[3].fY = (float)nScreenY;
	pVertices[3].fZ = 0.5f;
	pVertices[3].fRhw = 1.0f;
	pVertices[3].fU = tInfo.fU1;
	pVertices[3].fV = tInfo.fV0;

	switch (nScreenMode)
	{
	case 1:
	{
		const float fShift = (float)(gnScreenWidth_007C9138 / 4);
		pVertices[0].fX -= fShift;
		pVertices[1].fX -= fShift;
		pVertices[2].fX -= fShift;
		pVertices[3].fX -= fShift;
		break;
	}
	case 2:
	{
		const float fShift = (float)(gnScreenWidth_007C9138 / 4);
		pVertices[0].fX += fShift;
		pVertices[1].fX += fShift;
		pVertices[2].fX += fShift;
		pVertices[3].fX += fShift;
		break;
	}
	}

	const int nScreenWidth = gnScreenWidth_007C9138;
	const int nScreenHeight = gnScreenHeight_007C913C - 47;
	if ((pVertices[0].fX >= 0.0f && pVertices[0].fX < nScreenWidth && pVertices[0].fY >= 0.0f && pVertices[0].fY < nScreenHeight)
		|| (pVertices[1].fX >= 0.0f && pVertices[1].fX < nScreenWidth && pVertices[1].fY >= 0.0f && pVertices[1].fY < nScreenHeight)
		|| (pVertices[2].fX >= 0.0f && pVertices[2].fX < nScreenWidth && pVertices[2].fY >= 0.0f && pVertices[2].fY < nScreenHeight)
		|| (pVertices[3].fX >= 0.0f && pVertices[3].fX < nScreenWidth && pVertices[3].fY >= 0.0f && pVertices[3].fY < nScreenHeight))
	{
		const unsigned char nAlpha = sub_006B6680_GetAlpha(eDrawMode);
		if (!sub_006B5D40_UploadSprite(&tInfo, 1, pPalette, 0))
		{
			return 1;
		}

		sub_006B1EA0_SetState(1);
		sub_006B2030_SetFilterMode(1);
		sub_006B9780_SetColor(pVertices, dwGamma, nAlpha);
		pVertices[1].dwColor = pVertices[0].dwColor;
		pVertices[2].dwColor = pVertices[0].dwColor;
		pVertices[3].dwColor = pVertices[0].dwColor;

		D2TLVertexStrc* pLocked;
		if (gpVertexBuffer_00970F3C->lpVtbl->Lock(gpVertexBuffer_00970F3C, 0x21, (void**)&pLocked, 0))
		{
			return 1;
		}

		pLocked += gnVertexBufferPos_00970F40;
		memcpy(pLocked, pVertices, sizeof(pVertices));
		gpVertexBuffer_00970F3C->lpVtbl->Unlock(gpVertexBuffer_00970F3C);
		gpD3DDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpD3DDevice_00970E78, 6, gpVertexBuffer_00970F3C, gnVertexBufferPos_00970F40, 4, 0x1C);

		gnVertexBufferPos_00970F40 += 4;
		if (gnVertexBufferPos_00970F40 > 43)
		{
			gnVertexBufferPos_00970F40 = 0;
			return 1;
		}
	}

	return 1;
}
