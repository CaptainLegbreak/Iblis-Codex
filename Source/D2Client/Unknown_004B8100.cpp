#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SoundUnitNodeStrc;
struct Unicode;
struct D2RectStrc;
struct D2DialogWidget;
struct D2DialogWidgetNodeStrc;
struct D2DialogLineStrc;
struct D2SoundVecStrc;
struct D2SoundsTxtStrc;
struct T00481920;
struct D2SoundNodeStrc;

struct Unicode
{
    unsigned short ch;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2DialogWidget
{
    virtual void Unk0();
    virtual void Draw();
};

struct D2DialogWidgetNodeStrc
{
    D2DialogWidget* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

struct D2DialogLineStrc
{
    Unicode wszText[0x78];
    int nHeight;
    int nX;
    int nWidth;
    int nArg4;
    int nFont;
    int nType;
    int (__cdecl* pfnCallback)();
    int bEnabled;
};

struct D2ClientDialogStrc
{
    char unk0x00[0x08];
    void* pCelFile;
    int bDrawCel;
    char unk0x10[0x1C];
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    char unk0x3C[0x8];
    int f_44;
    char unk0x48[0x8];
    int nLines;
    int nDrawCount;
    int bAutoSize;
    int nMode;
    char unk0x60[0x8];
    D2DialogLineStrc pLines[10];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50
void* __cdecl sub_00453AB0(); // 0x00453AB0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0


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

struct D2SoundsTxtStrc
{
    char unk0x00[0x3C];
    unsigned char bEnabled;
    char unk0x3D[8];
    short nTimeout;
    int nKind;
    char unk0x4B[3];
    unsigned char f_4E;
    char unk0x4F[0x11];
    int nGroup;
};

#pragma pack(pop)
struct T00481920
{
    char unk0x00[0x18];
    unsigned char bFlag;
};

struct D2SoundNodeStrc
{
    D2ClientSoundStrc* f_0;
    D2SoundNodeStrc* pNext;
};

extern D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458
extern int gbSoundReady_007C545C; // 0x007C545C
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
unsigned int __cdecl sub_00481820(); // 0x00481820
D2SoundsTxtStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_00481890_GetCacheFirst(int nId); // 0x00481890
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax); // 0x004B93A0
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY); // 0x004E4160
void __fastcall sub_00516950_LinkEntry(D2SoundUnitNodeStrc** ppList, D2UnitStrc* pUnit); // 0x00516950
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

int gnSelectionFrame_007C0E50; // 0x007C0E50

// 0x004B8100
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog)
{
    D2_ASSERT(pDialog, 0x48E);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    ++pDialog->nDrawCount;

    tContext.unk0x40 = 0;
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
        sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, tRect.nRight - tRect.nLeft + 1, tRect.nBottom - tRect.nTop + 1, 0, 1);
        sub_00452E50_DrawRectangleBorder(&tRect);
    }

    for (D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_0)
        {
            pNode->f_0->Draw();
        }
    }

    const int nOldFont = sub_00502EF0(1);
    int nOffsetY = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        D2DialogLineStrc* pLine = &pDialog->pLines[i];
        int nColor = pLine->nType;
        sub_00502EF0(pLine->nFont);
        int nLineY = pDialog->nY;
        nLineY += *(volatile int*)&nOffsetY;
        nLineY += pLine->nHeight;
        const int nLineX = pLine->nX + pDialog->nX;
        if (pDialog->f_44 == i)
        {
            if (pDialog->nMode == 1)
            {
                nColor = 3;
            }

            if (pDialog->nMode == 2)
            {
                tContext.pCellFile = sub_00453AB0();
                tContext.nFrame = gnSelectionFrame_007C0E50 % 7;
                sub_004F6480(&tContext, nLineX - 24, nLineY + 4, -1, 5, 0);
                sub_004F6480(&tContext, pLine->nWidth + nLineX + 2, nLineY + 4, -1, 5, 0);
                ++gnSelectionFrame_007C0E50;
            }
        }

        sub_00502320(pLine->wszText, nLineX, nLineY, nColor, 0);
        nOffsetY += pLine->nHeight;
    }

    sub_00502EF0(nOldFont);
}

