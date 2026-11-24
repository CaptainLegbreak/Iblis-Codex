#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2ClientSound.h"
#include "D2SoundEnvironTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SoundUnitNodeStrc;
struct Unicode;
struct D2RectStrc;
struct D2DialogLineStrc;
struct D2SoundVecStrc;
struct D2SoundEnvironTxtStrc;
struct D2SoundNodeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnScreenWidth; // 0x0071146C
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

#pragma pack(push, 1)
struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    int f_1C;
    float fPan;
    int nArg4;
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
    unsigned int f_34;
    int nArg3;
    unsigned char nPriority;
    int bLocked;
    char unk0x41[0x18];
};

#pragma pack(pop)
extern D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458
extern int gbClientSoundReady; // 0x007C545C
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890
D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax); // 0x004B93A0
float __stdcall GFXUTIL_VectorLengthSquared(float fX, float fY); // 0x004E4160
void __fastcall D2SOUNDUTIL_ListAddHead(D2SoundUnitNodeStrc** ppList, D2UnitStrc* pUnit); // 0x00516950
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900


static void sub_004B83A0_PlaceLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    int nOldFont = D2Win_10127_SetFont(1);
    D2Win_10127_SetFont(pDialog->pLines[nIndex].nFont);
    int nWidth = D2Win_10121_GetTextWidth(pDialog->pLines[nIndex].wszText);
    if (nWidth >= pDialog->nWidth)
    {
        pDialog->pLines[nIndex].nWidth = nWidth;
        pDialog->pLines[nIndex].nX = 0;
    }
    else
    {
        pDialog->pLines[nIndex].nWidth = nWidth;
        pDialog->pLines[nIndex].nX = (pDialog->nWidth - nWidth + 1) / 2 + 1;
    }
    D2Win_10127_SetFont(nOldFont);
}

// 0x004B8410
void __fastcall sub_004B8410_LayoutDialog(D2ClientDialogStrc* pDialog)
{
    int nMaxWidth = 0;
    int nHeight = 0;
    D2_ASSERT(pDialog->bAutoSize, 0x59F);
    int nOldFont = D2Win_10127_SetFont(1);
    int nDisabled = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        int nWidth = D2Win_10121_GetTextWidth(pDialog->pLines[i].wszText);
        if (nWidth > nMaxWidth)
            nMaxWidth = nWidth;
        if (!pDialog->pLines[i].bEnabled)
            ++nDisabled;
        nHeight += pDialog->pLines[i].nHeight;
    }
    nMaxWidth += 0x14;
    nHeight += 0xF;
    D2Win_10127_SetFont(nOldFont);
    pDialog->nX = pDialog->nCenterX - nMaxWidth / 2;
    if (pDialog->bCountEnabled)
        pDialog->nY = pDialog->nCenterY - nDisabled * 0x15;
    else
        pDialog->nY = pDialog->nCenterY - nHeight / 3;
    D2_ASSERT(nMaxWidth <= gnScreenWidth - 0x50, 0x5D2);
    D2_ASSERT(nHeight <= gnScreenHeight - 0x62, 0x5D7);
    if (pDialog->nX + nMaxWidth > gnScreenWidth - 0xA)
        pDialog->nX = gnScreenWidth - nMaxWidth;
    if (pDialog->nY + nHeight > gnScreenHeight - 0x3A)
        pDialog->nY = gnScreenHeight - nHeight - 0x30;
    if (pDialog->nX <= 0xA)
        pDialog->nX = 0xA;
    if (pDialog->nY <= 0xA)
        pDialog->nY = 0xA;
    pDialog->nWidth = nMaxWidth;
    pDialog->nHeight = nHeight;
    for (int j = 0; j < pDialog->nLines; ++j)
        sub_004B83A0_PlaceLine(pDialog, j);
}

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4,
    int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled)
{
    int nIndex = pDialog->nLines;
    D2_ASSERT(nIndex < 10, 0x552);
    pDialog->nLines = nIndex + 1;
    pDialog->pLines[nIndex].nHeight = nHeight;
    pDialog->pLines[nIndex].nFont = nFont;
    pDialog->pLines[nIndex].nArg4 = nArg4;
    pDialog->pLines[nIndex].nX = 0;
    if (nType == 3)
    {
        D2_ASSERT(pDialog->nMode != 1, 0x55E);
    }
    pDialog->pLines[nIndex].nType = nType;
    pDialog->pLines[nIndex].pfnCallback = pfnCallback;
    pDialog->pLines[nIndex].bEnabled = bEnabled;
    int nLen = sub_00526800(wszText) + 1;
    if (nLen > 0x77)
        nLen = 0x77;
    sub_00526790(pDialog->pLines[nIndex].wszText, wszText, nLen);
    pDialog->pLines[nIndex].wszText[nLen].wChar = 0;
    if (bEnabled)
        pDialog->nEnabled += 1;
    if (pDialog->bAutoSize)
        sub_004B8410_LayoutDialog(pDialog);
    else
        sub_004B83A0_PlaceLine(pDialog, nIndex);
    D2RectStrc tRect;
    tRect.nLeft = pDialog->nX;
    tRect.nTop = pDialog->nY;
    tRect.nRight = pDialog->nX + pDialog->nWidth;
    tRect.nBottom = pDialog->nY + pDialog->nHeight;
    sub_00467430(&tRect);
    if (pDialog->nHover == -1 && bEnabled)
        sub_004B82F0_Select(pDialog, nIndex);
}

