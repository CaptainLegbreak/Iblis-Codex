#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2CelContext.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2ClientSound.h"
#include "D2ClientDialogWidget.h"
#include "D2SoundEnvironTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SoundUnitNodeStrc;
struct Unicode;
struct D2RectStrc;
struct D2DialogWidget;
struct D2DialogWidgetNodeStrc;
struct D2DialogLineStrc;
struct D2SoundVecStrc;
struct D2SoundEnvironTxtStrc;
struct D2SoundNodeStrc;

struct D2DialogWidget
{
    virtual void Unk0();
    virtual void Draw();
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50
void* __cdecl UI_GetFocusCel(); // 0x00453AB0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

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

int gnSelectionFrame; // 0x007C0E50

// 0x004B8100
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog)
{
    D2_ASSERT(pDialog, 0x48E);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    ++pDialog->nState;

    tContext.nDirection = 0;
    D2RectStrc tRect;
    tRect.nTop = pDialog->nY;
    tRect.nLeft = pDialog->nX;
    tRect.nRight = pDialog->nX + pDialog->nWidth - 1;
    tRect.nBottom = pDialog->nY + pDialog->nHeight - 1;

    if (pDialog->bDrawCel)
    {
        if (pDialog->pCelFile)
        {
            tContext.pCellFile = pDialog->pCelFile;
            tContext.nFrame = 0;
            sub_004F6480(&tContext, pDialog->nX, pDialog->nY + pDialog->nHeight, -1, 5, 0);
        }
    }
    else
    {
        AUTOMAP_DrawFramedBox(tRect.nLeft, tRect.nTop, tRect.nRight - tRect.nLeft + 1, tRect.nBottom - tRect.nTop + 1, 0, 1);
        UI_DrawRectangleBorder(&tRect);
    }

    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->pWidget)
        {
            pNode->pWidget->Draw();
        }
    }

    const int nOldFont = D2Win_10127_SetFont(1);
    int nOffsetY = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        D2DialogLineStrc* pLine = &pDialog->pLines[i];
        int nColor = pLine->nType;
        D2Win_10127_SetFont(pLine->nFont);
        int nLineY = pDialog->nY;
        // volatile: the original adds dialog y and the offset first, then the line height
        nLineY += *(volatile int*)&nOffsetY;
        nLineY += pLine->nHeight;
        const int nLineX = pLine->nX + pDialog->nX;
        if (pDialog->nHover == i)
        {
            if (pDialog->nMode == 1)
            {
                nColor = 3;
            }

            if (pDialog->nMode == 2)
            {
                tContext.pCellFile = UI_GetFocusCel();
                tContext.nFrame = gnSelectionFrame % 7;
                sub_004F6480(&tContext, nLineX - 24, nLineY + 4, -1, 5, 0);
                sub_004F6480(&tContext, pLine->nWidth + nLineX + 2, nLineY + 4, -1, 5, 0);
                ++gnSelectionFrame;
            }
        }

        D2Win_10117_DrawText(pLine->wszText, nLineX, nLineY, nColor, 0);
        nOffsetY += pLine->nHeight;
    }

    D2Win_10127_SetFont(nOldFont);
}