static D2ClientSoundStrc* __stdcall sub_004B9760_FindGroupSound(D2ClientSoundStrc* pExclude, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->f_0;
        if (sub_00481890_GetCacheFirst(pSound->nSoundId) == pTxt->nGroup && pSound != pExclude && !pSound->bLocked)
        {
            if (pTxt->nTimeout < 0 || sub_00481820() - pSound->f_34 <= pTxt->nTimeout)
                return pSound;
        }
    }
    return NULL;
}

// 0x004B97D0
static void __stdcall sub_004B97D0_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos)
{
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    int nX;
    int nY;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    UNITS_GetClientCoords(pPlayer, &tPlayer);
    UNITS_GetClientCoords(pUnit, &tUnit);
    if (nSoundId == 0xA27)
    {
        const double dSlope = -2.0;
        const float fPX = (float)tPlayer.nX;
        const float fPY = (float)tPlayer.nY;
        const float fT = (dSlope * fPX + fPY - tUnit.nX * 0.5 - tUnit.nY) / -2.5;
        nX = (int)fT;
        const float fY = dSlope * fPX - dSlope * fT + fPY;
        nY = (int)fY;
    }
    else
    {
        nY = tUnit.nY;
        nX = tUnit.nX;
    }

    pPos->fX = (float)(nX - tPlayer.nX);
    pPos->fZ = 640.0f;
    pPos->fY = (float)(nY - tPlayer.nY) * 2.0f;
}

static float __stdcall sub_004B9890_GetSoundPan(D2UnitStrc* pUnit, int nSoundId)
{
    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    if (pTxt)
    {
        if (pTxt->nKind == 4)
            return 0.0f;

        if (pTxt->nGroup == 0xCA)
        {
            T00481920* pEnviron = sub_00481920_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
            if (pEnviron && pEnviron->bFlag)
                return 0.5f;

            return 0.0f;
        }
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
        return 0.5f;

    return 0.0f;
}

static void sub_004B98F0_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = sub_004E4160_LengthSquared2D(fX, fY);
}

// 0x004B9A00
int __fastcall sub_004B9A00_PlaySound(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4)
{
    if (!gbSoundReady_007C545C)
        return 0;

    if (nSoundId <= 0)
        return 0;

    D2SoundsTxtStrc* pTxt = sub_00481860(nSoundId);
    int nTick = sub_00481820();
    if (!pTxt->bEnabled)
        return 0;

    D2ClientSoundStrc* pSound = NULL;
    if (pTxt->nTimeout)
        pSound = sub_004B9760_FindGroupSound(NULL, nSoundId);

    if (!pSound)
    {
        pSound = sub_004B93F0_AllocHintEntry();
        if (!pSound)
            return 0;

        pSound->nArg3 = nArg3;
        pSound->nSoundId = nSoundId;
        pSound->f_34 = nTick + nDelay;
        pSound->nArg4 = nArg4;
        pSound->f_1C = 0xFF;
        pSound->nPriority = pTxt->f_4E;

        D2SoundVecStrc tPos;
        if (pUnit)
        {
            sub_004B97D0_GetSoundOffset(pUnit, nSoundId, &tPos);
            sub_004B98F0_SetSoundPosition(pSound, &tPos);
            pSound->fPan = sub_004B9890_GetSoundPan(pUnit, nSoundId);
        }
        else
        {
            tPos.fX = 0.0f;
            tPos.fY = 0.0f;
            tPos.fZ = 320.0f;
            sub_004B98F0_SetSoundPosition(pSound, &tPos);
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
        pSound->nPriority += 0x50;

    if (pUnit)
    {
        sub_00516950_LinkEntry(&pSound->pUnitList, pUnit);
        sub_004CA8A0_AddUnitSound(pUnit, pSound->f_8);
    }

    return pSound->f_8;
}
